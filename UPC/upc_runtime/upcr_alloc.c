/*
 * UPC runtime memory allocation functions
 *
 * Jason Duell <jcduell@lbl.gov>
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_alloc.c $
 *
 */

#include <upcr_internal.h>
#include <umalloc_2_upcr.h>

#include <upcr_handlers.h>

/* Initial sizes of local and global heaps */
#define UPCRI_LOCALHEAP_INITSZ	(8192 * 4)
#define UPCRI_GLOBALHEAP_INITSZ	(8192 * 4)

const static size_t UPCRI_MEGABYTE = 1024*1024;
#if UPCR_DEBUGMALLOC
  int upcri_debug_malloc = 0;
#endif
int upcri_firsttouch = 0;

/* ---------------
 * LOCK HIERARCHY  
 * ---------------
 *
 * If multiple locks need to be held simultaneously,
 * those that need locking must be obtained in this order:
 *  1) global_heap_lock
 *  2) local_heap_locks  (by thread number, increasing)
 *  3) heapsizes_lock
 */ 

/* Local heap data is kept either in a single variable (if !PTHREADS) or in
 * the pthread-specific struct (to avoid cache-line collisions).  But in the
 * latter case we still need to keep a global table that can allow a
 * pthreads to reach another's heap, to support upc_free.
 */

static struct {
    upcra_sharedglobal_heap_t *heap; 
    gasnet_hsl_t lock;		
    uintptr_t size;		/* current size of local heap */
    uintptr_t startaddr;	/* start of heap region for this thread */
    /* pad out to 2 cache lines, to avoid false sharing */
    char _pad[GASNETT_CACHE_LINE_BYTES]; 
} global_heap;

typedef struct upcri_localheap {
    upcra_sharedlocal_heap_t *heap;
    gasnet_hsl_t lock;		
    uintptr_t size;		/* current size of local heap */
    uintptr_t startaddr;	/* start of heap region for this thread */
    /* pad out to 2 cache lines, to avoid false sharing */
    char _pad[GASNETT_CACHE_LINE_BYTES]; 
} upcri_localheap_t;

#if UPCRI_UPC_PTHREADS
#define mylocalheap		(upcri_auxdata()->localheap)
#define localheap(pthread)	(upcri_hisauxdata(pthread)->localheap)
#else
static upcri_localheap_t upcri_mylocalheap;
#define mylocalheap			(&upcri_mylocalheap)
#define localheap(pthread)		(upcri_assert((pthread)==0), &upcri_mylocalheap)
#endif

const char *upcri_alloccaller_fntable[] = {
  "upc_alloc", "upc_global_alloc", "upc_all_alloc", "upc_free"
  };

/* You may read the heapsize variables without holding this lock (since they
 * are monotonically increasing, the worst that can happen is that you may get
 * a smaller value than actually exists, so you may call the expand_heapsize
 * functions unnecessarily).
 */
static gasnet_hsl_t heapsizes_lock = GASNET_HSL_INITIALIZER; 
static uintptr_t largest_local_heapsize; /* node 0 has correct value: other nodes 
					    have cached vals (may be too small) */
uintptr_t upcri_perthread_heapsize;	 /* Size of each UPC thread's region
					    for combined local/global heaps */ 

/* If global heap can grow down, local/global heaps can grow until they
 * would touch.  Otherwise, a fixed size limit must be assigned to each at
 * init time.  */
#ifdef UPCR_GLOBALHEAP_GROWS_UP
  static uintptr_t global_heapsize_limit;
  static uintptr_t local_heapsize_limit;
#endif
uintptr_t upcri_umalloc_alignthreshold = 0;
uintptr_t upcri_umalloc_alignsize = 0;

/******************************************************************************
 * Utility functions
 ******************************************************************************/

uint32_t upcri_memtouch_sink = 0;
/* touch memory pages in a given range to establish first-touch affinity
 * writes are preferred (since they're less likely to be ignored by the 
 * first-touch hardware) but reads are also supported in cases where 
 * the data must be preserved
 */
static void upcri_memtouch(void *start, uintptr_t length, int allowwrites) {
  uint8_t *p;
  uint32_t tmp = 0;

  /* we touch the pages in reverse order, to reduce TLB faults on subsequent sequential use */
  p = (uint8_t *)UPCRI_PAGEALIGNDOWN(((uint8_t*)start) + length - 1);
  while (p > (uint8_t *)start) {
    if (allowwrites) *p = 0;
    else tmp += *p;
    p = (uint8_t *)UPCRI_PAGEALIGNDOWN(p-1);
  }
  if (allowwrites) *((uint8_t*)start) = 0;
  else {
    tmp += *((uint8_t*)start);
    upcri_memtouch_sink = tmp;
  }
}

/* each thread's cached high-water mark for "highest" global heap location seen&touched */
#define UPCRI_MY_GHEAP_TOUCHPOS (upcri_auxdata()->globalheap_touchpos)

/* process a new global heap allocation and touch any new portions of our global heap
   that we just noticed
 */
#define upcri_update_globaltouch(newalloc, nblocks, blocksz, allowwrites) \
       _upcri_update_globaltouch(newalloc, nblocks, blocksz, allowwrites UPCRI_PT_PASS)
static int _upcri_update_globaltouch(upcr_shared_ptr_t newalloc, 
                                    size_t nblocks, size_t blocksz, int allowwrites UPCRI_PT_ARG) {
  uint8_t *thisloc, *thisend; 
  size_t thislen;
  if (nblocks == 1) return 0; /* not on global heap */
  upcri_assert(UPCRI_MY_GHEAP_TOUCHPOS);
  thisloc = upcri_shared_to_remote_withthread(newalloc, upcr_mythread());
  thislen = upcr_affinitysize(nblocks*blocksz, blocksz, 0); /* should be maximal on zero */
  thisend = thisloc + thislen - 1;
  #ifdef UPCR_GLOBALHEAP_GROWS_UP
    if (thisend > UPCRI_MY_GHEAP_TOUCHPOS) {
      if (UPCRI_MY_GHEAP_TOUCHPOS < thisloc) /* need to catch up, using non-destructive touch */
        upcri_memtouch(UPCRI_MY_GHEAP_TOUCHPOS, thisloc - UPCRI_MY_GHEAP_TOUCHPOS, 0);
      upcri_memtouch(thisloc, thislen, allowwrites);
      UPCRI_MY_GHEAP_TOUCHPOS = thisend;
      return 1;
    }
  #else
    if (thisloc < UPCRI_MY_GHEAP_TOUCHPOS) {
      if (thisend+1 < UPCRI_MY_GHEAP_TOUCHPOS) /* need to catch up, using non-destructive touch */
        upcri_memtouch(thisend+1, UPCRI_MY_GHEAP_TOUCHPOS - thisend, 0);
      upcri_memtouch(thisloc, thislen, allowwrites);
      UPCRI_MY_GHEAP_TOUCHPOS = thisloc;
      return 1;
    }
  #endif
  return 0;
}

/*
 * Tell our tale of woe and drop dead if we run out of shared memory.
 */
extern void upcri_getheapstats(const char *prefix, char *buf, size_t bufsz) {
  int retval;
  upcri_assert(gasnet_mynode() == 0);
  retval = snprintf(buf, bufsz,
	  "%sLocal shared memory in use:  %4lu MB per-thread,  %4lu MB total\n"
#ifdef UPCR_GLOBALHEAP_GROWS_UP
	  "%sLocal shared memory max:     %4lu MB per-thread,  %4lu MB total\n"
#endif
	  "%sGlobal shared memory in use: %4lu MB per-thread,  %4lu MB total\n"
#ifdef UPCR_GLOBALHEAP_GROWS_UP
	  "%sGlobal shared memory limit:  %4lu MB per-thread,  %4lu MB total"
#else
	  "%sTotal shared memory limit:   %4lu MB per-thread,  %4lu MB total"
#endif
        , prefix,
	(unsigned long)(largest_local_heapsize/UPCRI_MEGABYTE), 
	(unsigned long)(largest_local_heapsize*upcr_threads()/UPCRI_MEGABYTE),
#ifdef UPCR_GLOBALHEAP_GROWS_UP
        prefix,
	(unsigned long)(local_heapsize_limit/UPCRI_MEGABYTE), 
	(unsigned long)(local_heapsize_limit*upcr_threads()/UPCRI_MEGABYTE),
#endif
        prefix,
	(unsigned long)(global_heap.size/UPCRI_MEGABYTE), 
	(unsigned long)(global_heap.size*upcr_threads()/UPCRI_MEGABYTE),
#ifdef UPCR_GLOBALHEAP_GROWS_UP
        prefix,
	(unsigned long)(global_heapsize_limit/UPCRI_MEGABYTE), 
	(unsigned long)(global_heapsize_limit*upcr_threads()/UPCRI_MEGABYTE)
#else
        prefix,
	(unsigned long)(upcri_perthread_segsize/UPCRI_MEGABYTE), 
	(unsigned long)(upcri_perthread_segsize*upcr_threads()/UPCRI_MEGABYTE)
#endif
  );
  if (retval < 0 || retval > bufsz-5) strcpy(buf+bufsz-5,"...");
}

/* AM-safe */
GASNETT_INLINE(death_by_heap_collision)
void 
death_by_heap_collision(upcri_alloccaller_t caller, uintptr_t request_sz)
{
    char buf[1024];
    upcri_getheapstats("  ", buf, 1024);

    /* NOTE: the test harness scans for this string */
    upcri_err("out of shared memory\n"
          "%s\n"
	  "%s unable to service request from thread %i for %lu more bytes\n", 
	buf, 
        UPCRI_ALLOCCALLER_FN(caller), 
        (int)UPCRI_ALLOCCALLER_THREAD(caller), 
        (unsigned long)request_sz);
}

#ifdef PLATFORM_ARCH_64
  /* bug 1778: detect 32-bit overflow bugs in caller code */
  #define UPCRI_ALLOC_SANITYCHECK(nblocks,blocksz,caller) do {                  \
    if_pf (((nblocks) | (blocksz)) & (1UL << 63)) {                             \
      upcri_err("Thread %i asked for a ridiculous amount of memory from %s:\n"  \
                "  nblocks=%lu * nbytes=%lu == %lu total bytes\n"               \
                "Check for overflow in the caller code?",                       \
                UPCRI_ALLOCCALLER_THREAD(caller), UPCRI_ALLOCCALLER_FN(caller), \
                (unsigned long)(nblocks), (unsigned long)(blocksz),             \
                (unsigned long)((nblocks)*(blocksz)));                          \
    }                                                                           \
  } while (0)
#else
  #define UPCRI_ALLOC_SANITYCHECK(nblocks,blocksz,caller) ((void)0)
#endif

/*
 * Checks to see if an increase in the local shared heap size limit is OK, and
 * sets largest_local_heapsize to requested value if so.  It is possible that
 * newlargest will be larger than the requested value (if the request is based
 * on a cached value that is out of date).
 *
 * 'neededsz' is the new size for the local heap that is needed.
 *
 * IMPORTANT: this function must be called with the heapsizes_lock held!!!
 * Call is AM-safe and may run on non-app threads
 */
GASNETT_INLINE(upcri_expand_largest_lheapsz)
void 
upcri_expand_largest_lheapsz(uintptr_t neededsz, uintptr_t requestsz, 
                             upcri_alloccaller_t caller)
{
    UPCRI_TRACE_PRINTF(("HEAPOP EXPANSION: %s on %i expanding local heap by %lu pages to %lu total\n",
                  UPCRI_ALLOCCALLER_FN(caller), 
                  (int)UPCRI_ALLOCCALLER_THREAD(caller), 
		  (unsigned long)(requestsz/UPCR_PAGESIZE),
                  (unsigned long)(neededsz/UPCR_PAGESIZE)));

    upcri_assert(gasnet_mynode() == 0);
    upcri_assert(!(neededsz % UPCR_PAGESIZE));   /* must be multiple */
    upcri_assert(!(requestsz % UPCR_PAGESIZE));  /* of page size */

    /* request may be less than what node 0 has already given out */
    if (neededsz <= largest_local_heapsize)
	return;

#ifdef UPCR_GLOBALHEAP_GROWS_UP
    if (neededsz > local_heapsize_limit) {
#else
    if ( (neededsz + global_heap.size) > upcri_perthread_heapsize) {
#endif
	/* Out of shared memory */
	gasnet_hsl_unlock(&heapsizes_lock);
	death_by_heap_collision(caller, requestsz);
    }
    largest_local_heapsize = neededsz;
}

/*
 * Expands global heap size by requested amount, or drops dead if heaps would
 * collide.
 *
 * IMPORTANT: this function must be called with the global_heap_lock held!!!
 * Must be AM-safe
 */

GASNETT_INLINE(upcri_expand_global_heapsize)
void 
upcri_expand_global_heapsize(uintptr_t morebytes, upcri_alloccaller_t caller)
{
    uintptr_t newsize;

    upcri_assert(gasnet_mynode() == 0);

    gasnet_hsl_lock(&heapsizes_lock);
    newsize = global_heap.size + morebytes;

    UPCRI_TRACE_PRINTF(("HEAPOP EXPANSION: %s on %i expanding global heap by %lu pages to %lu total (%lu MB)\n",
                  UPCRI_ALLOCCALLER_FN(caller), 
                  (int)UPCRI_ALLOCCALLER_THREAD(caller), 
                  (unsigned long)(morebytes/UPCR_PAGESIZE), 
		  (unsigned long)(newsize/UPCR_PAGESIZE), 
                  (unsigned long)(newsize/UPCRI_MEGABYTE)));

#ifdef UPCR_GLOBALHEAP_GROWS_UP
    if (newsize > global_heapsize_limit) {
#else
    if ( (newsize + largest_local_heapsize) > upcri_perthread_heapsize) {
#endif
	/* Out of shared memory */
	gasnet_hsl_unlock(&heapsizes_lock);
	gasnet_hsl_unlock(&global_heap.lock);
	death_by_heap_collision(caller, morebytes);
    }
    global_heap.size = newsize;
    gasnet_hsl_unlock(&heapsizes_lock);

}

/* function for calculating how much to attempt to grow the heap after a failure
   allocsz is the size of the allocation request
   morebytes is the last guess returned by this function (should be 0 on first call)
   heap_freebytes_hint is a hint of the free bytes currently in the heap 
   heap_morecore_hint is a hint of the number of bytes the heap internally 
     requested during the last allocation failure 
*/
size_t upcri_calc_heapgrowth(size_t allocsz, size_t morebytes,
                             uintptr_t heap_freebytes_hint, uintptr_t heap_morecore_hint) {
  UPCRI_TRACE_PRINTF(("upcri_calc_heapgrowth: allocsz=%llu morebytes=%llu "
                      "heap_freebytes_hint=%llu heap_morecore_hint=%llu",
                      (unsigned long long)allocsz,
                      (unsigned long long)morebytes,
                      (unsigned long long)heap_freebytes_hint,
                      (unsigned long long)heap_morecore_hint
                      ));
  if (heap_morecore_hint > 0 && heap_morecore_hint <= 1.1*(allocsz+UPCR_PAGESIZE)) {
      /* if we have a hint and it looks reasonable, use it
         this helps us handle umalloc's descriptor space overhead,
         which may cause it to fail to allocate, even when the heap is
         already large enough to hold the object itself
      */
      morebytes = heap_morecore_hint;
  } else if (morebytes == 0) { /* no hint - first time call */
    /* start by assuming that all the free bytes are at the end of the heap 
       and can partially satisfy this allocation - prevents us from way 
       overshooting the heap growth when the heap only needs to grow by 
       a few more pages to satisfy the failed allocation */
    morebytes = allocsz+UPCR_PAGESIZE; /* provide one extra page for umalloc overhead */
    if (heap_freebytes_hint < morebytes) morebytes -= heap_freebytes_hint;
  } else {
      /* now increase the heap growth request exponentially up to allocsz,
         and for multi-MB allocsz, start the bidding at 1MB */ 
      morebytes = MIN(allocsz+UPCR_PAGESIZE, MAX(morebytes*2, 1024*1024));
      /* TODO: in degenerate cases, this algorithm may still cause us to 
         overshoot the necessary heap growth by as much as allocsz - page_sz,
         although that's hopefully unlikely.
         A better algorithm would check the available growth space and 
         ensure we try the allocation after giving the allocator every last byte
         of available space, before invoking the growth operation that 
         results in an out-of-memory crash. One way to do this would be an argument
         to upcri_expand_*heapsize which allows it to return less than the 
         requested expansion if the heaps collide.
       */
  }
  /* always ask for more memory in page-sized chunks */
  morebytes = upcri_roundup_pagesz(morebytes);
  UPCRI_TRACE_PRINTF(("upcri_calc_heapgrowth returning: %llu ", (unsigned long long)morebytes));
  return morebytes;
}

/******************************************************************************
 * Memory debugging functions
 ******************************************************************************/

#if UPCR_DEBUG
/* header preceeding each block */
typedef struct {
  size_t length;
  union { /* This union ensures ABI's alignment is preserved */
    uint64_t signature; /* only this member is used */
    double d;
    void* p;
  } u;
} memcheck_header_t;

/* signature values */
static const uint64_t memcheck_free = 0x5ff6f205e65bae5dULL;
static const uint64_t memcheck_live = 0x86c729990c076c48ULL;
static const uint64_t memcheck_tail = 0xbdafc8a39eca293bULL;

/* amount of padding needed to add header and optionally preserve alignment */
static size_t memcheck_headspace(size_t size) {
  if (size >= upcri_umalloc_alignthreshold) {
    return MAX(upcri_umalloc_alignsize, sizeof(memcheck_header_t));
  } else {
    return sizeof(memcheck_header_t);
  }
}

static void *memcheck_post_alloc(char *ptr, size_t length) {
  memcheck_header_t *header;

  upcri_assert((length < upcri_umalloc_alignthreshold) || !((uintptr_t)ptr % upcri_umalloc_alignsize));

  ptr += memcheck_headspace(length);
  header = (memcheck_header_t *)ptr - 1;
  header->length = length;
  header->u.signature = memcheck_live;
  memcpy(ptr + length, &memcheck_tail, 8);
  return ptr;
}

static void *memcheck_pre_free(char *ptr, upcr_thread_t thread, int isglobal) {
  memcheck_header_t *header = (memcheck_header_t *)ptr - 1;
  size_t length = header->length;

  if_pf ((header->u.signature != memcheck_live) ||
         memcmp(ptr + length, &memcheck_tail, 8)) {
    /* invalid address, double-free or under/over-run */
    upcri_err("Thread %i detected memory corruption or an illegal operation\n"
              " on the UPC %s shared heap, while performing a upc_free operation",
              (int)thread, (isglobal?"global":"local"));
  }

  header->u.signature = memcheck_free;
  return ptr - memcheck_headspace(length);
}

#define MEMCHECK_POST_ALLOC(p,l)   memcheck_post_alloc(p,l)
#define MEMCHECK_PRE_FREE(p,t,g)   memcheck_pre_free(p,t,g)
#define MEMCHECK_SPACE(l)          (memcheck_headspace(l) + 8)
#else
#define MEMCHECK_POST_ALLOC(p,l)   (p)
#define MEMCHECK_PRE_FREE(p,t,g)   (p)
#define MEMCHECK_SPACE(l)          (0)
#endif /* UPCR_DEBUGMALLOC */

/******************************************************************************
 * UPC Memory allocation functions
 ******************************************************************************/

void upcri_init_heaps(void *start, uintptr_t len)
{
    UPCR_BEGIN_FUNCTION();
    void *gheap_startaddr;

    /* UPC_FIRSTTOUCH: dynamically perform first touch on shared heap memory to help
       ensure correct memory-thread affinity on NUMA SMP's with first-touch 
       physical memory allocation (eg Altix, Origin). Enabled by default with 2+ pthreads
       current status of the heuristic: 
         always effective for local heap memory (upc_alloc)
         always effective for upc_all_alloc'd memory, in programs that 
            never use upc_global_alloc, or programs that never upc_free memory obtained
            from upc_global_alloc (see below)
         may not be effective for upc_global_alloc'd memory if the "wrong" thread
            is the first to touch a given page in a upc_global_alloc'd area. 
            This effect can also contaminate the affinity of upc_all_alloc'd memory
            if such an area is subsequently upc_free'd and then re-allocated using upc_all_alloc
       Note these effectiveness guarantees assume threads do not migrate across physical CPU's. 
         In the presense of thread migration, all bets are off for SMP memory affinity.
     */
    upcri_firsttouch = gasnett_getenv_yesno_withdefault("UPC_FIRSTTOUCH", upcri_mypthreads() > 1);
    if (gasnett_getenv_yesno_withdefault("UPC_FORCETOUCH", 0)) {
      /* UPC_FORCETOUCH: force each thread to touch the ENTIRE shared heap at startup to
         guarantee correct memory-thread affinity on NUMA SMP's with first-touch 
         physical memory allocation (eg Altix, Origin). Disabled by default.
         This approach is effective under all conditions, but could noticeably delay program startup
           and could increase the consumption of OS memory resources (eg swap space) on some systems
           (it's recommended to set UPC_SHARED_HEAP_SIZE to a tight upper bound when using this option)
       */
      upcri_memtouch(start, len, 1);
      upcri_firsttouch = 0;
    }

    /* 1st pthread on each node does global data init */
    if (upcri_mypthread() == 0) {
	largest_local_heapsize = upcri_roundup_pagesz(UPCRI_LOCALHEAP_INITSZ);
	upcri_perthread_heapsize = len;

        { /* decide on size threshold for automatic cache alignment - default to 4KB */
          upcri_umalloc_alignthreshold = gasnett_getenv_int_withdefault("UPC_SHARED_ALLOC_ALIGN", 4096, 1);
          upcri_umalloc_alignsize = GASNETT_CACHE_LINE_BYTES;
        }
    }

    upcri_pthread_barrier();

    /* Only node 0 uses the global heap allocator. */
    if (upcr_mythread() == 0) {
	global_heap.size = upcri_roundup_pagesz(UPCRI_GLOBALHEAP_INITSZ);
	gasnet_hsl_init(&global_heap.lock);
#ifdef UPCR_GLOBALHEAP_GROWS_UP
	/* TODO: at least make this configurable rather than 50%-50% split */
	global_heapsize_limit = local_heapsize_limit = len/2;
	global_heap.startaddr = ((uintptr_t)start) + len - global_heapsize_limit;
#else
	global_heap.startaddr = ((uintptr_t)start) + len - 1;
#endif
        gheap_startaddr = (void *)global_heap.startaddr;
	global_heap.heap = upcra_sharedglobal_init(
					(void *)global_heap.startaddr,
					global_heap.size);
	if (global_heap.heap == NULL)
	    upcri_err("Error initializing global heap (got NULL)");
    }

    /* each thread inits the globalheap affinity touching high-water mark */
    upcri_broadcast(0, &gheap_startaddr, sizeof(gheap_startaddr));
    UPCRI_MY_GHEAP_TOUCHPOS = upcri_shared_to_remote_withthread(
        upcr_local_to_shared_withphase(gheap_startaddr, 0, 0), upcr_mythread());

    /* every thread initializes its own allocator */
#if UPCRI_UPC_PTHREADS
    mylocalheap = UPCRI_XMALLOC(upcri_localheap_t, 1);
#endif
    mylocalheap->size = upcri_roundup_pagesz(UPCRI_LOCALHEAP_INITSZ); 
    mylocalheap->heap = upcra_sharedlocal_init(start, mylocalheap->size);
    gasnet_hsl_init(&mylocalheap->lock);
    mylocalheap->startaddr = (uintptr_t)start;
    if (upcri_firsttouch) /* first-touch all the pages being added */
      upcri_memtouch(start, mylocalheap->size, 1);
}

/* 
 * Non-collective operation that allocates nblocks * blocksz bytes in the shared
 * memory area with affinity to this thread, and returns a pointer to the new
 * data, which is suitably aligned for any kind of variable. 
 *
 * Requires nblocks >= 0 and blocksz >= 0
 *
 * The memory is not cleared or initialized in any way, although it has been
 * properly registered with the network system in a way appropriate for the
 * current platform such that remote threads can read and write to the memory
 * using upcr shared data transfer operations. 
 *
 * If insufficient memory is available, the function will print an
 * implementation-defined error message and terminate the job.
 *
 * The phase of the returned pointer is set to zero.
 */

/* perform a local alloc on a given local pthread's sharedlocal heap, 
   which may or may not be the heap of the current pthread. 
   This is AM Safe and may run on non-application threads 
   (so upcri_mypthread() calls are prohibited!)
 */
upcr_shared_ptr_t 
upcri_alloc(size_t nbytes, upcri_pthread_t pthread,
            upcri_alloccaller_t caller)
{
    void * ptr;
    size_t prevgrowth = 0;
    upcri_localheap_t *lh = localheap(pthread);
    size_t allocsz = nbytes + MEMCHECK_SPACE(nbytes);

    UPCRI_ALLOC_SANITYCHECK(1,nbytes,caller);

    if_pf (!nbytes) {
	upcr_shared_ptr_t result = UPCR_NULL_SHARED;
	return result;
    }

    gasnet_hsl_lock(&lh->lock);
    while (!(ptr = upcra_sharedlocal_alloc(lh->heap, allocsz)))
    {
	size_t neededlheapsz;
        /* allocation failed - decide how much to grow the heap */
        size_t morebytes = upcri_calc_heapgrowth(allocsz, prevgrowth, 
          upcra_sharedlocal_query_freebytes(lh->heap), umalloc_morecore_hint(lh->heap));

	/* See if our copy of largest_local_heapsize indicates we have enough
	 * room to enlarge the local heap enough.  If not, ask node 0 for more
	 * room (or if we are node 0, make the room).
	 */
	gasnet_hsl_lock(&heapsizes_lock);
	neededlheapsz = lh->size + morebytes;
	if (neededlheapsz > largest_local_heapsize) {
	    prevgrowth = morebytes;
	    if (gasnet_mynode() == 0) {
		upcri_expand_largest_lheapsz(neededlheapsz, morebytes, caller);
		upcri_assert(largest_local_heapsize >= neededlheapsz);
	    } else { 
               /* this code path is never taken in AM context, 
                  because all allocation AM handlers run on node 0 */
		/* we need to ask node 0 for more space */
		volatile int trigger = UPCRI_REQUEST_BLOCKED;

		/* We have to let go of the locks here, since we're doing an
		 * AM call.  This means that other pthreads on our same node
		 * may wind up entering this function while we wait, and may
		 * also make overlapping AM calls to expand the local heap's
		 * size.  At worst, this may cause some AM requests to get
		 * repeated (if several pthreads ask node 0 for a heapsize
		 * just big enough for their own allocation, and then one of
		 * them slurps up all of the resulting space).  If this turns
		 * out to be a problem, we can change the code to ask for a
		 * larger increase than is needed for the present allocation
		 * (which might also save network trips for future calls even
		 * on a single-threaded implementation).
		 */
		gasnet_hsl_unlock(&heapsizes_lock);
		gasnet_hsl_unlock(&lh->lock);

		/* pass size_t's as pointers, since may be 64 bits */
		UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(4, 7,
			      (0, UPCRI_HANDLER_ID(upcri_expand_local_SRequest),
				    UPCRI_SEND_PTR(neededlheapsz),
				    UPCRI_SEND_PTR(morebytes),
				    UPCRI_SEND_PTR(&trigger),
                                    (gasnet_handlerarg_t)caller)));

		GASNET_BLOCKUNTIL(trigger == UPCRI_REQUEST_DONE);

		gasnet_hsl_lock(&lh->lock);
		gasnet_hsl_lock(&heapsizes_lock);
	    }
	} else {
	    /* A jump to lh->size = largest_local_heapsize should not
	     * contribute to computation of the next value of morebytes. */
	    prevgrowth = 0;
	}
#if UPCR_DEBUG /* Debug output in case bug 2986 pops up again */
	if_pf (largest_local_heapsize < neededlheapsz) {
	    fprintf(stderr, "largest_local_heapsize = %p but neededlheapsz = %p\n", (void*)largest_local_heapsize, (void*)neededlheapsz);
	    fprintf(stderr, "morebytes = %p lh->size = %p\n", (void*)morebytes, (void*)(lh->size));
	}
#endif
	upcri_assert(largest_local_heapsize >= neededlheapsz);

	/* some other thread may have increased largest_local_heapsize
	 * while we were without the locks, or node 0 may have given
	 * us more room then we asked for (and we might as well give
	 * it all to the heap) */
	morebytes = (largest_local_heapsize - lh->size);
	upcri_assert(!(morebytes % UPCR_PAGESIZE));
	gasnet_hsl_unlock(&heapsizes_lock);

	if (morebytes) {
            if (upcri_firsttouch) /* first-touch all the pages being added */
              upcri_memtouch((void*)(lh->startaddr + lh->size), morebytes, 1);
	    upcra_sharedlocal_provide_pages(lh->heap, morebytes);
	    lh->size += morebytes;
        }
    }
    gasnet_hsl_unlock(&lh->lock);

    return upcr_local_to_shared_withphase(MEMCHECK_POST_ALLOC(ptr, nbytes), 0, 
				upcri_1stthread(gasnet_mynode()) + pthread);
}

upcr_shared_ptr_t 
_upcr_alloc(size_t nbytes UPCRI_PT_ARG)
{
  upcr_shared_ptr_t retval;

  #define UPCRI_PEVT_ARGS , nbytes
  upcri_pevt_start(GASP_UPC_ALLOC);
  #undef UPCRI_PEVT_ARGS

  retval = upcri_alloc(nbytes, upcri_mypthread(),
         UPCRI_ALLOCCALLER(UPCRI_ALLOCCALLERFN_LOCAL, upcr_mythread()));

  #define UPCRI_PEVT_ARGS , nbytes, &retval
  upcri_pevt_end(GASP_UPC_ALLOC);
  #undef UPCRI_PEVT_ARGS

  #ifdef GASNET_TRACE
    { char ptrstr[UPCRI_DUMP_MIN_LENGTH];
      upcri_dump_shared(retval, ptrstr, UPCRI_DUMP_MIN_LENGTH);
      UPCRI_TRACE_PRINTF(("HEAPOP upc_alloc(%llu) => %s", 
          (unsigned long long)nbytes, ptrstr));
    }   
  #endif
  return retval;
}

void upcri_expand_local_SRequest(gasnet_token_t token, 
				 void *neededlheapsz,
				 void *request_sz,
				 void *trigger_addr,
                                 gasnet_handlerarg_t caller)
{
    uintptr_t neededsz = (uintptr_t)neededlheapsz;
    uintptr_t newlargest;

    gasnet_hsl_lock(&heapsizes_lock);
    upcri_expand_largest_lheapsz(neededsz, (uintptr_t)request_sz, 
                                 (upcri_alloccaller_t)caller);
    upcri_assert(largest_local_heapsize >= neededsz);
    newlargest = largest_local_heapsize;
    gasnet_hsl_unlock(&heapsizes_lock);

    /* Send new largest_local_heapsize as ptr, since uintptr_t may be 64 bits */
    UPCRI_AM_CALL(UPCRI_SHORT_REPLY(2, 4,
		    (token, UPCRI_HANDLER_ID(upcri_expand_local_SReply),
			    UPCRI_SEND_PTR(newlargest),
			    UPCRI_SEND_PTR(trigger_addr))));
}

void upcri_expand_local_SReply(gasnet_token_t token, 
			       void *newlargestlh,
			       void *trigger_addr)
{
    gasnet_hsl_lock(&heapsizes_lock);
    /* MAX required because Replies can be processed out-of-order (bug 2986) */
    largest_local_heapsize = MAX(largest_local_heapsize, (uintptr_t) newlargestlh);
    gasnet_hsl_unlock(&heapsizes_lock);

    *((int*)trigger_addr) = UPCRI_REQUEST_DONE;
}
			    

/* Non-collective operation that allocates nblocks * blocksz bytes spread across
 * the shared memory area of 1 or more threads, and returns a pointer to the new
 * data, which is suitably aligned for any kind of variable. 
 *
 * Requires nblocks >= 0 and blocksz >= 0
 *
 * The memory is blocked across all the threads as if it had been created by the
 * UPC declaration: 
 *
 *    shared [blocksz] char[nblocks*blocksz] (both sizes are expressed in bytes).
 *
 * Specifically, thread i allocates (at least): 
 *
 *    Max({0} union {
 *	0 < n <= nblocks * blocksz | (floor(n-1/blocksz) % THREADS) == i})  bytes.
 *
 * More specifically, thread i allocates (at least) this many bytes:
 *
 *    blocksz *  ceil(nblocks/THREADS)  if i <= (nblocks % THREADS)
 *    blocksz * floor(nblocks/THREADS)  if i >  (nblocks % THREADS)
 *
 * Implementor's note: Some implementations may allocate the full (blocksz *
 * ceil(nblocks/THREADS)) memory on each thread for simplicity, even though less
 * may be required on some threads.
 *
 * Note if nblocks == 1, then all the memory will be allocated in the shared
 * memory space of thread 0 (and implementations should attempt not to waste
 * space on other threads in this common special case).
 *
 * In all cases the returned pointer will point to a memory location in the
 * shared memory space of thread 0, and any subsequent chunks in the shared
 * space of other threads will be logically aligned with this pointer (such that
 * incrementing a shared pointer of the appropriate blocksz past the end of a
 * block on one thread will bring it to the start of the next block on the next
 * thread).
 *
 * The phase of the returned pointer is set to zero
 *
 * The memory is not cleared or initialized in any way, although it has been
 * properly registered with the network system in a way appropriate for the
 * current platform such that remote threads can read and write to the memory
 * using the upcr shared data transfer operations.  If insufficient memory is
 * available, the function will print an implementation-defined error message
 * and terminate the job.
 */

/* 
 * This runs only on node 0, and does the actual allocation
 */

static void
upcri_do_global_alloc(size_t nblocks, size_t blocksz, upcr_shared_ptr_t *pout, 
		       upcri_alloccaller_t caller)
{
    void * newaddr;
    size_t morebytes = 0;
    size_t nbytes = blocksz * upcri_ceiling_div(nblocks, upcr_threads()); 
    size_t allocsz = nbytes + MEMCHECK_SPACE(nbytes);

    UPCRI_ALLOC_SANITYCHECK(nblocks,blocksz,caller);
    upcri_assert(gasnet_mynode() == 0);
    upcri_assert(nblocks > 0);
    upcri_assert(blocksz > 0);
    upcri_assert(global_heap.heap != NULL);

    /* convert to local shared alloc on thread 0 if indefinite blocksz 
       This is a CRUCIAL optimization to ensure that we dont waste 
       (THREADS-1)*totalsz for indefinitely blocked shared allocations 
       invoked via upc_all_alloc or upc_global_alloc
     */
    if (nblocks == 1) {
	*pout = upcri_alloc(blocksz, 0, caller);
	return;
    }

    /* Do allocation with lock held.  Expand global heap as needed */
    gasnet_hsl_lock(&global_heap.lock);
    while (!(newaddr = upcra_sharedglobal_alloc(global_heap.heap, allocsz))) {
        /* allocation failed - decide how much to grow the heap */
        morebytes = upcri_calc_heapgrowth(allocsz, morebytes, 
          upcra_sharedglobal_query_freebytes(global_heap.heap),
          umalloc_morecore_hint(global_heap.heap));

	upcri_expand_global_heapsize(morebytes, caller);
	upcra_sharedglobal_provide_pages(global_heap.heap, morebytes);
    }
    gasnet_hsl_unlock(&global_heap.lock);

    /* any pthread on node could be handling this request, but the addr
     * returned must point to UPC thread 0 */
    upcr_local_to_shared_ref_withphase(MEMCHECK_POST_ALLOC(newaddr, nbytes), 0, 0, pout);
}

/* 
 * global_alloc handler runs on node 0: allocated memory, and replies with
 * address.  Also sends latest largest_local_heapsize to update remote node's
 * cached copy
 */
void upcri_global_alloc_SRequest(gasnet_token_t token, 
				 void *nblocks, 
				 void *blocksz, 
				 void *result_addr,
				 void *trigger_addr,
                                 gasnet_handlerarg_t caller)
{
    upcr_shared_ptr_t out;

    upcri_assert(gasnet_mynode() == 0);

    /* Foregone success: AM guarantees at least a 512 byte max msg size */
    upcri_assert(sizeof(upcr_shared_ptr_t) < gasnet_AMMaxMedium());

    upcri_do_global_alloc((size_t)(uintptr_t)nblocks, (size_t)(uintptr_t)blocksz, &out, caller);

    /* We don't need to lock the heapsizes_lock to send
     * largest_local_heapsize: worst that can happen is we send a smaller
     * value than we could have).  We send largest_local_heapsize as a ptr, in
     * case uintptr_t is 64 bits. */
    UPCRI_AM_CALL(UPCRI_MEDIUM_REPLY(3, 6,
		    (token, UPCRI_HANDLER_ID(upcri_global_alloc_MReply),
		     &out, sizeof(out), 
			 UPCRI_SEND_PTR(result_addr),
			 UPCRI_SEND_PTR(trigger_addr),
			 UPCRI_SEND_PTR(largest_local_heapsize))));
}

/* 
 * We use a 'medium' AM handler, since we don't want to violate the
 * encapulation of the shared pointer interface by breaking it up into
 * 32 bit chunks that we could pass as regular args.  So instead we use the
 * Medium type's ability to do a memcpy.
 */
void upcri_global_alloc_MReply(gasnet_token_t token, 
			       void *msg, size_t len, 
			       void *result, void *trigger, void *llheapsz)
{
    int * ptrigger = (int *)trigger;
    uintptr_t new_llheapsz = (uintptr_t) llheapsz; 
    
    /* copy global_alloc's return value from network buffer */
    upcri_assert(len == sizeof(upcr_shared_ptr_t));
    memcpy(result, msg, len);

    gasnett_weak_wmb();

    /* unblock thread that called global_alloc */
    *ptrigger = UPCRI_REQUEST_DONE;

    /* Update local cached value for largest_local_heapsize, using lock and
     * check to make sure we never set it lower than current value */
    upcri_assert(gasnet_mynode() != 0);
    gasnet_hsl_lock(&heapsizes_lock);
    if (new_llheapsz > largest_local_heapsize)
	largest_local_heapsize = new_llheapsz;
    gasnet_hsl_unlock(&heapsizes_lock);
}

upcr_shared_ptr_t 
_upcr_global_alloc(size_t nblocks, size_t blocksz UPCRI_PT_ARG)
{
    upcr_shared_ptr_t result;
    upcri_alloccaller_t caller = 
      UPCRI_ALLOCCALLER(UPCRI_ALLOCCALLERFN_GLOBAL, upcr_mythread());
    
    #define UPCRI_PEVT_ARGS , nblocks, blocksz
    upcri_pevt_start(GASP_UPC_GLOBAL_ALLOC);
    #undef UPCRI_PEVT_ARGS

    if_pf (!nblocks || !blocksz) {
	upcr_setnull_shared(&result);
    } else {
      if (gasnet_mynode() == 0) {
	upcri_do_global_alloc(nblocks, blocksz, &result, caller);
      } else {
	/* Send request to node 0, and wait until reply arrives */
	volatile int trigger = UPCRI_REQUEST_BLOCKED; 

	UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(5, 9, 
		      (0, UPCRI_HANDLER_ID(upcri_global_alloc_SRequest),
				UPCRI_SEND_PTR(nblocks), 
                                UPCRI_SEND_PTR(blocksz), 
				UPCRI_SEND_PTR(&result),
				UPCRI_SEND_PTR(&trigger),
                                (gasnet_handlerarg_t)caller)));

	GASNET_BLOCKUNTIL(trigger == UPCRI_REQUEST_DONE);
      }

      if (upcri_firsttouch) /* first-touch new global-heap pages as we notice them */
        upcri_update_globaltouch(result, nblocks, blocksz, 1);
    }

    upcri_assert(upcr_threadof_shared(result) == 0);
    #define UPCRI_PEVT_ARGS , nblocks, blocksz, &result
    upcri_pevt_end(GASP_UPC_GLOBAL_ALLOC);
    #undef UPCRI_PEVT_ARGS

    #ifdef GASNET_TRACE
    { char ptrstr[UPCRI_DUMP_MIN_LENGTH];
      upcri_dump_shared(result, ptrstr, UPCRI_DUMP_MIN_LENGTH);
      UPCRI_TRACE_PRINTF(("HEAPOP upc_global_alloc(%llu, %llu) => %s", 
        (unsigned long long)(nblocks), (unsigned long long)(blocksz), ptrstr));
    }   
    #endif
    return upcri_checkvalid_shared(result);
}


/* 
 * Collective version of upcr_global_alloc() - the semantics are identical to
 * upcr_global_alloc() with the following exceptions:
 * -- The function must be called by all threads during the same synchronization
 *    phase, and all threads must provide the same arguments.
 * -- May act as a barrier for all threads, but might not in some
 *    implementations. 
 * -- All threads receive a copy of the result, and the shared pointer values
 *    will be equal (according to upcr_isequal_shared_shared()) on all
 *    threads.
 */
upcr_shared_ptr_t 
_upcr_all_alloc(size_t nblocks, size_t blocksz UPCRI_PT_ARG)
{
    upcr_shared_ptr_t result;

    #define UPCRI_PEVT_ARGS , nblocks, blocksz
    upcri_pevt_start(GASP_UPC_ALL_ALLOC);
    #undef UPCRI_PEVT_ARGS

    if_pf (!nblocks || !blocksz) {
      upcr_setnull_shared(&result);
    } else {
      struct {
        upcr_shared_ptr_t out;
        uint8_t flags;
      } bundle;
      int touchbarrier = 0;

      if (upcr_mythread() == 0) {
        memset(&bundle, 0, sizeof(bundle)); /* prevent a valgrind warning caused by struct padding */
        upcri_do_global_alloc(nblocks, blocksz, &bundle.out, 
           UPCRI_ALLOCCALLER(UPCRI_ALLOCCALLERFN_ALL, 0));
        if (upcri_firsttouch && /* decide if we'll need a pause for first-touch of new global-heap pages */
            upcri_update_globaltouch(bundle.out, nblocks, blocksz, 1)) bundle.flags = 0x1;
        else bundle.flags = 0;
      }
      upcri_broadcast(0, &bundle, sizeof(bundle));
      result = bundle.out;
      touchbarrier = (bundle.flags & 0x1);
      upcri_assert(upcr_threadof_shared(result) == 0);

      if (upcri_firsttouch) /* first-touch new global-heap pages as we notice them */
        upcri_update_globaltouch(bundle.out, nblocks, blocksz, touchbarrier);
      if (touchbarrier) { /* barrier to ensure first-touch is globally complete */
	UPCRI_SINGLE_BARRIER();
      }
    }

    #define UPCRI_PEVT_ARGS , nblocks, blocksz, &result
    upcri_pevt_end(GASP_UPC_ALL_ALLOC);
    #undef UPCRI_PEVT_ARGS

    #ifdef GASNET_TRACE
    { char ptrstr[UPCRI_DUMP_MIN_LENGTH];
      upcri_dump_shared(result, ptrstr, UPCRI_DUMP_MIN_LENGTH);
      UPCRI_TRACE_PRINTF(("HEAPOP upc_all_alloc(%llu, %llu) => %s", 
        (unsigned long long)(nblocks), (unsigned long long)(blocksz), ptrstr));
    }   
    #endif
    return upcri_checkvalid_shared(result);
}

/* Local heapsizes only get larger, and under correct usage, the pointer
 * passed to this function can't come from a region resulting from an increase
 * that this function misses by not having the lock.  So we don't need to
 * grab the lock to read the heap size here.
 * */
static int
upcri_ptr_within_local_heap(void *ptr, upcr_thread_t pthread)
{
    uintptr_t addr = (uintptr_t)ptr;
    uintptr_t start = localheap(pthread)->startaddr;
    uintptr_t len = localheap(pthread)->size;
    if ( addr < start || addr > (start + len) )
	return 0;
    return 1;
}

/* No need to grab lock to read global_heapsize, for some reason as above */
static int
upcri_ptr_within_global_heap(void * ptr)
{
    uintptr_t addr = (uintptr_t)ptr;
    uintptr_t start = global_heap.startaddr;
    uintptr_t len = global_heap.size;
#ifdef UPCR_GLOBALHEAP_GROWS_UP
    if ( addr < start || addr > (start + len) )
	return 0;
#else
    if ( addr > start || addr < (start - len) )
	return 0;
#endif
    return 1;
}


/*
 * upcri_do_local_free
 * AM-safe
 */
void 
upcri_do_local_free(upcr_shared_ptr_t sptr)
{
    void *addr;
    upcr_thread_t thread;
    upcri_pthread_t pthread;

    upcri_assert(upcri_shared_nodeof(sptr) == gasnet_mynode());
    thread = upcr_threadof_shared(sptr);
    pthread = upcri_thread_to_pthread(thread);
    /* Any pthread on the node can service this call, so use 'remote' addr
     * function to get local address */
    addr = upcri_shared_to_remote(sptr);

    if (upcri_ptr_within_local_heap(addr, pthread)) {
	upcri_localheap_t *h = localheap(pthread);
	gasnet_hsl_lock(&h->lock);
	upcra_sharedlocal_free(h->heap, MEMCHECK_PRE_FREE(addr, thread, 0));
	gasnet_hsl_unlock(&h->lock);
    } else if (upcri_ptr_within_global_heap(addr)) {
	if (gasnet_mynode() == 0) {
	    gasnet_hsl_lock(&global_heap.lock);
	    upcra_sharedglobal_free(global_heap.heap, MEMCHECK_PRE_FREE(addr, thread, 1));
	    gasnet_hsl_unlock(&global_heap.lock);
	} else {
	    upcri_err("Internal error in upcri_do_local_free()");
	}
    } else {
#if UPCR_DEBUG
	char buf[UPCRI_DUMP_MIN_LENGTH];
	upcri_dump_shared(sptr, buf, sizeof(buf));
	upcri_warn("upc_free called with bad pointer: %s", buf);
#endif
    }
}


/* 
 * This function is safe to call from handler context only if the pointer to
 * be freed was allocated from the same node as the call is made on.
 */
void 
_upcr_free(upcr_shared_ptr_t sptr UPCRI_PT_ARG)
{
    gasnet_node_t sptrnode = upcri_shared_nodeof(sptr);

    (void) upcri_checkvalid_shared(sptr);

  #ifdef GASNET_TRACE
    { char ptrstr[UPCRI_DUMP_MIN_LENGTH];
      upcri_dump_shared(sptr, ptrstr, UPCRI_DUMP_MIN_LENGTH);
      UPCRI_TRACE_PRINTF(("HEAPOP upc_free(%s)", ptrstr));
    }
  #endif

    #define UPCRI_PEVT_ARGS , &sptr
    upcri_pevt_start(GASP_UPC_FREE);

    if (upcr_isnull_shared(sptr)) { 
      /* upc_free(NULL) is a no-op */
    } else if (sptrnode == gasnet_mynode()) {
	upcri_do_local_free(sptr);
    } else {
	UPCRI_AM_CALL(UPCRI_MEDIUM_REQUEST(0, 0, 
		      (sptrnode, UPCRI_HANDLER_ID(upcri_free_MRequest), 
		       &sptr, sizeof(sptr))));
    }

    upcri_pevt_end(GASP_UPC_FREE);
    #undef UPCRI_PEVT_ARGS
}

void 
_upcr_all_free(upcr_shared_ptr_t sptr UPCRI_PT_ARG)
{
    (void) upcri_checkvalid_shared(sptr);

  #ifdef GASNET_TRACE
    { char ptrstr[UPCRI_DUMP_MIN_LENGTH];
      upcri_dump_shared(sptr, ptrstr, UPCRI_DUMP_MIN_LENGTH);
      UPCRI_TRACE_PRINTF(("HEAPOP upc_all_free(%s)", ptrstr));
    }
  #endif

    /* XXX:upc_all_free(NULL) is a no-op, except for tracing, and could skip this barrier */
    UPCRI_SINGLE_BARRIER();

    if (upcr_threadof_shared(sptr) == upcr_mythread()) {
        /* TODO: Do we want a distinct GASP event? */

        #define UPCRI_PEVT_ARGS , &sptr
        upcri_pevt_start(GASP_UPC_FREE);

        if (upcr_isnull_shared(sptr)) { 
          /* upc_all_free(NULL) is a no-op */
        } else {
          upcri_do_local_free(sptr);
        }

        upcri_pevt_end(GASP_UPC_FREE);
        #undef UPCRI_PEVT_ARGS
    }
}

void 
upcri_free_MRequest(gasnet_token_t token, void * addr, size_t len)
{
    upcri_assert(len == sizeof(upcr_shared_ptr_t));

    upcri_do_local_free(*((upcr_shared_ptr_t*)addr));
}



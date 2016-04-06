/*
 * UPC Runtime pthreads logic (and stubs for unthreaded processes). 
 *
 * Jason Duell <jcduell@lbl.gov>
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_threads.h $
 */

#ifndef UPCR_THREADS_H
#define UPCR_THREADS_H

GASNETT_BEGIN_EXTERNC

/*******************
 * Types
 *******************/

/* "Public size" for thread IDs: shared pointers may use something smaller */ 
typedef unsigned int upcr_thread_t;
#define UPCRI_INVALID_THREAD UINT_MAX

/* IDs for a node's pthreads: internal type */
typedef unsigned int upcri_pthread_t;

#define UPCRI_MAX_SPTRSZ 32 /* upper bound on space required for any pointer-to-shared */

/*******************
 * Global variables 
 *******************/

extern upcr_thread_t    upcri_threads;	      /* total # of UPC threads        */

#if ! UPCRI_SINGLE_ALIGNED_REGIONS
/* - thread2region maps UPC thread to starting address of its shared segment,
 *   for all threads.
 * - thread2local stores the correct offset for addrfields for local threads,
 *   or NULL if thread is remote.  
 */
extern uintptr_t      * upcri_thread2region;
extern uintptr_t      * upcri_thread2local;
#endif

/* For which threads are the shared heaps directly addressable? */
#if UPCRI_SYMMETRIC_SEGMENTS || UPCRI_USING_PSHM || UPCRI_UPC_PTHREADS
  /* Shared heaps of some or all non-local threads are addressable
   * - shared_thread stores list of directly addressable threads
   * - shared_threads is length of that list
   */
  #define UPCRI_SHARED_THREADS 1
  extern int * upcri_shared_thread, upcri_shared_threads;
#else
  /* Only the local segement is addressable */
  #define UPCRI_SHARED_THREADS 0
#endif

/* Equal values indicate GASNet nodes on same shared-memory node */
extern gasnet_nodeinfo_t  * upcri_nodeinfo;

extern uintptr_t upcri_perthread_segsize;  /* Size of each UPC thread's share of
					      shared memory segment */
extern uintptr_t upcri_perthread_heapsize; /* Size of each UPC thread's region
					      for combined local/global heaps */ 

extern int upcri_polite_wait; /* whether or not to use polite sync algorithms */

/* Support for alloca on systems which lack it natively */
#if HAVE_ALLOCA_H  || 1 /* Alternative is disabled - see bug 2131 */
  #define UPCRI_ALLOCA_DECLNOSEMI()
  #define UPCRI_ALLOCA_CLEANUP() do {} while(0)
#else
  #define UPCRI_ALLOCA_DECLNOSEMI() \
    ; void **_bupc_alloca_head = NULL /* intentional no semicolon */
  #define UPCRI_ALLOCA_CLEANUP()                      \
    while (_bupc_alloca_head) {                       \
      void **_bupc_alloca_next = *_bupc_alloca_head;  \
      free(_bupc_alloca_head);                        \
      _bupc_alloca_head = _bupc_alloca_next;          \
    }
#endif

/* stack-checking support */
#ifdef UPCR_DEBUG
  typedef struct {
    char *cold;
    char *hot; 
  } upcri_stackinfo_t;
  extern uintptr_t upcri_stacksz_threshhold;
  extern void upcri_stack_check(upcri_stackinfo_t *si, upcr_thread_t mythreadid, const char *filename, int linenum);
  #define UPCRI_STACK_CHECK_DECLNOSEMI() \
    ; const char _bupc_dummy_STACKCHECK = (upcri_stack_check(&(upcri_auxdata()->stack_info), \
                                           upcr_mythread(), __FILE__, __LINE__),0) \
                                           + (char)sizeof(_bupc_dummy_STACKCHECK) /* intentional no semicolon */
#else
  #define UPCRI_STACK_CHECK_DECLNOSEMI() 
#endif

#ifndef UPCRI_STACK_DEFAULT
#define UPCRI_STACK_DEFAULT (1*1024*1024) 
#endif
extern uintptr_t upcri_stacksz; /* approx stack size available */

/* thread-specific data for barriers */

typedef struct { /* Shared barrier state (single-writer, multiple-reader) */
#if (GASNETT_CACHE_LINE_BYTES > (2 * SIZEOF_INT))
  char _cache_pad[GASNETT_CACHE_LINE_BYTES - 2 * sizeof(int)];
#endif
  int value;
  int flags;
} upcri_barrier_args_t;

extern upcri_barrier_args_t *upcri_barrier_args;

typedef struct { /* Private barrier state */
  int barrier_phase;
  enum { 
      upcr_barrierstate_outsidebarrier = 0,
      upcr_barrierstate_insidebarrier
  } barrier_state;
  upcri_barrier_args_t *barrier_args;
} upcri_barrier_t;

/* thread-specific data for locks */
struct upcri_heldlock;
struct upcri_shared_lockinfo;
struct _upcri_lock_t;
typedef struct upcri_lockinfo {
    struct upcri_shared_lockinfo *shared;
    struct upcri_heldlock *locksheld;
    struct upcri_heldlock *freelist;
    upcr_thread_t next_affinity;
    volatile int need_gc;
    struct _upcri_lock_t *freelocks;
    gasnet_hsl_t hsl;
#ifdef GASNET_STATS
    int64_t alloccnt;
    int64_t freecnt;
    int64_t locklocal_cnt;
    int64_t lockremote_cnt;
    int64_t lockfaillocal_cnt;
    int64_t lockfailremote_cnt;
    int64_t unlocklocal_cnt;
    int64_t unlockremote_cnt;
    gasnett_tick_t waittime; /* total time spent blocking for lock acquisition */
#endif
} upcri_lockinfo_t;

/* thread-specific data for semaphores */
typedef uint32_t upcri_sem_seqnum_t; /* might expand this if it causes problems */
typedef struct upcri_seminfo {
  upcri_sem_seqnum_t next_seqnum;
  void **inittable;
  unsigned int inittable_sz;
  unsigned int inittable_cnt;
  void *freequeue;
  #if GASNET_STATS
    int64_t alloc_cnt;
    int64_t free_cnt;
    int64_t postlocal_cnt;
    int64_t postremote_cnt;
    int64_t putsignallocal_cnt;
    int64_t putsignalremote_cnt;
    int64_t putsignallocal_databytes;
    int64_t putsignalremote_databytes;
    int64_t waitlocal_cnt;
    int64_t waitremote_cnt;
    int64_t trylocal_cnt;
    int64_t tryremote_cnt;
    int64_t trylocal_failure_cnt;
    int64_t tryremote_failure_cnt;
    int64_t tinypacket_incoming_connections;
    int64_t tinypacket_outgoing_connections;
    int64_t tinypacket_send_cnt;
    int64_t tinypacket_databytes;
    int64_t tinypacket_backpressure_cnt;
    int64_t tinypacket_noconnection_cnt;
    int64_t post_short_cnt;
    int64_t put_medium_cnt;
    int64_t put_long_cnt;
    int64_t put_longasync_cnt;
    gasnett_tick_t waittime; /* total time spent blocking for sem wait */
  #endif
} upcri_seminfo_t;

/* runtime's thread-specific data, all of which are auto-init to zero
   access via: 
      upcri_auxdata()->fieldname
      or (for threads other than the current thread):
      upcri_hisauxdata(pthreadnum)->fieldname
 */
typedef struct {
  /* data which is either read-only after startup, 
     or read/written only by the owning pthread: */
  struct upcri_localheap *localheap;  /* pointer to local heap */

  void		**coll_dstlist; /* collective dst address list */
  void		**coll_srclist; /* collective src address list */

  void                *eop_freelist;  /* free list for memcpy_async handles */
  short               rand_state[3];  /* state for rand() */
  short               cpu;  /* cpu core to which thread is bound, or -1 if not bound */
  uint8_t             *globalheap_touchpos; /* high-water mark for globalheap affinity touching */
  #if UPCR_DEBUG
    int               finalbarrier_count; /* for early-exit detection */
  #endif

  #if UPCRI_GASP
    uint64_t          pevt_ptrtmp[UPCRI_MAX_SPTRSZ/8];
    gasp_context_t    pevt_context;
    int               pevt_pragma;
  #endif

  upcri_seminfo_t sem_info;

  #if UPCR_DEBUG
    upcri_stackinfo_t stack_info;      /* rough estimate of user stack extents */
  #endif

  upcri_barrier_t barrier_info;

  char _pad1[GASNETT_CACHE_LINE_BYTES];

  /* data which might be read/written by any pthread, 
     or should be cache-line-isolated for other reasons: */

  upcri_lockinfo_t lock_info;
  char _pad3[GASNETT_CACHE_LINE_BYTES];

} upcri_auxdata_t;

#if UPCRI_UPC_PTHREADS && !(UPCRI_USING_GCCUPC || UPCRI_USING_CUPC)
  /* use _upcr_pthreadinfo shadow arguments to amortize threadkey operations */
  #define UPCRI_PT_PASS_ENABLED 1
#endif

/******************************************************************************/
#ifdef UPCRI_UPC_PTHREADS
/******************************************************************************/

GASNETT_THREADKEY_DECLARE(upcri_pthread_key);
extern gasnet_node_t   *upcri_thread2node;    /* maps UPC threads to nodes     */
extern upcri_pthread_t *upcri_thread2pthread; /* UPC thread->local pthread num */
extern upcri_pthread_t *upcri_node1stthread;  /* # of first UPC thread on node */
extern upcri_pthread_t *upcri_node2pthreads;  /* # of pthreads per node	       */
extern int	        upcri_mypthread_cnt;  /* # of pthreads on this node    */

#ifndef UPCR_PTHREADS_SECTION
#  define UPCR_PTHREADS_STRUCT 1
#endif

/*
 * Per-pthread data struct.
 *
 * Note: UPC 'thread' rank spans nodes (processes), while pthread rank does
 * not.  So in a UPC process running on two 2-pthreaded nodes, the layout is
 *
 *	Node	UPC Thread	pthread 
 *	-------------------------------
 *	  0	    0		    0
 *	  0	    1		    1
 *	  1	    2		    0
 *	  1	    3		    1
 *
 * If we're using UPCR_PTHREADS_STRUCT, then this struct is the first member
 * of the upcri_tld_t struct that contains all thread-local data, so we can
 * cast back and forth between the types.
 */
typedef struct upcri_pthreadinfo {
    upcr_thread_t	mythread;	/* UPC thread rank (across nodes)   */
    gasnet_threadinfo_t gasnet_tinfo;	/* GASNet per-thread info	    */
    upcri_pthread_t	mypthread;	/* pthread rank (on this node)	    */
    uintptr_t		myregion;       /* start of this thread's shmem  */
#ifdef UPCR_USING_LINKADDRS
    uintptr_t		link_offset;    /* add to turn linker-assigned address 
					   into addr within shared segment  */
#endif
    /* most pthread-specific runtime data belongs
       in the auxdata struct, defined above */
    upcri_auxdata_t _auxdata;
} upcri_pthreadinfo_t;

/* must be less than GASNet's pthread limit */
#define UPCR_MAX_PTHREADS GASNETT_MAX_THREADS

extern upcri_pthreadinfo_t **upcri_pthreadtoinfo;  /* map of all pthread infos */

/* Thread local data interface.  */
#if UPCRI_PT_PASS_ENABLED
  #define upcri_mypthreadinfo()	_upcr_pthreadinfo
#else
  #define upcri_mypthreadinfo()	((upcri_pthreadinfo_t *)gasnett_threadkey_get_noinit(upcri_pthread_key))
#endif
#define upcr_mythread()		upcri_mypthreadinfo()->mythread
#define upcri_hispthreadinfo(pthreadnum) \
        (upcri_assert((pthreadnum) < upcri_mypthreads()), \
        upcri_pthreadtoinfo[pthreadnum])
#define upcri_mypthread()	upcri_mypthreadinfo()->mypthread
#define upcri_1stthread(node)  (upcri_assert((gasnet_node_t)node < gasnet_nodes()), \
                                upcri_node1stthread[node])
#define upcri_thread_to_pthread(upc_thread) \
        (upcri_assert((upcr_thread_t)upc_thread < upcr_threads()), \
                                upcri_thread2pthread[upc_thread])
#define upcri_myregion()	upcri_mypthreadinfo()->myregion

/* returns number of pthreads (per node) in use */
#define upcri_pthreads(node)	upcri_node2pthreads[node]
#define upcri_mypthreads()	upcri_mypthread_cnt

#define upcri_auxdata()              (&(upcri_mypthreadinfo()->_auxdata))
#define upcri_hisauxdata(pthreadnum) (&(upcri_hispthreadinfo(pthreadnum)->_auxdata))

#if UPCR_PTHREADS_STRUCT
# ifdef UPCRI_USING_TLD
 /* Store thread-local data in a upcri_tld_t struct, whose type definition is
  * not knowable until compile time.
  *
  *	int UPCR_TLD_DEFINE(foo, 4, 4) = 97;  
  *
  * defines a 4 byte int called 'foo' with initial value of 97.
  * Use the UPCR_TLD_DEFINE_TENTATIVE macro if a variable is defined
  * tentatively (i.e., without an initial value, but also without 'extern'):
  *
  * These macros are grepped out of the files by an external program, so don't
  * be confused if they appear to do nothing here.
  */

  /* all variables stored as char arrays, to avoid type conflicts and
   * declaration ordering issues.  */
#  ifndef UPCR_TLD_MAX_ALIGN
     /* Strictest alignment we've seen in practice is 16-bytes for long double on many platforms.
        We are assuming here that the struct itself will be allocated with sufficient alignment. */
#    define UPCR_TLD_MAX_ALIGN 16
#  endif
#  define UPCR_TLD_DEFINE(name, size, align)  char name[size];
#  define UPCR_TRANSLATOR_TLD(type, name, initval)  type name;
   struct upcri_tld_t {
      upcri_pthreadinfo_t upcri_tinfo;	/* MUST be first member of struct */
      char _upcri_alignment_padding[UPCR_TLD_MAX_ALIGN - (sizeof(upcri_pthreadinfo_t) & (UPCR_TLD_MAX_ALIGN-1))];
#  include "global.tld"
#  include <upcr_translator_tld.h>
   };
#  undef UPCR_TLD_DEFINE
#  undef UPCR_TRANSLATOR_TLD
   /* used for declarations: store initial value, detect name collisions */
#  define UPCR_TLD_DEFINE(name, size, align)		name
#  define UPCR_TLD_DEFINE_TENTATIVE(name, size, align)  name
   /* all references to TLD are by address */
#  define UPCR_TLD_ADDR(name) ((void *)&((struct upcri_tld_t *)upcri_mypthreadinfo())->name)
# endif /* ! UPCRI_USING_TLD */
#else
   struct upcri_tld_t {
      upcri_pthreadinfo_t upcri_tinfo;	/* MUST be first member of struct */
   };
#endif

/******************************************************************************/
#else /*********************** ! UPCRI_UPC_PTHREADS ***************************/
/******************************************************************************/
extern uintptr_t     upcri_myregion_single;    /* start of this process' shmem  */

#define UPCR_MAX_PTHREADS			1
#define upcr_mythread()				gasnet_mynode()
#define upcri_mypthread()			0
#define upcri_pthreads(node)			1
#define upcri_mypthreads()			1
#define upcri_1stthread(node)			node
#define upcri_thread_to_pthread(upc_thread)	0
#define upcri_myregion()			upcri_myregion_single

extern upcri_auxdata_t _upcri_auxdata;
#define upcri_auxdata()              (&_upcri_auxdata)
#define upcri_hisauxdata(pthreadnum) (upcri_assert((pthreadnum) == 0), upcri_auxdata())

#define UPCR_TLD_DEFINE(name, size, align)		name
#define UPCR_TLD_DEFINE_TENTATIVE(name, size, align)	name
#define UPCR_TLD_ADDR(name)				(&name)
/******************************************************************************/
#endif  /* UPCRI_UPC_PTHREADS */
/******************************************************************************/

#if UPCRI_PT_PASS_ENABLED

  #ifndef UPCRI_UPC_PTHREADS
    #error UPCRI_PT_PASS_ENABLED should only be enabled for UPCRI_UPC_PTHREADS
  #endif

  #define UPCRI_PT_ARG_ALONE  upcri_pthreadinfo_t * const _upcr_pthreadinfo
  #define UPCRI_PT_ARG	      , UPCRI_PT_ARG_ALONE
  #define UPCRI_PT_PASS_ALONE (upcri_assert(UPCRI_PTHREADINFO_VALID()), _upcr_pthreadinfo)
  #define UPCRI_PT_PASS	      , UPCRI_PT_PASS_ALONE

  #if HAVE_NONCONST_STRUCT_INIT
    #define UPCRI_PT_ARG_FIELD  UPCRI_PT_ARG_ALONE
  #else
    /* cannot use 'const' because we must initialize element-wise */
    #define UPCRI_PT_ARG_FIELD  upcri_pthreadinfo_t * _upcr_pthreadinfo
  #endif

  /* perform expensive lookup of pthreadinfo, return NULL for non-UPC threads */
  #define UPCRI_PTHREADINFO_LOOKUPDECL() UPCRI_PT_ARG_ALONE = gasnett_threadkey_get(upcri_pthread_key)
  #define UPCRI_PTHREADINFO_VALID()      (_upcr_pthreadinfo != NULL)

  #ifdef UPCR_DEBUG
    #define UPCRI_ASSERT_NONNULL_DECLNOSEMI(expr) \
      ; const char _bupc_dummy_NONNULL = (upcri_assert(expr != NULL),0) \
                                         + (char)sizeof(_bupc_dummy_NONNULL) /* intentional no semicolon */
  #else
    #define UPCRI_ASSERT_NONNULL_DECLNOSEMI(expr) 
  #endif

  #define UPCR_BEGIN_FUNCTION()                                          \
    UPCRI_ASSERT_NOTINAMHANDLER_DECL()  /* intentional no semicolon */   \
    UPCRI_PT_ARG_ALONE = gasnett_threadkey_get_noinit(upcri_pthread_key) \
    upcri_srcpos_declnosemi()           /* intentional no semicolon */   \
    UPCRI_ASSERT_NONNULL_DECLNOSEMI(upcri_mypthreadinfo()) /* ensure this is a runtime-created pthread */ \
    UPCRI_PEVT_BEGINFN_DECLNOSEMI()     /* intentional no semicolon */   \
    UPCRI_STACK_CHECK_DECLNOSEMI()      /* intentional no semicolon */   \
    UPCRI_ALLOCA_DECLNOSEMI()           /* intentional no semicolon */

#else /* !UPCRI_PT_PASS_ENABLED */

  #define UPCRI_PT_ARG_ALONE  void
  #define UPCRI_PT_ARG
  #define UPCRI_PT_PASS_ALONE
  #define UPCRI_PT_PASS

  #define UPCRI_PTHREADINFO_LOOKUPDECL() const char _bupc_dummy_PTHLOOKUP = \
                                             (char)sizeof(_bupc_dummy_PTHLOOKUP)
  #ifdef UPCRI_UPC_PTHREADS
    #define UPCRI_PTHREADINFO_VALID() (gasnett_threadkey_get(upcri_pthread_key) != NULL)
  #else
    #define UPCRI_PTHREADINFO_VALID() (1)
  #endif

  #define UPCR_BEGIN_FUNCTION()                                        \
    UPCRI_ASSERT_NOTINAMHANDLER_DECL()  /* intentional no semicolon */ \
    const int _bupc_dummy_BEGIN_FUNCTION = (int)sizeof(_bupc_dummy_BEGIN_FUNCTION) \
                                        /* intentional no semicolon */ \
    upcri_srcpos_declnosemi()           /* intentional no semicolon */ \
    UPCRI_PEVT_BEGINFN_DECLNOSEMI()     /* intentional no semicolon */ \
    UPCRI_STACK_CHECK_DECLNOSEMI()      /* intentional no semicolon */ \
    UPCRI_ALLOCA_DECLNOSEMI()           /* intentional no semicolon */

#endif

#define UPCR_EXIT_FUNCTION()  do { upcri_srcpos(); UPCRI_PEVT_EXITFN(); UPCRI_ALLOCA_CLEANUP(); } while (0)

/* number of UPC threads in the system */
#if __UPC_STATIC_THREADS__
  #define upcr_threads() THREADS
#else
  #define upcr_threads() upcri_threads
#endif

/* number of nodes in the job */
#define upcr_nodes() ((upcr_thread_t)gasnet_nodes())

/* Current thread's node number */

#define upcr_mynode() upcri_mynode
extern upcr_thread_t upcri_mynode;


/* gasnet node id for a given UPC thread */
#if UPCRI_UPC_PTHREADS
  #define upcri_thread_to_node(threadid) \
    (upcri_assert((upcr_thread_t)threadid < upcr_threads()), \
    upcri_thread2node[threadid])
#else
  #define upcri_thread_to_node(threadid) \
    (upcri_assert((upcr_thread_t)threadid < upcr_threads()), \
    (gasnet_node_t)(threadid))
#endif

/* thread is member of my gasnet node */
GASNETT_INLINE(upcri_thread_is_local)
int upcri_thread_is_local(upcr_thread_t thread)
{
#if UPCRI_UPC_PTHREADS
    return upcri_thread2local[thread] != 0;
#else
    return thread == gasnet_mynode();
#endif
}

/* thread is reachable by load/store */
GASNETT_INLINE(upcri_thread_is_addressable)
int upcri_thread_is_addressable(upcr_thread_t thread)
{
#if UPCRI_SYMMETRIC_SEGMENTS
    return 1;
#elif UPCRI_UPC_PTHREADS || UPCRI_USING_PSHM
    return upcri_thread2local[thread] != 0;
#else
    return thread == gasnet_mynode();
#endif
}

unsigned int _bupc_thread_distance(int x, int y UPCRI_PT_ARG);
#define bupc_thread_distance(x,y) \
       (upcri_srcpos(), _bupc_thread_distance((x),(y) UPCRI_PT_PASS))

/* C library decls that could probably live elsewhere... */
#define upcri_rand() _upcri_rand(UPCRI_PT_PASS_ALONE)
extern int _upcri_rand(UPCRI_PT_ARG_ALONE);
#define upcri_srand(x) _upcri_srand(x UPCRI_PT_PASS)
extern void _upcri_srand(unsigned int _seed UPCRI_PT_ARG);
#define upcri_rand_init() _upcri_rand_init(UPCRI_PT_PASS_ALONE)
extern void _upcri_rand_init(UPCRI_PT_ARG_ALONE);

GASNETT_END_EXTERNC

#endif /* UPCR_THREADS_H */

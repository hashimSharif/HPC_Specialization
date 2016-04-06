/*
 * UPC Runtime allocation functions.
 *
 * Jason Duell	<jcduell@lbl.gov>
 *
 * Includes hook to intercept C library's malloc(), free(), etc.
 * functions--we need to ensure they are guarded by handler-safe locks (see
 * gasnet docs for more info)
 */

#ifndef UPCR_ALLOC_H
#define UPCR_ALLOC_H

#if GASNET_DEBUGMALLOC
  #ifdef UPCR_DEBUGMALLOC
    /* Keep the current value */
  #else
    #define UPCR_DEBUGMALLOC 1
  #endif
#else
  /* Discard the current value, if any. */
  #undef UPCR_DEBUGMALLOC
#endif

/******************************************************************************
 * Override of Standard C library memory allocation functions
 ******************************************************************************/


/* Intercept all calls to malloc/free/etc.  Need to use critical sections for
 * handler safe locks, so handlers can call them, too.
 *
 * TODO:  #define of malloc is not a full solution--it will change any malloc
 * calls made within user UPC files, but will not change calls in C
 * objects/libraries that the user links into the app.  We need to figure out
 * a portable way to intercept malloc at the link symbol level.
 */

extern uint64_t upcri_stat_mallocsz;
extern int upcri_debug_malloc;

#ifndef UPCR_NO_SRCPOS
  /* ensure debug malloc reports caller line numbers for calls in user code */
  #undef GASNETT_MALLOC_USE_SRCPOS
  #define GASNETT_MALLOC_USE_SRCPOS 1
#endif

GASNETT_INLINE(upcri_malloc) GASNETT_MALLOC
void * upcri_malloc(size_t bytes) {
    UPCRI_PTHREADINFO_LOOKUPDECL_IFINST();
    void * retval;
    #ifdef GASNET_STATS
      /* there is a race condition here, but a relatively harmless one
         (this only provides an approximation of the memory 
          in use anyhow, because we don't track free sizes)
       */
      upcri_stat_mallocsz += bytes;
    #endif

    #define UPCRI_PEVT_ARGS , bytes
    upcri_pevt_start(GASP_C_MALLOC);
    #undef UPCRI_PEVT_ARGS

    #if UPCR_DEBUGMALLOC
      if (upcri_debug_malloc) retval = gasnett_debug_malloc(bytes);
      else 
    #endif
      {
        gasnet_hold_interrupts();
        retval = malloc(bytes);
        gasnet_resume_interrupts();
      }

    #define UPCRI_PEVT_ARGS , bytes, retval
    upcri_pevt_end(GASP_C_MALLOC);
    #undef UPCRI_PEVT_ARGS

    return retval;
}
GASNETT_MALLOCP(upcri_malloc)

GASNETT_INLINE(upcri_calloc) GASNETT_MALLOC
void * upcri_calloc(size_t N, size_t S) {
    size_t const NS = N * S;
    void * retval = upcri_malloc(NS);
    if (retval != NULL) memset(retval, 0, NS);
    return retval;
}
GASNETT_MALLOCP(upcri_calloc)

GASNETT_INLINE(upcri_realloc)
void * upcri_realloc(void *ptr, size_t bytes) {
    UPCRI_PTHREADINFO_LOOKUPDECL_IFINST();
    void * retval;
    #ifdef GASNET_STATS
      upcri_stat_mallocsz += bytes;
    #endif
    #define UPCRI_PEVT_ARGS , ptr, bytes
    upcri_pevt_start(GASP_C_REALLOC);
    #undef UPCRI_PEVT_ARGS

    #if UPCR_DEBUGMALLOC
      if (upcri_debug_malloc) retval = gasnett_debug_realloc(ptr, bytes);
      else 
    #endif
      {
        gasnet_hold_interrupts();
        retval = realloc(ptr, bytes);
        gasnet_resume_interrupts();
      }

    #define UPCRI_PEVT_ARGS , ptr, bytes, retval
    upcri_pevt_end(GASP_C_REALLOC);
    #undef UPCRI_PEVT_ARGS
    
    return retval;
}

GASNETT_INLINE(upcri_strdup) GASNETT_MALLOC
char * upcri_strdup(const char *s) {
  char *retval;
  if_pf (s == NULL) {
    /* special case to avoid strlen(NULL) */
    retval = (char *)upcri_malloc(1);
    retval[0] = '\0';
  } else {
    size_t sz = strlen(s) + 1;
    retval = (char *)memcpy((char *)upcri_malloc(sz), s, sz);
  }
  return retval;
}
GASNETT_MALLOCP(upcri_strdup)

GASNETT_INLINE(upcri_strndup) GASNETT_MALLOC
char * upcri_strndup(const char *s, size_t n) {
  char *retval;
  if_pf (s == NULL) {
    retval = (char *)upcri_malloc(1);
    retval[0] = '\0';
  } else {
    size_t len;
    for (len = 0; len < n && s[len]; len++) ;
    retval = (char *)upcri_malloc(len + 1);
    memcpy(retval, s, len);
    retval[len] = '\0';
  }
  return retval;
}
GASNETT_MALLOCP(upcri_strndup)

GASNETT_INLINE(upcri_free)
void upcri_free(void * addr) {
    UPCRI_PTHREADINFO_LOOKUPDECL_IFINST();
    #define UPCRI_PEVT_ARGS , addr
    upcri_pevt_start(GASP_C_FREE);

    #if UPCR_DEBUGMALLOC
      if (upcri_debug_malloc) gasnett_debug_free(addr);
      else 
    #endif
      {
        gasnet_hold_interrupts();
        free(addr);
        gasnet_resume_interrupts();
      }

    upcri_pevt_end(GASP_C_FREE);
    #undef UPCRI_PEVT_ARGS
}

/* 
 * Convenient "barf on failure", cast-free versions 
 */

#define UPCRI_XMALLOC(type, count)   \
	((type *) upcri_checkmalloc(sizeof(type) * (count)))

GASNETT_INLINE(upcri_checkmalloc) GASNETT_MALLOC
void * upcri_checkmalloc(size_t bytes) {
    void * retval = upcri_malloc(bytes);
    if_pf (retval == NULL)
	upcri_errno("malloc failed to allocate %lu bytes!", (unsigned long)bytes);
    return retval;
}
GASNETT_MALLOCP(upcri_checkmalloc)

#define UPCRI_XCALLOC(type, count)   \
	((type *) upcri_checkcalloc(sizeof(type) * (count)))

GASNETT_INLINE(upcri_checkcalloc) GASNETT_MALLOC
void * upcri_checkcalloc(size_t bytes) {
    void * retval = upcri_calloc(1, bytes);
    if_pf (retval == NULL)
	upcri_errno("calloc failed to allocate %lu bytes!", (unsigned long)bytes);
    return retval;
}
GASNETT_MALLOCP(upcri_checkcalloc)

/* for allocations before gasnet_attach() called */
#define UPCRI_XMALLOC_EARLY(type, count)   \
	((type *) upcri_checkmalloc_early(sizeof(type) * (count)))

GASNETT_INLINE(upcri_checkmalloc_early) GASNETT_MALLOC
void * upcri_checkmalloc_early(size_t bytes) {
    void *retval;
    #if UPCR_DEBUGMALLOC
      if (upcri_debug_malloc) retval = gasnett_debug_malloc(bytes);
      else 
    #endif
        retval = malloc(bytes);
    if_pf (retval == NULL)
	upcri_errno("malloc failed to allocate %lu bytes!", (unsigned long)bytes);
    return retval;
}
GASNETT_MALLOCP(upcri_checkmalloc_early)

#if UPCR_DEBUGMALLOC
  #define upcri_memcheck(ptr) \
        ( upcri_debug_malloc ? (void)gasnett_debug_memcheck(ptr) : (void)0) 
  #define upcri_memcheck_one() gasnett_debug_memcheck_one()
  #define upcri_memcheck_all() gasnett_debug_memcheck_all()
#else
  #define upcri_memcheck(ptr)      ((void)0) 
  #define upcri_memcheck_one()     ((void)0)
  #define upcri_memcheck_all()     ((void)0)
#endif

#ifdef malloc
#undef malloc
#endif
#define malloc(sz)    (upcri_srcpos(), upcri_malloc(sz))
#ifdef calloc
#undef calloc
#endif
#define calloc(N,S)   (upcri_srcpos(), upcri_calloc((N),(S)))
#ifdef realloc
#undef realloc
#endif
#define realloc(p,sz) (upcri_srcpos(), upcri_realloc(p,sz))
#ifdef strdup
#undef strdup
#endif
#define strdup(s)     (upcri_srcpos(), upcri_strdup(s))
#ifdef strndup
#undef strndup
#endif
#define strndup(s,n)  (upcri_srcpos(), upcri_strndup(s,n))
#ifdef free
#undef free
#endif
#define free(p)       (upcri_srcpos(), upcri_free(p))

/******************************************************************************
 * UPC shared memory allocation functions:
 ******************************************************************************/

/* ALLOCCALLER: used to pass status information about the reason for a given 
   shared allocation, so we can report that info in errors and diagnostics.
   Info is packed into a convenient integer for ease and performance of AM passing.
 */
typedef uint32_t upcri_alloccaller_t;
#define UPCRI_ALLOCCALLERFN_LOCAL  0
#define UPCRI_ALLOCCALLERFN_GLOBAL 1
#define UPCRI_ALLOCCALLERFN_ALL    2
#define UPCRI_ALLOCCALLERFN_FREE   3
extern const char *upcri_alloccaller_fntable[];
#define UPCRI_ALLOCCALLER(callerfn, callerthread) \
  ((upcri_alloccaller_t) ((((uint32_t)(callerthread))<<2) | ((callerfn) & 0x3) ))
#define UPCRI_ALLOCCALLER_FN(alloccaller) \
  (upcri_alloccaller_fntable[((upcri_alloccaller_t)(alloccaller))&0x3])
#define UPCRI_ALLOCCALLER_THREAD(alloccaller) \
  ((upcr_thread_t)(((upcri_alloccaller_t)(alloccaller))>>2))

/* Non-collective operation that allocates nbytes bytes in the
 * shared memory area with affinity to this thread, and returns a pointer to
 * the new memory, which is suitably aligned for any kind of variable. 
 *
 * Requires nbytes >= 0.
 *
 * The memory is not cleared or initialized in any way, although it has been
 * properly registered with the network system in a way appropriate for the
 * current platform such that remote threads can read and write to the memory
 * using upcr shared data transfer operations. 
 *
 * If insufficient memory is available, the function will print an
 * implementation-defined error message and terminate the job.
 *
 * The phase of the returned pointer is set to zero
 */
#define upcr_alloc(nbytes) \
       (UPCRI_TRACE_PRINTF(("HEAPOP upc_alloc(%llu)", (unsigned long long)(nbytes))), \
        upcri_srcpos(), _upcr_alloc(nbytes UPCRI_PT_PASS))

upcr_shared_ptr_t _upcr_alloc(size_t nbytes UPCRI_PT_ARG) GASNETT_WARN_UNUSED_RESULT;

/* Non-collective operation that allocates nblocks * blocksz bytes spread
 * across the shared memory area of 1 or more threads, and returns a pointer
 * to the new data, which is suitably aligned for any kind of variable. 
 *
 * Requires nblocks >= 0 and blocksz >= 0.
 *
 * The memory is blocked across all the threads as if it had been created by
 * the UPC declaration: 
 *
 *    shared [blocksz] char[nblocks * blocksz] (i.e. both sizes are in bytes).
 *
 * Specifically, thread i allocates at least this many bytes:
 *
 *    blocksz *  ceil(nblocks/THREADS)  if i <= (nblocks % THREADS)
 *    blocksz * floor(nblocks/THREADS)  if i >  (nblocks % THREADS)
 *
 * Implementor's note: Some implementations may allocate the full (blocksz *
 * ceil(nblocks/THREADS)) memory on each thread for simplicity, even though
 * less may be required on some threads.

 * Note if nblocks == 1, then all the memory will be allocated in the shared
 * memory space of thread 0 (and implementations should attempt not to waste
 * space on other threads in this common special case).

 * In all cases the returned pointer will point to a memory location in the
 * shared memory space of thread 0, and any subsequent chunks in the shared
 * space of other threads will be logically aligned with this pointer (such
 * that incrementing a shared pointer of the appropriate blocksz past the end
 * of a block on one thread will bring it to the start of the next block on
 * the next thread).

 * The phase of the returned pointer is set to zero.

 * The memory is not cleared or initialized in any way, although it has been
 * properly registered with the network system in a way appropriate for the
 * current platform such that remote threads can read and write to the memory
 * using the upcr shared data transfer operations. 
 *
 * If insufficient memory is available, the function will print an
 * implementation-defined error message and terminate the job.
 */
#define upcr_global_alloc(nblocks, blocksz) \
       (UPCRI_TRACE_PRINTF(("HEAPOP upc_global_alloc(%llu, %llu)", \
          (unsigned long long)(nblocks), (unsigned long long)(blocksz))), \
        upcri_srcpos(), _upcr_global_alloc(nblocks, blocksz UPCRI_PT_PASS))

upcr_shared_ptr_t _upcr_global_alloc(size_t nblocks, size_t blocksz UPCRI_PT_ARG) GASNETT_WARN_UNUSED_RESULT;


/* Collective version of upcr_global_alloc() - the semantics are identical to
 * upcr_global_alloc() with the following exceptions:
 *   -- The function must be called by all threads during the same
 *	synchronization phase, and all threads must provide the same
 *	arguments.
 *   -- The function may act as a barrier for all threads, but might not in
 *	some implementations.
 *   -- All threads receive a copy of the result, and the shared pointer
 *	values will compare equal (according to upcr_isequal_shared_shared())
 *	on all threads.
 */

#define upcr_all_alloc(nblocks, blocksz) \
       (UPCRI_TRACE_PRINTF(("HEAPOP upc_all_alloc(%llu, %llu)", \
          (unsigned long long)(nblocks), (unsigned long long)(blocksz))), \
        upcri_srcpos(), _upcr_all_alloc(nblocks, blocksz UPCRI_PT_PASS))

upcr_shared_ptr_t _upcr_all_alloc(size_t nblocks, size_t blocksz UPCRI_PT_ARG) GASNETT_WARN_UNUSED_RESULT;

/* Non-collective operation used to deallocate a shared memory region
 * previously allocated (but not deallocated) using one of:
 * upcr_alloc(), upcr_global_alloc() or upcr_all_alloc(). 
 *
 * If sptr is a null pointer the operation is ignored. 
 *
 * The shared pointer value passed to upcr_free() must be the same value
 * returned by the allocation function that created the region (i.e. it must
 * point to the beginning of the object, and for upcr_global_alloc() and
 * upcr_all_alloc() the thread field must indicate thread 0). 
 *
 * If sptr has been freed by a prior call to upcr_free() or upcr_all_free(),
 * or does not point to the beginning of a live object in shared memory, the
 * behavior is undefined. 
 *
 * Note that any thread may call upcr_free() to free a given
 * dynamically-allocated shared object, even if that object was created by a
 * call to upcr_alloc() from a different thread.
 *
 * Also note that memory allocated using upcr_all_alloc() should only be freed
 * by a call to upcr_free() from a _single_ thread, or using upcr_all_free().
 */

#define upcr_free(sptr)		      \
       (upcri_srcpos(), _upcr_free(sptr UPCRI_PT_PASS))

void _upcr_free(upcr_shared_ptr_t sptr UPCRI_PT_ARG);

/* Collective operation used to deallocate a shared memory region previously
 * allocated (but not deallocated) using one of:
 * upcr_alloc(), upcr_global_alloc() or upcr_all_alloc(). 
 *
 * If sptr is a null pointer the operation is ignored. 
 *
 * The shared pointer value passed to upcr_all_free() must be the same value
 * returned by the allocation function that created the region (i.e. it must
 * point to the beginning of the object, and for upcr_global_alloc() and
 * upcr_all_alloc() the thread field must indicate thread 0). 
 *
 * If sptr has been freed by a prior call to upcr_free() or upcr_all_free(),
 * or does not point to the beginning of a live object in shared memory, the
 * behavior is undefined. 
 */
#define upcr_all_free(sptr)		      \
       (upcri_srcpos(), _upcr_all_free(sptr UPCRI_PT_PASS))

void _upcr_all_free(upcr_shared_ptr_t sptr UPCRI_PT_ARG);


extern void upcri_getheapstats(const char *prefix, char *buf, size_t bufsz);


/* LEGACY (to be removed at UPC-1.4) ONLY: */
UPCRI_DEPRECATED_STUB(bupc_all_free)
#define bupc_all_free(sptr) (bupc_all_free (), upcr_all_free(sptr))

#endif /* UPCR_ALLOC_H */


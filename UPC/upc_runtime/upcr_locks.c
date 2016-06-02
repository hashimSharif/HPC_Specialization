/*   $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_locks.c $
 * Description: UPC lock implementation on GASNet
 * Copyright 2002, Dan Bonachea <bonachea@cs.berkeley.edu>
 */

#include <upcr_internal.h>
#include <upcr_handlers.h>

#ifndef UPCRI_USE_SMPLOCKS
#define UPCRI_USE_SMPLOCKS 1
#endif
#ifndef UPCRI_CACHEPAD_SMPLOCKS
#define UPCRI_CACHEPAD_SMPLOCKS 1
#endif
#ifndef UPCRI_LOCKS_PSHARED
#define UPCRI_LOCKS_PSHARED 1
#endif

/* -------------------------------------------------------------------------- */
#if GASNET_CONDUIT_SMP && !GASNET_PSHM && UPCRI_USE_SMPLOCKS
  /* implement upc_lock_t using bare pthread mutexes to save some overhead
     this is *only* safe because smp-conduit has a no-op AMPoll
   */
  #if UPCRI_SUPPORT_PTHREADS
    #define UPCRI_MUTEX_LOCKT               gasnett_mutex_t
    #define _UPCRI_MUTEX_LOCKINIT(pmutex)   do {  \
            memset((pmutex),0,sizeof(*(pmutex))); \
            gasnett_mutex_init(pmutex);           \
      } while (0)
    #define _UPCRI_MUTEX_LOCK(pmutex) do {                                \
      if_pf (upcri_polite_wait) gasnett_mutex_lock(pmutex);               \
      else while (gasnett_mutex_trylock(pmutex)) gasnett_spinloop_hint(); \
    } while (0)
    #define _UPCRI_MUTEX_TRYLOCK(pmutex)     (!gasnett_mutex_trylock(pmutex))
    #define _UPCRI_MUTEX_UNLOCK(pmutex)      gasnett_mutex_unlock(pmutex)
    #define _UPCRI_MUTEX_DESTROY(pmutex)     gasnett_mutex_destroy_ignoreerr(pmutex)
  #else
    #undef UPCRI_CACHEPAD_SMPLOCKS
    #define UPCRI_CACHEPAD_SMPLOCKS 0 /* no point in wasting space */
    #define UPCRI_MUTEX_LOCKT                char
    #define _UPCRI_MUTEX_LOCKINIT(pmutex)    ((void)0)
    #define _UPCRI_MUTEX_LOCK(pmutex)        ((void)0)
    #define _UPCRI_MUTEX_TRYLOCK(pmutex)     (1)
    #define _UPCRI_MUTEX_UNLOCK(pmutex)      ((void)0)
    #define _UPCRI_MUTEX_DESTROY(pmutex)     ((void)0)
  #endif
  #if UPCR_LOCK_DEBUG
    #define UPCRI_LOCKC_LOCKT          \
      typedef struct _upcri_lock_t {   \
        UPCRI_MUTEX_LOCKT mutex;       \
        uint8_t islocked;              \
        upcr_thread_t owner_thread_id; \
        gasnett_atomic_t num_waiters;  \
      } upcri_lock_t
    #define UPCRI_LOCKC_LOCKINIT(lockaddr) do {             \
        (lockaddr)->islocked = 0;                           \
        (lockaddr)->owner_thread_id = UPCRI_INVALID_THREAD; \
        gasnett_atomic_set(&((lockaddr)->num_waiters), 0, 0); \
        _UPCRI_MUTEX_LOCKINIT(&((lockaddr)->mutex));        \
      } while (0)
    #define UPCRI_MUTEX_LOCK(lockaddr) do {                                   \
        gasnett_atomic_increment(&((lockaddr)->num_waiters), 0);              \
        _UPCRI_MUTEX_LOCK(&((lockaddr)->mutex));                              \
        upcri_assert(!(lockaddr)->islocked &&                                 \
                       (lockaddr)->owner_thread_id == UPCRI_INVALID_THREAD);  \
        upcri_assert(gasnett_atomic_read(&((lockaddr)->num_waiters), 0) > 0); \
        gasnett_atomic_decrement(&((lockaddr)->num_waiters), 0);              \
        (lockaddr)->islocked = 1;                                             \
        (lockaddr)->owner_thread_id = upcr_mythread();                        \
      } while (0)
    #define UPCRI_MUTEX_TRYLOCK(lockaddr,success) do {                    \
        success = _UPCRI_MUTEX_TRYLOCK(&((lockaddr)->mutex));             \
        if (success) {                                                    \
          upcri_assert(!(lockaddr)->islocked &&                           \
                       (lockaddr)->owner_thread_id == UPCRI_INVALID_THREAD); \
          (lockaddr)->islocked = 1;                                       \
          (lockaddr)->owner_thread_id = upcr_mythread();                  \
        }                                                                 \
      } while (0)
    #define UPCRI_MUTEX_UNLOCK(lockaddr) do {                        \
       upcri_assert((lockaddr)->islocked);                           \
       upcri_assert((lockaddr)->owner_thread_id == upcr_mythread()); \
       (lockaddr)->islocked = 0;                                     \
       (lockaddr)->owner_thread_id = UPCRI_INVALID_THREAD;           \
       _UPCRI_MUTEX_UNLOCK(&((lockaddr)->mutex));                    \
      } while (0)
    #define UPCRI_MUTEX_DESTROY(lockptr, lockaddr) do {                  \
        upcri_heldlock_t * _hl = NULL;                                   \
        upcr_thread_t _tmp = (lockaddr)->owner_thread_id;                \
        do {                                                             \
          if ((_tmp != upcr_mythread()) &&                               \
	      _UPCRI_MUTEX_TRYLOCK(&((lockaddr)->mutex))) {              \
            /* now hold the "raw" mutex w/o any held-locks list entry */ \
            break;                                                       \
          } else if (_tmp != UPCRI_INVALID_THREAD) {                     \
            upcri_lockinfo_t * _li = upcri_getlockinfo(_tmp);            \
            gasnet_hsl_lock(&(_li->hsl));                                \
            _hl = upcri_heldlock_find(_li, lockptr);                     \
            if (_hl) {                                                   \
              _hl->freed = 1;                                            \
              gasnett_local_wmb();                                       \
              _li->need_gc = 1;                                          \
            } /* else: the holder released before we could catch it */   \
            gasnet_hsl_unlock(&(_li->hsl));                              \
          }                                                              \
        } while (!_hl);                                                  \
        if (gasnett_atomic_read(&((lockaddr)->num_waiters), 0) > 0)      \
          upcri_err("upc_lock_free() was called on a upc_lock_t *,"      \
                    " while one or more threads were blocked trying to " \
                    "acquire it in upc_lock()");                         \
        _UPCRI_MUTEX_DESTROY(&((lockaddr)->mutex));                      \
        memset((void*)&((lockaddr)->num_waiters),0,sizeof(gasnett_atomic_t));\
      } while (0)
  #else
    #if UPCRI_CACHEPAD_SMPLOCKS
      #define UPCRI_LOCKC_LOCKT                                                             \
        typedef struct _upcri_lock_t {                                                      \
          UPCRI_MUTEX_LOCKT mutex;                                                          \
          char _pad[MAX(8,(int)GASNETT_CACHE_LINE_BYTES - (int)sizeof(UPCRI_MUTEX_LOCKT))]; \
        } upcri_lock_t
      #define UPCRI_LOCKC_LOCKINIT(lockaddr)          _UPCRI_MUTEX_LOCKINIT(&((lockaddr)->mutex))
      #define UPCRI_MUTEX_LOCK(lockaddr)              _UPCRI_MUTEX_LOCK(&((lockaddr)->mutex))
      #define UPCRI_MUTEX_TRYLOCK(lockaddr, success)  success = _UPCRI_MUTEX_TRYLOCK(&((lockaddr)->mutex))
      #define UPCRI_MUTEX_UNLOCK(lockaddr)            _UPCRI_MUTEX_UNLOCK(&((lockaddr)->mutex))
      #define UPCRI_MUTEX_DESTROY(lockptr, lockaddr)  _UPCRI_MUTEX_DESTROY(&((lockaddr)->mutex))
    #else
      #define UPCRI_LOCKC_LOCKT                       typedef UPCRI_MUTEX_LOCKT upcri_lock_t
      #define UPCRI_LOCKC_LOCKINIT(lockaddr)          _UPCRI_MUTEX_LOCKINIT(lockaddr)
      #define UPCRI_MUTEX_LOCK(lockaddr)              _UPCRI_MUTEX_LOCK(lockaddr)
      #define UPCRI_MUTEX_TRYLOCK(lockaddr, success)  success = _UPCRI_MUTEX_TRYLOCK(lockaddr)
      #define UPCRI_MUTEX_UNLOCK(lockaddr)            _UPCRI_MUTEX_UNLOCK(lockaddr)
      #define UPCRI_MUTEX_DESTROY(lockptr, lockaddr)  _UPCRI_MUTEX_DESTROY(lockaddr)
    #endif
  #endif
  
  #define UPCRI_LOCKC_LOCK(li, node, lockaddr, isblocking, success) do { \
      upcri_assert(node == gasnet_mynode());                             \
      if (isblocking) {                                                  \
          UPCRI_MUTEX_LOCK(lockaddr);                                    \
          success = 1;                                                   \
      } else UPCRI_MUTEX_TRYLOCK(lockaddr,success);                      \
    } while (0)
  #define UPCRI_LOCKC_UNLOCK(li, node, lockaddr) do { \
      upcri_assert(node == gasnet_mynode());          \
      UPCRI_MUTEX_UNLOCK(lockaddr);                   \
    } while (0)
  #define UPCRI_LOCKC_DESTROY(lockptr, lockaddr) do { \
      UPCRI_MUTEX_DESTROY(lockptr, lockaddr);         \
      _upcr_free(lockptr UPCRI_PT_PASS);              \
    } while (0)
#else
  #define UPCRI_AMLOCKS  1
#endif
/* -------------------------------------------------------------------------- */

/* These macros are for compile-time elimination of AM threadid args
 * which can be determined implicitly from the GASNet node numbers.
 */
#if UPCRI_UPC_PTHREADS
  /* Cannot assume tid, so tids are passed in AM Args */
  #define UPCR_LOCK_TID_OF_RCVR(var) /*empty*/
  #define UPCR_LOCK_TID_ARG(X)       ,X
  #define UPCRI_LOCK_REQUEST(A32S,A64S,A32P,A64P,ARGS) \
                                     UPCRI_SHORT_REQUEST(A32P,A64P,ARGS)
  #define UPCRI_LOCK_REPLY(A32S,A64S,A32P,A64P,ARGS) \
                                     UPCRI_SHORT_REPLY(A32P,A64P,ARGS)
#else
  /* Can assume tid == node, so tids are obtained from gasnet_mynode() */
  #define UPCR_LOCK_TID_OF_RCVR(var) \
      upcr_thread_t var = gasnet_mynode();
  #define UPCR_LOCK_TID_ARG(X)       /*empty*/
  #define UPCRI_LOCK_REQUEST(A32S,A64S,A32P,A64P,ARGS) \
                                     UPCRI_SHORT_REQUEST(A32S,A64S,ARGS)
  #define UPCRI_LOCK_REPLY(A32S,A64S,A32P,A64P,ARGS) \
                                     UPCRI_SHORT_REPLY(A32S,A64S,ARGS)
#endif
/* -------------------------------------------------------------------------- */

/* low-level locks controlling access the internals of the MCS lock */

#if GASNETT_STRONGATOMIC_NOT_SIGNALSAFE
  /* Disable PSHARED locks when shared-memory-safe atomics are unavailable.
   * TODO: Remove the "fallback" to spinlocks from the PSHARED mutex code?
   * XXX: The assumption that (signal-safe == shared-mem-safe) is not true
   *      in general, but for current GASNet platforms will only err on
   *      the side of safety (by excluding PA-RISC and SPARC<v8).
   */
  #undef UPCRI_LOCKS_PSHARED
#endif

#if UPCRI_USING_PSHM || (UPCRI_SYMMETRIC_SEGMENTS && !GASNET_CONDUIT_SMP)
  #define UPCRI_LOCKS_SHARED 1
#else
  #define UPCRI_LOCKS_SHARED 0
#endif

#if !UPCRI_AMLOCKS
  /* Not implementing MCS locks at all */
  #undef UPCRI_LOCKS_PSHARED
  #define upcri_lllocksystem_init() ((void)0)
#elif !(UPCRI_LOCKS_PSHARED && UPCRI_LOCKS_SHARED)
  /* GASNet's HSLs only when lll cannot be in shared memory */
  #undef UPCRI_LOCKS_PSHARED
  #define upcri_lllocksystem_init() ((void)0)
  typedef gasnet_hsl_t upcri_lllock_t;
  #define upcri_lllock_init(_lp)    gasnet_hsl_init(_lp)
  #define upcri_lllock_fini(_lp)    gasnet_hsl_destroy(_lp)
  #define upcri_lllock_acquire(_lp) gasnet_hsl_lock(_lp)
  #define upcri_lllock_release(_lp) gasnet_hsl_unlock(_lp)
#else
  /* Spinlock code common to both implemetations below.
     Note the use of *strong* atomics is required for shared memory.
     TODO: linear or exponential backoff?
   */
  #define UPCRI_LLSPINLOCK_BUSY \
      if_pf (upcri_polite_wait) {   \
        gasnet_resume_interrupts(); \
        gasnett_sched_yield();      \
        gasnet_hold_interrupts();   \
      }                             \
      gasnett_spinloop_hint();
 #if GASNETT_HAVE_STRONGATOMIC_CAS
  /* Case I: spinlock via CAS-based version of a test-and-test-and-set */
  typedef gasnett_strongatomic_t upcri_llspinlock_t;
  enum {
  #if UPCR_LOCK_DEBUG
    UPCRI_LLSL_INVALID = 0,
  #endif
    UPCRI_LLSL_FREE,
    UPCRI_LLSL_HELD
  };
  #define upcri_llspinlock_init(_lp)    gasnett_strongatomic_set(_lp, UPCRI_LLSL_FREE, 0)
  #if UPCR_LOCK_DEBUG
    #define upcri_llspinlock_fini(_lp)  gasnett_strongatomic_set(_lp, UPCRI_LLSL_INVALID, 0)
  #else
    #define upcri_llspinlock_fini(_lp)  ((void)0)
  #endif
  GASNETT_INLINE(upcri_llspinlock_acquire)
  void upcri_llspinlock_acquire(upcri_llspinlock_t *lp) {
    while (!((gasnett_strongatomic_read(lp, 0) == UPCRI_LLSL_FREE) &&
             gasnett_strongatomic_compare_and_swap(lp,
                                                   UPCRI_LLSL_FREE, UPCRI_LLSL_HELD,
                                                   GASNETT_ATOMIC_ACQ_IF_TRUE))) {
    #if UPCR_LOCK_DEBUG
      gasnett_atomic_val_t readval = gasnett_strongatomic_read(lp,0);
      upcri_assert((readval == UPCRI_LLSL_FREE) || (readval == UPCRI_LLSL_HELD));
    #endif
      UPCRI_LLSPINLOCK_BUSY
    }
  }
  #define upcri_llspinlock_release(_lp) \
    gasnett_strongatomic_set(_lp, UPCRI_LLSL_FREE, GASNETT_ATOMIC_REL)
 #else
  /* Case II: spinlock via dec-and-test */
  typedef gasnett_strongatomic_t upcri_llspinlock_t;
  enum {
    UPCRI_LLSL_FREE = 1
  #if UPCR_LOCK_DEBUG
    , UPCRI_LLSL_INVALID = 2
  #endif
  };
  #define upcri_llspinlock_init(_lp)    gasnett_strongatomic_set(_lp, UPCRI_LLSL_FREE, 0)
  #if UPCR_LOCK_DEBUG
    #define upcri_llspinlock_fini(_lp)  gasnett_strongatomic_set(_lp, UPCRI_LLSL_INVALID, 0)
  #else
    #define upcri_llspinlock_fini(_lp)  ((void)0)
  #endif
  GASNETT_INLINE(upcri_llspinlock_acquire)
  void upcri_llspinlock_acquire(upcri_llspinlock_t *lp) {
    while ((gasnett_strongatomic_read(lp, 0) != UPCRI_LLSL_FREE) ||
           !gasnett_strongatomic_decrement_and_test(lp, GASNETT_ATOMIC_ACQ_IF_TRUE)) {
      upcri_assert(gasnett_strongatomic_read(lp, 0) != UPCRI_LLSL_INVALID);
      UPCRI_LLSPINLOCK_BUSY
    }
  }
  #define upcri_llspinlock_release(_lp) \
    gasnett_strongatomic_set(_lp, UPCRI_LLSL_FREE, GASNETT_ATOMIC_REL)
 #endif

  #if HAVE_PTHREAD_MUTEXATTR_SETPSHARED && defined(PTHREAD_PROCESS_SHARED) && 0
    /* XXX: disabled because testing so far shows no advantage over spinlocks */
    /* Pthread mutex with PTHREAD_PROCESS_SHARED attribute.
       Used only if pthread.h has beed included and setpshared is available.
       If setpshared fails at runtime, we fall back to spinlocks.
       We also use spinlocks if env var UPC_LOCKS_LL_SPINLOCK is "true".

       TODO: The configure-time check has actually RUN a test to see that
             we can creare a pshared mutex, EXCEPT when cross-compiling.
             So, should we ONLY fall-back in a cross-compiled build?
             Could/should we add a check to cross-configure-help.c?
       TODO: Do we want this at all?? 
             Spinlocks have timed as faster when uncontended.
             Mutexes have timed as faster under mild contention.
             Under contention to the point of 2X cpu-overcommit,
             they are nearly equivalent.
             However, the testing is still quite limited.
             So, why not JUST use the spinlocks?
     */
    static int upcri_pshared_mutex = 0; /* pshared support present/enabled */
    void upcri_lllocksystem_init(void) {
      pthread_mutexattr_t attr;
      pthread_mutex_t mutex;

      if (gasnett_getenv_yesno_withdefault("UPC_LOCKS_LL_SPINLOCK", 0)) return;

      if (! pthread_mutexattr_init(&attr)) {
        if (! pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED)) {
          if (! pthread_mutex_init(&mutex, &attr)) {
            upcri_pshared_mutex = 1;
            pthread_mutex_destroy(&mutex);
          }
        }
        pthread_mutexattr_destroy(&attr);
      }
    }

    typedef union {
        pthread_mutex_t    mutex;
        upcri_llspinlock_t spinlock;
    } upcri_lllock_t;
    void upcri_lllock_init(upcri_lllock_t *lp) {
      if (upcri_pshared_mutex) {
        pthread_mutexattr_t attr;
        /* TODO: don't simply ignore failure */
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
        pthread_mutex_init(&lp->mutex, &attr);
        pthread_mutexattr_destroy(&attr);
      } else {
        upcri_llspinlock_init(&lp->spinlock);
      }
    }
    void upcri_lllock_fini(upcri_lllock_t *lp) {
      if (upcri_pshared_mutex) {
        pthread_mutex_destroy(&lp->mutex);
      } else {
        upcri_llspinlock_fini(&lp->spinlock);
      }
    }
    GASNETT_INLINE(upcri_lllock_acquire)
    void upcri_lllock_acquire(upcri_lllock_t *lp) {
      gasnet_hold_interrupts();
      if (upcri_pshared_mutex) {
        pthread_mutex_t * const mp = &lp->mutex;
        if_pf (pthread_mutex_trylock(mp) == EBUSY) {
          if (upcri_polite_wait) {
            pthread_mutex_lock(mp);
          } else {
            while (pthread_mutex_trylock(mp) == EBUSY) {
              gasnett_compiler_fence();
              gasnett_spinloop_hint();
            }
          }
        }
      } else {
        upcri_llspinlock_acquire(&lp->spinlock);
      }
    }
    GASNETT_INLINE(upcri_lllock_release)
    void upcri_lllock_release(upcri_lllock_t *lp) {
      if (upcri_pshared_mutex) {
        pthread_mutex_unlock(&lp->mutex);
      } else {
        upcri_llspinlock_release(&lp->spinlock);
      }
      gasnet_resume_interrupts();
    }
  #else
    /* Pure spinlock implementation
       Used when pshared mutexes are not available.
     */
    #define upcri_lllocksystem_init() ((void)0)
    typedef upcri_llspinlock_t upcri_lllock_t;
    #define upcri_lllock_init(_lp)  upcri_llspinlock_init(_lp)
    #define upcri_lllock_fini(_lp)  upcri_llspinlock_fini(_lp)
    #define upcri_lllock_acquire(_lp) do { \
      gasnet_hold_interrupts();            \
      upcri_llspinlock_acquire(_lp);       \
    } while (0)
    #define upcri_lllock_release(_lp) do { \
      upcri_llspinlock_release(_lp);       \
      gasnet_resume_interrupts();          \
    } while (0)
  #endif
#endif

/* -------------------------------------------------------------------------- */
typedef struct upcri_heldlock {
    upcr_shared_ptr_t lockptr;
    struct upcri_heldlock *next; /* list successor */
#if UPCRI_AMLOCKS
    volatile upcr_thread_t next_thread; /* MCS successor or UPCRI_INVALID_THREAD */
    upcr_thread_t thread; /* owning thread needed for asychronous free-held-lock logic */
    uint32_t generation;
  #if UPCR_LOCK_DEBUG
    volatile int queued; /* boolean use to detect freed-with-waiters case */
  #endif
#endif
    volatile int freed; /* boolean for asychronous free-held-lock logic */
} upcri_heldlock_t;

#ifdef UPCRI_LOCKC_LOCKT
  UPCRI_LOCKC_LOCKT;
#else
  typedef struct _upcri_lock_t {
      upcri_heldlock_t *tail_addr; /* or 'next' when on freelist */
      upcr_thread_t     tail_thread;
      upcri_lllock_t    lll;
    #if UPCRI_AMLOCKS
      uint32_t          generation;
    #endif
    #if UPCR_LOCK_DEBUG
      volatile int freed; /* boolean for detection of use-after-free */
    #endif
  } upcri_lock_t;
#endif

#if UPCRI_AMLOCKS
enum {
    UPCRI_UNLOCK_WAITING, /* Waiting for reply to change the value */
    UPCRI_UNLOCK_DONE,    /* Reply says we are finished */
    UPCRI_UNLOCK_PASS     /* Reply says we have a successor */
};

typedef struct upcri_shared_lockinfo {
    char _cache_pad1[GASNETT_CACHE_LINE_BYTES];
    void * volatile        reply_addr;   /* address portion of an AM reply */
    volatile upcr_thread_t reply_thread; /* thread portion of an AM reply */
    volatile uint32_t      reply_gen;    /* generation portion of an AM reply */
    volatile int           blocked;      /* non-zero when blocked waiting for a lock */
    volatile int           unlock_state; /* state of unlock messaging protocol */
    volatile int           need_gc;      /* non-zero when locksheld may contain freed entries */
    char _cache_pad2[GASNETT_CACHE_LINE_BYTES];
    upcri_heldlock_t       first_holder; /* the initial free list entry */
    char _cache_pad3[GASNETT_CACHE_LINE_BYTES];
} upcri_shared_lockinfo_t;

static uintptr_t upcri_sli_addrfield;
#endif

static upcr_thread_t upcri_locks_rr;

/* -------------------------------------------------------------------------- */
/* Given (thread, addr) return localized pointer or NULL.  */
GASNETT_INLINE(upcri_lock_localaddr)
void *upcri_lock_localaddr(upcr_thread_t thread, void *addr) {
  #if !UPCRI_AMLOCKS
    upcri_err("illegal call to upcri_lock_localaddr");
    return NULL;
  #elif UPCRI_UPC_PTHREADS || UPCRI_USING_PSHM
    const uintptr_t t2l = upcri_thread2local[thread];
    if (t2l) {
        return (void *)(t2l + ((uintptr_t)addr) UPCRI_MINUS_REMOTE_OFFSET(thread));
    }
    return NULL;
  #elif UPCRI_SYMMETRIC_SEGMENTS
    return addr;
  #else
    if (thread == upcr_mythread()) {
        return addr;
    }
    return NULL;
  #endif
}
/* -------------------------------------------------------------------------- */
/* Given (node,thread,addr) for a lock, return localized pointer or NULL.  */
#if UPCRI_LOCKS_PSHARED
  #define upcri_lock_pshared_addr(_n,_t,_a) ((upcri_lock_t*)upcri_lock_localaddr((_t),(_a)))
#else
  #define upcri_lock_pshared_addr(_n,_t,_a) (((_n) == gasnet_mynode()) ? (_a) : NULL)
#endif
/* -------------------------------------------------------------------------- */
#if UPCRI_AMLOCKS
  /* Given a local thread, return pointer to their shared lockinfo.  */
  GASNETT_INLINE(upcri_his_sharedlockinfo)
  upcri_shared_lockinfo_t *
  upcri_his_sharedlockinfo(upcr_thread_t thread)
  {
    upcri_assert(upcri_thread_is_local(thread));
  #if UPCRI_UPC_PTHREADS
    /* cheaper than going via upcri_hisauxdata() */
    return (upcri_shared_lockinfo_t *) (upcri_sli_addrfield + upcri_thread2local[thread]);
  #else
    return upcri_auxdata()->lock_info.shared;
  #endif
  }
  /* Given thread return localized pointer to their shared lockinfo, or NULL if remote.  */
  GASNETT_INLINE(upcri_get_sharedlockinfo_or_null)
  upcri_shared_lockinfo_t *
  upcri_get_sharedlockinfo_or_null(upcr_thread_t thread)
  {
  #if UPCRI_UPC_PTHREADS || UPCRI_USING_PSHM
    const uintptr_t t2l = upcri_thread2local[thread];
    if (t2l) {
        return (upcri_shared_lockinfo_t *) (upcri_sli_addrfield + t2l);
    }
    return NULL;
  #elif UPCRI_SYMMETRIC_SEGMENTS
    return (upcri_shared_lockinfo_t *) (upcri_sli_addrfield UPCRI_PLUS_REMOTE_OFFSET(thread));
  #else
    if (thread == upcr_mythread()) {
        return upcri_auxdata()->lock_info.shared;
    }
    return NULL;
  #endif
  }
#endif
/* Given a local thread return pointer to their lockinfo */
GASNETT_INLINE(upcri_getlockinfo)
upcri_lockinfo_t *
upcri_getlockinfo(upcr_thread_t threadnum)
{
    upcri_assert(upcri_thread_is_local(threadnum));
    return &(upcri_hisauxdata(upcri_thread_to_pthread(threadnum))->lock_info);
}
/* -------------------------------------------------------------------------- */
extern void _upcri_locksystem_init(UPCRI_PT_ARG_ALONE) { /* called by each pthread during startup */
  upcri_lockinfo_t * const li = &(upcri_auxdata()->lock_info);

  /* Initialize the low-level locks system if required */
  if (upcri_mypthread() == 0) {
    upcri_lllocksystem_init();
  }

  #if UPCRI_AMLOCKS
  { upcr_shared_ptr_t sli_array = upcr_all_alloc(upcr_threads(), sizeof(upcri_shared_lockinfo_t));
    if (upcri_mypthread() == 0) {
      /* Ick!
         It appears that w/o the following cast-to-volatile, gcc-4.4.2 on
         x86-64 generates code for the assignment which is equivalent to
            upcri_sli_addrfield = upcri_mypthread() ? upcri_sli_addrfield : addrfield(sli_array);
         using a branchless instruction seqence (e.g. a "cmov" instruction).
         The result is that there is a pthread race in which a non-zero
         pthread may read the initial 0 value and then write it back after
         pthread zero has written the correct value!
         We don't just make the variable "volatile" because we want the
         compiler to feel free to eliminate redundant loads.
       */
      *(volatile uintptr_t *)&upcri_sli_addrfield = upcr_addrfield_shared(sli_array);
    }
    li->shared = upcri_shared_to_remote_withthread(sli_array,upcr_mythread());
    li->freelist = &(li->shared->first_holder);
    li->freelist->next = NULL;
    li->freelist->thread = upcr_mythread();
    li->freelist->freed = 0;
    li->freelocks = NULL;
    li->shared->unlock_state = UPCRI_UNLOCK_DONE;
    li->shared->need_gc = 0;
    #define UPCRI_LOCKINFO_NEED_GC(_li) (_li)->shared->need_gc
  }
  #elif UPCR_LOCK_DEBUG
    li->freelist = NULL;
    li->need_gc = 0;
    #define UPCRI_LOCKINFO_NEED_GC(_li) (_li)->need_gc
  #endif

  #if UPCR_LOCK_DEBUG || UPCRI_AMLOCKS
    gasnet_hsl_init(&(li->hsl));
  #endif

  li->locksheld = NULL;

  /* For placement of locks allocated with upc_all_lock_alloc()
   * the new (>= 2.12.2) default is round-robin placement, rather
   * then the prior policy of placing them all on thread 0.
   */
  if (upcri_mypthread() == 0) {
    /* Use "width" of first node to layout locks */
  #if UPCRI_UPC_PTHREADS
    int tmp = upcri_node2pthreads[0];
    if (tmp == upcri_threads) tmp = 1; /* all threads on 1 node - use all pthreads */
  #else
    int tmp = 1;
  #endif
    if (1 == upcri_threads) tmp = 0; /* one thread - nothing to distribute over */
    tmp = gasnett_getenv_int_withdefault("UPC_LOCKS_RR",tmp,0) % upcri_threads;
    upcri_locks_rr = (tmp < 0) ? (tmp + upcri_threads) : tmp;
  }
  li->next_affinity = 0;
}
/* -------------------------------------------------------------------------- */
/* linked-list management for prefetch and for lock debug sanity checking */
#if UPCR_LOCK_DEBUG || UPCRI_AMLOCKS
  #if UPCR_LOCK_DEBUG
  /* Locate a specific entry in the held-lock list
     NOTE: caller must hold li->hsl
   */
  static upcri_heldlock_t *
  upcri_heldlock_find(upcri_lockinfo_t *li, upcr_shared_ptr_t lockptr) {
      upcri_heldlock_t *result;
      for (result = li->locksheld; result; result = result->next) {
          if (upcr_isequal_shared_shared(result->lockptr, lockptr)) {
              break;
          }
      }
      return result;
  }
  #endif /* UPCR_LOCK_DEBUG */
  /* Clean up any 'freed' lock holders */
  GASNETT_NEVER_INLINE(upcri_heldlock_gc,
  static void upcri_heldlock_gc(upcri_lockinfo_t *li)) {
      upcri_heldlock_t **prev_p, *p;

      /* Clear before doing work - ensures we can only err on the side of extra checks */
      UPCRI_LOCKINFO_NEED_GC(li) = 0;
      gasnett_compiler_fence();

      prev_p = &li->locksheld;
      p = li->locksheld;
      while (p) {
          upcri_heldlock_t * const next = p->next;
	  if (p->freed) {
              p->freed = 0;
	      *prev_p = p->next;
              p->next = li->freelist;
              li->freelist = p;
	  } else {
	      prev_p = &(p->next);
	  }
	  p = next;
      }
  }
  /* Push entry for new held lock onto the stack */
  #define upcri_heldlock_push(li, ib, p) \
          _upcri_heldlock_push(li, ib, p UPCRI_PT_PASS)
  GASNETT_INLINE(_upcri_heldlock_push)
  upcri_heldlock_t *
  _upcri_heldlock_push(upcri_lockinfo_t *li, int isblocking, upcr_shared_ptr_t lockptr UPCRI_PT_ARG) {
    upcri_heldlock_t *newentry;
    #if UPCR_LOCK_DEBUG
      gasnet_hsl_lock(&(li->hsl));
    #endif
      if_pf (UPCRI_LOCKINFO_NEED_GC(li)) {
          upcri_heldlock_gc(li);
      }
    #if UPCR_LOCK_DEBUG
      if (upcri_heldlock_find(li, lockptr)) {
	upcri_err("Attempted to acquire a upc_lock which was already held");
      }
    #endif
      if_pt (li->freelist) {
          newentry = li->freelist;
          li->freelist = newentry->next;
      } else {
	#if UPCRI_AMLOCKS
          #if UPCR_LOCK_DEBUG
            /* cannot call upcri_alloc with HSL held, since it might use AM */
            gasnet_hsl_unlock(&(li->hsl));
          #endif
          {
	      upcr_shared_ptr_t allocptr =
                  upcri_alloc(sizeof(upcri_heldlock_t), upcri_mypthread(),
                                    UPCRI_ALLOCCALLER(UPCRI_ALLOCCALLERFN_LOCAL,
                                                      upcr_mythread()));
	      newentry = upcr_shared_to_local(allocptr);
              newentry->thread = upcr_mythread(); /* never changes */
          }
          #if UPCR_LOCK_DEBUG
            gasnet_hsl_lock(&(li->hsl));
          #endif
	#else
	  newentry = (upcri_heldlock_t *) upcri_checkmalloc(sizeof(upcri_heldlock_t));
	#endif
        newentry->freed = 0; /* IF this ever changes, gc will change it back */
      }
      newentry->lockptr = lockptr;
    #if UPCRI_AMLOCKS
      newentry->next_thread = UPCRI_INVALID_THREAD;
    #endif
      newentry->next = li->locksheld;
      li->locksheld = newentry;
    #if UPCRI_AMLOCKS && UPCR_LOCK_DEBUG
      newentry->queued = isblocking;
    #endif
    #if UPCR_LOCK_DEBUG
      gasnet_hsl_unlock(&(li->hsl));
    #endif
      return newentry;
  }
  #if UPCRI_AMLOCKS
  /* Pop (and discard) top entry off of held-lock stack - for failed lock_attempt() */
  GASNETT_INLINE(upcri_heldlock_pop)
  void upcri_heldlock_pop(upcri_lockinfo_t *li, upcri_heldlock_t *p) {
    #if UPCR_LOCK_DEBUG
      gasnet_hsl_lock(&(li->hsl));
    #endif
      upcri_assert(li->locksheld == p); /* Must be at top of stack */
      li->locksheld = p->next;
      p->next = li->freelist;
      li->freelist = p;
    #if UPCR_LOCK_DEBUG
      gasnet_hsl_unlock(&(li->hsl));
    #endif
  }
  #endif
  /* Remove specific entry from held-lock list
     Though this moves it to the free list, the content remains "live"
   */
  GASNETT_INLINE(upcri_heldlock_unlink)
  upcri_heldlock_t *
  upcri_heldlock_unlink(upcri_lockinfo_t *li, upcr_shared_ptr_t lockptr) {
      upcri_heldlock_t **prev_p = &li->locksheld;
      upcri_heldlock_t *p, *result = NULL;

    #if UPCR_LOCK_DEBUG
      gasnet_hsl_lock(&(li->hsl));
    #endif
      p = li->locksheld;
      while (p) {
	  if (upcr_isequal_shared_shared(p->lockptr, lockptr)) {
	      *prev_p = p->next;
              p->next = li->freelist;
              li->freelist = p;
	      result = p;
	      break;
	  }
	  prev_p = &(p->next);
	  p = p->next;
      }
    #if UPCR_LOCK_DEBUG
      gasnet_hsl_unlock(&(li->hsl));
    #endif
      return result;
  }
#endif
/* -------------------------------------------------------------------------- */
#define upcri_createlock() _upcri_createlock(UPCRI_PT_PASS_ALONE)

static upcr_shared_ptr_t _upcri_createlock(UPCRI_PT_ARG_ALONE) {
    upcr_shared_ptr_t retval;
    upcri_lock_t *ul;

   #if UPCRI_AMLOCKS
    upcri_lockinfo_t * const li = &(upcri_auxdata()->lock_info);
    gasnet_hsl_lock(&li->hsl);
      ul = li->freelocks;
      if (ul) li->freelocks = *(upcri_lock_t **)ul;
    gasnet_hsl_unlock(&li->hsl);

    if (ul) {
      retval = upcr_local_to_shared_withphase(ul, 0, upcr_mythread());
    } else
   #endif
    {
      retval = upcr_alloc(sizeof(upcri_lock_t));
      ul = upcri_shared_to_remote(retval);
    #ifndef UPCRI_LOCKC_LOCKINIT
      upcri_lllock_init(&(ul->lll));
     #if UPCRI_AMLOCKS
      ul->generation = 0;
     #endif
    #endif
    }

  #ifdef UPCRI_LOCKC_LOCKINIT
    UPCRI_LOCKC_LOCKINIT(ul);
  #else
  /*ul->tail_addr   = NULL;  unnecessary */
    ul->tail_thread = UPCRI_INVALID_THREAD;
   #if UPCR_LOCK_DEBUG
    ul->freed = 0;
   #endif
  #endif
    return retval;
}

/* -------------------------------------------------------------------------- */
#if UPCRI_AMLOCKS
GASNETT_INLINE(upcri_doSRQ_lockdestroy)
void upcri_doSRQ_lockdestroy(upcr_thread_t lock_threadid,
                             upcri_lock_t *lock,
                             upcr_thread_t *tail_thread_p,
                             upcri_heldlock_t **tail_addr_p) {

    upcri_lllock_acquire(&(lock->lll));
      #if UPCR_LOCK_DEBUG
        if_pf (lock->freed) {
          upcri_err("Attempted to free a upc_lock_t multiple times");
        }
        /* Help detect invalid use after free (and limit "damage" from such errors) */
        lock->freed = 1;
      #endif
      lock->generation += 1;
      *tail_addr_p   = lock->tail_addr;
      *tail_thread_p = lock->tail_thread;
    upcri_lllock_release(&(lock->lll));

 /* upcri_lllock_fini(&(lock->lll)); - avoid extra work when recycled */

    {
      upcri_lockinfo_t *li = upcri_getlockinfo(lock_threadid);
      gasnet_hsl_lock(&li->hsl);
        *(upcri_lock_t **)lock = li->freelocks;
        li->freelocks = lock;
      gasnet_hsl_unlock(&li->hsl);
    }
}
#endif
/* -------------------------------------------------------------------------- */
void upcri_SRQ_lockdestroy(gasnet_token_t token,
                           gasnet_handlerarg_t freer_threadid
                           UPCR_LOCK_TID_ARG(gasnet_handlerarg_t lock_threadid),
                           void *_lock) {
#if !UPCRI_AMLOCKS
    upcri_err("Bad call to upcri_SRQ_lockdestroy");
#else
    UPCR_LOCK_TID_OF_RCVR(lock_threadid)
    upcri_lock_t *lock = (upcri_lock_t *) _lock;
    upcr_thread_t tail_thread;
    upcri_heldlock_t *tail_addr;
  #if UPCRI_LOCKS_SHARED
    upcri_shared_lockinfo_t *his_sli;
  #endif
    uint32_t generation = lock->generation;
    
    upcri_doSRQ_lockdestroy(lock_threadid, lock, &tail_thread, &tail_addr);

  #if UPCRI_LOCKS_SHARED
    his_sli = upcri_get_sharedlockinfo_or_null(freer_threadid);
    if (his_sli != NULL) {
        /* Same as upcri_doSRP_lockreply() which isn't defined yet */
        his_sli->reply_gen    = generation;
        his_sli->reply_addr   = tail_addr;
        gasnett_local_wmb();
        his_sli->reply_thread = tail_thread;
    } else
  #endif
    UPCRI_AM_CALL(UPCRI_LOCK_REPLY(3,4,4,5,
                     (token, UPCRI_HANDLER_ID(upcri_SRP_lockreply)
                      UPCR_LOCK_TID_ARG(freer_threadid), generation,
                      tail_thread, UPCRI_SEND_PTR(tail_addr))));
#endif
}

/* -------------------------------------------------------------------------- */
#if UPCRI_AMLOCKS
GASNETT_INLINE(upcri_doSRQ_freeheldlock)
void upcri_doSRQ_freeheldlock(upcri_heldlock_t *holder) {

  #if UPCR_LOCK_DEBUG
    {
        upcri_lockinfo_t *li = upcri_getlockinfo(holder->thread);
        upcri_shared_lockinfo_t *sli = li->shared;

        gasnet_hsl_lock(&(li->hsl));
        holder->freed = 1;
        /* use of HSL eliminates need for a wmb here */
        sli->need_gc = 1;
        if (holder->queued) {
            upcri_err("Attempted to free a upc_lock_t"
                      " while one or more threads were blocked trying to acquire it in upc_lock()");
        } else {
            upcri_heldlock_t *p;
            for (p = li->freelist; p; p = p->next) {
                if (p == holder) {
                    upcri_err("Attempted to free a upc_lock_t which has already been freed");
                }
            }
        }
        gasnet_hsl_unlock(&(li->hsl));
    }
  #else
    upcri_shared_lockinfo_t *sli = upcri_get_sharedlockinfo_or_null(holder->thread);
    holder->freed = 1;
    gasnett_local_wmb();
    sli->need_gc = 1;
  #endif
}
#endif
void upcri_SRQ_freeheldlock(gasnet_token_t token, void *_tail_addr) {
  #if UPCRI_AMLOCKS
    upcri_doSRQ_freeheldlock((upcri_heldlock_t *) _tail_addr);
  #else
    upcri_err("illegal call to upcri_SRQ_freeheldlock");
  #endif
}
/* -------------------------------------------------------------------------- */
upcr_shared_ptr_t _upcr_global_lock_alloc(UPCRI_PT_ARG_ALONE) {
    upcr_shared_ptr_t retval;
    UPCRI_TRACE_PRINTF(("HEAPOP upc_global_lock_alloc()"));
    #if GASNET_STATS
      upcri_auxdata()->lock_info.alloccnt++;
    #endif
    #define UPCRI_PEVT_ARGS 
    upcri_pevt_start(GASP_UPC_GLOBAL_LOCK_ALLOC);
    #undef UPCRI_PEVT_ARGS

    retval = upcri_createlock();

    #define UPCRI_PEVT_ARGS , &retval
    upcri_pevt_end(GASP_UPC_GLOBAL_LOCK_ALLOC);
    #undef UPCRI_PEVT_ARGS

    return upcri_checkvalid_shared(retval);
}

upcr_shared_ptr_t _upcr_all_lock_alloc(UPCRI_PT_ARG_ALONE) {
    upcri_lockinfo_t * const li = &(upcri_auxdata()->lock_info);
    upcr_shared_ptr_t retval;
    upcr_thread_t lock_threadaff = li->next_affinity;

    UPCRI_TRACE_PRINTF(("HEAPOP upc_all_lock_alloc()"));
    #define UPCRI_PEVT_ARGS 
    upcri_pevt_start(GASP_UPC_ALL_LOCK_ALLOC);
    #undef UPCRI_PEVT_ARGS

    if (upcr_mythread() == lock_threadaff) {
	retval = upcri_createlock();
        #if GASNET_STATS
          upcri_auxdata()->lock_info.alloccnt++;
        #endif
    }
    upcri_broadcast(lock_threadaff, &retval, sizeof(retval));

    if (upcri_locks_rr) {
        /* Take care to avoid overflow */
        li->next_affinity =
            (lock_threadaff >= upcri_threads - upcri_locks_rr)
                ? (lock_threadaff - (upcri_threads - upcri_locks_rr))
		: (lock_threadaff + upcri_locks_rr);
    }

    #define UPCRI_PEVT_ARGS , &retval
    upcri_pevt_end(GASP_UPC_ALL_LOCK_ALLOC);
    #undef UPCRI_PEVT_ARGS

    return upcri_checkvalid_shared(retval);
}

static
void _upcr_do_lock_free(upcr_shared_ptr_t lockptr UPCRI_PT_ARG) {
    upcri_lockinfo_t * const li = &(upcri_auxdata()->lock_info);
  #if UPCRI_AMLOCKS
    upcri_shared_lockinfo_t * const sli = li->shared;
  #endif
    upcr_thread_t lock_threadaff = upcr_threadof_shared(lockptr);
    gasnet_node_t node = upcri_thread_to_node(lock_threadaff);
    upcri_lock_t *lockaddr = upcri_shared_to_remote(lockptr);
    const upcr_thread_t threads = upcr_threads();
    if (upcr_isnull_shared(lockptr)) return; /* upc_lock_free(NULL) is a no-op */
  #if GASNET_STATS
    upcri_auxdata()->lock_info.freecnt++;
  #endif

#ifdef UPCRI_LOCKC_DESTROY
  UPCRI_LOCKC_DESTROY(lockptr, lockaddr);
#else
    /* May need to stall for the reply from a previous unlock.
     * Otherwise the destroy AM might pass an unlock AM on the same lock!
     */
    if_pf (sli->unlock_state == UPCRI_UNLOCK_WAITING) {
        UPCRI_POLLWHILE_NORMB(sli->unlock_state == UPCRI_UNLOCK_WAITING);
        /* only arrival of enqueue could have gotten us here: */
        upcri_assert(sli->unlock_state == UPCRI_UNLOCK_PASS);
    }
    
    sli->reply_thread = threads; /* An impossible reply */

    /* Can bypass AM paths when lock_threadaff is local.
       Need to free memory prevents bypass on full super-node. */
    if (node == gasnet_mynode()) {
      upcri_doSRQ_lockdestroy(lock_threadaff, lockaddr,
                              (upcr_thread_t *) &(sli->reply_thread),
                              (upcri_heldlock_t **) &(sli->reply_addr));
    } else {
      gasnett_local_wmb(); /* prevents race against GASNet handler on reply_thread */
      UPCRI_AM_CALL(UPCRI_LOCK_REQUEST(2,3,3,4,
	  (node, UPCRI_HANDLER_ID(upcri_SRQ_lockdestroy), 
           upcr_mythread()
           UPCR_LOCK_TID_ARG(lock_threadaff),
	   UPCRI_SEND_PTR(lockaddr))));
    }

    /* block for AM reply */
    UPCRI_POLLWHILE(sli->reply_thread == threads);

    /* provide additional help if necessary */
    if (sli->reply_thread != UPCRI_INVALID_THREAD) {
        upcr_thread_t tail_thread = sli->reply_thread;
        upcri_heldlock_t *tail_addr = sli->reply_addr;
        upcri_heldlock_t *local_addr;

      #if UPCR_LOCK_DEBUG
        /* MUST run freeheldlock logic local to holder to perform debug checks */
        local_addr = (upcri_thread_to_node(tail_thread) == gasnet_mynode())
                         ? tail_addr : NULL;
      #else
        /* OK to operate on any thread we can address directly */
        local_addr = upcri_lock_localaddr(tail_thread, tail_addr);
      #endif
        if (local_addr) {
            upcri_doSRQ_freeheldlock(local_addr);
        } else {
            node = upcri_thread_to_node(tail_thread);
            UPCRI_AM_CALL(
              UPCRI_SHORT_REQUEST(1,2,
	        (node, UPCRI_HANDLER_ID(upcri_SRQ_freeheldlock), 
                 UPCRI_SEND_PTR(tail_addr))));
        }
    }
#endif
}

void _upcr_lock_free(upcr_shared_ptr_t lockptr UPCRI_PT_ARG) {
  #ifdef GASNET_TRACE
    char ptrstr[UPCRI_DUMP_MIN_LENGTH];
    upcri_dump_shared(lockptr, ptrstr, UPCRI_DUMP_MIN_LENGTH);
    UPCRI_TRACE_PRINTF(("HEAPOP upc_lock_free(%s)", ptrstr));
  #endif

  #define UPCRI_PEVT_ARGS , &lockptr
  upcri_pevt_start(GASP_UPC_LOCK_FREE);

  _upcr_do_lock_free(lockptr UPCRI_PT_PASS);

  upcri_pevt_end(GASP_UPC_LOCK_FREE);
  #undef UPCRI_PEVT_ARGS
}

void _upcr_all_lock_free(upcr_shared_ptr_t lockptr UPCRI_PT_ARG) {
  #ifdef GASNET_TRACE
    char ptrstr[UPCRI_DUMP_MIN_LENGTH];
    upcri_dump_shared(lockptr, ptrstr, UPCRI_DUMP_MIN_LENGTH);
    UPCRI_TRACE_PRINTF(("HEAPOP upc_all_lock_free(%s)", ptrstr));
  #endif

  /* XXX: upc_all_lock_free(NULL) is a no-op, except for tracing, and could skip this barrier */
  UPCRI_SINGLE_BARRIER();

  if (upcr_threadof_shared(lockptr) == upcr_mythread()) {
    /* TODO: Do we want a distinct GASP event? */

    #define UPCRI_PEVT_ARGS , &lockptr
    upcri_pevt_start(GASP_UPC_LOCK_FREE);

    _upcr_do_lock_free(lockptr UPCRI_PT_PASS);

    upcri_pevt_end(GASP_UPC_LOCK_FREE);
    #undef UPCRI_PEVT_ARGS
  }
}

/* -------------------------------------------------------------------------- */
#if UPCRI_AMLOCKS
GASNETT_INLINE(upcri_doSRP_lockreply)
void upcri_doSRP_lockreply(upcri_shared_lockinfo_t * const sli,
			   uint32_t generation,
			   upcr_thread_t thread, void *addr) {
    sli->reply_gen    = generation;
    sli->reply_addr   = addr;
    gasnett_local_wmb();
    sli->reply_thread = thread;
}
#endif
void upcri_SRP_lockreply(gasnet_token_t token
                         UPCR_LOCK_TID_ARG(gasnet_handlerarg_t threadid),
                         gasnet_handlerarg_t generation,
                         gasnet_handlerarg_t thread, void *addr) {
  #if UPCRI_AMLOCKS
    UPCR_LOCK_TID_OF_RCVR(threadid)
    upcri_shared_lockinfo_t *his_sli = upcri_his_sharedlockinfo(threadid);
    upcri_doSRP_lockreply(his_sli, generation, (upcr_thread_t)thread, addr);
  #else
    upcri_err("Bad call to upcri_doSRP_lockreply");
  #endif
}
/* -------------------------------------------------------------------------- */
#if UPCRI_AMLOCKS
GASNETT_INLINE(upcri_doSRP_unlockreply)
void upcri_doSRP_unlockreply(upcri_shared_lockinfo_t * const sli, int reply) {
    sli->unlock_state = reply;
}
#endif
void upcri_SRP_unlockreply(gasnet_token_t token
                           UPCR_LOCK_TID_ARG(gasnet_handlerarg_t threadid),
                           gasnet_handlerarg_t reply) {
  #if UPCRI_AMLOCKS
    UPCR_LOCK_TID_OF_RCVR(threadid)
    upcri_shared_lockinfo_t *his_sli = upcri_his_sharedlockinfo(threadid);
    upcri_doSRP_unlockreply(his_sli, reply);
  #else
    upcri_err("Bad call to upcri_doSRP_unlockreply");
  #endif
}
/* -------------------------------------------------------------------------- */
#if UPCRI_AMLOCKS
GASNETT_INLINE(upcri_doSRP_lockgrant)
void upcri_doSRP_lockgrant(upcri_shared_lockinfo_t * const sli) {
    upcri_assert(sli->blocked);
    sli->blocked = 0;
}
#endif
void upcri_SRP_lockgrant(gasnet_token_t token
                           UPCR_LOCK_TID_ARG(gasnet_handlerarg_t threadid)) {
  #if UPCRI_AMLOCKS
    UPCR_LOCK_TID_OF_RCVR(threadid)
    upcri_shared_lockinfo_t *his_sli = upcri_his_sharedlockinfo(threadid);
    upcri_doSRP_lockgrant(his_sli);
  #else
    upcri_err("Bad call to upcri_doSRP_lockgrant");
  #endif
}
/* -------------------------------------------------------------------------- */
#if UPCRI_AMLOCKS
GASNETT_INLINE(upcri_doSRQ_lockenqueue)
void upcri_doSRQ_lockenqueue(upcr_thread_t next_thread,
                             upcri_heldlock_t *held_lock) {
    held_lock->next_thread = next_thread;
}
#endif
void upcri_SRQ_lockenqueue(gasnet_token_t token,
                           gasnet_handlerarg_t next_thread,
                           void *_addr) {
  #if UPCRI_AMLOCKS
    upcri_doSRQ_lockenqueue((upcr_thread_t) next_thread, (upcri_heldlock_t *)_addr);
  #else
    upcri_err("Bad call to upcri_doSRQ_lockenqueue");
  #endif
}
/* -------------------------------------------------------------------------- */
#if UPCRI_AMLOCKS
GASNETT_INLINE(upcri_doSRQ_lock)
void upcri_doSRQ_lock(gasnet_handlerarg_t isblocking, upcri_lock_t *lock,
                      gasnet_handlerarg_t thread, upcri_heldlock_t *address,
                      upcr_thread_t *reply_thread, upcri_heldlock_t ** reply_addr) {
    register upcr_thread_t     prev_thread;
    register upcri_heldlock_t *prev_addr;

    if (isblocking) {
       upcri_lllock_acquire(&(lock->lll));
         #if UPCR_LOCK_DEBUG
           if_pf (lock->freed) {
             upcri_err("Attempted to acquire a upc_lock_t which has been freed");
           }
         #endif
         prev_addr   = lock->tail_addr;
         prev_thread = lock->tail_thread;
         lock->tail_addr   = address;
         lock->tail_thread = thread;
       upcri_lllock_release(&(lock->lll));
    } else {
        prev_addr   = NULL; /* Unused */
        prev_thread = lock->tail_thread;
        if (prev_thread == UPCRI_INVALID_THREAD) { /* bug 1209: reduce LLL contention from failed attempts */
            upcri_lllock_acquire(&(lock->lll));
              #if UPCR_LOCK_DEBUG
                if_pf (lock->freed) {
                  upcri_err("Attempted to acquire a upc_lock_t which has been freed");
                }
              #endif
              prev_thread = lock->tail_thread;
              if_pt (prev_thread == UPCRI_INVALID_THREAD) {
                  lock->tail_addr   = address;
                  lock->tail_thread = thread;
              }
            upcri_lllock_release(&(lock->lll));
        }
    }

    upcri_assert(thread != UPCRI_INVALID_THREAD);
    upcri_assert(thread != prev_thread);
    *reply_thread = prev_thread;
    *reply_addr   = prev_addr;
}
#endif

void upcri_SRQ_lock(gasnet_token_t token,
                    gasnet_handlerarg_t isblocking, void *_lock,
                    gasnet_handlerarg_t threadid, void *_address) {
#if !UPCRI_AMLOCKS
    upcri_err("Bad call to upcri_SRQ_lock");
#else
    upcr_thread_t reply_thread;
    upcri_heldlock_t *reply_addr;
  #if UPCRI_LOCKS_SHARED
    upcri_shared_lockinfo_t *his_sli;
  #endif
    upcri_lock_t * const lock = (upcri_lock_t *)_lock;
    if (isblocking) {
      upcri_doSRQ_lock(1, lock,
                       threadid, (upcri_heldlock_t *)_address,
                       &reply_thread, &reply_addr);
      if (reply_thread != UPCRI_INVALID_THREAD) {
        upcri_heldlock_t *local_addr = upcri_lock_localaddr(reply_thread, reply_addr);
        if (local_addr != NULL) {
            /* short-cut to avoid our caller sending us another AM for the enqueue */
            upcri_doSRQ_lockenqueue(threadid, local_addr);
            reply_addr = NULL;
        }
      }
    } else {
      upcri_doSRQ_lock(0, lock,
                       threadid, (upcri_heldlock_t *)_address,
                       &reply_thread, &reply_addr);
    }
  #if UPCRI_LOCKS_SHARED
    his_sli = upcri_get_sharedlockinfo_or_null(threadid);
    if (his_sli != NULL) {
        upcri_assert(upcri_thread_to_node(threadid) != gasnet_mynode());
        upcri_doSRP_lockreply(his_sli, lock->generation, reply_thread, reply_addr);
    } else
  #endif
    {
        UPCRI_AM_CALL(UPCRI_LOCK_REPLY(3,4,4,5,
		     (token, UPCRI_HANDLER_ID(upcri_SRP_lockreply)
                      UPCR_LOCK_TID_ARG(threadid), lock->generation,
                      reply_thread, UPCRI_SEND_PTR(reply_addr))));
    }
#endif
}


/* -------------------------------------------------------------------------- */
#if UPCRI_AMLOCKS
GASNETT_INLINE(upcri_doSRQ_unlock)
int
upcri_doSRQ_unlock(gasnet_handlerarg_t threadid,
                   gasnet_handlerarg_t generation,
                   upcri_lock_t *lock) {
    register int isfree = 0;

    if (lock->tail_thread == threadid) { /* reduce LLL contention */
      upcri_lllock_acquire(&(lock->lll));
        #if UPCR_LOCK_DEBUG
          if_pf (lock->freed && (lock->generation == generation)) {
            upcri_err("Attempted to release a upc_lock_t which has been freed");
          }
        #endif
        isfree = (lock->generation == generation) /* correct lock */
                 && (lock->tail_thread == threadid); /* caller still at tail = no waiters */
        if_pt (isfree) {
            lock->tail_thread = UPCRI_INVALID_THREAD;
        }
      upcri_lllock_release(&(lock->lll));
    }

    return isfree;
}
#endif

void upcri_SRQ_unlock(gasnet_token_t token,
                      gasnet_handlerarg_t threadid,
                      gasnet_handlerarg_t generation,
		      void *_lock) {
#if !UPCRI_AMLOCKS
    upcri_err("Bad call to upcri_SRQ_unlock");
#else
    upcri_lock_t * const lock = (upcri_lock_t *) _lock;
    const int isfree = upcri_doSRQ_unlock(threadid, generation, lock);
    const int reply = (int) ( isfree ? UPCRI_UNLOCK_DONE : UPCRI_UNLOCK_PASS );

  #if UPCRI_LOCKS_SHARED
    upcri_shared_lockinfo_t *his_sli = upcri_get_sharedlockinfo_or_null(threadid);
        if (his_sli != NULL) {
        upcri_assert(upcri_thread_to_node(threadid) != gasnet_mynode());
        upcri_doSRP_unlockreply(his_sli, reply);
    } else
  #endif
    {
        UPCRI_AM_CALL(UPCRI_LOCK_REPLY(1,1,2,2,
                      (token, UPCRI_HANDLER_ID(upcri_SRP_unlockreply)
                       UPCR_LOCK_TID_ARG(threadid), reply)));
    }
#endif
}


/* -------------------------------------------------------------------------- */
#define upcri_lock(lockptr, isblocking) \
       _upcri_lock(lockptr, isblocking UPCRI_PT_PASS)

GASNETT_INLINE(_upcri_lock)
int _upcri_lock(upcr_shared_ptr_t lockptr, int isblocking UPCRI_PT_ARG) {
    gasnet_node_t node = upcri_shared_nodeof(lockptr);
    upcri_lock_t *lockaddr = upcri_shared_to_remote(lockptr);
    upcri_lockinfo_t * const li = &(upcri_auxdata()->lock_info);
  #if UPCRI_AMLOCKS
    upcri_shared_lockinfo_t * const sli = li->shared;
    upcri_lock_t *localaddr;
  #endif
    upcri_heldlock_t * held_lock;
    const upcr_thread_t mythread = upcr_mythread();
    int success;
    #if GASNET_STATS
      gasnett_tick_t starttime = gasnett_ticks_now();
    #endif

  #ifdef UPCRI_LOCKC_LOCK
    UPCRI_LOCKC_LOCK(li, node, lockaddr, isblocking, success);
    #if UPCR_LOCK_DEBUG
    if (success) {
      upcri_heldlock_push(li, 0, lockptr);
    }
    #endif
  #else
    /* May need to stall for the reply from a delayed unlock.
     * Otherwise the lock AM might pass an unlock AM on the same lock!
     * TODO: unlock_state[hash(lockptr)] could lessen stalls, but not
     *       for the case of repeated lock/unlock of a single lock.
     */
    if_pf (sli->unlock_state == UPCRI_UNLOCK_WAITING) {
        UPCRI_POLLWHILE_NORMB(sli->unlock_state == UPCRI_UNLOCK_WAITING);
        /* only arrival of enqueue could have gotten us here: */
        upcri_assert(sli->unlock_state == UPCRI_UNLOCK_PASS);
    }

    sli->reply_thread = mythread; /* never a valid reply */
    sli->blocked = 1;
    held_lock = upcri_heldlock_push(li, isblocking, lockptr);
    /* This memory barrier prevents a race against GASNet handler on the values above
       and provides the wmb half of the memory barrier semantics required by upc_lock().
       The rmb half comes either explicitly (local case) or from POLLWHILE (remote case).
     */
    gasnett_local_wmb();

    localaddr = upcri_lock_pshared_addr(node, upcr_threadof_shared(lockptr), lockaddr);
    if (localaddr) {
      sli->reply_gen = localaddr->generation;
      upcri_doSRQ_lock(isblocking, localaddr, mythread, held_lock,
                       (upcr_thread_t *) &(sli->reply_thread),
                       (upcri_heldlock_t **) &(sli->reply_addr));
      success = (sli->reply_thread == UPCRI_INVALID_THREAD);
      if (success) { /* Have acquired the lock */
          gasnett_local_rmb();
      } else if (!isblocking) { /* Failed upc_lock_attempt */
	  /* ensure progress: unlock may be waiting in AM queue */
	  upcr_poll_nofence();
      }
    } else {
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(4,6,
		      (node, UPCRI_HANDLER_ID(upcri_SRQ_lock),
                       isblocking, UPCRI_SEND_PTR(lockaddr),
                       mythread, UPCRI_SEND_PTR(held_lock))));

      /* UPCRI_POLLWHILE provides rmb for upc_lock and to synchronize sli->reply_addr */
      UPCRI_POLLWHILE(sli->reply_thread == mythread);
      success = (sli->reply_thread == UPCRI_INVALID_THREAD);
    }

    if (isblocking && !success) { /* enqueue self and then wait */
        upcri_heldlock_t *remote_addr = sli->reply_addr;

        if (remote_addr != NULL) {
            upcr_thread_t remote_thread = sli->reply_thread;
            upcri_heldlock_t *local_addr;

            local_addr = upcri_lock_localaddr(remote_thread, remote_addr);
            if (local_addr) {
                upcri_doSRQ_lockenqueue(mythread, local_addr);
            } else {
                node = upcri_thread_to_node(remote_thread);
                UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(2,3,
		              (node, UPCRI_HANDLER_ID(upcri_SRQ_lockenqueue),
                               mythread, UPCRI_SEND_PTR(remote_addr))));
            }
        }
        /* else enqueue was done in upcri_doSRQ_lock */

        UPCRI_POLLWHILE(sli->blocked); /* need the rmb to Acquire */
    }
    #if UPCR_LOCK_DEBUG
    held_lock->queued = 0;
    #endif
  #endif

  #if GASNET_STATS
    li->waittime += (gasnett_ticks_now() - starttime);
  #endif
  if (isblocking || success) {
    #if UPCRI_AMLOCKS
      upcri_assert(upcr_isequal_shared_shared(li->locksheld->lockptr, lockptr));
      held_lock->generation = sli->reply_gen;
    #endif
    #if GASNET_STATS
      if (node == gasnet_mynode()) (li->locklocal_cnt)++;
      else (li->lockremote_cnt)++;
    #endif
    upcri_strict_hook();
    return 1;
  } else {
    #if UPCRI_AMLOCKS
      upcri_heldlock_pop(li, held_lock);
    #endif
    #if GASNET_STATS
      if (node == gasnet_mynode()) (li->lockfaillocal_cnt)++;
      else (li->lockfailremote_cnt)++;
    #endif
    return 0;
  }
}

void _upcr_lock(upcr_shared_ptr_t lockptr UPCRI_PT_ARG) {
  #ifdef GASNET_TRACE
    char ptrstr[UPCRI_DUMP_MIN_LENGTH];
    upcri_dump_shared(lockptr, ptrstr, UPCRI_DUMP_MIN_LENGTH);
    UPCRI_TRACE_PRINTF(("LOCK upc_lock(%s)", ptrstr));
  #endif
  #define UPCRI_PEVT_ARGS , &lockptr
  upcri_pevt_start(GASP_UPC_LOCK);
    upcri_lock(lockptr, 1);
  upcri_pevt_end(GASP_UPC_LOCK);
  #undef UPCRI_PEVT_ARGS
}

int _upcr_lock_attempt(upcr_shared_ptr_t lockptr UPCRI_PT_ARG) {
  int retval;
  #ifdef GASNET_TRACE
    char ptrstr[UPCRI_DUMP_MIN_LENGTH];
    upcri_dump_shared(lockptr, ptrstr, UPCRI_DUMP_MIN_LENGTH);
    UPCRI_TRACE_PRINTF(("LOCK upc_lock_attempt(%s)", ptrstr));
  #endif
  #define UPCRI_PEVT_ARGS , &lockptr
  upcri_pevt_start(GASP_UPC_LOCK_ATTEMPT);
  #undef UPCRI_PEVT_ARGS

  retval = upcri_lock(lockptr, 0);

  #define UPCRI_PEVT_ARGS , &lockptr, retval
  upcri_pevt_end(GASP_UPC_LOCK_ATTEMPT);
  #undef UPCRI_PEVT_ARGS

  return retval;
}

/* -------------------------------------------------------------------------- */
void _upcr_unlock(upcr_shared_ptr_t lockptr UPCRI_PT_ARG) {
  #define UPCRI_PEVT_ARGS , &lockptr
    upcri_strict_hook();
  upcri_pevt_start(GASP_UPC_UNLOCK);
  {
    gasnet_node_t node = upcri_shared_nodeof(lockptr);
    upcri_lock_t *lockaddr = upcri_shared_to_remote(lockptr);
    upcri_lockinfo_t * const li = &(upcri_auxdata()->lock_info);
  #if UPCRI_AMLOCKS
    upcri_shared_lockinfo_t * const sli = li->shared;
  #endif
    int isfree = 0;

  #if UPCR_LOCK_DEBUG || UPCRI_AMLOCKS
    upcri_heldlock_t *held_lock = upcri_heldlock_unlink(li, lockptr);
  #endif
  #if UPCR_LOCK_DEBUG
    if_pf (held_lock == NULL) {
        upcri_err("Attempted to release a upc_lock which was not held");
    }
  #endif

  #ifdef GASNET_TRACE
  {
    char ptrstr[UPCRI_DUMP_MIN_LENGTH];
    upcri_dump_shared(lockptr, ptrstr, UPCRI_DUMP_MIN_LENGTH);
    UPCRI_TRACE_PRINTF(("LOCK upc_unlock(%s)", ptrstr));
  }
  #endif

  #if GASNET_STATS
    if (node == gasnet_mynode()) (li->unlocklocal_cnt)++;
    else (li->unlockremote_cnt)++;
  #endif

  #ifdef UPCRI_LOCKC_UNLOCK
    UPCRI_LOCKC_UNLOCK(li, node, lockaddr);
  #else
    /* Poll first.
       bug 1531 - for fairness, look for incoming lock requests
       Additionlly helps catch incomming enqueues early, to avoid the AM round-trip
     */
    gasnet_AMPoll();

    /* may need to stall for the reply from the previous unlock */
    if_pf (sli->unlock_state == UPCRI_UNLOCK_WAITING) {
        UPCRI_POLLWHILE_NORMB(sli->unlock_state == UPCRI_UNLOCK_WAITING);
        /* only arrival of enqueue could have gotten us here: */
        upcri_assert(sli->unlock_state == UPCRI_UNLOCK_PASS);
    }

    if (held_lock->next_thread != UPCRI_INVALID_THREAD) {
        /* already know my successor */
        gasnett_local_mb();
    } else {
        const upcr_thread_t mythread = upcr_mythread();
        upcri_lock_t *localaddr = upcri_lock_pshared_addr(node, upcr_threadof_shared(lockptr), lockaddr);

        gasnett_local_wmb(); /* half of the full mb property of the unlock */
        if (localaddr) {
            /* lll acquire/release is full mb (but wmb is too late to elide the one above) */
            isfree = upcri_doSRQ_unlock(mythread, localaddr->generation, localaddr);
            if (!isfree) UPCRI_POLLWHILE(held_lock->next_thread == UPCRI_INVALID_THREAD);
        } else {
            sli->unlock_state = UPCRI_UNLOCK_WAITING;

            UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(3,4,
                            (node, UPCRI_HANDLER_ID(upcri_SRQ_unlock),
                             mythread, held_lock->generation, UPCRI_SEND_PTR(lockaddr))));

            UPCRI_POLLWHILE_NORMB((held_lock->next_thread == UPCRI_INVALID_THREAD) &&
                                  (sli->unlock_state == UPCRI_UNLOCK_WAITING));

            if (held_lock->next_thread != UPCRI_INVALID_THREAD) {
                /* We know our successor */
            } else if (sli->unlock_state == UPCRI_UNLOCK_PASS) {
                /* We've been told we must wait for our successor */
                UPCRI_POLLWHILE_NORMB(held_lock->next_thread == UPCRI_INVALID_THREAD);
            } else {
                /* We've been told there is no successor */
                upcri_assert(sli->unlock_state == UPCRI_UNLOCK_DONE);
                isfree = 1;
            }

            /* provide the rmb for upc_unlock since the polls excluded one */
            gasnett_local_rmb();
        }
    }

    if (!isfree) {
        /* grant to the successor */
        const upcr_thread_t next_thread = held_lock->next_thread;
        upcri_shared_lockinfo_t *his_sli = upcri_get_sharedlockinfo_or_null(next_thread);
        upcri_assert(next_thread != upcr_mythread()); /* Cannot be ones own successor */
        upcri_assert(next_thread != UPCRI_INVALID_THREAD);

        if (his_sli != NULL) {
            upcri_doSRP_lockgrant(his_sli);
        } else {
          node = upcri_thread_to_node(next_thread);
          UPCRI_AM_CALL(UPCRI_LOCK_REQUEST(0,0,1,1,
		       (node, UPCRI_HANDLER_ID(upcri_SRP_lockgrant)
                        UPCR_LOCK_TID_ARG(next_thread))));
        }
    }
  #endif
  }
  upcri_pevt_end(GASP_UPC_UNLOCK);
  #undef UPCRI_PEVT_ARGS
}

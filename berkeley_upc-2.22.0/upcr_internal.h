/*
 * Internal UPC Runtime functions.
 *
 * Jason Duell  <jcduell@lbl.gov>
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_internal.h $
 */

#ifndef UPCR_INTERNAL_H
#define UPCR_INTERNAL_H

#if !UPCRI_BUILDING_LIBUPCR
  #error Include/build error - upcr_internal.h should only be included by the upcr implementation .c files, which should only be compiled via upcr_globfiles.c
#endif

#include <upcr.h>
#include <gasnet_tools.h>

GASNETT_BEGIN_EXTERNC

/************************************************************************
 * Internal library global data
 ************************************************************************/

/* ensures that startup functions called in correct order */
typedef enum {
    upcri_startup_init,
    upcri_startup_attach,
    upcri_startup_spawn,
    upcri_startup_done
} upcri_startup_t;
extern upcri_startup_t upcri_startup_lvl;

/************************************************************************
 * Internal library non-inlined functions
 ************************************************************************/

void upcri_alloc_initheaps(void);

/* Broadcasts data from one thread to all the rest  */
#define upcri_broadcast(fromthread, addr, len) \
       _upcri_broadcast(fromthread, addr, len UPCRI_PT_PASS)

void _upcri_broadcast(upcr_thread_t fromthread, void *addr, size_t len UPCRI_PT_ARG);

/* single-phase barrier that cannot, in general, be mixed with notify/wait */
#define upcri_barrier(barrierval, flags)	\
	_upcri_barrier(barrierval, flags UPCRI_PT_PASS)
void _upcri_barrier(int barrierval, int flags UPCRI_PT_ARG);

void upcri_do_local_free(upcr_shared_ptr_t sptr);

#if UPCRI_SUPPORT_TOTALVIEW
  /* To support TotalView debugging of application code */
  #define upcri_startup_totalview(argv) \
       _upcri_startup_totalview(argv UPCRI_PT_PASS)
  int _upcri_startup_totalview(char **argv UPCRI_PT_ARG);
#else
  #define upcri_startup_totalview(argv) (0)
#endif

/************************************************************************
 * Inline functions and macros that don't need to be visible to user.
 ************************************************************************/
    
#include <assert.h>
#undef assert
#define assert(x) !!! Error - use upcri_assert() !!!

/* (En/Dis)able use of out-of-segment temporaries with GASNet collectives.
 * This presently affects the UPC reduce and prefix-reduce implementations
 * and totalview initialization.
 * This is a "shutoff" switch for use if GASNet is suspected to be unreliable.
 * If not set, then upcr_alloc() is used to obtain in-segment temporaries.
 */
#define UPCRI_COLL_USE_LOCAL_TEMPS 1

/* "Single" barriers that are named in a DEBUG build (to catch errors)
 * and anonymous in an NDEBUG build (for speed).
 *
 * When debugging, we hope to catch any case that a barrier internal to
 * the runtime would accidentally match any other barrier.  For this
 * reason we use __LINE__ to name barriers rather than a sequence number.
 * However, we also add a large offset to reduce to possibility of
 * collision with small integers that are a likely choice for use in
 * application code.  There is no "perfect" naming, but this is good
 * enough for our purposes.
 *
 * _NOTHR variants call gasnet directly for code prior to pthread setup.
 */
#ifndef UPCRI_SINGLE_BARRIER_NAME
  /* Can redefine if this happens to colide with an app to be debugged */
  #define UPCRI_SINGLE_BARRIER_NAME()	(__LINE__+88888888)
#endif
#if UPCR_DEBUG
  #define UPCRI_SINGLE_BARRIER_WITHCODE_NOTHR(code) do { \
      int _name = UPCRI_SINGLE_BARRIER_NAME();           \
      gasnet_barrier_notify(_name, 0);                   \
      code;                                              \
      gasnet_barrier_wait(_name, 0);                     \
    } while(0)
  #define UPCRI_SINGLE_BARRIER_WITHCODE(code) do { \
      int _name = UPCRI_SINGLE_BARRIER_NAME();     \
      upcr_notify(_name, 0);                       \
      code;                                        \
      upcr_wait(_name, 0);                         \
    } while(0)
  #define UPCRI_SINGLE_BARRIER_NOTHR() \
      gasnet_barrier(UPCRI_SINGLE_BARRIER_NAME(), 0)
  #define UPCRI_SINGLE_BARRIER() \
      upcri_barrier(UPCRI_SINGLE_BARRIER_NAME(), 0)
#else
  #define UPCRI_SINGLE_BARRIER_WITHCODE_NOTHR(code) do {      \
      gasnet_barrier_notify(0, GASNET_BARRIERFLAG_UNNAMED);   \
      code;                                                   \
      gasnet_barrier_wait(0, GASNET_BARRIERFLAG_UNNAMED);     \
    } while(0)
  #define UPCRI_SINGLE_BARRIER_WITHCODE(code) do { \
      upcr_notify(0, UPCR_BARRIERFLAG_UNNAMED);    \
      code;                                        \
      upcr_wait(0, UPCR_BARRIERFLAG_UNNAMED);      \
    } while(0)
  #define UPCRI_SINGLE_BARRIER_NOTHR() \
      gasnet_barrier(0, GASNET_BARRIERFLAG_UNNAMED)
  #define UPCRI_SINGLE_BARRIER() \
      upcri_barrier(0, GASNET_BARRIERFLAG_UNNAMED)
#endif


/* Collective helpers common to multiple source files */

/* Make 0 an alias for the ALLSYNC flags and check flag sanity if debugging */
/* XXX: add callsite information to error messages? */
#define UPCRI_COLL_INSYNC_MASK	(UPC_IN_NOSYNC  | UPC_IN_MYSYNC  | UPC_IN_ALLSYNC)
#define UPCRI_COLL_OUTSYNC_MASK	(UPC_OUT_NOSYNC | UPC_OUT_MYSYNC | UPC_OUT_ALLSYNC)
GASNETT_INLINE(upcri_coll_fixsync)
upc_flag_t upcri_coll_fixsync(upc_flag_t sync_mode) {
  if ((sync_mode & UPCRI_COLL_INSYNC_MASK) == 0) {
    sync_mode |= UPC_IN_ALLSYNC;
  }
  if ((sync_mode & UPCRI_COLL_OUTSYNC_MASK) == 0) {
    sync_mode |= UPC_OUT_ALLSYNC;
  }

#if UPCR_DEBUG
  switch (sync_mode & UPCRI_COLL_INSYNC_MASK) {
    case UPC_IN_NOSYNC:
    case UPC_IN_MYSYNC:
    case UPC_IN_ALLSYNC:
      break;
    default:
      upcri_err("Invalid combination of multiple UPC_IN_*SYNC flags");
  }
  switch (sync_mode & UPCRI_COLL_OUTSYNC_MASK) {
    case UPC_OUT_NOSYNC:
    case UPC_OUT_MYSYNC:
    case UPC_OUT_ALLSYNC:
      break;
    default:
      upcri_err("Invalid combination of multiple UPC_OUT_*SYNC flags");
  }
  if (sync_mode & ~(UPCRI_COLL_INSYNC_MASK | UPCRI_COLL_OUTSYNC_MASK)) {
    upcri_warn("Invalid/unknown flags set in sync_mode");
  }
#endif

  return sync_mode;
}

extern const char *upcri_op2str(upc_op_t op);

/* FCA support: */
#if UPCRI_FCA && defined(GASNET_SEQ) && (GASNET_CONDUIT_MXM || GASNET_CONDUIT_IBV)
  #define UPCRI_USE_FCA 1
#endif

/* With PSHM "upcri_shared_to_remote[_withthread]()" returns the address as used
 * in the virtual address space of the target thread without regards to where
 * in the local virtual address space the corresponding segment is mapped.
 */
#if UPCRI_USING_PSHM
  #define UPCRI_COLL_LOCALIZE(_addr,_thr) \
    ((void *)((uintptr_t)(_addr) UPCRI_MINUS_REMOTE_OFFSET(_thr) + upcri_thread2local[(_thr)]))
#else
  #define UPCRI_COLL_LOCALIZE(_addr,_thr) (_addr)
#endif

/* GASNET_BLOCKUNTIL() is really only legal for AM-generated conditions.
 * That allows, for instance, implementations which block in select().
 * So, we use these when waiting on a condition that could change due to
 * some non-AM event (e.g. a write to shared memory).
 * Note 1: no poll if end condition is already true
 * Note 2: rmb() unconditionally (except in _NORMB variants, of course)
 */
#define UPCRI_POLLWHILE_NORMB(cnd)    \
  do {                                \
    if (cnd) {                        \
      gasnet_AMPoll();                \
      while (cnd) {                   \
        if_pf (upcri_polite_wait)     \
          gasnett_sched_yield();      \
        gasnet_AMPoll();              \
      }                               \
    }                                 \
  } while (0)
#define UPCRI_POLLWHILE(cnd)          \
  do {                                \
    UPCRI_POLLWHILE_NORMB (cnd);      \
    gasnett_local_rmb();              \
  } while (0)
#define UPCRI_POLLUNTIL_NORMB(cnd) UPCRI_POLLWHILE_NORMB(!(cnd))
#define UPCRI_POLLUNTIL(cnd) UPCRI_POLLWHILE(!(cnd))


GASNETT_END_EXTERNC

#endif /* UPCR_INTERNAL_H */

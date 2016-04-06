/* $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_barrier.c $
 * Description: UPC barrier implementation on GASNet
 * Copyright 2002, Dan Bonachea <bonachea@cs.berkeley.edu>
 */

#include <upcr.h>
#include <upcr_internal.h>

/*----------------------------------------------------------------------------*/

static int upcri_barrier_mismatch_warns;

GASNETT_NEVER_INLINE(upcri_barrier_mismatch,
static void upcri_barrier_mismatch(UPCRI_PT_ARG_ALONE))
{
  if (upcri_barrier_mismatch_warns) {
    char loc[500] = { '\0', };
    upcri_append_srcloc(loc, sizeof(loc));
    upcri_warn("barrier mismatch detected by thread %d%s", upcr_mythread(), loc);
  } else {
    /* upcri_err() already provides SRCPOS */
    upcri_err("barrier mismatch detected by thread %d", upcr_mythread());
  }
}

GASNETT_INLINE(upcri_barrier_flags)
int upcri_barrier_flags(int flags)
{
  upcri_assert(!flags || (flags == UPCR_BARRIERFLAG_ANONYMOUS) || (flags == UPCR_BARRIERFLAG_UNNAMED));
#if (UPCR_BARRIERFLAG_ANONYMOUS == GASNET_BARRIERFLAG_ANONYMOUS) && \
    (UPCR_BARRIERFLAG_UNNAMED   == GASNET_BARRIERFLAG_UNNAMED)
  return flags;
#else
  return !flags ? 0
                : ((flags == UPCR_BARRIERFLAG_ANONYMOUS) ? GASNET_BARRIERFLAG_ANONYMOUS
                                                         : GASNET_BARRIERFLAG_UNNAMED);
#endif
}

#define UPCRI_BARRIERSTATE_BARRIER(_bar) do {                            \
        if_pf ((_bar)->barrier_state == upcr_barrierstate_insidebarrier) \
	    upcri_err("misordered call to barrier");                     \
    } while(0)
#define UPCRI_BARRIERSTATE_NOTIFY(_bar) do {                             \
        if_pf ((_bar)->barrier_state == upcr_barrierstate_insidebarrier) \
	    upcri_err("misordered call to barrier notify");              \
        (_bar)->barrier_state = upcr_barrierstate_insidebarrier;         \
    } while(0)
#define UPCRI_BARRIERSTATE_WAIT_ENTER(_bar) do {                          \
        if_pf ((_bar)->barrier_state == upcr_barrierstate_outsidebarrier) \
	    upcri_err("misordered call to barrier wait");                 \
    } while(0)
#if PLATFORM_COMPILER_PATHSCALE || PLATFORM_COMPILER_SGI
  /* bug1337: extraneous deref is workaround for pathscale optimizer bug */
  /* bug2474: also appears necessary for SGI's compiler. */
  #define UPCRI_BARRIERSTATE_WAIT_LEAVE(_bar) \
      ((void)(*(volatile int *)&((_bar)->barrier_state) = (int)upcr_barrierstate_outsidebarrier))
#else
  #define UPCRI_BARRIERSTATE_WAIT_LEAVE(_bar) \
      ((void)((_bar)->barrier_state = upcr_barrierstate_outsidebarrier))
#endif

/*----------------------------------------------------------------------------*/

#ifdef UPCRI_UPC_PTHREADS

static char _cache_pad1[GASNETT_CACHE_LINE_BYTES];
static gasnett_atomic_t barrier_count; /* init to { upcr_numthreads } */
static char _cache_pad2[GASNETT_CACHE_LINE_BYTES];

static int volatile notify_done[2] = {0,0};
static int volatile wait_done[2] = {0,0};
static gasnett_mutex_t barrier_lock = GASNETT_MUTEX_INITIALIZER;

static int barrier_consensus_value = 0;
static int barrier_flags = 0;

static int barrier_result_anon  = 0;
static int barrier_result_value = 0;

upcri_barrier_args_t *upcri_barrier_args = NULL;

typedef struct {
  gasnett_atomic_t	count;
  volatile int		done;
  gasnett_cond_t	cond;
  gasnett_mutex_t	lock;
} upcri_pthread_barrier_t;

static upcri_pthread_barrier_t upcri_pthread_barrier_var[2];
static int volatile upcri_pthread_barrier_phase = 0;

int
_upcri_pthread_barrier(void) {
    const int phase = upcri_pthread_barrier_phase;
    upcri_pthread_barrier_t *state = &(upcri_pthread_barrier_var[phase]);
    int last;

    if_pf (upcri_polite_wait) {
	gasnett_mutex_lock(&state->lock);
    }

    /* The REL ensures everything written by this thread prior to entering the barrier
     * will be visible to all threads before any thread can leave the barrier.
     */
    last = gasnett_atomic_decrement_and_test(&(state->count), GASNETT_ATOMIC_REL);
    if (last) {
	upcri_pthread_barrier_t *tmp = &(upcri_pthread_barrier_var[!phase]);

	upcri_pthread_barrier_phase = !phase;
	tmp->done = 0;
	gasnett_atomic_set(&(tmp->count), upcri_mypthreads(), GASNETT_ATOMIC_WMB_POST);

	state->done = 1;

	if_pf (upcri_polite_wait) {
	    gasnett_cond_broadcast(&state->cond);
	}
    } else {
	do {
	    if_pf (upcri_polite_wait) {
		gasnett_cond_wait(&state->cond, &state->lock);
	    } else {
		gasnett_spinloop_hint();	/* XXX: gasnet_AMPoll() ? */
	    }
	} while (!state->done);
    }

    if_pf (upcri_polite_wait) {
	gasnett_mutex_unlock(&state->lock);
    }
    
    /* Ensure all values written by any thread before entering the barrer will be
     * visible on this thread before we return.  This also includes the values of the
     * barrier structure that will be observed on our next pass through this function.
     */
    gasnett_local_rmb();

    return last;
}

/* TODO: shift to a non-atomic implementation for pthread-level barrier.
 * First Titanium, and now GASNet, have found that shared-memory barriers using
 * a spin-polling Notify can significantly out-perform the use of a centralized
 * counter with atomic dec-and-test.  In particular the costs of the atomic op
 * don't scale as well as spinning on a clean cacheline waiting for a write.
 * Additionally, static election of a "master" thread (vs dynamically selecting
 * the last arrival) can simplify the code and give better cache reuse.
 */
void 
_upcr_notify(int barrierval, int flags UPCRI_PT_ARG)
{
    upcri_barrier_t * const bar = &(upcri_auxdata()->barrier_info);
    upcri_barrier_args_t * const args = bar->barrier_args;
    const int phase = (bar->barrier_phase = !bar->barrier_phase);

    #define UPCRI_PEVT_ARGS , !(flags & UPCR_BARRIERFLAG_ANONYMOUS), barrierval
    upcri_pevt_start(GASP_UPC_NOTIFY);

    UPCRI_BARRIERSTATE_NOTIFY(bar);
    upcri_strict_hook();

    args->value = barrierval;
    args->flags = flags;
    if (upcri_mypthreads() == 1) {
      gasnet_barrier_notify(barrierval, upcri_barrier_flags(flags));
    } else {
	int lastone = gasnett_atomic_decrement_and_test(&barrier_count, GASNETT_ATOMIC_REL | GASNETT_ATOMIC_ACQ_IF_TRUE);

	if (lastone) {		/* we are the last thread to notify */
	    if (flags == UPCR_BARRIERFLAG_UNNAMED) {
	      barrier_flags = GASNET_BARRIERFLAG_UNNAMED;
	    } else {
	      int i;

	      barrier_flags = GASNET_BARRIERFLAG_ANONYMOUS;
	      for (i = 0; i < upcri_mypthreads(); i++) {
		const upcri_barrier_args_t * const his_args = &upcri_barrier_args[i];
		if (!his_args->flags) {
		    if (barrier_flags) {
			upcri_assert(barrier_flags == GASNET_BARRIERFLAG_ANONYMOUS);
			barrier_consensus_value = his_args->value;
			barrier_flags = 0;
		    } else if_pf (his_args->value != barrier_consensus_value) {
			barrier_flags = GASNET_BARRIERFLAG_MISMATCH;
			break;
		    }
		} else {
		    upcri_assert(his_args->flags == UPCR_BARRIERFLAG_ANONYMOUS);
		}
	      }			/*  for */
	    }
    
	    /*  do the global gasnet barrier notify */
	    gasnet_barrier_notify(barrier_consensus_value, barrier_flags);
	    /*  signal that notify is complete */
            notify_done[!phase] = 0;
	    gasnett_atomic_set(&barrier_count, upcri_mypthreads(), GASNETT_ATOMIC_WMB_POST);
            notify_done[phase] = 1;
	}
  }

  upcri_pevt_end(GASP_UPC_NOTIFY);
  #undef UPCRI_PEVT_ARGS
}


static int 
upcr_wait_internal(int barrierval, int flags, int block UPCRI_PT_ARG)
{
    upcri_barrier_t * const bar = &(upcri_auxdata()->barrier_info);
    const upcri_barrier_args_t * const args = bar->barrier_args;
    int phase = bar->barrier_phase;

    UPCRI_BARRIERSTATE_WAIT_ENTER(bar);

    if (upcri_mypthreads() == 1) {
        const int wait_flags = upcri_barrier_flags(flags);
        int retval;
        if (block) retval = gasnet_barrier_wait(barrierval, wait_flags);
        else {
          retval = gasnet_barrier_try(barrierval, wait_flags);
          if (retval == GASNET_ERR_NOT_READY) return 0;
        }
	if_pf (retval == GASNET_ERR_BARRIER_MISMATCH)
          upcri_barrier_mismatch(UPCRI_PT_PASS_ALONE);
	barrier_result_anon = gasnet_barrier_result(&barrier_result_value);
    } else if (!wait_done[phase]) {	/* redundant, but reduces lock contention */
	if (gasnett_mutex_trylock(&barrier_lock) == EBUSY) {
	    if (!block)
		return 0;
            /* the lock holder will complete the barrier, se we need only wait for them */
	    while (!wait_done[phase]) {
	      if (upcri_polite_wait) gasnett_sched_yield(); /* spin-wait */
              gasnett_spinloop_hint();
            }
            goto done; 
	}

        /* Lock acquisition ensures we will observe the values written by the notify */
	if (!wait_done[phase]) {
	    int retval;

	    if (!notify_done[phase]) { /*  not everyone has notified yet */
                if (!block) {
	          gasnett_mutex_unlock(&barrier_lock);
                  return 0;
                }
		while (!notify_done[phase]) {
	          if (upcri_polite_wait) gasnett_sched_yield(); /* spin-wait */
                  gasnett_spinloop_hint();
                }
	    }
	    gasnett_local_rmb();

	    if (block)		/*  do the global gasnet barrier wait */
		retval = gasnet_barrier_wait(barrier_consensus_value, barrier_flags);
	    else {
		retval = gasnet_barrier_try(barrier_consensus_value, barrier_flags);
                if (retval == GASNET_ERR_NOT_READY) {
	          gasnett_mutex_unlock(&barrier_lock);
		  return 0;
                }
	    }
	    if_pf (retval == GASNET_ERR_BARRIER_MISMATCH)
		upcri_barrier_mismatch(UPCRI_PT_PASS_ALONE);
	    upcri_assert(!(barrier_flags & GASNET_BARRIERFLAG_MISMATCH) || upcri_barrier_mismatch_warns);
	    barrier_result_anon = gasnet_barrier_result(&barrier_result_value);

	    wait_done[!phase] = 0;
            gasnett_local_wmb();
  	    wait_done[phase] = 1;
	}
	gasnett_mutex_unlock(&barrier_lock);
    }
done:
    gasnett_local_rmb();
    if_pf (!flags && !barrier_result_anon && (barrierval != barrier_result_value))
	upcri_barrier_mismatch(UPCRI_PT_PASS_ALONE); /* named wait/try mismatch a named notify */
    upcri_strict_hook();
    UPCRI_BARRIERSTATE_WAIT_LEAVE(bar);
    return 1;
}

void 
_upcr_wait(int barrierval, int flags UPCRI_PT_ARG)
{
  #define UPCRI_PEVT_ARGS , !(flags & UPCR_BARRIERFLAG_ANONYMOUS), barrierval
  upcri_pevt_start(GASP_UPC_WAIT);

    upcr_wait_internal(barrierval, flags, 1 UPCRI_PT_PASS);

  upcri_pevt_end(GASP_UPC_WAIT);
  #undef UPCRI_PEVT_ARGS
}

int 
_upcr_try_wait(int barrierval, int flags UPCRI_PT_ARG)
{
    return upcr_wait_internal(barrierval, flags, 0 UPCRI_PT_PASS);
}

/* Used internally for "UPCR_BARRIER_SINGLE()".
 * Note we do NOT perform the name matching across pthreads here.
 * There is not any strict requirement to do so.
 * That means somewhat less ability to catch certain errors, but
 * probabilistically they will still show as cross-node mismatches.
 * TODO: a debug build could be made to perform the checking.
 */
void 
_upcri_barrier(int barrierval, int flags UPCRI_PT_ARG)
{
    static volatile int phase = 0;
    static volatile int done[2] = {0,0};
    int my_phase, last;

    upcri_barrier_t * const bar = &(upcri_auxdata()->barrier_info);
    UPCRI_BARRIERSTATE_BARRIER(bar);
    upcri_strict_hook();

    my_phase = phase;
    last = (upcri_mypthreads() == 1) || _upcri_pthread_barrier();

    if (last) {
        const int result = gasnet_barrier(barrierval, upcri_barrier_flags(flags));

        if_pf (upcri_polite_wait) {
            _upcri_pthread_barrier();
        } else {
            /* "half" barrier is cheaper (non-atomic), but not very polite */
            phase = my_phase ^ 1;
            done[my_phase ^ 1] = 0;
            gasnett_local_wmb();
            done[my_phase] = 1;
        }

        if_pf (result == GASNET_ERR_BARRIER_MISMATCH) {
            upcri_barrier_mismatch(UPCRI_PT_PASS_ALONE);
        }
    } else {
        if_pf (upcri_polite_wait) {
            _upcri_pthread_barrier();
         } else {
            do {
                gasnett_spinloop_hint();        /* XXX: gasnet_AMPoll() ? */
            } while (!done[my_phase]);
            gasnett_local_rmb(); /* ensure we read right phase on next pass */
        }
    }
}

#else	/* !UPCRI_UPC_PTHREADS */

void 
_upcr_notify(int barrierval, int flags)
{
  #define UPCRI_PEVT_ARGS , !(flags & UPCR_BARRIERFLAG_ANONYMOUS), barrierval
  upcri_pevt_start(GASP_UPC_NOTIFY);

  { upcri_barrier_t * const bar = &(upcri_auxdata()->barrier_info);
    UPCRI_BARRIERSTATE_NOTIFY(bar);
    upcri_strict_hook();

    bar->barrier_phase ^= 1;
    gasnet_barrier_notify(barrierval, upcri_barrier_flags(flags));
  }

  upcri_pevt_end(GASP_UPC_NOTIFY);
  #undef UPCRI_PEVT_ARGS
}

void 
_upcr_wait(int barrierval, int flags)
{
  #define UPCRI_PEVT_ARGS , !(flags & UPCR_BARRIERFLAG_ANONYMOUS), barrierval
  upcri_pevt_start(GASP_UPC_WAIT);

  { upcri_barrier_t * const bar = &(upcri_auxdata()->barrier_info);
    UPCRI_BARRIERSTATE_WAIT_ENTER(bar);

    if (gasnet_barrier_wait(barrierval, upcri_barrier_flags(flags)) == GASNET_ERR_BARRIER_MISMATCH)
        upcri_barrier_mismatch(UPCRI_PT_PASS_ALONE);

    upcri_strict_hook();
    UPCRI_BARRIERSTATE_WAIT_LEAVE(bar);
  }

  upcri_pevt_end(GASP_UPC_WAIT);
  #undef UPCRI_PEVT_ARGS
}

int 
_upcr_try_wait(int barrierval, int flags)
{
    upcri_barrier_t * const bar = &(upcri_auxdata()->barrier_info);
    int retval;

    UPCRI_BARRIERSTATE_WAIT_ENTER(bar);

    retval = gasnet_barrier_try(barrierval, upcri_barrier_flags(flags));

    if (retval == GASNET_ERR_NOT_READY)
	return 0;
    if (retval == GASNET_ERR_BARRIER_MISMATCH)
	upcri_barrier_mismatch(UPCRI_PT_PASS_ALONE);

    upcri_strict_hook();
    UPCRI_BARRIERSTATE_WAIT_LEAVE(bar);
    return 1;
}

void 
_upcri_barrier(int barrierval, int flags)
{
    upcri_barrier_t * const bar = &(upcri_auxdata()->barrier_info);
    UPCRI_BARRIERSTATE_BARRIER(bar);
    upcri_strict_hook();

    if (gasnet_barrier(barrierval, upcri_barrier_flags(flags)) == GASNET_ERR_BARRIER_MISMATCH)
        upcri_barrier_mismatch(UPCRI_PT_PASS_ALONE);
}
#endif

void 
upcri_barrier_init(void)
{
  #ifdef UPCRI_UPC_PTHREADS
    int i;

    gasnett_atomic_set(&barrier_count, upcri_mypthreads(), 0);
    upcri_barrier_args = UPCRI_XCALLOC(upcri_barrier_args_t, 1 + upcri_mypthreads()); /* +1 for cache padding */

    for (i = 0; i < 2; ++i) {
	gasnett_atomic_set(&(upcri_pthread_barrier_var[i].count), upcri_mypthreads(), 0);
	upcri_pthread_barrier_var[i].done = 0;
	gasnett_cond_init(&upcri_pthread_barrier_var[i].cond);
	gasnett_mutex_init(&upcri_pthread_barrier_var[i].lock);
    }
  #endif

    upcri_barrier_mismatch_warns = gasnett_getenv_yesno_withdefault("UPC_BARRIER_MISMATCH_WARNS", 0);
    if (upcri_barrier_mismatch_warns && !gasnet_mynode()
        && !gasnett_getenv_yesno_withdefault("UPC_WARN_FATAL",0)) {
      upcri_warn("barrier mismatches in this run will be non-fatal.");
    }
}

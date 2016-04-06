/*
 * UPC barrier functions
 */

#ifndef UPCR_BARRIER_H
#define UPCR_BARRIER_H

#define UPCR_BARRIERFLAG_ANONYMOUS 1 /* Code gen uses "1", so we must match */
/* Should match GASNet unless conflicts */
#if (GASNET_BARRIERFLAG_UNNAMED != UPCR_BARRIERFLAG_ANONYMOUS)
  #define UPCR_BARRIERFLAG_UNNAMED GASNET_BARRIERFLAG_UNNAMED
#else
  #define UPCR_BARRIERFLAG_UNNAMED 2
#endif

#define UPCR_FINAL_BARRIER_VALUE (0xFFC1A43B) /* something a user is unlikely to choose */

extern void upcri_barrier_init(void); /* called by exactly 1 thread/proc at startup */

#if UPCRI_UPC_PTHREADS

/* A simple barrier among the local pthreads, returning non-zero to the last arrival */
#define upcri_pthread_barrier()\
        _upcri_pthread_barrier()
extern int _upcri_pthread_barrier(void);

#else

#define upcri_pthread_barrier() (1)

#endif  /* UPCRI_UPC_PTHREADS */

/* define calls to add threadinfo struct if using pthreads */
#define upcr_notify(barrierval, flags)		\
	(upcri_srcpos(), _upcr_notify(barrierval, flags UPCRI_PT_PASS))
#define upcr_wait(barrierval, flags)		\
	(upcri_srcpos(), _upcr_wait(barrierval, flags UPCRI_PT_PASS))
#define upcr_try_wait(barrierval, flags)	\
	(upcri_srcpos(), _upcr_try_wait(barrierval, flags UPCRI_PT_PASS))

void _upcr_notify(int barrierval, int flags UPCRI_PT_ARG);
void _upcr_wait(int barrierval, int flags UPCRI_PT_ARG);
int  _upcr_try_wait(int barrierval, int flags UPCRI_PT_ARG);

#endif /* UPCR_BARRIER_H */

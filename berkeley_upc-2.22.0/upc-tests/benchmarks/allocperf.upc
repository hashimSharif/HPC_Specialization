/* UPC allocation performance tester, v0.1
   Copyright 2003, Dan Bonachea <bonachea@cs.berkeley.edu>
   This program is public domain - permission is granted for any and all uses.
 */
#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

int giters=0;
int threshwarning = 0;

#if __UPC_TICK__
#include <upc_tick.h>
#endif

static int64_t mygetMicrosecondTimeStamp(void) {
#if __UPC_TICK__
    return upc_ticks_to_ns(upc_ticks_now()) / 1000;
#else
    int64_t retval;
    struct timeval tv;
    if (gettimeofday(&tv, NULL)) {
	perror("gettimeofday");
	abort();
    }
    retval = ((int64_t)tv.tv_sec) * 1000000 + tv.tv_usec;
    return retval;
#endif
}

#define TIME() mygetMicrosecondTimeStamp()
#define TIMER_THRESHOLD_US 10000
#define ZEROMSG(s) do {  \
    if (MYTHREAD == 0) { \
      printf(s);         \
      fflush(stdout);    \
    }                    \
  } while(0)
static void report(int64_t timeus, const char *msg) {
  const char *threshmark = "";
  if (timeus < TIMER_THRESHOLD_US) {
    threshmark = "(*)";
    threshwarning = 1;
  }
  printf(" %-35s: Total=%6.3f sec  Avg=%6.3f us %s\n",
    msg, ((double)timeus)/1000000, ((double)timeus)/giters, threshmark);
  fflush(stdout);
}

/* Usage: allocperf <iters>
 * Runs a performance test of various UPC allocation-related functions
 *  barrier performance is also shown for comparison purposes
 * In each case, we allocate <iters> objects by calling an allocation function,
 *  then free them using upc_free. Operations are performed from both thread 0
 *  and thread THREADS-1 (which is assumed to be a representative non-0 thread)
 * Average performance is reported for both the allocation and free steps.
 * Small objects are used to emphasize the fixed, per-operation overhead, 
 *  rather than costs linear in allocation size - since the latter are
 *  likely to be independent of communication costs and allocation semantics
 * During any given phase, at most one thread is using non-collective allocation,
 *  to prevent introducing thread contention that might cloud results 
 */

int main(int argc, char **argv) {
  int64_t start,total;
  shared char **ptrs;
  shared char * shared [] *shptrs;
  int i = 0;
  int iters = 0;

  if (argc > 1) iters = atoi(argv[1]);
  if (iters <= 0) iters = 10000;
  giters = iters;

  if (MYTHREAD == 0) {
      printf("running perf test with %i iterations, %i threads\n", iters, THREADS);
      printf("  TN = THREADS-1 (thread %i)\n", THREADS-1);
      printf("-------------------------------------------------------------------------------\n");
      fflush(stdout);
  }

  /* setup */
  ptrs = malloc(sizeof(shared char *) * iters);
  shptrs = upc_all_alloc(1, sizeof(shared char *) * iters);

  /* ----------------------------------------------------- 
   * Warm up the allocator
   * alloc and free some memory to pay any first-call costs
   * (e.g. obtaining pages from the system) so that we 
   * measure steady-state behavior
   * ----------------------------------------------------- */
  
    for (i=0; i < iters; i++) {
      ptrs[i] = upc_alloc(1); 
    }
    for (i=0; i < iters; i++) {
      upc_free(ptrs[i]); 
    }
    for (i=0; i < iters; i++) {
      ptrs[i] = upc_all_alloc(THREADS, 1); 
    }
    if (MYTHREAD == 0) {
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
    }
    for (i=0; i < iters; i++) {
      ptrs[i] = upc_global_alloc(THREADS, 1); 
    }
    for (i=0; i < iters; i++) {
      upc_free(ptrs[i]); 
    }
    upc_barrier;

  /* ----------------------------------------------------- */
    ZEROMSG("\n    --- Timing upc_barrier ---\n\n");
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      upc_barrier;
    }
    total = TIME() - start;
    upc_barrier;
    if (MYTHREAD == 0) report(total, "Anon. Barrier latency");
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      upc_barrier i;
    }
    total = TIME() - start;
    upc_barrier;
    if (MYTHREAD == 0) report(total, "Named Barrier latency");

  /* ----------------------------------------------------- */
    ZEROMSG("\n    --- Timing upc_alloc() and upc_free() ---\n\n");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == 0) {
      start = TIME();
      for (i=0; i < iters; i++) {
        ptrs[i] = upc_alloc(1); /* 1 byte on thread */
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_alloc(1) on T0");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == 0) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_free() from T0");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == THREADS-1) {
      start = TIME();
      for (i=0; i < iters; i++) {
        ptrs[i] = upc_alloc(1); /* 1 byte on thread */
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == THREADS-1) report(total, "upc_alloc(1) on TN");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == THREADS-1) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == THREADS-1) report(total, "upc_free() from TN");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == 0) {
      start = TIME();
      for (i=0; i < iters; i++) {
        ptrs[i] = upc_alloc(1); /* 1 byte on thread */
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_alloc(1) on T0");
  /* ----------------------------------------------------- */
    /* move pointers to a different thread */
    if (MYTHREAD == 0) 
      upc_memput(shptrs, ptrs, iters * sizeof(shared char *)); /* push */
    upc_barrier;
    if (MYTHREAD == THREADS-1) 
      upc_memget(ptrs, shptrs, iters * sizeof(shared char *)); /* pull */
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == THREADS-1) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == THREADS-1) report(total, "upc_free() from TN");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == THREADS-1) {
      start = TIME();
      for (i=0; i < iters; i++) {
        ptrs[i] = upc_alloc(1); /* 1 byte on thread */
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == THREADS-1) report(total, "upc_alloc(1) on TN");
  /* ----------------------------------------------------- */
    /* move pointers to a different thread */
    if (MYTHREAD == THREADS-1) 
      upc_memput(shptrs, ptrs, iters * sizeof(shared char *)); /* push */
    upc_barrier;
    if (MYTHREAD == 0) 
      upc_memget(ptrs, shptrs, iters * sizeof(shared char *)); /* pull */
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == 0) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_free() from T0");

  /* ----------------------------------------------------- */
    ZEROMSG("\n    --- Timing upc_all_alloc() and upc_free() ---\n\n");
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      ptrs[i] = upc_all_alloc(THREADS, 1); /* 1 byte on each thread */
    }
    total = TIME() - start;
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_all_alloc(THREADS,1)");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == 0) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_free() from T0");
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      ptrs[i] = upc_all_alloc(THREADS, 1); /* 1 byte on each thread */
    }
    total = TIME() - start;
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_all_alloc(THREADS,1)");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == THREADS-1) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == THREADS-1) report(total, "upc_free() from TN");
  /* ----------------------------------------------------- */
  upc_barrier;

  /* ----------------------------------------------------- */
    ZEROMSG("\n    --- Timing upc_global_alloc() and upc_free() ---\n\n");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == 0) {
      start = TIME();
      for (i=0; i < iters; i++) {
        ptrs[i] = upc_global_alloc(THREADS, 1); /* 1 byte per thread */
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_global_alloc(THREADS, 1) on T0");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == 0) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_free() from T0");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == THREADS-1) {
      start = TIME();
      for (i=0; i < iters; i++) {
        ptrs[i] = upc_global_alloc(THREADS, 1); /* 1 byte per thread */
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == THREADS-1) report(total, "upc_global_alloc(THREADS, 1) on TN");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == THREADS-1) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == THREADS-1) report(total, "upc_free() from TN");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == 0) {
      start = TIME();
      for (i=0; i < iters; i++) {
        ptrs[i] = upc_global_alloc(THREADS, 1); /* 1 byte per thread */
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_global_alloc(THREADS, 1) on T0");
  /* ----------------------------------------------------- */
    /* move pointers to a different thread */
    if (MYTHREAD == 0) 
      upc_memput(shptrs, ptrs, iters * sizeof(shared char *)); /* push */
    upc_barrier;
    if (MYTHREAD == THREADS-1) 
      upc_memget(ptrs, shptrs, iters * sizeof(shared char *)); /* pull */
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == THREADS-1) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == THREADS-1) report(total, "upc_free() from TN");
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == THREADS-1) {
      start = TIME();
      for (i=0; i < iters; i++) {
        ptrs[i] = upc_global_alloc(THREADS, 1); /* 1 byte per thread */
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == THREADS-1) report(total, "upc_global_alloc(THREADS, 1) on TN");
  /* ----------------------------------------------------- */
    /* move pointers to a different thread */
    if (MYTHREAD == THREADS-1) 
      upc_memput(shptrs, ptrs, iters * sizeof(shared char *)); /* push */
    upc_barrier;
    if (MYTHREAD == 0) 
      upc_memget(ptrs, shptrs, iters * sizeof(shared char *)); /* pull */
  /* ----------------------------------------------------- */
    upc_barrier;
    if (MYTHREAD == 0) {
      start = TIME();
      for (i=0; i < iters; i++) {
        upc_free(ptrs[i]); 
      }
      total = TIME() - start;
    }
    upc_barrier;
    if (MYTHREAD == 0) report(total, "upc_free() from T0");

  upc_barrier;

  /* cleanup */
  free(ptrs);
  ZEROMSG("-------------------------------------------------------------------------------\n");
  if (threshwarning) {
    ZEROMSG(" (*) = Total time too short relative to timer granularity/overhead.\n"
            "       Number should not be trusted - run more iterations.\n");
  }
  if (MYTHREAD == 0) upc_free(shptrs);
  ZEROMSG("done.\n");

  upc_barrier;

  return 0;
}

/* UPC atomic performance tester, v0.1
 * Written by Dan Bonachea
 * Copyright 2014, The Regents of the University of California 
 * This code is under BSD license: http://upc.lbl.gov/download/dist/LICENSE.TXT
 */

/*******************************************************************************
atomicperf is a microbenchmark that exercises a representative sample of
interesting cases for the UPC 1.3 atomics library.  It requires a compliant
implementation of the atomics library standard and a UPC 1.2 compliant
compiler.

Usage: atomicperf [<iterations>]

The test defaults to 10000 iterations, which should complete in reasonable time
on most systems, but is probably too short to provide reliable answers on
high-performance shared memory systems. The test requires a unary or even
number of threads, and provides the most meaningful results with at least four
threads.

By default it measures five representative types, but all eleven types can be
enabled with -DTEST_ALLTYPES.  The test creates a domain with all the available
operations on the given type, and then proceeds to measure the performance of a
sampling of interesting operations. All AMO operations are relaxed (except
where labeled in the output as strict). 

Operations are measured under various scenarios wrt. the target of the AMO: 

 - a "local" uncontended target memory location (with affinity to the calling
   thread). Represents best-case performance.

 - a "remote" uncontended target memory location (with affinity to an idle
   thread, that is as "far away" as possible). Represents worst-case communication
   latency with best-case contention.

 - a target location on thread zero contended by all threads. Represents
   worst-case performance for most threads.

Timing is reported as avg/min/max latency per operation across active threads.
The test assumes the relaxed AMOs are performed as fully blocking operations,
although a very smart UPC optimizer could potentially pipeline/coalesce/overlap
adjacent operations (thus invalidating the timings). No result validation is
performed.  The test additionally measures a couple related system functions
(eg barriers + locks) for rough comparison purposes.

 *******************************************************************************/
#include <upc.h>
#include <upc_atomic.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>

#ifndef MIN
#define MIN(x,y)  ((x)<(y)?(x):(y))
#endif
#ifndef MAX
#define MAX(x,y)  ((x)>(y)?(x):(y))
#endif

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
static void report(int64_t timeus, const char *msg, int include_this_thread) {
  const char *threshmark = "";
  double myus = ((double)timeus)/giters;
  static shared double minus, maxus, avgus, activecnt;
  static upc_atomicdomain_t *dom;
  if (!MYTHREAD) { minus = 1e20; maxus = avgus = activecnt = 0; } 
  if (!dom) dom = upc_all_atomicdomain_alloc(UPC_DOUBLE, UPC_MIN|UPC_MAX|UPC_ADD|UPC_INC, 0);
  upc_barrier;
  if (include_this_thread) {
      upc_atomic_relaxed(dom, NULL, UPC_MIN, &minus, &myus, NULL);
      upc_atomic_relaxed(dom, NULL, UPC_MAX, &maxus, &myus, NULL);
      upc_atomic_relaxed(dom, NULL, UPC_ADD, &avgus, &myus, NULL);
      upc_atomic_relaxed(dom, NULL, UPC_INC, &activecnt, NULL, NULL);
  }
  upc_barrier;
  if (!MYTHREAD) {
    avgus = avgus / activecnt;
    if (minus*giters < TIMER_THRESHOLD_US) {
      threshmark = "(*)";
      threshwarning = 1;
    }
    printf(" %-40s: Total=%6.3f sec  Avg/Min/Max=%6.3f %6.3f %6.3f us %s\n",
      msg, ((double)maxus)*giters/1000000, avgus, minus, maxus, threshmark);
    fflush(stdout);
  }
}

/* Usage: atomicperf <iters>
 * Runs a performance test of various UPC atomic-related functions
 *  performance of a few related functions is also shown for comparison purposes
 * Average performance is reported 
 */

upc_lock_t * shared alllocks[THREADS];

int main(int argc, char **argv) {
  if (THREADS > 1 && THREADS % 2 != 0) { 
    if (!MYTHREAD) printf("ERROR: this test requires a unary or even thread count\n"); 
    exit(1);
  }
  //if (THREADS < 4 && !MYTHREAD) printf("WARNING: this test provides the most complete results with 4+ threads\n"); 

  int64_t start,total;
  int i = 0;
  int iters = 0;

  if (argc > 1) iters = atoi(argv[1]);
  if (iters <= 0) iters = 10000;
  giters = iters;

  if (MYTHREAD == 0) {
      printf("Running atomicperf test with %i iterations, %i threads\n", iters, THREADS);
      printf("-------------------------------------------------------------------------------\n");
      fflush(stdout);
  }

  /* create locks and exchange information */
  upc_lock_t *mylock = upc_global_lock_alloc(); 
  alllocks[MYTHREAD] = mylock;
  upc_barrier;
 
  int partnerid;
#if defined __BERKELEY_UPC_RUNTIME__
  if (THREADS == 1) {
    partnerid = 0;
  } else {
    /* Automatically select between "cyclic" or "block" layout to maximize minimum separation */
    int cyclicid = (MYTHREAD^1);
    int blockedid = ((MYTHREAD + (THREADS/2)) % THREADS);
    int distance;
    static shared int min_cyclic = BUPC_THREADS_VERYFAR, min_block = BUPC_THREADS_VERYFAR;
    upc_atomicdomain_t *dom = upc_all_atomicdomain_alloc(UPC_INT, UPC_MIN, 0);
    upc_barrier;

    distance = bupc_thread_distance(MYTHREAD, cyclicid);
    upc_atomic_relaxed(dom, NULL, UPC_MIN, &min_cyclic, &distance, NULL);

    distance = bupc_thread_distance(MYTHREAD, blockedid);
    upc_atomic_relaxed(dom, NULL, UPC_MIN, &min_block, &distance, NULL);

    upc_barrier;

    if (min_cyclic > min_block) {
      partnerid = cyclicid;
    } else {
      partnerid = blockedid;
    }
  }
#elif 1  /* assumes block layout of threads is the more common case */
  /* The following assumes "block" allocation of threads to nodes */
  partnerid = (THREADS == 1) ? 0 : ((MYTHREAD + (THREADS/2)) % THREADS);
#else
  /* The following assumes "cyclic" allocation of threads to nodes */
  partnerid = (THREADS == 1 )? 0 : (MYTHREAD^1);
#endif

  if (MYTHREAD < partnerid) printf("Thread Partners: %i <=> %i\n", MYTHREAD, partnerid);
  fflush(NULL);
  upc_barrier;

  #define OPS_ACCESS  ((upc_op_t)(UPC_GET | UPC_SET | UPC_CSWAP))
  #define OPS_BITWISE ((upc_op_t)(UPC_AND | UPC_OR | UPC_XOR))
  #define OPS_NUMERIC ((upc_op_t)(UPC_ADD | UPC_SUB | UPC_MULT | \
                                UPC_INC | UPC_DEC | \
                                UPC_MAX | UPC_MIN))
  #define OPS_ALL   (OPS_ACCESS | OPS_BITWISE | OPS_NUMERIC)
  #define OPS_INT   OPS_ALL
  #define OPS_PTS   OPS_ACCESS
  #define OPS_FLOAT (OPS_ACCESS | OPS_NUMERIC)

  #define TEST_OP(desc, code) do {                      \
    upc_barrier;                                        \
    if (selected)                                       \
      for (i=0; i < MIN(10,iters/10); i++) { code; }    \
    upc_barrier;                                        \
    start = TIME();                                     \
    if (selected) {                                     \
      for (i=0; i < iters; i++) {                       \
        code;                                           \
      }                                                 \
    }                                                   \
    total = TIME() - start;                             \
    upc_barrier;                                        \
    report(total, desc, selected);                      \
   } while(0) 

  #define TEST_OPS(target, include_this_thread) do {                                                           \
    int selected = include_this_thread;                                                                        \
    if (ops&UPC_GET)   TEST_OP("GET",   upc_atomic_relaxed(d, &fetch, UPC_GET, target, NULL, NULL));           \
    if (ops&UPC_SET)   TEST_OP("SET",   upc_atomic_relaxed(d, NULL, UPC_SET, target, &tmp1, NULL));            \
    if (ops&UPC_SET)   TEST_OP("SWAP",  upc_atomic_relaxed(d, &fetch, UPC_SET, target, &tmp1, NULL));          \
    if (ops&UPC_CSWAP) TEST_OP("CSWAP", upc_atomic_relaxed(d, &fetch, UPC_CSWAP, target, &tmp1, &tmp2));       \
    if (ops&UPC_GET)   TEST_OP("strict GET",   upc_atomic_strict(d, &fetch, UPC_GET, target, NULL, NULL));     \
    if (ops&UPC_SET)   TEST_OP("strict SET",   upc_atomic_strict(d, NULL, UPC_SET, target, &tmp1, NULL));      \
    if (ops&UPC_SET)   TEST_OP("strict SWAP",  upc_atomic_strict(d, &fetch, UPC_SET, target, &tmp1, NULL));    \
    if (ops&UPC_CSWAP) TEST_OP("strict CSWAP", upc_atomic_strict(d, &fetch, UPC_CSWAP, target, &tmp1, &tmp2)); \
    if (ops&UPC_ADD)   TEST_OP("fetch-ADD",   upc_atomic_relaxed(d, &fetch, UPC_ADD, target, &tmp1, NULL));    \
    if (ops&UPC_INC)   TEST_OP("fetch-INC",   upc_atomic_relaxed(d, &fetch, UPC_INC, target, NULL, NULL));     \
    if (ops&UPC_SUB)   TEST_OP("fetch-SUB",   upc_atomic_relaxed(d, &fetch, UPC_SUB, target, &tmp1, NULL));    \
    if (ops&UPC_DEC)   TEST_OP("fetch-DEC",   upc_atomic_relaxed(d, &fetch, UPC_DEC, target, NULL, NULL));     \
    if (ops&UPC_MULT)  TEST_OP("fetch-MULT",  upc_atomic_relaxed(d, &fetch, UPC_MULT, target, &tmp1, NULL));   \
    if (ops&UPC_MIN)   TEST_OP("fetch-MIN",   upc_atomic_relaxed(d, &fetch, UPC_MIN, target, &tmp1, NULL));    \
    if (ops&UPC_MAX)   TEST_OP("fetch-MAX",   upc_atomic_relaxed(d, &fetch, UPC_MAX, target, &tmp1, NULL));    \
    if (ops&UPC_AND)   TEST_OP("fetch-AND",   upc_atomic_relaxed(d, &fetch, UPC_AND, target, &tmp1, NULL));    \
    if (ops&UPC_OR)    TEST_OP("fetch-OR",    upc_atomic_relaxed(d, &fetch, UPC_OR, target, &tmp1, NULL));     \
    if (ops&UPC_XOR)   TEST_OP("fetch-XOR",   upc_atomic_relaxed(d, &fetch, UPC_XOR, target, &tmp1, NULL));    \
  } while (0)


  #define TEST(T, TM, OPS) do {                                                         \
    ZEROMSG("\n    --- Timing "#TM" atomics ---\n\n");                                  \
    upc_atomicdomain_t **domarr = malloc(iters*sizeof(upc_atomicdomain_t *));           \
    static shared T vals[THREADS];                                                      \
    shared T *ltarget = &vals[MYTHREAD];                                                \
    shared T *ptarget = &vals[partnerid];                                               \
    shared T *ztarget = &vals[0];                                                       \
    upc_barrier;  /* warmup */                                                          \
    for (i=0; i < iters; i++) domarr[i] = upc_all_atomicdomain_alloc(TM, OPS, 0);       \
    for (i=0; i < iters; i++) upc_all_atomicdomain_free(domarr[i]);                     \
    for (i=0; i < iters; i++) upc_atomic_isfast(TM, OPS, ptarget);                      \
    upc_barrier; /* alloc test */                                                       \
    start = TIME();                                                                     \
    for (i=0; i < iters; i++) {                                                         \
      domarr[i] = upc_all_atomicdomain_alloc(TM, OPS, 0);                               \
    }                                                                                   \
    total = TIME() - start;                                                             \
    upc_barrier;                                                                        \
    report(total, "upc_all_atomicdomain_alloc", 1);                                     \
    upc_barrier; /* free test */                                                        \
    start = TIME();                                                                     \
    for (i=0; i < iters; i++) {                                                         \
      upc_all_atomicdomain_free(domarr[i]);                                             \
    }                                                                                   \
    total = TIME() - start;                                                             \
    report(total, "upc_all_atomicdomain_free", 1);                                      \
    upc_barrier; /* isfast test */                                                      \
    start = TIME();                                                                     \
    for (i=0; i < iters; i++) {                                                         \
      upc_atomic_isfast(TM, OPS, ptarget);                                              \
    }                                                                                   \
    total = TIME() - start;                                                             \
    report(total, "upc_atomic_isfast", 1);                                              \
    upc_barrier; /* atomic op tests */                                                  \
    upc_atomicdomain_t *d = upc_all_atomicdomain_alloc(TM, OPS, 0);                     \
    T fetch, tmp1 = 0, tmp2 = 0;                                                        \
    upc_op_t ops = OPS;                                                                 \
    ZEROMSG("    === Local (uncontended) ===\n");                                       \
    TEST_OPS(ltarget, 1);                                                               \
    if (THREADS >= 2) {                                                                 \
      ZEROMSG("    === Remote (uncontended) ===\n");                                    \
      TEST_OPS(ptarget, MYTHREAD <= partnerid);                                         \
      ZEROMSG("    === All to one (contendedxTHREADS) === \n");                         \
      TEST_OPS(ztarget, 1);                                                             \
    }                                                                                   \
  } while(0)

#ifdef TEST_ALLTYPES
  TEST(int,             UPC_INT,    OPS_INT);
  TEST(unsigned int,    UPC_UINT,   OPS_INT);
  TEST(long,            UPC_LONG,   OPS_INT);
  TEST(unsigned long,   UPC_ULONG,  OPS_INT);
  TEST(uint32_t,        UPC_UINT32, OPS_INT);
  TEST(uint64_t,        UPC_UINT64, OPS_INT);
#endif
  TEST(int32_t,         UPC_INT32,  OPS_INT);
  TEST(int64_t,         UPC_INT64,  OPS_INT);

  TEST(float,           UPC_FLOAT,  OPS_FLOAT);
  TEST(double,          UPC_DOUBLE, OPS_FLOAT);

  typedef shared void *svp_t;
  TEST(svp_t,           UPC_PTS, OPS_PTS);

  /* ----------------------------------------------------- */
  /* Other "possibly-related" system functions             */
  /* ----------------------------------------------------- */
  shared char **ptrs = malloc(sizeof(shared char *) * iters);

  /* ----------------------------------------------------- 
   * Warm up the allocator
   * alloc and free some memory to pay any first-call costs
   * (e.g. obtaining pages from the system) so that we 
   * measure steady-state behavior
   * ----------------------------------------------------- */

    for (i=0; i < iters; i++) {
      ptrs[i] = upc_all_alloc(THREADS, 1);
    }
    for (i=0; i < iters; i++) {
      upc_all_free(ptrs[i]);
    }
    upc_barrier;

  /* ----------------------------------------------------- */
    ZEROMSG("\n    --- Timing upc_all_alloc() and upc_all_free() ---\n\n");
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      ptrs[i] = upc_all_alloc(THREADS, 1); /* 1 byte on each thread */
    }
    total = TIME() - start;
    upc_barrier;
    report(total, "upc_all_alloc(THREADS,1)", 1);
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      upc_all_free(ptrs[i]);
    }
    total = TIME() - start;
    upc_barrier;
    report(total, "upc_all_free()", 1);
  /* ----------------------------------------------------- */


  /* ----------------------------------------------------- */
  /* fetch lock pointers from remote and cache them in local vars */
  upc_lock_t *partnerlock = alllocks[partnerid]; 
  upc_lock_t *zerolock = alllocks[0]; 

  /* ----------------------------------------------------- 
   * Warm up the locks
   * pay any first-call costs so that we 
   * measure steady-state behavior
   * ----------------------------------------------------- */
  
    for (i=0; i < MIN(10,iters/10); i++) {
      upc_lock(mylock); 
      upc_unlock(mylock); 
      upc_lock(partnerlock); 
      upc_unlock(partnerlock); 
    }
    upc_barrier;

  /* ----------------------------------------------------- */
    ZEROMSG("\n    --- Timing upc_lock/upc_unlock latency ---\n\n");
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      upc_lock(mylock); 
      upc_unlock(mylock); 
    }
    total = TIME() - start;
    upc_barrier;
    report(total, "local lock, uncontended (others testing)", 1);
  /* ----------------------------------------------------- */
  if (THREADS > 1) {
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      upc_lock(partnerlock); 
      upc_unlock(partnerlock); 
    }
    total = TIME() - start;
    upc_barrier;
    report(total, "remote lock, uncontended (peer testing)", 1);
  }
  /* ----------------------------------------------------- */
  if (THREADS > 1) {
    upc_barrier;
    for (int j = 0; j < 2; ++j) {
      if ((MYTHREAD & 1) == j) {
        start = TIME();
        for (i=0; i < iters; i++) {
          upc_lock(partnerlock); 
          upc_unlock(partnerlock); 
        }
        total = TIME() - start;
      }
      upc_barrier;
    }
    report(total, "remote lock, uncontended (peer polling)", 1);
  }
  /* ----------------------------------------------------- */
  if (THREADS >= 4) {
    char msg[255];
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      upc_lock(zerolock); 
      upc_unlock(zerolock); 
    }
    total = TIME() - start;
    upc_barrier;
    sprintf(msg, "lock contended by %i threads, one local", THREADS);
    report(total, msg, 1);
  }
  /* ----------------------------------------------------- */
    ZEROMSG("\n    --- Timing lock allocation/deallocation ---\n\n");
  /* ----------------------------------------------------- */
    upc_lock_t **lockarr = malloc(iters*sizeof(upc_lock_t *));

    upc_barrier; /* warm up */
    for (i=0; i < iters; i++) lockarr[i] = upc_global_lock_alloc();
    for (i=0; i < iters; i++) upc_lock_free(lockarr[i]);
    for (i=0; i < MIN(10,iters/10); i++) lockarr[i] = upc_all_lock_alloc();
    if (!MYTHREAD) {
      for (i=0; i < MIN(10,iters/10); i++) upc_lock_free(lockarr[i]);
    }
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      lockarr[i] = upc_global_lock_alloc();
    }
    total = TIME() - start;
    upc_barrier;
    report(total, "upc_global_lock_alloc", 1);
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      upc_lock_free(lockarr[i]);
    }
    total = TIME() - start;
    upc_barrier;
    report(total, "upc_lock_free local (others testing)", 1);
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      lockarr[i] = upc_all_lock_alloc();
    }
    total = TIME() - start;
    upc_barrier;
    report(total, "upc_all_lock_alloc", 1);
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    if (!MYTHREAD) {
      for (i=0; i < iters; i++) {
        upc_lock_free(lockarr[i]);
      }
    }
    total = TIME() - start;
    upc_barrier;
    report(total, "upc_lock_free from T0", !MYTHREAD);
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
    report(total, "Anon. Barrier latency", 1);
  /* ----------------------------------------------------- */
    upc_barrier;
    start = TIME();
    for (i=0; i < iters; i++) {
      upc_barrier i;
    }
    total = TIME() - start;
    upc_barrier;
    report(total, "Named Barrier latency", 1);
  /* ----------------------------------------------------- */

  upc_barrier;
  /* cleanup */
  free(lockarr);
  upc_lock_free(mylock);
  ZEROMSG("-------------------------------------------------------------------------------\n");
  if (threshwarning) {
    ZEROMSG(" (*) = Total time too short relative to timer granularity/overhead.\n"
            "       Number should not be trusted - run more iterations.\n");
  }
  ZEROMSG("done.\n");

  upc_barrier;

  return 0;
}

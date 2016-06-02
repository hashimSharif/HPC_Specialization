/*    $Source: bitbucket.org:berkeleylab/upc-runtime.git/upc-tests/benchmarks/bupc_memperf.upc $ */
/*  Description: UPC memcpy extensions performance microbenchmark */
/*  Copyright 2005, Dan Bonachea <bonachea@cs.berkeley.edu> */

#include <upc.h>
#include <upc_tick.h>
#include <upc_nb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* usage: bupc_memperf (<iters> (<maxsz> ([ABGPFL]))) 
   A = _async operations
   B = blocking operations
   P = puts
   G = gets
   F = Flood test
   L = Latency test
 */

int main(int argc, char **argv) {
  int iters=0, maxsz=0;
  int doasync=0, doblocking=0, doput=0, doget=0, doflood=0, dolatency=0;
  const char *optype = "ABPGFL";
  int peerid = (MYTHREAD+1)%THREADS, iamsender = !(MYTHREAD&0x1);
  if (argc > 1) iters = atoi(argv[1]);
  if (!iters) iters = 1000;
  if (argc > 2) maxsz = atoi(argv[2]);
  if (!maxsz) maxsz=2*1048576;
  if (argc > 3) optype = argv[3];
  if (strchr(optype,'A') || strchr(optype,'a')) doasync = 1;
  if (strchr(optype,'B') || strchr(optype,'b')) doblocking = 1;
  if (!doasync && !doblocking) { doasync = 1; doblocking = 1; }
  if (strchr(optype,'P') || strchr(optype,'p')) doput = 1;
  if (strchr(optype,'G') || strchr(optype,'g')) doget = 1;
  if (!doput && !doget) { doput = 1; doget = 1; }
  if (strchr(optype,'F') || strchr(optype,'f')) doflood = 1;
  if (strchr(optype,'L') || strchr(optype,'l')) dolatency = 1;
  if (!doflood && !dolatency) { doflood = 1; dolatency = 1; }

  shared char *data = upc_all_alloc(THREADS, maxsz*2);
  shared [] char *remote = (shared [] char *)(data + peerid);
  char *local = ((char *)(data+MYTHREAD))+maxsz;
  upc_handle_t *handles = malloc(iters*sizeof(upc_handle_t));

#ifdef __BERKELEY_UPC_RUNTIME___
  if (!MYTHREAD) printf("Timer granularity: <= %.3f us, overhead: ~ %.3f us\n",
       bupc_tick_granularityus(), bupc_tick_overheadus()); fflush(stdout);
#endif

  #define LATENCYTEST(desc, op, numiters, datasz, report) do {            \
    if (iamsender) {                                                      \
      upc_tick_t start = upc_ticks_now();                                 \
        for (int i=0; i < numiters; i++) {                                \
          op;                                                             \
        }                                                                 \
      upc_barrier;                                                        \
      if (report) {                                                       \
        double secs = upc_ticks_to_ns(upc_ticks_now()-start)*1.e-9;       \
        double latencyus = secs*1000000.0/numiters;                       \
        printf("%3i: %10i byte, %11.6f secs: %11.3f us/iter (%s)\n",      \
                MYTHREAD, datasz, secs, latencyus, desc);                 \
        fflush(stdout);                                                   \
      }                                                                   \
    } else upc_barrier;                                                   \
  } while (0)

  upc_barrier;
  if (dolatency) {
    if (!MYTHREAD) printf("Round-trip latency test iters=%i maxsz=%i\n",iters,maxsz); fflush(stdout);

    /* operation warm-up */
    LATENCYTEST("upc_memget", upc_memget(local, remote, 8), iters, 8, 0);
    LATENCYTEST("upc_memput", upc_memput(remote, local, 8), iters, 8, 0);
    LATENCYTEST("upc_memget_nb", upc_sync(upc_memget_nb(local, remote, 8)), iters, 8, 0);
    LATENCYTEST("upc_memput_nb", upc_sync(upc_memput_nb(remote, local, 8)), iters, 8, 0);
    for (int sz = 1; sz <= maxsz; sz*=2) {
      upc_barrier;
      /* per-size warm-up */
      LATENCYTEST("upc_memget", upc_memget(local, remote, sz), 1, sz, 0);
      LATENCYTEST("upc_memput", upc_memput(remote, local, sz), 1, sz, 0);
      LATENCYTEST("upc_memget_nb", upc_sync(upc_memget_nb(local, remote, sz)), 1, sz, 0);
      LATENCYTEST("upc_memput_nb", upc_sync(upc_memput_nb(remote, local, sz)), 1, sz, 0);
      upc_barrier;
      if (doblocking && doget) 
        LATENCYTEST("upc_memget", upc_memget(local, remote, sz), iters, sz, 1);
      upc_barrier;
      if (doasync && doget) 
        LATENCYTEST("upc_memget_nb", upc_sync(upc_memget_nb(local, remote, sz)), iters, sz, 1);
      upc_barrier;
      if (doblocking && doput) 
        LATENCYTEST("upc_memput", upc_memput(remote, local, sz), iters, sz, 1);
      upc_barrier;
      if (doasync && doput) 
        LATENCYTEST("upc_memput_nb", upc_sync(upc_memput_nb(remote, local, sz)), iters, sz, 1);
    }
  }

  #define FLOODTEST(desc, op, numiters, datasz, report, reap) do {            \
    if (iamsender) {                                                          \
      upc_tick_t start = upc_ticks_now();                                     \
        for (int i=0; i < numiters; i++) {                                    \
          op;                                                                 \
        }                                                                     \
        if (reap) for (int i=0; i < numiters; i++) upc_sync(handles[i]); \
      upc_barrier;                                                            \
      if (report) {                                                           \
        double secs = upc_ticks_to_ns(upc_ticks_now()-start)*1.e-9;           \
        double bwKB = (((double)datasz) * numiters / 1024.0) / secs;          \
        printf("%3i: %10i byte, %11.6f secs: %11.3f KB/sec (%s)\n",           \
                MYTHREAD, datasz, secs, bwKB, desc);                          \
        fflush(stdout);                                                       \
      }                                                                       \
    } else upc_barrier;                                                       \
  } while (0)

  upc_barrier;
  if (doflood) {
    if (!MYTHREAD) printf("Flood bandwidth test iters=%i maxsz=%i\n",iters,maxsz); fflush(stdout);

    /* operation warm-up */
    FLOODTEST("upc_memget", upc_memget(local, remote, 8), iters, 8, 0, 0);
    FLOODTEST("upc_memput", upc_memput(remote, local, 8), iters, 8, 0, 0);
    FLOODTEST("upc_memget_nb", handles[i] = upc_memget_nb(local, remote, 8), iters, 8, 0, 1);
    FLOODTEST("upc_memput_nb", handles[i] = upc_memput_nb(remote, local, 8), iters, 8, 0, 1);
    for (int sz = 1; sz <= maxsz; sz*=2) {
      upc_barrier;
      /* per-size warm-up */
      FLOODTEST("upc_memget", upc_memget(local, remote, sz), 1, sz, 0, 0);
      FLOODTEST("upc_memput", upc_memput(remote, local, sz), 1, sz, 0, 0);
      FLOODTEST("upc_memget_nb", handles[i] = upc_memget_nb(local, remote, sz), 1, sz, 0, 1);
      FLOODTEST("upc_memput_nb", handles[i] = upc_memput_nb(remote, local, sz), 1, sz, 0, 1);
      upc_barrier;
      if (doblocking && doget) 
        FLOODTEST("upc_memget", upc_memget(local, remote, sz), iters, sz, 1, 0);
      upc_barrier;
      if (doasync && doget) 
        FLOODTEST("upc_memget_nb", handles[i] = upc_memget_nb(local, remote, sz), iters, sz, 1, 1);
      upc_barrier;
      if (doblocking && doput) 
        FLOODTEST("upc_memput", upc_memput(remote, local, sz), iters, sz, 1, 0);
      upc_barrier;
      if (doasync && doput) 
        FLOODTEST("upc_memput_nb", handles[i] = upc_memput_nb(remote, local, sz), iters, sz, 1, 1);
    }
  }

  upc_barrier;
  if (!MYTHREAD) printf("done.\n");
  return 0;
}

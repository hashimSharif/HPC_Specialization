/*
  This test case would sometimes trigger a fatal error when run with >= 2
  pthreads on a single node (regardless of network, though smp is easiest).

  The problem was that the single-node optimization inside of
  upcr_wait_internal() was allowing a collective operation to begin in thread 1
  while thread 0 was still performing a gasnet_barrier_wait().  The collective
  (with OUT_ALLSYNC) would call gasnet_barrier_notify() resulting in
  "*** GASNet FATAL ERROR: gasnet_barrier_notify() called twice in a row"

  If/when the single-node optimization is fixed this test will help verify it.

  This problem never received a bug id.
*/

#include <upc.h>
#include <upc_collective.h>
#include <stdio.h>

#define ITERS 10

shared double A = 1.2;
shared double B[THREADS];

int main(void) {
  int i;

  for (i = 0; i < ITERS; ++i) {
    upc_barrier;
    upc_all_broadcast(B, &A, sizeof(double), UPC_IN_ALLSYNC | UPC_OUT_MYSYNC);
    upc_barrier;
    upc_all_broadcast(B, &A, sizeof(double), UPC_IN_NOSYNC  | UPC_OUT_ALLSYNC);
  }

  printf("done.\n");
  upc_barrier;

  return 0;
}


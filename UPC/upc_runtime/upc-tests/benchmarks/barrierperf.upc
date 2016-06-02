#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

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

int main(int argc, char **argv) {
  int iters=0;
  int64_t start,total;
  int i = 0;

  if (argc > 1) iters = atoi(argv[1]);
  if (!iters) iters = 10000;

  if (MYTHREAD == 0) {
      printf("running barrier perf test with %i iterations, %i threads\n",iters, THREADS);
      fflush(stdout);
  }
  upc_barrier;

  start = TIME();
  for (i=0; i < iters; i++) {
    upc_barrier i;
  }
  total = TIME() - start;

  upc_barrier;

  if (MYTHREAD == 0) {
      printf("Total time: %8.3f sec  Avg Named Barrier latency: %8.3f us\n",
        ((float)total)/1000000, ((float)total)/iters);
      fflush(stdout);
  }
  upc_barrier;

  start = TIME();
  for (i=0; i < iters; i++) {
    upc_barrier;
  }
  total = TIME() - start;

  upc_barrier;

  if (MYTHREAD == 0) {
      printf("Total time: %8.3f sec  Avg Anon. Barrier latency: %8.3f us\n",
        ((float)total)/1000000, ((float)total)/iters);
      fflush(stdout);
  }

  if (MYTHREAD == 0) printf("done.\n");

  return 0;
}

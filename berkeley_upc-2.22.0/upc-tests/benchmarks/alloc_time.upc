#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdint.h>

#if __UPC_TICK__
#include <upc_tick.h>
#endif

static int64_t mygetMicrosecondTimeStamp(void)
{
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

void do_alloc(int iter, int nbtyes); 

int main (int argc, char** argv) {

  if (argc != 3) {
    if (MYTHREAD == 0) {
      printf("Usage: ./alloc_time iter KBytes\n");
    }
    upc_global_exit(1);
  }
  
  do_alloc(atoi(argv[1]), atoi(argv[2]) * 1024);
  upc_barrier;
  printf("done.\n");
}

shared double time_counter[THREADS];

void do_alloc(int iter, int nbytes) {

  shared [] char *p;
  int i = 0;
  double start, end;
  double max = 0;
  
  if (MYTHREAD == 0) {
    start = TIME();
    for (i = 0; i < iter; i++) {
      p = (shared [] char *) upc_global_alloc(THREADS, nbytes);
      //upc_free(upc_global_alloc(THREADS, nbytes));
      upc_free(p);		
    }
    end = TIME();
    printf("Global Alloc with %d THREADS, %d block size: %f us\n", THREADS, nbytes, (int32_t)(end-start)/(double)iter);
  }
  upc_barrier;
  start = TIME();
  for (i = 0; i < iter; i++) {
    p = (shared [] char *) upc_all_alloc(THREADS, nbytes);
    if (MYTHREAD == 0) {
      upc_free(p);
    }
  }
  end = TIME();
  time_counter[MYTHREAD] = (int32_t)(end-start)/(double)iter; 
  upc_barrier;
  if (MYTHREAD == 0) {
    for (i = 0; i < THREADS; i++) {
      if (max < time_counter[i]) {
	max = time_counter[i];
      }
    }
    printf("All Alloc with %d THREADS, %d block size: %f us\n", THREADS, nbytes, (int32_t)(end-start)/(double)iter);
  }
}

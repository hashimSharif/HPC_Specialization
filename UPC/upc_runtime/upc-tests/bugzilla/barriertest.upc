#include <upc_relaxed.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int iters = 100;
int failed = 0;

static double doWork();
#ifdef __BERKELEY_UPC_ELAN_CONDUIT__
#define SIMPLE_TEST 1
#else
#define SIMPLE_TEST 0
#endif
void barrierid_test() {
  int i;
  if (SIMPLE_TEST || MYTHREAD % 2 == 0) {
    for (i=0;i<iters;i++) {
      upc_barrier i;
    }
    for (i=0;i<iters;i++) {
      upc_notify i;
      upc_wait i;
    }
  } else {
    for (i=0;i<iters;i++) {
      upc_notify;
      upc_wait;
    }
    for (i=0;i<iters;i++) {
      upc_barrier;
    }
  }
}

shared strict int barrier_flag;
#define SET_FLAG(val) barrier_flag = val
#define CHECK_FLAG(val) do {                                   \
  int currflag = barrier_flag;                                 \
  int expected = val;                                          \
  if (currflag != val) {                                       \
    printf("T%i: ERROR - barrier_flag should be %i, got %i\n", \
      MYTHREAD, expected, currflag);                           \
    failed = 1;                                                \
} } while (0)


void barrierrace_test() {
  int i,j;
  upc_barrier;
  for (i=0;i<iters;i++) {
    upc_barrier;
      SET_FLAG(i);
      for (j=0;j<MYTHREAD;j++) {
        doWork();
        CHECK_FLAG(i);
      }
    upc_barrier;
      SET_FLAG(-1);
    upc_barrier;
      if (i % THREADS == MYTHREAD) SET_FLAG(MYTHREAD);
    upc_barrier;
      CHECK_FLAG(i % THREADS);
  }
  upc_barrier;
}

int main(int argc, char **argv) {

  if (argc > 1) iters = atoi(argv[1]);
  if (MYTHREAD == 0) 
    printf("Running barriertest with %i iterations on %i threads\n", iters, THREADS);

  upc_barrier;
  if (MYTHREAD == 0) printf("Barrier id test...\n");
  upc_barrier;
  barrierid_test();
  upc_barrier;
  if (MYTHREAD == 0) printf("Barrier race test...\n");
  upc_barrier;
  barrierrace_test();
  upc_barrier;

  if (MYTHREAD == 0) {
    if (failed) printf("Barrier test FAILED\n");
    else printf("Barrier test SUCCESS\n");
  }
  return failed;
}

static double doWork() {
  int i;
  double x = 1.00001;
  static int workctr = 0;
  int *junkarr = malloc(sizeof(int)*16535); 
  shared char *p = upc_global_alloc(4,4);
  for (i = 0; i < 100000*THREADS; i++) {
    x = x * 0.99999 / 0.9999;
  }
  workctr++;
  if (workctr % 100 == MYTHREAD) sleep(1);  
#ifdef __BERKELEY_UPC_RUNTIME__
  gasnett_sched_yield();
#else
  sleep(0);
#endif
  upc_free(p);
  free(junkarr);
  return x;
}

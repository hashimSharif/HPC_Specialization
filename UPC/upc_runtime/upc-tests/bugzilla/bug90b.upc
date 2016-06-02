#include <upc_strict.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

shared int x[THREADS];
int main(void) {
  x[MYTHREAD] = (MYTHREAD+1)*100;
  upc_barrier;
  if (THREADS < 2) {
    printf("ERROR: test requires at least 2 threads (have only %d)\n", THREADS);
    upc_global_exit(1);
  }
  printf("%i: Hello\n", MYTHREAD);
  upc_barrier;
  if (MYTHREAD == 0) {
    return 0;
  }
  else {
    int i;
    int val = 0;
    int expectedval = 0;
    sleep(5);
    for (i=0;i<THREADS;i++) {
      val += x[i];
      expectedval += (i+1)*100;
    }
    if (val != expectedval) {
      printf("ERROR: bad val: %i  expected: %i\n",val,expectedval);
      return 1;
    }
    printf("%i: done.\n", MYTHREAD);
  }

  return 0;
}

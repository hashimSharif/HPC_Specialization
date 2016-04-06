#include <stdio.h>
#include <upc.h>

shared void *p;

int main(void) {
  int i;

  for (i=0; i<10000; ++i) {
    p = upc_global_alloc(1,4);
  }

  upc_barrier;
  if (MYTHREAD == 0) {
    printf("done.\n");
  }

  return 0;
}

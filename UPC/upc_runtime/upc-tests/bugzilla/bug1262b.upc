#include <upc.h>
#include <stdio.h>
#include <assert.h>

#define SZ 1000
int main(void) {
  for (int i = 0; i < 100; i++) {
    if (MYTHREAD == 0) {
      shared void *p = upc_global_alloc(THREADS,SZ*sizeof(int));
      upc_free(p);
    }
    upc_barrier;
    shared int *p = upc_all_alloc(THREADS,SZ*sizeof(int));
    assert(THREADS%2==0);
    shared [] int *myp = (shared [] int *)(p+(MYTHREAD^1));
    for (int j = 0; j < SZ; j++) myp[j] = 1000+MYTHREAD;
    upc_barrier;
    for (int j = 0; j < SZ; j++) assert(myp[j] == 1000+MYTHREAD);
    upc_barrier;
  }
  printf("done.\n");
  return 0;
}

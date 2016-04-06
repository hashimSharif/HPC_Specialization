// minimal upc_castable test

#include <upc_castable.h>
#include <upc.h>
#include <assert.h>
#include <stdio.h>

shared int arr[THREADS];
int main() {
  shared int *sp = &arr[MYTHREAD];
  int *lp = upc_cast(sp);
  assert(lp == (int *)sp);
  upc_barrier;
  for (int th = (MYTHREAD+1)%THREADS; th != MYTHREAD; th = (th + 1)%THREADS) { 
    upc_barrier;
    sp = &arr[th];
    int *lp = upc_cast(sp);
    if (lp) {
      *lp = MYTHREAD;
      assert(arr[th] == MYTHREAD);
    }
    upc_barrier;
  }
  if (!MYTHREAD) printf("passed\n");
  return 0;
}

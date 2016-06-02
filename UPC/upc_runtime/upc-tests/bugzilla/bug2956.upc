#include <upc.h>
#include <stdio.h>

shared int A[THREADS];
shared int fail = 0;

int main(void)
{
  int j1, j2;
  int k1, k2;
  int limit = 8;

  j1 = k1 = 0;
  upc_forall(int i = 0; i < THREADS; i++ ; (k1++, &A[i]) ) { ++j1; }

  j2 = k2 = 0;
  upc_forall(int i = 0; i < limit; i++ ; (k2++, MYTHREAD) ) { ++j2; }

  upc_barrier;
  if (j1 != 1) {
    printf("FAIL: thread %d has final j1 %d when expecting 1\n", MYTHREAD, j1);
    fail = 1;
  }
  if (k1 != THREADS) {
    printf("FAIL: thread %d has final k1 %d when expecting %d\n", MYTHREAD, k1, THREADS);
    fail = 1;
  }
  if (j2 != limit) {
    printf("FAIL: thread %d has final j2 %d when expecting %d\n", MYTHREAD, j2, limit);
    fail = 1;
  }
  if (k2 != limit) {
    printf("FAIL: thread %d has final k2 %d when expecting %d\n", MYTHREAD, k2, limit);
    fail = 1;
  }

  upc_barrier;
  if (!MYTHREAD && !fail) {
    puts("PASS");
  }

  upc_barrier;
  return 0;
}


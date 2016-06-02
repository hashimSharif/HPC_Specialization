#include <stdio.h>
// alloca() is non-standard and may be in stdlib.h or alloc.h
#include <stdlib.h>
#if !defined(alloca) && !defined(__NetBSD__) && !defined(__OpenBSD__)
#include <alloca.h>
#endif

/* Fibonacci sequence done with wasteful self-verification to exercise alloca().
 * Each stack frame allocates O(n) temporary space.
 * Peak space used by alloca() should be O(n^2) ints.
 */
int fib(int i) {
  int *tmp = alloca(i*sizeof(int));
  int j;

  if (i <= 1)  return 1;

  tmp[i-1] = fib(i-1);
  tmp[i-2] = fib(i-2);

  /* Verification: */
  for (j = i-3; j >= 0; --j) {
    tmp[j] = tmp[j+2] - tmp[j+1];
  }
  if ((tmp[0] != 1) || (tmp[1] != 1)) {
    printf("FAILURE: fib(%d) detected corrupted result\n", i);
  }
  
  return tmp[i-1] + tmp[i-2];
}

struct {
  int in;
  int out;
} X[] = {
	{ 0, 1},
	{ 1, 1},
	{ 2, 2},
	{ 3, 3},
	{ 4, 5},
	{ 5, 8},
	{ 6, 13},
	{ 7, 21},
	{ 8, 34},
	{ 9, 55},
	{10, 89},
	{20, 10946}
};

int main(void) {
  int i;

  for (i = 0; i < sizeof(X)/sizeof(X[0]); ++i) {
    int f = fib(X[i].in);
    if (f != X[i].out) {
      printf("FAILURE: fib(%d) returned %d rather than %d\n", X[i].in, f, X[i].out);
    }
    printf("%4d %d\n", X[i].in, f);
  }

  upc_barrier;

  printf("SUCCESS\n");

  return 0;
}

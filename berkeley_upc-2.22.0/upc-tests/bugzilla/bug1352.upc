#include <assert.h>
#include <stdio.h>

#define ABS(x) (x < 0 ? -(x) : (x))
shared[100] double a[100][100*THREADS];
shared int i = 10, j = 20, k = 30;
void foo() {
  a[j][i] = 4;
  a[j][k] = -5;
}
int main() {
  foo();
  if (ABS(a[j][k]) > a[j][i]) {
    printf("done.\n");
  } else {
    printf("ERROR\n");
  }
  return 0;
}


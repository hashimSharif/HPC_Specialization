#include <stdio.h>
#include <upc.h>

shared [10] int x[10*THREADS];

int main() {
  shared [10] int *x0 = &(x[0]);
  return 0;
}


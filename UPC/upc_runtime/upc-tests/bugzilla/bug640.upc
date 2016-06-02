#include <stdio.h>
#include <upc.h>

shared struct {
  shared [] int *ptr;
} A[THREADS*8];

int main(void) {
  int x = 3;
  shared void *p1, *p2;

  if (MYTHREAD == 0) {
    p1 = &A[x*THREADS];
    p2 = &A[MYTHREAD+x*THREADS];

    if (p1 != p2) {
      printf("ERROR addresses don't match\n");
    } else {
      printf("done.\n");
    }
  }
  
  upc_barrier;
  return 0;
} 
  

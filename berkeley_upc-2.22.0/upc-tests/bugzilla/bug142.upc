#include <stdio.h>
#include <upc.h>

typedef shared int *T;
shared T a[10*THREADS];

int main() {
  int i,j;

    for (i=0;i<10;i++) {
      a[i] = upc_all_alloc(100, sizeof(int)); 
    }

  upc_barrier;

  if (MYTHREAD == 0) {
    for (i=0;i<10;i++) {
     for (j=0;j<100;j++) {
       a[i][j] = 50;
     }
    }
  }
  
  upc_barrier;

  printf("done.\n");
  return 0;
}

#include <upc.h>
#include <stdio.h>

#define SZ_A 1
#define SZ_B 3
#define SZ_C 5

int MEGABYTES = 1024*1024;
shared int* shared a[THREADS];
shared int* shared b[THREADS];
shared int* shared c[THREADS];

int main(void) {
      if (!MYTHREAD) printf("Program should run in about %d MB per thread.\n", 1+SZ_A+SZ_B+SZ_C);

      a[MYTHREAD] = (shared int*)upc_alloc(SZ_A*MEGABYTES);
      b[MYTHREAD] = (shared int*)upc_alloc(SZ_B*MEGABYTES);
      c[MYTHREAD] = (shared int*)upc_alloc(SZ_C*MEGABYTES);

      upc_barrier;
      if (!MYTHREAD) puts("done.");
      return 0;
}


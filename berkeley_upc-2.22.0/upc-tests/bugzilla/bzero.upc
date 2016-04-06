#include <stdio.h>
#include <upc.h>

/* Simple test to see that static data is zeroed as expected */

shared int A[THREADS];
shared int B[THREADS*4];
shared [] int C[100];
shared [1] int D[THREADS*40];
shared [2] int E[THREADS*40];
shared [4] int F[THREADS*40];
shared [3] int G[THREADS*40];
shared int H;

#define CHECK(X) \
 { int i; \
   upc_forall (i=0; i < sizeof(X)/sizeof(int); ++i; &X[i]) { \
     if ( X[i] != 0 ) { \
       printf ("ERROR: " #X "[%d] = %d\n", i, X[i]); \
     } \
   } \
 }

int main(void) {
  CHECK(A);
  CHECK(B);
  CHECK(C);
  CHECK(D);
  CHECK(E);
  CHECK(F);
  CHECK(G);
  if ((MYTHREAD == 0) && (H != 0)) {
    printf ("ERROR: H = %d\n", H);
  }

  upc_barrier;
  if (MYTHREAD == 0) {
    printf ("done.\n");
  }
  return 0;
}

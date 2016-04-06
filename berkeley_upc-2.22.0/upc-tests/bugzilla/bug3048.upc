#include <upc.h>
#include <stdio.h>

#if defined(__UPC_DYNAMIC_THREADS__) || (THREADS < 2)
  #error "Test is valid only for 2 or more static threads"
#endif

#define B1 (4096 + B2) // Has low 12 same as B2
#define B2 1

shared [B1] int A1[B1 * THREADS];
shared [B2] int A2[B2 * THREADS];

int main(void) {
  int error = (upc_threadof(&A2[B2]) != 1);

  if (!MYTHREAD) puts ( error ? "FAIL" : "PASS" );
  upc_barrier;

  return error;
}

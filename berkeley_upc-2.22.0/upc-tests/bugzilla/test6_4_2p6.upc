// Test conformance to 6.4.2p6 of UPC 1.2 spec which says that
// phase is ignored in comparing two compatible pointers-to-shared
// Based on a test case contributed by Gary Funck with some minor
// modifications by Paul H. Hargrove.

#include <upc.h>
#include <stdio.h>
#include <assert.h>

shared [8] int A[8*THREADS];

int main(void)
{
  shared [] int *p = (shared [] int *)&A[3]; // Has phase of 0 by 6.4.2p2
  shared [8] int *q = (shared [8] int *)p;   // Still/again has phase==0

  if (!MYTHREAD) {
    printf ("phase of &A[3] = %u\n", (unsigned)upc_phaseof(&A[3]));
    printf ("phase of p = %u\n", (unsigned)upc_phaseof(p));
    printf ("phase of q = %u\n", (unsigned)upc_phaseof(q));
    printf ("&A[3] - q = %d\n", (int)(&A[3] - q));
    printf ("q     = (%lu,%u,%u)\n",
      (unsigned long)upc_addrfield(q), (unsigned)upc_threadof(q),
      (unsigned)upc_phaseof(q));
    printf ("&A[0] = (%lu,%u,%u)\n",
      (unsigned long)upc_addrfield(&A[0]),
      (unsigned)upc_threadof(&A[0]),
      (unsigned)upc_phaseof(&A[0]));
    printf ("&A[3] = (%lu,%u,%u)\n",
      (unsigned long)upc_addrfield(&A[3]),
      (unsigned)upc_threadof(&A[3]),
      (unsigned)upc_phaseof(&A[3]));
#if 0
    assert(q == &A[3]);
#else
    puts ((q == &A[3]) ? "PASS" : "FAIL");
    fflush(stdout);
#endif
  }

  upc_barrier;

  return 0;
}

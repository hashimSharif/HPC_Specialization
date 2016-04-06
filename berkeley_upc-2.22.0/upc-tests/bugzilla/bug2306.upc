/* Tester for BUPC bug 2306, based on bug351 tester within intrepid/test18.upc
   But modified because our bug is different.

   Bug is that sizeof(A[0]) is translated equivalent to (THREADS * sizeof(int))
   Note that the problem only exists in a Dynamic threads environment.
*/

#include <upc.h>
#include <stdio.h>

shared int A[THREADS];

int main(void) {
  if (!MYTHREAD) { 
    int got = (int) sizeof (A[0]);
    if (got != sizeof(int))
      fprintf (stderr, "Error: expected: %d, got: %d\n", (int) sizeof(int), got);
    else
      puts ("Done.");
  }
  upc_barrier;
  return 0;
}


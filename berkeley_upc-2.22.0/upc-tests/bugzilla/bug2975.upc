#include <upc.h>
#include <stdio.h>
#include <stdlib.h>


#if __UPC_STATIC_THREADS__
/* The prior definition of A is required, to cause
   the mis-definition of B.  */
shared            int A[THREADS][THREADS];
shared [THREADS]  int B[THREADS][THREADS];
#endif

int main()
{
#if __UPC_STATIC_THREADS__
  int test_ok = 1;
  if (MYTHREAD == 0)
    {
      if (upc_blocksizeof(A) != 1)
	{
	  fprintf (stderr, "Error: block size of A = %lu, expected: %lu\n",
		  (unsigned long)upc_blocksizeof(A),
		  (unsigned long)1);
	  test_ok = 0;
	}
      if (upc_blocksizeof(B) != THREADS)
	{
	  fprintf (stderr, "Error: block size of B = %lu, expected: %lu\n",
		  (unsigned long)upc_blocksizeof(B),
		  (unsigned long)THREADS);
	  test_ok = 0;
	}
    }
  upc_barrier;
  if (MYTHREAD == 0)
    {
      if (test_ok)
        printf ("Test passed.\n");
      else  
        {
          fprintf (stderr, "Test failed.\n");
          upc_global_exit (2); 
	}
    }
#else
  if (MYTHREAD == 0)
    printf ("This test is not applicable"
            " in a dynamic threads environment.\n");
#endif
  return 0;
}

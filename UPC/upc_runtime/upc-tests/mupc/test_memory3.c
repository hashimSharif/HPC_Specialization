/* _test_memory3.c: test the correctness of upc_local_alloc.

        Date created    : October 1, 2002
        Date modified   : November 4, 2002

        Function tested: upc_local_alloc
        
        Description:
	- Tests the correctness of upc_local_alloc(). 
	- Test case first allocates THREAD number of array a dynamically using upc_local_alloc(),
          then thread 0's array is initialized.
	- Thread i then fills up the values in its array with values from thread (i - 1). 
	- After all the arrays have been filled, thread 0 perform the necessary error checking.
 
        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    2, 4            October 1, 2002         Yes
	UPC0 (all types)	4		October 29, 2002	Yes
	UPC0 (all types) 	4		November 5, 2002	Yes
	CSE0 (all types)	2,4,8,16	November 11, 2002	No
	LION (all types)	2,4,8,16,32	November 22, 2002	No
	UPC0 (all types)	2		December 3, 2002	Yes

        Bugs Found:
	[11/11/2002] Test case fails for all type. The wrong value is stored in all threads,
		     except the last.
	[11/22/2002] On lionel, test case fails for DTYPE=all, n=2,4,8,16,32, S=16.
		MPI process rank 0 (n0, p5121) caught a SIGSEGV in MPI_Test.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE DATA
#define SIZE 16000

shared [] DTYPE * shared a[THREADS];

int main ()
{
	int i, j, error=0;
	
	/* Perform initialization of variable and allocate array */	
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
	a[MYTHREAD] = upc_alloc(SIZE * sizeof(DTYPE));
#else   
	a[MYTHREAD] = upc_local_alloc(SIZE, sizeof(DTYPE));
#endif

	/* Initialize thread 0's array */
	if (MYTHREAD == 0)
		for (i = 0; i < SIZE; i++)
			a[MYTHREAD][i] = (DTYPE)((DTYPE)(i) + (DTYPE)(10));

	upc_barrier;

	/* Copies thread (i - 1)'s array values from thread i's array. */
	for (i = 1; i < THREADS; i++) {
			
		if (MYTHREAD == i) 
			for (j = 0; j < SIZE; j++) 
				a[i][j] = a[i-1][j] + (DTYPE)(1);

		upc_barrier;
	}

	/* Error checking */
	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++) 
			for (j = 0; j < SIZE; j++) {
#ifdef VERBOSE0
				printf("[thread %d] a[%d][%d] = %d\n", i, i, j, a[i][j]);
#endif
				if (a[i][j] != (DTYPE)((DTYPE)(10)+(DTYPE)(i)+(DTYPE)(j)))
					error = 1;
			}
		
		if (error)
			printf("Error: test_memory3.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_memory3.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
}	

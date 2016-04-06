/* _test_int_barlocks.c: integrates memory alloc., locking, and split-barrier functions.

        Date created    : October 2, 2002
        Date modified   : November 4, 2002

        Function tested: upc_all_lock_alloc, upc_global_alloc, upc_memset, upc_lock_init,
			 upc_lock, upc_unlock, upc_notify, upc_wait

        Description:
	- Integrates memory allocation functions with upc_notify, upc_wait, and locking
	  functions. 
	- Test case first perform necessary memory and lock allocations; and initialization.
	- All threads perform initialization of a[MYTHREAD] in between the 1st split-barrier.
	- All threads perform error checking on array a[MYTHREAD+1] in the 2nd split-barrier 
	  to make sure that synchronization occurred in the previous split-barrier.
	- Each thread takes turn to enter a critical region where each thread accumulates
	  the value of a[MYTHREAD] in the array acc. 
	- Thread 0 performs error checking at end.

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    2-10  		October 1, 2002         Yes
	UPC0			2, 4, 8		October 7, 2002		Yes
	UPC0 (all - D)		4		October 30, 2002	Partial	
	UPC0 (all - D)		4		November 5, 2002	Partial
	CSE0 (all - D)		2,4,8,16	November 9, 2002	Partial
	CSE0 (all types)	2,4,8,12	November 16, 2002	Yes
	LION (all types)	2,4,8,16,32	November 19, 2002	No
	UPC0 (all types)	2		December 3, 2002	Yes
	
        Bugs Found:
[FIXED]	[10/30/2002] Test case fails for DTYPE=double, SIZE=16. No error message was
		     produced, test case just hangs. Bug reported to programmer.
[FIXED]	[11/05/2002] Same as above.
[FIXED]	[11/09/2002] On CSEO, test case failed for DTYPE=double, SIZE=16. No error 
		     message was produced, test case just hangs.
	[11/19/2002] On lionel, test case failed for DTYPE=all, n=2,4,8,16,32, S=16.
		MPI process rank 0 (n0, p29569) caught a SIGSEGV.
*/

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

//#define VERBOSE0
#define DTYPE DATA 
#define SIZE 16000

shared DTYPE * shared a[THREADS];
shared DTYPE *acc;
upc_lock_t *lock_1;

shared int err[THREADS];

int main (void)
{
	int i, error=0;
	DTYPE compare = 0; 

	/* Perform necessary initialization */
	if (MYTHREAD == 0) error = 0; 				/* Initialize error var */
	a[MYTHREAD] = upc_global_alloc(SIZE, sizeof(DTYPE));	/* Allocate memory */
	lock_1 = upc_all_lock_alloc();				/* Allocate locks collectively */
#if 0
	upc_lock_init(lock_1);					/* Initialize locks */
#endif
	acc = upc_all_alloc(SIZE, sizeof(DTYPE));		/* Allocate memory for accumulator */
	
	upc_forall (i = 0; i < SIZE; i++; &acc[i]) {	 	/* Initialize array acc */
		acc[i] = (DTYPE)(0);
	}
	upc_barrier 1;

	upc_notify 1;
	/* Each thread initializes the array a[MYTHREAD] */
	for (i = 0; i < SIZE; i++)
		a[MYTHREAD][i] = (DTYPE)(MYTHREAD);
	upc_wait 1;

        upc_barrier; /* DOB: program has a race condition without this barrier */

	upc_notify 2;
	/* Check for if writes of shared data has been completed and that synchronization
	   between threads occurred */
	for (i = 0; i < SIZE; i++)
		if (a[(MYTHREAD+1)%THREADS][i] != (DTYPE)((MYTHREAD+1)%THREADS))
			err[MYTHREAD] = 1;

	/* Critical region: Accumulate the values */ 
	upc_lock(lock_1);
	for(i = 0; i < SIZE; i++)
		acc[i] += a[MYTHREAD][i];
	upc_unlock(lock_1);
	upc_wait 2;

	upc_barrier 2;

	/* Error checking */
	if (MYTHREAD == 0) {
		
		for (i = 0; i < THREADS; i++) {
			compare += (DTYPE)(i);
		}

		for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
			printf("acc[%d] = %d\n", i, acc[i]);
#endif
			if (acc[i] != compare)
				error = 1;
		}

		for (i = 0; i < THREADS; i++)
			error += err[i];
	
		if (error)
			printf("Error: test_int_barlocks.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_int_barlocks.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}
		
	return (error);
} 


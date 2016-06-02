/* _test_int_multilocks.c: test multiple locks and multiple memory allocations.

        Date created    : October 3, 2002
        Date modified   : November 4, 2002

        Function tested: upc_all_alloc, upc_memset, up_all_lock_alloc, upc_lock_init, upc_lock, upc_unlock

        Description:
	- Test the robustness of MuPC's locking mechansism. Most test cases only make use  
	  of single lock. We attempt to use multiple locks in this test case, nesting them, 
	  while updating 3 shared arrays in the critical regions. 
	- First allocate memory for 3 shared arrays, a[0], a[1], and a[2], and initialize them.
	- Allocate 3 locks and initialize them.
	- Create 3 critical regions protected by the 3 locks. These critical regions overlap
	  each other causing the 3 locks to be nested inside one another.
	- Perform error checking at end. 

        Platform Tested         No. Proc        Date Tested             Success
        UPC0			4		October 3, 2002		No
	UPC0                    2, 4, 8         October 8, 2002         Yes
	UPC0 (all types)	4		October 30, 2002	Yes
	CSE0 (all types)	2,4,8,16	November 10, 2002	Yes
	LION (all types)	2,4,8,16,32	November 18, 2002	Yes
	UPC0 (all types)	2,16K		December 3, 2002	Yes

        Bugs Found:
[FIXED]	[10/3/2002] Error when n = 4, but ran fine when n = 2. The following error message was
		    produced. This error message signals that a segmentation fault has occurred.
		MPI process rank 0 (n0, p3219) caught a SIGSEGV.

	Notes:	
	[10/3/2002] Bug reported to programmer. Problem might lie with upc_lock_init and 
		    upc_memset functions.
	[10/7/2002] Bug fixed. Seems like there are at least 2 problems. 
		    1st: upc_all_lock_alloc, 2nd: upc_all_alloc.
*/

#include <upc.h>
#include <unistd.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE DATA 
#define SIZE 16000

shared DTYPE *acc[3];
upc_lock_t *lock_1, *lock_2, *lock_3;

int main (void) 
{
	int i, j, error=0;

	/* Allocate memory for 3 shared arrays and initialize them */	
	for (i = 0; i < 3; i++) {
		acc[i] = upc_all_alloc(SIZE, sizeof(DTYPE));
		for (j = 0; j < SIZE; j++)
			acc[i][j] = (DTYPE)(0);
	}
	
	/* Allocate locks and initialize them */
	lock_1 = upc_all_lock_alloc();
	lock_2 = upc_all_lock_alloc();
	lock_3 = upc_all_lock_alloc();
#if 0
	upc_lock_init(lock_1);
	upc_lock_init(lock_2);
	upc_lock_init(lock_3);
#endif

	upc_barrier;

	/* Multiple critical regions secured by multiple locks */
#if defined(__xlC__) && defined(__PPC64__)
        /* bug work-around: sleep() never waking! */
	usleep(1000000*(THREADS - MYTHREAD));
#else
	sleep(THREADS - MYTHREAD);
#endif
	upc_lock(lock_1);

	for(i = 0; i < SIZE; i++)
		acc[0][i] += (DTYPE)(1);

	upc_lock(lock_2);
	
	for(i = 0; i < SIZE; i++)
		acc[1][i] += (DTYPE)(1);

	upc_unlock(lock_1);
	
	upc_lock(lock_3);

	for(i = 0; i < SIZE; i++)
		acc[2][i] += (DTYPE)(1);

	upc_unlock(lock_2);

	upc_unlock(lock_3);

	upc_barrier;

        if (MYTHREAD == 0) upc_lock_free(lock_1);
        if (MYTHREAD == 0) upc_lock_free(lock_2);
        if (MYTHREAD == THREADS-1) upc_lock_free(lock_3);

	/* Perform error checking */
	if (MYTHREAD == 0) {
		for (i = 0; i < 3; i++) 
			for (j = 0; j < SIZE; j++) {
				
				if (acc[i][j] != (DTYPE)(THREADS))
					error = 1;
#ifdef VERBOSE0
			printf("acc[%d][%d] = %d\n", i, j, acc[i][j]);
#endif
			}

		if (error)
			printf("Error: test_int_multilocks.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_int_multilocks.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}
	
	return (error);				
}

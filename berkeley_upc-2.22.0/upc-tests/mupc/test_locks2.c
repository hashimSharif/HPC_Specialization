/* _test_locks2.c: test of upc_global_lock_alloc and other locking mechanisms.

        Date created    : September 16, 2002
        Date modified   : November 4, 2002

	Function tested: upc_global_lock_alloc, upc_lock_init, upc_lock, upc_unlock

        Description:
	- Tests the correctness of upc_global_alloc. Also test if upc_lock_init, upc_lock,
	  and upc_unlock works.
        - Allocate locks using global_lock_alloc, and perform all necessary initialization.
	- Use the two locks allocated to protect 2 critical regions.
	- Perform error checking at end.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0			2, 4		September 16, 2002	Yes
	UPC0			4		September 17, 2002	Yes
	UPC0			4		October 10, 2002	Yes
	UPC0 (all types)	4		October 29, 2002	Yes
	UPC0 (all types)	4		November 5, 2002	Yes
	CSE0 (all - D)		2,4,8,16	November 11, 2002	Partial	
	CSE0 (double)		2,4,8,12,16	November 16, 2002	Yes
	LION (all types)	2,4,8,16,32	November 19, 2002	No
	UPC0 (all types)	2		December 3, 2002	Yes
	
	Bugs Found:
[FIXED]	[11/11/2002] Test case failed for DTYPE=double, n=16. Test case PASSES for 
		     DTYPE=double, n=2,4,8.
	[11/19/2002] On lionel, test case failed for DTYPE=all, n=2,4,8,16,32, C=10.
		MPI process rank 0 (n0, p31749) caught a SIGSEGV.
	
	Notes: 1) Regarding the priority of locks - understandable why thread 0 obtain locks
                  faster than others; locks are local to thread 0. However, can't explain 
                  why thread 1 gets more priority when locking compared to thread 2 and 3.
*/

#include <upc.h>
#include <unistd.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define COUNT 1000

upc_lock_t* shared lock_1;
upc_lock_t* shared lock_2;
shared DTYPE zeroCounter;
shared DTYPE counter;
shared int arrayCount;
shared int critical[COUNT*THREADS];

int main (void) 
{
	int i, j, error=0;

	/* Perform necessary initialization */
	if (MYTHREAD == 0) {
		lock_1 = upc_global_lock_alloc();
		lock_2 = upc_global_lock_alloc();
#if 0
		upc_lock_init(lock_1);
		upc_lock_init(lock_2);
#endif
		zeroCounter = (DTYPE)(0);
		arrayCount = 0;
		counter = (DTYPE)(0);
	}

	upc_barrier 1;
	
#if defined(__xlC__) && defined(__PPC64__)
        /* bug work-around: sleep() never waking! */
	usleep(1000000*(THREADS - MYTHREAD));
#else
	sleep(THREADS - MYTHREAD);
#endif

	/* 1st Critical region protected by lock */
	for (i = 0; i < COUNT; i++) {
		upc_lock(lock_1);
		zeroCounter += (DTYPE)(10);
		zeroCounter -= (DTYPE)(10);
		critical[arrayCount++] = MYTHREAD;
		upc_unlock(lock_1);
	}

	/* 2nd critical region protected by lock */
	for (i = 0; i < COUNT; i++) { 
		upc_lock(lock_2);
		counter += (DTYPE)(1);
		upc_unlock(lock_2);
	}

	upc_barrier 2;

	/* Error checking by thread 0 */
	if (MYTHREAD == 0) {
#ifdef VERBOSE0
		printf("zeroCounter = %d\n", zeroCounter);
		printf("counter = %d\n", counter);
#endif	
		if ((zeroCounter == 0) && (counter == (COUNT * THREADS * (DTYPE)(1))))
			error = 0;
		else 
			error = 1;
		
		/* Check that all threads was in critical region COUNT times. */
		for (i = 0; i < THREADS; i++) {
			arrayCount = 0;	
			for (j = 0; j < COUNT * THREADS; j++) {
				if (critical[j] == i)
					++arrayCount;
			} 
			if (arrayCount != COUNT) { 
				error = 1;
				break;	
			}
		}

		if (error) 
			printf("Error: test_locks2.c failed! [th=%d, error=%d, DATA]\n",
				THREADS, error);
		else
			printf("Success: test_locks2.c passed! [th=%d, error=%d, DATA]\n",
				THREADS, error);
	}

	return (error);
}
			
	

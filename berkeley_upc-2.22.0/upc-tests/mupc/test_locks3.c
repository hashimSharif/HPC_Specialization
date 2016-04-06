/* _test_locks3.c: test the use of lock_attempt, and other locking mechanism.

	Date created    : September 25, 2002
        Date modified   : November 4, 2002

	Function tested: upc_all_lock_alloc, upc_lock_init, upc_lock_attempt, upc_unlock

        Description:
	- Test the correctness of the upc_lock_attempt() function.
	- First allocate lock, and perform necessary initializations.
	- Lock critical region using upc_lock_attempt.
	- Perform accumulation in critical region.
	- Thread 0 performs error checking.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0			2, 4		September 25, 2002	Yes
	UPC0			8		September 26, 2002	No
       	UPC0 (all types)	4		October 29, 2002	Yes
	UPC0 (all types)	4		November 5, 2002	Yes
	CSE0 (all types)	2,4		November 11, 2002	Yes
	CSE0 (all types)	8,16		November 11, 2002	No
	LION (all types)	2,4,8		November 19, 2002	Yes
 	LION (all types)	16,32		November 19, 2002	No
	UPC0 (all types)	2		December 3, 2002	Yes

	Bugs Found:
	[9/26/2002] When n = 8, the program just hangs. When printfs were added to the
		    internal RTS, it's discovered that threads > 0 failed to 
		    obtain lock. Either thread 0 failed to relinquish lock, or
		    the other thread failed to obtain lock.
	[11/11/2002] On cse0, for n>=8, program loops inifinitely too.
	[11/19/2002] On lionel, for n>=16, program loops infinitely.
*/


#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE DATA
#define SIZE (THREADS*4000)

shared int counter[THREADS];
shared DTYPE a[SIZE];
upc_lock_t *lock_1;

int main (void) 
{
	int i, error=0;
	counter[MYTHREAD] = 0;

	/* Allocate lock using collective function, then initialize it */
	lock_1 = upc_all_lock_alloc();
#if 0
	upc_lock_init(lock_1);
#endif

	upc_forall(i = 0; i < SIZE; i++; i)
		a[i] = (DTYPE)(0);

	upc_barrier;

	/* Try to get lock_1 using upc_lock_attempt */	
	while (!upc_lock_attempt(lock_1))
		counter[MYTHREAD] += 1;

	/* Update content of array a */	
	for (i = 0; i < SIZE; i++) 
		a[i] += (DTYPE)(1);		
	
	upc_unlock(lock_1);

	upc_barrier;

#ifdef VERBOSE0
	printf("[thread %d] counter[%d] = %d\n", MYTHREAD, MYTHREAD, counter[MYTHREAD]);
#endif

	/* Perform error checking */
	if(MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++) {
			if (a[i] != (DTYPE)(THREADS))
				error = 1;
#ifdef VERBOSE0
			printf("a[%d] = %d\n", i, a[i]);
#endif
		}
		
		if (error)
			printf("Error: test_locks3.c failed! [th=%d,  error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_locks3.c passed! [th=%d,  error=%d, DATA]\n", THREADS, error);
	}
	
	return (error);
}


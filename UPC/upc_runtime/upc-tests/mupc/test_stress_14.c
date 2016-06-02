/* _test_stress_14.c: stress test of upc_lock and upc_unlock.

	Date created: October 16, 2002
	Date modified: November 4, 2002

	Function tested: upc_lock, upc_unlock, upc_all_lock_alloc, upc_lock_init.

	Description:
	- Stress test upc_lock and upc_unlock by calling the functions numerous times. 
	  The number of times can be changed by modifying the constant CONST.
	- A lock, lock_1, is first allocated collectively.
	- A critical region protected by lock_1 is executed CONST number of times.
	- Perform error checking at end.

	Platform Tested         No. Proc        Date Tested             Success
	UPC0 (all types)	4		October 28, 2002	Yes
	UPC0 (all types)	4		November 6, 2002	Yes
	CSE0 (all types)	2,4,8,16	November 15, 2002	Yes
	LION (all types)	2,4,8,16,32	November 18, 2002	Yes
	UPC0 (all types)	2,10K		December 3, 2002	Yes
	
	Bugs Found:
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE DATA 
#define CONST 10240
#define LOOP 1000

upc_lock_t *lock_1;
shared DTYPE counter;

int main (void)
{
	int i, error=0;
	
	/* Initialize variables */		
	if (MYTHREAD == 0) {
		counter = (DTYPE)(0);
	}
	
	/* Allocate lock collectively */
	lock_1 = upc_all_lock_alloc();
#if 0
	upc_lock_init(lock_1);
#endif
	upc_barrier;

	/* Execute critical region for CONST number of times */
	for (i = 0; i < CONST; i++) {	
		upc_lock (lock_1);
		counter = (DTYPE)(counter + (DTYPE)(1));
		counter = (DTYPE)(counter - (DTYPE)(1));
		upc_unlock(lock_1);
	}

	upc_barrier;

	/* Error checking */	
	if (MYTHREAD == 0) {
#ifdef VERBOSE0
		printf("counter = %d\n", counter);
#endif	
		if (counter != (DTYPE)(0))
			error = 1;
	
		if (error)
			printf("Error: test_stress_14.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_14.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
}


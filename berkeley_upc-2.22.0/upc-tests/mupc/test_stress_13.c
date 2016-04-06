/* _test_stress_13.c: stress test of upc_all_lock_alloc, upc_lock_init.

	Date created: October 15, 2002
	Date modified: November 4, 2002

	Function tested: upc_all_lock_alloc, upc_lock_init, upc_lock, upc_unlock.

	Description:
	- Stress test upc_all_lock_alloc by calling the function numerous times. 
	  The number of times called is limited by the 8MB of memory pool allocated for 
	  each thread. 
	- Since a lock has to be initialized in MuPC in order to be used,
	  this also stress test upc_lock_init.
	- Each thread collectively allocates CONST number of locks using upc_all_lock_alloc.
	- One of the locks in then used to determine if all threads received the valid pointer.
	- Error checking is performed at end by thread 0. 

	Platform Tested         No. Proc        Date Tested             Success
	UPC0			2,4		October 17, 2002	Yes	
	UPC0 (all types)	4		October 28, 2002	Yes
	UPC0 (all types)	4		November 6, 2002	Yes
	CSE0 (all types)	2,4,8,12	November 15, 2002	Yes
	LION (all types)	2,4,8,16,32	November 18, 2002	Yes
	UPC0 (all types)	2		December 3, 2002	Yes
	
	Bugs Found:

	Note:
*/

#include <upc.h>
#include <stdio.h>
#include <string.h>

//#define VERBOSE0
#define DTYPE DATA
#define CONST 10240
#define LOOP 100

upc_lock_t *lock_1[CONST];
shared DTYPE counter;

int main (void)
{
	int i, error=0;
		
	if (MYTHREAD == 0) {
		counter = (DTYPE)0;
	}

	/* Allocates CONST number of locks and then initialize them */
	for (i = 0; i < CONST; i++) {
		lock_1[i] = upc_all_lock_alloc();
#if 0
		upc_lock_init(lock_1[i]);
#endif
	}

	upc_barrier;

	for (i = 0; i < LOOP; i++) {	
		upc_lock (lock_1[0]);
		counter = (DTYPE)(counter + (DTYPE)(1));
		counter = (DTYPE)(counter - (DTYPE)(1));
		upc_unlock(lock_1[0]);
	}

	upc_barrier;
	
	if (MYTHREAD == 0) {
#ifdef VERBOSE0
		printf("counter = %d\n", counter);
#endif	
		if (counter != (DTYPE)(0))
			error = 1;
	
		if (error)
			printf("Error: test_stress_13.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_13.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
}


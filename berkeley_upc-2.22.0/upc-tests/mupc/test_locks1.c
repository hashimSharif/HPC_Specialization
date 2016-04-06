/* _test_locks1.c: test the use of upc_all_lock_alloc and other locking mechanisms.

        Date created    : September 13, 2002
        Date modified   : October 29, 2002
	
	Function tested: upc_all_lock_alloc, upc_lock_init, upc_lock, upc_unlock

        Description:
	- Allocate locks using the colelctive upc_all_lock_alloc function.
	- Use allocated locks to protect a critical region.
	- Perform error checking at end.

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    2		September 13		No
	UPC0			4		September 16		Yes
	UPC0			1-8		October 10		Yes
	UPC0 (all types)	4		October 29, 2002	Yes
	UPC0 (all types)	4		November 5, 2002	Yes
	CSE0 (all types)	2,4,8,16	November 10, 2002	Yes
	LION (all types)	2,4,8,16,32	November 19, 2002	Yes
	UPC0 (all types)	2,2K		December 3, 2002	Yes

        Bugs Found:
FIXED	[9/13/2002] MPI process rank 0 (n0, p30784) caught a SIGSEGV.
		    MPI_Irecv: internal MPI error (rank 0, MPI_COMM_WORLD)
	
	Note: 
	[9/13/2002] Failed on MuPC, but passed on Compaq's RTS. 
	[9/15/2002] Cause of error in all_lock_alloc() very probable.
		    Bug reported to programmer.
	[9/16/2002] Bug corrected by programmer. Notice that in the MuPC RTS,
		    locks allocated using upc_global_lock_alloc() and 
		    upc_all_lock_alloc() needs to be initialized explicitly 
		    using upc_lock_init.
*/

 
#include <upc.h>
#include <stdio.h>
#include <time.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define COUNT 2000

upc_lock_t *lock1;
shared DTYPE counter;

int main (void)
{
	int i, error=0;

	lock1 = upc_all_lock_alloc(); /* Allocate lock using collective method */
#if 0
	upc_lock_init(lock1); /* Initialize lock */ 
#endif
	upc_barrier;
	
	if (MYTHREAD == 0) {
		upc_lock(lock1);
		counter = (DTYPE)(0);
		upc_unlock(lock1);
	}

	upc_barrier;

	/* Use lock to protect critical region */
	for (i = 0; i < COUNT; i++) {
		upc_lock(lock1);
		counter += (DTYPE)(1);
		counter -= (DTYPE)(1);
		upc_unlock(lock1);
	}

	upc_barrier;

#ifdef VERBOSE0
	printf("[thread %d] Final counter value = %d\n", MYTHREAD, counter);
#endif 
	upc_barrier(999);
	
	if (MYTHREAD == 0) {
		if (counter != (DTYPE)(0)) {
			error = 1;
			printf("Error: test_locks1.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		}
                else {
			error = 0;
                        printf("Success: test_locks1.c passed! [th=%d, error=%d , DATA]\n", THREADS, error);
		}
	}

	return (error);
}

	

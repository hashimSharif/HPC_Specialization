/* _test_int_memlocks.c: integration test of locking, mem. alloc, and mem. xfer funcs.

        Date created    : October 8, 2002
        Date modified   : November 4, 2002

        Function tested: upc_local_alloc, upc_global_alloc, upc_all_lock_alloc, upc_lock_init,
			 upc_lock, upc_unlock, upc_memset, upc_memget, upc_memput, upc_memcpy.

        Description:
	- Test the interaction of the locking, memory allocation, and memory transfer functions. 
	- In this test case, each thread will take turns to enter a critical region where it will
	  perform memory transfer operations from one array to another.
	- First, memory and lock is allocated, and initialized.
	- Each thread enters the critical region, and perform copying of blocks of data from
	  one array to another.
	- Thread 0 performs error checking at end.

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    2,4,7,8,16      October 8, 2002         Yes
	UPC0 (all types)	4		October 30, 2002	Yes
	UPC0 (all types)	4		November 5, 2002	Yes
	CSE0 (all - D,L)	2,4,8,12	November 10, 2002	Partial	
	CSE0 (all - L)		2,4,8,12	November 16, 2002	Partial
	LION (all types)	2,4,8,16,32	November 19, 2002	No
	UPC0 (all types)	2		December 3, 2002	Yes

        Bugs Found: 
[FIXED]	[11/10/2002] test case failed for DTYPE=double, n=8
		MPI process rank 0 (n0, p26683) caught a SIGFPE in MPI_Irecv.
	[11/10/2002] test case failed for DTYPE=long, n=2,4,8,12, S=T*12
	[11/19/2002] On lionel, test case failed for DTYPE=all, n=2,4,8,16,32, S=12.
		MPI process rank 0 (n0, p29902) caught a SIGSEGV.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE DATA 
#define SIZE 3200

shared DTYPE * shared master;
shared [] DTYPE * shared secondary;
upc_lock_t *lock_1;
DTYPE local[SIZE];

int main (void)
{
	int i, error=0;

	/* Perform memory and lock allocation */
	lock_1 = upc_all_lock_alloc();
#if 0
	upc_lock_init(lock_1);
#endif
	if (MYTHREAD == 0) {
		master = upc_global_alloc(SIZE, sizeof(DTYPE));
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
		secondary = upc_alloc(SIZE * sizeof(DTYPE));
#else   
		secondary = upc_local_alloc(SIZE, sizeof(DTYPE));
#endif
	}

	upc_barrier;

	/* Initialize contents of master and secondary array */
	upc_memset(secondary, 0, SIZE * sizeof(DTYPE));
	for (i = 0; i < SIZE; i++) 
		upc_memset(master+i, 0, sizeof(DTYPE));

	upc_barrier;

#ifdef VERBOSE0
	if (MYTHREAD == 0) 
		for (i = 0; i < SIZE; i++) 
			printf("master[%d] = %d, secondary[%d] = %d\n", 
				i, master[i], i, secondary[i]);
	upc_barrier;
#endif
	/* Critical region where memory transfers take place */
	upc_lock(lock_1);

	for (i = 0; i < SIZE; i++)
		upc_memget(local+i, master+i, sizeof(DTYPE));

	for (i = 0; i < SIZE; i++)
		local[i] += (DTYPE)(1);
	
	for (i = 0; i < SIZE; i++) 
		upc_memput(master+i, local+i, sizeof(DTYPE));

	for (i = 0; i < SIZE; i++)
		upc_memcpy(secondary+i, master+i, sizeof(DTYPE));
	
	upc_unlock(lock_1);

	upc_barrier;

	/* Error checking */
	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
			printf("master[%d] = %d, secondary[%d] = %d\n", i, master[i], i, secondary[i]);
#endif	
			if (master[i] != (DTYPE)(THREADS))
				error = 1;
	
			if (secondary[i] != (DTYPE)(THREADS))
				error = 1;
		}
		
		if (error)
			printf("Error: test_int_memlocks.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_int_memlocks.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);

	}

	return (error);
}

/* _test_stress_08.c: stress test of upc_memset.

	Date created  : October 15, 2002
	Date modified : November 4, 2002

	Function tested: upc_local_alloc, upc_memset.

	Description:
	- Stress test upc_memset function and the internal buffering system by calling
	  upc_memset many times, with as little synchronization in between calls.
	- Each thread allocates a shared array "dst[MYTHREAD]".
	- Each thread initializes its own shared array using upc_memset CONST number times.
	- Each thread performs error checking. Final values in dst[MYTHREAD] should be 0.
	- Thread 0 determines the success of test case. 

	Platform Tested         No. Proc        Date Tested             Success
	UPC0 (all types)	4		October 28, 2002	Yes	
	UPC0 (all types)	4		November 6, 2002	Yes
	CSE0 (all types)	2,4,8,12	November 13, 2002	No
	LION (all types)	2,4,8,16,32	November 18, 2002	No
	UPC0 (all types)	2		December 3, 2002	Yes
	
	Bugs Found:
	[11/14/2002] Test case fails for all DTYPE, n=2,4,8,12, S=1024, C=100. Bug reported
		     to programmer.
	[11/18/2002] On lionel, test case fails for all DTYPE, n=2,4,8,16,32, S=1024.
		MPI process rank 0 (n0, p23797) caught a SIGSEGV.
*/

#include "upc.h"
#include <stdio.h>
#include <string.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define SIZE 10240
#define CONST 100

shared [] DTYPE * shared dst[THREADS];
shared int err[THREADS];

int main (void)
{
	int i, error=0;
	err[MYTHREAD] = 0;
		
	/* Each thread allocates shared memory with affinity to it */ 
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
	dst[MYTHREAD] = upc_alloc(SIZE * sizeof(DTYPE));
#else   
	dst[MYTHREAD] = upc_local_alloc(SIZE, sizeof(DTYPE));
#endif

	/* Each thread perfrom CONST times of upc_memset */	
	for (i = (CONST-1); i >= 0; i--) 
		upc_memset(dst[MYTHREAD], i, SIZE * sizeof(DTYPE));

	for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
		printf("dst[%d][%d] = %f\n", MYTHREAD, i, dst[MYTHREAD][i]);
#endif
		if (dst[MYTHREAD][i] != (DTYPE)(0))
			err[MYTHREAD] = 1;
	}

	upc_barrier;

	/* Error checking */	
	if (MYTHREAD == 0) {
		
		for (i = 0; i < THREADS; i++) 
			error += err[i]; 

		if (error)
			printf("Error: test_stress_08.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_08.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
}


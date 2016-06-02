/* _test_stress_06.c: stress test of upc_memcpy. 

	Date created: October 15, 2002
	Date modified: November 4, 2002

	Function tested: upc_local_alloc, upc_memcpy, upc_memset.

	Description:
	- Stress test upc_memcpy function and the internal buffering system by calling
	  upc_memcpy many times, with as little synchronization in between calls.
	- Thread 0 allocates and initialize destination array with non-zero values.
	- Each thread allocates shared array src[MYTHREAD] with affinity to it.
	- Each thread copies the content of its array CONST number of times to the
	  shared dst array. In every iteration, each thread would do a upc_memset
	  to src[MYTHREAD] to change the values of the array.
	- Thread 0 performs error checking at end. All values in dst should be 0 at
	  this point.

	Platform Tested         No. Proc        Date Tested             Success
	UPC0			2,4		October 15, 2002	Yes
	UPC0			4		November 6, 2002	Yes
	CSE0 (all - L)		2,4,8,12	November 14, 2002	Partial
	LION (all types)	2,4,8,16,32	November 18, 2002	No
	UPC0 (all types)	2		December 3, 2002	Yes
	
	Bugs Found:
[FIXED]	[10/28/2002] Test case failed when DTYPE=double, SIZE=128, n=4. Error
		     message is as follows.
		MPI process rank 0 (n0, p30083) caught a SIGFPE in MPI_Test.

	[11/14/2002] Test case failed for DTYPE=long, n=12, S=128.

	[11/06/2002] Test case failed. Failing conditions are the same as above.

	[11/18/2002] On lionel, test case failed for all DTYPE, all n, S=128.
		MPI process rank 0 (n0, p23408) caught a SIGSEGV.
*/

#include <upc.h>
#include <stdio.h>
#include <string.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define SIZE 5000 
#define CONST 1024 

shared [] DTYPE * shared dst;
shared [] DTYPE * shared src[THREADS];

int main (void)
{
	int i, error=0;
	
	if (MYTHREAD == 0) { /* Allocate and initialize source array */
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
		dst = upc_alloc(SIZE * sizeof(DTYPE));
#else   
		dst = upc_local_alloc(SIZE, sizeof(DTYPE));
#endif
		upc_memset(dst, 1, SIZE * sizeof(DTYPE));
	}
	
	upc_barrier;

	/* Each thread allocates shared memory with affinity to it */ 
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
	src[MYTHREAD] = upc_alloc(SIZE * sizeof(DTYPE));
#else   
	src[MYTHREAD] = upc_local_alloc(SIZE, sizeof(DTYPE));
#endif

	/* Each thread copies the content of its own array src[MYTHREAD]
	   to dst for CONST number of times. */ 
	for(i = (CONST-1); i >= 0; i--) {
		upc_memset(src[MYTHREAD], i, SIZE * sizeof(DTYPE));
		upc_memcpy(dst, src[MYTHREAD], SIZE * sizeof(DTYPE));
	}

	upc_barrier;

	/* Error checking */	
	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
			printf("dst[%d] = %d\n", i, dst[i]);
#endif
			if (dst[i] != (DTYPE)(0)) 
				error = 1;	
		}

		if (error)
			printf("Error: test_stress_06.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_06.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
}


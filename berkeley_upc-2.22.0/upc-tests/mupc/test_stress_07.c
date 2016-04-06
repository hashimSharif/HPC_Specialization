/* _test_stress_07.c: alternative stress test of upc_memcpy. 

	Date created: October 9, 2002
	Date modified: November 4, 2002

	Function tested: upc_local_alloc, upc_memcpy, upc_memset.

	Description:
	- Stress test upc_memcpy function and the internal buffering system, by copying
	  large amount of memory. The stress here is not on the number times, but the
	  amount of data copied.
	- Thread 0 allocates a shared array "src" and sets the whole array to 0.
	- Each thread allocates shared array dst[MYTHREAD] with affinity to itself. Also,
	  each shared array is initialized using upc_memset non-zero values.
	- Each thread copies content of "src" to "dst[MYTHREAD]" concurrently. After
	  the upc_memcpy, each dst[MYTHREAD] should contain 0 values.
	- Each thread performs error checking and sends results to thread 0. Thread 0
	  decides if test case passes or fails.

	Platform Tested         No. Proc        Date Tested             Success
	UPC0 (SIZE=1K)		2,4		October 14, 2002	Yes
	UPC0 (SIZE=10K)		2,4		October 14, 2002	No
	UPC0 (SIZE=1K)		4		October 28, 2002	No
	UPC0 (SIZE=1K) (a-D)	4		November 6, 2002	Partial
	CSE0 (all types)	2,4,8,12	November 14, 2002	No
	LION (all types)	2,4,8,16,32	November 18, 2002	No
	UPC0 (all types)	2,4		November 25, 2002	Yes
	UPC0 (all types)	2		December 3, 2002	Yes

	Bugs Found:
[FIXED]	[10/15/2002] It seems that other than thread 0, the other threads did not get the
		     proper value from the upc_memcpy operation. 
		Error: test_1_7.c failed! [th=2, error=1]

[FIXED]	[10/28/2002] Test case fails for DTYPE=double, SIZE=1024, n=4. Error message:
		MPI process rank 0 (n0, p30587) caught a SIGFPE in MPI_Test.

[FIXED]	[11/06/2002] Same as [10/28/2002].

	[11/14/2002] Test case fails for DTYPE=all, n=2,4,8,12, S=1024 
	
	[11/18/2002] On lionel, test case failed for DTYPE=all, n=2,4,8,16,32, S=1024.	
		MPI process rank 0 (n0, p23656) caught a SIGSEGV.
	
	Notes:
	[10/15/2002] This test case worked when SIZE is 1024. However, it failed when SIZE
		     was increased to 10240. 
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define SIZE 502400

shared [] DTYPE * shared src;
shared [] DTYPE * shared dst[THREADS];
shared int err[THREADS];

int main (void)
{
	int i, j, error=0;
 	err[MYTHREAD] = 0;
	
	if (MYTHREAD == 0) { /* Allocate and initialize source array */
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
		src = upc_alloc(SIZE * sizeof(DTYPE));
#else
		src = upc_local_alloc(SIZE, sizeof(DTYPE));
#endif
		upc_memset(src, 0, SIZE * sizeof(DTYPE));
	}
	
	upc_barrier;

	/* Each thread allocates shared memory with affinity to it, and then
	   initializes the allocated memory */
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
	dst[MYTHREAD] = upc_alloc(SIZE * sizeof(DTYPE));
#else
	dst[MYTHREAD] = upc_local_alloc(SIZE, sizeof(DTYPE));
#endif
	upc_memset(dst[MYTHREAD], MYTHREAD+1, SIZE * sizeof(DTYPE));

#ifdef VERBOSE0
	for (i = 0; i < THREADS; i++) {
		upc_barrier;
		if (MYTHREAD == i)
			for (j = 0; j < SIZE; j++) 
				printf("[af=%d] dst[%d][%d] = %d\n", upc_threadof(&dst[i][j]), i, j, dst[i][j]);
	}
#endif
	
	/* Each thread copies the content of src to its own array dst[MYTHREAD] */
	upc_memcpy(dst[MYTHREAD], src, SIZE * sizeof(DTYPE));

	for (i = 0; i < SIZE; i++)
		if (dst[MYTHREAD][i] != (DTYPE)(0)) {
			err[MYTHREAD] = 1;
			break;
		}
	
	upc_barrier;

/*	
	for (i = 0; i < THREADS; i++) {
		upc_barrier;
		if (MYTHREAD == i)
			for (j = 0; j < SIZE; j++) 
				printf("[af=%d] dst[%d][%d] = %d\n", upc_threadof(&dst[i][j]), i, j, dst[i][j]);
	}
	upc_barrier;

	if (MYTHREAD == 0) 	
		for (i = 0; i < SIZE; i++) 
			printf("[af=%d] src[%d] = %d\n", upc_threadof(&src[i]), i, src[i]);
*/

	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++)
			error += err[i];
	
		if (error)
			printf("Error: test_stress_07.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_07.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}
	return (error);
}


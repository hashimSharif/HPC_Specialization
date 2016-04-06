/* _test_stress_11.c: stress test of upc_global_alloc

	Date created: November 8, 2002
	Date modified: November 8, 2002

	Function tested: upc_global_alloc

	Description:
	- Stress test upc_global_alloc by calling the function numerous times. The number
	  of times called is limited by the 8MB of memory pool allocated for 
	  each thread.
	- Each thread allocates memory using upc_global_alloc CONST number of times and store
	  the pointer returned each time in an array.
	- Each thread makes use of some of the memory allocated.
	- Each thread performs error checking.
	- Thread 0 performs determines if test case passes. 

	Platform Tested         No. Proc        Date Tested             Success
	UPC0 (all types)	4		November 8, 2002	Yes
	CSE0 (all types)	2,4,8,12	November 14, 2002	Yes
	LION (all types)	2,4,8,16,32	November 18, 2002	Yes
	UPC0 (all types)	2,16K		December 3, 2002	Yes

	Bugs Found:
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE DATA
#define SIZE 16000
#define CONST 100

shared DTYPE *a[CONST]; 
shared int err[THREADS];

int main (void)
{
	int i, error=0;

	/* Each thread allocates memory CONST times concurrently */
	for (i = 0; i < CONST; i++) {
		a[i] = upc_global_alloc(SIZE, sizeof(DTYPE));
	}
	
	/* Each thread make use of some of the memory allocated */
	for (i = 0; i < SIZE; i++) {
		a[0][i] = (DTYPE)(i);
		a[1][i] = (DTYPE)((DTYPE)(i) + (DTYPE)(1));
	}

	/* Each thread performs error checking */
	for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
		if (MYTHREAD == 0) {
			printf("a[0][%d] = %d\n", i, a[0][i]);
			printf("a[1][%d] = %d\n", i, a[1][i]);
		}
#endif

		if (a[0][i] != (DTYPE)(i)) {
			err[MYTHREAD] += 1;
			break;
		}
	
		if (a[1][i] != (DTYPE)((DTYPE)(i) + (DTYPE)(1))) {
			err[MYTHREAD] += 1;
			break;
		}
	}

	upc_barrier;

	/* Thread 0 determines the success of test case */
	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++) {
			error += err[i];
		}

		if (error)
			printf("Error: test_stress_11.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_11.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
}


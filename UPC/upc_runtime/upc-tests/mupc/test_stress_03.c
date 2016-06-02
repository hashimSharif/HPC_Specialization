/* _test_stress_03.c: stress test upc_memget.

	Date created    : October 14, 2002
        Date modified   : November 4, 2002

        Function tested: upc_memget. 

        Description:
	- Stress test upc_memget by doing many memgets as fast as possible, i.e. without
	  operations that require synchronization in between the memgets, such as barriers. 
	- Thread 0 initializes array "a".
	- Every thread performs CONST number of upc_memget from shared array "a" to local
	  array "local". 
	- Error checking at end.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0			2,4,8		October 14, 2002	Yes
	UPC0 (all types)	4		October 28, 2002	Yes
	UPC0 (all types)	4		November 6, 2002	Yes
	CSE0 (all - D)		2,4,8,12,16	November 12, 2002	Yes
	CSE0 (double)		16		November 17, 2002	Yes
	LION (all types)	2,4,8,16,32	November 18, 2002	No
	UPC0 (all types)	2,16K		December 3, 2002	No	

        Bugs Found:
[FIXED]	[11/12/2002] Test case failed for DTYPE=double, n=16, S=16.

	[11/18/2002] On Lionel, compilation failed. Error message:
		Segmentation fault
	[12/03/2002] On upc0, test case failed for DTYPE=all, n=2, S=16K. 
		MPI process 25603 died from signal 11 (Segmentation fault)

	Notes:
	[10/14/2002] It seems that the threads are not executing concurrently, but rather
		     serially, thread 0 would output first, followed by th 1, 2, ... n-1.
	[10/14/2002] Took 540s = 7+mins to execute COUNT=1K, n = 8. 
		     For n = 2, COUNT=10K, t = 215s
			 n = 4, COUNT=10K, t = 732s
			 n = 8, COUNT=10K, t = 5538s
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE int 
#define SIZE 16000
#define COUNT 1000

shared [] DTYPE a[SIZE];
shared int error[THREADS];
DTYPE local[SIZE];

int main (void)
{
	int i, err=0;
	error[MYTHREAD] = 0;	

	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++) 
			a[i] = (DTYPE)(i);
	}
	upc_barrier;

	for (i = 0; i < COUNT; i++) {
		upc_memget(local, a, SIZE*sizeof(DTYPE));
	}

	for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
		printf("[th=%d] local[%d] = %d\n", MYTHREAD, i, local[i]);
#endif
		if (local[i] != (DTYPE)(i)) {
			error[MYTHREAD] = 1;
			break;
		}
	}

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++) {
			err += error[i];
		}
		
		if (err)
			printf("Error: test_stress_03.c failed! [th=%d, error=%d, DATA]\n", THREADS, err);
		else
			printf("Success: test_stress_03.c passed! [th=%d, error=%d, DATA]\n", THREADS, err);
	}
	
	return (err);
}

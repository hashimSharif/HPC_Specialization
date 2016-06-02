/* _test_memory8.c: test of implied synchronization of upc_all_alloc. 

        Date created    : November 8, 2002
        Date modified   : November 8, 2002

	Function tested: upc_all_alloc
        
	Description:
	- Check if there's an implied synchronization before all threads execute
	  the collective memory allocation function - upc_all_alloc.
 	- Each thread set the value of sync[MYTHREAD] with the value 1.
	- Each thread allocates memory collectively.
	- Each thread sums up the elements in array sync, and the value should
	  be equal to THREADS.
	- Each thread performs error checking.
	- Thread 0 determines if test case passes.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0 (all types)	4		11/08/2002		Yes
	CSE0 (all types)	2,4,8,16	11/11/2002		Yes
	LION (all types)	2,4,8,16,32	11/22/2002		Yes
	UPC0 (all types)	2		12/03/2002		Yes

	Bugs Found:
*/

/* bug 1281: this test is invalid, because upc_all_alloc is NOT specified to 
 * provide the implied synchronization being tested for */
#error this test is invalid

#include <upc.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//#define VERBOSE0
#define DTYPE DATA 
#define SIZE (THREADS*4000)

shared DTYPE *ptr;
shared DTYPE mysync[THREADS];
shared int err[THREADS];

int main (void) 
{
	int i, error=0;
	DTYPE sum;

	sum = (DTYPE)(0);
	sleep(MYTHREAD);
	mysync[MYTHREAD] = (DTYPE)(1);
	ptr = upc_all_alloc(SIZE, sizeof(DTYPE));
	
	for (i = 0; i < THREADS; i++) {	
		sum += mysync[i];
	}

#ifdef VERBOSE0
	printf("[th=%d] sum = %d\n", MYTHREAD, sum);
#endif

	if (sum != (DTYPE)(THREADS))
		err[MYTHREAD] = 1;

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++)
			error += err[i];

		if (error)
                        printf("Error: test_memory8.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
                else
                        printf("Success: test_memory8.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}	

	return (error);
}

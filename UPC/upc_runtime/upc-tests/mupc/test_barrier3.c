/* _test_barrier3.c: test of synchronization of upc_barrier. 

        Date created    : November 8, 2002
        Date modified   : November 8, 2002

	Function tested: upc_barrier
        
	Description:
	- Check if synchronization does happen in a barrier.
 	- Each thread sets the value of sync[MYTHREAD] with the value 1.
	- Each thread executes the barrier statement with local variable "localVar"
	  in the expression.
	- Each thread sums up the elements in array sync, and the value should
	  be equal to THREADS.
	- Each thread performs error checking.
	- Repeat the steps above with the only change of shared variable "shVar"
	  as the expression for the barrier statement.
	- Thread 0 determines if test case passes.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0 (all types)	4,8		11/08/2002		Yes
	CSE0 (all types)	2,4,8,16	11/10/2002		Yes
	LION (all types)	2,4,8,16,32	11/19/2002		Yes
	UPC0 (all types)	2		12/03/2002		Yes
	
	Bugs Found:
*/

#include <upc.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//#define VERBOSE0 
#define DTYPE DATA 

shared DTYPE mysync[THREADS];
shared int err[THREADS];
shared int shVar;

int main (void) 
{
	int i, localVar, error=0;
	DTYPE sum;

	localVar = 1;
	shVar = 2;
	sum = (DTYPE)(0);

	sleep(MYTHREAD);
	mysync[MYTHREAD] = (DTYPE)(1);
	upc_barrier (localVar);
	
	for (i = 0; i < THREADS; i++) {	
		sum += mysync[i];
	}

#ifdef VERBOSE0
	printf("[th=%d] barrier with localVar, sum = %d\n", MYTHREAD, sum);
#endif

	if (sum != (DTYPE)(THREADS))
		err[MYTHREAD] += 1;

	upc_barrier;

	sum = (DTYPE)(0);
	sleep(MYTHREAD);
	mysync[MYTHREAD] = (DTYPE)(1);
	upc_barrier (shVar);
	
	for (i = 0; i < THREADS; i++) {	
		sum += mysync[i];
	}

#ifdef VERBOSE0
	printf("[th=%d] barrier with shVar, sum = %d\n", MYTHREAD, sum);
#endif

	if (sum != (DTYPE)(THREADS))
		err[MYTHREAD] += 1;

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++)
			error += err[i];

		if (error)
                        printf("Error: test_barrier3.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
                else
                        printf("Success: test_barrier3.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}	

	return (error);
}

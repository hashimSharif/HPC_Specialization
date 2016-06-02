/* _test_barrier4.c: test of synchronization of split-barrier. 

        Date created    : November 8, 2002
        Date modified   : November 17, 2002

	Function tested: upc_notify, upc_wait.
        
	Description:
	- Check if synchronization does happen in a split-barrier. 
 	- Each thread sets the value of sync[MYTHREAD] with the value 1 right before
	  executing the upc_notify with local variable "localVar" as expression.
	- Each thread executes the upc_notify with "localVar" as expression. 
	- Each thread increments the value of sync[MYTHREAD] in between the 
	  upc_notify and upc_wait.
	- Each thread executes the upc_wait with "localVar" as expression.
	- Each thread sums up the elements in array sync, and the value should
	  be equal to (2*THREADS).
	- Each thread performs error checking.
	- Repeat the steps above with the only change of shared variable "shVar"
	  as the expression for the split-barrier.
	- Thread 0 determines if test case passes.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0 (all - D)		4		11/08/2002		Partial	
	CSE0 (all - D)		2,4,8,16	11/10/2002		Partial
	LION (all - D)		2,4,8,16,32	11/19/2002		Partial
	UPC0 (all types)	2,4		11/24/2002		Yes
	UPC0 (all types)	2		12/03/2002		Yes

	Bugs Found:
[FIXED]	[11/08/2002] Test case fails for DTYPE=double, n=4. No error message was produced.
	[11/10/2002] On CSE0 test case fails for DTYPE=double, n=2,4,8,16. Same as above,
		     no error message was produced. Program hangs.
	[11/19/2002] On lionel, test case failed for DTYPE=double, n=2,4,8,16,32. No
		     error message was produced. Program hangs.
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
	upc_notify (localVar);
	upc_wait (localVar);
	
	for (i = 0; i < THREADS; i++) {	
		sum += mysync[i];
	}

#ifdef VERBOSE0
	printf("[th=%d] split-barrier with localVar, sum = %d\n", MYTHREAD, sum);
#endif

	if (sum != (DTYPE)(THREADS))
		err[MYTHREAD] += 1;

	upc_barrier;

	sum = (DTYPE)(0);
	sleep(MYTHREAD);
	mysync[MYTHREAD] = (DTYPE)(1);
	upc_notify (shVar);
	upc_wait (shVar);
	
	for (i = 0; i < THREADS; i++) {	
		sum += mysync[i];
	}

#ifdef VERBOSE0
	printf("[th=%d] split-barrier with shVar, sum = %d\n", MYTHREAD, sum);
#endif

	if (sum != (DTYPE)(THREADS))
		err[MYTHREAD] += 1;

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++)
			error += err[i];

		if (error)
                        printf("Error: test_barrier4.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
                else
                        printf("Success: test_barrier4.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}	

	return (error);
}

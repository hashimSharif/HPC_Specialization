/* _test_barrier2.c: Test if appropriate run-time error is generated.

        Date created    : September 25, 2002
        Date modified   : November 4, 2002

	Function tested: upc_notify, upc_wait

        Description:
	- Perform test on the upc_notify() and upc_wait() functions. 
	- This primarily tests if upc_notify and upc_wait would
	  generate a runtime error should the expressions used in the
	  two functions doesn't match.
	- We first initialized an array "a". 
	- Calls upc_notify and upc_wait with different expressions.
	- Test case passes if run-time error's generated, and fails if
	  the printfs are executed.

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    2, 4            September 18, 2002     	No 
	UPC0 (all types)	4		October 30, 2002	No
	UPC0 (all types)	4		November 4, 2002	No	
	CSE0 (all types)	2,4,8,16	November 10, 2002	No
	LION (all types)	2,4,8,16,32	November 19, 2002	No
	UPC0			2		December 3, 2002	No

        Bugs Found:
	[9/25/2002] No run-time error was generated when value of upc_wait()'s expression
		    is different from upc_notify()'s. 
	[11/19/2002] On lionel, the error's the same as above.

	Note:
	[9/26/2002] Bug found on 9/25/2002 reported to programmer.

*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define SIZE (THREADS*4) 

shared int counter;
shared DTYPE a[SIZE];

int main (void)
{
	int i;

	if (MYTHREAD == 0) counter = 0;
	
	upc_forall(i = 0; i < SIZE; i++; i)
		a[i] = (DTYPE)(i);

	upc_notify 1;

	counter += 1;
	upc_barrier;  /* This statement will also produce a run-time error */

	upc_wait 2;

#ifdef VERBOSE0
	/* This section of the code should not be executed? */	
	printf("counter = %d\n", counter);
	
	upc_forall(i = 0; i < SIZE; i++; i)
		printf("a[%d] = %d\n", i, a[i]);
#endif
	if (MYTHREAD == 0) 
		printf("Error: test_barrier2.c failed! [th=%d, DATA]\n", THREADS);

	return(1); 
}

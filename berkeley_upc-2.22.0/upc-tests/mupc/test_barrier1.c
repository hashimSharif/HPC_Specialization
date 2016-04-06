/* _test_barrier1.c: test of gets and puts with notify and wait (works for n = pow(2, x), x=0,1,2,...) 

	Date created	: September 4, 2002
	Date modified	: October 29, 2002

	Function tested: upc_notify, upc_wait
	
	Description:
        - Integration test of gets and puts functions with split-barrier (notify and wait). 
	- Initialize and update data concurrently. 
	- Calls upc_notify and upc_wait. Perform local computation in between the split-barriers.
	- Calls upc_notify and upc_wait for a specified number of time inside a for loop. Acts
	  as a kinda of stress test.
	- Thread 0 performs error checking at end.
 	
	Platform Tested		No. Proc	Date Tested		Success
	UPC0			4		September 12, 2002	Yes
	UPC0			4,5,8		October 9, 2002		Yes
	UPC0 (all - D)		4		October 28, 2002	Partial
	UPC0 (all - D)		4		November 4, 2002	Partial
	CSE0 (all - D)		2,4,8,16	November 10, 2002	Partial
	CSE0 (double)		2,4,8,16	November 17, 2002	Yes
	LION (all - D)		2,4,8,16,32	November 19, 2002	Partial
	UPC0 (all)		2,4		November 23, 2002	Yes
	UPC0 (all types)	2		December 3, 2002	Yes

	Bugs Found:
[FIXED]	[10/29/2002] Test case hangs when all threads reaches upc_notify(), when data type
		     "double" is used. No error message was produced. Problem has been reported
		     to programmer.
	[11/19/2002] On lionel, test case hangs for DTYPE=double, n=2, S=T*25.

	Notes: 
	[10/29/2002] Test case will fail unless gcd(3, PERTHREAD) = 1 && gcd(3, THREADS) = 1. Due
	             to our implementation, if the condition stated above doesn't hold, 
                     all elements in the array Idata[] wouldn't be incremented, eventually causing
		     an error when correctness of data is checked.
*/

#include <upc.h>
#include <stdio.h>
#include <sys/time.h>

//#define VERBOSE0
#define DTYPE int 
#define PERTHREAD 2500
#define SIZE (THREADS * PERTHREAD)

shared DTYPE Idata[SIZE];
shared int err[THREADS];

int main (void) {

        int i, j, error=0;
	int offset = 2*PERTHREAD;
	DTYPE x = 1; 
	err[MYTHREAD] = 0;

	/* Initialize data concurrently */
	upc_forall(i = 0; i < SIZE; i++; &Idata[i]) {
		Idata[i] = (DTYPE)(i);
	}

	upc_barrier;
	

	/* Perform gets and puts of data using different memory access pattern */
	/* NOTE: the origional definition of j below does not consititute
	   an invertable (1-1) mapping of the index space whenever the
	   thread count is a multiple of 3.  Replaced it with simple shift
	   mapping, which is always invertable.  Need to insure each element
	   gets incremented exactly once.
	*/
	upc_forall(i = 0; i < SIZE; i++; i) {
/* BUG	 	j = (i * 3) % SIZE;	*/
	 	j = (i + offset) % SIZE;	
		Idata[j] += (DTYPE)(1);
	}

	upc_notify;

	/* Local computation in between the split-barrier */	
	x = x + (DTYPE)(1);
	x = x - (DTYPE)(1);

	upc_wait;

	/* Calling a bunch of notify and wait with incremental i. Introduce delays
	   in between notify and wait to test synchronization ability of notify and wait.
        */
	for (i = 0; i < 10; i++) {
                upc_notify(i);
                x = x + (DTYPE)(1);
                x = x - (DTYPE)(1);
		upc_wait(i);    
        }

#ifdef VERBOSE0
	/* Perform gets of data */
	for (j = 0; j < THREADS; j++) {
		if (MYTHREAD == j)
			for (i = 0; i < SIZE; i++)
				if (MYTHREAD == upc_threadof(&Idata[i]))
					printf("Idata[%d] = %d, x = %d\n", i, Idata[i], x);
	}
#endif

	/* Check local variable */
	if (x != (DTYPE)(1))
		err[MYTHREAD] = 1;

	upc_barrier;

	/* Check if the test case passes or fails */
	if (MYTHREAD == 0) {
		
		for (i = 0; i < SIZE; i++)
			if (Idata[i] != (DTYPE)((DTYPE)(i)+(DTYPE)(1))) 
				error = 1;
		
		for (i = 0; i < THREADS; i++)
			error += err[i];

		if (error)
                	printf("Error: test_barrier1.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
                else
                        printf("Success: test_barrier1.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);	
	}
	return (error);
}



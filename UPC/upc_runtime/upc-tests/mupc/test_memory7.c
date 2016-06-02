/* _test_memory7.c: test that upc_addrfield functions properly.

        Date created    : November 11, 2002
        Date modified   : November 11, 2002

	Function tested: upc_addrfield

        Description:
	- This is a simple test case that tests the correctness of the upc_addrfield
	  function. This function is part of the MuPC RTS because it was
	  implemented by the programmer.
	- Each thread checks if the value returned from upc_addrfield is appropriate.
	- Thread 0 performs error checking at end. 
	   
        Platform Tested         No. Proc        Date Tested             Success
	UPC0 (all types)	2,4,8		November 11, 2002	Yes
	CSE0 (all - L)		2,4,8,16	November 12, 2002	Partial
 	LION (all types)	2,4,8,16,32	November 22, 2002	Yes
	UPC0 (all types)	2		December 3, 2002	Yes
	
        Bugs Found:
	[11/11/2002] Test case failed for DTYPE=long, n=2,4,8,16, S=16.
*/

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

//#define VERBOSE0
#define DTYPE DATA 
#define SIZE 16000

shared [] DTYPE a[SIZE]; 
shared int err[THREADS];

int main()
{
	int i, error=0;

	/* Each thread checks that the address returned from upc_addrfield
	   is appropriate */
	for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
		printf("addr(&a[%d]) = %p", i, upc_addrfield(&a[i]));
		printf(", addr2=%p\n", upc_addrfield(&a[0])+(i*sizeof(DTYPE)));
#endif
		if (upc_addrfield(&a[i]) != (upc_addrfield(&a[0])+(i*sizeof(DTYPE))))
			err[MYTHREAD] += 1;
	}
			
	upc_barrier;
	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++) {
			error += err[MYTHREAD];
		}
			
		if (error)	
			printf("Error: test_memory7.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else 
			printf("Success: test_memory7.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}		
	
	return (error);
}

		

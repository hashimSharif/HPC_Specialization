/* _test_memory5.c: test that upc_threadof functions properly.

        Date created    : November 6, 2002
        Date modified   : November 6, 2002

	Function tested: upc_threadof

        Description:
	- This is a simple test case that tests the correctness of the upc_threadof
	  function. This function is part of the MuPC RTS because it was
	  implemented by the programmer.
	- First check that upc_threadof returns the right affinity for each of the elements
	  in array "ptr" which was declared with a blocking factor of 1.
	- Secondly, check that upc_threadof returns the proper affinity for each of the
	  elements in array "ptr2" which was declared with a blocking factor of BLOCK.
	- Thread 0 performs error checking at end. 
	   
        Platform Tested         No. Proc        Date Tested             Success
	UPC0 (all types)	4,8		November 6, 2002	Yes
	CSE0 (all types)	2,4,8,16	November 11, 2002	Yes
 	LION (all types)	2,4,8,16,32	November 22, 2002	Yes
	UPC0 (all types)	2		December 3, 2002	Yes
	
        Bugs Found:
*/

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

//#define VERBOSE0
#define DTYPE DATA 
#define BLOCK 1000 
#define SIZE (THREADS*BLOCK) 

shared DTYPE ptr[SIZE];
shared [BLOCK] DTYPE ptr2[SIZE];
shared int err[THREADS];

int main()
{
	int i, error=0;

	for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
		if (MYTHREAD == 0) 
			printf("upc_threadof(&ptr[%d]) = %d\n", i, upc_threadof(&ptr[i]));
#endif
		if (upc_threadof(&ptr[i]) != (i%THREADS)) 
			err[MYTHREAD] = 1;	
	}
	
	for (i = 0; i < SIZE; i++) {
		if (upc_threadof(&ptr2[i]) != ((i/BLOCK)%THREADS))
			err[MYTHREAD] = 1;
	}

	upc_barrier;
	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++)
			error += err[MYTHREAD];
			
		if (error)	
			printf("Error: test_memory5.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else 
			printf("Success: test_memory5.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}		
	
	return (error);
}

		

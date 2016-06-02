/* _test_memory6.c: test that upc_phaseof functions properly.

        Date created    : November 7, 2002
        Date modified   : November 7, 2002

	Function tested: upc_phaseof

        Description:
	- This is a simple test case that tests the correctness of the upc_phaseof
	  function. This function is part of the MuPC RTS because it was
	  implemented by the programmer.
	- Each thread first checks that the phase of each element in array "ptr"
	  which was declared with block factor of 1, is always 0.
	- Then, each thread checks that the phase of each element (returned by 
	  the upc_phaseof function) in array "ptr2" declared with block factor of 
	  BLOCK is correct.
	- Thread 0 then performs assignment and casting of pointers, and check
	  that upc_phaseof still returns the right phase.
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
#define BLOCK 400 
#define SIZE (THREADS*BLOCK) 

shared DTYPE ptr[SIZE];
shared [BLOCK] DTYPE ptr2[SIZE], *ptr3;
shared [BLOCK+2] DTYPE *ptr4;
shared int err[THREADS];

int main()
{
	int i, error=0;

	/* Phase of each element in an array declared with block size of 1 is always 0 */
	for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
		if (MYTHREAD == 0) 
			printf("phaseof(&ptr[%d]) = %d\n", i, upc_phaseof(&ptr[i]));
#endif
		if (upc_phaseof(&ptr[i]) != 0) 
			err[MYTHREAD] += 1;	
	}
	
	/* Check the phase of array "ptr2" which was declared with blocking factor BLOCK */
	for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
		if (MYTHREAD == 0) 
			printf("phaseof(&ptr2[%d]) = %d\n", i, upc_phaseof(&ptr2[i]));
#endif
		if (upc_phaseof(&ptr2[i]) != (i%BLOCK))
			err[MYTHREAD] += 1;
	}

	if (MYTHREAD == 0) {
		/* Phase of ptr3 will not be reset to 0 since it has the same type
		   and blocking factor as ptr2 */
		ptr3 = &ptr2[BLOCK-2];
		if (upc_phaseof(ptr3) != (BLOCK-2)) {
			error += 1;
		}
#ifdef VERBOSE0	
		printf("phase(ptr3)=%d\n", upc_phaseof(ptr3));
#endif

		/* Phase of ptr4 will be reset to 0 */
		ptr4 = (shared [BLOCK+2] DTYPE *)&ptr2[BLOCK-2];
		if (upc_phaseof(ptr4) != 0) {
			error += 1;
		}
#ifdef VERBOSE0
		printf("phase(ptr4)=%d\n", upc_phaseof(ptr4));
#endif
	}
		
	upc_barrier;
	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++)
			error += err[MYTHREAD];
			
		if (error)	
			printf("Error: test_memory6.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else 
			printf("Success: test_memory6.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}		
	
	return (error);
}

		

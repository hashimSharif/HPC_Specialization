/* _test_memory4.c: test if the RTS allows a user to allocate more than the max memory.

        Date created    : September 24, 2002
        Date modified   : November 4, 2002
	
	Function tested: upc_global_alloc

        Description:
	- Test if allocating more than the maximum allowed memory would produce an error.
 	- MuPC only allows 8MB of memory to be used/allocated in each thread. Allocating
	  size of memory that exceeds 8MB is not allowed. 
	- This is a simple test case that allocates more than 8MB of memory using upc_global_alloc.

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    2               September 19, 2002      No 
	UPC0 (all types)	4		October 30, 2002	No	
	UPC0 (all types)	4		November 5, 2002	No
	CSE0 (all types)	2,4,8,16	November 11, 2002	No
	LION (all types)	2,4,8,16,32	November 22, 2002	No
	UPC0 (all types)	2		December 3, 2002	No

        Bugs Found:
	[9/24/2002] MuPC allowed the the memory to be allocated, which is not proper.
		    Bug reported to the programmer.
	[11/22/2002] On lionel, fails for DTYPE=all, n=2,4,8,16,32, S=16M.
 
*/


#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE int 
#define SIZE (16 * 1024 * 1024) 

shared DTYPE * shared a;

int main (void) 
{
	/* Allocate more than 8MB of memory */
	if (MYTHREAD == 0)
		a = upc_global_alloc(SIZE, sizeof(DTYPE));
	
	/* This part of the code shouldn't be executed */
	if (MYTHREAD == 0) {
#ifdef VERBOSE0
		printf("Memory larger than 8MB allocated successfully... test case failed!\n");
#endif
		printf("Error: test_memory4.c failed! [th=%d, DATA]\n", THREADS);
	}
	return (1);	
}


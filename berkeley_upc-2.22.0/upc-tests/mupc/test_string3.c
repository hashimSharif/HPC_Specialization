/* _test_string3.c: test correctness of upc_memput.

        Date created    : September 17, 2002
        Date modified   : November 6, 2002

	Function tested: upc_memput

        Description:
        - Test correctness of upc_memput() function.
	- Each thread first initializes local array "src".
	- Each thread takes turn to copy the content of its local array "src" to
	  shared array "dst". 
	- Thread 0 performs error checking and determines if test case passes.

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    4               September 17, 2002      Yes
	UPC0 (all types)	4,8		October 30, 2002	Yes
	UPC0 (all types)	4		November 6, 2002	Yes
	UPC0 (all - L)		2,4,8,16	November 12, 2002	Partial
	CSE0 (all - L)		2,4,8,12,16	November 17, 2002	Partial
	LION (all types)	2,4,8,16,32	November 19, 2002	Yes
	UPC0 (all types)	2		November 26, 2002	No

        Bugs Found:
	[11/12/2002] Test case failed for DTYPE=long, n=2,4,8,16, S=20.
	[11/17/2002] On cse0, test case failed for DTYPE=long, n=2,4,8,12,16, S=20.
	[11/26/2002] Test case failed for DTYPE=all, n=2, S=6.4K.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE int 
#define SIZE 6400

shared [] DTYPE dst[SIZE];
DTYPE src[SIZE];

int main (void)
{
	int i, j, error=0;
	
	/* Each thread initializes local array */
	for (i = 0; i < SIZE; i++)
		src[i] = (DTYPE)((DTYPE)(i) + (DTYPE)(MYTHREAD));

	upc_barrier;

	/* Each thread takes turn to put memory to shared array */
	for (i = 0; i < THREADS; i++) {
		if (MYTHREAD == i)
			upc_memput(dst, src, SIZE * sizeof(DTYPE));
		
		upc_barrier;
		
		if (MYTHREAD == 0) 
			for (j = 0; j < SIZE; j++) {
#ifdef VERBOSE0
				printf("[th=%d] dst[%d] = %d\n", i, j, dst[j]);
#endif
				if (dst[j] != (DTYPE)((DTYPE)(j) + (DTYPE)(i)))
					error = 1;
			} // for
		
		upc_barrier;
	}

	if (MYTHREAD == 0) {
		if (error)
			printf("Error: test_string3.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else	
			printf("Success: test_string3.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}
	
	return (error);
}


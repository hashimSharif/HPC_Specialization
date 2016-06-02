/* _test_string1.c: test correctness of upc_memcpy.

        Date created    : September 18, 2002
        Date modified   : November 6, 2002
	
	Function tested: upc_memcpy

        Description:
	- Test the correctness of the upc_memcpy() functionality.
	- Two source arrays "src" and "zeroSrc" are initialized.
	- Each thread takes turn to copy the content of "src" to "dst" array.
	- Thread 0 performs error checking and copies the content of "zeroSrc"
	  to "dst". This reinitializes the content of "dst" to 0.
	- Thread 0 determines the success of test case. 

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    2, 4		September 18, 2002	Yes
	UPC0 (all types)	4		October 30, 2002	Yes
	UPC0 (all types)	4		November 6, 2002	Yes
	CSE0 (all - L)		2,4,8,16	November 12, 2002	Partial
	LION (all - D)		2,4,8,16	November 19, 2002	Partial
	UPC0 (all types)	2		December 3, 2002	Yes

        Bugs Found:
	[11/12/2002] Test case failed for DTYPE=long, n=2,4,8,16, S=T*10.
	[11/19/2002] Test case failed for DTYPE=double, n=4,8,16,32, S=100.

*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define SIZE 10000 

shared [] DTYPE src[SIZE];
shared [] DTYPE zeroSrc[SIZE];
shared [] DTYPE dst[SIZE];

int main ()
{
	int i, j, error=0;
	
	/* Initialize the 2 source arrays */
	if (MYTHREAD == 0)
		for (i = 0; i < SIZE; i++) {
			src[i] = (DTYPE)(i);
			zeroSrc[i] = (DTYPE)(0);
		}

	/* Each thread takes turn to copy content of src[] to dst[].
	   Thread 0 performs error checking, and initializes dst[] by copying
           the contents of zeroSrc[] to dst[]. */
	for (i = 0; i < THREADS; i++) {
		
		upc_barrier;

		if (MYTHREAD == i)
			upc_memcpy(dst, src, SIZE * sizeof(DTYPE));

		
		upc_barrier;

		if (MYTHREAD == 0) {
			for (j = 0; j < SIZE; j++) {
#ifdef VERBOSE0
				printf("[%d] dst[%d] = %d\n", i, j, dst[j]);
#endif
				if (dst[j] != (DTYPE)(j))
					error = 1;	
			}	
			upc_memcpy(dst, zeroSrc, SIZE * sizeof(DTYPE));
		}
	}		

	if (MYTHREAD == 0) {
		if (error)
			printf("Error: test_string1.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_string1.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
} 

/* _test_string4.c: test the functionality of upc_memset.

        Date created    : September 17, 2002
        Date modified   : November 19, 2002

	Function tested: upc_memset

        Description:
	- Test correctness of upc_memset() function. 
	- Each thread initializes a local array "compare[]" to be used for comparison purposes.
	- Then, upc_memset each element in "a" to VALUE+MYTHREAD.
	- Each thread performs error checking by comparing "a" to array "compare". 
	- Thread 0 determines success of test case at end.

        Platform Tested         No. Proc        Date Tested             Success
       	UPC0			4(1K), 2(10K)	September 17, 2002	Yes
	UPC0			4(1K)		October 30, 2002	Yes
	CSE0 (all types)	2,4,8,16	November, 12, 2002	Yes
	LION (all types)	2,4,8,16,32	November 19, 2002	Yes
	UPC0 (all types)	2,10K		December 3, 2002	Yes

	Bugs Found:
*/

#include <upc.h>
#include <stdio.h>
#include <string.h>

#define DTYPE DATA 
#define SIZE 10000
#define VALUE 99 

shared [] DTYPE a[SIZE];
DTYPE compare[SIZE];
shared int err[THREADS];
shared int error;
 
int main (void) 
{
	int i, j, error=0;

	err[MYTHREAD] = 0;

	upc_barrier;
	/* Each thread memsets the "compare" array, and then upc_memsets
	   a[MYTHREAD] */
	for (i = 0; i < THREADS; i++) {
		if (MYTHREAD == i) {
			memset(compare, VALUE+MYTHREAD, SIZE*sizeof(DTYPE));
			upc_memset(a, VALUE+MYTHREAD, SIZE*sizeof(DTYPE));

			for (j = 0; j < SIZE; j++) {
				if (a[j] != compare[j])
					err[MYTHREAD] += 1;
			}
		}
		upc_barrier;
	}

	upc_barrier;

	if (MYTHREAD == 0) { /* See if the test case passes */
		for (i = 0; i < THREADS; i++) 
			error += err[i];

		if (error)
                        printf("Error: test_string4.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
                else
                        printf("Success: test_string4.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);	
	}

	return (error);
}


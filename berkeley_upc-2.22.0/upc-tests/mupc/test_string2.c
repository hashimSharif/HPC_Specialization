/* _test_string2.c: test correctness of upc_memget.
	
	Date created    : September 17, 2002
        Date modified   : November 6, 2002
	
	Function tested: upc_memget

        Description:
        - Test correctness of upc_memget() function. There are 2 parts to this test case.
	  The first execute a single upc_memget(), while the 2nd executes a specified
	  time of upc_memget(). 
	- 1st Part:
	  - Thread 0 initializes content of array "masterCopy".
	  - Each thread copies the content of "masterCopy" to its local array
	    "localCopy".
	  - Each thread performs error checking and store results in err[MYTHREAD].
	  - Thread 0 determines if the 1st part passes or not.
	- 2nd Part:
	  - Thread 0 reinitializes content of array "masterCopy" with different values.
	  - Each thread performs multiple get from "masterCopy" to local array "localCopy".
	  - Each thread performs error checking and store results in err[MYTHREAD]. 
	  - Thread 0 determines if 2nd part passes.
	- Thread 0 determines if test case passes. 

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    4               September 17, 2002      Yes
	UPC0			4		September 18, 2002	Yes
	UPC0 (all types)	4		October 30, 2002	Yes
	UPC0 (all types)	4		November 6, 2002	Yes
	CSE0 (all types)	2,4,8,12	November 12, 2002	Yes
	LION (all - D)		2,4,8,16,32	November 19, 2002	Partial
	UPC0 (all types)	2		December 3, 2002	Yes

        Bugs Found:
	[11/19/2002] On lionel, test case failed for DTYPE=double, n=16,32, S=50.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define SIZE 5000
#define LOCALCOPY 5

shared [] DTYPE masterCopy[SIZE];
DTYPE localCopy[LOCALCOPY][SIZE];
shared int err[THREADS];

int main (void)
{
	int i, j;
	int error1=0, error2=0, error=0;
	err[MYTHREAD] = 0;

	/* Initialize master copy */
	if (MYTHREAD == 0)
		for (i = 0; i < SIZE; i++) 
			masterCopy[i] = (DTYPE)(i);

	upc_barrier;
	
	/* All threads copies masterCopy's content to local array. */
	upc_memget(localCopy[0], masterCopy, SIZE * sizeof(DTYPE));
	
	/* Each thread perform error checking. */
	for (i = 0; i < SIZE; i++) {
/*		printf("[thread %d] localCopy[0][%d] = %d\n", MYTHREAD, i, localCopy[0][i]); 
*/
		if (localCopy[0][i] != masterCopy[i])
			err[MYTHREAD] = 1;
	}
	
	upc_barrier;	

	/* Thread 0 determines if any error occurred in any thread. */
	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++)
			error1 += err[i];
#ifdef VERBOSE0
		if (error1)
			printf("Error: test_string2.c (pt 1) failed! [th=%d, error1=%d]\n", THREADS, error1);
		else
			printf("Success: test_string2.c (pt 1) passed! [th=%d, error1=%d]\n", THREADS, error1);
#endif
	}

	if (MYTHREAD == 0) 
		for (i = 0; i < SIZE; i++)
			masterCopy[i] = (DTYPE)(((DTYPE)(i) * (DTYPE)(10)) + (DTYPE)(1));

	upc_barrier;

	/* Perform multiple upc_memget */
	for (i = 0; i < LOCALCOPY; i++)
		upc_memget(localCopy[i], masterCopy, SIZE * sizeof(DTYPE));

	/* Each thread performs error checking */
	for (i = 0; i < LOCALCOPY; i++)
		for (j = 0; j < SIZE; j++)
			if (localCopy[i][j] != (DTYPE)((DTYPE)(j) * (DTYPE)(10) + (DTYPE)(1)))
				err[MYTHREAD] = 1;

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++)
                        error2 += err[i];
#ifdef VERBOSE0
		if (error1)
			printf("Error: test_string2.c (pt 2) failed! [th=%d, error2=%d]\n", THREADS, error2);
		else
			printf("Success: test_string2.c (pt 2) passed! [th=%d, error2=%d]\n", THREADS, error2);
#endif
                
		if (error)
			printf("Error: test_string2.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_string2.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
        }
	
	return (error);
}
		

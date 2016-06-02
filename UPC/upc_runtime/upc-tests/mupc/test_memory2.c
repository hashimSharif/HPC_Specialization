/* _test_memory2.c: test the correctness of upc_global_alloc function.

        Date created    : September 19, 2002
        Date modified   : November 4, 2002

	Function tested: upc_global_alloc
        
	Description:
	- Test the correctness of upc_global_alloc(). There are 2 parts in this test case.
	- 1st part: 
	  - All threads will perform global memory allocation, initialization,
 	    simultaneously. 
	  - Thread 0 performs error checking at end. 
	- 2nd part: 
	  - Each thread initializes the elements in array b with value of the array a of
	    its neighbour (MYTHREAD + 1).      
	  - Thread 0 performs error checking at end.
	- Thread 0 determines the success of this test case.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0			4		September 19, 2002	Yes
	UPC0 (all types)	4		October 29, 2002	Yes
	UPC0 (all types)	4		November 5, 2002	Yes
	CSE0 (all - D)		2,4,8,16	November 11, 2002	Partial
	CSE0 (double)		2,4,8,16	November 17, 2002	Yes
	LION (all types)	2,4,8,16,32	November 22, 2002	No
	UPC0 (all types)	2		December 3, 2002	Yes

        Bugs Found:
[FIXED]	[11/11/2002] Test case failed for DTYPE=double, n=16, S=16.

	[11/22/2002] On lionel, test case failed for DTYPE=all, n=2,4,8,16,32, S=16.
		MPI process rank 0 (n0, p4752) caught a SIGSEGV
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE int 
#define SIZE 16000

shared DTYPE * shared a[THREADS];
shared DTYPE * shared b[THREADS];

int main (void) 
{
	int i, j;
	int error1=0, error2=0, error=0;

	/* Allocate memory using global memory allocation */
	a[MYTHREAD] = upc_global_alloc(SIZE, sizeof(DTYPE));
	b[MYTHREAD] = upc_global_alloc(SIZE, sizeof(DTYPE));

	/* Each thread initializes it's own array */
	for (i = 0; i < SIZE; i++) { 
		a[MYTHREAD][i] = (DTYPE)((DTYPE)(i) + (DTYPE)(MYTHREAD));
	}

#ifdef VERBOSE0
	for (j =0; j < THREADS; j++) {
		if (MYTHREAD == j) 
			for (i = 0; i < SIZE; i++)
				printf("<%d>[aff %d] a[%d][%d] = %d\n", 
					MYTHREAD, upc_threadof(&a[j][i]), j, i, a[j][i]);
		upc_barrier;
	}
#endif

	upc_barrier;

	if (MYTHREAD == 0) {
		for (j = 0; j < THREADS; j++) 
			for (i = 0; i < SIZE; i++)
				if (a[j][i] != (DTYPE)((DTYPE)(i) + (DTYPE)(j)))
					error1 = 1;
#ifdef VERBOSE0
		if (error1)
			printf("Error: test_memory2.c (pt 1) failed! [th=%d, error1=%d]\n", THREADS, error1); 
		else
			printf("Success: test_memory2.c (pt 1) passed! [th=%d, error1=%d]\n", THREADS, error1); 
#endif
	}

	upc_barrier;

	
	for(i = 0; i < SIZE; i++) {
		b[MYTHREAD][i] = a[(MYTHREAD+1)%THREADS][i];
	}

#ifdef VERBOSE_1
	for (j =0; j < THREADS; j++) {  
                if (MYTHREAD == j)
                        for (i = 0; i < SIZE; i++) 
                                printf("<%d>[aff %d] b[%d][%d] = %d\n",
                                        MYTHREAD, upc_threadof(&b[j][i]), j, i, b[j][i]);
                upc_barrier;
        }
#endif

	upc_barrier;

	if (MYTHREAD == 0) {
                for (j = 0; j < THREADS; j++) 
                        for (i = 0; i < SIZE; i++)
                                if (b[j][i] != (DTYPE)((DTYPE)(i) + (DTYPE)((j + 1) % THREADS)))
                                        error2 = 1;
#ifdef VERBOSE0 
		if (error2)
			printf("Error: test_memory2.c (pt 2) failed! [th=%d, error2=%d]\n", THREADS, error2); 
		else
			printf("Success: test_memory2.c (pt 2) passed! [th=%d, error2=%d]\n", THREADS, error2); 
#endif 
		error = error1 + error2;

		if (error)
			printf("Error: test_memory2.c failed! [th=%d, error=%d, DATA]\n", THREADS, error); 
		else
			printf("Success: test_memory2.c passed! [th=%d, error=%d, DATA]\n", THREADS, error); 
        }

	return (error);
}	

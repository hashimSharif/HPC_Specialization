/* _test_memory1.c: test the correctness of upc_all_alloc.

        Date created    : September 23, 2002
        Date modified   : November 4, 2002

	Function tested: upc_all_alloc

        Description:
	- Test the correctness of upc_all_alloc() dynamic memory allocation function.
	- Each thread initialized sync[MYTHREAD] to 1 just before reaching upc_all_alloc.
	- A shared array "a" is then allocated using the collective memory allocation function. 
	- Each thread sums up the values of array "sync" and they should get a value of THREADS.
	- Each thread performs error checking.
	- The shared array "a" is initialized and updated by all threads using upc_forall.
	- Finally thread 0 perform the necessary error checking to determine what error has occurred.
 
        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    4               September 23, 2002      Yes
	UPC0			8 		September 26, 2002	Yes
	UPC0 (all types)	4		October 29, 2002	Yes
	CSE0 (all types)	2,4,8,16	November 11, 2002	Yes
	LION (all types)	2,4,8,16,32	November 22, 2002	Yes
	UPC0 (all types)	2		December 3, 2002	Yes

        Bugs Found:
*/

#include <upc.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

//#define VERBOSE0
#define DTYPE DATA 
#define SIZE (THREADS * 800) 

shared DTYPE *a;
shared DTYPE mysync[THREADS];
shared int err[THREADS];

int main()
{
	int i, j, error=0;
	DTYPE check=0;
	
	/* Allocate memory using collective function, and check if 
	   synchronization occurred */
	sleep(MYTHREAD);
	mysync[MYTHREAD] = (DTYPE)(1);
	a = upc_all_alloc(SIZE, sizeof(DTYPE));
#if 0
/* bug 1281: this test is invalid, because upc_all_alloc is NOT specified to 
 * provide the implied synchronization being tested for */
	
	for (i = 0; i < THREADS; i++) 
		check += mysync[i];

	if (check != (DTYPE)(THREADS))
		err[MYTHREAD] = 1;
#endif

	/* Perform initialization. */
	upc_forall(i = 0; i < SIZE; i++; &a[i])
		a[i] = (DTYPE)(i);

	upc_barrier 1;

#ifdef VERBOSE0
	/* Print value of shared array. */
	for (j = 0; j < THREADS; j++) {
		if (MYTHREAD == j)  
			for (i = 0; i < SIZE; i++)
				if (upc_threadof(&a[i]) == j)
					printf("[th=%d, af=%d] a[%d] = %d\n", MYTHREAD, upc_threadof(&a[i]), i, a[i]);
	
		upc_barrier;	
	}
#endif

	/* Update content of shared array. */
	upc_forall(i = 0; i < SIZE; i++; &a[i])
		a[i] += (DTYPE)(1);

	upc_barrier 2;

	/* Error checking.*/
	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++)
			if (a[i] != (DTYPE)((DTYPE)(i) + (DTYPE)(1)))
				error = 1;
		
		for (i = 0; i < THREADS; i++)
			error += err[i];

		if (error)
			printf("Error: test_memory1.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else 
			printf("Success: test_memory1.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}		
	
	return (error);
}

		

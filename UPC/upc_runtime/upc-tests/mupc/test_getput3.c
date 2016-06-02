/* _test_getput3.c: gets and puts w/ uniform offset affinity.

	Date created	: August 29, 2002
	Date modified	: November 4, 2002

	Function tested: UPCRTS_GetBytes, UPCRTS_GetSyncInteger, UPCRTS_PutInteger
			 UPCRTS_GetSyncFloat, UPCRTS_PutFloat, UPCRTS_GetSyncDouble,
			 UPCRTS_PutDouble.
	
	Description:
	- A 2-part test case that tests gets and puts with uniform offset of affinity.
	- This test case is similar to test_getput1.c, except that the declaration of
	  shared array "Idata" is different. This gives us different memory access pattern.
	- 1st Part (gets and puts with affinity to thread): 
	  - All threads initialize and update array "Idata" concurrently. 
	  - Thread 0 performs error checking.
	- 2nd Part (gets and puts with no affinity to thread):
	  - All threads reinitialize and update array "Idata".
	  - Thread 0 performs error checking.
	- Thread 0 determine the success of test case in general.
	
	Platform Tested		No. Proc	Date Tested		Success
	UPC0			4		August 29, 2002		Yes
	UPC0			1-16		October 9, 2002		Yes
	UPC0 (all types)	4		October 28, 2002	Yes
	UPC0 (all types)	4		November 4, 2002	Yes
	CSE0 (all types)	2,4,8,16	November 7, 2002	Yes
	CSE0 (all types)	2,4,8,16,32	November 18, 2002	Yes
	UPC0 (all types)	2		December 3, 2002	Yes

	Bugs Found:
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define BLOCK 1000 
#define SIZE (THREADS * BLOCK)

shared [BLOCK] DTYPE Idata[SIZE];
shared int error1, error2, error;

int main () {

        int i, j;
	error1 = 0; error2 = 0; error = 0;

	/* Test gets and puts with affinity */

        upc_forall(i = 0; i < SIZE; ++i; &Idata[i]) /* Initialize array */
                Idata[i] = (DTYPE)(i);

	upc_forall(i = 0; i < SIZE; ++i; &Idata[i]) /* Update value of array */
		Idata[i] = (DTYPE)(Idata[i] + (DTYPE)(1));

	upc_barrier;

	/* Error checking */	
	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
			printf("(part 1) Idata[%d] = %d\n", i, Idata[i]);
#endif	
			if (Idata[i] != (DTYPE)((DTYPE)(i) + (DTYPE)(1)))
				error1 = 1;
		}

#ifdef VERBOSE0
		if (error1)
			printf("Error: test_getput3.c (pt 1) failed! error1 = %d\n", error1);
		else 
			printf("Success: test_getput3.c (pt 1) passed! error1 = %d\n", error1);
#endif
	}

	upc_barrier;

	/* Test gets and puts with no affinity */

	upc_forall(i = 0; i < SIZE; ++i; &Idata[i]) { /* Initialization */
		Idata[i] = (DTYPE)(i);
	}
	
	upc_barrier;

	/* Each thread takes turn to update data w/o affinity to it */
	for (j = 0; j < THREADS; ++j) {
		if (MYTHREAD == j) {
			for (i = 0; i < SIZE; ++i) {
				if (MYTHREAD != upc_threadof(&Idata[i]))
					Idata[i] = (DTYPE)(Idata[i] + (DTYPE)(100));
 			}
		}
		upc_barrier;
	}

	/* Error checking */
	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; ++i) {
#ifdef VERBOSE0

			printf("(part 2) Idata[%d] = %d\n", i, Idata[i]);
#endif	
			if (Idata[i] != (DTYPE)((DTYPE)(i) + (THREADS-1) * (DTYPE)(100)))
				error2 = 1;
		}
#ifdef VERBOSE0		
		if (error2)
			printf("Error: test_getput3.c (pt 2) failed! error2 = %d\n", error2);
		else
			printf("Success: test_getput3.c (pt 2) passed! error2 = %d\n", error2);
#endif
		error = error1 + error2;

		if (error)
			printf("Error: test_getput3.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_getput3.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}	
	return (error);
}



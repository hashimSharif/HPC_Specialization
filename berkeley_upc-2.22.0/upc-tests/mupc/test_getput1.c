/* _test_getput1.c: gets and puts w/ and w/o affinity.

	Date created	: August 27, 2002
	Date modified	: November 4, 2002

	Function tested: UPCRTS_GetBytes, UPCRTS_GetSyncInteger, UPCRTS_PutInteger.
			 UPCRTS_GetSyncFloat, UPCRTS_PutFloat, UPCRTS_GetSyncDouble,
			 UPCRTS_PutDouble.

	Description:
	- A 2-part test case that test gets and puts with affinity followed by 
	  test of gets and puts with no affinity.
	- 1st part:
	  	- Initalize shared array "Idata" concurrently.  
		- Each thread updates data in "Idata" that it has affinity to.
		- Thread 0 performs error checking at end.
	- 2nd part:
		- Reinitialize shared array "Idata"
		- Each thread updates data in "Idata" that it has no affinity to.
		- Thread 0 performs error checking at end.
 	- Thread 0 determines the success of test case.
	
	Platform Tested		No. Proc	Date Tested		Success
	UPC0			1,2,4		August 29, 2002		Yes
	UPC0			1-5		October 9, 2002		Yes
	UPC0 (all types)	4		October 27, 2002	Yes
	UPC0 (all types)	4		November 4, 2002	Yes
	CSE0 (all types)	2,4,8,16	November 7, 2002	Yes
	LION (all types)	2,4,8,16,32	November 18, 2002	Yes
	UPC0 (all types)	2		December 3, 2002	Yes
	
	Bugs Found:
*/


#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE int 
#define SIZE (THREADS * 5) 

shared DTYPE Idata[SIZE];

int main () {

        int i, j;
	int error1=0, error2=0, error=0;

	/* Test gets and puts with affinity */
        
        upc_forall(i = 0; i < SIZE; ++i; &Idata[i]) /* Initialization */
                Idata[i] = (DTYPE)(i);

	upc_forall(i = 0; i < SIZE; ++i; &Idata[i]) /* Update array */
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
                        printf("Error: test_getput1.c (pt 1) failed! error1 = %d\n", error1);
                else
                        printf("Success: test_getput1.c (pt 1) passed! error1 = %d\n", error1);
#endif
        }

        upc_barrier;

	/* Test gets and puts with no affinity */

	upc_forall(i = 0; i < SIZE; ++i; &Idata[i]) {
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
                        if (Idata[i] != ((DTYPE)(i) + (DTYPE)((THREADS-1) * (DTYPE)(100))))
                                error2 = 1;
                }
#ifdef VERBOSE0
                if (error2)
                        printf("Error: test_getput1.c (pt 2) failed! error2 = %d\n", error2);
                else
                        printf("Success: test_getput1.c (pt 2) passed! error2 = %d\n", error2);
#endif
                error = error1 + error2;

                if (error)
                        printf("Error: test_getput1.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
                else
                        printf("Success: test_getput1.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
        }

	return (error);
}



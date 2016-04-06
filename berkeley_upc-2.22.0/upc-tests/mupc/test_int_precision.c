/* _test_int_precision.c: test loss of precision in floating-point numbers during data transfer. (X)

	Date created    : October 24, 2002
        Date modified   : November 18, 2002

        Function tested: upc_memcpy, upc_memget, upc_memput, UPCRTS_GetBytes,
			 UPCRTS_GetSyncFloat, UPCRTS_GetSyncDouble, UPCRTS_PutFloat,
			 UPCRTS_PutDouble. 

        Description:
	- Tests if a loss of precision occurs when transferring floating-point numbers.
	- Change the constant DTYPE to test either "float" or "double" data type.
	- Initialize an array origin with data type DTYPE.
	- Transfer data using all possible methods - normal gets and puts, upc_memcpy,
	  upc_memput, and upc_memget.
        - Perform error checking at end.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0 (both)		2,4,8		October 24, 2002	Yes
	UPC0 (both)		4		November 5, 2002	Yes
	CSE0 (both)		2,4,8,16	November 10, 2002	Yes
	LION (both)		2,4,8,16,32	November 18, 2002	Yes	
	UPC0 (both)		2		December 3, 2002	No

        Bugs Found:
	[12/03/2002] On upc0, test case failed for n=2, S=3.2K. Source of problem might
		     lie in the upc_memput function.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define SIZE 3200

shared [] DTYPE origin[SIZE];
shared [] DTYPE clone1[SIZE];
shared DTYPE *clone2;
DTYPE local[SIZE];

shared int err[THREADS];
shared int error;

int main (void)
{
	int i;
	
	clone2 = upc_all_alloc(SIZE, sizeof(DTYPE));
	
	/* Initialize the origin array and misc var.*/
	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++) {
			origin[i] = (DTYPE)(1.123 * i);
		}
	}
	upc_barrier 1;

	/* Copy values in array "origin" using all available
	   methods to other threads. */
	upc_memcpy (clone1, origin, SIZE*sizeof(DTYPE));
	upc_memget (local, origin, SIZE*sizeof(DTYPE));
	upc_memput (origin, local, SIZE*sizeof(DTYPE));
 
	for (i = 0; i < SIZE; i++) {
		clone2[i] = origin[i];
	}

	upc_barrier 2;

	/* Each thread performs error checking on array "local" and "clone2". */
	for (i = 0; i < SIZE; i++) {
		DTYPE volatile d = (DTYPE)(1.123 * i); /* see BUPC bug 168 */
		if (local[i] != d)
			err[MYTHREAD] += 1;
	}

	upc_forall (i = 0; i < SIZE; i++; &clone2[i]) {
		DTYPE volatile d = (DTYPE)(1.123 * i); /* see BUPC bug 168 */
		if (clone2[i] != d)
			err[MYTHREAD] += 1;
	}

	upc_barrier 3;

	/* Thread 0 performs error checking on array "origin" and "clone1"
	   which it has affinity to */
	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++) {
			error += err[i];
		}

		for (i = 0; i < SIZE; i++) {
                   DTYPE volatile d; /* see BUPC bug 168 */
#ifdef VERBOSE0
			printf("origin[%d] = %3.10f\n", i, origin[i]);
			printf("clone1[%d] = %3.10f\n", i, clone1[i]);
			printf("clone2[%d] = %3.10f\n", i, clone2[i]);
			printf("local[%d]  = %3.10f\n\n", i, local[i]);
#endif
			d = (DTYPE)(1.123 * i);
			if (origin[i] != d) {
				error += 1;
				break;
			}

			if (clone1[i] != d) {
				error += 1;
				break;
			}
		}
		
		if (error)
			printf("Error: test_int_precision.c failed! [th=%d, error=%d]\n", THREADS, error);
		else
			printf("Success: test_int_precision.c passed! [th=%d, error=%d]\n", THREADS, error);
	}

	return (error);
}

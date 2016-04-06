/* _test_getput4.c: volume test MuPC by concurrently doing many gets and puts.

	Date created    : September 4, 2002
        Date modified   : November 4, 2002

	Function tested: UPCRTS_GetBytes, UPCRTS_GetSyncInteger, UPCRTS_PutInteger,
			 UPCRTS_GetSyncFloat, UPCRTS_PutFloat, UPCRTS_GetSyncDouble, 
			 UPCRTS_PutDouble

        Description:
        - Volume test MuPC RTS by issuing many gets and puts from all threads concurrently. 
	- All threads initialize and updates a[MYTHREAD][i] concurrently.
	- Thread 0 performs error checking at end. 

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    4 (SIZE<240)    September 4, 2002       Yes
	UPC0			4 (SIZE>280)	September 4, 2002	No
        UPC0			4 (SIZE<=800)	October 2, 2002		Yes
	UPC0			4 (SIZE>900)	October 2, 2002		No
	UPC0 (all types)	4 (SIZE=100) 	October 28, 2002	Yes
	UPC0 (all types)	4 (SIZE=1K)	October 30, 2002	Yes
	UPC0 (all types)	4 (SIZE=1K)	November 4, 2002	Yes
	CSE0 (all types)	2,4,8,16,1K	November 9, 2002	Yes
	LION (all types)	2,4,8,16,32,1K	November 18, 2002	Yes
	UPC0 (all types)	2,10K		December 3, 2002	Yes

	Bugs Found:
[FIXED]	[09/04/2002] Error when size of array is defined to be (THREADS * 70) 
		MPI_Isend: internal MPI error: GER overflow (rank 2, MPI_COMM_WORLD)
	
[FIXED]	[10/01/2002] Error when SIZE=900. It worked for SIZE<=800 after modification. 
		     However, 800 > (4 * 70 = 280). This error occurs at different SIZEs.
		MPI_Isend: internal MPI error: GER overflow (rank 2, MPI_COMM_WORLD)

	Notes:
	[09/04/2002] Error found today is due to MPI's resource limitation, according to
		     the programmer.
	[10/01/2002] According to programmer, the errors are due to MPI's resource
                     limitation.
        [10/01/2002] Amazing, now it won't work for SIZE=[700, 800]!! It worked before
		     this. Just a couple of mins ago. Weird...
	[10/28/2002] It seems that adding the  -nger option when running mpirun would
		     enable SIZE to be larger, but results can still be unpredictable.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE DATA 
#define SIZE 10240

shared int a[THREADS][SIZE];
shared int error;

int main (void) {

	int i, j;
	error = 0;

	/* All threads initialize array */	
	for (i = 0; i < SIZE; i++)
		a[MYTHREAD][i] = (DTYPE)(1);

	/* All threads update array */
	for (i = 0; i < SIZE; i++)
		a[MYTHREAD][i] += (DTYPE)(MYTHREAD);

#ifdef VERBOSE0
	for (i = 0; i < SIZE; i++)
		printf("[th=%d, af=%d] a[%d][%d] = %d\n", MYTHREAD, upc_threadof(&a[MYTHREAD][i]), 
			MYTHREAD, i, a[MYTHREAD][i]);
#endif
	upc_barrier;

	if (MYTHREAD == 0) {

		for (j = 0; j < THREADS; j++) 
			for (i = 0; i < SIZE; i++) 
				if (a[j][i] != (DTYPE)((DTYPE)(j) + (DTYPE)(1)))
					error = 1;
		
		if (error)
			printf("Error: test_getput4.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_getput4.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
}

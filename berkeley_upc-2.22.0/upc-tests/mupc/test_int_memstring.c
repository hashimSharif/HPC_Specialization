/* _test_int_memstring.c: tests upc_all_alloc, and memory transfer functions.

	Date created    : September 9, 2002
        Date modified   : November 4, 2002

	Function tested: upc_all_alloc, upc_memget, upc_memput

        Description:
        - Allocate shared array "a" and "b[i]" using upc_all_alloc, and initialize array "a".
	- Each thread copies the content of shared array "a" into its local array, modifies
	  the content of the local array, and then write to shared array.
	- Thread 0 performs error checking at end.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0			2, 4		September 25, 2002	Yes				
	UPC0			2		October 7, 2002		Yes
	UPC0			4, 8		October 7, 2002		No
	UPC0 (all types)	4		October 29, 2002	Yes
	UPC0 (all types)	4		November 5, 2002	Yes
	CSE0 (all - L)		2,4,8,16	November 10, 2002	Partial
	CSE0 (long)		2,4,8,12	November 17, 2002	No
	LION (all types)	2,4,8,16,32	November 19, 2002	No
	UPC0 (all types)	2		December 3, 2002	Yes

        Bugs Found:
[FIXED] [10/7/2002] The error below is probably caused by upc_all_alloc. Bug is being fixed
		    by programmer.
		MPI process rank 0 (n0, p13185) caught a SIGSEGV.

	[11/10/2002] On cse0, test case failed for DTYPE=long. Problem might lie in the put_block
		     or get_block function.
	[11/17/2002] On cse0, test case failed for DTYPE=long, n=2,4,8,12, S=T*10.
	[11/19/2002] On lionel, test case failed for DTYPE=all, n=2,4,8,16,32, S=32.
		MPI process rank 0 (n0, p30052) caught a SIGSEGV.

	Notes:
	[10/7/2002] Bugs found in [10/7/2002] fixed by programmer. The 2 functions that are
		    causing problems are upc_all_lock_alloc, and upc_all_alloc.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define SIZE 3200

shared DTYPE *a;
shared DTYPE * shared b[THREADS];
DTYPE local[SIZE];

shared int err[THREADS];

int main (void) {

	int i, j, error=0;
	err[MYTHREAD] = 0;
	
	a = upc_all_alloc(SIZE, sizeof(DTYPE));
	
	/* Allocate THREADS number of array b.*/
	for (i = 0; i < THREADS; i++) 
		b[i] = upc_all_alloc(SIZE, sizeof(DTYPE));
	
	upc_forall(i = 0; i < SIZE; i++; &a[i]) {
		a[i] = (DTYPE)(i);
#ifdef VERBOSE0
		printf("[af=%d] addr = %u,  a[%d] = %d\n", 
			upc_threadof(&a[i]), upc_addrfield(&a[i]), i, a[i]);
#endif
	}	

	upc_barrier;

	for (i = 0; i < SIZE; i++) 
		upc_memget(local+i,  a+i, sizeof(DTYPE));

	upc_barrier;

#ifdef VERBOSE0
	for(i = 0; i < THREADS; i++) {
		if (MYTHREAD == i) 
			for (j = 0; j < SIZE; j++)
				printf("[thread %d] local[%d] = %d\n", MYTHREAD, j, local[j]);		
 
		upc_barrier;
	}
#endif
 
	for (i = 0; i < SIZE; i++)
		local[i] += (DTYPE)(MYTHREAD);	

	for (i = 0; i < SIZE; i++)
		upc_memput(b[MYTHREAD]+i, local+i, sizeof(DTYPE));

	upc_barrier;

#ifdef VERBOSE0
	for(i = 0; i < THREADS; i++) {
		if (MYTHREAD == i) 
			for (j = 0; j < SIZE; j++)
				printf("[thread %d] b[%d][%d] = %d\n", MYTHREAD, i, j, b[MYTHREAD][j]);		
 
		upc_barrier;
	}
#endif
 
	/* Each thread performs error checking */
	for (i = 0; i < SIZE; i++)
		if (b[MYTHREAD][i] != (DTYPE)((DTYPE)(i) + (DTYPE)(MYTHREAD)))
			err[MYTHREAD] = 1;

	upc_barrier;
	
	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++) {
			error += err[i];
		}

		if (error)
                        printf("Error: test_int_memstring.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
                else
                        printf("Success: test_int_memstring.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
} 

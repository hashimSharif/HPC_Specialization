/* _test_stress_05.c: alternative stress test of upc_memget.

	Date created    : October 14, 2002
        Date modified   : November 4, 2002

        Function tested: upc_memget, upc_memset.

        Description:
	- Stress test upc_memget and the internal buffering system by doing large memgets. 
	- If block of message to be "get" is larger than the maximum transferable block, it'll be
	  split into multiple section and retrieved one after another. 
	- To really stress this, one can change the MAX_BLOCK_XFER constant from 10,000 to 10. 
	  In this case, a 10K block would have to be chopped into 1000 parts. However, the user
	  needs access to the source code of MuPC.
	- Thread 0 first initializes a shared array "a" to 0.
	- Every thread initializes its own local array to a value that's non-zero.
	- Each thread then performs upc_memget of large chunks of memory.
	- Each thread perform error checking. Thereafter, thread 0 will sum up the error value
	  of each thread, the total should equal to 0.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0			2,4		October 14, 2002	Yes
	UPC0 (all types)	4		October 27, 2002	Yes
	UPC0 (all types)	4		November 6, 2002	Yes
	CSE0 (all types)	2,4,8,12	November 13, 2002	Yes
	LION (all - I,L,F)	2,4,8,16,32	November 18, 2002	Partial
	UPC0 (all types)	2		December 3, 2002	Yes

        Bugs Found:
	[11/18/2002] On lionel, test case failed for DTYPE=int,long,float; n=2,4,8,16,32, S=1M.
		     Error message is as follows:
		MPI process rank 1 (n0, p15695) caught a SIGSEGV.
*/

#include <upc.h>
#include <stdio.h>
#include <string.h>

//#define VERBOSE0
#define DTYPE DATA
#define SIZE (1000 * 1024)

shared [] DTYPE a[SIZE];
shared int err[THREADS];
DTYPE local[SIZE];

int main (void)
{
	int i, error=0;

	if (MYTHREAD == 0) { /* initialize the content of shared array */ 
		upc_memset (a, 0, SIZE*sizeof(DTYPE));
	}
	upc_barrier;
		
	memset(local, 1, SIZE*sizeof(DTYPE));
	upc_memget(local, a, SIZE*sizeof(DTYPE));

	for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
		printf("[th=%d] local[%d] = %d\n", MYTHREAD, i, local[i]);
#endif
		if (local[i] != (DTYPE)(0))
			err[MYTHREAD] = 1;
	}

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++) 
			error += err[i];
 
		if (error)
			printf("Error: test_stress_05.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_05.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}
	
	return (error);
}

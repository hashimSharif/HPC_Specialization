/* _test_stress_04.c: alternative stress test of upc_memputs. 

	Date created    : October 14, 2002
        Date modified   : November 4, 2002

        Function tested: upc_memput, upc_memset.

        Description:
	- Stress test upc_memput and the internal buffering system by doing large memputs. 
	- If block of message to be "put" is larger than the maximum transferable block, it'll be
	  split into multiple section and sent one after another. 
	- To really stress this, one can change the MAX_BLOCK_XFER constant from 10,000 to 10.
	  In this case, a 10K block would have to be chopped into 1000 parts. However, the 
	  user needs access to the source code of MuPC.
	- Initialize a shared array "a" using upc_memset to something != 0.
	- Each thread initialize local array "local" using memset to 0.
	- Perform upc_memput of a large volume.
	- Perform error checking at end.
 	
        Platform Tested         No. Proc        Date Tested             Success
	UPC0			4		October 14, 2002	Yes
	UPC0 (all types)	4		October 27, 2002	Yes
	UPC0 (all types)	4		November 6, 2002	Yes
	CSE0 (all types)	2,4,8,12	November 13, 2002	Yes
	LION (all types)	2,4,8,16,32	November 18, 2002	Yes
	UPC0 (all - D)		2		December 3, 2002	No

        Bugs Found:
	[12/03/2002] On upc0, test case failed for n=2, S=1M. Problem in upc_memput.
*/

#include <upc.h>
#include <stdio.h>
#include <string.h>

//#define VERBOSE0 
#define DTYPE DATA 
#define SIZE (1000 * 1024)

shared [] DTYPE a[SIZE];
DTYPE local[SIZE];

int main (void)
{
	int i, error=0;

	if (MYTHREAD == 0) /* initialize the content of shared array */ 
		upc_memset (a, 1, SIZE*sizeof(DTYPE));
	upc_barrier;
		
	memset(local, 0, SIZE*sizeof(DTYPE));
	upc_memput(a, local, SIZE*sizeof(DTYPE));

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
			printf("a[%d] = %d\n", i, a[i]);
#endif
			if (a[i] != (DTYPE)(0)) {
				error = 1;
				break;
			}
		}
		
		if (error)
			printf("Error: test_stress_04.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_04.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}
	
	return (error);
}

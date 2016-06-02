/* _test_stress_01.c: stress test barriers and notify's and wait's. 

	Date created    : October 10, 2002
        Date modified   : November 6, 2002

        Function tested: upc_notify, upc_wait, upc_barrier. 

        Description:
	- Stress test barriers and split-barriers. 
	- Call COUNT number of barriers and split barriers in for loop, while performing
	  checks for barrier synchronization.  
	- Perform error checking at end.

        Platform Tested         No. Proc        Date Tested             Success
       	UPC0                    2 4            	October 10, 2002        Yes
	UPC0 (all types)	2,4		October 24, 2002	Yes
	UPC0 (all - D)		4		November 6, 2002	Partial
	CSE0 (all types)	2,4,8,16	November 12, 2002	Yes
	LION (all - D)		2,4,8,16,32	November 18, 2002	Partial	
	UPC0 (all types)	2, 1K		December 3, 2002	Yes

        Bugs Found:
[FIXED]	[11/06/2002] Test case hung when DTYPE=double. Bug reported to programmer.
	[11/18/2002] Test case failed for DTYPE=double, n=2,4,8,16,32, count=50.
*/

#include <upc.h>
#include <stdio.h>
#include <string.h>

//#define VERBOSE0
#define DTYPE DATA 
#define COUNT 1000

shared DTYPE a[THREADS];
shared int err[THREADS];

int main (void)
{
	int i, j, sum, error=0;

	/* Perform calls to barriers, upc_notifys, upc_waits. */
	for (i = 0; i < COUNT; i++) {
		sum = (DTYPE)(0);
		a[MYTHREAD] = (DTYPE)(1); 
		upc_barrier i;

		for (j = 0; j < THREADS; j++)
			sum += a[j];

		if (sum != (DTYPE)(THREADS))
			err[MYTHREAD] = 1;
		
		upc_notify i;
		upc_wait i;
	}

	/* Peform error checking */
	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++) {
#ifdef VERBOSE0
			printf("err[%d] = %d\n", MYTHREAD, err[MYTHREAD]);
#endif
			error += err[i];
		}
		
		if (error)
			printf("Error: test_stress_01.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_01.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}
	
	return (error);
}

/* _test_stress_02.c: stress test upc_memputs. 

	Date created    : October 14, 2002
        Date modified   : November 4, 2002

        Function tested: upc_memput. 

        Description:
	- Stress test upc_memput by doing many memputs as fast as possible, i.e. without
	  operations that require synchronization in between the memputs, such as barriers. 
	- Each thread initialize its own local array.
	- Copy value of local array to array "a" using upc_memput.
	- Perform error checking at end. 

        Platform Tested         No. Proc        Date Tested             Success
	UPC0			2, 4		October 14, 2002	Yes
	UPC0 (all types)	4		October 28, 2002	Yes
	CSE0 (all types)	2,4,8,16	November 12, 2002	Yes
	LION (all types)	2,4,8,16,32	November 18, 2002	No
	UPC0 (all types)	2		December 3, 2002	No

        Bugs Found:
	[11/18/2002] On lionel, compilation failed. The following error message was received:
		mupcc -f 2 test_stress_02.c
		Linux & UPC
		Segmentation fault
		__INIT_9_1test_stress_02_c_main
	[12/03/2002] On upc0, test case failed for n=2, S=3.2K, C=1K. Problem most probably in
		     upc_memput function.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define DTYPE DATA 
#define SIZE 3200
#define COUNT 100

shared [] DTYPE a[SIZE];
DTYPE local[SIZE];

int main (void)
{
	int i, error=0;

	for (i = 0; i < SIZE; i++) {
		local[i] = (DTYPE)i;
	}

	for (i = 0; i < COUNT; i++) {
		upc_memput(a, local, SIZE*sizeof(DTYPE));
	}

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
			printf("a[%d] = %d\n", i, a[i]);
#endif
			if (a[i] != (DTYPE)(i))
				error = 1;
		}
		
		if (error)
			printf("Error: test_stress_02.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_02.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}
	
	return (error);
}

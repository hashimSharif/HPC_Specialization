/* _test_stress_10.c: stress test of upc_all_alloc. 

	Date created: October 15, 2002
	Date modified: November 4, 2002

	Function tested: upc_all_alloc

	Description:
	- Stress test upc_all_alloc by calling the function numerous times. The number
	  of times called is limited by the 8MB of memory pool allocated for 
	  each thread.
	- Each thread collectively performs allocation of CONST number of arrays, each
	  with size of SIZE.
	- Some of these allocated arrays is used to verify that they exist and that
	  the pointers returned are valid.
	- Thread 0 performs error checking at end.

	Platform Tested         No. Proc        Date Tested             Success
	UPC0			2,4		October 16, 2002	Yes
	UPC0 (all types)	4		October 28, 2002	Yes
	UPC0 (all types)	4		November 6, 2002	Yes
	CSE0 (all types)	2,4,8,12	November 14, 2002	Yes
	LION (all types)	2,4,8,16,32	November 18, 2002	Yes
	UPC0 (all types)	2,5K		December 3, 2002	Yes
	
	Bugs Found:

	Note:
	[10/16/2002] Try to use CONST > 1000 for an effective stress testing 
*/

#include <upc.h>
#include <stdio.h>
#include <string.h>

//#define VERBOSE0
#define DTYPE DATA 
#define SIZE 5000 
#define CONST 100

shared DTYPE *ptr[CONST]; 

int main (void)
{
	int i, error=0;
		
	for (i = 0; i < CONST; i++) 
		ptr[i] = upc_all_alloc(SIZE, sizeof(DTYPE));
	
	upc_forall(i = 0; i < SIZE; i++; i) {
		ptr[CONST-10][i] = (DTYPE)(i);
		ptr[CONST-100][i] = (DTYPE)(ptr[CONST-10][i]);
	}

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++)  {
#ifdef VERBOSE0
			printf("ptr[%d][%d] = %d, ptr[%d][%d] = %d\n", CONST-10, i, ptr[CONST-10][i],
				CONST-100, i, ptr[CONST-100][i]);
#endif	
			if ((ptr[CONST-10][i] != (DTYPE)(i)) || (ptr[CONST-100][i] != (DTYPE)(i)))
				error = 1;
		}

		if (error)
			printf("Error: test_stress_10.c failed! [th=%d, error=%d, DATA]\n", THREADS, error);
		else
			printf("Success: test_stress_10.c passed! [th=%d, error=%d, DATA]\n", THREADS, error);
	}

	return (error);
}


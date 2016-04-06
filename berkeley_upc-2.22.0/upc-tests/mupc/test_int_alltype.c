/* _test_int_alltype.c: a more complex test case that integrates the different data types. (X)

        Date created : October 22, 2002
        Date modified: November 4, 2002

        Function tested: All gets and puts functions, upc_local_alloc, upc_memcpy,
			 upc_memset. 

        Description:
	- This program tries to integrate all the different data types, this includes
	  char, short, long, int, float, and double. 
	- 6 arrays of all data types are allocated using upc_local_alloc on thread 0.
	- The allocated arrays are then initialized first with upc_memset, then given
	  some values. 
	- Each thread then copies the arrays from thread 0 into their own arrays.
	- Error checking is performed at end.
	
        Platform Tested         No. Proc        Date Tested             Success
	CSE0			2		10/22/2002		No
	UPC0			2,4		10/23/2002		Yes
	UPC0			4		11/04/2002		Yes
	CSE0 			2,4,8,16	11/09/2002		No
	CSE0 			2		11/16/2002		No
	LION			2		11/18/2002		No
	UPC0			2		12/03/2002		No

        Bugs Found:
	[10/22/2002] For n=2, on CSE0, the elements in some of the arrays are not 
		     properly initialized.
	[11/09/2002] Test case failed for n=2,4,8,16.
	[11/16/2002] Bug found on 11/09/2002 not fixed.
	[11/19/2002[ On lionel, test case failed for n=2. Error message as follows:
		MPI process rank 0 (n0, p29473) caught a SIGSEGV in MPI_Test.
	[12/03/2002] On upc0, test case failed for n=2, S=3.2K. Cause of bug is
		     probably the upc_memput() function.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define SIZE 3200

#ifdef sgi
  /* IRIX linker has a predefined symbol called fdata */
  #define fdata fdata_uniqname
#endif

shared [] char   *shared cdata[THREADS];
shared [] short  *shared sdata[THREADS];
shared [] long   *shared ldata[THREADS];
shared [] int    *shared idata[THREADS];
shared [] float  *shared fdata[THREADS]; 
shared [] double *shared ddata[THREADS];

shared int err[THREADS];

int main (void)
{
	int i, j, error=0;
	err[MYTHREAD] = 0;

	/* Huge allocation of memory, and initialization */
	if (MYTHREAD == 0) {
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
		cdata[MYTHREAD] = upc_alloc (SIZE * sizeof(char));
		sdata[MYTHREAD] = upc_alloc (SIZE * sizeof(short));
		ldata[MYTHREAD] = upc_alloc (SIZE * sizeof(long));
		idata[MYTHREAD] = upc_alloc (SIZE * sizeof(int));
		fdata[MYTHREAD] = upc_alloc (SIZE * sizeof(float));
		ddata[MYTHREAD] = upc_alloc (SIZE * sizeof(double));	
#else   
		cdata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(char));
		sdata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(short));
		ldata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(long));
		idata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(int));
		fdata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(float));
		ddata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(double));	
#endif
	
		upc_memset (cdata[MYTHREAD], 0, SIZE*sizeof(char));
		upc_memset (sdata[MYTHREAD], 0, SIZE*sizeof(short));
		upc_memset (ldata[MYTHREAD], 0, SIZE*sizeof(long));
		upc_memset (idata[MYTHREAD], 0, SIZE*sizeof(int));
		upc_memset (fdata[MYTHREAD], 0, SIZE*sizeof(float));
		upc_memset (ddata[MYTHREAD], 0, SIZE*sizeof(double));

		for (i = 0; i < SIZE; i++) {
			cdata[MYTHREAD][i] = 2;
			sdata[MYTHREAD][i] = (4*i)-2;
			ldata[MYTHREAD][i] = (6*i);
			idata[MYTHREAD][i] = i;
			fdata[MYTHREAD][i] = 0.1 * i;
			ddata[MYTHREAD][i] = 1.1 * i;
		}
/*	
		for (i = 0; i < SIZE; i++) {
			printf("cdata[%d][%d]=%d \t\t", MYTHREAD, i, cdata[MYTHREAD][i]); 
			if (((i % 4) == 0) && (i > 0))
				printf("\n");
		}
		printf("\n\n");
	
		for (i = 0; i < SIZE; i++) {
			printf("sdata[%d][%d]=%d \t\t", MYTHREAD, i, sdata[MYTHREAD][i]); 
			if (((i % 4) == 0) && (i > 0))
				printf("\n");
		}
		printf("\n\n");

		for (i = 0; i < SIZE; i++) {
			printf("ldata[%d][%d]=%d \t\t", MYTHREAD, i, ldata[MYTHREAD][i]); 
			if (((i % 4) == 0) && (i > 0))
				printf("\n");
		}
		printf("\n\n");
		
		for (i = 0; i < SIZE; i++) {
			printf("idata[%d][%d]=%d \t\t", MYTHREAD, i, idata[MYTHREAD][i]); 
			if (((i % 4) == 0) && (i > 0))
				printf("\n");
		}
		printf("\n\n");

		for (i = 0; i < SIZE; i++) {
			printf("fdata[%d][%d]=%3.2f \t", MYTHREAD, i, fdata[MYTHREAD][i]); 
			if (((i % 4) == 0) && (i > 0))
				printf("\n");
		}
		printf("\ni\n");

		for (i = 0; i < SIZE; i++) {
			printf("ddata[%d][%d]=%3.2f \t", MYTHREAD, i, ddata[MYTHREAD][i]); 
			if (((i % 4) == 0) && (i > 0))
				printf("\n");
		}
		printf("\n\n");
*/
	}
	else {
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
		cdata[MYTHREAD] = upc_alloc (SIZE * sizeof(char));
		sdata[MYTHREAD] = upc_alloc (SIZE * sizeof(short));
		ldata[MYTHREAD] = upc_alloc (SIZE * sizeof(long));
		idata[MYTHREAD] = upc_alloc (SIZE * sizeof(int));
		fdata[MYTHREAD] = upc_alloc (SIZE * sizeof(float));
		ddata[MYTHREAD] = upc_alloc (SIZE * sizeof(double));	
#else   
		cdata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(char));
		sdata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(short));
		ldata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(long));
		idata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(int));
		fdata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(float));
		ddata[MYTHREAD] = upc_local_alloc (SIZE, sizeof(double));	
#endif
	
		upc_memset (cdata[MYTHREAD], 0, SIZE*sizeof(char));
		upc_memset (sdata[MYTHREAD], 0, SIZE*sizeof(short));
		upc_memset (ldata[MYTHREAD], 0, SIZE*sizeof(long));
		upc_memset (idata[MYTHREAD], 0, SIZE*sizeof(int));
		upc_memset (fdata[MYTHREAD], 0, SIZE*sizeof(float));
		upc_memset (ddata[MYTHREAD], 0, SIZE*sizeof(double));
	}
	
	upc_barrier;
      if(MYTHREAD != 0) {		
	upc_memcpy (cdata[MYTHREAD], cdata[0], SIZE*sizeof(char));
	upc_memcpy (sdata[MYTHREAD], sdata[0], SIZE*sizeof(short));
	upc_memcpy (ldata[MYTHREAD], ldata[0], SIZE*sizeof(long));
	upc_memcpy (idata[MYTHREAD], idata[0], SIZE*sizeof(int));
	upc_memcpy (fdata[MYTHREAD], fdata[0], SIZE*sizeof(float));
	upc_memcpy (ddata[MYTHREAD], ddata[0], SIZE*sizeof(double));
     }
#ifdef VERBOSE0
	for (j = 0; j < THREADS; j++) {
		if (MYTHREAD == j) {
			for (i = 0; i < SIZE; i++) {
				printf("cdata[%d][%d]=%d \t\t", MYTHREAD, i, cdata[MYTHREAD][i]); 
				if (((i % 4) == 0) && (i > 0))
					printf("\n");
			}
			printf("\n\n");
		}
		upc_barrier;
	}

	for (j = 0; j < THREADS; j++) {
		if (MYTHREAD == j) {
			for (i = 0; i < SIZE; i++) {
				printf("sdata[%d][%d]=%d \t\t", MYTHREAD, i, sdata[MYTHREAD][i]); 
				if (((i % 4) == 0) && (i > 0))
					printf("\n");
			}
			printf("\n\n");
		}
		upc_barrier;
	}

	
	for (j = 0; j < THREADS; j++) {
		if (MYTHREAD == j) {
			for (i = 0; i < SIZE; i++) {
				printf("ldata[%d][%d]=%d \t\t", MYTHREAD, i, ldata[MYTHREAD][i]); 
				if (((i % 4) == 0) && (i > 0))
					printf("\n");
			}
			printf("\n\n");
		}
		upc_barrier;
	}

	for (j = 0; j < THREADS; j++) {
		if (MYTHREAD == j) {
			for (i = 0; i < SIZE; i++) {
				printf("idata[%d][%d]=%d \t\t", MYTHREAD, i, idata[MYTHREAD][i]); 
				if (((i % 4) == 0) && (i > 0))
					printf("\n");
			}
			printf("\n\n");
		}
		upc_barrier;
	}
	
	for (j = 0; j < THREADS; j++) {
		if (MYTHREAD == j) {
			for (i = 0; i < SIZE; i++)  {
				printf("fdata[%d][%d]=%3.20f \t", MYTHREAD, i, fdata[MYTHREAD][i]); 
				if (((i % 4) == 0) && (i > 0))
					printf("\n");
			}
			printf("\n\n");
		}
		upc_barrier;
	}
	
	for (j = 0; j < THREADS; j++) {
		if (MYTHREAD == j) {
			for (i = 0; i < SIZE; i++) {
				printf("ddata[%d][%d]=%3.2f \t", MYTHREAD, i, ddata[MYTHREAD][i]); 
				if (((i % 4) == 0) && (i > 0))
					printf("\n");
			}
			printf("\n\n");
		}
		upc_barrier;
	}
#endif

	/* Each thread performs error checking and save result in err[MYTHREAD] */
	for (i = 0; i < SIZE; i++) {
	      float volatile f; double volatile d; /* see bug 168 */
		if (cdata[MYTHREAD][i] != 2) {
			err[MYTHREAD] = 1;
			break;
		}

		if (sdata[MYTHREAD][i] != ((4*i)-2)) {
			err[MYTHREAD] = 2;
			break;
		}

		if (ldata[MYTHREAD][i] != (6*i)) {
			err[MYTHREAD] = 3;
			break;
		}
	
		if (idata[MYTHREAD][i] != i) {
			err[MYTHREAD] = 4;
			break;
		}
		
		f = (float)(0.1*i);		
		if (fdata[MYTHREAD][i] != f) { 
			err[MYTHREAD] = 5;
			break;
		}

		d = (double)(1.1*i);
		if (ddata[MYTHREAD][i] != d) { 
			err[MYTHREAD] = 6;
			break;
		}
	}

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < THREADS; i++) {
#ifdef VERBOSE0
			printf("err[%d] = %d\n", i, err[MYTHREAD]);
#endif
			error += err[i];
		}

		if (error)
                        printf("Error: test_int_alltype.c failed! [th=%d, error=%d]\n", THREADS, error);
                else
                        printf("Success: test_int_alltype.c passed! [th=%d, error=%d]\n", THREADS, error);
	}

	return (error);
}

/* _test_int_allfunc.c: a test case that includes all the functions implemented in MuPC. (X) 

        Date created : October 23, 2002
        Date modified: November 4, 2002	 

        Function tested: All functions.

        Description:
	- This program incorporates all the functions currently implemented in MuPC.
	- This is not an application program, but simply a test program that tries
	  to make use of all functions and generate lots of communications between
	  threads. This test case is an extension of test_alltype.c. 
	- Thread 0 allocates memory for 6 arrays of diff data types using upc_local_alloc.
	- Thread 0 initializes the contents of the 6 arrays with upc_memset. This is not
	  necessary, but we incorporate it anyway.
	- Thread 0 fills in the 6 arrays with some values. 
	- Each thread copies the contents of the 6 arrays from thread 0 into its own.  
        
	Platform Tested         No. Proc        Date Tested             Success
	UPC0			2,4		November 4, 2002	Yes	
	CSE0 			2,4,8,16	November 9, 2002	No
	CSE0 			2		November 16, 2002	No
	LION			2		November 19, 2002	No
	UPC0			2		December 3, 2002	No
	
        Bugs Found:
	[11/09/2002] On cse0, Test case failed for n=2,4,8,16. Since test_int_alltype.c failed,
		     this test case would probably failed too since it builds upon
		     test_int_alltype.c
		Error: test_int_allfunc.c failed! [th=2, error=1]

	[11/16/2002] Previous bug has not been fixed.
	[11/19/2002] On lionel, test case failed for n=2. Error message as follows:
		MPI process rank 0 (n0, p29427) caught a SIGSEGV in MPI_Isend.
	[12/03/2002] On upc0, test case failed for n=2, S=3.2K. Problem might lie in the upc_memput
		     function.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0
#define SIZE 3200

#ifdef sgi
  /* IRIX linker has a predefined symbol called fdata */
  #define fdata fdata_uniqname
#endif

upc_lock_t *lock_1;
upc_lock_t *shared lock_2;

shared int *totalCopy;
shared int *shared totalCopy2;

shared [] char   *shared cdata[THREADS];	
shared [] short  *shared sdata[THREADS];
shared [] long   *shared ldata[THREADS];
shared [] int    *shared idata[THREADS];
shared [] float  *shared fdata[THREADS]; 
shared [] double *shared ddata[THREADS];

shared int err[THREADS];

char   lcdata[SIZE];	/* Local char array */
short  lsdata[SIZE];	/* Local short array */
long   lldata[SIZE];	/* Local long array */
int    lidata[SIZE];	/* Local integer array */
float  lfdata[SIZE];	/* Local float array */
double lddata[SIZE];	/* Local double array */

int main (void)
{
	int i, j, temp, error=0, check=0;
	err[MYTHREAD] = 0;

	/* Lock allocation and initialization */
	lock_1 = upc_all_lock_alloc ();
#if 0
	upc_lock_init(lock_1);	
#endif

	/* Huge allocation of memory, and initialization */
	totalCopy = upc_all_alloc (SIZE, sizeof(int));
#if 0
/* DOB: this is completely broken */
	upc_memset (totalCopy, 0, SIZE*sizeof(int));
#endif
        upc_memset(totalCopy+MYTHREAD, 0, 
          upc_affinitysize(SIZE*sizeof(int), sizeof(int), MYTHREAD));
	
	if (MYTHREAD == 0) {
          int i;
		
		/* Allocate 2nd lock non-collectively */		
		lock_2 = upc_global_lock_alloc();
#if 0
		upc_lock_init(lock_2);
#endif

		/* Allocate shared memory non-collectively */
		totalCopy2 = upc_global_alloc(SIZE, sizeof(int));
#if 0 
/* DOB: also completely broken */
		upc_memset (totalCopy2, 0, SIZE*sizeof(int));
#endif
                for (i=0;i<THREADS;i++) {
                  upc_memset(totalCopy2+i, 0, 
                      upc_affinitysize(SIZE*sizeof(int), sizeof(int), i));
                }

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
	
	upc_barrier 1;
		
	upc_memcpy (cdata[MYTHREAD], cdata[0], SIZE*sizeof(char));
	upc_memcpy (sdata[MYTHREAD], sdata[0], SIZE*sizeof(short));
	upc_memcpy (ldata[MYTHREAD], ldata[0], SIZE*sizeof(long));
	upc_memcpy (idata[MYTHREAD], idata[0], SIZE*sizeof(int));
	upc_memcpy (fdata[MYTHREAD], fdata[0], SIZE*sizeof(float));
	upc_memcpy (ddata[MYTHREAD], ddata[0], SIZE*sizeof(double));

	upc_notify 1;
	upc_wait 1;

	/* Copy values from shared array of (MYTHREAD+1)%THREAD to local array. */
	upc_memget (lcdata, cdata[(MYTHREAD+1)%THREADS], SIZE*sizeof(char));
	upc_memget (lsdata, sdata[(MYTHREAD+1)%THREADS], SIZE*sizeof(short));
	upc_memget (lldata, ldata[(MYTHREAD+1)%THREADS], SIZE*sizeof(long));
	upc_memget (lidata, idata[(MYTHREAD+1)%THREADS], SIZE*sizeof(int));
	upc_memget (lfdata, fdata[(MYTHREAD+1)%THREADS], SIZE*sizeof(float));
	upc_memget (lddata, ddata[(MYTHREAD+1)%THREADS], SIZE*sizeof(double));

	/* For all i, sum up i's of all 6 arrays, and store them in integer array. */
	for (i = 0; i < SIZE; i++) 
		lidata[i] += (lcdata[i] + lsdata[i] + lldata[i] + lfdata[i] + lddata[i]);

/*	if (MYTHREAD == 0)
		for (i = 0; i < SIZE; i++)
			printf("lidata[%d] = %d\n", i, lidata[i]);
*/
	upc_barrier 2;

	/* Put the updated value of integer array to MYTHREAD-1. */
	if (MYTHREAD == 0) 
		upc_memput (idata[THREADS-1], lidata, SIZE*sizeof(int));
	else
		upc_memput (idata[MYTHREAD-1], lidata, SIZE*sizeof(int));
/*
	for (j = 0; j < THREADS; j++) {
		upc_barrier;
		if (MYTHREAD == j) 
			for (i = 0; i < SIZE; i++)
				printf("idata[%d][%d] = %d\n", j, i, idata[j][i]);
	}
*/
	
	upc_barrier 3;
	
	/* All threads add the value in their integer array to total array. */
	upc_lock (lock_1);
	for (i = 0; i < SIZE; i++)
		totalCopy[i] += idata[MYTHREAD][i];	
	upc_unlock (lock_1);

	while (!upc_lock_attempt(lock_2));
	for (i = 0; i < SIZE; i++) 	
		totalCopy2[i] += idata[MYTHREAD][i];	
	upc_unlock (lock_2);

	upc_notify 2;
	upc_wait 2;

	if (MYTHREAD == 0) {	
		for (i = 0; i < SIZE; i++) {
#ifdef VERBOSE0
			printf("totalCopy[%d] = %d, totalCopy2[%d] = %d\n", i, totalCopy[i], i, totalCopy2[i]);
#endif
			if (totalCopy[i] != totalCopy2[i])
				++check;
		}
	}

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < SIZE; i++) {
#if 1 /* mimic original computation more closely to reduce compiler optimization problems */
			temp = i;
			temp += ((char)2 + (short)((4*i)-2) + (long)(6*i) + (float)(0.1*i) + (double)(1.1*i));
			temp *= THREADS;
#else
			temp = (int)(i + 2 + ((4*i)-2) + (6*i) + (float)(0.1*i) + (double)(1.1*i)) * THREADS; 
#endif
#ifdef VERBOSE0
			printf("(final) totalCopy[%d] = %d\n", i, totalCopy[i]);
			printf("temp = %d\n", temp);
#endif
			if (totalCopy[i] != temp)
				error = 1;
		}

		if (check) {
			error = 1;
		}

		if (error)
                        printf("Error: test_int_allfunc.c failed! [th=%d, error=%d]\n", THREADS, error);
                else
                        printf("Success: test_int_allfunc.c passed! [th=%d, error=%d]\n", THREADS, error);
	}

	return (error);
} 

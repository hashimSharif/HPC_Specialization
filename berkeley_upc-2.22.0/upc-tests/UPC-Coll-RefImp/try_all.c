
/*****************************************************************************/
/*                                                                           */
/*  Copyright (c) 2004, Michigan Technological University                    */
/*  All rights reserved.                                                     */
/*                                                                           */ 
/*  Redistribution and use in source and binary forms, with or without       */
/*  modification, are permitted provided that the following conditions       */
/*  are met:                                                                 */
/*                                                                           */
/*  * Redistributions of source code must retain the above copyright         */
/*  notice, this list of conditions and the following disclaimer.            */
/*  * Redistributions in binary form must reproduce the above                */
/*  copyright notice, this list of conditions and the following              */
/*  disclaimer in the documentation and/or other materials provided          */
/*  with the distribution.                                                   */
/*  * Neither the name of the Michigan Technological University              */
/*  nor the names of its contributors may be used to endorse or promote      */
/*  products derived from this software without specific prior written       */
/*  permission.                                                              */
/*                                                                           */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS      */
/*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT        */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  */
/*  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER */
/*  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, */
/*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,      */
/*  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR       */
/*  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   */
/*  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     */
/*  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS       */
/*  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/*                                                                           */
/*        UPC collective function library, reference implementation          */
/*                                                                           */
/*   Steve Seidel, Dept. of Computer Science, Michigan Technological Univ.   */
/*   steve@mtu.edu                                        March 1, 2004      */
/*                                                                           */
/*****************************************************************************/

// Collectives exerciser
//
// This moves data through a sequence of collective operations and
// verifies that they come out OK on the other side.  All of the
// basic forms of the collective functions are used at least once.

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <upc_collective.h>

#define NELEMS		17
#define TYPE		int
#define SYNC_MODE	UPC_IN_ALLSYNC | UPC_OUT_ALLSYNC

// shared [NELEMS] TYPE		A[NELEMS];
shared [NELEMS] TYPE		*A;
shared [NELEMS] TYPE		B[NELEMS*THREADS];
// shared [NELEMS*THREADS] TYPE	C[THREADS][NELEMS*THREADS];
shared TYPE			*Cdata;
shared [] TYPE * shared		C[THREADS];
// shared [NELEMS*THREADS] TYPE	D[THREADS][NELEMS*THREADS];
shared TYPE			*Ddata;
shared [] TYPE * shared		D[THREADS];
shared [NELEMS] TYPE		E[NELEMS*THREADS];
shared [NELEMS] TYPE		F[NELEMS*THREADS];

// rand_perm is used to generate a permutation of integers 0..THREADS-1.
// Generate a sequence of random integers and label them with
// consecutive indices.  Sort the random integers and carry
// the indices along to create a permutation of indices.
// upc_all_sort() is used to sort the random integers.  The
// resulting permutation is used to test upc_all_perm().

typedef struct
{       int randm;
        int indx;
}rand_perm;

shared rand_perm scram[THREADS];
shared int       perm[THREADS];

// Comparison function used in call to upc_all_sort().

int scram_comp( shared void *x, shared void *y )
{
 	int x_val = (*((shared rand_perm *)x)).randm;
	int y_val = (*((shared rand_perm *)y)).randm;

	return x_val > y_val ? 1 : x_val < y_val ? -1 : 0;
}

int main(void)
{
	int nbytes = sizeof(TYPE);
	int i, j, k, n;
	TYPE sum;

	A = upc_all_alloc(NELEMS, sizeof(TYPE)*NELEMS);

// 1) Initialize A[i]=123321+i and B[i] = THREADS+i

	if ( MYTHREAD==0 )
		for (i=0; i<NELEMS; ++i)
			A[i] = 123321+i;

	for (i=0; i<NELEMS; ++i)
		B[MYTHREAD*NELEMS+i] = THREADS + i;

// 2) Broadcast A to B

	upc_all_broadcast( B, A, nbytes*NELEMS, SYNC_MODE );

// 3) Check that B[i]==123321+i

	for (i=0; i<NELEMS; ++i)
		if ( B[MYTHREAD*NELEMS+i] !=123321+i )
			printf("Thread %d: broadcast failure: B[%d]=%d\n",
				MYTHREAD, i, B[i] );

// 4) Re-initialize B[i] = i

	for (i=0; i<NELEMS; ++i)
		B[MYTHREAD*NELEMS+i] = MYTHREAD*NELEMS + i;

	Cdata = upc_all_alloc(THREADS*THREADS, NELEMS*sizeof(TYPE));
	C[MYTHREAD] = (shared [] TYPE *)&Cdata[MYTHREAD];
	Ddata = upc_all_alloc(THREADS*THREADS, NELEMS*sizeof(TYPE));
	D[MYTHREAD] = (shared [] TYPE *)&Ddata[MYTHREAD];
	upc_barrier;

	if ( MYTHREAD == 0 )
	{
		for (i=0; i<THREADS; ++i)
		{
			for (j=0; j<NELEMS*THREADS; ++j)
				C[i][j] = 123321;
		}
/*
		for (i=0; i<NELEMS*THREADS; ++i)
			printf("B[%d]=%d  ", i, B[i]);
		printf("\n\n");
*/
	}

// 5) Use gather_all to copy B to each row of C
	// (This is analogous to broadcasting B to the rows of C.)

	upc_all_gather_all ( Cdata, B, nbytes*NELEMS, SYNC_MODE );

// 6) Check that C[MYTHREAD][i]==i

	for (i=0; i<NELEMS*THREADS; ++i)
	{
		if ( C[MYTHREAD][i] != i )
			printf("Thread %d: gather_all failure: %d\n",
				MYTHREAD, C[MYTHREAD][i] );
	}

/*
	if ( MYTHREAD == 0 )
	{
		for (i=0; i<THREADS; ++i)
		{
			for (j=0; j<NELEMS*THREADS; ++j)
				printf("C[%d][%d]=%d ", i, j, C[i][j]);
			printf("\n");
		}
		printf("\n");
	}
*/

// 7) Multiply each element of C by 10 * MYTHREAD

	for (i=0; i<NELEMS*THREADS; ++i)
		C[MYTHREAD][i] += 10 * MYTHREAD;

	if ( MYTHREAD == 0 )
		for (i=0; i<THREADS; ++i)
			for (j=0; j<NELEMS*THREADS; ++j)
				D[i][j] = 123321;

// 8) Transpose C to D

	upc_all_exchange ( Ddata, Cdata, nbytes*NELEMS, SYNC_MODE );

/*
	if ( MYTHREAD == 0 )
	{
		for (i=0; i<THREADS; ++i)
		{
			for (j=0; j<NELEMS*THREADS; ++j)
				printf("D[%d][%d]=%d ", i, j, D[i][j]);
			printf("\n");
		}
		printf("\n");
	}
*/

	if ( MYTHREAD == 0 )
	{
	for (i=0; i<THREADS; ++i)
		for (j=0; j<THREADS; ++j)
			for (k=0; k<NELEMS; ++k)
			{
				n = j*NELEMS+k;
				if ( C[i][n] != D[n/NELEMS][i*NELEMS+k] )
				printf("Exchange failure:"
					" C[%d][%d]=%d != D[%d][%d] = %d\n",
					i, n, C[i][n],
					n/NELEMS, i*NELEMS+k, D[n/NELEMS][i*NELEMS+k] );
			}
	}

	upc_barrier;

//	Initialize D

	for (i=0; i<THREADS; ++i)
		for (j=0; j<NELEMS; ++j)
			D[MYTHREAD][i*NELEMS+j] = MYTHREAD*NELEMS*THREADS + i*NELEMS + j;
/*
	if ( MYTHREAD == 0 )
	{
		for (i=0; i<THREADS; ++i)
		{
			for (j=0; j<NELEMS*THREADS; ++j)
				printf("D[%d][%d]=%d ", i, j, D[i][j]);
			printf("\n");
		}
		printf("\n");
	}
*/

// 9) Add each row of D and write it to vector B.

	for (i=0; i<THREADS; ++i)
		upc_all_reduceI( &B[i], D[i], UPC_ADD,
			NELEMS*THREADS, NELEMS*THREADS, NULL, SYNC_MODE);
/*
	if ( MYTHREAD == 0 )
	{
		for (i=0; i<THREADS; ++i)
			printf("B[%d]=%d ", i, B[i]);
		printf("\n");
	}
*/

// 10) Check that B contains the correct sums

#if 0  // formula and actual sum can have different overflow behaviors -PHH 2009.09.25
	i = (MYTHREAD+1)*NELEMS*THREADS;
	j = i - NELEMS*THREADS;
	if ( B[MYTHREAD] != ((i*(i-1))/2) - ((j*(j-1))/2) )
		printf("Thread %d: reduce failure: %d \t %d\n",
			MYTHREAD, B[MYTHREAD], ((i*(i-1))/2) - ((j*(j-1))/2) );
#else
	sum = 0;
	for (i=0; i<NELEMS*THREADS; ++i)
		sum += D[MYTHREAD][i];
	if ( B[MYTHREAD] != sum )
		printf("Thread %d: reduce failure: %d \t %d\n",
			MYTHREAD, B[MYTHREAD], sum );
#endif

// 11) Do a few back-and-forth gather-scatters between B and the rows of C.

	for (k=0; k<THREADS/2; ++k)
	{
		upc_all_gather ( C[k], B, nbytes*NELEMS, SYNC_MODE );
		upc_all_scatter ( B, C[k], nbytes*NELEMS, SYNC_MODE );

// 12) Re-check that B contains the correct sums

#if 0 // as in #10, must validate against actual sum not the formula -PHH 2009.09.25
	i = (MYTHREAD+1)*NELEMS*THREADS;
	j = i - NELEMS*THREADS;
	if ( B[MYTHREAD] != ((i*(i-1))/2) - ((j*(j-1))/2) )
		printf("Thread %d: gather-scatter failure: %d\n",
			MYTHREAD, B[MYTHREAD] );
#else
	if ( B[MYTHREAD] != sum )
		printf("Thread %d: gather-scatter failure: %d\n",
			MYTHREAD, B[MYTHREAD] );
#endif
	}

	upc_barrier;

	// Throw away first random number.
	srand(42*MYTHREAD);
	B[MYTHREAD*NELEMS] = (int)rand();

	for (i=0; i<NELEMS; ++i)
		B[MYTHREAD*NELEMS+i] = (int)rand() % 53426;	
		

// 13) Prefix reduce B

	upc_all_prefix_reduceI ( E, B, UPC_ADD, NELEMS*THREADS, NELEMS,
				NULL, SYNC_MODE);

// 14) Check that E contains the correct prefixes

	if ( MYTHREAD==0 )
	{
		sum = 0;
		for(i=0; i<NELEMS*THREADS; i++)
		{
			sum += B[i];
			if ( E[i] != sum )
				printf("prefix reduce failure:"
					" B[%d]=%d  E[%d]=%d\n", i, B[i], i, E[i] );
		}
	}

// 15) Generate a vector of random numbers and an index for each one.

	if ( MYTHREAD == 0 )
	{
		for(i=0; i<THREADS; i++)
		{
			scram[i].randm = (int)rand();
			scram[i].indx = i;
		}
	}

// 16) Sort the random numbers while carrying the indices along.

	upc_all_sort ( scram, sizeof(rand_perm), THREADS, 1, scram_comp, SYNC_MODE );

// 17) Check that the sort was done correctly.

	if ( MYTHREAD > 0 )
		if ( scram[MYTHREAD-1].randm > scram[MYTHREAD].randm )
			printf("Thread %d: sort failure: %d > %d\n",
				MYTHREAD, scram[MYTHREAD-1].randm,
				scram[MYTHREAD].randm );

// 18) The scrambled indices are a permutation of 0..THREADS-1.

	if ( MYTHREAD == 0 )
		for (i=0; i<THREADS; ++i)
		{
			perm[i] = scram[i].indx;
		}

// 19) Use that permutation to permute E to F

	upc_all_permute ( F, E, perm, nbytes*NELEMS, SYNC_MODE );

// 20) Check that F contains the correct values.

	for(i=0; i<NELEMS; i++)
		if ( E[MYTHREAD*NELEMS+i] != F[perm[MYTHREAD]*NELEMS+i] )
			printf("Thread %d: permutation failure: %d\n",
				MYTHREAD, F[MYTHREAD*NELEMS+i] );

	if ( MYTHREAD == 0 )
		printf("tryall: If this is the only line of output, then all is well.\n");
}

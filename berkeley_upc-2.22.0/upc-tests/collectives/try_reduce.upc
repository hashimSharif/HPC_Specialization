
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

#include <upc.h>
#include <upc_collective.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE	9
#define FULLSIZE	SIZE*THREADS
#define _UPC_RED_T int

#ifdef TEST_BLK_SIZE
#define blk_size	TEST_BLK_SIZE
#else
#define blk_size	4
#endif

shared [blk_size] _UPC_RED_T A[FULLSIZE];
shared [blk_size] _UPC_RED_T B[FULLSIZE];
shared [blk_size] _UPC_RED_T OrigA[FULLSIZE];

// #define blk_size	(sizeof(A)/upc_elemsizeof(A)+THREADS-1)/THREADS

_UPC_RED_T addneg( _UPC_RED_T i, _UPC_RED_T j)
{
	if ( i > 0 )
		if ( j > 0 )
			return -i - j;
		else
			return -i + j;
	else
		if ( j > 0 )
			return i - j;
		else
			return i + j;
}

int main(void)
{
 	int i, j, nelems;
 	int offsetA, offsetB;
	_UPC_RED_T sum;
	int failure;

	if ( MYTHREAD == 0 )
		{
         		// Throw away first random number.
			srand(42);
			OrigA[0] = (int)rand();

			for(i=0; i<FULLSIZE; i++)
			{
				sum =  (int)rand();
                 		OrigA[i] = sum % 32768;
			}
		}

	upc_barrier;
	upc_forall(i=0; i<FULLSIZE; i++; &A[i])
		A[i]= (_UPC_RED_T) OrigA[i];
	upc_barrier;

	failure = 0;
	nelems = 1;
	offsetA = 0;
	// nelems = 2;
	// offsetA = 11;

	while ( nelems+offsetA <= FULLSIZE )
	{
		// offsetB = 14;
		offsetB = 0;

		while ( nelems+offsetB <= FULLSIZE )
		{
			upc_barrier;
			upc_forall (i=0; i<FULLSIZE; ++i; &B[i])
				B[i] = (_UPC_RED_T) 123321;

/* Don't print debugging output
			if (MYTHREAD == 0)
				printf("offsetA: %d (%d) \t offsetB: %d (%d) \t nelems: %d\n",
					offsetA, (int)upc_phaseof((shared void *)&(A[offsetA])),
					offsetB, (int)upc_phaseof((shared void *)&(B[offsetB])),
					nelems);
*/

			upc_all_reduceI( &B[offsetB], &A[offsetA],
				UPC_ADD, nelems, blk_size, NULL, 0 );

			if (MYTHREAD == 0)
			{
				sum = (_UPC_RED_T) 0;
				for (i=offsetA; i<nelems+offsetA; ++i)
				{
					sum += A[i];
				}
				if (B[offsetB] != sum)
				{
					failure = 1;
				}
				if ( failure )
				{
					printf("try_reduce: failure: A in main: ");
					sum = (_UPC_RED_T) 0;
					for (i=offsetA; i<nelems+offsetA; ++i)
					{
						sum += A[i];
						printf("%d   ", A[i]);
					}
					printf("\ntry_reduce: B and sum in main: %d %d\n", B[offsetB], sum);
				}

				if (failure)
					upc_global_exit(1);
			}
			++offsetB;
	
		}	// B loop

		++offsetA;
		if ( offsetA+nelems > FULLSIZE )
		{
			offsetA = 0;
			++nelems;
		}

	}	// A loop

	if ( MYTHREAD == 0 )
	{
		for (i=0; i<FULLSIZE; i++)
			if ( A[i] != OrigA[i] )
			{
				printf("tryreduce: Source array is damaged.\n");
				break;
			}
		printf("tryreduce: If this is the only line of output, then all is well.\n");
	}

}


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
#define _UPC_RED_T	double

#ifdef TEST_BLK_SIZE
#define blk_size	TEST_BLK_SIZE
#else
#define blk_size	4
#endif

shared [blk_size] _UPC_RED_T A[FULLSIZE];
shared [blk_size] _UPC_RED_T B[FULLSIZE];
shared [blk_size] _UPC_RED_T PermA[FULLSIZE];

// #define blk_size	(sizeof(A)/upc_elemsizeof(A)+THREADS-1)/THREADS

_UPC_RED_T add( _UPC_RED_T x, _UPC_RED_T y)
{
	return x+y;
}

int main(void)
{
 	int i, j, nelems;
 	int offsetA, offsetB, offsetL;
	_UPC_RED_T sum;
	int failure;

	if ( MYTHREAD == 0 )
		{
         		// Throw away first random number.
			srand(42);
			PermA[0] = (_UPC_RED_T)(int)rand();

			for(i=0; i<FULLSIZE; i++)
			{
				sum =  (_UPC_RED_T)(int)rand();
                 		PermA[i] =(_UPC_RED_T)((int)sum % 32768);
			}
		}

	upc_barrier;
	upc_forall(i=0; i<FULLSIZE; i++; &A[i])
		A[i]= (_UPC_RED_T) PermA[i];
	upc_barrier;

	failure = 0;
	nelems = 1;
	offsetA = 0;

	while ( nelems+offsetA <= FULLSIZE )
	{
#ifdef __BERKELEY_UPC_RUNTIME__
		// Berkeley UPC runtime supports different affinity for 'src' and 'dst'.
		// So, we change the test a bit to exercise unaligned cases.
		// However, the phases must remain the same.
		offsetB = upc_phaseof((shared void *)&(A[offsetA]));
#else
		// Spec compilance only requires supporting input such that
		//    (upc_threadof(src) == upc_threadof(dst)) &&
		//     (upc_phaseof(src) == upc_phaseof(dst))
		offsetB = blk_size ? offsetA % (THREADS * blk_size) : 0;
#endif

		while ( nelems+offsetB <= FULLSIZE )
		{
			upc_barrier;
			upc_forall(i=0; i<FULLSIZE; i++; &B[i])
				B[i] = (_UPC_RED_T) 123321;

/* Don't print debugging output
			if (MYTHREAD == 0)
				printf("offsetA: %d (%d) \t offsetB: %d (%d) \t nelems: %d\n",
					offsetA, (int)upc_phaseof((shared void *)&(A[offsetA])),
					offsetB, (int)upc_phaseof((shared void *)&(B[offsetB])),
					nelems);
*/
			upc_all_prefix_reduceD( &B[offsetB], &A[offsetA],
				UPC_FUNC, nelems, blk_size, add, 0 );

			if (MYTHREAD == 0)
			{
				sum = (_UPC_RED_T) 0;
				for (i=offsetA, j=offsetB; i<offsetA+nelems; ++i, ++j)
				{
					sum += A[i];
					if (B[j] != sum)
					{
						failure = 1;
						break;
					}
				}

				if ( failure )
				{
					printf("try_prefix: failure: Prefixes are ");
					sum = (_UPC_RED_T) 0;
					for (i=offsetA, j=offsetB; i<offsetA+nelems; ++i, ++j)
					{
						sum += A[i];
						// printf("A[%d]=%d \t sum=%d \t B[%d]=%d \n",
							// i, A[i], sum, j, B[j]);
						if (B[j] != sum)
							printf("\n Error at offset %d:"
								"  %f vs. %f.", i, B[j], sum);
						else
							printf(" %f  ", B[j]);
					}
					printf("\n\n");
				}

				if (failure)
					upc_global_exit(1);
			}
#if blk_size == 0
			// The threads and phases of A and B are always 0
			offsetB += 1;
#elif defined(__BERKELEY_UPC_RUNTIME__)
			// The phases of A and B must remain the same.
			offsetB += blk_size;
#else
			// The threads and phases of A and B must remain the same.
			offsetB += THREADS * blk_size;
#endif
	
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
			if ( A[i] != PermA[i] )
			{
				printf("tryprefix: Source array is damaged.\n");
				break;
			}
		printf("tryprefix: If this is the only line of output, then all is well.\n");
	}
}

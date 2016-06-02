
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

// NOTE: Contrary to the spec, this implementation assumes that the phases
//	 of the src and dst arguments agree.

/* The true set of function names is in upc_all_collectives.c */
/* void upc_all_prefix_reduce_GENERIC */
				( shared void *dst,
				shared const void *src,
				upc_op_t op,
				size_t nelems,
				size_t blk_size,
				_UPC_RED_T (*func)(_UPC_RED_T, _UPC_RED_T),
				upc_flag_t sync_mode )
{

/*
	This prefix reduce algorithm is linear in the number of array elements/THREADS.
	The prefixes are calculated in a loop that iterates as many times+1
	as the src array wraps from thread THREADS-1 to thread 0.  The cost of
	computing prefixes of an array with a small block size (that wraps many
	times) is likely to be much higher than the cost of computing prefixes
	of an array of the same size but with block size [*].  This code favors
	the affinity of the src array.  Thus, if the affinities of the src and dst
	arrays are different, there will many off-thread references (i.e. writes,
	that is, "pushes") to the dst array.

	Each iteration contains two internal barriers and about THREADS off-thread
	reads and writes in the best case.  The pref pointer switches between the
	first and second halves of the array so that one thread can be working
	an iteration ahead (or behind) of another without interference.  Otherwise,
	an additional barrier would be needed.

	Allocate pref[2*THREADS]
	Determine the number of times the array "wraps".
	Compute the offset address and number of local elements for 1st pass.
	for (w=0; w<=wraps; ++w)
		Initialize local prefix "sum"
		Compute local prefixes
		if (MYTHREAD < THREADS-1)
			Write rightmost local prefix to pref[MYTHREAD+1]
		barrier
		if (MYTHREAD == THREADS-1)
			if (w>0)
				pref[0] = last "sum" from previous iteration
			Compute prefixes in pref[]
		barrier
		"Add" pref[MYTHREAD] to each prefix computed at top of loop
		if (wraps > w)
			Swap pointer to first or last half of pref[]
			Increment offset address and compute n_local for next pass
	barrier
	free pref[]

	Thread THREADS-1 was chosen to handle pref[] simply to avoid giving
	thread 0 more work.  "push" and "pull" versions of this collective
	function are not distinguished.  As it stands, the writes to pref[]
	are "pushes" and the reads from pref[] are "pulls".  If the affinities
	of src and dst differ, this function can be regarded as a "push"
	because the affinity of the src array is favored.
*/

	int	// constant over all iterations
		src_thr,	// source thread
		dst_thr,	// destination thread
		phase,		// phase of src and dst array must be identical
		wraps,		// number of times src array properly wraps around

		// first iteration only
		leaders,	// number of vacant positions to left of src

		// modified on each iteration
		i, j, k,	// addressing indices
		w,		// main loop index for "wraps"
		src_offset,	// offset from src of first local element
		dst_offset,	// offset from dst of first element
		first_thr,	// first thread that contains local src elements
		last_thr,	// last thread that contains local src elements
		row_elems,	// number of src elements in the row processed
		n_local,	// number of local src elements
		rem_elems;	// number of elements remaining to be processed

	shared	_UPC_RED_T 	*pref;	// shared array to hold local prefixes

 	if ( !upc_coll_init_flag )
		upc_coll_init();

#ifdef _UPC_COLL_CHECK_ARGS
	upc_coll_err( dst, src, NULL, 0, sync_mode, blk_size, nelems, op, UPC_PRED);
#endif

      	// Synchronize using barriers in the cases of MYSYNC and ALLSYNC.

	if ( UPC_IN_MYSYNC & sync_mode || !(UPC_IN_NOSYNC & sync_mode) )

		upc_barrier;

	// This array is used to share local prefixes.

	pref = upc_all_alloc(2*THREADS, sizeof(_UPC_RED_T));

	src_thr = upc_threadof((shared void *)src);
	phase = upc_phaseof((shared void *)src);
	dst_thr = upc_threadof((shared void *)dst);

	// Total number of elements remaining to be processed.

	rem_elems = nelems;

	// Determine offsets in all threads as if there really are elements in all
	// threads.  Addresses will be src + offset.  (If MYTHREAD < src_thr, MYTHREAD
	// has no elements for this iteration but it might have elements for next
	// iteration.)  Note: offset is sometimes negative because src is addressed
	// here as if its block size is 1.  Similar comments apply to dst.

	if ( MYTHREAD != src_thr )
	{
		src_offset = MYTHREAD - src_thr - phase*THREADS;
		dst_offset = src_offset;

		// The following arithmetic is undocumentable.
		if ( MYTHREAD >= THREADS + src_thr - dst_thr)
			dst_offset += (blk_size-1)*THREADS;
		if ( MYTHREAD < src_thr - dst_thr)
			dst_offset -= (blk_size-1)*THREADS;
	}
	else
	{
		src_offset = 0;
		dst_offset = 0;
	}

	// first_thr .. last_thr is range of threads that contains src elements of current row

	first_thr = src_thr;

	// Compute n_local, the number of src elements local to this thread,

	if ( blk_size == 0 || phase+nelems <= blk_size )
	{	// All elements are on the src_thr.

		leaders = 0;	// (Not needed here.  Initialize for debugging output.)
		row_elems = nelems;
		wraps = 0;

		if ( MYTHREAD == src_thr )
			n_local = nelems;
		else
			n_local = 0;
		last_thr = src_thr;
	}
	else	// At least two threads contain elements.
	{
		// Detemine how many elements are in the first row.
		leaders = src_thr*blk_size + phase;
		if ( (leaders + nelems) / (blk_size*THREADS) > 0 )	//first row is "full"
			row_elems = blk_size*THREADS - leaders;
		else
			row_elems = nelems;

		// Determine how many rows wrap back around to thread 0.

		wraps = (leaders + nelems - 1) / (blk_size*THREADS);

		// Assume most likely situation; modify if necessary

		last_thr = THREADS - 1;
		n_local = blk_size;

		if ( MYTHREAD == src_thr )
			n_local = blk_size - phase;
		if ( MYTHREAD < src_thr )
			n_local = 0;
		if ( leaders + nelems < blk_size*THREADS )
		{
			// There are not enough elements to fill the
			// end of the first row.  Assert: wraps = 0
			last_thr = (leaders+nelems-1) / blk_size;
			if ( (MYTHREAD == last_thr) && (last_thr > src_thr))
				n_local = (leaders+nelems) - (MYTHREAD*blk_size);
			else
				if ( MYTHREAD > last_thr )
					n_local = 0;
		}
	}


//////// Main loop.

	for ( w=0; w<=wraps; ++w )
	{

		if (n_local > 0)
		{
			// Initialize first element.

			*((shared _UPC_RED_T *)dst + dst_offset)
				=  *((shared const _UPC_RED_T *)src + src_offset);

			// Compute local prefixes.

			switch (op)
			{
			case UPC_ADD:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					*((shared _UPC_RED_T *)dst + j)
						= *((shared const _UPC_RED_T *)dst + i)
						+ *((shared const _UPC_RED_T *)src + k);
				}
				break;
			case UPC_MULT:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					*((shared _UPC_RED_T *)dst + j)
						= *((shared const _UPC_RED_T *)dst + i)
						* *((shared const _UPC_RED_T *)src + k);
				}
				break;
#ifndef _UPC_NONINT_T
        // Skip if not integral type, per spec 4.3.1.1
        // (See additional comments in upc_collective.c)
			case UPC_AND:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					*((shared _UPC_RED_T *)dst + j)
						= *((shared const _UPC_RED_T *)dst + i)
						& *((shared const _UPC_RED_T *)src + k);
				}
				break;
			case UPC_OR:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					*((shared _UPC_RED_T *)dst + j)
						= *((shared const _UPC_RED_T *)dst + i)
						| *((shared const _UPC_RED_T *)src + k);
				}
				break;
			case UPC_XOR:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					*((shared _UPC_RED_T *)dst + j)
						= *((shared const _UPC_RED_T *)dst + i)
						^ *((shared const _UPC_RED_T *)src + k);
				}
				break;
#endif	// _UPC_NOINT_T
			case UPC_LOGAND:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					*((shared _UPC_RED_T *)dst + j)
						= *((shared const _UPC_RED_T *)dst + i)
						&& *((shared const _UPC_RED_T *)src + k);
				}
				break;
			case UPC_LOGOR:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					*((shared _UPC_RED_T *)dst + j)
						= *((shared const _UPC_RED_T *)dst + i)
						|| *((shared const _UPC_RED_T *)src + k);
				}
				break;
			case UPC_MIN:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					if ( *((shared const _UPC_RED_T *)dst + i)
						< *((shared const _UPC_RED_T *)src + k) )
						*((shared _UPC_RED_T *)dst + j)
							= *((shared const _UPC_RED_T *)dst + i);
					else
						*((shared _UPC_RED_T *)dst + j)
							= *((shared const _UPC_RED_T *)src + k);
				}
				break;
			case UPC_MAX:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					if ( *((shared const _UPC_RED_T *)dst + i)
						> *((shared const _UPC_RED_T *)src + k) )
						*((shared _UPC_RED_T *)dst + j)
							= *((shared const _UPC_RED_T *)dst + i);
					else
						*((shared _UPC_RED_T *)dst + j)
							= *((shared const _UPC_RED_T *)src + k);
				}
				break;
			case UPC_FUNC:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					*((shared _UPC_RED_T *)dst + j)
						= func( *((shared const _UPC_RED_T *)dst + i),
						*((shared const _UPC_RED_T *)src + k) );
				}
				break;
			case UPC_NONCOMM_FUNC:
				for (i=dst_offset, j=i+THREADS, k=src_offset+THREADS;
					k < (src_offset + n_local*THREADS);
					i=j, j+=THREADS, k+=THREADS)
				{
					*((shared _UPC_RED_T *)dst + j)
						= func( *((shared const _UPC_RED_T *)dst + i),
						*((shared const _UPC_RED_T *)src + k) );
				}
				break;
			}

			if ( MYTHREAD < THREADS-1 )
				// Write last prefix to shared array.  (This is spurious,
				// e.g., sometimes when n_local < blk_size.)

				pref[MYTHREAD+1] = *((shared const _UPC_RED_T *)dst
						+ dst_offset + (n_local-1)*THREADS);
		}

		upc_barrier;

		// Now thread THREADS-1 computes prefixes of pref[first_thr..last_thr]
		// even if it doesn't contain any elements itself.

		if ( MYTHREAD == THREADS-1 )
		{
			if ( w > 0 )	// (first_thr is always 0 in this case)

				// Write the last prefix computed on the *previous* iteration.

				pref[0] = *((shared const _UPC_RED_T *)dst + dst_offset - THREADS);

			else	// On the first iteration the source thread has no left neighbor.

				++first_thr;

			// Compute prefixes in pref[first_thr..last_thr].

                        	switch (op)
                        	{
                        	case UPC_ADD:
					{
					for ( i=first_thr+1; i<=last_thr; ++i )
						pref[i] += pref[i-1];
                               		}
                               		break;
				case UPC_MULT:
					{
					for ( i=first_thr+1; i<=last_thr; ++i )
						pref[i] *= pref[i-1];
					}
					break;
#ifndef _UPC_NONINT_T
        // Skip if not integral type, per spec 4.3.1.1
        // (See additional comments in upc_collective.c)
				case UPC_AND:
					for ( i=first_thr+1; i<=last_thr; ++i )
						pref[i] &= pref[i-1];
					break;
				case UPC_OR:
					for ( i=first_thr+1; i<=last_thr; ++i )
						pref[i] |= pref[i-1];
					break;
				case UPC_XOR:
					for ( i=first_thr+1; i<=last_thr; ++i )
						pref[i] ^= pref[i-1];
					break;
#endif	// _UPC_NOINT_T
				case UPC_LOGAND:
					for ( i=first_thr+1; i<=last_thr; ++i )
						pref[i] = pref[i-1] && pref[i];
					break;
				case UPC_LOGOR:
					for ( i=first_thr+1; i<=last_thr; ++i )
						pref[i] = pref[i-1] || pref[i];
					break;
				case UPC_MIN:
					for ( i=first_thr+1; i<=last_thr; ++i )
						if ( pref[i-1] < pref[i] )
							pref[i] = pref[i-1];
					break;
				case UPC_MAX:
					for ( i=first_thr+1; i<=last_thr; ++i )
						if ( pref[i-1] > pref[i] )
							pref[i] = pref[i-1];
					break;
				case UPC_FUNC:
					for ( i=first_thr+1; i<=last_thr; ++i )
						pref[i] = func( pref[i-1], pref[i] );
					break;
				case UPC_NONCOMM_FUNC:
					for ( i=first_thr+1; i<=last_thr; ++i )
						pref[i] = func( pref[i-1], pref[i] );
					break;
				}
		}	// THREAD-1 is done doing it's special job.

		upc_barrier;

                if ( (n_local > 0) && ( (w>0) || (MYTHREAD > src_thr) ) )
                {
			// "Add" pref[MYTHREAD] to local prefixes.  (On the first
			// iteration, only threads beyond src_thr should do this.)

                        switch (op)
                        {
                        case UPC_ADD:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
				{
                                        *((shared _UPC_RED_T *)dst + i) += pref[MYTHREAD];
                                }
                                break;
			case UPC_MULT:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
				{
                                        *((shared _UPC_RED_T *)dst + i) *= pref[MYTHREAD];
				}
				break;
#ifndef _UPC_NONINT_T
        // Skip if not integral type, per spec 4.3.1.1
        // (See additional comments in upc_collective.c)
			case UPC_AND:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
                                        *((shared _UPC_RED_T *)dst + i) &= pref[MYTHREAD];
				break;
			case UPC_OR:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
                                        *((shared _UPC_RED_T *)dst + i) |= pref[MYTHREAD];
				break;
			case UPC_XOR:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
                                        *((shared _UPC_RED_T *)dst + i) *= pref[MYTHREAD];
				break;
#endif	// _UPC_NOINT_T
			case UPC_LOGAND:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
                                        *((shared _UPC_RED_T *)dst + i)
                                        	= *((shared _UPC_RED_T *)dst + i) && pref[MYTHREAD];
				break;
			case UPC_LOGOR:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
                                        *((shared _UPC_RED_T *)dst + i)
                                        	= *((shared _UPC_RED_T *)dst + i) || pref[MYTHREAD];
				break;
			case UPC_MIN:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
                                        if ( pref[MYTHREAD] < *((shared _UPC_RED_T *)dst + i) )
                                        	*((shared _UPC_RED_T *)dst + i) = pref[MYTHREAD];
				break;
			case UPC_MAX:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
                                        if ( pref[MYTHREAD] > *((shared _UPC_RED_T *)dst + i) )
                                        	*((shared _UPC_RED_T *)dst + i) = pref[MYTHREAD];
				break;
			case UPC_FUNC:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
                                        *((shared _UPC_RED_T *)dst + i)
					= func( pref[MYTHREAD], *((shared _UPC_RED_T *)dst + i) );
				break;
			case UPC_NONCOMM_FUNC:
                                for (i=dst_offset; i<(dst_offset + n_local*THREADS); i+=THREADS)
                                        *((shared _UPC_RED_T *)dst + i)
					= func( pref[MYTHREAD], *((shared _UPC_RED_T *)dst + i) );
				break;
                        }
		}

		if ( wraps > w )	// Set up for the next iteration.
		{
			// swap between two halves of pref array
			if ( w%2 == 0 )
				pref = pref + THREADS;
			else
				pref = pref - THREADS;

			rem_elems -= row_elems;

			if ( rem_elems / (blk_size*THREADS) > 0 )	// next row is "full"
				row_elems = blk_size*THREADS;
        		else
                		row_elems = rem_elems;

			first_thr = 0;
			last_thr = (row_elems-1) / blk_size;

			n_local = blk_size;
			if ( MYTHREAD == last_thr )
			{
				if ( row_elems % blk_size > 0 )
					n_local = row_elems % blk_size;
				else;
			}
			if ( MYTHREAD > last_thr )
				n_local = 0;
			
			// Handle phase > 0 on first iteration

			if ( (w==0) && (MYTHREAD==src_thr) )
			{
				src_offset -= phase*THREADS;
				dst_offset -= phase*THREADS;
			}

			// All the preceding work makes this easy:

			src_offset += blk_size*THREADS;
			dst_offset += blk_size*THREADS;
		}

	} // End of main "wrap" loop

      	// Synchronize using barriers in the cases of MYSYNC and ALLSYNC.

	if ( UPC_OUT_MYSYNC & sync_mode || !(UPC_OUT_NOSYNC & sync_mode) )

		upc_barrier;
	else
		// we have to synchronize anyway to free the pref array
		upc_barrier;

	if ( MYTHREAD == THREADS-1 ) {
                if ( w%2 == 0 ) pref -= THREADS; /* DOB: be sure we free the original pointer! */
		upc_free(pref);
        }
}

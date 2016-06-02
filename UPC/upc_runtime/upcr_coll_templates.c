/*
 * UPC Collectives templates for typed interfaces
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_coll_templates.c $
 */

/* NOTE:
 * This file is included multiple times with different values of the
 * following three preprocessor tokens to define the typed reduce and
 * prefix-reduce interfaces:
 *
 * UPCRI_COLL_RED_TYPE:		type for (prefix) reduction operations
 * UPCRI_COLL_RED_SUFF:		suffix for (prefix) reduction interfaces
 * UPCRI_COLL_RED_OPS:		legal operators, one of UPCRI_COLL_{INT,NONINT}
 *
 */

#include <upcr.h>
#include <upcr_internal.h>
#include <gasnet_coll.h>
#include <gasnet_vis.h>

#ifdef UPCRI_USE_FCA
#include "fca/gasnet_fca.h"
#include "upcr_fca.h"
#endif

#if !defined(UPCRI_COLL_RED_TYPE) || !defined(UPCRI_COLL_RED_SUFF) || !defined(UPCRI_COLL_RED_OPS)
  #error "This file is only for use in building libupcr"
#endif

#if defined(GASNET_TRACE)
  #define UPCRI_TRACE_RED(name, type, op, nelems) \
        UPCRI_TRACE_PRINTF(("COLLECTIVE UPC_ALL_" _STRINGIFY(name) ": type = %2s count = %6llu op = %s", _STRINGIFY(type), (long long unsigned)(nelems), upcri_op2str(op)))
#else
  #define UPCRI_TRACE_RED(name, type, op, nelems) ((void)0)
#endif


  #define UPCRI_COLL_NONINT_RED(X,Y_P,FUNC,COUNT)                        \
    case UPC_NONCOMM_FUNC: /* needed when called for prefix reduce */    \
    case UPC_FUNC: while(COUNT--) { X = (*(FUNC))(X,*(Y_P++)); }         \
      break;                                                             \
    case UPC_ADD:  while(COUNT--) { X += *(Y_P++); }                     \
      break;                                                             \
    case UPC_MULT: while(COUNT--) { X *= *(Y_P++); }                     \
      break;                                                             \
    case UPC_MIN:  while(COUNT--) { if (*Y_P < X) { X = *Y_P; } ++Y_P; } \
      break;                                                             \
    case UPC_MAX:  while(COUNT--) { if (*Y_P > X) { X = *Y_P; } ++Y_P; } \
      break;                                                             \
    default:                                                             \
      upcri_err("invalid op");                                           \
      break;

  #define UPCRI_COLL_INT_RED(X,Y_P,FUNC,COUNT)                \
    case UPC_AND:    while(COUNT--) { X &= *(Y_P++); }        \
      break;                                                  \
    case UPC_OR:     while(COUNT--) { X |= *(Y_P++); }        \
      break;                                                  \
    case UPC_LOGAND: while(COUNT--) { X = X && *(Y_P++); }    \
      break;                                                  \
    case UPC_LOGOR:  while(COUNT--) { X = X || *(Y_P++); }    \
      break;                                                  \
    case UPC_XOR:    while(COUNT--) { X = X ^ *(Y_P++); }     \
      break;                                                  \
    UPCRI_COLL_NONINT_RED(X,Y_P,FUNC,COUNT)
  
  #define UPCRI_COLL_REDUCE_INNER(SUFF) \
    _CONCAT(upcri_coll_reduce_inner,SUFF)

  #define UPCRI_COLL_REDUCE_INNER_PROTO(TYPE,SUFF)      \
    GASNETT_INLINE(UPCRI_COLL_REDUCE_INNER(SUFF))       \
    TYPE UPCRI_COLL_REDUCE_INNER(SUFF)(                 \
        TYPE partial, const TYPE *src, upc_op_t op,     \
        size_t count, TYPE (*func)(TYPE, TYPE))

  #define UPCRI_COLL_REDUCE_NC(SUFF) \
    _CONCAT(upcri_coll_reduce_nc,SUFF)

  #define UPCRI_COLL_REDUCE_NC_PROTO(TYPE,SUFF)         \
    GASNETT_INLINE(UPCRI_COLL_REDUCE_NC(SUFF))          \
    void UPCRI_COLL_REDUCE_NC(SUFF)                     \
        (upcr_shared_ptr_t dst, upcr_shared_ptr_t src,  \
         size_t nelems, size_t blk_size,                \
         TYPE (*func)(TYPE,TYPE), upc_flag_t sync_mode, \
         int bcast UPCRI_PT_ARG)

  #define UPCRI_COLL_REDUCE_C(SUFF) \
    _CONCAT(upcri_coll_reduce_c,SUFF)

  #define UPCRI_COLL_REDUCE_C_PROTO(TYPE,SUFF)         \
    GASNETT_INLINE(UPCRI_COLL_REDUCE_C(SUFF))          \
    void UPCRI_COLL_REDUCE_C(SUFF)                     \
        (upcr_shared_ptr_t dst, upcr_shared_ptr_t src, \
         upc_op_t op, size_t nelems, size_t blk_size,  \
         TYPE (*func)(TYPE,TYPE), upc_flag_t sync_mode,\
         int bcast UPCRI_PT_ARG)

  #define UPCRI_COLL_REDUCE_PROTO(TYPE,SUFF)            \
    void _CONCAT(_upcr_all_reduce,SUFF)                 \
        (upcr_shared_ptr_t dst, upcr_shared_ptr_t src,  \
         upc_op_t op, size_t nelems, size_t blk_size,   \
         TYPE (*func)(TYPE,TYPE), upc_flag_t sync_mode, \
         int bcast UPCRI_PT_ARG)

  #define UPCRI_COLL_NONINT_PRED(X,Y_P,FUNC,COUNT)                              \
    case UPC_NONCOMM_FUNC:                                                      \
    case UPC_FUNC: while(COUNT--) { X = (*(FUNC))(X,*Y_P); *(Y_P++) = X; }      \
      break;                                                                    \
    case UPC_ADD:  while(COUNT--) { X += *Y_P; *(Y_P++) = X; }                  \
      break;                                                                    \
    case UPC_MULT: while(COUNT--) { X *= *Y_P; *(Y_P++) = X; }                  \
      break;                                                                    \
    case UPC_MIN:  while(COUNT--) { if (*Y_P < X) { X = *Y_P; } *(Y_P++) = X; } \
      break;                                                                    \
    case UPC_MAX:  while(COUNT--) { if (*Y_P > X) { X = *Y_P; } *(Y_P++) = X; } \
      break;                                                                    \
    default:                                                                    \
      upcri_err("invalid op");                                                  \
      break;

  #define UPCRI_COLL_INT_PRED(X,Y_P,FUNC,COUNT)                      \
    case UPC_AND:    while(COUNT--) { X &= *Y_P; *(Y_P++) = X; }     \
      break;                                                         \
    case UPC_OR:     while(COUNT--) { X |= *Y_P; *(Y_P++) = X; }     \
      break;                                                         \
    case UPC_LOGAND: while(COUNT--) { X = X && *Y_P; *(Y_P++) = X; } \
      break;                                                         \
    case UPC_LOGOR:  while(COUNT--) { X = X || *Y_P; *(Y_P++) = X; } \
      break;                                                         \
    case UPC_XOR:    while(COUNT--) { X = X ^ *Y_P; *(Y_P++) = X; }  \
      break;                                                         \
    UPCRI_COLL_NONINT_PRED(X,Y_P,FUNC,COUNT)

  #define UPCRI_COLL_PREFIX_REDUCE_INNER(SUFF) \
    _CONCAT(upcri_coll_prefix_reduce_inner,SUFF)

  #define UPCRI_COLL_PREFIX_REDUCE_INNER_PROTO(TYPE,SUFF) \
    GASNETT_INLINE(UPCRI_COLL_PREFIX_REDUCE_INNER(SUFF))  \
    TYPE UPCRI_COLL_PREFIX_REDUCE_INNER(SUFF)(            \
        TYPE partial, TYPE *arry, upc_op_t op,            \
        size_t count, TYPE (*func)(TYPE, TYPE))

  #define UPCRI_COLL_PREFIX_REDUCE_PROTO(TYPE,SUFF)     \
    void _CONCAT(_upcr_all_prefix_reduce,SUFF)          \
        (upcr_shared_ptr_t dst, upcr_shared_ptr_t src,  \
         upc_op_t op, size_t nelems, size_t blk_size,   \
         TYPE (*func)(TYPE,TYPE), upc_flag_t sync_mode  \
         UPCRI_PT_ARG)

  #if UPCRI_COLL_USE_LOCAL_TEMPS
    /* Temps are NOT in the segment */
    #define UPCRI_COLL_SRC_MIGHT_BE_LOCAL 0
    #define UPCRI_COLL_DST_MIGHT_BE_LOCAL 0
  #else
    /* Temps ARE in the segment */
    #define UPCRI_COLL_SRC_MIGHT_BE_LOCAL GASNET_COLL_SRC_IN_SEGMENT
    #define UPCRI_COLL_DST_MIGHT_BE_LOCAL GASNET_COLL_DST_IN_SEGMENT
  #endif

  #if UPCR_DEBUG
    /* Named barriers for assistance in debugging */
    #define UPCRI_COLL_BARRIER_DECL() \
	const int barrier_name = UPCRI_SINGLE_BARRIER_NAME()
    #define UPCRI_COLL_NOTIFY_IF(cond) \
	if_pf(cond) { _upcr_notify(barrier_name, 0 UPCRI_PT_PASS); }
    #define UPCRI_COLL_WAIT_IF(cond) \
	if_pf(cond) { _upcr_wait(barrier_name, 0 UPCRI_PT_PASS); }
    #define UPCRI_COLL_BARRIER_IF(cond) \
	if_pf(cond) { _upcri_barrier(barrier_name, 0 UPCRI_PT_PASS); }
  #else
    /* Unnamed barriers for speed */
    #define UPCRI_COLL_BARRIER_DECL() \
	int _dummy_to_eat_semicolon = sizeof(_dummy_to_eat_semicolon)
    #define UPCRI_COLL_NOTIFY_IF(cond) \
	if_pf(cond) { _upcr_notify(0, UPCR_BARRIERFLAG_UNNAMED UPCRI_PT_PASS); }
    #define UPCRI_COLL_WAIT_IF(cond) \
	if_pf(cond) { _upcr_wait(0, UPCR_BARRIERFLAG_UNNAMED UPCRI_PT_PASS); }
    #define UPCRI_COLL_BARRIER_IF(cond) \
	if_pf(cond) { _upcri_barrier(0, UPCR_BARRIERFLAG_UNNAMED UPCRI_PT_PASS); }
  #endif

#if 0 /* Not used because the (buggy) unequal phase code  is disabled */
  #if UPCRI_BUILD_PREFIX_REDUCE
  /* Building block for copy of a blocked array with unequal src/dst phases */
  static void _upcri_coll_strided_get(void *dst, upcr_thread_t src_th, void *src,
				      size_t elem_size, size_t nelems, size_t blk_size,
				      size_t len, size_t skip UPCRI_PT_ARG) {
    uintptr_t dst_addr = (intptr_t)dst;
    uintptr_t src_addr = (intptr_t)src;
    size_t stride = blk_size * elem_size;
    gasnet_node_t src_node = upcri_thread_to_node(src_th);
    UPCRI_PASS_GAS();

    if (src_node == gasnet_mynode()) {
	/* First deal with leading partial (if any) */
	if (skip) {
	    if (skip < len) {
		size_t count = MIN(nelems, len-skip);
		memcpy((void *)(dst_addr + skip * elem_size),
		       (void *)(src_addr + skip * elem_size),
		       count * elem_size);
	    }
	    dst_addr += stride;
	    src_addr += stride;
	    nelems -= MIN(nelems, blk_size - skip);
	}
    
	/* Now deal with full rows (if any) */
	if (nelems >= len) {
	    size_t blocks = 1 + ((nelems - len) / blk_size);
	    int i;

	    for (i = 0; i < blocks; ++i) {
		memcpy((void *)dst_addr, (void *)src_addr, len * elem_size);
		dst_addr += stride;
		src_addr += stride;
	    }

	    nelems -= MIN(nelems, blocks*blk_size);
	}
    
	/* Take care of trailing final elements (if any) */
	if (nelems) {
	    memcpy((void *)dst_addr, (void *)src_addr, nelems * elem_size);
	}
    } else {
	/* First deal with leading partial (if any) */
	if (skip) {
	    if (skip < len) {
		size_t count = MIN(nelems, len-skip);
		gasnet_get_nbi_bulk((void *)(dst_addr + skip * elem_size),
				    src_node, (void *)(src_addr + skip * elem_size),
				    count * elem_size);
	    }
	    dst_addr += stride;
	    src_addr += stride;
	    nelems -= MIN(nelems, blk_size - skip);
	}
    
	/* Now deal with full rows (if any) */
	if (nelems >= len) {
	    size_t blocks = 1 + ((nelems - len) / blk_size);
	    size_t count[2];

	    count[0] = len * elem_size;
	    count[1] = blocks;

	    gasnet_gets_nbi_bulk((void *)dst_addr, &stride, src_node, (void *)src_addr, &stride, count, 1);

	    dst_addr += blocks*stride;
	    src_addr += blocks*stride;
	    nelems -= MIN(nelems, blocks*blk_size);
	}
    
	/* Take care of trailing final elements (if any) */
	if (nelems) {
	    gasnet_get_nbi_bulk((void *)dst_addr, src_node, (void *)src_addr, nelems * elem_size);
	}

	/* Wait for gets to finish */
	gasnet_wait_syncnbi_gets();
    }
  }
  #endif /* UPCRI_BUILD_PREFIX_REDUCE */
#endif

/*----------------------------------------------------------------------------*/

/* Templated reduction inner loop function */
UPCRI_COLL_REDUCE_INNER_PROTO(UPCRI_COLL_RED_TYPE,UPCRI_COLL_RED_SUFF)
{
    switch(op) {
	_CONCAT(UPCRI_COLL_RED_OPS,_RED)(partial, src, func, count)
    }
    return partial;
}

/*----------------------------------------------------------------------------*/

#if UPCRI_BUILD_REDUCE
/* Templated non-commutative reduction function */
/* XXX: We should segment (and pipeline) to bound the amount
 * of temporary storage required. */
UPCRI_COLL_REDUCE_NC_PROTO(UPCRI_COLL_RED_TYPE,UPCRI_COLL_RED_SUFF)
{
    /* See below for a description of these variables */
    size_t start_thread, start_phase;
    size_t end_thread, end_phase;
    size_t rows, partials;
#if !UPCRI_COLL_USE_LOCAL_TEMPS
    upcr_shared_ptr_t partial_sptr;
#endif
    const upcr_thread_t mythread = upcr_mythread();
    UPCRI_COLL_RED_TYPE *my_partial;
    UPCRI_COLL_BARRIER_DECL();
    UPCRI_PASS_GAS();

    /* STEP 1: Notify the barrier for IN_ALLSYNC if needed. (all threads)
     */
    UPCRI_COLL_NOTIFY_IF(sync_mode & UPC_IN_ALLSYNC);

    /* STEP 2: Compute the bounding box information. (all threads)
     *
     * Since this is a purely local computation on single valued arguments
     * we can safely do this between barrier phases (if any).
     *
     * (start_thread, start_phase): the thread and phase of the first element
     * (end_thread, end_phase): the thread and phase of the last element
     * rows: the number of time the array reaches the end of a row
     * partials: the number of non-empty rows
     *
     * XXX: If this math moved into a macro in upc_collective.h, then the
     * backend compiler could optimize in the static threads case.
     */
    {
	size_t tmp;

	if (!blk_size) blk_size = nelems; /* support indefinite layout */

	start_thread = upcr_threadof_shared(src);
	start_phase = upcr_phaseof_shared(src);
	tmp = nelems + start_phase;
	end_phase = tmp % blk_size;
	tmp = start_thread + (tmp / blk_size);
	rows = tmp / upcri_threads;
	end_thread = tmp % upcri_threads;
	partials = rows ? (rows + ((end_thread || end_phase)?1:0)) : 1;
    }

    /* STEP 3: Wait on the barrier for IN_ALLSYNC if needed. (all threads)
     */
    UPCRI_COLL_WAIT_IF(sync_mode & UPC_IN_ALLSYNC);

    /* STEP 4: Allocate local scratch space for partial results. (all threads)
     */
#if UPCRI_COLL_USE_LOCAL_TEMPS
    my_partial = upcri_malloc(partials * sizeof(UPCRI_COLL_RED_TYPE));
#else
    partial_sptr = upcr_alloc(partials * sizeof(UPCRI_COLL_RED_TYPE));
    my_partial = upcr_shared_to_local(partial_sptr);
#endif

    /* STEP 5: Compute my thread's own contribution, if any. (all threads)
     */
    {
	size_t first_row_count, my_count;
	const UPCRI_COLL_RED_TYPE *my_src;
	UPCRI_COLL_RED_TYPE my_tmp;
	int this_row;
	int i;

	/* Count full rows as a starting point, these gets adjusted further */
	my_src = (const UPCRI_COLL_RED_TYPE *)upcri_shared_to_remote_withthread(src, mythread) - start_phase;
	my_count = blk_size * rows;
	first_row_count = blk_size;
	this_row = 0;

	/* Adjust count for the final partial row */
	if (mythread < end_thread) {
	    my_count += blk_size;
	} else if (mythread == end_thread) {
	    my_count += end_phase;
	}

	/* Deal with leading row, which may be only partially populated */
	if (mythread == start_thread) {
	    /* First block, might be partial */
	    my_src += start_phase;
	    my_count -= start_phase;
	    first_row_count -= start_phase;
	} else if (mythread < start_thread) {
	    /* Skip the full first block */
	    my_src += blk_size;
	    my_count -= blk_size;
	    this_row = 1;
	}
	first_row_count = MIN(first_row_count, my_count);
	upcri_assert((ssize_t)my_count >= 0);

	/* Compute on the leading row, regardless of whether is is partial or full */
	if (my_count) {
	    my_tmp = *(my_src++);
	    for (i = 1; i < first_row_count; ++i) {
		my_tmp = (*func)(my_tmp, *(my_src++));
	    }
	    my_partial[this_row++] = my_tmp;
	    my_count -= first_row_count;
	}

	/* Compute on full rows */
	while (my_count >= blk_size) {
	    my_tmp = *(my_src++);
	    for (i = 1; i < blk_size; ++i) {
		my_tmp = (*func)(my_tmp, *(my_src++));
	    }
	    my_partial[this_row++] = my_tmp;
	    my_count -= blk_size;
	}

	/* Compute trailing partial row, if any */
	if (my_count) {
	    my_tmp = *(my_src++);
	    for (i = 1; i < my_count; ++i) {
		my_tmp = (*func)(my_tmp, *(my_src++));
	    }
	    my_partial[this_row++] = my_tmp;
	}
    }

    {
	/* STEP 6: SMP-level reduction (one thread on each node)
	 *
	 * NOT IMPLEMENTED
	 *
	 * XXX: We could add a simple smp-level reduction over local threads here.
	 * That would change the gather to be one partial result per node, rather than per thread.
	 * That will also require changing the final reduction logic to deal with
	 * missing contributions by nodes, rather than by threads.
	 */

	upcr_shared_ptr_t gath_sptr;
	UPCRI_COLL_RED_TYPE *gathered = NULL;
	upcr_thread_t dst_th = upcr_threadof_shared(dst);

	/* STEP 7: Gather (all threads)
	 *
	 * This call contributes the local partial result(s) to a gather which
	 * targets the node to which the destination has affinity.
	 */
	if (dst_th == mythread) {
	    gath_sptr = upcr_alloc(upcri_threads * partials * sizeof(UPCRI_COLL_RED_TYPE));
	    gathered = upcr_shared_to_local(gath_sptr);
	}
	gasnet_coll_gather(GASNET_TEAM_ALL, dst_th, gathered, my_partial,
			   sizeof(UPCRI_COLL_RED_TYPE) * partials,
			   (GASNET_COLL_LOCAL |
			    GASNET_COLL_DST_IN_SEGMENT |
			    UPCRI_COLL_SRC_MIGHT_BE_LOCAL |
			    GASNET_COLL_IN_MYSYNC | GASNET_COLL_OUT_MYSYNC));

	if (dst_th == mythread) {
	    /* STEP 8: Final reduction (one thread on destination node only)
	     */
	    UPCRI_COLL_RED_TYPE *p;
	    UPCRI_COLL_RED_TYPE tmp;
	    upcr_thread_t trailing_ths = end_thread + (end_phase?1:0);
	    int i, j;

	    /* Deal with the first row, regardless of whether is is partial or full */
	    j = rows ? upcri_threads : trailing_ths;
	    p = gathered + start_thread * partials;
	    tmp = *p;
	    for (i = start_thread + 1; i < j; ++i) {
		p += partials;
		tmp = (*func)(tmp, *p);
	    }

	    /* Deal with full rows */
	    for (i = 1; i < rows; ++i) {
		p = gathered + i;
		for (j = 0; j < upcri_threads; ++j) {
		    tmp = (*func)(tmp, *p);
		    p += partials;
		}
	    }

	    /* Deal with the trailing partial row, if any */
	    if (rows && trailing_ths) {
		p = gathered + rows;
		for (i = 0; i < trailing_ths; ++i) {
		    tmp = (*func)(tmp, *p);
		    p += partials;
		}
	    }
    
	    *(UPCRI_COLL_RED_TYPE *)upcr_shared_to_local(dst) = tmp;
	    *my_partial = tmp;	/* Needed in case of a broadcast of the result */
    

	    /* STEP 9: Free scatch space (one thread on destination node only)
	     */
	    upcr_free(gath_sptr);
	}
    
	/* STEP 10: Broadcast and/or OUTSYNC barrier if required (all threads)
	 */
	if (bcast) {
	    gasnet_coll_broadcast(GASNET_TEAM_ALL,
				  upcri_shared_to_remote_withthread(dst, mythread),
				  dst_th, my_partial,
				  sizeof(UPCRI_COLL_RED_TYPE),
				  GASNET_COLL_LOCAL |
				  UPCRI_COLL_SRC_MIGHT_BE_LOCAL |
				  GASNET_COLL_DST_IN_SEGMENT |
				  GASNET_COLL_IN_MYSYNC |
				  ((sync_mode & UPC_OUT_ALLSYNC) ? GASNET_COLL_OUT_ALLSYNC
								 : GASNET_COLL_OUT_MYSYNC));
	} else if (sync_mode & UPC_OUT_ALLSYNC) {
	    UPCRI_SINGLE_BARRIER();
	}
    }

    /* STEP 11: Free scratch space
     */
#if UPCRI_COLL_USE_LOCAL_TEMPS
    upcri_free(my_partial);
#else
    upcr_free(partial_sptr);
#endif
}

/* Templated commutative reduction function */
UPCRI_COLL_REDUCE_C_PROTO(UPCRI_COLL_RED_TYPE,UPCRI_COLL_RED_SUFF)
{
    /* See below for a description of these variables */
#if UPCRI_COLL_USE_LOCAL_TEMPS
    UPCRI_COLL_RED_TYPE my_temp;
#else
    upcr_shared_ptr_t partial_sptr;
#endif
    const upcr_thread_t mythread = upcr_mythread();
    UPCRI_COLL_RED_TYPE *my_partial;
    size_t start_thread, start_phase;
    size_t end_thread, end_phase;
    size_t rows;
    size_t my_count;
    UPCRI_COLL_BARRIER_DECL();
    UPCRI_PASS_GAS();
#ifdef UPCRI_USE_FCA
    const int use_single_phase_barrier = gasnet_team_fca_is_active(GASNET_TEAM_ALL, _FCA_BARRIER);
#else
    const int use_single_phase_barrier = 0;
#endif

    /* STEP 1: Notify the barrier for IN_ALLSYNC if needed. (all threads)
     */
    UPCRI_COLL_NOTIFY_IF((sync_mode & UPC_IN_ALLSYNC) && !use_single_phase_barrier);

    /* STEP 2: Compute the bounding box information. (all threads)
     *
     * Since this is a purely local computation on single valued arguments
     * we can safely do this between barrier phases (if any).
     *
     * (start_thread, start_phase): the thread and phase of the first element
     * (end_thread, end_phase): the thread and phase of the last element
     * rows: the number of time the array reaches the end of a row
     *
     * XXX: If this math moved into a macro in upc_collective.h, then the
     * backend compiler could optimize in the static threads case.
     */
    {
	size_t tmp;

	if (!blk_size) blk_size = nelems; /* support indefinite layout */

	start_thread = upcr_threadof_shared(src);
	start_phase = upcr_phaseof_shared(src);
	tmp = nelems + start_phase;
	end_phase = tmp % blk_size;
	tmp = start_thread + (tmp / blk_size);
	rows = tmp / upcri_threads;
	end_thread = tmp % upcri_threads;
    }

    /* STEP 3: Wait on the barrier for IN_ALLSYNC if needed. (all threads)
     */
    if (use_single_phase_barrier) {
        UPCRI_COLL_BARRIER_IF(sync_mode & UPC_IN_ALLSYNC);
    } else {
        UPCRI_COLL_WAIT_IF(sync_mode & UPC_IN_ALLSYNC);
    }

    /* STEP 4: Setup local scratch space for partial results. (all threads)
     */
#if UPCRI_COLL_USE_LOCAL_TEMPS
    my_partial = &my_temp;
#else
    partial_sptr = upcr_alloc(sizeof(UPCRI_COLL_RED_TYPE));
    my_partial = upcr_shared_to_local(partial_sptr);
#endif

    /* STEP 5: Compute my thread's own contribution, if any. (all threads)
     */
    {
	size_t my_skipped;

	/* Count how many leading elements we skip relative to the base of the array */
	if (mythread < start_thread) {
	    my_skipped = blk_size;
	} else if (mythread == start_thread) {
	    my_skipped = start_phase;
	} else {
	    my_skipped = 0;
	}

	/* Count full rows, less the skipped leading elements... */
	my_count = blk_size * rows - my_skipped;
	/* ... then adjust for the final partial row, if any */
	if (mythread < end_thread) {
	    my_count += blk_size;
	} else if (mythread == end_thread) {
	    my_count += end_phase;
	}
	upcri_assert((ssize_t)my_count >= 0);

	if (my_count != 0) {
	    const UPCRI_COLL_RED_TYPE *my_src;

	    my_src = (const UPCRI_COLL_RED_TYPE *)upcri_shared_to_remote_withthread(src, mythread)
				- start_phase + my_skipped;

	    *my_partial = UPCRI_COLL_REDUCE_INNER(UPCRI_COLL_RED_SUFF)
					(*my_src, my_src+1, op, my_count-1, func);
	}
    }

    {
	/* STEP 6: SMP-level reduction (one thread on each node)
	 *
	 * NOT IMPLEMENTED
	 *
	 * XXX: We could add a simple smp-level reduction over local threads here.
	 * That would change the gather to be one partial result per node, rather than per thread.
	 * That will also require changing the final reduction logic to deal with
	 * missing contributions by nodes, rather than by threads.
	 */
    }
#ifdef UPCRI_USE_FCA
  {
        /* Note that after local reduction some of the processes might have my_count=0
         * which means that they should not participate in the reduction. However, in the case
         * of FCA every process in the FCA communicator has to call a collective function.
         *
         * To deal with this we init my_partial variable to dummy value for those processes who has
         * myu_count=0. Dummy means "unitary" for a particular reduction operation. i.e. it does not
         * change a result been "added" to it. For "UPC_ADD" it is 0, for "UPC_MULT" it's 1, etc.
         *
         * The only exception is XOR operation which does not have a "unitary" element. In this case
         * we use "0"  as a partial result. Then if the number of dummy processes is even their 
         * share in the total result would go away since X^0^0=x. In the case the number of dummies is
         * odd we need to do one extra XOR with 0 on the root with the resulting variable.
         * */
        int ret = -1;
        if (gasnet_team_fca_is_active(GASNET_TEAM_ALL, _FCA_REDUCE)){
            int dummy_counter = 0;
            fca_reduce_type_t type;
            EVAL(CALL_FCA_PREP_FN,type,UPCRI_COLL_RED_SUFF,&type);
            if (my_count == 0){
                /*Get a "unitary" element for the particular "type" and "op"*/
                upcr_my_partial_dummy_init(my_partial,op,type);
            }
            if (!bcast){
                void *dest_addr = NULL;
                if (upcr_threadof_shared(dst) == mythread){
                    dest_addr = (void *)upcr_shared_to_local(dst);
                    if (UPC_XOR == op){
                        /*If we are doing XOR, then calc how many dummies we have, so
                         * the root can decide whether to do one extra XOR in the end
                         */
                        COUNT_DUMMY_THREADS;
                    }
                }

    
                ret = upcr_fca_reduce(upcr_threadof_shared(dst),
                        dest_addr,
                        (void *)my_partial,
                        op,
                        type,
                        0);

                if (UPC_XOR == op && dummy_counter%2){
                    /*Do one more XOR with zero*/
                    XOR_RESULT;
                }
            }
            else{
                if (UPC_XOR == op){
                    COUNT_DUMMY_THREADS;
                }

                ret = upcr_fca_reduce_all((void *)upcri_shared_to_remote_withthread(dst, mythread),
                        (void *)my_partial,
                        op,
                        type,
                        0);

                if (UPC_XOR == op && dummy_counter%2){
                    XOR_RESULT;
                }
            }
        }
   if (ret < 0) /* fall back if FCA unavailable or failed */
#endif
   {
	/* STEP 7: Gather (all threads)
	 *
	 * This call contributes the local partial result(s) to a gather which
	 * targets the node to which the destination has affinity.
	 */

	upcr_shared_ptr_t gath_sptr;
	UPCRI_COLL_RED_TYPE *gathered = NULL;
	upcr_thread_t dst_th = upcr_threadof_shared(dst);

	if (dst_th == mythread) {
	    gath_sptr = upcr_alloc(upcri_threads * sizeof(UPCRI_COLL_RED_TYPE));
	    gathered = upcr_shared_to_local(gath_sptr);
	}
	gasnet_coll_gather(GASNET_TEAM_ALL, dst_th, gathered, my_partial,
			   sizeof(UPCRI_COLL_RED_TYPE),
			   (GASNET_COLL_LOCAL |
			    GASNET_COLL_DST_IN_SEGMENT |
			    UPCRI_COLL_SRC_MIGHT_BE_LOCAL |
			    GASNET_COLL_IN_MYSYNC | GASNET_COLL_OUT_MYSYNC));

	if (dst_th == mythread) {
	    upcr_thread_t first_th, first_row_ths, trailing_ths;
	    UPCRI_COLL_RED_TYPE tmp;

	    /* STEP 8: Final reduction (destination thread only)
	     */
	    trailing_ths = end_thread + (end_phase?1:0);
	    first_th = start_thread;
	    if (rows == 0) {
		/* We reach the last element before the end of the first row
		 * and looks something like:
		 *     .XX.
		 *     0123
		 * in which 0 and 4 have no contribution
		 */
		first_row_ths = trailing_ths - first_th;
		trailing_ths = 0;
	    } else if ((rows == 1) && (trailing_ths < first_th)) {
		/* There is a gap between the head and the tail and looks something like:
		 *     ..XX
		 *     0123
		 * in which threads 0 and 1 have no contribution, or like
		 *     X...
		 *     ..XX
		 *     0123
		 * in which thread 1 has no contribution.
		 */
		first_row_ths = upcri_threads - first_th;
	    } else {
		/* The head and tail wrap to yield a contribution from every thread.
		 * For the (rows > 1) case it may look something like
		 *     X...
		 *     XXXX
		 *     ..XX
		 *     0123
		 * For the (trailing_ths >= first_th) case it may look something like
		 *     XXX.
		 *     ..XX
		 *     0123
		 */
		first_th = 0;
		first_row_ths = upcri_threads;
		trailing_ths = 0;
	    }
    
	    /* Deal with the first row, regardless of whether is is partial or full */
	    tmp = UPCRI_COLL_REDUCE_INNER(UPCRI_COLL_RED_SUFF)
				(gathered[first_th], &gathered[first_th + 1], op, first_row_ths - 1, func);
    
	    /* Deal with the final partial row, if any */
	    tmp = UPCRI_COLL_REDUCE_INNER(UPCRI_COLL_RED_SUFF)
				(tmp, gathered, op, trailing_ths, func);

	    *(UPCRI_COLL_RED_TYPE *)upcr_shared_to_local(dst) = tmp;
	    *my_partial = tmp;	/* Needed in case of a broadcast of the result */
    

	    /* STEP 9: Free scatch space (destination thread only)
	     */
	    upcr_free(gath_sptr);
	}
     
	/* STEP 10: Broadcast and/or OUTSYNC barrier if required (all threads)
	 */
	if (bcast) {
	    /* Note promotion to OUT_MYSYNC to ensure the temporary is fully consumed before it is freed. */
	    gasnet_coll_broadcast(GASNET_TEAM_ALL,
				  upcri_shared_to_remote_withthread(dst, mythread),
				  dst_th, my_partial,
				  sizeof(UPCRI_COLL_RED_TYPE),
				  GASNET_COLL_LOCAL |
				  UPCRI_COLL_SRC_MIGHT_BE_LOCAL |
				  GASNET_COLL_DST_IN_SEGMENT |
				  GASNET_COLL_IN_MYSYNC |
				  ((sync_mode & UPC_OUT_ALLSYNC) ? GASNET_COLL_OUT_ALLSYNC
								 : GASNET_COLL_OUT_MYSYNC));
	} else if (sync_mode & UPC_OUT_ALLSYNC) {
	    UPCRI_SINGLE_BARRIER();
	}
   }
#ifdef UPCRI_USE_FCA
   if ((sync_mode & UPC_OUT_ALLSYNC) && (ret >= 0)){
       UPCRI_SINGLE_BARRIER();
   }
  }
#endif
    /* STEP 11: free scratch space
     */
#if !UPCRI_COLL_USE_LOCAL_TEMPS
    upcr_free(partial_sptr);
#endif
}

/* Templated reduction function */
UPCRI_COLL_REDUCE_PROTO(UPCRI_COLL_RED_TYPE,UPCRI_COLL_RED_SUFF)
{
    sync_mode = upcri_coll_fixsync(sync_mode);

    UPCRI_TRACE_RED(REDUCE, UPCRI_COLL_RED_SUFF, op, nelems);

    #define UPCRI_PEVT_ARGS , &dst, &src, (int)op, nelems, blk_size, \
            (void *)func, (int)sync_mode, _CONCAT(GASP_UPC_REDUCTION_,UPCRI_COLL_RED_SUFF)
    upcri_pevt_start(GASP_UPC_ALL_REDUCE);

    if (op == UPC_NONCOMM_FUNC) {
	UPCRI_COLL_REDUCE_NC(UPCRI_COLL_RED_SUFF)
		(dst, src, nelems, blk_size, func, sync_mode, bcast UPCRI_PT_PASS);
    } else {
	UPCRI_COLL_REDUCE_C(UPCRI_COLL_RED_SUFF)
		(dst, src, op, nelems, blk_size, func, sync_mode, bcast UPCRI_PT_PASS);
    }

    upcri_pevt_end(GASP_UPC_ALL_REDUCE);
    #undef UPCRI_PEVT_ARGS
}

#endif /* UPCRI_BUILD_REDUCE */

/*----------------------------------------------------------------------------*/

#if UPCRI_BUILD_PREFIX_REDUCE

/* Templated prefix reduction inner loop function */
UPCRI_COLL_PREFIX_REDUCE_INNER_PROTO(UPCRI_COLL_RED_TYPE,UPCRI_COLL_RED_SUFF)
{
    switch(op) {
	_CONCAT(UPCRI_COLL_RED_OPS,_PRED)(partial, arry, func, count)
    }
    return partial;
}

/* Templated prefix reduction function */
/* XXX Cyclic case has a few shortcuts, but could be better still if the root
 * performed the inclusive reduction.  Then the results could just be memcpy()ed
 * into place from the scatter.
 * XXX segment this to bound temporary space.
 */
UPCRI_COLL_PREFIX_REDUCE_PROTO(UPCRI_COLL_RED_TYPE,UPCRI_COLL_RED_SUFF)
{
    /* See below for a description of these variables */
#if !UPCRI_COLL_USE_LOCAL_TEMPS
    upcr_shared_ptr_t partial_sptr;
#endif
    UPCRI_COLL_RED_TYPE *my_partial;
    const upcr_thread_t mythread = upcr_mythread();
    UPCRI_COLL_RED_TYPE *my_dst;
    size_t my_count, first_row_count, first_row;
    size_t start_thread, start_phase;
    size_t end_thread, end_phase;
    size_t rows, partials;
    UPCRI_COLL_BARRIER_DECL();
    UPCRI_PASS_GAS();

    sync_mode = upcri_coll_fixsync(sync_mode);
    UPCRI_TRACE_RED(PREFIX_REDUCE, UPCRI_COLL_RED_SUFF, op, nelems);

    #define UPCRI_PEVT_ARGS , &dst, &src, (int)op, nelems, blk_size, \
            (void *)func, (int)sync_mode, _CONCAT(GASP_UPC_REDUCTION_,UPCRI_COLL_RED_SUFF)
    upcri_pevt_start(GASP_UPC_ALL_PREFIX_REDUCE);

    /* STEP 1: Notify the barrier IN_{MY,ALL}SYNC if needed. (all threads)
     */
    UPCRI_COLL_NOTIFY_IF(!(sync_mode & UPC_IN_NOSYNC));

    /* STEP 2: Compute the bounding box information. (all threads)
     *
     * Since this is a purely local computation on single valued arguments
     * we can safely do this between barrier phases (if any).
     *
     * (start_thread, start_phase): the thread and phase of the first element
     * (end_thread, end_phase): the thread and phase of the last element
     * rows: the number of time the array reaches the end of a row
     *
     * XXX: If this math moved into a macro in upc_collective.h, then the
     * backend compiler could optimize in the static threads case.
     */
    {
	size_t tmp;

	if (!blk_size) blk_size = nelems; /* support indefinite layout */

	start_thread = upcr_threadof_shared(dst);
	start_phase = upcr_phaseof_shared(dst);
	tmp = nelems + start_phase;
	end_phase = tmp % blk_size;
	tmp = start_thread + (tmp / blk_size);
	rows = tmp / upcri_threads;
	end_thread = tmp % upcri_threads;
	partials = rows ? (rows + ((end_thread || end_phase)?1:0)) : 1;
    }

    /* STEP 3: Wait on the barrier for IN_{MY,ALL}SYNC if needed. (all threads)
     */
    UPCRI_COLL_WAIT_IF(!(sync_mode & UPC_IN_NOSYNC));

    /* STEP 4: Copy src to dst. (all threads)
     *
     * XXX: current implementation requires equal phases for src and dst.
     */
    {
	upcr_thread_t src_aff = upcr_threadof_shared(src);
	size_t src_phase = upcr_phaseof_shared(src);
	upcr_thread_t src_th;

	/* Compute source thread, taking care to avoid overflow */
	if (start_thread >= src_aff) {
	    const upcr_thread_t diff = start_thread - src_aff;
	    if (mythread >= diff) {
		src_th = mythread - diff;
	    } else {
		src_th = mythread + (upcri_threads - diff);
	    }
	} else {
	    const upcr_thread_t diff = src_aff - start_thread;
	    if (mythread < upcri_threads - diff) {
		src_th = mythread + diff;
	    } else {
		src_th = mythread - (upcri_threads - diff);
	    }
	}

	/* Start with unadjusted base addresses, subject to later adjustment */
	my_dst = (UPCRI_COLL_RED_TYPE *)upcri_shared_to_remote_withthread(dst, mythread) - start_phase;

	/* Start with count of full rows, subject to later adjustment */
	my_count = blk_size * rows;
	first_row_count = blk_size;
	first_row = 0;

	/* Count how many leading elements we skip relative to the base of the arrays */
	if (mythread < start_thread) {
	    my_dst += blk_size;
	    my_count -= blk_size;
	    first_row = 1;
	} else if (mythread == start_thread) {
	    my_count -= start_phase;
	    first_row_count -= start_phase;
	    my_dst += start_phase;
	}

	/* Adjust for the final partial row, if any */
	if (mythread < end_thread) {
	    my_count += blk_size;
	} else if (mythread == end_thread) {
	    my_count += end_phase;
	}
	upcri_assert((ssize_t)my_count >= 0);

	first_row_count = MIN(first_row_count, my_count);

	if (my_count != 0) {
	    if (upcri_threads == 1) {
		/* Very simple case of one thread */
		memcpy((void *)upcr_shared_to_local(dst),
		       (void *)upcr_shared_to_local(src),
		       my_count * sizeof(UPCRI_COLL_RED_TYPE));
	    } else if (src_phase == start_phase) {
		/* Simple case for equal src and dst phase */
		size_t nbytes = my_count * sizeof(UPCRI_COLL_RED_TYPE);
		UPCRI_COLL_RED_TYPE *my_src;

		my_src = (UPCRI_COLL_RED_TYPE *)upcri_shared_to_remote_withthread(src, src_th);
		if (src_th < src_aff) {
		    my_src += blk_size - start_phase;
		} else if (src_th > src_aff) {
		    my_src -= start_phase;
		}
		if (upcri_thread_is_addressable(src_th)) {
		    UPCRI_UNALIGNED_MEMCPY(my_dst, UPCRI_COLL_LOCALIZE(my_src, src_th), nbytes);
		} else {
		    gasnet_get_bulk(my_dst, upcri_thread_to_node(src_th), my_src, nbytes);
		}
	    } else {
#if 1
		/* We had tried to support this case, which is not required by spec.
		   However, it turns out we've always gotten it subtly wrong.
		   See bug 2991, and the "Bug2991" comment below.  -PHH
		 */
		upcri_err("unsupported call to upc_all_prefix_reduce"
			  _STRINGIFY(UPCRI_COLL_RED_SUFF)
			  "() with upc_phaseof(src) != upcr_phaseof(dst)");
#else
		/* Complicated case for unequal src and dst phase */
		UPCRI_COLL_RED_TYPE *tmp_src, *tmp_dst;
		ssize_t delta = start_phase - upcr_phaseof_shared(src);
		size_t tmp_count, skip;
		size_t sub_count, offset;

		/* Get left-hand chunk of each block */ 
		tmp_count = my_count;
		if (delta > 0) {
		    sub_count = delta;
		    if (src_th > 0) {
			src_th--;
		    } else {
			src_th = upcri_threads - 1;
		    }
		} else {
		    sub_count = blk_size + delta;
		}
		tmp_src = (UPCRI_COLL_RED_TYPE *)upcri_shared_to_remote_withthread(src, src_th)
						- src_phase + blk_size - sub_count;
		if (src_th < src_aff) {
		   tmp_src += blk_size;
		}
		tmp_dst = (UPCRI_COLL_RED_TYPE *)upcri_shared_to_remote_withthread(dst, mythread) - start_phase;
		skip = 0;
		if ((mythread < start_thread) ||
		    (((mythread == start_thread) && (start_phase >= sub_count)))) {
		    tmp_dst += blk_size;
		} else if (mythread == start_thread) {
		    skip = start_phase;
		}

		/* Bug2991: at this point tmp_count is always equal to my_count.
		   That is almost certainly wrong since at a minimum it means that
		   we are fetching elements that are overwritten by the later fetch
		   of the right-hand chunk.  However, in the case observed as bug2991
		   the situation is worse as we end up writting beyond the end of dst.
		   The obvious possible solution of computing the right-hand count
		   and subtracting it from the left-hand count did not work.
		 */
		_upcri_coll_strided_get(tmp_dst, src_th, tmp_src, sizeof(UPCRI_COLL_RED_TYPE), tmp_count, blk_size, sub_count, skip UPCRI_PT_PASS);

		/* Now for the right-hand chunk */
		offset = sub_count;
		sub_count = (blk_size - sub_count);
		if (src_th == upcri_threads - 1) {
		    src_th = 0;
		} else {
		    src_th += 1;
		}
		tmp_src = (UPCRI_COLL_RED_TYPE *)upcri_shared_to_remote_withthread(src, src_th) - src_phase;
		if ((src_th < src_aff) || ((src_th == src_aff) && (src_phase >= sub_count))) {
		   tmp_src += blk_size;
		}
		tmp_dst = (UPCRI_COLL_RED_TYPE *)upcri_shared_to_remote_withthread(dst, mythread)
										+ offset - start_phase;
		skip = 0;
		if (mythread == start_thread) {
		    skip = start_phase;
		} else if (mythread < start_thread) {
		    tmp_dst += blk_size;
		}
		if (skip < offset) {
		  tmp_count -= MIN(tmp_count, offset - skip);
		  skip = 0;
		} else {
		  skip -= offset;
		}
		if (tmp_count) {
		    _upcri_coll_strided_get(tmp_dst, src_th, tmp_src, sizeof(UPCRI_COLL_RED_TYPE), tmp_count, blk_size, sub_count, skip UPCRI_PT_PASS);
		}
#endif /* diables unequal phase case */
	    }
	}
    }
    
    /* STEP 5: Allocate local scratch space for partial results. (all threads)
     */
#if UPCRI_COLL_USE_LOCAL_TEMPS
    my_partial = upcri_malloc(partials * sizeof(UPCRI_COLL_RED_TYPE));
#else
    partial_sptr = upcr_alloc(partials * sizeof(UPCRI_COLL_RED_TYPE));
    my_partial = upcr_shared_to_local(partial_sptr);
#endif

    /* STEP 6: Perform a prefix reduction on local blocks. (all threads)
     */
    if (blk_size > 1) {
	UPCRI_COLL_RED_TYPE *tmp_dst = my_dst;
	size_t tmp_count = my_count;
	size_t this_row = first_row;

	/* Compute on the leading row, regardless of whether is is partial or full */
	if (tmp_count) {
	    my_partial[this_row++] = UPCRI_COLL_PREFIX_REDUCE_INNER(UPCRI_COLL_RED_SUFF)
						(*tmp_dst, tmp_dst + 1, op, first_row_count - 1, func);
	    tmp_count -= first_row_count;
	    tmp_dst += first_row_count;
	}
		
	/* Compute on full rows */
	while (tmp_count >= blk_size) {
	    my_partial[this_row++] = UPCRI_COLL_PREFIX_REDUCE_INNER(UPCRI_COLL_RED_SUFF)
						(*tmp_dst, tmp_dst + 1, op, blk_size - 1, func);
	    tmp_count -= blk_size;
	    tmp_dst += blk_size;
	}
			
	/* Compute trailing partial row, if any */
	if (tmp_count) {
	    my_partial[this_row++] = UPCRI_COLL_PREFIX_REDUCE_INNER(UPCRI_COLL_RED_SUFF)
						(*tmp_dst, tmp_dst + 1, op, tmp_count - 1, func);
	}
    } else {
	memcpy(&my_partial[first_row], my_dst, my_count * sizeof(UPCRI_COLL_RED_TYPE));
    }

    {
	/* STEP 7: SMP-level reduction (one thread on each node)
	 *
	 * NOT IMPLEMENTED
	 *
	 * XXX: We could add a simple smp-level reduction over local threads here.
	 * That would change the gather to be one partial result per node, rather than per thread.
	 * That will also require changing the final reduction logic to deal with
	 * missing contributions by nodes, rather than by threads.
	 */

	upcr_shared_ptr_t gath_sptr;
	UPCRI_COLL_RED_TYPE *gathered = NULL;

	/* STEP 8: Gather (all threads)
	 *
	 * This call contributes the local partial result(s) to a gather 
	 * targets the node to which the destination has affinity.
	 */
	if (start_thread == mythread) {
	    gath_sptr = upcr_alloc(upcri_threads * partials * sizeof(UPCRI_COLL_RED_TYPE));
	    gathered = upcr_shared_to_local(gath_sptr);
	}
	gasnet_coll_gather(GASNET_TEAM_ALL, start_thread, gathered, my_partial,
			   sizeof(UPCRI_COLL_RED_TYPE) * partials,
			   (GASNET_COLL_LOCAL |
			    GASNET_COLL_DST_IN_SEGMENT |
			    UPCRI_COLL_SRC_MIGHT_BE_LOCAL |
			    GASNET_COLL_IN_MYSYNC | GASNET_COLL_OUT_MYSYNC));

	if (start_thread == mythread) {
	    /* STEP 8: Prefix reduction of partials (one thread on destination node only)
	     *
	     * Note that this step is an "exclusive" prefix reduction, done in place.
	     * Note also that we are using the REDUCE_INNER, not PREFIX_REDUCE_INNER.
	     */
	    UPCRI_COLL_RED_TYPE *p;
	    UPCRI_COLL_RED_TYPE prev, next;
	    upcr_thread_t trailing_ths = end_thread + (end_phase?1:0);
	    int i, j;

	    /* Deal with the first row, regardless of whether is is partial or full */
	    j = rows ? upcri_threads : trailing_ths;
	    p = gathered + start_thread * partials;
	    prev = *p;
	    for (i = start_thread + 1; i < j; ++i) {
		p += partials;
		next = UPCRI_COLL_REDUCE_INNER(UPCRI_COLL_RED_SUFF)(prev, p, op, 1, func);
		*p = prev;
		prev = next;
	    }

	    /* Deal with full rows */
	    for (i = 1; i < rows; ++i) {
		p = gathered + i;
		for (j = 0; j < upcri_threads; ++j) {
		    next = UPCRI_COLL_REDUCE_INNER(UPCRI_COLL_RED_SUFF)(prev, p, op, 1, func);
		    *p = prev;
		    prev = next;
		    p += partials;
		}
	    }

	    /* Deal with the trailing partial row, if any */
	    if (rows && trailing_ths) {
		p = gathered + rows;
		for (i = 0; i < trailing_ths; ++i) {
		    next = UPCRI_COLL_REDUCE_INNER(UPCRI_COLL_RED_SUFF)(prev, p, op, 1, func);
		    *p = prev;
		    prev = next;
		    p += partials;
		}
	    }
	}

	/* STEP 9: Scatter (all threads)
	 *
	 * This call sends out the partials required to complete the computation
	 */
	gasnet_coll_scatter(GASNET_TEAM_ALL, my_partial, start_thread, gathered,
			    sizeof(UPCRI_COLL_RED_TYPE) * partials,
			    (GASNET_COLL_LOCAL |
			     GASNET_COLL_SRC_IN_SEGMENT |
			     UPCRI_COLL_DST_MIGHT_BE_LOCAL |
			     GASNET_COLL_IN_MYSYNC | GASNET_COLL_OUT_MYSYNC));

	if (start_thread == mythread) {
	    /* STEP 10: Free scatch space (one thread on destination node only)
	     */
	    upcr_free(gath_sptr);
	}
    }

    /* STEP 11: Perform the final prefix reduction on local blocks. (all threads)
     */
    if (blk_size > 1) {
	UPCRI_COLL_RED_TYPE *tmp_dst = my_dst;
	size_t tmp_count = my_count;
	UPCRI_COLL_RED_TYPE tmp;
	size_t this_row = first_row;
	int i;

	/* Compute on the leading row, regardless of whether is is partial or full */
	if (tmp_count) {
	    /* special case the first block */
	    if (mythread == start_thread) {
		tmp_dst += first_row_count;
		tmp_count -= first_row_count;
		this_row++;
	    } else {
		tmp = my_partial[this_row++];
		for (i = 0; i < first_row_count; ++i) {
		    (void)UPCRI_COLL_PREFIX_REDUCE_INNER(UPCRI_COLL_RED_SUFF)(tmp, tmp_dst++, op, 1, func);
		}
		tmp_count -= first_row_count;
	    }
	}
		
	/* Compute on full rows */
	while (tmp_count >= blk_size) {
	    tmp = my_partial[this_row++];
	    for (i = 0; i < blk_size; ++i) {
		(void)UPCRI_COLL_PREFIX_REDUCE_INNER(UPCRI_COLL_RED_SUFF)(tmp, tmp_dst++, op, 1, func);
	    }
	    tmp_count -= blk_size;
	}
			
	/* Compute trailing partial row, if any */
	if (tmp_count) {
	    tmp = my_partial[this_row++];
	    for (i = 0; i < tmp_count; ++i) {
		(void)UPCRI_COLL_PREFIX_REDUCE_INNER(UPCRI_COLL_RED_SUFF)(tmp, tmp_dst++, op, 1, func);
	    }
	}
    } else {
	UPCRI_COLL_RED_TYPE *tmp_dst = my_dst;
	size_t tmp_count = my_count;
	size_t this_row = first_row;
	int i;

	if (tmp_count) {
	    if (mythread == start_thread) {
		upcri_assert(first_row_count == 1);
		this_row++;
		tmp_count--;
		tmp_dst++;
	    }

	    for (i = 0; i < tmp_count; ++i) {
	      (void)UPCRI_COLL_PREFIX_REDUCE_INNER(UPCRI_COLL_RED_SUFF)
						(my_partial[this_row++], tmp_dst++, op, 1, func);
	    }
	}
    }

    /* STEP 11: Final barrier and free scratch space
     */
    if (sync_mode & UPC_OUT_ALLSYNC) {
	UPCRI_SINGLE_BARRIER();
    }
#if UPCRI_COLL_USE_LOCAL_TEMPS
    upcri_free(my_partial);
#else
    upcr_free(partial_sptr);
#endif

    upcri_pevt_end(GASP_UPC_ALL_PREFIX_REDUCE);
    #undef UPCRI_PEVT_ARGS
}

#endif /* UPCRI_BUILD_PREFIX_REDUCE */
/*----------------------------------------------------------------------------*/

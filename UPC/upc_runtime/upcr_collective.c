/*
 * UPC Collectives implementation on GASNet
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_collective.c $
 */

#include <upcr.h>
#include <upcr_internal.h>

/*----------------------------------------------------------------------------*/
/* Magical helpers */

#if (UPC_IN_ALLSYNC == 0) || (UPC_OUT_ALLSYNC == 0)
  #error "No longer support a upc_flag_t representation with zero-valued ALLSYNCs"
#endif

GASNETT_INLINE(upcri_coll_syncmode_only)
unsigned int upcri_coll_syncmode_only(upc_flag_t sync_mode) {
  unsigned int result;

  if (sync_mode & UPC_IN_NOSYNC) {
    result = GASNET_COLL_IN_NOSYNC;
  } else if (sync_mode & UPC_IN_MYSYNC) {
    result = GASNET_COLL_IN_MYSYNC;
  } else if (sync_mode & UPC_IN_ALLSYNC) {
    result = GASNET_COLL_IN_ALLSYNC;
  } else result = 0;

  if (sync_mode & UPC_OUT_NOSYNC) {
    result |= GASNET_COLL_OUT_NOSYNC;
  } else if (sync_mode & UPC_OUT_MYSYNC) {
    result |= GASNET_COLL_OUT_MYSYNC;
  } else if (sync_mode & UPC_OUT_ALLSYNC) {
    result |= GASNET_COLL_OUT_ALLSYNC;
  }

  return result;
}

GASNETT_INLINE(upcri_coll_syncmode)
unsigned int upcri_coll_syncmode(upc_flag_t sync_mode) {
  return GASNET_COLL_SINGLE |
	 GASNET_COLL_SRC_IN_SEGMENT | GASNET_COLL_DST_IN_SEGMENT |
	 upcri_coll_syncmode_only(sync_mode);
}

#define UPCRI_COLL_ONE_DST(D)	upcr_threadof_shared(D), upcri_shared_to_remote(D)
#define UPCRI_COLL_ONE_SRC(S)	upcr_threadof_shared(S), upcri_shared_to_remote(S)

#if UPCRI_SINGLE_ALIGNED_REGIONS
    #define UPCRI_COLL_MULTI_DST(D)	upcri_shared_to_remote(D)
    #define UPCRI_COLL_MULTI_SRC(S)	upcri_shared_to_remote(S)
    #define UPCRI_COLL_TEAM_MULTI_DST(TEAM, D)	upcri_shared_to_remote(D)
    #define UPCRI_COLL_TEAM_MULTI_SRC(TEAM, S)	upcri_shared_to_remote(S)
    #define UPCRI_COLL_GASNETIFY(NAME,ARGS)\
	_CONCAT(gasnet_coll_,NAME)ARGS;
    #define UPCRI_COLL_GASNETIFY_NB(NAME,ARGS)\
	_CONCAT(_CONCAT(gasnet_coll_,NAME),_nb)ARGS;
#else /* Multiple regions or single unaligned regions */
    GASNETT_INLINE(upcri_coll_shared_to_dstlist)
    void **upcri_coll_shared_to_dstlist(upcr_shared_ptr_t ptr UPCRI_PT_ARG) {
        void **result = upcri_auxdata()->coll_dstlist;
        upcr_thread_t i;
        for (i = 0; i < upcri_threads; ++i) {
	    result[i] = upcri_shared_to_remote_withthread(ptr, i);
        }
        return result;
    }
    #define UPCRI_COLL_MULTI_DST(D)		upcri_coll_shared_to_dstlist(D UPCRI_PT_PASS)

    GASNETT_INLINE(upcri_coll_team_shared_to_list)
    void **upcri_coll_team_shared_to_list(gasnet_team_handle_t team, upcr_shared_ptr_t ptr UPCRI_PT_ARG) {
      void **result = upcri_malloc(sizeof(void*) * gasnet_coll_team_size(team));
        upcr_thread_t i;
        for (i = 0; i < gasnet_coll_team_size(team); ++i) {
          result[i] = upcri_shared_to_remote_withthread(ptr, gasnet_coll_team_rank2node(team,i));
        }
        return result;
    }
    #define UPCRI_COLL_TEAM_MULTI_DST(TEAM, D)		upcri_coll_team_shared_to_list(TEAM, D UPCRI_PT_PASS)
    #define UPCRI_COLL_TEAM_MULTI_SRC(TEAM, S)		upcri_coll_team_shared_to_list(TEAM, S UPCRI_PT_PASS)

    GASNETT_INLINE(upcri_coll_shared_to_srclist)
    void **upcri_coll_shared_to_srclist(upcr_shared_ptr_t ptr UPCRI_PT_ARG) {
        void **result = upcri_auxdata()->coll_srclist;
        upcr_thread_t i;
        for (i = 0; i < upcri_threads; ++i) {
	    result[i] = upcri_shared_to_remote_withthread(ptr, i);
        }
        return result;
    }
    #define UPCRI_COLL_MULTI_SRC(S)		upcri_coll_shared_to_srclist(S UPCRI_PT_PASS)
    #define UPCRI_COLL_GASNETIFY(NAME,ARGS)\
	_CONCAT(_CONCAT(gasnet_coll_,NAME),M)ARGS;
    #define UPCRI_COLL_GASNETIFY_NB(NAME,ARGS)\
	_CONCAT(_CONCAT(_CONCAT(gasnet_coll_,NAME),M),_nb)ARGS;
#endif

#define UPCRI_TRACE_COLL(name, nbytes) \
	UPCRI_TRACE_PRINTF(("COLLECTIVE UPC_ALL_" _STRINGIFY(name) ": sz = %6llu", (long long unsigned)(nbytes)))

void bupc_coll_wait(bupc_coll_handle_t handle) {
  gasnet_coll_wait_sync((gasnet_coll_handle_t) handle);
}

bupc_team_t _upcr_team_split(bupc_team_t parent_team, int mycolor, int myrelrank UPCRI_PT_ARG) {
  gasnet_seginfo_t myscratch;
  upcr_shared_ptr_t scratch_addr;
  scratch_addr = upcr_alloc(UPCR_COLLECTIVE_SCRATCH_SIZE);
  myscratch.addr = upcr_shared_to_local(scratch_addr);
  myscratch.size = UPCR_COLLECTIVE_SCRATCH_SIZE;
  return (bupc_team_t) gasnet_coll_team_split((gasnet_team_handle_t) parent_team, mycolor, myrelrank, &myscratch);
}

void bupc_load_coll_tuning_file(bupc_team_t team, char *file) {
  gasnet_coll_loadTuningState(file, (gasnet_team_handle_t)team);
}

extern void bupc_store_coll_tuning_file(bupc_team_t team, char *file) {
  gasnet_coll_dumpTuningState(file, (gasnet_team_handle_t)team);
}

/*----------------------------------------------------------------------------*/
/* Data movement collectives
 *
 * With the aid of the helpers above, these functions compile correctly
 * with and without aligned segments and with and without pthreads.
 */

void _upcr_all_broadcast(upcr_shared_ptr_t dst,
                         upcr_shared_ptr_t src,
                         size_t nbytes,
                         upc_flag_t sync_mode
                         UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    sync_mode = upcri_coll_fixsync(sync_mode);
    UPCRI_STRICT_HOOK_IF(sync_mode & UPC_IN_ALLSYNC);
    UPCRI_TRACE_COLL(BROADCAST, nbytes);
    #define UPCRI_PEVT_ARGS , &dst, &src, nbytes, (int)sync_mode
    upcri_pevt_start(GASP_UPC_ALL_BROADCAST);
    UPCRI_COLL_GASNETIFY(broadcast,
				(GASNET_TEAM_ALL,
				 UPCRI_COLL_MULTI_DST(dst),
				 UPCRI_COLL_ONE_SRC(src),
				 nbytes, upcri_coll_syncmode(sync_mode)));
    upcri_pevt_end(GASP_UPC_ALL_BROADCAST);
    #undef UPCRI_PEVT_ARGS
}

bupc_coll_handle_t _upcr_team_broadcast(bupc_team_t team, upcr_shared_ptr_t dst,
                                        upcr_shared_ptr_t src,
                                        size_t nbytes,
                                        upc_flag_t sync_mode
                                        UPCRI_PT_ARG)
{
  gasnet_coll_handle_t handle;
  gasnet_node_t relroot = gasnet_coll_team_node2rank(team, upcr_threadof_shared(src));
#if !UPCRI_SINGLE_ALIGNED_REGIONS
  void **tmp_dst_list;
#else
  void *tmp_dst_list;
#endif
  UPCRI_PASS_GAS();
  if(relroot >= gasnet_coll_team_size(team)) {
    fprintf(stderr, "BAD RELATIVE ROOT: %d (act: %d) needs to be between: 0 and %d\n", (int)relroot, upcr_threadof_shared(src), (int)gasnet_coll_team_size(team));
  }
  
  sync_mode = upcri_coll_fixsync(sync_mode);
  UPCRI_STRICT_HOOK_IF(sync_mode & UPC_IN_ALLSYNC);
  UPCRI_TRACE_COLL(BROADCAST, nbytes);
#define UPCRI_PEVT_ARGS , &dst, &src, nbytes, (int)sync_mode
  upcri_pevt_start(GASP_UPC_ALL_BROADCAST);
  tmp_dst_list = UPCRI_COLL_TEAM_MULTI_DST(team, dst);
  handle = UPCRI_COLL_GASNETIFY_NB(broadcast,
                                   ((gasnet_team_handle_t) team,
                                    tmp_dst_list,
                                    relroot, upcri_shared_to_remote(src),
                                    nbytes, upcri_coll_syncmode(sync_mode)));
#if !UPCRI_SINGLE_ALIGNED_REGIONS
  upcri_free(tmp_dst_list);
#endif
  
  upcri_pevt_end(GASP_UPC_ALL_BROADCAST);
#undef UPCRI_PEVT_ARGS
  return (bupc_coll_handle_t) handle;
}



void _upcr_all_scatter(upcr_shared_ptr_t dst,
                       upcr_shared_ptr_t src,
                       size_t nbytes,
                       upc_flag_t sync_mode
                       UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    sync_mode = upcri_coll_fixsync(sync_mode);
    UPCRI_STRICT_HOOK_IF(sync_mode & UPC_IN_ALLSYNC);
    UPCRI_TRACE_COLL(SCATTER, nbytes);
    #define UPCRI_PEVT_ARGS , &dst, &src, nbytes, (int)sync_mode
    upcri_pevt_start(GASP_UPC_ALL_SCATTER);
    UPCRI_COLL_GASNETIFY(scatter,
				(GASNET_TEAM_ALL,
				 UPCRI_COLL_MULTI_DST(dst),
				 UPCRI_COLL_ONE_SRC(src),
				 nbytes, upcri_coll_syncmode(sync_mode)));
    upcri_pevt_end(GASP_UPC_ALL_SCATTER);
    #undef UPCRI_PEVT_ARGS
}

void _upcr_all_gather(upcr_shared_ptr_t dst,
                      upcr_shared_ptr_t src,
                      size_t nbytes,
                      upc_flag_t sync_mode
                      UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    sync_mode = upcri_coll_fixsync(sync_mode);
    UPCRI_TRACE_COLL(GATHER, nbytes);
    #define UPCRI_PEVT_ARGS , &dst, &src, nbytes, (int)sync_mode
    upcri_pevt_start(GASP_UPC_ALL_GATHER);
    UPCRI_COLL_GASNETIFY(gather,
				(GASNET_TEAM_ALL,
				 UPCRI_COLL_ONE_DST(dst),
				 UPCRI_COLL_MULTI_SRC(src),
				 nbytes, upcri_coll_syncmode(sync_mode)));
    upcri_pevt_end(GASP_UPC_ALL_GATHER);
    #undef UPCRI_PEVT_ARGS
}

void _upcr_all_gather_all(upcr_shared_ptr_t dst,
                          upcr_shared_ptr_t src,
                          size_t nbytes,
                          upc_flag_t sync_mode
                          UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    sync_mode = upcri_coll_fixsync(sync_mode);
    UPCRI_STRICT_HOOK_IF(sync_mode & UPC_IN_ALLSYNC);
    UPCRI_TRACE_COLL(GATHER_ALL, nbytes);
    #define UPCRI_PEVT_ARGS , &dst, &src, nbytes, (int)sync_mode
    upcri_pevt_start(GASP_UPC_ALL_GATHER_ALL);
    UPCRI_COLL_GASNETIFY(gather_all,
				(GASNET_TEAM_ALL,
				 UPCRI_COLL_MULTI_DST(dst),
				 UPCRI_COLL_MULTI_SRC(src),
				 nbytes, upcri_coll_syncmode(sync_mode)));
    upcri_pevt_end(GASP_UPC_ALL_GATHER_ALL);
    #undef UPCRI_PEVT_ARGS
}

void _upcr_all_exchange(upcr_shared_ptr_t dst,
                        upcr_shared_ptr_t src,
                        size_t nbytes,
                        upc_flag_t sync_mode
                        UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    sync_mode = upcri_coll_fixsync(sync_mode);
    UPCRI_STRICT_HOOK_IF(sync_mode & UPC_IN_ALLSYNC);
    UPCRI_TRACE_COLL(EXCHANGE, nbytes);
    #define UPCRI_PEVT_ARGS , &dst, &src, nbytes, (int)sync_mode
    upcri_pevt_start(GASP_UPC_ALL_EXCHANGE);
    UPCRI_COLL_GASNETIFY(exchange,
				(GASNET_TEAM_ALL,
				 UPCRI_COLL_MULTI_DST(dst),
				 UPCRI_COLL_MULTI_SRC(src),
				 nbytes, upcri_coll_syncmode(sync_mode)));
    upcri_pevt_end(GASP_UPC_ALL_EXCHANGE);
    #undef UPCRI_PEVT_ARGS
}

bupc_coll_handle_t _upcr_team_exchange(bupc_team_t team, upcr_shared_ptr_t dst,
                                       upcr_shared_ptr_t src,
                                       size_t nbytes,
                                       upc_flag_t sync_mode
                                       UPCRI_PT_ARG)

{
  gasnet_coll_handle_t handle;

  
  UPCRI_PASS_GAS();
  sync_mode = upcri_coll_fixsync(sync_mode);
  UPCRI_STRICT_HOOK_IF(sync_mode & UPC_IN_ALLSYNC);
  UPCRI_TRACE_COLL(EXCHANGE, nbytes);
#define UPCRI_PEVT_ARGS , &dst, &src, nbytes, (int)sync_mode
  upcri_pevt_start(GASP_UPC_ALL_EXCHANGE);

#if UPCRI_SINGLE_ALIGNED_REGIONS
  handle = gasnet_coll_exchange_nb((gasnet_team_handle_t) team,
                                    upcr_shared_to_local(dst), upcr_shared_to_local(src), 
                                   nbytes, 
                                   upcri_coll_syncmode_only(sync_mode) | 
                                   GASNET_COLL_SINGLE|GASNET_COLL_DST_IN_SEGMENT
                                   |GASNET_COLL_SRC_IN_SEGMENT);
#else
    handle = gasnet_coll_exchange_nb((gasnet_team_handle_t) team,
                                    upcr_shared_to_local(dst), upcr_shared_to_local(src), 
                                     nbytes, 
                                     upcri_coll_syncmode_only(sync_mode) | 
                                     GASNET_COLL_LOCAL|GASNET_COLL_DST_IN_SEGMENT
                                     |GASNET_COLL_SRC_IN_SEGMENT);
#endif
  upcri_pevt_end(GASP_UPC_ALL_EXCHANGE);
#undef UPCRI_PEVT_ARGS
  return (bupc_coll_handle_t) handle;
}


/* GASNet interface not yet (ever?) specified */
/* This one is an odd ball regardless, and may never follow the template */
void _upcr_all_permute(upcr_shared_ptr_t dst,
                       upcr_shared_ptr_t src,
                       upcr_pshared_ptr_t perm,
                       size_t nbytes,
                       upc_flag_t sync_mode
                       UPCRI_PT_ARG)
{
#if UPCRI_UPC_PTHREADS
    const int thread_count = upcri_mypthreads();
    const int first_thread = upcri_1stthread(gasnet_mynode());
    const int i_am_master = (upcri_mypthread() == 0);
#else
    const int thread_count = 1;
    const int first_thread = upcr_mythread();
    const int i_am_master = 1;
#endif
    #if UPCRI_GASP
      upcr_shared_ptr_t permtmp = upcr_pshared_to_shared(perm);
    #endif
    int i;
    sync_mode = upcri_coll_fixsync(sync_mode);
    UPCRI_STRICT_HOOK_IF(sync_mode & UPC_IN_ALLSYNC);
    UPCRI_TRACE_COLL(PERMUTE, nbytes);

    #define UPCRI_PEVT_ARGS , &dst, &src, &permtmp, nbytes, (int)sync_mode
    upcri_pevt_start(GASP_UPC_ALL_PERMUTE);

    if (!(sync_mode & UPC_IN_NOSYNC)) {
	UPCRI_SINGLE_BARRIER();
    }
    if (i_am_master) { /* One distinguished thread per node does all the work */
	for (i = 0; i < thread_count; ++i) {
	    /* XXX: use puti? */
	    upcr_thread_t dst_th = *((int *)upcri_pshared_to_remote_withthread(perm, first_thread+i));
	    void *dst_addr = upcri_shared_to_remote_withthread(dst, dst_th);
	    void *src_addr = upcri_shared_to_remote_withthread(src, first_thread+i);
    
	    if (upcri_thread_is_addressable(dst_th)) {
		UPCRI_UNALIGNED_MEMCPY(UPCRI_COLL_LOCALIZE(dst_addr, dst_th), src_addr, nbytes);
	    } else {
		gasnet_put_nbi_bulk(upcri_thread_to_node(dst_th), dst_addr, src_addr, nbytes);
	    }
	}
        gasnet_wait_syncnbi_puts();
    }
    if (!(sync_mode & UPC_OUT_NOSYNC)) {
	UPCRI_SINGLE_BARRIER();
    }

    upcri_pevt_end(GASP_UPC_ALL_PERMUTE);
    #undef UPCRI_PEVT_ARGS
}

/*----------------------------------------------------------------------------*/

#if defined(GASNET_TRACE) || defined(UPCRI_USE_FCA)
const char *upcri_op2str(upc_op_t op) {
    switch (op) {
        case UPC_NONCOMM_FUNC: return("UPC_NONCOMM_FUNC");
        case UPC_FUNC:   return("UPC_FUNC");
        case UPC_ADD:    return("UPC_ADD");
        case UPC_MULT:   return("UPC_MULT");
        case UPC_MIN:    return("UPC_MIN");
        case UPC_MAX:    return("UPC_MAX");
        case UPC_AND:    return("UPC_AND");
        case UPC_OR:     return("UPC_OR");
        case UPC_LOGAND: return("UPC_LOGAND");
        case UPC_LOGOR:  return("UPC_LOGOR");
        case UPC_XOR:    return("UPC_XOR");
    }
    return "INVALID";
}
#endif

/*----------------------------------------------------------------------------*/

/*
 * UPC Collectives implementation on GASNet
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_collective.h $
 */

/* Include upc_bits.h and upc_collective_bits.h for upc_flag_t and constants */
#include <upcr_preinclude/upc_bits.h>
#include <upcr_preinclude/upc_collective_bits.h>

#define UPCR_COLLECTIVE_SCRATCH_SIZE 2*1024*1024

extern void upcri_coll_init(void);
extern void _upcri_coll_init_thread(UPCRI_PT_ARG_ALONE);
#define upcri_coll_init_thread() _upcri_coll_init_thread(UPCRI_PT_PASS_ALONE)



extern void _upcr_all_broadcast(upcr_shared_ptr_t dst, upcr_shared_ptr_t src,
                                size_t nbytes, upc_flag_t sync_mode UPCRI_PT_ARG);
extern bupc_coll_handle_t _upcr_team_broadcast(bupc_team_t team, upcr_shared_ptr_t dst, upcr_shared_ptr_t src,
                                size_t nbytes, upc_flag_t sync_mode UPCRI_PT_ARG);
extern void _upcr_all_scatter(upcr_shared_ptr_t dst, upcr_shared_ptr_t src,
                              size_t nbytes, upc_flag_t sync_mode UPCRI_PT_ARG);
extern void _upcr_all_gather(upcr_shared_ptr_t dst, upcr_shared_ptr_t src,
                             size_t nbytes, upc_flag_t sync_mode UPCRI_PT_ARG);
extern void _upcr_all_gather_all(upcr_shared_ptr_t dst, upcr_shared_ptr_t src,
                                 size_t nbytes, upc_flag_t sync_mode UPCRI_PT_ARG);
extern void _upcr_all_exchange(upcr_shared_ptr_t dst, upcr_shared_ptr_t src,
                               size_t nbytes, upc_flag_t sync_mode UPCRI_PT_ARG);

extern bupc_coll_handle_t _upcr_team_exchange(bupc_team_t team, upcr_shared_ptr_t dst, upcr_shared_ptr_t src,
                               size_t nbytes, upc_flag_t sync_mode UPCRI_PT_ARG);

extern void _upcr_all_permute(upcr_shared_ptr_t dst, upcr_shared_ptr_t src, upcr_pshared_ptr_t perm,
                              size_t nbytes, upc_flag_t sync_mode UPCRI_PT_ARG);

extern bupc_team_t _upcr_team_split(bupc_team_t parent_team, int mycolor, int myrelrank UPCRI_PT_ARG);
#if !UPCRI_LIBWRAP
#define bupc_team_split(parent_team, mycolor, myrelrank) \
	(upcri_srcpos(), _upcr_team_split(parent_team, mycolor, myrelrank UPCRI_PT_PASS))

#define bupc_all_broadcast(dst,src,nbytes,mode) \
	(upcri_srcpos(), _upcr_all_broadcast(dst,src,nbytes,mode UPCRI_PT_PASS))
#define bupc_team_broadcast(team,dst,src,nbytes,mode)              \
	(upcri_srcpos(), _upcr_team_broadcast(team,dst,src,nbytes,mode UPCRI_PT_PASS))
#define bupc_all_scatter(dst,src,nbytes,mode) \
	(upcri_srcpos(), _upcr_all_scatter(dst,src,nbytes,mode UPCRI_PT_PASS))
#define bupc_all_gather(dst,src,nbytes,mode) \
	(upcri_srcpos(), _upcr_all_gather(dst,src,nbytes,mode UPCRI_PT_PASS))
#define bupc_all_gather_all(dst,src,nbytes,mode) \
	(upcri_srcpos(), _upcr_all_gather_all(dst,src,nbytes,mode UPCRI_PT_PASS))
#define bupc_all_exchange(dst,src,nbytes,mode) \
	(upcri_srcpos(), _upcr_all_exchange(dst,src,nbytes,mode UPCRI_PT_PASS))
#define bupc_team_exchange(team, dst,src,nbytes,mode)                     \
	(upcri_srcpos(), _upcr_team_exchange(team, dst,src,nbytes,mode UPCRI_PT_PASS))
#define bupc_all_permute(dst,src,perm,nbytes,mode) \
	(upcri_srcpos(), _upcr_all_permute(dst,src,perm,nbytes,mode UPCRI_PT_PASS))
#endif

#define UPCRI_UPCR_REDUCE_PROTOTYPES(typecode,fulltype)                          \
  extern void _upcr_all_reduce##typecode(upcr_shared_ptr_t _dst,                 \
                                 upcr_shared_ptr_t _src,                         \
                                 upc_op_t _op, size_t _nelems, size_t _blk_size, \
                                 fulltype (*_func)(fulltype,fulltype),           \
                                 upc_flag_t _sync_mode, int bcast UPCRI_PT_ARG); \
  extern void _upcr_all_prefix_reduce##typecode(upcr_shared_ptr_t _dst,          \
                                 upcr_shared_ptr_t _src,                         \
                                 upc_op_t _op, size_t _nelems, size_t _blk_size, \
                                 fulltype (*_func)(fulltype,fulltype),           \
                                 upc_flag_t _sync_mode UPCRI_PT_ARG);                    

UPCRI_UPCR_REDUCE_PROTOTYPES(C,  signed char)
UPCRI_UPCR_REDUCE_PROTOTYPES(UC, unsigned char)
UPCRI_UPCR_REDUCE_PROTOTYPES(S,  signed short)
UPCRI_UPCR_REDUCE_PROTOTYPES(US, unsigned short)
UPCRI_UPCR_REDUCE_PROTOTYPES(I,  signed int)
UPCRI_UPCR_REDUCE_PROTOTYPES(UI, unsigned int)
UPCRI_UPCR_REDUCE_PROTOTYPES(L,  signed long)
UPCRI_UPCR_REDUCE_PROTOTYPES(UL, unsigned long)
UPCRI_UPCR_REDUCE_PROTOTYPES(F,  float)
UPCRI_UPCR_REDUCE_PROTOTYPES(D,  double)
UPCRI_UPCR_REDUCE_PROTOTYPES(LD, UPCRI_COLL_LONG_DOUBLE)

#if !UPCRI_LIBWRAP

#define bupc_all_reduceC(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceC(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allC(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceC(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceUC(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceUC(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allUC(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceUC(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceS(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceS(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allS(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceS(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceUS(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceUS(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allUS(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceUS(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceI(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceI(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allUI(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceUI(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceUI(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceUI(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allI(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceI(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceL(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceL(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allL(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceL(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceUL(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceUL(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allUL(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceUL(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceF(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceF(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allF(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceF(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceD(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceD(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allD(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceD(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))
#define bupc_all_reduceLD(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceLD(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,0 UPCRI_PT_PASS))
#define bupc_all_reduce_allLD(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_reduceLD(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode,1 UPCRI_PT_PASS))

#define bupc_all_prefix_reduceC(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceC(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceUC(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceUC(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceS(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceS(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceUS(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceUS(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceI(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceI(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceUI(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceUI(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceL(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceL(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceUL(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceUL(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceF(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceF(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceD(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceD(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))
#define bupc_all_prefix_reduceLD(dst,src,op,nelems,blk_sz,func,sync_mode) \
	(upcri_srcpos(), _upcr_all_prefix_reduceLD(dst,src,(upc_op_t)(op),nelems,blk_sz,func,sync_mode UPCRI_PT_PASS))

#endif /* !UPCRI_LIBWRAP */


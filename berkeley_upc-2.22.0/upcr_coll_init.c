/*
 * UPC Collectives initialization over GASNet
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_coll_init.c $
 */

#include <upcr.h>
#include <upcr_internal.h>

/*----------------------------------------------------------------------------*/
/* Initialization, global variables */
bupc_team_t bupc_team_all;


#define SET_DEFAULT_TEAMS() do {\
    bupc_team_all = (void*) GASNET_TEAM_ALL;     \
  } while(0)
#if UPCRI_SINGLE_ALIGNED_REGIONS
    void upcri_coll_init(void) {
        gasnet_coll_init(NULL, 0 /* ignored */, NULL, 0 , 0);
        SET_DEFAULT_TEAMS();
    }
    void _upcri_coll_init_thread(UPCRI_PT_ARG_ALONE) {
        /* No per-thread work */
    }
#elif UPCRI_UPC_PTHREADS
    void upcri_coll_init(void) {
        /* Nothing to do */
    }
    void _upcri_coll_init_thread(UPCRI_PT_ARG_ALONE) {
        UPCRI_PASS_GAS();
        gasnet_node_t nodes = gasnet_nodes();
        gasnet_image_t *tmp_node2pthreads = upcri_malloc(sizeof(gasnet_image_t) * nodes);
        int i;
    
        for (i = 0; i < nodes; ++i) {
	    tmp_node2pthreads[i] = upcri_pthreads(i);
        }
        gasnet_coll_init(tmp_node2pthreads, upcr_mythread(), NULL, 0, 0);
        SET_DEFAULT_TEAMS();
        upcri_free(tmp_node2pthreads);
        (upcri_auxdata()->coll_dstlist) = upcri_malloc(upcri_threads * sizeof(void *));
	(upcri_auxdata()->coll_srclist) = upcri_malloc(upcri_threads * sizeof(void *));
    }
#else /* single unaligned regions */
    void upcri_coll_init(void) {
        (upcri_auxdata()->coll_dstlist) = upcri_malloc(upcri_threads * sizeof(void *));
        (upcri_auxdata()->coll_srclist) = upcri_malloc(upcri_threads * sizeof(void *));
        gasnet_coll_init(NULL, 0/* ignored */, NULL, 0, 0);
        SET_DEFAULT_TEAMS();
    }
    void _upcri_coll_init_thread(UPCRI_PT_ARG_ALONE) {
        /* No per-thread work */
    }
#endif

/*----------------------------------------------------------------------------*/

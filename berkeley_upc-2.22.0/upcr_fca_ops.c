/*
 * Copyright (c)  2012, Mellanox Technologies LTD. All rights reserved.
 */

#include <stdio.h>
#include "upcr_internal.h"

#ifdef UPCRI_USE_FCA

#include "fca/gasnet_fca.h"
#include "upcr_fca.h"
#include "upcr_fca_inlines.h" 

int upcr_my_partial_dummy_init(void *my_partial, upc_op_t op, fca_reduce_type_t type){
    int type_size = size_of_type(type);
    switch(op){
        case UPC_AND:
            memset(my_partial,UCHAR_MAX,type_size);
            break;
        case UPC_LOGAND:
            memset(my_partial,1,type_size);
            break;
        case UPC_OR:
        case UPC_LOGOR:
        case UPC_XOR:
        case UPC_ADD:
            memset(my_partial,0,type_size);
            break;
        case UPC_MAX:
            set_min(my_partial,type);
            break;
        case UPC_MIN:
            set_max(my_partial,type);
            break;
        case UPC_MULT:
            set_one(my_partial,type);
            break;
        default:
            break;
    }
    return 0;
}

int upcr_fca_reduce(int root,  void *target, const void *source, upc_op_t op, fca_reduce_type_t type, int upc_flag)
{
    int fca_dtype;
    int fca_op;
    int gasnet_flag=0;
    if ( (fca_dtype = upc_dtype_to_fca_dtype(type)) < 0){
        FCA_VERBOSE(5,"UPC_DATA_TYPE = %i is unsupported in the current version of FCA library; using original reduce",fca_dtype);
        return UPCR_FCA_ERROR;
    }
    if ( (fca_op = upc_op_to_fca_op(op)) < 0){
        FCA_VERBOSE(5,"UPC_OPERATION_TYPE = %s is unsupported; using original reduce",upcri_op2str(op));
        return UPCR_FCA_ERROR;
    }
    if (upc_flag & UPC_IN_ALLSYNC) gasnet_flag |= GASNET_COLL_IN_ALLSYNC;
    if (upc_flag & UPC_OUT_ALLSYNC) gasnet_flag |= GASNET_COLL_OUT_ALLSYNC;
    return gasnet_fca_reduce(root,target,source,fca_op,fca_dtype,1,GASNET_TEAM_ALL, gasnet_flag);
}

int upcr_fca_reduce_all( void *target, const void *source, upc_op_t op, fca_reduce_type_t type, int upc_flag)
{
    int fca_dtype;
    int fca_op;
    int gasnet_flag=0;
    if ( (fca_dtype = upc_dtype_to_fca_dtype(type)) < 0){
        FCA_VERBOSE(5,"UPC_DATA_TYPE = %i is unsupported in the current version of FCA library; using original reduce",fca_dtype);
        return UPCR_FCA_ERROR;
    }
    if ( (fca_op = upc_op_to_fca_op(op)) < 0){
        FCA_VERBOSE(5,"UPC_OPERATION_TYPE = %s is unsupported; using original reduce",upcri_op2str(op));
        return UPCR_FCA_ERROR;
    }

    if (upc_flag & UPC_IN_ALLSYNC) gasnet_flag |= GASNET_COLL_IN_ALLSYNC;
    if (upc_flag & UPC_OUT_ALLSYNC) gasnet_flag |= GASNET_COLL_OUT_ALLSYNC;
    return gasnet_fca_reduce_all(target,source,fca_op,fca_dtype,1,GASNET_TEAM_ALL,gasnet_flag);
}

#endif /* UPCRI_USE_FCA */

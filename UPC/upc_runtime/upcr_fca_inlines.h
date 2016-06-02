/*
 * Copyright (c)  2012, Mellanox Technologies LTD. All rights reserved.
 */
#include "upcr_fca.h"
#include "fca/gasnet_fca.h"
#include <limits.h>
#include <float.h>
#include <string.h>
#define UPCR_FCA_ERROR GASNET_FCA_ERROR

GASNETT_INLINE(if_floating_type)
int if_floating_type(fca_reduce_type_t type)
{
    if ((type==fca_f)  ||       (type == fca_d)  ||  (type == fca_ld))
        return 1;
    else
        return 0;
}

GASNETT_INLINE(size_of_type)
int size_of_type(fca_reduce_type_t type)
{
    switch(type){
        case fca_sc:
            return sizeof(signed char);
            break;
        case fca_uc:
            return sizeof(unsigned char);
            break;
        case fca_ss:
            return sizeof(signed short);
            break;
        case fca_us:
            return sizeof(unsigned short);
            break;
        case fca_si:
            return sizeof(signed int);
            break;
        case fca_ui:
            return sizeof(unsigned int);
            break;
        case fca_sl:
            return sizeof(signed long);
            break;
        case fca_ul:
            return sizeof(unsigned long);
            break;
        case fca_f:
            return sizeof(float);
            break;
        case fca_d:
            return sizeof(double);
            break;
        case fca_ld:
            return sizeof(long double);
            break;
        default:
            return 0;
    }
}


GASNETT_INLINE(_signed)
int _signed(fca_reduce_type_t type)
{
    if ((type == fca_uc) || (type == fca_us) || (type == fca_ui) || (type == fca_ul))
        return 0;
    else
        return 1;
}

GASNETT_INLINE(upc_dtype_to_fca_dtype)
int upc_dtype_to_fca_dtype(fca_reduce_type_t type)
{
    int type_size = size_of_type(type)*8;
    switch(type_size){
        case 64:
            if (if_floating_type(type))
                return FCA_DTYPE_DOUBLE;
            else if (_signed(type))
                return FCA_DTYPE_LONG;
            else
                return FCA_DTYPE_UNSIGNED_LONG;
            break;
        case 32:
            if (if_floating_type(type))
                return FCA_DTYPE_FLOAT;
            else if (_signed(type))
                return FCA_DTYPE_INT;
            else 
                return FCA_DTYPE_UNSIGNED;
            break;
        case 16:
            if (if_floating_type(type))
                return UNSUPPORTED_OP;
            else if (_signed(type))
                return FCA_DTYPE_SHORT;
            else 
                return FCA_DTYPE_UNSIGNED_SHORT;
            break;
        case 8: 
            if (if_floating_type(type))
                return UNSUPPORTED_OP;
            else if (_signed(type))       
                return FCA_DTYPE_CHAR;
            else 
                return FCA_DTYPE_UNSIGNED_CHAR;
            break;
        default:
            return UNSUPPORTED_OP;
    }
}


GASNETT_INLINE(upc_op_to_fca_op)
int upc_op_to_fca_op(upc_op_t op)
{
    switch(op){
        case UPC_AND:
            return FCA_OP_BAND;
            break;
        case UPC_OR:
            return FCA_OP_BOR;
            break;
        case UPC_XOR:
            return FCA_OP_BXOR;
        case UPC_MAX:
            return FCA_OP_MAX;
            break;
        case UPC_MIN:
            return FCA_OP_MIN;
            break;
        case UPC_ADD:
            return FCA_OP_SUM;
            break;
        case UPC_MULT:
            return FCA_OP_PROD;
            break;
        case UPC_LOGAND:
            return FCA_OP_LAND;
            break;
        case UPC_LOGOR:
            return FCA_OP_LOR;
            break;
        default:
            return UNSUPPORTED_OP;
    }
}

GASNETT_INLINE(set_one)
int set_one(void *my_partial, fca_reduce_type_t type){
    switch(type){
        case fca_sc:
            *(signed char *)my_partial = 1;
            break;
        case fca_uc:
            *(unsigned char *)my_partial = 1;
            break;
        case fca_ss:
            *(signed short *)my_partial = 1;
            break;
        case fca_us:
            *(unsigned short *)my_partial = 1;
            break;
        case fca_si:
            *(signed int *)my_partial = 1;
            break;
        case fca_ui:
            *(unsigned int *)my_partial = 1;
            break;
        case fca_sl:
            *(signed long *)my_partial = 1;
            break;
        case fca_ul:
            *(unsigned long *)my_partial = 1;
            break;
        case fca_f:
            *(float *)my_partial = 1;
            break;
        case fca_d:
            *(double *)my_partial = 1;
            break;
        case fca_ld:
            *(long double *)my_partial = 1;
            break;
        default:
            return 1;
    }
    return 0;
}

GASNETT_INLINE(set_max)
int set_max(void *my_partial, fca_reduce_type_t type){
    switch(type){
        case fca_sc:
            *(signed char *)my_partial = SCHAR_MAX;
            break;
        case fca_uc:
            *(unsigned char *)my_partial = UCHAR_MAX;
            break;
        case fca_ss:
            *(signed short *)my_partial = SHRT_MAX;
            break;
        case fca_us:
            *(unsigned short *)my_partial = USHRT_MAX;
            break;
        case fca_si:
            *(signed int *)my_partial = INT_MAX;
            break;
        case fca_ui:
            *(unsigned int *)my_partial = UINT_MAX;
            break;
        case fca_sl:
            *(signed long *)my_partial = LONG_MAX;
            break;
        case fca_ul:
            *(unsigned long *)my_partial = ULONG_MAX;
            break;
        case fca_f:
            *(float *)my_partial = FLT_MAX;
            break;
        case fca_d:
            *(double *)my_partial = DBL_MAX;
            break;
        case fca_ld:
            *(long double *)my_partial = LDBL_MAX;
            break;
        default:
            return 1;
    }
    return 0;
}

GASNETT_INLINE(set_min)
int set_min(void *my_partial, fca_reduce_type_t type){
    switch(type){
        case fca_sc:
            *(signed char *)my_partial = SCHAR_MIN;
            break;
        case fca_uc:
            *(unsigned char *)my_partial = 0;
            break;
        case fca_ss:
            *(signed short *)my_partial = SHRT_MIN;
            break;
        case fca_us:
            *(unsigned short *)my_partial = 0;
            break;
        case fca_si:
            *(signed int *)my_partial = INT_MIN;
            break;
        case fca_ui:
            *(unsigned int *)my_partial = 0;
            break;
        case fca_sl:
            *(signed long *)my_partial = LONG_MIN;
            break;
        case fca_ul:
            *(unsigned long *)my_partial = 0;
            break;
        case fca_f:
            *(float *)my_partial = FLT_MIN;
            break;
        case fca_d:
            *(double *)my_partial = DBL_MIN;
            break;
        case fca_ld:
            *(long double *)my_partial = LDBL_MIN;
            break;
        default:
            return 1;
    }
    return 0;
}

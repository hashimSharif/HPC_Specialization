/* Reference implementation of upc_types.h 
 * Written by Dan Bonachea 
 * Copyright 2012, The Regents of the University of California 
 * See LICENSE.TXT for licensing information.
 * This implementation of the header is specifically designed to avoid interference 
 * if some subset of its symbols are already defined by a previously included header
 */

#ifndef _RUPC_TYPES_H
#define _RUPC_TYPES_H

/* pickup any potential defines from the UPC compiler */
#ifdef __UPC__  /* ensure this header is strictly conformant C99 */
#include <upc.h> 
#endif
#ifdef __UPC_COLLECTIVE__
#include <upc_collective.h>
#endif

#ifndef UPC_ADD

#ifndef upc_op_t
#define upc_op_t rupc_op_t
typedef unsigned long rupc_op_t;
#endif

#define UPC_ADD         (1UL<<0)
#define UPC_MULT        (1UL<<1)
#define UPC_AND         (1UL<<2)
#define UPC_OR          (1UL<<3)
#define UPC_XOR         (1UL<<4)
#define UPC_LOGAND      (1UL<<5)
#define UPC_LOGOR       (1UL<<6)
#define UPC_MIN         (1UL<<7)
#define UPC_MAX         (1UL<<8)

#elif !UPC_ADD || !UPC_MULT || !UPC_AND || !UPC_OR || !UPC_XOR || \
    !UPC_MIN || !UPC_MAX || !UPC_LOGAND || !UPC_LOGOR
#error Incomplete upc_op_t macro definitions
#endif

#ifndef UPC_CHAR

#ifndef upc_type_t
#define upc_type_t rupc_type_t
typedef int upc_type_t;
#endif

#define UPC_CHAR        1
#define UPC_UCHAR       2 
#define UPC_SHORT       3  
#define UPC_USHORT      4 
#define UPC_INT         5 
#define UPC_UINT        6 
#define UPC_LONG        7 
#define UPC_ULONG       8 
#define UPC_LLONG       9 
#define UPC_ULLONG      10 
#define UPC_INT8        11 
#define UPC_UINT8       12 
#define UPC_INT16       13 
#define UPC_UINT16      14 
#define UPC_INT32       15 
#define UPC_UINT32      16 
#define UPC_INT64       17 
#define UPC_UINT64      18 
#define UPC_FLOAT       19 
#define UPC_DOUBLE      20 
#define UPC_LDOUBLE     21 
#define UPC_PTS         22 

#elif !UPC_CHAR || !UPC_UCHAR || !UPC_SHORT || !UPC_USHORT || \
      !UPC_INT  || !UPC_UINT  || !UPC_LONG  || !UPC_ULONG || \
      !UPC_LLONG || !UPC_ULLONG || \
      !UPC_INT8  || !UPC_UINT8  || !UPC_INT16 || !UPC_UINT16 || \
      !UPC_INT32 || !UPC_UINT32 || !UPC_INT64 || !UPC_UINT64 || \
      !UPC_FLOAT || !UPC_DOUBLE || !UPC_LDOUBLE || !UPC_PTS
#error Incomplete upc_type_t macro definitions
#endif

#ifndef UPC_IN_ALLSYNC

#ifndef upc_flag_t
#define upc_flag_t rupc_flag_t
typedef int rupc_flag_t;
#endif

#define UPC_IN_ALLSYNC       (1<<0)
#define UPC_IN_MYSYNC        (1<<1)
#define UPC_IN_NOSYNC        (1<<2)
#define UPC_OUT_ALLSYNC      (1<<3)
#define UPC_OUT_MYSYNC       (1<<4)
#define UPC_OUT_NOSYNC       (1<<5)

#elif !UPC_IN_ALLSYNC  || !UPC_IN_MYSYNC  || !UPC_IN_NOSYNC || \
      !UPC_OUT_ALLSYNC || !UPC_OUT_MYSYNC || !UPC_OUT_NOSYNC
#error Incomplete upc_flag_t macro definitions
#endif

#endif /* _RUPC_TYPES_H */

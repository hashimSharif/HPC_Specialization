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
/*   steve@mtu.edu                                        February 6, 2004   */
/*                                                                           */
/*****************************************************************************/

#include <upc.h>

#ifndef UPC_IN_ALLSYNC // Avoid conflict with vendor-provided upc_flag_t
  // Flag type for synchronization semantics (and potentially other uses)

  #define upc_flag_t		int
  
  // Synchronization flags
  
  #define UPC_IN_NOSYNC		1
  #define UPC_IN_MYSYNC		2
  #define UPC_IN_ALLSYNC	0
  #define UPC_OUT_NOSYNC	4
  #define UPC_OUT_MYSYNC	8
  #define UPC_OUT_ALLSYNC	0
#endif

// Operation type for upc_all_reduceT() and upc_all_prefix_reduceT()

#ifndef UPC_ADD  // Avoid conflict with vendor-provided upc_op_t
#define upc_op_t		int

#define UPC_ADD			0
#define UPC_MULT		1
#define UPC_AND			2
#define UPC_OR			3
#define UPC_XOR			4
#define UPC_LOGAND		5
#define UPC_LOGOR		6
#define UPC_MIN			7
#define UPC_MAX			8
#endif

#ifndef UPC_FUNC
#define UPC_FUNC		9
#define UPC_NONCOMM_FUNC	10
#endif

// Function codes for error checking

#define UPC_BRDCST		0
#define UPC_SCAT		1
#define UPC_GATH		2
#define UPC_GATH_ALL		3
#define UPC_EXCH		4
#define UPC_PERM		5
#define UPC_RED			6
#define UPC_PRED		7
#define UPC_SORT		8

extern void upc_all_broadcast( shared void *dst,
                        shared const void *src,
                        size_t nbytes,
                        upc_flag_t sync_mode );

extern void upc_all_scatter( shared void *dst,
                        shared const void *src,
                        size_t nbytes,
                        upc_flag_t sync_mode );

extern void upc_all_gather( shared void * dst,
                        shared const void * src,
                        size_t nbytes,
                        upc_flag_t sync_mode );

extern void upc_all_gather_all(shared void *dst,
                        shared const void *src,
                        size_t nbytes,
                        upc_flag_t sync_mode);

extern void upc_all_exchange(shared void *dst,
                        shared const void *src,
                        size_t nbytes,
                        upc_flag_t sync_mode);

extern void upc_all_permute( shared void *dst,
                        shared const void *src,
                        shared const int *perm,
                        size_t nbytes,
                        upc_flag_t sync_mode );

extern void upc_all_reduceC ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        signed char (*func)(signed char, signed char),
                        upc_flag_t sync_mode );

extern void upc_all_reduceUC ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        unsigned char (*func)(unsigned char, unsigned char),
                        upc_flag_t sync_mode );

extern void upc_all_reduceS ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        signed short (*func)(signed short, signed short),
                        upc_flag_t sync_mode );

extern void upc_all_reduceUS ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        unsigned short (*func)(unsigned short, unsigned short),
                        upc_flag_t sync_mode );

extern void upc_all_reduceI ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        signed int (*func)(signed int, signed int),
                        upc_flag_t sync_mode );

extern void upc_all_reduceUI ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        unsigned int (*func)(unsigned int, unsigned int),
                        upc_flag_t sync_mode );

extern void upc_all_reduceL ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        signed long (*func)(signed long, signed long),
                        upc_flag_t sync_mode );

extern void upc_all_reduceUL ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        unsigned long (*func)(unsigned long, unsigned long),
                        upc_flag_t sync_mode );

extern void upc_all_reduceF ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        float (*func)(float, float),
                        upc_flag_t sync_mode );

extern void upc_all_reduceD ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        double (*func)(double, double),
                        upc_flag_t sync_mode );

extern void upc_all_reduceLD ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        long double (*func)(long double, long double),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceC ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        signed char (*func)(signed char, signed char),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceUC ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        unsigned char (*func)(unsigned char, unsigned char),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceS ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        signed short (*func)(signed short, signed short),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceUS ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        unsigned short (*func)(unsigned short, unsigned short),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceI ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        signed int (*func)(signed int, signed int),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceUI ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        unsigned int (*func)(unsigned int, unsigned int),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceL ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        signed long (*func)(signed long, signed long),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceUL ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        unsigned long (*func)(unsigned long, unsigned long),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceF ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        float (*func)(float, float),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceD ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        double (*func)(double, double),
                        upc_flag_t sync_mode );

extern void upc_all_prefix_reduceLD ( shared void *dst, shared const void *src,
                        upc_op_t op, size_t nelems, size_t blk_size,
                        long double (*func)(long double, long double),
                        upc_flag_t sync_mode );

extern void upc_all_sort( shared void *A,
                        size_t elem_size,
                        size_t nelems,
                        size_t blk_size,
                        int (*func)(shared void *, shared void *),
                        upc_flag_t sync_mode);

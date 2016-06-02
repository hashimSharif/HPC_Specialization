
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
#include <stdlib.h>
#include <upc_collective.h>

// This file includes the 6 "relocalization" functions, 11 versions each
// of reduce and prefix_reduce, and the sort function.

int upc_coll_init_flag = 0;

#ifdef	_UPC_COLL_CHECK_ARGS
#include "upc_coll_err.c"
#endif

#include "upc_coll_init.c"

#include "upc_all_broadcast.c"

#include "upc_all_scatter.c"

#include "upc_all_gather.c"

#include "upc_all_gather_all.c"

#include "upc_all_exchange.c"

#include "upc_all_permute.c"

/* The bodies of the functions upc_all_reduceT and upc_all_prefix_reduceT */
/* are in upc_all_reduce.c and upc_all_prefix_reduce.c, respectively.	  */
/* A macro is used to plug in each of the 11 types.  The beginning of the */
/* first line of each function, e.g., "void upc_all_reduceC", appears	  */
/* explicity below for each individual case.				  */

/* _UPC_NONINT_T is used in some cases below to avoid compiling sections  */
/* of code that involve bitwise operations (&, |, and ^) that cannot be   */
/* applied to nonintegral types (float, etc.).				  */

/*---------    upc_all_reduceT    -------------*/

#define _UPC_RED_T signed char
void upc_all_reduceC
#include "upc_all_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T unsigned char
void upc_all_reduceUC
#include "upc_all_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T signed short
void upc_all_reduceS
#include "upc_all_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T unsigned short
void upc_all_reduceUS
#include "upc_all_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T signed int
void upc_all_reduceI
#include "upc_all_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T unsigned int
void upc_all_reduceUI
#include "upc_all_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T signed long
void upc_all_reduceL
#include "upc_all_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T unsigned long
void upc_all_reduceUL
#include "upc_all_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T float
#define _UPC_NONINT_T
void upc_all_reduceF
#include "upc_all_reduce.c"
#undef _UPC_NONINT_T
#undef _UPC_RED_T

#define _UPC_RED_T double
#define _UPC_NONINT_T
void upc_all_reduceD
#include "upc_all_reduce.c"
#undef _UPC_NONINT_T
#undef _UPC_RED_T

#if TEST_LONG_DOUBLE /* Berkeley UPC has known problems with long double */
#define _UPC_RED_T long double
#define _UPC_NONINT_T
void upc_all_reduceLD
#include "upc_all_reduce.c"
#undef _UPC_NONINT_T
#undef _UPC_RED_T
#endif

/*---------    upc_all_prefix_reduceT    -------------*/

#define _UPC_RED_T signed char
void upc_all_prefix_reduceC
#include "upc_all_prefix_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T unsigned char
void upc_all_prefix_reduceUC
#include "upc_all_prefix_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T signed short
void upc_all_prefix_reduceS
#include "upc_all_prefix_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T unsigned short
void upc_all_prefix_reduceUS
#include "upc_all_prefix_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T signed int
void upc_all_prefix_reduceI
#include "upc_all_prefix_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T unsigned int
void upc_all_prefix_reduceUI
#include "upc_all_prefix_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T signed long
void upc_all_prefix_reduceL
#include "upc_all_prefix_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T unsigned long
void upc_all_prefix_reduceUL
#include "upc_all_prefix_reduce.c"
#undef _UPC_RED_T

#define _UPC_RED_T float
#define _UPC_NONINT_T
void upc_all_prefix_reduceF
#include "upc_all_prefix_reduce.c"
#undef _UPC_NONINT_T
#undef _UPC_RED_T

#define _UPC_RED_T double
#define _UPC_NONINT_T
void upc_all_prefix_reduceD
#include "upc_all_prefix_reduce.c"
#undef _UPC_NONINT_T
#undef _UPC_RED_T

#if TEST_LONG_DOUBLE /* Berkeley UPC has known problems with long double */
#define _UPC_RED_T long double
#define _UPC_NONINT_T
void upc_all_prefix_reduceLD
#include "upc_all_prefix_reduce.c"
#undef _UPC_NONINT_T
#undef _UPC_RED_T
#endif

/*---------    upc_all_sort    -------------*/

#include "upc_all_sort.c"

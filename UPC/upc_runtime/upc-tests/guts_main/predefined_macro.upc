/*
 * The GWU Unified Testing Suite (GUTS) 
 * Latest modifications and integration to GUTS framework
 *  
 * Copyright (C) 2007 ... Abdullah Kayi
 * Copyright (C) 2007 ... Tarek El-Ghazawi 
 * Copyright (C) 2007 ... The George Washington University
 *
 * ---------------------------------------------------------------------------
 *
 * UPC Testing Suite Original Development
 *
 * Copyright (C) 2003 ... Veysel Baydogan, Proshanta Saha, Tarek El-Ghazawi
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include <upc.h>
#include <gula.h>
#include <stdio.h>

#ifndef UPC_MAX_BLOCK_SIZE
#error "UPC_MAX_BLOCK_SIZE is not defined"
#endif

#ifdef __UPC_STATIC_THREADS__
#define N 5
#endif

#ifdef __UPC_DYNAMIC_THREADS__ 
#define N 4
#endif

#ifdef __UPC_STATIC_THREADS__
#ifdef __UPC_DYNAMIC_THREADS__ 
#error "Cannot define STATIC as well as DYNAMIC at the same time"
#endif
#endif

/* A is a shared integer array and each THREADS has A[N]*/
shared int A[N*THREADS];

int
main()
{
    /*
     * To check that __UPC_DYNAMIC_THREADS__ and __UPC_STATIC_THREADS__ macro names are conditionally defined
     */

    if( (N != 4) && (N != 5) )
        GULA_FAIL("failed in UPC_DYNAMIC_THREADS__ and __UPC_STATIC_THREADS__");

    /*
     * To check that __UPC_VERSION__ macro names are conditionally defined
     */

#ifdef BUPC_TEST_HARNESS
    if ( ! (( __UPC_VERSION__ == 200505L )
            || ( __UPC_VERSION__ == 201311L )))
#else
    if (  __UPC_VERSION__ != 200505L )
#endif
        GULA_FAIL("failed in __UPC_VERSION__");

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

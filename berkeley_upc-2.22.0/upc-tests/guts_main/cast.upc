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

#define N 3
#define M 5

shared int *p;
shared void *q1, *q2;

int number_phase1, number_phase2;

shared[N] int a[N*THREADS];
shared[N] int *p1;
shared[M] int *p2;

shared[5] int *pp1;
shared[5] long int *pp2;

int
main()
{
    /*
     * To check that if a generic pointer-to-shared is cast to a non generic
     * pointer-to-shared type with indefinite block size, the result is a pointer
     * with a phase of zero 
     */

    number_phase1 = upc_phaseof(((shared[] int *)q1));

    if(number_phase1 != 0)
        GULA_FAIL("failed to setup the correct phase");

    /*
     * To check that if a generic pointer-to-shared is cast to a non generic
     * pointer-to-shared type with block size of one, the result is a pointer with a phase of zero
     */

    number_phase2 = upc_phaseof(((shared[1] int *)q2));

    if(number_phase2 != 0)
        GULA_FAIL("failed to setup the correct phase");

    /*
     * To check that casts or assignments from one shared pointer to another,
     * in which either the type size or the block size  differs, results in a 
     * pointer with a zero phase, unless one of the types is "shared void*"
     */

    p1 = &a[MYTHREAD];
    p1 = (shared[N] int *)p2;

    if((upc_phaseof(p1) != 0) || (upc_phaseof(p2) != 0))
        GULA_FAIL("failed to setup the correct phase");

    pp1 = (shared[5] int *) pp2; /* Cast shared long int p2 pointer as shared int*/

    if((upc_phaseof(pp1) != 0) || (upc_phaseof(pp2) != 0))
        GULA_FAIL("failed to setup the correct phase");

    /*
     * Shared objects with affinity to a given thread can be accessed by either
     * pointers-to-shared or pointers-to-local of that thread
     * successfull compilation is good enough for passing the test
     */

    int i, *q;

    if (upc_threadof(p) == MYTHREAD)
        q = (int *) p;

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

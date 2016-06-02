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

#define BLOCKS 5
#define N      BLOCKS*THREADS
#define M      10

shared[BLOCKS] int A[N];
shared[BLOCKS] int *p;

shared int B[M*THREADS];
shared int *pp;

int
main()
{
    /*
     * To check that the block size dictates the number of consecutive
     * elements have affinity to the same thread. If the block size is
     * zero, or no block size is given, all objects must have affinity 
     * to the same thread. If there is no layout qualifier, the block 
     * size should default to 1 
     */

    int i;

    upc_forall(i=0; i<N; i++; &A[i])
        A[i] = MYTHREAD;

    /* Re-initialize the pointer for reading as consecutively */
    p = (shared[BLOCKS] int *) &A[BLOCKS*MYTHREAD];

    for(i=0; i< BLOCKS; i++, p++) {
        if(*p != MYTHREAD)
            GULA_FAIL("failed to setup the affinity");
    }

    /*
     * To check that the block size dictates the number of consecutive 
     * elements have affinity to the same thread. If the block size is 
     * zero, or no block size is given, all objects must have affinity
     * to the same thread. If there is no layout qualifier, the block 
     * size should default to 1 
     */

    int affinity;

    pp = &B[MYTHREAD];

#ifdef BUPC_TEST_HARNESS
    for(i=0; i< M; i++, pp += THREADS){
#else
    for(i=0; i< N; i++, pp + THREADS){
#endif
        affinity = upc_threadof(pp);

        if(affinity != MYTHREAD)
            GULA_FAIL("failed to setup the affinity");
    }

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

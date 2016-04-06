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
 * Copyright (C) 2003 ... Veysel Baydogan, Onur Filiz, Proshanta Saha, Tarek El-Ghazawi
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

#define  N      5
#define  BLOCKS 3

shared int A[N*THREADS];
shared[N] int B[N*THREADS];
shared[BLOCKS] int C[BLOCKS*THREADS];

int
main()
{
    /*
     * To check that shared array elements with no block size are
     * distributed in round-robin fashion, by one element 
     */

    int i;
    int affinity;

    if(MYTHREAD ==0) {
        for(i = 0; i< (N*THREADS); i++) {
            affinity = upc_threadof(&A[i]);
            if(affinity != (i%THREADS))
                GULA_FAIL("failed to specify correct affinity in shared array with no blocksize");
        }
    }

    /*
     * To check that shared array elements are distributed in 
     * round-robin fashion, by chunks of block-size elements
     */

    int *p;

    p = (int *) &B[N * MYTHREAD];

    for(i=0; i< N; i++, p++)
        *p = MYTHREAD;

    p = (int *) &B[N * MYTHREAD];

    for(i=0; i<N; i++) {
        if(*p != MYTHREAD)
            GULA_FAIL("failed to specify correct affinity in shared array with no blocksize");
    }

    /*
     * To check that in an array declaration, the type qualifier applies to the elements
     */

    int *pp;

    pp = (int *) &C[BLOCKS * MYTHREAD];

    for(i=0; i< BLOCKS; i++, pp++)
        *pp = MYTHREAD;

    pp = (int *) &C[BLOCKS * MYTHREAD];

    for(i=0; i<(BLOCKS*THREADS); i++){
        if(((i/BLOCKS)%THREADS) == MYTHREAD){
            if(*pp != MYTHREAD)
                GULA_FAIL("failed to apply type qualifier to the elements");
            pp++;
        }
    }

    /*
     * To check that upc_phaseof(&array) is zero for any shared array
     */

    upc_forall(i=0; i<5; i++; &C[i]) {
        if(upc_phaseof(&C) != 0)
            GULA_FAIL("upc_phaseof(&array) is not zero for any shared array");
    }

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

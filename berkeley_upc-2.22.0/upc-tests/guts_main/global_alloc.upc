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

#define N     10

shared [N] int *shared p1;
shared [N] int *ptr;
shared int *p;
shared int *pp;
typedef shared int * t_shared_int;
shared t_shared_int ptrs[THREADS];


int
main()
{
    /*
     * To check that if nblocks*nbytes is zero, the result is a null pointer-to-shared 
     */

    p = upc_global_alloc(0, 0);

    if(p != NULL)
        GULA_FAIL("failed when nblocks*nbytes is zero");

    /*
     * To check that upc_global_alloc(size_t nblocks, size_t nbytes)
     * function allocates a contiguous shared memory space of
     * (nblocks*nbytes) size distributed by (nbytes) bytes to each thread
     */

    int i;
    int affinity;

    if( MYTHREAD == 0 )
        p1 = (shared[N] int *)upc_global_alloc(N*THREADS, sizeof(int));

    upc_barrier;

    if(p1 == NULL)
        GULA_FAIL("failed to allocate memory");

    ptr = p1;
    for(i=0; i<N*THREADS; i++, ptr++) {
        affinity = upc_threadof(ptr);
        if(affinity != i/N)
            GULA_FAIL("failed to allocate contiguous shared memory");
    }

    upc_barrier;

    if( MYTHREAD == 0 )
        upc_free(p1);

    /*
     * To check that if the upc_global_alloc function was called by multiple 
     * threads, all threads which make the call get different locations
     */

    ptrs[MYTHREAD] = (shared int *) upc_global_alloc(1, sizeof(int));

    if( ptrs[MYTHREAD] == NULL)
        GULA_FAIL("failed to allocate memory");

    upc_barrier;

    if(MYTHREAD == 0) {
        for(i=1; i<THREADS; i++) {
            if( ptrs[0] == ptrs[i] )
                GULA_FAIL("failed to return different locations for different calling threads");
        }
    }

    upc_free(ptrs[MYTHREAD]);

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

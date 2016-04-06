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
 * Copyright (C) 2003 ... Francois Cantonnet, Philippe Scheffer, Ashrujit Mohanty, Tarek El-Ghazawi
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

#define  N  10
#define  W  THREADS*(THREADS - 1)/2
#define  Z  50

shared [2] int *shared p;
shared [N] int *p1;
shared int sh_affinity = 0;
upc_lock_t   *lock1;

int
main()
{
    /*
     * To check that memory allocation and iteration statements work together correctly
     */

    int i;
    int affinity;
    volatile int j;

    if( MYTHREAD == 0 ) {
        p =(shared [2] int *) upc_global_alloc(2*THREADS,2*sizeof(int));
        if(p == NULL)
            GULA_FAIL("failed to allocate memory");
    }

    upc_barrier;

    for( i=0; i<2*THREADS*2; i++ ) {
        affinity = upc_threadof(&p[i]);
        if(affinity != ((i/2)%THREADS))
            GULA_FAIL("failed to do memory allocation in upc_forall");
    }

    upc_barrier;

    if( MYTHREAD == 0 )
        upc_free(p);

    /*
     * To check that shared pointer arithmetic works correctly on 
     * dynamically allocated shared memory with different block sizes
     */

    i = 2*THREADS*N;

    p1 =(shared[N] int *) upc_all_alloc(2*THREADS,N*sizeof(int));

    if(p1 ==NULL)
        GULA_FAIL("failed to allocate memory");

    while(i != 0) {
        affinity = upc_threadof(p1+i-1);
        if(affinity != (((i-1)/N)%THREADS))
            GULA_FAIL("failed to allocate memory in sequential order");
        i--;
    }

    upc_barrier;

    if( MYTHREAD == 0 )
        upc_free(p1);

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

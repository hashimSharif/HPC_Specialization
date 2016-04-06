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
 * Copyright (C) 2003 ... Veysel Baydogan, Proshanta Saha, , Francois Cantonnet, Tarek El-Ghazawi
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
#include <unistd.h>

shared int A[THREADS];

int
main()
{
    int i;

    /*
     * To check that a upc_wait statement does not complete until 
     * all threads have completed the corresponding upc_notify statements
     */

    A[MYTHREAD] = 1;

    if(MYTHREAD == 0)
        sleep(1);

    upc_notify;
    upc_wait;

    for( i=0; i<THREADS; i++ ) {
        if(A[i] != 1)
            GULA_FAIL("upc_notify and upc_wait synchronization does not work correctly");
    }

    upc_barrier;

    /*
     * To check that a upc_barrier statement is equal to a 
     * {upc_notify; upc_wait} pair, that is, no thread proceeds 
     * after the barrier until all the other threads have reached 
     * that statement as well
     */

    if(MYTHREAD == 0)
        sleep(1);

    A[MYTHREAD] = 1;

    upc_barrier;    /* Synchronization function */

    for( i=0; i<THREADS; i++ ) {
        if(A[i] != 1)
            GULA_FAIL("upc_notify and upc_wait synchronization does not work correctly");
    }

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

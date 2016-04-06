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

#define N 5

shared int *p;
shared[N] int A[N*THREADS];

int
main()
{
    /*
     * To check that the upc_resetphase function returns a pointer-to-shared
     * which is identical to its input except that it has zero phase 
     */

    size_t phase_number;

    A[MYTHREAD] = MYTHREAD;

#ifdef BUPC_TEST_HARNESS
    /* As noted by Gary Funck, the following makes much more sense. */
    p = (shared int *) upc_resetphase(&A[MYTHREAD]);
#else
    p = (shared int *) upc_resetphase(A);
#endif

    phase_number = upc_phaseof(p);

    upc_barrier;

    if(phase_number != 0)
        GULA_FAIL("failed to reset the phase");

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

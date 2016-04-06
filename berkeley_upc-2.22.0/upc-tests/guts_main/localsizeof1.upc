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

#define N  5

/* A is a shared integer array and each THREADS has A[N]*/
shared [N] int A[N*THREADS];
shared [] int B[N*THREADS];

int
main()
{
    /*
     * To check that the upc_localsizeof operator returns the size, in bytes, of the local 
     * portion of its operand and that value is the same for all threads
     */

    size_t sh_variable_size;

    /* upc_localsizeof will return size of (N * sizeof(int)) */
    sh_variable_size = upc_localsizeof(A);

    if(sh_variable_size < (N*sizeof(int)))
        GULA_FAIL("failed to return correct data size");

    /*
     * To check that if the shared object's block size is indefinite,
     * the upc_localsizeof operator returns zero on all threads, which do 
     * not have affinity to that object
     */

    /* Assign shared A variable size to local sh_variable_size variable */
    sh_variable_size = upc_localsizeof(B);

    if(sh_variable_size < sizeof(int)*N*THREADS)
        GULA_FAIL("failed to return correct data size when the blocksize is indefinite");

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

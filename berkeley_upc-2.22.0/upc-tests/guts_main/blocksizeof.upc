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

#define N      20

/* A shared variable's qualifier type is THREADS */
shared [N] int A[N*THREADS];

/* B shared variable has not qualifier type      */
shared int B[THREADS];

/* C shared variable with indefinite blocksize   */
shared[] int C[THREADS];

int
main()
{
    /*
     * To check that the upc_blocksizeof operator returns the block size of the operand
     * If there is no layout qualifier, the result should be 1 
     */

    size_t array_block_size;

    array_block_size = upc_blocksizeof(A[MYTHREAD*N]);
    if(array_block_size != N)
        GULA_FAIL("failed to return the correct data size");

    array_block_size = upc_blocksizeof(B);
    if(array_block_size != 1)
        GULA_FAIL("failed to return the correct data size when there is no layout qualifier");

    /*
     * To check that if the operand has indefinite block size, the upc_blocksizeof operator returns 0
     */

    array_block_size = upc_blocksizeof(C);
    if(array_block_size != 0)
        GULA_FAIL("failed to return the correct data size when the blocksize is indefinite");

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

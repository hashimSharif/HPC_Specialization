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

typedef struct {
    int  A[THREADS];
    int  B[THREADS];
} Elem_size_t;

/* Define a shared variable with Elem_size structure type*/
shared Elem_size_t Elem_size;

int
main()
{
    /*
     * To check that the upc_elemsizeof operator returns the size, 
     * in bytes, of the highest-level (leftmost) type that is not an array 
     * For non-array objects, upc_elemsizeof returns the same value as sizeof  
     */

    size_t var_elem_size;

    var_elem_size = upc_elemsizeof(Elem_size);

    if(var_elem_size != (sizeof(int)*THREADS + sizeof(int)*THREADS))
        GULA_FAIL("failed to return the correct size ");

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

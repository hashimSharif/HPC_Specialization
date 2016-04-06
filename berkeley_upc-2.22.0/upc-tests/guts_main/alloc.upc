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

shared int *p;
shared int *pp;

int
main()
{
    /*
     * To check that the upc_alloc(size_t nbytes) function returns 
     * a pointer to a nbytes bytes of shared memory with affinity 
     * to the calling thread 
     */

    size_t sizeof_int;
    sizeof_int = sizeof(int);

    p = (shared int *) upc_alloc((1*sizeof_int));

    *p = MYTHREAD+1;

    upc_barrier;

    if(p[0] != MYTHREAD+1)
        GULA_FAIL("failed to do upc_alloc properly");

    if(upc_threadof(p) != MYTHREAD)
        GULA_FAIL("failed to setup the correct affinity");

    upc_free(p);

    /*
     * To check that upc_alloc(size_t nbytes) function returns a null pointer when nbytes is zero
     */

    pp = (shared int *)upc_alloc(0);

    if(pp != NULL)
        GULA_FAIL("failed when nbytes is zero");

    upc_free(pp);

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

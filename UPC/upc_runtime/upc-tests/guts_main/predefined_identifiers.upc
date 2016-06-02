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

upc_lock_t *lock1;

/* Define shared integer variable to find total threads */
shared int total_thread;

int
main()
{
    /*
     * To check that the predefined identifier THREADS is equal to the number of threads running 
     */

    lock1 = upc_all_lock_alloc();

    upc_lock(lock1);
    total_thread++;             /* Add 1 for all threads */
    upc_unlock(lock1);

    upc_barrier;                /* Syhncronize the all thread */

    /* Check the Thread numbers, it should equal to different number of compiled thread*/

    if(total_thread != THREADS)
        GULA_FAIL("THREADS is not equal to the actual number of running threads");

    /*
     * To check that the predefined identifier MYTHREAD takes all the values in the interval [0..THREADS-1]
     */

    if((MYTHREAD > (THREADS - 1)) || (MYTHREAD < 0))
        GULA_FAIL("MYTHREAD identifier failed to be between [0..THREADS-1]");

    /*
     * MYTHREAD should have type 'int'
     */

    if (sizeof(MYTHREAD) != sizeof(int))
        GULA_FAIL("FAILED: MYTHREAD has wrong size");

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

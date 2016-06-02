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

shared int a;
upc_lock_t *lock1;

int
main()
{
    /*
     * To check that the upc_unlock function frees the lock pointed to by the argument of type (*upc_lock_t) 
     */

    int local_a= MYTHREAD + 55;
    int check_parm;

#ifdef BUPC_TEST_HARNESS
    if(THREADS == 1) {
        if(!MYTHREAD)
            printf ("WARNING: test SKIPPED because it requires 2 or more UPC threads\n");
        return 0;
    }
#endif /* BUPC_TEST_HARNESS */

    lock1 = upc_all_lock_alloc();

    if(lock1 == NULL)
        GULA_FAIL("failed to allocate lock");

    if(MYTHREAD == 1) {
        upc_lock(lock1);
        a = local_a + MYTHREAD;
        upc_unlock(lock1);
    }

    upc_barrier;

    if(MYTHREAD == 0){
        check_parm = upc_lock_attempt(lock1);
        if(check_parm != 1)
            GULA_FAIL("failed to unlock");
        upc_unlock(lock1);
    }

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

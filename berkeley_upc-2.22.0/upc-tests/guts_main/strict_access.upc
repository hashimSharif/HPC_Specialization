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

strict shared int flag = 0;
shared int a, b;

int
main()
{
    /*
     * To check that access to "strict" shared objects are according to strict access guidelines 
     */

#ifdef BUPC_TEST_HARNESS
    if(THREADS == 1) {
        if(!MYTHREAD)
            printf ("WARNING: test SKIPPED because it requires 2 or more UPC threads\n");
        return 0;
    }
#endif /* BUPC_TEST_HARNESS */

    a = 5;
    b = 6;

    upc_barrier;

#ifdef BUPC_TEST_HARNESS
    switch((int)!MYTHREAD) {
#else
    switch(!MYTHREAD) {
#endif /* BUPC_TEST_HARNESS */
        case 0 :
            a = 10;
            flag= 1;
            break;
        case 1 :
            while(!flag);
            b = a + 3;
            break;
    }

    upc_barrier;

    if (b != 13)
        GULA_FAIL("Strict semantics failed");

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

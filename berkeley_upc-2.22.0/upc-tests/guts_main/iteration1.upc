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

#define N  10
#define pmod(a, b) (a>=0) ? (a%b) : (((a%b) +b) %b)

#if defined(BUPC_TEST_HARNESS) && !defined(__BERKELEY_UPC__)
/* This alternative form of pmod() works-around a pgcc bug which is triggered
   when translating with clang-upc2c.  However, use of this alternative form
   triggers the bug when the Berkeley UPC translator is used.  Sigh!
 */
#undef pmod
#define pmod(a, b) (a>=0) ? (a%(unsigned)b) : (((a%b) +b) %b)
#endif

shared int affinity[N*THREADS];
shared int A[N][THREADS];

int
main()
{
    /*
     * To check that when affinity field in a upc_forall statement is
     * a reference to shared memory space, the loop body is executed 
     * for each iteration in which the value of MYTHREAD equals the value of the affinity field 
     */

    int i,j;

    upc_forall(i=0; i< N; i++; &affinity[MYTHREAD]) {
        if(upc_threadof(&affinity[MYTHREAD]) != MYTHREAD)
            GULA_FAIL("failed to setup the correct affinity in upc_forall");
    }

    /*
     * To check that when affinity field in a upc_forall statement is 
     * an integer expression, the loop body is executed for each 
     * iteration in which the value of MYTHREAD equals the value 
     * pmod(affinity, THREADS), where pmod(a,b) is evaluated as 
     * (a>=0) ? (a%b) : ( ( (a%b) + b) % b)
     */

    int thread_number;

    upc_forall(i=0; i< THREADS; i++; i) {
        thread_number = pmod(i, THREADS);
        if(thread_number != MYTHREAD)
            GULA_FAIL("failed to setup the correct affinity in upc_forall with integer expression");
    }

    /*
     * To check that when affinity field in a upc_forall statement is
     * "continue", the loop body of the upc_forall statement is
     * executed for every iteration on every thread
     */

    upc_forall(i=0; i< N; i++; continue)
        A[i][MYTHREAD] = 1;

    for(i=0; i<N; i++) {
        if(A[i][MYTHREAD] != 1)
            GULA_FAIL("failed to work properly when the affinity field is 'continue' in upc_forall");
    }

    /*
     * To check that when no affinity field is specified in a
     * upc_forall statement, the loop body of the upc_forall
     * statement is executed for every iteration on every thread
     */

    upc_forall(i=0; i< N; i++;)
        A[i][MYTHREAD] = 4;

    for(i=0; i<N; i++) {
        if(A[i][MYTHREAD] != 4)
            GULA_FAIL("failed when there is no affinity field in upc_forall");
    }

    /* Make sure this round of testing is complete. */
    upc_barrier;

    /*
     * To check that in a nested upc_forall statement, 
     * the upc_forall statements which are not "controlling" 
     * behave as if their affinity expressions were "continue"
     */

    upc_forall(i=0; i< N; i++; i) {
        upc_forall(j=0; j< THREADS; j++;j)
            A[i][j] = 1;
    }

    upc_forall(i=0; i<N; i++;i) {
        if(A[i][MYTHREAD] != 1)
            GULA_FAIL("failed with nested upc_forall");
    }

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

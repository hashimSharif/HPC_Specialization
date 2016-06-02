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

#define N 20
#define B 2

shared[N] int A[N*THREADS];
shared[N] int *shr_ptr;

shared[B] int *p, *p1;
shared[B] int C[B*THREADS];

int *pp1, *pp2;
shared[B] int *s1, *s2;
shared[B] int D[B*THREADS];

int
main()
{
    /*
     * To check that when an expression that has integer type is 
     * added to or subtracted from a shared pointer, the result has 
     * the type of the shared pointer operand 
     */

    int i, k, add_variable, subs_variable;

    shr_ptr = A;                       /* shr_ptr is pointing &A[0]   */

    add_variable  = 15;
    subs_variable = 10;

    upc_forall(i=0; i<N; i++; &A[i])
        A[i] = i + MYTHREAD*N;

    shr_ptr +=add_variable ;           /* shr_ptr is pointing &A[MYTREAD*N + add_variable] */

    upc_barrier;

    if(*shr_ptr != add_variable)
        GULA_FAIL("failed to do shared pointer arithmetic");

    shr_ptr -= subs_variable;          /* shr_ptr is pointing &A[MYTREAD + add_variable - subs_variable] */

    upc_barrier;

    if(*shr_ptr  != (add_variable - subs_variable))
        GULA_FAIL("failed to do shared pointer arithmetic");

    /*
     * To check that after shared pointer arithmetic, the result 
     * shared pointer has the correct phase and has the affinity to the correct thread.
     */

    i = 5 + B*THREADS/2;
    int phase1, thread1, phase2, thread2;

#ifdef BUPC_TEST_HARNESS
    /* Avoid uninitialized var warnings from Clang, which doesn't know
     * that i>0 (thus these *must* be assigned values in the for loop).
     * -PHH 2013.01.11
     */
    phase1 = phase2 = 0;
#endif

    p = (shared[B] int*) &A[0];
    p1 = p + i;

    upc_barrier;

    for(k=0; k<i; k++){
        phase1  = upc_phaseof(p1);
        phase2  = ((upc_phaseof(p) + i) % B);
        thread1 = upc_threadof(p1);
        thread2 = ((upc_threadof(p) + (upc_phaseof(p) + i) / B) % THREADS);
    }

    if(phase1 == phase2) {
        if(thread1 != thread2)
            GULA_FAIL("Shared pointer does NOT have affinity to the correct thread");
    }

    /*
     * To check that shared pointers point to correct elements after being cast to local pointers
     */

    s1 = &D[B*MYTHREAD];
    s2 = &D[(B*MYTHREAD + 1)];

    pp1 = (int*) s1;
    pp2 = (int*) s2;

    if((upc_addrfield(s2) - upc_addrfield(s1)) != ((pp2 - pp1) * sizeof(int)))
        GULA_FAIL("Shared pointer failed to point to the correct elements after being cast to local pointers");

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

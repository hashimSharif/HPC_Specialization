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

#define N       15
#define BLOCK1  5
#define BLOCK2  3

shared[BLOCK1] int A[N*THREADS];
shared[BLOCK2] char B[N*THREADS];

shared int  *pp1;
shared void *pp2;

/* The function definition is valid because of shared pointer declaration in context of the function */
void foo(shared int *p);

shared int a;
shared int *p2;

/*
 * To check that shared pointers can be declared inside structures
 */

typedef shared struct {
    int         a;
    shared int *b;
}foo1;

foo1 local_foo;

int
main()
{
    /*
     * To check that shared pointers can be declared with automatic storage class 
     */

    foo(p2);

    /*
     * To check that "shared void *" pointers are type compatible with any shared pointer type
     */

    pp1 = (shared int *) &A[MYTHREAD];
    pp2 = (shared int *) &B[MYTHREAD];

    pp1 = pp2;

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

void
foo(shared int *p) {
    p = &a;
}

/*
--------------------------------------------------------------------------

Copyright (c) 2003-2011, The Regents of the University of California,
through Lawrence Berkeley National Laboratory (subject to receipt of
any required approvals from U.S. Dept. of Energy)

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

(1) Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
(2) Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
(3) Neither the name of Lawrence Berkeley National Laboratory,
U.S. Dept. of Energy nor the names of its contributors may be used to
endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

--------------------------------------------------------------------------
Authors : The Berkeley UPC Team <upc@lbl.gov>
*/

#include <upc.h>
#include <stdio.h>
#include <gula.h>

shared int A[THREADS];

int
main(void)
{

    /*
     * Tests the spec language in 6.6.2:11, that reads
     * "Every thread evaluates the fourth clause of every iteration."
     */

    int j1, j2;
    int k1, k2;
    int limit = 8;

    j1 = k1 = 0;
    upc_forall(int i = 0; i < THREADS; i++ ; (k1++, &A[i]) ) { ++j1; }

    j2 = k2 = 0;
    upc_forall(int i = 0; i < limit; i++ ; (k2++, MYTHREAD) ) { ++j2; }

    upc_barrier;
    if (j1 != 1) {
        GULA_FAIL("failed upc_forall argument evaluation: incorrect j1");
    }
    if (k1 != THREADS) {
        GULA_FAIL("failed upc_forall argument evaluation: incorrect k1");
    }
    if (j2 != limit) {
        GULA_FAIL("failed upc_forall argument evaluation: incorrect j2");
    }
    if (k2 != limit) {
        GULA_FAIL("failed upc_forall argument evaluation: incorrect k2");
    }

    upc_barrier;

#ifdef BUPC_TEST_HARNESS
    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

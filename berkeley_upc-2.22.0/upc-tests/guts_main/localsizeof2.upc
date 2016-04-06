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
#include <gula.h>
#include <stdio.h>

shared [4] int A[4*THREADS];

int
main()
{
    /* UPC 1.2 Spec 6.4.1.2.4:
     * "If the the operand is an expression, that expression is not evaluated."
    */


    shared [4] int *p1 = &A[1];
    shared [4] int *p2 = p1;
    shared [4] int *p3 = (shared [4] int *)NULL;

    // Verify no pre-decrement or post-increment occurs:
    size_t want = sizeof(int);
    size_t size_p1 = upc_localsizeof(*(--p1));
    size_t size_p2 = upc_localsizeof(*(p2++));

    if ( size_p1 < want)
        GULA_FAIL("failed to return correct data size on p1");
    if ( size_p2 < want)
        GULA_FAIL("failed to return correct data size on p2");

    if (p1 != p2)
        GULA_FAIL("failed on UPC 1.2 spec 6.4.1.2.4");

    // Verify no dereference occurs:
    size_t size_p3 = upc_localsizeof(*p3);

    if ( size_p3 < want)
        GULA_FAIL("failed to return correct data size on p3");

    upc_barrier;

#ifdef BUPC_TEST_HARNESS
    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

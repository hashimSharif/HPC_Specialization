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

typedef struct S
{
    shared struct S *next;
    long data;
} S_t;

typedef shared S_t *S_p;

shared S_p S;

shared S_t S2;

int
main()
{
    /*
     * When the unary & is applied to a shared structure element of type T, the
     * result has type shared [] T *
     */

#ifdef BUPC_TEST_HARNESS /* GUTS Trac ticket #56 (remove/fix address_operator.upc test) */
    if (upc_blocksizeof(*(&(S->data))) != 0)
        GULA_FAIL("failed spec 6.4.4 Semantics 1");
    if (upc_blocksizeof(*(&(S2.data))) != 0)
        GULA_FAIL("failed spec 6.4.4 Semantics 1");
#else
    if (upc_blocksizeof(&(S->data)) != 0)
        GULA_FAIL("failed spec 6.4.4 Semantics 1");
    if (upc_blocksizeof(&(S2.data)) != 0)
        GULA_FAIL("failed spec 6.4.4 Semantics 1");
#endif /* BUPC_TEST_HARNESS */
#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

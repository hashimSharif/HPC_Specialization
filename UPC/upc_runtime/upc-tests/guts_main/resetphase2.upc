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

#include <stdio.h>
#include <upc.h>
#include <gula.h>


int
main()
{
    /*
     * tests rules about when phase is reset by assignments
     */

    shared int *p1;
    shared [5] int *p2;
    shared [] int *p3;
    shared [10] int *p4;
    shared void *p5;

    p3 = upc_alloc(1024);
    if (!p3)
        GULA_FAIL("ERROR: upc_alloc failed.");

    p4 = upc_all_alloc(1024,10*sizeof(int));
    if (!p4)
        GULA_FAIL("ERROR: upc_all_alloc failed.");

    p1 = (shared int *)&p4[1]; /* Different blocksize - must reset phase to 0 */
    p5 = &p4[1];
    p2 = p5;  /* Generic pointer - must preserve phase of 1 */

    if (upc_phaseof(p1) != 0 || upc_phaseof(p2) != 1)
        GULA_FAIL("failed in upc_phaseof() check - 1");

    p1 = upc_resetphase(p1); /* nop */
    p2 = upc_resetphase(p2); /* should reset phase */

    if (upc_phaseof(p1) != 0 || upc_phaseof(p2) != 0)
        GULA_FAIL("failed in upc_phaseof() check - 2");

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

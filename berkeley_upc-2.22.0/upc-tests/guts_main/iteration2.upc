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

int c1, c2, c3, c4;

int foo1 (void) { c1++; return 0; }
int foo2 (void) { c2++; return 0; }
int foo3 (void) { c3++; return 0; }
int foo4 (void) { c4++; return 0; }

int
main(void)
{
    /* 
     * Based on EXAMPLE 2 on p31 of UPC spec 1.2
     */

    int i;

    c1 = c2 = c3 = c4 = 0;
    upc_forall ((foo1(), i = 0); (foo2(), i < 10); (foo3(), i++); i){
        foo4();
    }
    upc_barrier;

// UPC SPEC says in describing the example:
// --begin quote--
//   Each thread evaluates foo1() exactly once, before any further action on that
//   thread. Each thread will execute foo2() and foo3() in alternating sequence, 10
//   times on each thread. Assuming there is no enclosing upc forall loop, foo4()
//   will be evaluated exactly 10 times total before the last thread exits the loop,
//   once with each of i=0..9. Evaluations of foo4() may occur on different threads
//   (as determined by the affinity clause) with no implied synchronization or
//   serialization between foo4() evaluations or controlling expressions on different
//   threads. The final value of i is 10 on all threads.
// --end quote--
// UPC SPEC language above says foo2() is executed 10 times, but does not say
// that those are the ONLY 10 times.  The NORMATIVE portion of the spec says
// in 6.6.2:11
// --begin quote--
//   Every thread evaluates the first three clauses of a upc forall statement
//   in accordance with the semantics of the corresponding clauses for the for
//   statement, as defined in [ISO/IEC00 Sec. 6.8.5.3]. Every thread evaluates
//   the fourth clause of every iteration.
// --end quote--
// That C spec text implies foo2() is run 11 times.
//
// So, we expect 
//   foo1() executes exactly 1 time
//   foo2() executes exactly 11 times
//   foo3() executes exactly 10 times
//   foo4() executes as determined by the affinity expression

    if (i != 10) {
      GULA_FAIL("failed to evaluate upc_forall argument correctly - bad i");
    }
    if (c1 != 1) {
      GULA_FAIL("failed to evaluate upc_forall argument correctly - bad c1");
    }
    if (c2 != 11) {
      GULA_FAIL("failed to evaluate upc_forall argument correctly - bad c2");
    }
    if (c3 != 10) {
      GULA_FAIL("failed to evaluate upc_forall argument correctly - bad c3");
    }
    if (c4 != ((10 + THREADS - 1 - MYTHREAD) / THREADS)) {
      GULA_FAIL("failed to evaluate upc_forall argument correctly - bad c4");
    }

    upc_barrier;

#ifdef BUPC_TEST_HARNESS
    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

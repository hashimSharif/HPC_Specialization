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

#define N 10
#define M 11

#define check(expr) do { \
  if (!(expr)) GULA_FAIL("failed in upc_forall semantics");} while (0)

#define threadof(p) ((int)upc_threadof(p))

shared int A[N*N*THREADS];

int
main()
{

    /* 
     * The following semantics descriptions are from version 1.2 of
     *  the UPC specification (page 30):
     *  
     * 5 upc forall is a collective operation in which, for each execution of the loop
     * body, the controlling expression and affinity expression are single-valued.
     * 
     * 6 The affinity field specifies the executions of the loop body which are to be
     * performed by a thread.
     * 
     * 7 When affinity is of pointer-to-shared type, the loop body of the upc forall
     * statement is executed for each iteration in which the value of MYTHREAD equals
     * the value of upc threadof(affinity). Each iteration of the loop body is
     * executed by precisely one thread.
     * 
     * 8 When affinity is an integer expression, the loop body of the upc forall
     * statement is executed for each iteration in which the value of MYTHREAD equals
     * the value affinity mod THREADS.
     * 
     * 9 When affinity is continue or not specified, each loop body of the upc forall
     * statement is performed by every thread and semantic 1 does not apply.
     * 
     * 10 If the loop body of a upc forall statement contains one or more upc forall
     * statements, either directly or through one or more function calls, the construct
     * is called a nested upc forall statement. In a nested upc forall, the
     * outermost upc forall statement that has an affinity expression which is
     * not continue is called the controlling upc forall statement. All upc forall
     * statements which are not controlling in a nested upc forall behave as if their
     * affinity expressions were continue.
     *
     */

#ifdef BUPC_TEST_HARNESS
    /* Use of unsigned here avoids a bug in PGI's C compilers prior to about 13.1 */
    unsigned int i,j,k;
#else
    int i,j,k;
#endif
    int cnt1, cnt2;
    shared [1] int *psi1 = (shared [1] int *)&A;
    shared [N] int *psiN = (shared [N] int *)&A;
    shared [] int *psiI0 = (shared [] int *)&A;
    shared [] int *psiITm1;

    psiITm1 = (shared [] int *)&(A[THREADS-1]);

#ifdef BUPC_TEST_HARNESS
    // UPC 1.3 makes case of negative affinity expression undefined
    upc_forall (i=0; i<N; i++; i) {
        check(i % THREADS == MYTHREAD);
    }
#else
    upc_forall (i=-N; i<N; i++; i) {
        if (i >= 0)
            check(i % THREADS == MYTHREAD);
        else
            check(((i % THREADS)+THREADS)%THREADS == MYTHREAD);
    }
#endif
    upc_barrier;
    upc_forall (i=0; i<N*THREADS; i++; &(psi1[i])) {
        check(threadof(&(psi1[i])) == MYTHREAD);
        check(i % THREADS == MYTHREAD);
    }
    upc_barrier;
    upc_forall (i=0; i<N*N*THREADS; i++; &(psiN[i])) {
        check(threadof(&(psiN[i])) == MYTHREAD);
        check((i/N) % THREADS == MYTHREAD);
    }
    upc_barrier;
    upc_forall (i=0; i<N*N; i++; &(psiI0[i])) {
        check(threadof(&(psiI0[i])) == MYTHREAD);
        check(MYTHREAD == 0);
    }
    upc_barrier;
    upc_forall (i=0; i<N*N; i++; &(psiITm1[i])) {
        check(threadof(&(psiITm1[i])) == MYTHREAD);
        check(MYTHREAD == THREADS-1);
    }
    upc_barrier;

    cnt1 = 0;
    cnt2 = 0;
    for (i=0;i<N;i++) {
        cnt1++;
        upc_forall (j=0; j<M*THREADS; j++; j) {
            cnt2++;
            check(j % THREADS == MYTHREAD);
        }
    }
    check(cnt1 == N);
    check(cnt2 == N*M);

    upc_barrier;

    cnt1 = 0;
    cnt2 = 0;
    upc_forall (i=0; i<M*THREADS; i++; i) {
        cnt1++;
        check(i % THREADS == MYTHREAD);
        for (j=0; j<N; j++) {
            cnt2++;
        }
    }
    check(cnt1 == M);
    check(cnt2 == M*N);

    upc_barrier;

    cnt1 = 0;
    cnt2 = 0;
    /* Nested upc_forall, inner upc_forall will be
       executed as if the affinity clause is "continue".  */
    upc_forall (i=0; i<M*THREADS; i++; i) {
        cnt1++;
        check(i % THREADS == MYTHREAD);
        upc_forall (j=0; j<N; j++; j) {
            cnt2++;
        }
    }
    check(cnt1 == M);
    check(cnt2 == M*N);

    upc_barrier;

    cnt1 = 0;
    cnt2 = 0;
    /* Nested upc_forall with three upc_forall statements. The outer-most
       upc_forall affinity clause is given as "continue".  The upc_forall statement
       that iterates on 'i' becomes the "controlling statement".
       The innermost loop that iterates on 'j' will execute
       as if its affinity clause is "continue".  */
    upc_forall (k=0; k<3; k++; continue) {
        upc_forall (i=0; i<M*THREADS; i++; i) {
            cnt1++;
            check(i % THREADS == MYTHREAD);
            upc_forall (j=0; j<N; j++; j) {
                cnt2++;
            }
        }
    }
    check(cnt1 == 3*M);
    check(cnt2 == 3*M*N);

    upc_barrier;

    cnt1 = 0;
    cnt2 = 0;
    /* Nested upc_forall, with three upc_forall statements.
       The outermost upc_forall statement that iterates on 'i'
       is the "controlling statement".  The loop that iterates on
       'k' has an affinity clause of "continue".  The innermost loop
       that iterates on 'j' will execute as if its affinity
       clause is "continue".  */
    upc_forall (i=0; i<M*THREADS; i++; i) {
        upc_forall (k=0; k<3; k++; continue) {
            cnt1++;
            check(i % THREADS == MYTHREAD);
            upc_forall (j=0; j<N; j++; j) {
                cnt2++;
            }
        }
    }
    check(cnt1 == M*3);
    check(cnt2 == M*3*N);

    upc_barrier;

    cnt1 = 0;
    cnt2 = 0;
    /* Nested upc_forall, with three upc_forall statements.
       The outermost upc_forall statement that iterates on 'i'
       is the "controlling statement".  The loop that iterates on 'j'
       will execute as if its affinity clause is "continue".
       The innermost loop that iterates on 'k' has an affinity
       clause of "continue".  */
    upc_forall (i=0; i<M*THREADS; i++; i) {
        cnt1++;
        check(i % THREADS == MYTHREAD);
        upc_forall (j=0; j<N; j++; j) {
            upc_forall (k=0; k<3; k++; continue) {
                cnt2++;
            }
        }
    }
    check(cnt1 == M);
    check(cnt2 == M*N*3);

    upc_barrier;

#ifdef BUPC_TEST_HARNESS
    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

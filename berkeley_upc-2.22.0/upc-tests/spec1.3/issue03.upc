/*
 * Copyright 2012-2013 Cray Inc. All Rights Reserved 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are 
 * met: 
 *
 *  * Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 *
 *  * Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 *
 *  * Neither the name Cray Inc. nor the names of its contributors may be 
 *    used to endorse or promote products derived from this software 
 *    without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 *
 */

#include <stdio.h>
#include <upc.h>

#define VFMT "%3d"
#define VTYPE int
#define EXPECTED(i,j) ((COLS * (i)) + (j))

#define TFMT "%1d"
#define TTYPE int
#define MAX_THREADS 10
#define EXPECTED_THR(i,j) ((((COLS * (i)) + (j)) / BLKS) % THREADS)

#define PFMT "%1d"
#define PTYPE int
#define BLKS (5)
#define EXPECTED_PHASE(i,j) (((COLS * (i)) + (j)) % BLKS)

/* One of these must be a multiple of THREADS */
#define ROWS (3*THREADS)
#define COLS (7)

/* Helper macros to save some typing and duplication */
#define t0_print \
    if ( !MYTHREAD ) printf

/* Pass i, j, and failed explicitly to call out that they are
 * used in the macro.
 */
#define TEST_ELEM( i,j,expr,failed ) \
    shared [BLKS] VTYPE *ptr = &(expr); \
    VTYPE actual = *ptr; \
    int _failed = 0; \
    if ( (actual != EXPECTED(i,j))                  || \
         (upc_threadof( ptr ) != EXPECTED_THR(i,j)) || \
         (upc_phaseof( ptr) != EXPECTED_PHASE(i,j)) || \
         check_addrfield(i,j,ptr) ) _failed = 1; \
    t0_print( "%s" VFMT "@" TFMT ":" PFMT, \
              (_failed == 0) ? "  " : "**", \
              actual, \
              (TTYPE)upc_threadof( ptr ), \
              (PTYPE)upc_phaseof( ptr ) ); \
    failed |= _failed

/* Create a nice "ugly" multidimensional shared array whose rows and columns
 * do not neatly fit into the specified blocks to try to ensure that some rows'
 * initial elements are not at phase 0.
 */
shared [BLKS] VTYPE array2d[ROWS][COLS];

#ifdef BUPC_TEST_HARNESS
/* If set, then at least one of the threads detected a failure.  */
strict shared int failed_flag;

#endif /* BUPC_TEST_HARNESS */
/* Verify that ptr has a valid addrfield component */
int
check_addrfield( int i, int j, shared [BLKS] VTYPE *ptr )
{
    int failed = 0;

    int p_first_i = (BLKS * upc_threadof( ptr ) ) / COLS;
    int p_first_j = (BLKS * upc_threadof( ptr ) ) % COLS;

    shared [BLKS] VTYPE *p_first = &array2d[p_first_i][p_first_j];

    shared [] VTYPE *indef_ptr     = (shared [] VTYPE *)ptr;
    shared [] VTYPE *indef_p_first = (shared [] VTYPE *)p_first;

    size_t addr_diff  = (indef_ptr - indef_p_first) * sizeof( VTYPE );
    size_t exp_diff   = upc_affinitysize( ((COLS * i) + j + 1) *
                                          sizeof( VTYPE ), 
                                          BLKS * sizeof( VTYPE ),
                                          upc_threadof( ptr ) )
                        - sizeof( VTYPE );

    if ( addr_diff != exp_diff ) {
        failed = 1;
    }
    else if ( upc_threadof( ptr ) == MYTHREAD ) {
        size_t local_diff = (((VTYPE *)indef_ptr) - ((VTYPE *)indef_p_first))
                            * sizeof( VTYPE );

        if ( local_diff != exp_diff ) {
            failed = 1;
        }
    }

    return failed;
}

/* Initialize all elements of the array to known values based on position
 * in array
 */
void
init_array2d( void )
{
    int i,j;
    for ( i=0 ; i<ROWS ; ++i ) {
        upc_forall ( j=0 ; j<COLS ; ++j ; &array2d[i][j] ) {
            array2d[i][j] = EXPECTED(i,j);
        }
    }
    upc_barrier;
}

/* Verify simple array subscripting works as expected */
int
print_array2d( void )
{
    int failed = 0;
    int i,j;
    t0_print( "array2d:\n" );
    for ( i=0 ; i<ROWS ; ++i ) {
        for ( j=0 ; j<COLS ; ++j ) {
            TEST_ELEM( i, j, array2d[i][j], failed );
        }
        t0_print( "\n" );
    }
    t0_print( "\n" );
    upc_barrier;
    return failed;
}

/* Test pointer equivalence from ISO/IEC C99 6.5.2.1 2 for rows,
 * and array subscripting for columns.
 */
int
print_array2d_derefi( void )
{
    int failed = 0;
    int i,j;
    t0_print( "array2d (derefi):\n" );
    for ( i=0 ; i<ROWS ; ++i ) {
        for ( j=0 ; j<COLS ; ++j ) {
            TEST_ELEM( i, j, (*((array2d)+(i)))[j], failed );
        }
        t0_print( "\n" );
    }
    t0_print( "\n" );
    upc_barrier;
    return failed;
}

/* Test pointer equivalence from ISO/IEC C99 6.5.2.1 2 for columns,
 * and array subscripting for rows.
 */
int
print_array2d_derefj( void )
{
    int failed = 0;
    int i,j;
    t0_print( "array2d (derefj):\n" );
    for ( i=0 ; i<ROWS ; ++i ) {
        for ( j=0 ; j<COLS ; ++j ) {
            TEST_ELEM( i, j, (*((array2d[i])+(j))), failed );
        }
        t0_print( "\n" );
    }
    t0_print( "\n" );
    upc_barrier;
    return failed;
}

/* Test pointer equivalence from ISO/IEC C99 6.5.2.1 2 for rows and columns */
int
print_array2d_derefij( void )
{
    int failed = 0;
    int i,j;
    t0_print( "array2d (derefij):\n" );
    for ( i=0 ; i<ROWS ; ++i ) {
        for ( j=0 ; j<COLS ; ++j ) {
            TEST_ELEM( i, j, (*(((*((array2d)+(i))))+(j))), failed );
        }
        t0_print( "\n" );
    }
    t0_print( "\n" );
    upc_barrier;
    return failed;
}

/* Test pointer-to-shared pointing to a shared array type, one row at a time */
int
print_array2dptr_helper( int i, shared [BLKS] VTYPE (*array2dptr)[COLS] )
{
    int failed = 0;
    int j;
    for ( j=0 ; j<COLS ; ++j ) {
        TEST_ELEM( i, j, (*array2dptr)[j], failed );
    }
    t0_print( "\n" );
    return failed;
}

int
print_array2dptr( void )
{
    int failed = 0;
    int i;
    t0_print( "array2dptr:\n" );
    for ( i=0 ; i<ROWS ; ++i ) {
        failed += print_array2dptr_helper( i, &array2d[i] );
    }
    t0_print("\n");
    upc_barrier;
    return (failed > 0) ? 1 : 0;
}

int
main()
{
    int failed = 0;

    if ( THREADS > MAX_THREADS ) {
        t0_print( "Please run with %d or fewer threads.\n",
                  MAX_THREADS );
        return -1;
    }

    init_array2d();

    failed += print_array2d();
    failed += print_array2d_derefi();
    failed += print_array2d_derefj();
    failed += print_array2d_derefij();
    failed += print_array2dptr();

    if ( failed != 0 ) {
        printf("Thread %d failed %d tests!\n",MYTHREAD,failed);
#ifdef BUPC_TEST_HARNESS
	failed_flag = 1;
#endif /* BUPC_TEST_HARNESS */
    }

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if ( MYTHREAD == 0 ) {
        printf("Issue03 test %s.\n", failed_flag ? "failed" : "passed");
    }
#endif /* BUPC_TEST_HARNESS */

#ifndef BUPC_TEST_HARNESS
    return 0;
#else /* BUPC_TEST_HARNESS */
    return failed_flag;
#endif /* BUPC_TEST_HARNESS */
}

// Tester for "issue 64" compliance: upc_barrier argument
// Copyright 2013, The Regents of the University of California,
// through Lawrence Berkeley National Laboratory (subject to
// receipt of any required approvals from U.S. Dept. of Energy)
// See the full license terms at
//       http://upc.lbl.gov/download/dist/LICENSE.TXT

#include <upc.h>
#include <stdio.h>
#include <math.h>

#define TEST_ONE(expr1, expr2) \
  if (MYTHREAD % 2) {  \
    upc_barrier expr1; \
    upc_notify  expr1; \
    upc_wait    expr2; \
  } else {             \
    upc_barrier expr2; \
    upc_notify  expr2; \
    upc_wait    expr1; \
  }

int main(void) {

  if (THREADS < 2) {
    if (!MYTHREAD)
      puts("This test must be run with 2 or more threads");
    return 1;
  }

  TEST_ONE(0, sin(0));
  TEST_ONE(1, 1U);
  TEST_ONE(2, 2L);
  TEST_ONE(3, 3LL);
  TEST_ONE(4, 4LU);
  TEST_ONE(5, 5LLU);
  TEST_ONE(6, (short)6);
  TEST_ONE(7, (unsigned short)7);
  TEST_ONE(8, (signed char)8);
  TEST_ONE(9, (unsigned char)9);
  TEST_ONE(10,10.1234);
  TEST_ONE(11,11.2345L);

  if (!MYTHREAD) puts("SUCCESS");
  return 0;
}

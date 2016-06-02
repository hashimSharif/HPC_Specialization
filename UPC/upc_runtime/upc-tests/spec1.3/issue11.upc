// Tester for "issue 11" compliance: PTS-to-integer conversion is legal
// Copyright 2013, The Regents of the University of California,
// through Lawrence Berkeley National Laboratory (subject to
// receipt of any required approvals from U.S. Dept. of Energy)
// See the full license terms at
//       http://upc.lbl.gov/download/dist/LICENSE.TXT

#include <upc.h>
#include <stdio.h> // puts

shared int x[THREADS];
shared double y[THREADS];
shared long z[THREADS];

// param:
int pass_int(int i) { return i; }
long pass_long(long i) { return i; }
long long pass_llong(long long i) { return i; }

// return:
int ret_int(shared void *p) { return (int)p; }
long ret_long(shared void *p) { return (long)p; }
long long ret_llong(shared void *p) { return (long long)p; }

int main(void) {
  const int idx = MYTHREAD;

  // Note: 'volatile' keeps optimizer from discarding statements we are testing
  volatile void * v = (void*)&x[idx];

  // initialization:
  volatile int       i = (int)      &x[idx];
  volatile long      j = (long)     &y[idx];
  volatile long long k = (long long)&z[idx];

  // parameter passing:
  i = pass_int  ((int)      &z[idx]);
  j = pass_long ((long)     &x[idx]);
  k = pass_llong((long long)&y[idx]);

  // return:
  i = ret_int  (&x[idx]);
  j = ret_long (&y[idx]);
  k = ret_llong(&z[idx]);

  // assignment:
  i = (int)       &y[idx];
  j = (long)      &z[idx];
  k = (long long) &x[idx];

  // expression/comparison:
  int result = (i == (int)&y[idx]) && (j == (long)&z[idx]) && (k == (long long)&x[idx]) && (v == (void*)&x[idx]);
  if (!MYTHREAD) puts(result ? "PASS" : "FAIL");
  upc_barrier;

  return !result;
}

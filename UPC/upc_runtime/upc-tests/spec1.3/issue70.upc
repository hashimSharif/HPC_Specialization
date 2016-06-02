// Tester for "issue 70" compliance: reset phase with incomplete types
// Copyright 2013, The Regents of the University of California,
// through Lawrence Berkeley National Laboratory (subject to
// receipt of any required approvals from U.S. Dept. of Energy)
// See the full license terms at
//       http://upc.lbl.gov/download/dist/LICENSE.TXT

#include <upc.h>
#include <stdio.h>
#include <stdint.h>

shared int fail;
shared [2] uint32_t x[2*THREADS];

shared [2] uint64_t * shared Qs[THREADS];
shared [2] uint64_t * Qp[1];

shared [4] uint32_t * shared Rs[THREADS];
shared [4] uint32_t * Rp[1];

struct foo; // forward decl
shared [2] struct foo * shared Ss[THREADS];
shared [2] struct foo * Sp[1];

shared void * shared Ts[THREADS];
shared void * Tp[1];

int main(void) {
  // phase is 1:
  shared [2] uint32_t *p = &x[1];
  if ( upc_phaseof(p) != 1 ) {
    puts("FAIL: upc_phaseof(p) != 1");
    fail = 1;
  }
 
  // The following assignments must reset phase because type sizes differ:
  shared [2] uint64_t *q = (shared [2] uint64_t *)p;
  if ( upc_phaseof(q) != 0 ) {
    puts("FAIL: phase not reset when converting to pointer to different sized type");
    fail = 1;
  }
  Qs[MYTHREAD] = (shared [2] uint64_t *)p;
  if ( upc_phaseof(Qs[MYTHREAD]) != 0 ) {
    puts("FAIL: phase not reset when converting to pointer to different sized type (shared array)");
    fail = 1;
  }
  Qp[0] = (shared [2] uint64_t *)p;
  if ( upc_phaseof(Qp[0]) != 0 ) {
    puts("FAIL: phase not reset when converting to pointer to different sized type (private array)");
    fail = 1;
  }

  // The following assignments must reset phase because blocksizes differ:
  shared [4] uint32_t *r = (shared [4] uint32_t *)p;
  if ( upc_phaseof(r) != 0 ) {
    puts("FAIL: phase not reset when converting to pointer to different block size");
    fail = 1;
  }
  Rs[MYTHREAD] = (shared [4] uint32_t *)p;
  if ( upc_phaseof(Rs[MYTHREAD]) != 0 ) {
    puts("FAIL: phase not reset when converting to pointer to different block size (shared array)");
    fail = 1;
  }
  Rp[0] = (shared [4] uint32_t *)p;
  if ( upc_phaseof(Rp[0]) != 0 ) {
    puts("FAIL: phase not reset when converting to pointer to different block size (private array)");
    fail = 1;
  }

  // The following assignments must reset phase because one type is incomplete:
  shared [2] struct foo *s = (shared [2] struct foo *)p;
  if ( upc_phaseof(s) != 0 ) {
    puts("FAIL: phase not reset when converting to pointer to incomplete type");
    fail = 1;
  }
  Ss[MYTHREAD] = (shared [2] struct foo *)p;
  if ( upc_phaseof(Ss[MYTHREAD]) != 0 ) {
    puts("FAIL: phase not reset when converting to pointer to incomplete type (shared array)");
    fail = 1;
  }
  Sp[0] = (shared [2] struct foo *)p;
  if ( upc_phaseof(Sp[0]) != 0 ) {
    puts("FAIL: phase not reset when converting to pointer to incomplete type (private array)");
    fail = 1;
  }

  // The following assignments must PRESERVE phase because target is a generic PTS:
  shared void *t = (shared void *)p;
  if ( upc_phaseof(t) != 1 ) {
    puts("FAIL: phase not preserved when converting to generic pointer-to-shared");
    fail = 1;
  }
  Ts[MYTHREAD] = (shared void *)p;
  if ( upc_phaseof(Ts[MYTHREAD]) != 1 ) {
    puts("FAIL: phase not preserved when converting to generic pointer-to-shared (shared array)");
    fail = 1;
  }
  Tp[0] = (shared void *)p;
  if ( upc_phaseof(Tp[0]) != 1 ) {
    puts("FAIL: phase not preserved when converting to generic pointer-to-shared (private array)");
    fail = 1;
  }

  upc_barrier;
  if (!MYTHREAD)
    puts(fail ? "FAIL" : "PASS");

  return !fail;
}

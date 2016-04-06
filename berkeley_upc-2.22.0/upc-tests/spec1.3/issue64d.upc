// Tester for "issue 64" compliance: upc_barrier argument
// Copyright 2013, The Regents of the University of California,
// through Lawrence Berkeley National Laboratory (subject to
// receipt of any required approvals from U.S. Dept. of Energy)
// See the full license terms at
//       http://upc.lbl.gov/download/dist/LICENSE.TXT

#include <upc.h>


int main(void) {
  union { int i; float f; } x;

  // This is an implicit union -> int conversion and should be an error
  upc_barrier x;
  upc_notify x;
  upc_wait x;

  return 0;
}

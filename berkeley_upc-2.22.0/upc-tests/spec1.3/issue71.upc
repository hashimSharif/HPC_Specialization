// Tester for "issue 71" compliance: no [*] in typedefs
// Copyright 2013, The Regents of the University of California,
// through Lawrence Berkeley National Laboratory (subject to
// receipt of any required approvals from U.S. Dept. of Energy)
// See the full license terms at
//       http://upc.lbl.gov/download/dist/LICENSE.TXT

// The following is prohibited:
typedef shared [*] int int_type;
int_type arr[3*THREADS];

int main(void) {
  arr[0] = 0; // ensure arr (and thus int_type) don't get discarded
  return 0;
}

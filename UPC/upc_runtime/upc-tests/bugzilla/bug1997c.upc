/* This tests exactly 1 erroneous case from bug1997, to ensure they EACH get a warning */
#include "upc.h"

static int matmult1(shared double *x) { return 0; } 

int main( int argc, char **argv ) {
  shared [10] double *x10 = 0;
  matmult1(x10);
  return 0;
}

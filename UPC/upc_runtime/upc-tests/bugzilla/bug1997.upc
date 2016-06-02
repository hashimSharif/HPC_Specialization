#include "upc.h"

static int matmult10(shared [10] double *x) {
  return 0;
}

static int matmult1(shared double *x) {
  return 0;
}

static int matmultI(shared [] double *x) {
  return 0;
}

static int matmultV(shared void *x) {
  return 0;
}

int main( int argc, char **argv ) {
  shared [] double *xI = 0;
  shared [10] double *x10 = 0;
  shared double *x1 = 0;
  shared void *xV = 0;

  /* all correct usage: */
  matmult10(x10);
  matmult1(x1);
  matmultI(xI);
  matmult10(xV);
  matmult1(xV);
  matmultI(xV);
  matmultV(x10);
  matmultV(x1);
  matmultV(xI);

  /* all of these are incorrect and should generate a type mismatch error */
  matmult10(x1);
  //matmult10(xI);
  //matmult1(x10);
  //matmult1(xI);
  matmultI(x1);
  //matmultI(x10);

  return 0;

}

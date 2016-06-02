#include "upc.h"

shared [*] double x[2*THREADS];

int main( int argc, char **argv ) {
  shared [] double *y = x;
  return 0;
}

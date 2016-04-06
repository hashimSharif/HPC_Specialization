#include "upc.h"

int main( int argc, char **argv ) {
  shared [10] double *x = 0;
  shared [] double *y = x;
  return 0;
}

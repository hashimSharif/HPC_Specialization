#include "upc.h"

int main( int argc, char **argv ) {
  shared double *x = 0;
  shared [10] double *y = x;
  return 0;
}

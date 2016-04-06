#include "upc.h"

int main( int argc, char **argv ) {
  shared double *x = 0;
  shared [] double *y = x;
  return 0;
}

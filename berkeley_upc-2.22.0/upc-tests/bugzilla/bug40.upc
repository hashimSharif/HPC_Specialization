#include <stdio.h>
#include "bug40.h"

int foobar(char *p1, signed char *p2, unsigned char *p3) {
  return (int)*p1 + (int)*p2 + (int)*p3;
}


int main() {
  char x = '\x7F';
  signed char y = '\x7F';
  unsigned char z = '\xFF';
  int result = foobar(&x, &y, &z);
  if (result != 509) printf("ERROR: wrong result %i\n", result);
  printf("done.\n");
  return 0;
}

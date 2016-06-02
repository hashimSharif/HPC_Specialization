
#include <math.h>

enum {
  #include "bug1965a_enum.h"
/*
  a,
  b,
  c
*/
};

struct a {
  #include "bug1965a_struct.h"
/*
  int i;
  float f;
*/
};

union {
  #include "bug1965a_union.h"
/*
  struct a s;
  double d;
*/
} u;

#include <stdio.h>

int main(void) {
  u.s.i = b;
  return 0;
}

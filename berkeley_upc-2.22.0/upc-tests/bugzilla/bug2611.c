#include <stdio.h>

struct a { int *b; };

struct a A = { (int []) { 5 } };

int main() {
  printf("%u\n", A.b[0]);
  return 0;
}


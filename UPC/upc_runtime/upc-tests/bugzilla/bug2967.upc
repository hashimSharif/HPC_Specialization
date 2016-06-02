#include <upc.h>

shared struct S { int i, j; } A = {1, 2};
shared struct   { int i, j; } C = {1, 2}; // Anonymous case works!

int main(void) {
#ifdef WORK_AROUND
  // OK, since I guess we see "struct S" as used
  struct S B = A;
  return (B.i != 1);
#else
  // BAD even though A *is* used in .trans.c
  return (A.i != 1);
#endif
}

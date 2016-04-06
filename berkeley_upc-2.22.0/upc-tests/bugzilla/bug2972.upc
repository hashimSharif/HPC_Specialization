#include <upc.h>
#include <stdio.h> // for putchar() and puts()

int (*f1)(int) = &putchar; // BAD

int main(void) {
  int (*f2)(int) = &putchar; // OK
  int fail = (f1 != f2);
  puts (fail ? "FAIL" : "PASS");
  return fail;
}

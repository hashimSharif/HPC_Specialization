#include <upc.h>
#include <stdio.h>

int foo(shared int *p) { return (p == NULL); }

int main(void) {
  int result = foo(1); // BUG: 1 is passed as shared NULL
  puts(result ? "FAIL" : "PASS");
  return result;
}

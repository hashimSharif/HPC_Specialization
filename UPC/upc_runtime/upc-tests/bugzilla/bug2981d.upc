#include <upc.h>
#include <stdio.h>

int foo(shared int *p) { return (p == NULL); }

int main(void) {
  int result = foo((shared int *)1);
  puts(result ? "FAIL" : "PASS");
  return result;
}

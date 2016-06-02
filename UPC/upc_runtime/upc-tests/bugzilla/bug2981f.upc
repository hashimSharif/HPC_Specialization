#include <upc.h>
#include <stdio.h>

shared void *foo(void) { return (shared int *)1; }
  
int main(void) {
  int result = (foo() == NULL);
  puts(result ? "FAIL" : "PASS");
  return result;
}

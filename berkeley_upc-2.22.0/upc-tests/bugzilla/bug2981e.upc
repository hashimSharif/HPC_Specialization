#include <upc.h>
#include <stdio.h>

shared void *foo(void) {
  shared void *p = (shared int *)1;
  return p;
}
  
int main(void) {
  int result = (foo() == NULL);
  puts(result ? "FAIL" : "PASS");
  return result;
}

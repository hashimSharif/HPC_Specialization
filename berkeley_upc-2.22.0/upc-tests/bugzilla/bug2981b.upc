#include <upc.h>
#include <stdio.h>

shared void *foo(void) {
  shared void *p = 1; // BUG: p is initialized to shared NULL
  return p;
}
  
int main(void) {
  int result = (foo() == NULL);
  puts(result ? "FAIL" : "PASS");
  return result;
}

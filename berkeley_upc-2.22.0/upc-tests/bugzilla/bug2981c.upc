#include <upc.h>
#include <stdio.h>

shared void *foo(void) { return 1; }
  
int main(void) {
  int result = (foo() == NULL);
  puts(result ? "FAIL" : "PASS");
  return result;
}

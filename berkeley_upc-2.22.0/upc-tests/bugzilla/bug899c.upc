#include <upc.h>
#include <stdio.h>

extern int test(void);

int main(void) {
  int result = test();
  puts(result ? "PASS" : "FAIL");
  return !result;
}

#include <upc.h>
#include <stdio.h>

shared int i = 1;
shared struct { int j,k; } s = { 2,3 };

int main(void) {
  if (!MYTHREAD) puts("PASS");
  return 0;
}

// Derived from Gary Funck's attachment to bug 2902
#include <stdio.h>
#include <stdlib.h>

int x[]; // Incomplete array type

int main(void)
{
  unsigned long n_elem = (unsigned long)(sizeof(x)/sizeof(int));
  printf ("number of elements in x = %lu\n", n_elem);
  if (n_elem < 1) {
      puts("FAIL: number of elements in x < 1");
      return 1;
  }
  x[0] = 10;
  if (x[0] != 10) {
      puts("FAIL: x[0] != 10");
      return 1;
  }
  puts("Test PASSED");
  return 0;
}

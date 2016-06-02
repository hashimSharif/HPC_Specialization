#include <stdio.h>

int main(void)
{
  int a, b;

  #include "bug1965.h"

  if (a == c) printf("PASS\n");
  else printf("FAIL\n");

  return 0;
}

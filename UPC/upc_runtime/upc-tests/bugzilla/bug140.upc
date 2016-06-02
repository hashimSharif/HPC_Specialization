#include <stdio.h>

int main() {
  double x;
  x = 1.1;
  x += (double)(1.1f);
  if (x != 2.2) printf("ERROR: bad value!\n");
  else printf("done.\n");
  return 0;
}

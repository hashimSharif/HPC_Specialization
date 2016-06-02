#include <stdlib.h>


int entry_comparison(const void *e1, const void *e2) { return 0; }

int main() {
  int x[10];
  qsort(&x, 10, sizeof(int), entry_comparison);
  return 0;
}

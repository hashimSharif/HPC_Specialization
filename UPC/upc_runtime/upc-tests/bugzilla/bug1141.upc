#include <upc.h>
#include <stdio.h>

int main() {
  shared int *x = upc_all_alloc(10,10);
  if (x) printf("done.\n");
  else printf("ERROR\n");
}

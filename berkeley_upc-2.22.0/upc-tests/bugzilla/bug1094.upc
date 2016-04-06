#include <upc.h>
#include <stdio.h>

int main() {
  shared void *addr = NULL;
  shared void *addr2 = NULL;
  int x = ((shared [] char *)addr) - ((shared [] char *)addr2);
  if (x == 0) printf("done.\n");
  else printf("ERROR: %i\n",x);
}

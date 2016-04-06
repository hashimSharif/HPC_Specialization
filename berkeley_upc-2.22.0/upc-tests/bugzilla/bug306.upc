#include <stdio.h>
#include <upc.h>

int main() {
  shared void *p = upc_global_alloc(2,2);
  if (upc_threadof(p) != 0) printf("ERROR: thread = %i\n",(int)upc_threadof(p));
  upc_free(p);
  printf("done.\n");
  return 0;
}

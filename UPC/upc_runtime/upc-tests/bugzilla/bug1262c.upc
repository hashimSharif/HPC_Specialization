#include <upc.h>
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

int main() {
  shared void *p;
  p = upc_alloc(0);
  assert(p == NULL);
  upc_free(p);
  p = upc_all_alloc(0,1);
  assert(p == NULL);
  upc_free(p);
  p = upc_all_alloc(1,0);
  assert(p == NULL);
  upc_free(p);
  p = upc_global_alloc(0,1);
  assert(p == NULL);
  upc_free(p);
  p = upc_global_alloc(1,0);
  assert(p == NULL);
  upc_free(p);
  printf("done.\n");
  return 0;
}

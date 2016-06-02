#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

shared void * tmp;

int main(int argc, char **argv) {
  shared void **ptrs;
  shared void * shared *shptrs;
  int i = 0;
  int iters = 10;

  ptrs = malloc(sizeof(shared void *) * iters);
  shptrs = upc_all_alloc(sizeof(shared void *) * iters, 1);

    for (i=0; i < iters; i++) {
      ptrs[i] = upc_alloc(1); 
    }
    for (i=0; i < iters; i++) {
      upc_free(ptrs[i]); 
    }
  tmp = shptrs; /* prevent shptrs from being optimized away */
  printf("done.");
  return 0;
}

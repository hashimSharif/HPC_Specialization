#include <upc.h>
#include <stdio.h>

shared [10] int A[20*THREADS];

#define SHOW_PTR(x) \
  printf("upc_threadof("#x") = %i upc_phaseof("#x") = %i upc_addrfield("#x") = 0x%llx \n",\
          (int)upc_threadof(x),(int)upc_phaseof(x),(unsigned long long)upc_addrfield(x))

int main() {
  shared [10] int *p = &A[8];
  shared [10] int *q = &A[11];
  SHOW_PTR(p);
  SHOW_PTR(q);
  printf("q - p = %i\n", (int)(q - p));
  printf("q > p = %i\n", (q > p));
  if (p > q) printf("ERROR\n");
  else printf("done.\n");
}

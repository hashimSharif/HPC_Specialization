#include <stdio.h>
#include <inttypes.h>
#include <upc.h>

shared [] uint64_t s_A[11][12][13];

int main() {
  shared [] uint64_t * srcaddr = &(s_A[5][6][7]); 
  if ((srcaddr - (shared [] uint64_t*)s_A) != (5*12*13 + 6*13 + 7)) printf("ERROR\n");
  printf("done.\n");
return 0;
}

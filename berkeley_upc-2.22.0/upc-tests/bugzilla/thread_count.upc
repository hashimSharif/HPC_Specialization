/*
 * This test runs at various "odd" thread counts to check for corner
 * cases in the spawners, allocation, initialization, etc.
 */
#include <upc.h>
#include <stdio.h>

#define BLKSIZE 2

shared [BLKSIZE] int *A;
int main(void) {

  /* upc_all_alloc() for bug 1262 */
  A = upc_all_alloc(BLKSIZE, sizeof(int)*BLKSIZE);

  upc_barrier;
  if (!MYTHREAD) printf("done.\n");
  upc_barrier;

  return 0;
}

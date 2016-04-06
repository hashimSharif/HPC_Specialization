#include <upc.h>
#include <stdio.h>
#define BLKSIZE 100

int shared [BLKSIZE] *p0, *p1;
shared [BLKSIZE] int *p2, *p3;

int main() {
  if (upc_blocksizeof(*p0) != BLKSIZE) printf("ERROR0\n");
  if (upc_blocksizeof(*p1) != BLKSIZE) printf("ERROR1\n");
  if (upc_blocksizeof(*p2) != BLKSIZE) printf("ERROR2\n");
  if (upc_blocksizeof(*p3) != BLKSIZE) printf("ERROR3\n");
  printf("done.\n");
  return 0;
}


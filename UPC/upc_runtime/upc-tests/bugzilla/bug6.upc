#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

#if UPC_MAX_BLOCK_SIZE >= 1000000
#define BLK_SIZE 1000000
#elif UPC_MAX_BLOCK_SIZE >= 100
#define BLK_SIZE 100
#else
#define BLK_SIZE 1
#endif

shared [UPC_MAX_BLOCK_SIZE] char (*p)[UPC_MAX_BLOCK_SIZE];
shared [BLK_SIZE] char a[THREADS*BLK_SIZE];
shared [2] char b[THREADS * 1000000];
shared int fail = 0;

int main(void)
{
  if (upc_blocksizeof(*p) != UPC_MAX_BLOCK_SIZE)
    {
      fprintf (stderr, "block size of '*p' %lu != %lu\n", (unsigned long)upc_blocksizeof(*p), (unsigned long)UPC_MAX_BLOCK_SIZE);
      fail = 1;
    }
  if (upc_blocksizeof(a) != BLK_SIZE)
    {
      fprintf (stderr, "block size of 'a' %lu != %lu\n", (unsigned long)upc_blocksizeof(a), (unsigned long)BLK_SIZE);
      fail = 1;
    }
  if (upc_blocksizeof(b) != 2)
    {
      fprintf (stderr, "block size of 'b' %lu != %lu\n", (unsigned long)upc_blocksizeof(b), (unsigned long)2);
      fail = 1;
    }
  if (upc_localsizeof(*p) < UPC_MAX_BLOCK_SIZE)
    {
      fprintf (stderr, "local size of '*p' %lu < %lu\n", (unsigned long)upc_localsizeof(*p), (unsigned long)UPC_MAX_BLOCK_SIZE);
      fail = 1;
    }
  if (upc_localsizeof(a) < BLK_SIZE)
    {
      fprintf (stderr, "local size of 'a' %lu < %lu\n", (unsigned long)upc_localsizeof(a), (unsigned long)BLK_SIZE);
      fail = 1;
    }
  if (upc_localsizeof(b) < 1000000)
    {
      fprintf (stderr, "local size of 'b' %lu < %lu\n", (unsigned long)upc_localsizeof(b), (unsigned long)1000000);
      fail = 1;
    }
  upc_barrier;
  if (!MYTHREAD)
    puts(fail ? "FAILED" : "done.");
  return 0;
}

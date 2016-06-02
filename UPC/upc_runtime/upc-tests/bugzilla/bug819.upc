/* Compact test case to reproduce bug 819 */
#include <upc.h>

/* XXX: Changing to * or any integer >1 eliminates the bug */
#define BLKSZ 1
shared [BLKSZ] int array[THREADS];

int main(void) {
  /* XXX: removing both of the following eliminates the warning */
  int i = upc_blocksizeof(array);
  int j = upc_localsizeof(array);
  upc_global_exit(-1);
  return 0;
}

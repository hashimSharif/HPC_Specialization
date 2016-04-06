#include <upc.h>

shared [UPC_MAX_BLOCK_SIZE+1] char y[THREADS*(UPC_MAX_BLOCK_SIZE+1)]; /* error */

int main(void) { return 0; }

#include <upc.h>

shared [*] char z[THREADS*(UPC_MAX_BLOCK_SIZE+1)]; /* error */

int main(void) { return 0; }

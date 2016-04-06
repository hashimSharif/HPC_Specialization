/* Maximum UPC block size in this implementation exceeded.  */

#include <upc.h>

shared [UPC_MAX_BLOCK_SIZE+1] int A[(UPC_MAX_BLOCK_SIZE+1)*THREADS];

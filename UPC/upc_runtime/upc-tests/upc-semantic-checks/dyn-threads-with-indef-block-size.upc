/* In the UPC dynamic translation environment,
   THREADS may not appear in declarations
   of shared arrays with indefinite block size;
   the storage size cannot be calculated. */
#include <upc.h>

/* CHECK */
shared [] int A[THREADS];

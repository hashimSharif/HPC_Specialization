/* In the UPC dynamic translation environment,
   THREADS must appear exactly once in 
   declarations of shared arrays; 
   the storage size cannot be calculated. */

#include <upc.h>

/* CHECK */
shared int A[THREADS*THREADS];

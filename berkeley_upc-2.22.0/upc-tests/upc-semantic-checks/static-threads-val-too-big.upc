/* THREADS value exceeds UPC implementation limit.  */

#include <upc.h>

/* Must be compiled with large static value of THREADS.  */
shared int A[THREADS];

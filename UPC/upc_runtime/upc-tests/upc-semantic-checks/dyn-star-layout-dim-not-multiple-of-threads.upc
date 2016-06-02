/* A UPC layout qualifier of '[*]' requires that
   the array size is either an integral constant
   or an integral multiple of THREADS.  */

#include <upc.h>

/* CHECK */
shared [*] int A[THREADS+1];

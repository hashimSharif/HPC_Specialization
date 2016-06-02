/* UPC shared array declaration references THREADS
   more than once; the size cannot be calculated.  */

#include <upc.h>

/* CHECK */
shared int A[THREADS][THREADS];

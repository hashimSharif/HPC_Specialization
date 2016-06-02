/* UPC shared array dimension is not a simple multiple 
   of THREADS; the size cannot be calculated. */

#include <upc.h>

shared int A[10*THREADS + 1];

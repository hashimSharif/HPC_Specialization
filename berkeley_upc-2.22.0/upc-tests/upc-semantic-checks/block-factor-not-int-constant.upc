/* UPC layout qualifier is not an integral constant.  */

#include <upc.h>

shared [0.5] int A[10*THREADS];

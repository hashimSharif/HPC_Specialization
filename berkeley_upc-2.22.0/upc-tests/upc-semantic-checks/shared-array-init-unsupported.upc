/* Initialization of UPC shared arrays is currently not supported.  */

#include <upc.h>

shared int A[3*THREADS] = {1, 2, 3};

/* UPC layout qualifier is incompatible with the referenced type.  */

#include <upc.h>

typedef shared [3] int array_blocked_3_type[30];

shared [5] array_blocked_3_type A[THREADS];

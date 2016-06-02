/* UPC layout qualifier cannot be applied to a void type.  */

#include <upc.h>

shared [5] void *pts;

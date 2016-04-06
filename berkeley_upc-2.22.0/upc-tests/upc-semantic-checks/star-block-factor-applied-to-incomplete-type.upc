/* UPC layout qualifier of the form [*] cannot be
   applied to an incomplete type.  */

#include <upc.h>

shared [*] struct s_struct A5_icomplete[5*THREADS];

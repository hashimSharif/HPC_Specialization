/* ‘barrier’ was supported in version 1.0 of the UPC specification,
    it has been deprecated, use ‘upc_barrier’ instead.  */

#include <upc.h>

int main()
{
   barrier;
   return 0;
}

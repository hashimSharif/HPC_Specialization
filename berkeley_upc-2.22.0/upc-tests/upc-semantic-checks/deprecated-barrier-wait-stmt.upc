/* ‘barrier_wait’ was supported in version 1.0 of the UPC specification,
    it has been deprecated, use ‘upc_wait’ instead.  */

#include <upc.h>

int main()
{
   barrier_wait;
   return 0;
}

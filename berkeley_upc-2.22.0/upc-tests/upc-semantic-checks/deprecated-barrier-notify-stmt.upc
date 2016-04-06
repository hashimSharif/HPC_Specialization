/* ‘barrier_notify’ was supported in version 1.0 of the UPC specification,
    it has been deprecated, use ‘upc_notify’ instead.  */

#include <upc.h>

int main()
{
   barrier_notify;
   return 0;
}

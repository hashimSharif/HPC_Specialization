/* ‘forall’ was supported in version 1.0 of the UPC specification,
    it has been deprecated, use ‘upc_forall’ instead.  */

#include <upc.h>

shared int A[THREADS];

int main()
{
   forall (int i = 0; i < THREADS; ++i; i)
     {
       A[i] = 1;
     }
   return 0;
}

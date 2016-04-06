/* Initialization attempts to make a UPC pointer-to-shared value
   from an integer without a cast.  */

#include <upc.h>

shared int *p_4000;

int main()
{
   shared int *p = 0x4000;
   p_4000 = p;
   return 0;
}

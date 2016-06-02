/* Passing argument attempts to make a UPC pointer-to-shared
   value from an integer.  */

#include <upc.h>


extern void proc (shared int *arg);

int main()
{
   proc (0x4000);
   return 0;
}

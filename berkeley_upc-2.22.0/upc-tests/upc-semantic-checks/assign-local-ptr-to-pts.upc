/* UPC does not allow assignments from a local pointer
   to a pointer-to-shared.  */

#include <upc.h>

int x;

shared int *pts;

int main (void)
{
  int *local_ptr = &x;
  pts = local_ptr;
  return 0;
}

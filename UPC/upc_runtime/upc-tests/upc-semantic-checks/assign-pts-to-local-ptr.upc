/* UPC does not allow assignments
   from a pointer-to-shared to a local pointer.  */

#include <upc.h>

shared int *pts;

int main (void)
{
  int *local_ptr = pts;
  *local_ptr = 1;
  return 0;
}

/* UPC does not allow casts from a local pointer to a pointer-to-shared.  */

#include <upc.h>

int x;

int main (void)
{
  int *local_ptr = &x;
  shared int *pts = (shared int *)local_ptr;
  *pts = 1;
  return 0;
}

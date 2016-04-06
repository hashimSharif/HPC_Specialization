/* UPC does not allow casts from an integer to a pointer-to-shared.  */

#include <upc.h>

int main (void)
{
  shared int *pts = (shared int *)0x400;
  *pts = 1;
  return 0;
}

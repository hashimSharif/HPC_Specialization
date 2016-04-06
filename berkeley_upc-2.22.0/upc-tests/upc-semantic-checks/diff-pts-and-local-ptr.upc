/* Attempt to take the difference of a UPC pointer-to-shared
   and a local pointer.  */

#include <upc.h>

int x;
shared int v;

shared int *pts;
int *local_ptr;
int diff;

int main (void)
{
  local_ptr = &x;
  pts = &v;
  diff = (pts - local_ptr);
  return 0;
}

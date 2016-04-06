/* UPC does not allow comparisons between pointers to shared and
   local pointers.  */

#include <upc.h>

int x;
shared int v;

shared int *pts;
int *local_ptr;

int main (void)
{
  local_ptr = &x;
  pts = &v;
  return pts < local_ptr;
}

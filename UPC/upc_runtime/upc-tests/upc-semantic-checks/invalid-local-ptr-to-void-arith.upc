/* The consensus of the UPC community seems to be that
   arithmetic on (void *) pointers is a compilation error.  */

#include <upc.h>

int A[10];
void *p;

int main()
{
  p = (void *)A;
  p = p + 1;
  *((int *)p) = 1;
  return 0;
}

/* UPC operator applied to a void type.  */

#include <upc.h>

void *p;
size_t s;


int main()
{
  s = upc_localsizeof (*p);
  return 0;
}

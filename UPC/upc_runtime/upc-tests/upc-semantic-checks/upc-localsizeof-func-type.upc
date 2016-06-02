/* UPC operator applied to a function type.  */

#include <upc.h>


void func(void) {}

size_t s;

int main()
{
  s = upc_localsizeof (func);
  return 0;
}

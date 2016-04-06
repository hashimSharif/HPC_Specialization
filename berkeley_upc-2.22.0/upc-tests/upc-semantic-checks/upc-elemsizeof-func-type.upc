/* UPC operator applied to a function type.  */

#include <upc.h>


void func(void) {}

size_t s;

int main()
{
  s = upc_elemsizeof (func);
  return 0;
}

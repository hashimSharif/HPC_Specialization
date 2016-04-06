/* UPC operator applied to a non-shared type.  */

#include <upc.h>

int x[10];
size_t s;

int main()
{
  s = upc_blocksizeof (x);
  return 0;
}

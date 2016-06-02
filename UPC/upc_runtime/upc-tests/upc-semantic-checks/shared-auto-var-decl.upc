/* UPC does not support shared auto variables.  */

#include <upc.h>

int decl_shared_local (int p)
{
  shared int x = p;
  return x;
}

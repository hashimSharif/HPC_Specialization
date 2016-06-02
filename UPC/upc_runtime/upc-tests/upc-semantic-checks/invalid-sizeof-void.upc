/* The consensus of the UPC community seems to be that
   sizeof (void) is a compilation errors.  */

#include <upc.h>

int main()
{
  return sizeof (void);
}


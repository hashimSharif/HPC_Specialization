#include <upc.h>
#include "bug232.h"

double foo(point *in)
{
  return(in->x+in->y);
}

int main() {

  return 0;
}

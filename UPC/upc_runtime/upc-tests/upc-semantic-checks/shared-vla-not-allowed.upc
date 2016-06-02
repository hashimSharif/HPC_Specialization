/* UPC forbids the declaration of a variable-size shared array. */

#include <upc.h>

void declare_shared_vla (int N)
{
  shared int A[N*THREADS];
  A[0] = 1;
}


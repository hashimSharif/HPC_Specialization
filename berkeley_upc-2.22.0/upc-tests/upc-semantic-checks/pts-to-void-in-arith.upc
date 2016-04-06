/* UPC does not allow a pointer of type `shared void *'
   to be used in arithmetic.  */

#include <upc.h>

shared int A[THREADS];
shared void *pts;
shared int  *pts2;
size_t diff;

int main()
{
  pts = (shared void *)&A[0];
  pts += (MYTHREAD + 1) % THREADS;
  return 0;
}

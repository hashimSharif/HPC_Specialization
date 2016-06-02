/* Invalid application of <op> to shared void.
   (where <op> is sizeof(0) or __alignof()) */

#include <upc.h>

shared int A[THREADS];

size_t size;

int main()
{
   shared void *p = (shared void *)A;
   size = sizeof (*p);
   return 0;
}

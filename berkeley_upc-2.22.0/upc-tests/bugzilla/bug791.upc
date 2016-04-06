#include <upc.h>
#include <stddef.h>

#ifdef NORESTRICT
#define restrict
#endif

void my_function ( shared int * restrict y1, shared int * restrict z1) 
{
}  


int main() {
  shared int *a=NULL, *b=NULL;
  my_function(a,b);
  return 0;
}

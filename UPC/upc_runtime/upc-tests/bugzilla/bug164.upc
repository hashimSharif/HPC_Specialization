#include <upc_relaxed.h>
shared [] int *foo;
int main()
{
  foo = (shared [] int *) upc_alloc(100*sizeof(int));
  *((int *) foo)=1;
  return(0);
} 

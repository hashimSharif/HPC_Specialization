#include <stdlib.h>

void my_function ( int * restrict y1, void * restrict x) 
{
}  


int main() {
  int *p = NULL;
  int * restrict p2 = NULL;
  my_function(p,p2);
  return 0;
}

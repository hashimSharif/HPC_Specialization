#include <stdio.h>
#include <upc.h>

void foo(int lim) {
int array[lim];
  int i,j;
  for(i=0; i<lim; i++){
    array[i] = i;
  }
  for(i=0; i<lim; i++){
    j = array[i];
    if (j != i)
      printf("ERROR: read array[%i]=%d\n", i, j);
  }
}

int main(void)
{
  foo(18);

  upc_barrier;
  
  printf("done.\n");
  return (0);
}

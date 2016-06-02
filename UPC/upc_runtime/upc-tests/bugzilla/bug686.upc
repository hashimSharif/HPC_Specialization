#include <stdio.h>
#include <upc.h>

int main(void)
{
  int i, j;
  int array[THREADS];

  for(i=0; i<THREADS; i++){
    array[i] = 0;
  }

  j = array[0];
  if (j != 0)
    printf("ERROR: read j=%d\n", j);
  else
    printf("done.\n");

  upc_barrier;
  
  return (0);
}

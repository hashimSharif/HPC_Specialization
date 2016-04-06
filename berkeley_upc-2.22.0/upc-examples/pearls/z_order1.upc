/* Matrix multiplication */
#include <upc.h>
#include <stdio.h>
#include "z_order.h"

#define N 256
#define BLK (N*N/THREADS)
#define elem_t double
#define MTYPE shared[BLK] elem_t

/* Shared arrays */
MTYPE a[N][N], b[N][N], c[N][N];

int main()
{
  int i, j, k;

  for (i = 0; i < N; i++) {
    *(z_index((MTYPE *)a,i,i)) = 1;
    *(z_index((MTYPE *)b,i,i)) = i;
  }

  upc_barrier;

  for (i = 0; i < N; i++)
  {
    upc_forall (j = 0; j < N; j++; z_index((MTYPE *)c,i,j))
    {
      for (k = 0; k < N; k++)
        *(z_index((MTYPE *)c,i,j)) += 
          (*(z_index((MTYPE *)a,i,k))) * (*(z_index((MTYPE *)b,k,j)));
    }
  }

  upc_barrier;

  if (MYTHREAD == 0)
  { 
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++) {
        if (i==j) {
         if (*(z_index((MTYPE *)c,i,j)) != i) 
          printf ("ERROR: c[%d][%d]=%f\n", i, j, *(z_index((MTYPE *)c,i,j)));
        } else if (*(z_index((MTYPE *)c,i,j)) != 0)
          printf ("ERROR: c[%d][%d]=%f\n", i, j, *(z_index((MTYPE *)c,i,j)));
      }
    }
  }

  upc_barrier;

  printf("done.\n");
  return 0;
}

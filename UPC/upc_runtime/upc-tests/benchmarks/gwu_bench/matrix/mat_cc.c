// UPC Matrix multiplication Example
// a(N, P) is multiplied by b(P, M).  Result is stored in c(N, M)
// In this example, a is distributed by rows while b is distributed by columns.
// We do use the upc_forall construct in this example

#include <stdio.h>

#include <sys/time.h>

#include "second_cpu.c"

#include "conf.h"

elem_t a[N/NUM_PROC][P];
elem_t c[N/NUM_PROC][M];

#define NUM_PROC 1
  
elem_t b[P][M];

int main(int argc, char** argv) {

  int i,j,l;
  double sec;

  elem_t sum;

  if (N % NUM_PROC)
  { printf("The number of lines must be a multiple of the number of processor (%d)\n", N, NUM_PROC);
    exit(1);
  }

  if (1!=NUM_PROC)
  { printf("Please reconfigure for the valid number of processors (%d).\n", NUM_PROC);
    exit(1);
  }

// Collective arrays initialization for a 

  for(i=0;i<N;i++)
    for(j=0;j<P;j++) 
      a[i][j]=(i*NUM_PROC)*j+1;

  { for(i=0;i<P;i++)
      for(j=0;j<M;j++)
        b[i][j] = i * N +j + 3;
  }

  sec = second();

// all threads  perform matrix multiplication


  for(i=0;i<N/NUM_PROC;i++)
  // &a[i][0] specifies that this iteration will be 
  // executed by the thread that has affinity to element a[i][0]
  // This thread will have the affinity with the whole line

         for (j=0; j<M; j++) {
           sum = 0;
           for(l=0; l< P; l++) 
             sum +=a[i][l]*b[l][j];
           c[i][j] = sum;
         }


  printf("%lf\n", second()-sec);

//  Every thread print its own part of the matrix

#if 0
  { printf("\n\n");
    for(i=0;i<N;i++)
    { 
        for(j=0;j<M;j++)
          printf("c[%d][%d]=%lf\n",i,j,c[i/NUM_PROC][j]);
      fflush(stdout);
    }
  }
#endif
}

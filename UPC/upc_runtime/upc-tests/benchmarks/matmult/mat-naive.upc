/**
 * 
 * UPC Matrix multiplication Example
 * 
 * Compute C (N,M) = C(N,M) + a(N, P) * b(P, M).
 * This algorithm uses a simple 1D layout:
 * A and C are distributed by rows, while B is distributed by columns.
 */

#include <config.h>

shared [P] elem_t a[N][P];
shared [M] elem_t c[N][M];
shared elem_t b[P][M];

int main(int argc, char** argv) {

  int i,j,l;
  double sec;

  elem_t sum;

  /* Initializing a and b */
  for(i=0;i<N;i++)
    upc_forall(j=0;j<P;j++; &a[i][j]) 
      a[i][j]=(i*THREADS)*j+1;

  for(i=0;i<P;i++)
    upc_forall(j=0;j<M;j++; &b[i][j])
      b[i][j] = i * N +j + 3;
  upc_barrier;

  sec = second();

  /* all threads perform matrix multiplication */

  upc_forall(i=0; i<N; i++; &a[i][0]) {
    for (j=0; j<M; j++) {
      sum = 0;
      for(l=0; l< P; l++) 
	sum +=a[i][l]*b[l][j];
      c[i][j] += sum;
    }
  }

  printf("THREAD %d: running for %2f seconds\n", MYTHREAD, (second() - sec));

//  Every thread print its own part of the matrix

#if 0
  { printf("\n\n");
    for(i=0;i<N;i++)
    { 
        for(j=0;j<M;j++)
          printf("c[%d][%d]=%lf\n",i,j,c[i/THREADS][j]);
      fflush(stdout);
    }
  }
#endif
  upc_barrier;
  printf("done.\n");
}

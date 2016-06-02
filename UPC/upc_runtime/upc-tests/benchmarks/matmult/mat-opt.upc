/**
 * 
 * UPC Matrix multiplication Example
 * 
 * Compute C (N,M) = C(N,M) + a(N, P) * b(P, M).
 * This algorithm uses a simple 1D layout:
 * A and C are distributed by rows, while B is distributed by columns.
 * The difference is now that the entire B matrix is prefetched so that redundant communications 
 * can be avoided
 */

#include <config.h>

shared [P] elem_t a[N][P];
shared [M] elem_t c[N][M];
shared elem_t b[P][M];

int main(int argc, char** argv) {

  int i,j,l;
  double sec;
  elem_t blocal[P][M];

  elem_t sum;

  /* Initializing a and b */
  for(i=0;i<N;i++)
    upc_forall(j=0;j<P;j++; &a[i][j]) 
      a[i][j]=(i*THREADS)*j+1;

  for(i=0;i<P;i++)
    upc_forall(j=0;j<M;j++; &b[i][j])
      b[i][j] = i * N +j + 3;

  upc_barrier(0);
  sec = second();

  /* prefetch B */
#if 0
  // WARNING! The upc_memget() below is just plain WRONG for 2 reasons:
  // 1) The src doesn't have affinity to a single thread as required by spec.
  // 2) Since i==P at this point the src is not even the intended b array.
  // So, this just makes a local copy of uninitialized/unallocated memory!
  upc_memget(&blocal, &b[i], sizeof(b));
#else
  // Corrected code from Dan Bonachea's fixes to gwu_bench/matrix/mat-opt-prefetch:
  bupc_handle_t h[THREADS];
  for (int i=0; i < THREADS; i++) {
    int th = (MYTHREAD+i)%THREADS;
    size_t thsz = upc_affinitysize(P*M*sizeof(elem_t), sizeof(elem_t), th);
    h[i] = bupc_memget_fstrided_async(&blocal[0][th], sizeof(elem_t),
                                      THREADS*sizeof(elem_t), thsz/sizeof(elem_t),
                                      &b[0][th], thsz, thsz, 1);
  }
  bupc_waitsync_all(h, THREADS);
#endif

  /* all threads perform matrix multiplication */

  upc_forall(i=0; i<N; i++; &a[i][0]) {
    for (j=0; j<M; j++) {
      for(l=0; l< P; l++) 
	c[i][j] +=a[i][l] * blocal[l][j];
    }
  }

  printf("%f\n", second()-sec);

//  Every thread print its own part of the matrix

#if 0
  { printf("\n\n");
    for(i=0;i<N;i++)
    { 
        for(j=0;j<M;j++)
          printf("c[%d][%d]=%f\n",i,j,c[i/THREADS][j]);
      fflush(stdout);
    }
  }
#endif
  upc_barrier;
  printf("done.\n");
}

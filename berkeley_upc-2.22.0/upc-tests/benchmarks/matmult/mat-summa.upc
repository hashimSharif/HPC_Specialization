/**
 * 
 * UPC Matrix multiplication Example
 * 
 * Compute C (N,M) = C(N,M) + a(N, P) * b(P, M).
 * This uses the SUMMA algorithm
 */

#include <config.h>
#include <math.h>

struct square_mat {
  elem_t x[N][N];
};

shared struct square_mat a [THREADS];
shared struct square_mat b [THREADS];
shared struct square_mat c [THREADS];

elem_t res[N][N];

void init_matrix(shared struct square_mat* p) {
  
  int i,j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      p->x[i][j] = (MYTHREAD+1)*(2*i + j);
      //p->x[i][j] = MYTHREAD+1;
    }
  }
}

void mult(elem_t* col, elem_t* row) {

  int i,j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      res[i][j] = col[i] * row[j];
    }
  }
}

int main (int argc, char** argv) {

  int i,j,k,m,n;
  int dim;
  int owner;
  elem_t sum;
  elem_t acol[N], brow[N];
  double sec;
  struct square_mat tmp;
  shared struct square_mat *sptr;

  /* assume square grid for now 
   * (what's a good way to setup grid for non perfect square number of processors,
   *  factor it?)
   */
  if (THREADS != 1 && THREADS != 4 && THREADS != 9 && THREADS != 25) {
    printf("Number of THREADS(%d) must be a perfect square\n", THREADS);
    upc_global_exit(1);
  }
  /* initialize the matrices */
  upc_forall (i = 0; i < THREADS; i++; &a[i]) {
    init_matrix(&a[i]);
    init_matrix(&b[i]);
    init_matrix(&c[i]);
  }
  
  printf("THREAD %d starting\n", MYTHREAD);
  upc_barrier;
  
  sec = second();
  dim = (int) sqrt(THREADS);

  for (k = 0; k < N * dim; k++) {
    /* copy acol */
    owner = ((MYTHREAD / dim) * dim) + k / N;
    tmp = a[owner];
    for (i = 0; i < N; i++) {
      acol[i] = tmp.x[i][k%N];
    }
    
    /* copy brow */
    owner = ((k / N) * dim) + MYTHREAD % dim;
    tmp = b[owner];
    for (i = 0; i < N; i++) {
      brow[i] = tmp.x[k%N][i];
    }
    
    /* now compute */
    upc_forall (i = 0; i < THREADS; i++; &c[i]) {
      mult(acol, brow);
      sptr = &c[i];
      for (m = 0; m < N; m++) {
	for (n = 0; n < N; n++) {
	  sptr->x[m][n] += res[m][n];
	}
      }
    }

    /* Not sure why the barrier is necessary, but couldn't get it to work without it */
    upc_barrier;
  }

  printf("THREAD %d: running for %2f seconds\n", MYTHREAD, (second() - sec));
  upc_barrier;
  printf("done.\n");
}

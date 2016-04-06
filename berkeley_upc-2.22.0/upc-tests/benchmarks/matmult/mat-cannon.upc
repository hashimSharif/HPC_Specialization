/**
 * 
 * UPC Matrix multiplication Example
 * 
 * Compute C (N,M) = C(N,M) + a(N, P) * b(P, M).
 * This algorithm uses Cannon's algorithm
 */

#include <config.h>
#include <math.h>

struct square_mat {
  elem_t x[N][N];
};

shared struct square_mat a [THREADS];
shared struct square_mat b [THREADS];
shared struct square_mat c [THREADS];

shared struct square_mat a_shift [THREADS];
shared struct square_mat b_shift [THREADS];

void init_matrix(shared struct square_mat* p) {
  
  int i,j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      p->x[i][j] = (MYTHREAD+1)*(2*i + j);
    }
  }
}

void matmult(shared struct square_mat* a, shared struct square_mat* b, struct square_mat* c) {

  int i,j,k;
  elem_t sum;
  for(i=0; i<N; i++) {
    for (j=0; j<N; j++) {
      sum = 0;
      for(k=0; k<N; k++) 
	sum +=a->x[i][k] * b->x[k][j];
      c->x[i][j] += sum;
    }
  }
}

struct square_mat tmp;
  
int main (int argc, char** argv) {

  int i,j,k,m,n;
  int dim;
  int ind;
  double sec;

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

  upc_barrier(0);

  sec = second();
  upc_memget(&tmp, &c[MYTHREAD], sizeof(tmp));
  
  /* do the skewing */
  dim = (int) sqrt(THREADS);
  for (i = 0; i < dim; i++) {
    upc_forall (j = 0; j < dim; j++; &a_shift[i*dim + j]) {
      ind = (j + i) % dim;
      a_shift[i*dim + j] = a[i*dim + ind];
    }
  }
  
  for (j = 0; j < dim; j++) {
    upc_forall(i = 0; i < dim; i++; &b_shift[i*dim + j]) {
      ind = (j + i) % dim;
      b_shift[i*dim + j] = b[ind * dim + j];
    }
  }

  upc_barrier;

  for (k = 0; k < dim; k++) {
    /* Now do the mult */
    for (i = 0; i < dim; i++) {
      upc_forall (j = 0; j < dim; j++; &c[i*dim + j]) {
	ind = i*dim + j;
	if (k % 2) {
	  matmult(&a[ind], &b[ind], &tmp);
	} else {
	  matmult(&a_shift[ind], &b_shift[ind], &tmp); 
	}
      }
    }

    /* now do the circular shifts */
    i = ind / dim;
    j = ind % dim;

    if (k % 2) {
      a_shift[ind] = a[i*dim + (j+1) % dim];
      b_shift[ind] = b[(ind + dim) % THREADS];
    } else {
      a[ind] = a_shift[i*dim + (j+1) % dim];
      b[ind] = b_shift[(ind + dim) % THREADS];
    }

    /* is a barrier necessary? */
    upc_barrier;
  } /* k */

  upc_memput(&c[MYTHREAD], &tmp, sizeof(tmp));
  upc_barrier;

  printf("THREAD %d: running for %2f seconds\n", MYTHREAD, (second() - sec));
  upc_barrier;
  printf("done.\n");
}


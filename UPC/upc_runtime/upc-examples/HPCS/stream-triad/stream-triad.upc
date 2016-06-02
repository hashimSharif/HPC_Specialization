/***
 *
 *  UPC Implementation of the HPC Challenge Stream-Triad Benchmark
 *
 *  Benchmark Specification:
 *
 *  The EP-Stream-Triad benchmark implements a simple vector operation
 *  that scales and adds two vectors:
 *  a = b + alpha * c
 *  where
 *  -- a, b, c and m-element double vectors, with the value of m as runtime input
 *  -- b and c are assigned random values
 *  -- The operation should be performed at least 10 
 */

#include "upc.h"
#include "stdio.h"
#include "stdlib.h"
#include <sys/time.h>

#define NITERS 10

shared double *a, *b, *c;

double min_time = 0;

double wctime() {

  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec + 1E-6 * tv.tv_usec);
}


void kernel(double alpha, int m_per_thread) {

  double start, end;
  double *la = (double *) &a[MYTHREAD];
  double *lb = (double *) &b[MYTHREAD];
  double *lc = (double *) &c[MYTHREAD];

  for (int i = 0; i < NITERS; i++) {
    upc_barrier;
    start = wctime();
    for (int j = 0; j < m_per_thread; j++) {
      la[j] = lb[j] + alpha * lc[j];
    }
    upc_barrier;
    end = wctime();
    if (!MYTHREAD) {
      if (min_time == 0 || end - start < min_time) {
	min_time = end - start;
      }
    }
  }
}

int main(int argc, char* argv[]) {

  double alpha;
  int m, m_per_thread;
  double *la, *lb, *lc;

  if (argc < 3) {
    if (!MYTHREAD) {
      fprintf(stderr, "usage:  ./stream-triad <num-elements> <alpha>\n");
    }
    upc_global_exit(-1);
  }
   
  m = (unsigned) atoi(argv[1]);
  alpha = strtod(argv[2], NULL);
  m_per_thread = m / THREADS + (m % THREADS ? 1 : 0);

  a = (shared double *) upc_all_alloc(THREADS, m_per_thread * sizeof(double));
  b = (shared double *) upc_all_alloc(THREADS, m_per_thread * sizeof(double));
  c = (shared double *) upc_all_alloc(THREADS, m_per_thread * sizeof(double));

  if (a == NULL || b == NULL || c == NULL) {
    if (!MYTHREAD) {
      fprintf(stderr, "could not allocate three arrays of %d doubles\n", m);
    }
    upc_global_exit(-1);
  }

  //initialize array
  lb = (double *) &b[MYTHREAD]; 
  lc = (double *) &c[MYTHREAD];
  for (int i = 0; i < m_per_thread; i++) {
    lb[i] = rand();
    lc[i] = rand();
  }

  upc_barrier;

  kernel(alpha, m_per_thread);

  if (!MYTHREAD) {
    double perf = (24 * ((double) m) / min_time) / 1E9;
    printf("Stream-Triad Performance: %d threads, %d element vector, best time = %.3f seconds ( %.3f Gbytes/second)\n", 
	   THREADS, m, min_time, perf);
    printf("done.\n");
  }

}  



#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
  int nthreads, tid;
  int x = 0;

  #pragma omp parallel private(nthreads, tid)
  {
    /* Obtain thread number */
    tid = omp_get_thread_num();
    printf("Hello World from thread = %d\n", tid);

    // /* Only master thread does this */
    if (tid == 0) 
      {
	nthreads = omp_get_num_threads();
	printf("Number of threads = %d\n", nthreads);
      }
  }

  return 0;
}

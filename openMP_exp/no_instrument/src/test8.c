// RUN: %libomp-compile-and-run

// Description: weak scaling example

#include <stdio.h>
#include <math.h>
#include <time.h>

/*! Utility function to spend some time in a loop */
static void do_some_work (void)
{
  int i;
  double sum = 0;
  for(i = 0; i < 1000; i++){
    sum += sqrt (i);
  }
}

int test_omp_parallel_for_private()
{

  #pragma omp parallel 
  {
    do_some_work ();  
  } /*end of for*/

  return 1;
} /* end of check_parallel_for_private */

int main()
{
  clock_t tic = clock();

  int i;
  int num_failed = 0;
  int reps = 100000;

  for(i = 0; i < reps; i++) {
    if(!test_omp_parallel_for_private()) {
      num_failed++;
    }
  }
 
  clock_t toc = clock();  
  printf("\n time elapsed : %d \n", toc - tic);

  return 0;
}


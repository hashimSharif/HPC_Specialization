// RUN: %libomp-compile-and-run

// Description: Strong scaling example

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
  int sum;
  int i;
  int i2;
  int known_sum;

  sum = 0;
  i2 = 0;
  int LOOPCOUNT = 1000000;

  #pragma omp parallel for reduction(+:sum) schedule(static,1) private(i) private(i2)
  for (i=1;i<=LOOPCOUNT;i++)
  {
    i2 = i;
    #pragma omp flush
    do_some_work ();
    #pragma omp flush
    sum = sum + i2;
  } /*end of for*/
  known_sum = (LOOPCOUNT * (LOOPCOUNT + 1)) / 2;
  return (known_sum == sum);
} /* end of check_parallel_for_private */

int main()
{
  clock_t tic = clock();
  int i;
  int num_failed = 0;
  int reps = 1000 ;

  for(i = 0; i < reps; i++) {
    if(!test_omp_parallel_for_private()) {
      num_failed++;
    }
  }

  clock_t toc = clock();  
  printf("\n time elapsed : %d \n", toc - tic);

  return num_failed;
}



// Strong scaling

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int test_omp_parallel_private()
{
  int sum, num_threads, sum1;
  int known_sum;
  sum = 0;
  num_threads = 0;

  #pragma omp parallel private(sum1)
  {
    int i;
    sum1 = 7;
    #pragma omp for 
    for (i = 1; i < 1000; i++) {
      sum1 = sum1 + i;
    }
    #pragma omp critical
    {
      sum = sum + sum1;
      num_threads++;
    }
  }

  known_sum = (999 * 1000) / 2 + 7 * num_threads;
  return (known_sum == sum);
}

int main()
{
  int i;
  int num_failed = 0;
  int REPETITIONS = 10000;

  for(i = 0; i < REPETITIONS; i++) {
    if(!test_omp_parallel_private()) {
      num_failed++;
    }
  }

  printf("\nNum of tests failed %d \n", num_failed);
  return num_failed;
}

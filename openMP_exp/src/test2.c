
// Strong scaling

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>


int test_omp_parallel_private()
{
  int sum, num_threads, sum1;
  int known_sum;
  sum = 0;
  num_threads = 0;
  int loopSize = 1000000;

  #pragma omp parallel private(sum1)
  {
    int i;
    sum1 = 7;
    #pragma omp for 
    for (i = 1; i < loopSize; i++) {
      sum1 = sum1 + i;
    }
    #pragma omp critical
    {
      sum = sum + sum1;
      num_threads++;
    }
  }

  known_sum = ((loopSize -1) * (loopSize)) / 2 + 7 * num_threads;
  return (known_sum == sum);
}

int main()
{

  struct timeval t1, t2;
  gettimeofday(&t1, NULL);

  //clock_t tic = clock();
  int i;
  int num_failed = 0;
  int REPETITIONS = 100000;

  for(i = 0; i < REPETITIONS; i++) {
    if(!test_omp_parallel_private()) {
      num_failed++;
    }
  }
 
  gettimeofday(&t2, NULL);
  double elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000;
  printf("elapsed time in ms %f ", elapsedTime);

  return 0;
}

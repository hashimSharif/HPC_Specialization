
// Strong scaling

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <time.h>
#include <ctime>

#define size 10000000

void parallel_func()
{  
  int i;
  int randomNumbers[size];
  srand(time(NULL));

  #pragma omp parallel for
  for(i = 0; i < size; i++){
    randomNumbers[i] = rand() % size;  
  }
}


int main()
{
  struct timeval t1, t2;
  gettimeofday(&t1, NULL);

  int reps = 100;
  for(int i = 0; i < reps; i++)
    parallel_func();

  gettimeofday(&t2, NULL);
  double elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000;
  printf("elapsed time in ms %f ", elapsedTime);
   
  return 0; 
}

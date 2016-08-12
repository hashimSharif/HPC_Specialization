
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define size 10000

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
  parallel_func();
  printf("\n\n\n Random Number generation completed\n\n\n");
  return 0; 
}

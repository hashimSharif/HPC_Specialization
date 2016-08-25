
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define size 100000

void parallel_func()
{  
  int i;
  int randomNumbers[size];
  srand(time(NULL));

  #pragma omp parallel for
  for(i = 0; i < size; i++){
    randomNumbers[i] = rand() % size;  
  }
   
  #pragma omp parallel for
  for(i = 0; i < size; i++){
    randomNumbers[i] = rand() % size;  
  }
   
  #pragma omp parallel for
  for(i = 0; i < size; i++){
    randomNumbers[i] = rand() % size;  
  }
}


int main()
{
  int reps = 10000;
  for(int i = 0; i < reps; i++)
    parallel_func();

  printf("\n\n\n Multiple paralel regions \n\n\n");
  return 0; 
}




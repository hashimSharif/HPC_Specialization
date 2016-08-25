
#include <stdio.h>
#include "mpi.h"
#include <omp.h>
#include <sys/time.h>


int main(int argc, char *argv[]) {

  for(int i = 0; i < 10000; i++){
 
    #pragma omp parallel default(shared)
    {
      printf("Hello from thread \n");  
    }
  }

  return 0;
}

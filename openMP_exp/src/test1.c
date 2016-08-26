
#include <stdio.h>
#include "mpi.h"
#include <omp.h>
#include <sys/time.h>


int main(int argc, char *argv[]) {
 
  int reps = 1000000;
  for(int i = 0; i < reps; i++){
 
    #pragma omp parallel default(shared)
    {
      int threadNo = omp_get_thread_num();
    }
  }

  return 0;
}

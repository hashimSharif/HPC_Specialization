
// Test for barrier overhead

#include <stdio.h>
#include "mpi.h"
#include <omp.h>
#include <unistd.h>
#include <sys/time.h>


int main(int argc, char *argv[]) {

   #pragma omp parallel default(shared)
  {
    printf("Hello from thread \n");
    sleep(1);  
  }
 
  return 0;
}

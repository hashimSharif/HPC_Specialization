
#include <stdio.h>
#include "mpi.h"
#include <omp.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int numprocs, rank, namelen;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &namelen);

  for(int i = 0; i < 100; i++){
 
    #pragma omp parallel default(shared)
    {
      printf("Hello from thread \n");  
    }

    sleep(1);
  }
 
  MPI_Finalize();
  return 0;
}

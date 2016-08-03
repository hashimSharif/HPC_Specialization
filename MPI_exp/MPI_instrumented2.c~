

#include <stdio.h>
#include "mpi.h"
#include <omp.h>
#include <sys/time.h>



double time_diff(struct timeval x , struct timeval y)
{
  double x_ms , y_ms , diff;
  x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
  y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;     
  diff = (double)y_ms - (double)x_ms;    
  return diff;
}

int main(int argc, char *argv[]) {

  int numprocs, rank, namelen;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int iam = 0, np = 1;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &namelen);

  //clock_t start, end;
  struct timeval before, after;
  gettimeofday(&before, NULL);
  //start = get_nanos();
  //printf("start %.5f ", start);
   
#pragma omp parallel default(shared) private(iam, np)
  {
    np = omp_get_num_threads();
    iam = omp_get_thread_num();
    printf("Hello from thread %d out of %d from process %d out of %d on %s\n",
           iam, np, rank, numprocs, processor_name);
  }
  
  gettimeofday(&after, NULL);
  //end = get_nanos();
  //printf("start %.5f ", end);  
  //printf("clocks %.15f ", (float) end - start);
  
  printf(" \n*********\n Total time elapsed : %.0lf us \n*******\n" , time_diff(before , after));

  MPI_Finalize();

}

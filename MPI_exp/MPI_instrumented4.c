

#include <stdio.h>
#include "mpi.h"
#include <omp.h>
#include <sys/time.h>

/* This module includes a function that is used to instrument
individual omp calls
*/

int count = 0;
struct timeval timeArr[20];

double time_diff(struct timeval x , struct timeval y)
{
  double x_ms , y_ms , diff;
  x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
  y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;     
  diff = (double)y_ms - (double)x_ms;    
  return diff;
}


void printTimeDiff(){
   
  for(int  i = 0; i < 10; i = i + 2){
    printf(" \n*********\n Total time elapsed : %.0lf us \n*******\n" , time_diff(timeArr[i] , timeArr[i+1])); 
  }
}


void addTime(){

  gettimeofday(&timeArr[count], NULL);
  count += 1; 
}


int main(int argc, char *argv[]) {

  int numprocs, rank, namelen;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int iam = 0, np = 1;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &namelen);

  //struct timeval before, after;
  //gettimeofday(&before, NULL);
     
  addTime();

#pragma omp parallel default(shared) private(iam, np)
  {
    np = omp_get_num_threads();
    iam = omp_get_thread_num();
    printf("Hello from thread %d out of %d from process %d out of %d on %s\n",
           iam, np, rank, numprocs, processor_name);
  }
  
  printTimeDiff();

  MPI_Finalize();
}

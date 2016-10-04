/*
A simple MPI example program using non-blocking send and receive
and MPI_Waitall to wait for completion of all message transfers.
The program consists of one processes (process 0) which sends a message
containing its identifier to N-1 other processes. These receive the
message and send it back.
Both processes use non-blocking send and receive operations
(MPI_Isend and MPI_Irecv, and MPI_Waitall to wait until the messages
have arrived).
Compile the program with 'mpicc send-nonblocking-waitall.c -o send-nonblocking-waitall'
Run the program with 'mpiexec -n 6 ./send-nonblocking-waitall'
*/

#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"
#define MAXPROC 2
#define BUFSIZE 10000

int LOOPCOUNT = 1000;

/* The placeholder Functions is added to mark the start and end of code regions that need to be moved */
__attribute__((noinline)) void placeHolder(){
  printf("placeHolder func %d \n", 10);
}


int main(int argc, char* argv[]) {
  int i, x, np, me;
  int tag = 42;
  int reps=500;

  MPI_Status status[MAXPROC];
  /* Request objects for non-blocking send and receive */
  MPI_Request send_req[MAXPROC], recv_req[MAXPROC];
  int y[MAXPROC];  /* Array to receive values in */
  int buffer[BUFSIZE];

  MPI_Init(&argc, &argv);                /* Initialize */
  MPI_Comm_size(MPI_COMM_WORLD, &np);    /* Get nr of processes */
  MPI_Comm_rank(MPI_COMM_WORLD, &me);    /* Get own identifier */
  double t1 = MPI_Wtime();               /* Get start time */
    
  for(int i_count = 0; i_count < reps; i_count++){
    /* First check that we have at least 2 and at most MAXPROC processes */
    if (np != 2) {
      if (me == 0) {
	printf("You have to use at lest 2 and at most %d processes\n", MAXPROC);
      }
      MPI_Finalize();
      exit(0);
    }
  
    x = me;   /* This is the value we send, the process id */

    if (me == 0) {    /* Process 0 does this */  
    
      printf("Process %d receiving from all other processes\n", me);
      /* Receive a message from all other processes */
      for (i=1; i < np; i++) {
	printf("Master posting Irecv for process %d\n", i);
	MPI_Irecv (&buffer, BUFSIZE, MPI_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &recv_req[i]);
      }
      /* While the messages are delivered, we could do computations here */

      /* Wait until all messages have been received */
      /* Requests and statuses start from index 1 */ 

      placeHolder();
      MPI_Waitall(np-1, &recv_req[1], &status[1]);
     
    } else { /* all other processes do this */
 
      printf("Process 1 sending to Process 0 \n");
      MPI_Isend (&buffer, BUFSIZE, MPI_INT, 0, tag, MPI_COMM_WORLD, &send_req[0]);
      /* Lots of computations here */

      placeHolder();
      MPI_Wait(&send_req[0], &status[0]);

      // OPENMP CODE
      placeHolder(); 
      int sum = 0;
#pragma omp parallel for reduction(+:sum) schedule(static,1) private(i)
      for (i=1; i<=LOOPCOUNT; i++)
	{
	  sum = sum + i;
	}  
    }
  }

  double t2 = MPI_Wtime();
  printf("elapsed time for rank %d is %f\n", me, t2 - t1);

  MPI_Finalize();
  exit(0);
}

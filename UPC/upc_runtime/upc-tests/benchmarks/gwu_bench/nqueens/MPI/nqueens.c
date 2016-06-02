/*
MPI nqueens
Copyright (C) 2000 Frederic Vroman, Sebastien Chauvin, Tarek El-Ghazawi

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <mpi.h>

#include "defs.h"
#include "gen.h"
#include "sched.h"


/* ITERATION_NUM: number of iterations of the N-Queens algorithm. Running
 * the algorithm several times allows to get a more accurate execution time.
 */
#define ITERATION_NUM 1.0

int main(int argc, char** argv)
{ 
  // MAtrix used to store parameters sended to each processes :
  // params[0] : 0 for bad passing arguments else 1.
  // params[1] : Problem size (Number of queens).
  // params[2] : level.
  // params[3] : method (METH_CHUNKING or METH_ROUND).
  // params[4] : The number of jobs
  int params[5] ;
  int i, p ;
  clock_t clk ;
  int myRank ;
  int nbThreads ;
  int nbSols ;
  int recvSols ;

  /* Due to current implementation of mask, sizeof(msk_t) has to be 8 bytes!
   */
  assert(sizeof(msk_t)==8);

  // Initialize mpi
  MPI_Init(&argc, &argv) ;
  
  // Retrieve the rank of the process and 
  // the number of processes
  MPI_Comm_rank( MPI_COMM_WORLD, &myRank);
  MPI_Comm_size( MPI_COMM_WORLD, &nbThreads);

  setbuf(stdout, NULL) ;

#ifdef DEBUG
  if(myRank == 0)
    {
      printf("Starting test...\n");
      printf("NbThreads = %d\n",nbThreads) ;
      for(i = 0; i < argc; i++)	     
	printf("argv[%d]:%s\n ",i ,argv[i]) ;
      printf("\n") ;
    }
#endif

  // Parse arguments
  if (myRank == 0)
  { 
    params[0] = 1 ;

    if ((argc!=2) && (argc!=4))
    { fprintf(stderr, "Usage: %s n [level job_distribution]\n", argv[0]);
      fprintf(stderr, "\tn                 chessboard edge size, 0 < n <=16\n"
                      "\tlevel             job distribution depth level\n"
                      "\tjob_distribution  one of `chunking' or `round_robin'\n");
      MPI_Finalize();
      exit(1);
    }
    else
      {
	// Scan Problem size argument
	params[1] = atoi(argv[1]) ;
	if ((params[1] <= 0) || (params[1] > 16))
	  { 
	    fprintf(stderr,"0< Queens Number <17\n") ;
	    params[0] = 0 ;
	  }
	
	if(argc==4)
	{
	  // Scan level argument
	  params[2] = atoi(argv[2]) ;
	  if ((params[2] < 0) || (params[2] >= params[1]))
	  { 
	    fprintf(stderr,"0<= level <n\n") ;
	    params[0] = 0 ;
	  }
	
	// Scan method argument
	if (!strcmp(argv[3], "chunking"))
	  params[3] = METH_CHUNKING ;
	else 
	  if (!strcmp(argv[3],"round_robin"))
	    params[3] = METH_ROUND ;
	  else 
	    { 
	      fprintf(stderr,"chunking or round_robin\n") ;
	      params[0] = 0 ;
	    }
	}
	else
	{	// Default parameters
		params[2]=2;
		params[3]=METH_ROUND;
	}

	// Calculate the number of jobs and determine if the problem 
	// will exceed the number of jobs allowed
	params[4] = 1 ;

	for(i = 0; i < params[2]; i++) 
	  params[4] *= params[1] ; 
	
	if (params[4] > MAX_JOBS) 
	  return -1 ;  
      }
    
    // Start the timer
    clock() ;

    for(i = 1; i < nbThreads; i++)
	MPI_Send(&params, 5, MPI_INT, i, 1, MPI_COMM_WORLD) ;
  }
  else
    {
      MPI_Recv(&params, 5, MPI_INT, 0, 1, MPI_COMM_WORLD, (MPI_Status *)NULL) ;
    }

  MPI_Barrier(MPI_COMM_WORLD) ;

  if (!params[0])
    { 
      MPI_Finalize() ;
      exit(1) ;
    }

  nbSols = 0 ;

  for(i = 0; i < ITERATION_NUM; i++)
  {
    if(myRank == 0)
      {
	nbSols += sched(params[1], params[2], params[3], params[4], nbThreads) ;

	for(p = 1; p < nbThreads; p++)
	  {
	    MPI_Recv(&recvSols, 1, MPI_INT, p, 2, MPI_COMM_WORLD, (MPI_Status *)NULL) ;
	    nbSols += recvSols ;
	  }
      }
    else
      {
	nbSols = sched(params[1], params[2], params[3], params[4], nbThreads) ;

	MPI_Send(&nbSols, 1, MPI_INT, 0, 2, MPI_COMM_WORLD) ;
      }

    MPI_Barrier(MPI_COMM_WORLD) ;
  }

  if (myRank == 0)
  { 
    clk = clock() ;

#ifdef DEBUG
    fprintf(stderr, "Solutions Calculated : %d\n", nbSols);
    fprintf(stderr, "Computation time:\n");
#endif
    printf(" %f\n", ((double)clk) / ((double)(CLOCKS_PER_SEC * ITERATION_NUM)));
    }

  MPI_Barrier(MPI_COMM_WORLD) ;
  MPI_Finalize() ;
  return 0;
}

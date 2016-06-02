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

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include "defs.h"
#include "gen.h"

/**
 * This function should be called by all process and then then will send their
 * Results to the main process (myRank = 0).
 *
 * nbQueens : number of queens.
 * level : Number of lines take in account to process the distribution of job among
 *         processes.
 * method :  METH_CHUNKING (chunking) or METH_ROUND (round_robin)
 * nbThreads : number of threads to solve the problem.
 **/

int sched(int nbQueens, int level, int method, int njobs, int nbThreads)
{ 
  int l, j, c ;
  int nsols = 0 ;
  sol_t solutions ;
  
  int job ;
  int valid ;
  msk_t msk ;
  msk_t colstk ;
  
  int myRank ;

  MPI_Comm_rank( MPI_COMM_WORLD, &myRank) ;

#ifdef DEBUG 
  if(myRank == 0)
    {
      printf("njobs = %d\n", njobs) ;
    }
#endif

  for(j = 0; j < njobs; j++)
  { 
    if(((method == METH_ROUND) && (j % nbThreads == myRank)) 
       || ((method == METH_CHUNKING) && ((j * nbThreads) / njobs) == myRank))
      {
	job = j ; 
	valid = 1 ;
	msk = 0 ; 
	colstk = 0 ;

#ifdef DEBUG0
	printf("Job %d assigned to thread %d\n", j, myRank) ;
#endif
	for(l = 0; l < level; l++)          // Unpack the job number
	  { 
	    c = job % nbQueens ;                    // Compute the col number
	    job /= nbQueens ;                     // Prepare for the next level
	    colstk <<= 4 ;
	    colstk |= c ;                  // Push the column
	    
	    // Check the validity of the queen position
	    if (msk & (BASECOLMSK << c))            
	      { 
		valid = 0 ;                  
		break ;
	      }
	    // Place the queen
	    msk |= BASECOLMSK << c ;
	    
	    // Compute the diagonals shifts
	    msk = (msk & CMASK) + ((msk & D1MASK) << 1) + ((msk & D2MASK) >> 1);
	  }
	if (valid)
	  {
	    // Start the seq algorithm
	    nsols += gen(colstk, l, msk, nbQueens, &solutions) ;
	  }
      }
  }
  return nsols;
}

/*
UPC Matrix multiplication
Copyright (C) 2000 Sebastien Chauvin, Tarek El-Ghazawi

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
// UPC Matrix multiplication Example
// a(N, P) is multiplied by b(P, M).  Result is stored in c(N, M)
// In this example, a is distributed by rows while b is distributed by columns.
// We do use the upc_forall construct in this example

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>


#if (!defined NUM_PROC) || (!defined ELEM_T) || (!defined N) || (!defined M) || (!defined P)
# error "NUM_PROC, ELEM_T, N, M and P should be defined!"
#endif

typedef ELEM_T elem_t;

elem_t a[N/NUM_PROC][P];
elem_t c[N/NUM_PROC][M];
  
elem_t b[P][M];

// Warning : P*M must be a multiple of MSG_SIZE 
#define MSG_SIZE 1024

double second()
{
    double secx;
    struct tms realbuf;

    times(&realbuf);
    secx = ( realbuf.tms_stime + realbuf.tms_utime ) / (float) CLK_TCK;
    return ((double) secx);
}

int main(int argc, char** argv) {

  int i,j,l;
//  int cnt;

  int rank, size;
  elem_t sum;
  double time0, time1;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (N % NUM_PROC)
  { printf("The number of lines (%d) must be a multiple of the number of processor (%d)\n", N, NUM_PROC);
  	MPI_Finalize();
    return 1;
  }

  if (size!=NUM_PROC)
  { printf("Please reconfigure for the valid number of processors (%d).\n", NUM_PROC);
  	MPI_Finalize();
    return 1;
  }

// Collective arrays initialization for a 

  for(i=0;i<N;i++)
    for(j=0;j<P;j++) 
      a[i][j]=(i*NUM_PROC+rank)*j+1;

  if (rank == 0)
  { for(i=0;i<P;i++)
      for(j=0;j<M;j++)
        b[i][j] = i * N +j + 3;
  }

  time0=second();      // Start of the bench

  for (i=0; i<P; i+=MSG_SIZE/M)
    MPI_Bcast(&b[i], MSG_SIZE, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  time1=second();      // Start of the bench

#ifdef DEBUG
  if (rank==0)
  { printf(">%f\n", time1-time0);
  }
#endif

  MPI_Barrier(MPI_COMM_WORLD);

  time0=second();      // Start of the bench

// all threads  perform matrix multiplication


  for(i=0;i<N/NUM_PROC;i++)
  // &a[i][0] specifies that this iteration will be 
  // executed by the thread that has affinity to element a[i][0]
  // This thread will have the affinity with the whole line

         for (j=0; j<M; j++) {
           sum = 0;
           for(l=0; l< P; l++) 
             sum +=a[i][l]*b[l][j];
           c[i][j] = sum;
         }


   MPI_Barrier(MPI_COMM_WORLD);

  time1=second();      // Start of the bench

  if (rank==0)
  { printf("%f\n", time1-time0);
  }

//  Every thread print its own part of the matrix

#if 0
  { printf("\n\n");
    for(i=0;i<N;i++)
    { if (i%NUM_PROC==rank)
        for(j=0;j<M;j++)
          printf("c[%d][%d]=%lf\n",i,j,c[i/NUM_PROC][j]);
      fflush(stdout);
      MPI_Barrier(MPI_COMM_WORLD);
    }
  }
#endif
 MPI_Finalize();
}

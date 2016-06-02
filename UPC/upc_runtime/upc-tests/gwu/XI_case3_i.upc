/*
UPC Testing Suite

Copyright (C) 2000 Chen Jianxun, Sebastien Chauvin, Tarek El-Ghazawi

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
/**
   Test: XI_case3_i - upc_local_alloc
   Purpose: Check the dynamic memory allocation functions
   Type: Positive.
   How : - every thread allocate memory with upc_local_alloc
         - Check the affinity
         - All the thread initialize the buffers (in an interleaved fashion)
         - All the thread read all the allocated memory
*/

#include <stdio.h>
#include <errno.h>
#include <upc_relaxed.h>

#define SIZE 100000

shared [] int *shared sp[THREADS];  // shared pointer used to broadcast 
                                 // the result of the allocation
int main()
{
  int i,j;
  int pe=MYTHREAD;
  int errflag=0;

#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
  sp[MYTHREAD] = upc_alloc(SIZE * sizeof(int));
#else
  sp[MYTHREAD] = upc_local_alloc(SIZE, sizeof(int));
#endif

  upc_barrier 1;

  // Initialize the memory using only remote accesses

  if (!MYTHREAD) {
    for(i=0; i<THREADS; i++)
      if (upc_threadof(sp[i])!=i) errflag |= 1;
  }

  for (i=0; i< THREADS; i++)
    upc_forall(j=0; j< SIZE; j++; j+1)
      sp[i][j] = j*3;

  upc_barrier 2;

  // Read back the memory using different remote accesses

  for (i=0; i< THREADS; i++)
  {
    upc_forall(j=0; j< SIZE; j++; j+2)
      if (sp[i][j] != j*3) {
        printf("%d,%d = %d\n", i,j, sp[i][j]);
        errflag |= 2;
      }
  }

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);   
}

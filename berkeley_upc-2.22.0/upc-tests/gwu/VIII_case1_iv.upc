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
   Test: VIII_case1_iv   - forall test(Null)
   Purpose: To check that all threads execute all the iterations
   Type: Positive.
   How : - Declare a 2D array, a[N][THREADS], of integers of size N*THREADS.
           N is the number of iterations that will be used to test the forall. 
           This array will be automatically initialized to 0.
         - In the forall statement, every thread sets a[i][MYTHREAD] to 1,
           where i is  the current iteration.
         - At the end of the forall loop, check that every entry in this 2D 
           matrix is equal to 1.
*/


#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define N 100

shared int a[N][THREADS];

int
main()
{
  int i,j,pe=MYTHREAD;
  int sum=0;
  int errflag=0;

  upc_forall(i=0; i<N; i++; )
    a[i][pe]=1;

  upc_barrier;

  for (i=0; i<N; i++)
    for( j=0; j<THREADS; j++)
      sum+=a[i][j];
      
  if (sum!=N*THREADS){
      errflag=1;
      printf("Failure: on Thread %d with sum %d\n",MYTHREAD,sum);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}



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
   Test: VIII_case2_i   - Continue in the body of a forall
   Purpose: To check that a thread can skip its current iteration.
   Type: Positive.
   How : - In the body of the loop, put a condition that, when satisfied, 
           the thread should skip that iteration.
         - At the end of the loop, check if the iterations have been actually 
           skipped.
*/


#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define N 100

shared int a[N][THREADS];

int main()
{
  int i,j,pe=MYTHREAD;
  int errflag=0;
  
  upc_forall(i=0; i<N; i++; i%THREADS) {
    if (a[i][pe]==0) continue;
    a[i][pe]=1;
  }
  
  for(i=0; i<N;  i++)
     for (j=0; j<THREADS; j++)
        if (a[i][j]!=0) errflag=1;

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}

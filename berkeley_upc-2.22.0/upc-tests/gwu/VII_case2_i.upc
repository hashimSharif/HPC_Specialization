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
   Test: VII_case2_i   - Barrier test with an expression which contains 
                         shared references (same expression). 
   Purpose: To check that no thread can proceed after the barrier until 
         all the other threads have reached the statement as well. 
   Type: Positive.
   How : - Declare a shared array,i a, of integers of size THREADS. This array 
           will be automatically initialized to 0.
         - Just before reaching the barrier, each thread will set a[MYTHREAD] 
           to 1.
         - Just after the barrier, every thread computes the sum of the entries
           in the array. It should be equal to THREADS. Otherwise, the barrier
           statement is  not working properly.
*/

#include <stdio.h>
#include <errno.h>
#include <upc.h>

shared int a[THREADS];
shared int x; 

int
main()
{
  int i,pe=MYTHREAD;
  int sum;
  int errflag=0;

  if (pe==0) x=6;
  upc_barrier 1;

  a[pe]=1;
  upc_barrier x;

  sum=0;
  for(i=0; i<THREADS; i++)
    sum+=a[i];

  if (sum!=THREADS)
    errflag=1;

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}
 
  

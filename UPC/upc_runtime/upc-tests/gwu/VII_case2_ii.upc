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
   Test: VII_case2_ii  - upc_notify with an expression contains shared 
                         references (same expression).
   Purpose: to check that no thread may proceed from the upc_wait until
            after all other threads have issued their upc_notify
            statements.
   Type: Positive.
   How : - Declare a shared array, a, of integers of size THREADS.
           This array will be automatically initialized to 0.
         - Just before reaching the notify statement, each thread will set
           a[MYTHREAD] to 1.
         - Right after the wait statement, every thread should check that
           a is filled with ones. Otherwise, the barrier statement is not
           working properly.
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
  upc_notify x+1;

  if (a[pe]!=1) {
    errflag=1;
  }

  upc_wait x+1;
  
  sum=0;
  for(i=0; i<THREADS; i++)
    sum+=a[i];

  if (sum!=THREADS) {
    errflag |= 2;
  }

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}
 
  

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
   Test: VI_case1_i - Global Strict memory consistency
   Purpose:
         To check that program execution is conducted in a sequential order
         manner that is seen by all threads.
   Type: Positive.
   How : - Include upc_strict.h in the test program.
         - In a for loop, thread 0 will be assigning the index of the loop
           to a first variable, x, and the index+1 to another variable, y, 
           in that order. Other threads will be computing y-x. If, in any 
           iteration, y-x>1, then the strict consistency model is not 
           working properly. An error message should be issued.
*/

#include <stdio.h>
#include <errno.h>
#include <upc_strict.h>

#define COUNT 100000

shared int x,y;

int main()
{
  int i,pe=MYTHREAD;
  int errflag;
  
  errflag=0;
  upc_barrier 1;

  if (pe==0)
    for(i=0; i<COUNT; i++){
      x=i;
      y=i+1;
    }
  else
    for(i=0; i<COUNT; i++) {
      int ly = y;
      int lx = x;
      if (ly-lx>1) {
        errflag=1;
        #ifdef VERBOSE1
          printf("%d: Consistency error for i=%d, lx=%i ly=%i\n",pe,i,lx,ly);
        #endif
      }
   }
  upc_barrier 2;

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}


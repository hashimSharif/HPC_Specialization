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
   Test: V_case2_i   - Assignment of private data to shared data.
   Purpose:
         To check assignment of private data to shared data.
   Type: Positive.
   How : - Define a shared integer and a local integer variable.
         - Each thread assigns MYTHREAD to the local integer.
         - Sequentially, each thread assign its local integer to the shared
           integer and the others threads check the value of the shared integer
*/

#include <stdio.h>
#include <errno.h>
#include <upc.h>

shared int k;

int main()
{ 
  int i;
  int x,pe=MYTHREAD;
  int errflag=0;

  for (i = 0; i < THREADS; i ++ ) {
    if (pe == i) {
      // local assignment 
      x = MYTHREAD;
      // assign local to shared
      k = x;
    }
    upc_barrier;
    if (k != i)
       errflag = 1;
    upc_barrier;
  }

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}

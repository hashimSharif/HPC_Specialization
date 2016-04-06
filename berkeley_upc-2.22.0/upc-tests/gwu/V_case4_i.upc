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
   Test: V_case4_i   - Assignment of shared pointers to private pointers.
   Purpose: To check the assignment of shared pointers to private ones.
   Type: Positive.
   How : - Define a shared integer data, a shared pointer and a private 
           pointer to integer.
         - Thread 0 assign the shared data a defined value.
         - Place a barrier. 
         - All threads assign the shared pointer to their private pointers;
         - The thread 0  should see the same value through their private pointers. 
*/

#define CONST 100
 
#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define CONST 100

shared int x;
int *pptr;
shared int *sptr;

int
main()
{
  int pe=MYTHREAD;
  int errflag=0;

  if (pe==0) x=CONST;
  upc_barrier;

  sptr=&x;

  if (MYTHREAD==upc_threadof(sptr))    
    pptr=(int *)sptr;

  upc_barrier;

  if (pe==0) {
    if (*pptr!=CONST)
      errflag=1;
  }

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}

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
   Test: II_case1_i  - Set shared pointer to point to shared scalar
   Purpose: To check that such a declaration will result in a pointer
         variable and a scalar that both have affinity to thread 0
         and that these two variables are accessible to all threads. 
   Type: Positive
   How : -  Declare a shared pointer to  a shared scalar(for example,
            an integer, through shared int *ptr).
         -  Thread 0 sets the shared variable to a predefined value. 
         -  Place a barrier.
         -  Assigns its address to the shared pointer.
         -  All threads should see the same values of the pointer and 
            the variable pointed to.
         -  Check that upc_threadof will return 0 for both 
            the shared pointer and the shared variable.
*/
    
#define MARK 100

#include <stdio.h>
#include <upc.h>
#include <errno.h>

shared int x;
shared int *ptr;

int main()
{
  int i,pe=MYTHREAD;  
  int errflag=0;
 
  if (pe==0)  x=MARK; 
  upc_barrier 1;

  ptr=&x;
  if ((*ptr!=MARK)||(x!=MARK))
    errflag=1;

  if ((upc_threadof(ptr)!=0) || (upc_threadof(&x)!=0)) 
    errflag=1;

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }
 
  return errflag;
}


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
   Test: II_case2_i - Set shared pointer to point to shared array
   Purpose:
         To check that such a declaration will result in a pointer
         variable that has affinity to thread 0. This pointer should
         be pointing to a shared array. Also, we should check that
         this pointer is accessible to all threads.
   Type: Positive
   How : - Declare a shared pointer.
         - Assigns to the shared pointer the base address of the shared 
           array in every thread.
         - Thread 0 initializes the array to some predefined value.
         - Place a barrier.
         - All the threads should see the same values of the pointer and 
           the array elements.
*/ 
    
#define COUNT 10

#include <stdio.h>
#include <upc.h>
#include <errno.h>

shared int x[COUNT*THREADS];
shared int *ptr;

int main()
{
  int i,pe=MYTHREAD;  
  int errflag=0;

  //
  // Set ptr pointed the base address of shared array by all threads.
  //
  ptr=x;  // equivalent to &x[0]
  
  //
  // Thread 0 assigned the arr elements some value through the pointer.
  //
  if (pe==0){
    for (i=0; i<COUNT*THREADS; i++)
      ptr[i]=i*10;
  }
  upc_barrier 1;
  //
  // All threads should see the elements of array by the pointer
  //
  for (i=0; i<COUNT*THREADS; i++)
    if (ptr[i]!=i*10) errflag=1;
  
  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }
  return(errflag);
}


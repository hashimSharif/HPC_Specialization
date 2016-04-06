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
   Test: II_case3_i  - Set shared pointer to point to shared structure
   Purpose:
         To check that such a declaration will result in a pointer to
         a structure variable. Both the pointer and the variable should
         have affinity to thread 0. This pointer can point to the 
         shared structure variable. 
   Type: Positive.
   How : - Declare a private pointer to a shared structure.
           (for example a struct of two integers, through: shared struct
           foo * ptr)
         - Assigns to the shared pointer the address of the structure variable
           by all threads.
         - Thread 0 initializes its fields to some  predefined values. 
         - Place a barrier.
         - All threads should see the same values of the pointer,
           through upc_addrfield(ptr), and the same value for the struct
           variable members.
*/

#include <stdio.h>
#include <upc.h>
#include <errno.h>

shared struct foo{
  int x;
  int y;
} sdata;
shared struct foo *ptr;

int main(int argc, char** argv)
{
  int i,pe=MYTHREAD; 
  int errflag; 
   
  //
  // Assign to the shared pointer the address of struct.
  //
  ptr=&sdata;
  upc_barrier 1;
  
  //
  // Thread 0 initializes the structure variable fields to some value,
  // through pointer.
  // 
  if (pe==0) {
    ptr->x=10;
    ptr->y=20;
  }
  upc_barrier 2;
  
  // 
  // check if all thread can accessed the shared struct by the pointer
  //
  errflag=0; 
  if ((ptr->x!=10)||(ptr->y!=20))
    errflag=1;
  upc_barrier 3;

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}


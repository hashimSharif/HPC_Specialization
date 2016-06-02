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
   Test: II_case3_ii  - Set shared pointer to point to non-shared structures 
   Purpose: To test shared pointers pointing to non-shared structures. 
   Type: Negative-Compilation error
   How : - Declare a shared pointer that points to a non shared structure.
         - Assign to the shared pointer the address of the non 
           shared structure variable.
         - Thread 0 initializes the fields to some predefined value.
*/

#include <stdio.h>
#include <upc.h>
#include <errno.h>

struct foo{
  int x;
  int y;
} sdata;

shared struct foo *ptr;

int main()
{
  int i,pe=MYTHREAD;  
  int errflag;
   
  ptr=&sdata;  // here should be a compilation error
  upc_barrier 1;
 
  if (pe==0) { 
    ptr->x=10;
    ptr->y=20;
  }
  upc_barrier 2;
  
  errflag=0;
  #ifdef VERBOSE0
    printf("The test is OK!\n");
  #endif 
  return(errflag);
}


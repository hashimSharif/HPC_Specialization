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
   Test: II_case2_ii  -- Set shared pointer to point to non-shared array
   Purpose: To check shared pointers can not point to non-shared array.
   Type: Negative-Compilation error. 
   How : - Declare a non-shared array, x and a shared pointer ptr.
         - In thread 0, make the shared pointer point to array x. 
*/

#define BLOCK 5
#define COUNT 10

#include <stdio.h>
#include <upc.h>
#include <errno.h>

int x[COUNT];
shared int *ptr;

int main()
{
  int i,pe=MYTHREAD;  
  int errflag=0;

//
// Make ptr pointed the private array x[...]
// 
  ptr=(shared void *)x;  // here should be a compilation error.

  if (pe==0) {
    for (i=0; i<COUNT; i++)
      ptr[i]=i*(pe+1);
  }
  upc_barrier 1;
  
  if (pe==0) {
    for (i=0; i<COUNT; i++)
      if (ptr[i]!=i) errflag=1;
  }
  
  #ifdef VERBOSE0
    if (errflag==1)
      printf("Err in test\n");
    else
      printf("The test is OK!\n");
  #endif
  return(errflag);
}


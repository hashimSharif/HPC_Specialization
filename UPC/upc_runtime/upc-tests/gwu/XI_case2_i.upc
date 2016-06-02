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
   Test: XI_case2_i - upc_all_alloc
   Purpose: Check the dynamic memory allocation functions
   Type: Positive.
   How : - every thread allocate memory with upc_all_alloc
         - All the thread initialize the buffer (in an interleaved fashion)
         - All the thread read all the allocated memory
*/

#include <stdio.h>
#include <errno.h>
#include <upc_relaxed.h>

#define SIZE 100000

shared int *shared sp;  // shared pointer used to broadcast 
                        // the result of the allocation
int main()
{
  int i,j;
  int pe=MYTHREAD;
  int errflag=0;

  sp = upc_all_alloc(SIZE, sizeof(int));

  upc_barrier 1;

  // Initialize the memory using only remote accesses

  upc_forall(j=0; j< SIZE; j++; j+1)
    sp[j] = j*3;

  upc_barrier 2;

  // Read back the memory using different remote accesses

  upc_forall(j=0; j< SIZE; j++; j+2)
    if (sp[j] != j*3) {
      errflag = 1;
    }

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);   
}



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
   Test: V_case4_ii   - Assignment of blocked shared pointers to 
                        private pointers.
   Purpose:
         To check the assignment of blocked shared pointers to 
         private pointers.
   Type: Positive.
   How : - Define a blocked shared pointer and a blocked shared array with the
           same blocking factor.
         - Define a private pointer. 
         - All threads assign the blocked shared pointer to an element of 
           the blocked array a.
         - Assign the blocked shared pointer to private pointer. 
*/

#define BLOCK 8
 
#include <stdio.h>
#include <errno.h>
#include <upc.h>

int *pptr;

shared [BLOCK] int a[BLOCK*THREADS];
shared [BLOCK] int *sptr;

int main()
{
  int i,pe=MYTHREAD;
  int errflag=0;

  sptr=a;

  if (pe==0) {
    for (i=0; i<BLOCK*THREADS; i++){
      sptr[i]=i;
    }
  }
  upc_barrier;

  pptr=(int *)&sptr[MYTHREAD*BLOCK];

  for(i=0; i<BLOCK; i++){
    if (pptr[i]!=pe*BLOCK+i) errflag=1;
  }

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}

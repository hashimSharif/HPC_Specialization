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
   Test: IV_case1_i -- Pointers arithmetic for arrays with default
                         blocking
   Purpose: To check that the pointers to shared objects move in the proper
         manner across all thread memories. 
   Type: Positive.
   How : - Declare a pointer to a shared array of integers, and two private 
           pointer point to integer.
         - Increment the pointer by a certain value, i.
         - Check that the thread that has this pointer, is actually
           the one given by the formula:
              upc_threadof(ptr+i)==(upc_threadof(ptr)+i)%THREADS;
         - Also check that the virtual address satisfies:
           upc_addrfield(ptr+i)
           = upc_addrfield(ptr)+(upc_threadof(ptr)+i)/THREADS*sizeof(*ptr).
         - Two private shared pointer pS1,pS2 point to the two element of the 
           array respectively, and upc_addrfield(pS1)>upc_addrfield(pS2), pS1
           pS2 are point to elements of the same array and they both have affinity
           to the thread on which pL1 and pL2 are defined.
         - Make the shared pointer arithmetic, pL1=pS1, pL2=pS2.
         - Check that:
             upc_addrfield(pS2)-upc_field(pS1)=(pL2-pL1)*sizeof(*pL1);  
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <upc.h>

#define COUNT 20

shared int x[COUNT*THREADS];
shared int *ptr;
shared int *pS1,*pS2;
int *pL1, *pL2;

int
main()
{
  int i,j,k,pe=MYTHREAD;
  int errflag=0;

  i=25;
  ptr=x;

  if (upc_threadof(ptr+i)!=(upc_threadof(ptr)+i)%THREADS)
    errflag=1;

  if (upc_addrfield(ptr+i) != upc_addrfield(ptr)+
        (upc_threadof(ptr)+i)/THREADS*sizeof(*ptr))
    errflag=2;

  for(k=0; (k<COUNT)&&(!errflag); k++){
     // the i-th element and j-th element in a thread
    i=rand()%COUNT; j=rand()%COUNT;
    if (i>j) {
      int t;
      t=j; j=i; i=t;
    } 
    pS1=&x[pe+i*THREADS]; // point to i-th element in the thread
    pS2=&x[pe+j*THREADS]; // point to j-th element in the same thread
    pL1=(int *)pS1;
    pL2=(int *) pS2;
    if ((upc_addrfield(pS2)-upc_addrfield(pS1))!=(pL2-pL1)*sizeof(*pL1))
      errflag=1;
  }

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}
  

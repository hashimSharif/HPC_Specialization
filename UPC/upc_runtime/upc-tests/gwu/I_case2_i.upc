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
   Test: I_case2_i -- Declaration of shared arrays without blocking.
   Purpose: To check that shared array elements are 
         distributed by default across all the threads in a round robin 
         fashion.
   Type: Positive.
   How : - Declare a shared array of integers, check that element i
           has affinity to thread i%THREADS. 
*/


#include <stdio.h>
#include <upc.h>
#include <errno.h>
 

#define COUNT 8
shared int x[COUNT*THREADS];

int main()
{
   int i, pe=MYTHREAD;
   int errflag=0;

   if (pe==0){
     for(i=0; i<COUNT*THREADS; i++) {
       if (upc_threadof(&x[i])!=(i%THREADS)){
         errflag=1;
#ifdef VERBOSE0
         printf("Error!--The array element x[%d] is not in thread %d\n",i,i%THREADS);
#endif
       }
     } 

     if (errflag==0) 
       printf("Success: The elements of the shared array are distributed in a round robin fashion.\n");
     else 
       printf("Failure: The elements of the shared array are not distributed in a round robin fashion.\n");

   }
  
   upc_barrier 1;
   return(errflag);
} 


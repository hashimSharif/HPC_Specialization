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
   Test: I_case2_ii -- Declaration of shared arrays with blocking.
   Purpose: To check that the elements of the blocked shared array
         are distributed across all the threads by chunks of the 
         specified size (blocking factor). 
   Type: Positive.
   How : - declare a shared array of integers by chunks of the 
           specified size (BLOCK), check that element i
           has affinity to thread (i/BLOCK)%THREADS.
*/

#include <stdio.h>
#include <upc.h>
#include <errno.h>
 
#define BLOCK 5
#define COUNT 8

shared [BLOCK] int x[COUNT*THREADS];

int
main()
{
   int i, pe=MYTHREAD;
   int errflag=0;

   if (pe==0) {
#ifdef VERBOSE0
     printf("-------------- BLOCK size is:%d --------------------\n",BLOCK);
     printf("---- Element     Thread    Phase        Addrfield ----\n");
#endif 
     for(i=0; i<COUNT*THREADS; i++)
       if (upc_threadof(&x[i])==((i/BLOCK)%THREADS)) {
#ifdef VERBOSE0
          printf("      x[%3d] %10ld %8ld      %12ld \n",i,upc_threadof(&x[i]),
                 upc_phaseof(&x[i]),upc_addrfield(&x[i]));
#endif
       }
       else {
         errflag=1;
         printf("Failure: The array element x[%d] is not in thread %d\n",i,i%THREADS);
       }
     if (errflag == 0) {
	 printf("Success: proper distribution of block cyclic array\n");
     }
   } // end if
   upc_barrier 1;
   return(errflag); 
} 


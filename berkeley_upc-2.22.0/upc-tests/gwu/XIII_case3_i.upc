/*
UPC Testing Suite

Copyright (C) 2000 Sebastien Chauvin

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
/*
   Test: XIII_case3_i - Private to shared string copy
   Purpose: Test the upc_memput functionalities
   Type: Positive.
   How : - For each thread do the following:
         -   Initialize a private array
         -   Copy the private array to a shared array
	 -   Compare the two arrays
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <upc_relaxed.h>

#define SIZE 100000

#define VERBOSE0

#define MAX_THREADS 100

shared [] int dst[SIZE];
int src[SIZE];

int main()
{
    int i, j;
    int thr_errflag[MAX_THREADS] = {0};
    int errflag=0;

    if (THREADS>MAX_THREADS)
    { if(!MYTHREAD) printf("Too many threads.\n");
      exit(-1);
    }
     
    // Initialize private arrays (src)
    for(i=0; i<SIZE; i++) src[i]=i;
	
    // Each thread will `memput' its own src array in the shared dst array;
    // then thread 0 will check consistency of dst

    for(i=0; i<THREADS; i++)
    {
      // Initialize shared array (dst)
      if (!MYTHREAD) for(j=0; j<SIZE; j++) dst[j]=0;
	  upc_barrier 1;

      if (MYTHREAD==i)
      {
#ifdef VERBOSE1
		// We still can't display shared pointers using libc's printf
//		printf("<shared-%%p> to <shared-%%p> (%d)\n", src, dst[(MYTHREAD+1)%THREADS], SIZE*sizeof(int));
		printf("upc_memput from 0x%0lx to 0x%0lx (size=%d)\n", src,
		        upc_addrfield(dst), SIZE*sizeof(int));
#endif 
         upc_memput(dst, src, SIZE*sizeof(int));
      }
	
      upc_barrier 2;
    
      if (MYTHREAD==0)
      {
        for(j=0; j<SIZE; j++)
	    if (dst[j]!=src[j]) {
		thr_errflag[i] += 1;
	    }
      }
    }

    errflag = thr_errflag[MYTHREAD];
    if (errflag) {
	printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
    } else if (MYTHREAD == 0) {
	printf("Success: on Thread %d \n",MYTHREAD);
    }
    
    return(errflag);
}

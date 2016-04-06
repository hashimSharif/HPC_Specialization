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
   Test: XIII_case1_i - Shared to shared string copy
   Purpose: Test the upc_memcpy functionality
   Type: Positive.
   How : - Initialize a shared array
         - Copy the shared array to another shared array
	 - Compare the two arrays
*/

#include <stdio.h>
#include <errno.h>
#include <upc_relaxed.h>

#define SIZE 100000

shared [] int src[SIZE];
shared [] int* shared dst[THREADS];

int main()
{
    int i;
    int errflag=0;
    char fmt[10];
 
    if (!MYTHREAD) 
	for(i=0; i<SIZE; i++)
	    src[i] = i;
  
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
    dst[MYTHREAD] = (shared [] int*)upc_alloc(SIZE*sizeof(int));
#else
    dst[MYTHREAD] = (shared [] int*)upc_local_alloc(SIZE,sizeof(int));
#endif
  
    upc_barrier;

    // Each thread order a copy from thread 0 to its neighbour

#ifdef VERBOSE1
	// We still can't display shared pointers using libc's printf
//	printf("<shared-%%p> to <shared-%%p> (%d)\n", src, dst[(MYTHREAD+1)%THREADS], SIZE*sizeof(int));
	printf("0x%0lx to 0x%0lx (%d)\n", upc_addrfield(src),
	        upc_addrfield(&dst[(MYTHREAD+1)%THREADS]), SIZE*sizeof(int));
#endif 

    upc_memcpy(dst[(MYTHREAD+1)%THREADS], src, SIZE*sizeof(int));

    upc_barrier;
    
    for(i=0; i<SIZE; i++)
	if (dst[MYTHREAD][i]!=src[i]) {
	    errflag = 1;
#ifdef VERBOSE1
	    printf("Error at (Thr:%d,Elmt:%d)=%d(instead of %d)\n", 
		   MYTHREAD, i, dst[MYTHREAD][i], src[i]);
#endif
	    break;
	}
  
    upc_barrier;
    
    if (errflag) {
	printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
    } else if (MYTHREAD == 0) {
	printf("Success: on Thread %d \n",MYTHREAD);
    }

    return(errflag);   
}

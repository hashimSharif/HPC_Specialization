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
   Test: XIII_case2_i - Shared to private string copy
   Purpose: Test the upc_memget functionality
   Type: Positive.
   How : - Initialize a shared array
         - Copy the shared array to private array
	 - Compare the two arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <upc_relaxed.h>

#define SIZE 100000


shared [] int src[SIZE];
int* dst;

int main()
{
    int i;
    int errflag=0;
 
    if (!MYTHREAD) 
	for(i=0; i<SIZE; i++)
	    src[i] = i;
  
    dst = (int*)malloc(SIZE*sizeof(int));
  
    upc_barrier;

    // Each thread order a copy from thread 0 to its neighbor

#ifdef VERBOSE1
	// We still can't display shared pointers using libc's printf
//	printf("<shared-%%p> to <shared-%%p> (%d)\n", src, dst[(MYTHREAD+1)%THREADS], SIZE*sizeof(int));
	printf("0x%0lx to 0x%0lx (%d)\n", upc_addrfield(src), dst, SIZE*sizeof(int));
#endif 

    upc_memget(dst, src, SIZE*sizeof(int));
  
    upc_barrier;
    
    for(i=0; i<SIZE; i++)
	if (dst[i]!=src[i]) {
	    errflag = 1;
#ifdef VERBOSE1
	    printf("Error at (Thr:%d,Elmt:%d)=%d(instead of %d)\n", 
		   MYTHREAD, i, dst[i], src[i]);
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

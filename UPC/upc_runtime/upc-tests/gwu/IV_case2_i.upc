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
   Test: IV_case2_i -- Pointers arithmetic for blocked pointers
   Purpose: To check that pointers to blocked shared objects move in 
            the proper manner across all threads memories.
   Type: Positive.
   How : - Declare a blocked pointer to a shared array of integer.
         - Increment the pointer by a certain value, i.
         - Check that the thread that has this pointer, is actually
           the one given by this formula:
             upc_threadof(ptr+i)=
             ( upc_threadof(ptr)+(upc_phaseof(ptr)+i)/BLOCK )%THREADS;
         - Also check that the phase satisfies:
             upc_phaseof(ptr+i)=(upc_phaseof(ptr)+i)%BLOCK;
         - Check that:
             upc_addrfield(pS2)-upc_addrfield(pS1)=(pL2-pL1)*sizeof(*pL1);
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define BLOCK 8
#define COUNT BLOCK 

shared[BLOCK] int x[2*COUNT*THREADS];
shared[BLOCK] int * ptr;

int test_ptr(shared[BLOCK] int* ptr, int ptr_index, int i)
{
    int errflag = 0;
    shared [BLOCK] int *p1, *p2;
    int *pp1, *pp2;


	/*** upc_threadof() ***/

    if (upc_threadof(ptr+i)!=(upc_threadof(ptr)+((upc_phaseof(ptr)+i)/BLOCK))%THREADS)
	{
#ifdef VERBOSE1
		printf("Problem in the thread number.\n");
#endif
		errflag=1;
    } 
    

	/*** upc_phaseof() ***/
	
    if (upc_phaseof(ptr+i) != ((upc_phaseof(ptr)+i)%BLOCK)) {
#ifdef VERBOSE1
		printf("Problem in the phase.\n");
#endif
		errflag=2;
    } 


	/*** upc_addrfield() test ***/
	
	/* the following test would succeed if and only if the data pointed to by
	 * both p1 and p2 has affinity to the same thread; therefore, we just skip
	 * this thread when data pointed to by p1 and p2 doesn't have affinity to
	 * the same thread.
	 */
    /* DOB: cast-to-local only has well-defined result with affinity */
	if (upc_threadof(ptr) == MYTHREAD && upc_threadof(ptr+i) == MYTHREAD)
	{
	    p1 = ptr;
	    p2 = ptr+i;
	    pp1 = (int*) p1;
	    pp2 = (int*) p2;

	    if (  (upc_addrfield(p2) - upc_addrfield(p1)) !=
		      (((size_t)(pp2-pp1)) * sizeof(*pp1)))
		{
#ifdef VERBOSE1
			printf("Problem in the addrfield.\n");
#endif
			errflag=3;
	    }
	}

    return errflag;
}

int main()
{
	int i, j;
	int errflag=0;

	/*
	 * Test upc_threadof() and upc_phaseof().
	 */
	for (i=0; i<COUNT*THREADS; i++) // test 10 times for random ptr
	{
		ptr=&x[i];    // ptr point the any position of the array
		for(j=0; j<BLOCK; j++)
		errflag |= test_ptr(ptr, i, j);
	}
	
	if (errflag) {
	    printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
	} else if (MYTHREAD == 0) {
	    printf("Success: on Thread %d \n",MYTHREAD);
	}

	return(errflag);
}

/* vi: ts=4:ai
 */

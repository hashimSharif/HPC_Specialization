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
/**
   Test: XIII_case4_i - shared string initialization
   Purpose: Test the upc_memset functionality
   Type: Positive.
   How : - Initialize a private array using memset
         - For each thread do the following:
         -   Initialize a shared array using upc_memset
	 -   Compare the two arrays
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <upc_relaxed.h>


#define SIZE 1000
#define VALUE 24

int arr1[SIZE];
shared[] int arr2[SIZE];

int main()
{
	int i, j;
	int errflag=0;

   	memset(arr1, VALUE, SIZE*sizeof(int));

   	for (i=0; i<THREADS; i++)
	{
		upc_barrier;
      
		if (MYTHREAD==i) upc_memset(arr2, VALUE, SIZE*sizeof(int));

		upc_barrier;
      
		if (MYTHREAD==0)
			for(j=0; j<SIZE; j++)
				if (arr1[j] != arr2[j]) errflag = 1;

		upc_barrier;
		upc_memset(arr2, VALUE+1, SIZE*sizeof(int));	
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

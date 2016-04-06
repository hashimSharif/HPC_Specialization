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
   Test: I_case4_i  -- Declaration of a shared unions
   Purpose: To check that a shared union has affinity to thread 0
         and that it is, as well as its members, accessible to
         to all the threads.
   Type: Positive.
   How : -  Declare a shared union made of two or more fields,
            thread 0 initializes members to some predefined values.
         -  All threads check that they can see the same values. 
            Otherwise, an error message should be returned.
         -  Check that union variable has affinity to thread 0, 
            using upc_threadof(). If it is different from 0, an 
            error message should be returned.
*/

#include <stdio.h>
#include <stdlib.h>
#include <upc.h>
#include <errno.h>

#define MAX_THREADS 100

shared struct ufoo { 
  int a[MAX_THREADS]; 
  float b[MAX_THREADS]; 
} udata;

int main()
{
    int i;
    int errflag=0;

    if (THREADS>MAX_THREADS) {
	printf("Failure: Too many threads.\n");
	exit(1);
    }
    
    //
    // thread 0 set the union field some predefined value
    //
    if (MYTHREAD==0) {
	for(i=0; i<THREADS; i++)
	    udata.a[i]=i;
    }
    upc_barrier 1;
    //
    // to check the variable can be accessed by all threads
    //
    for (i=0; i<THREADS; i++)
	if (udata.a[i]!=i){
	    errflag=1;
#ifdef VERBOSE0
	    printf("Err in thread %d with the union element %d\n",MYTHREAD,i);
#endif
	}
    //
    // check union variable's affinity
    //
    if (upc_threadof(&udata)!=0){
	errflag=1;
#ifdef VERBOSE0
	printf("Error: The union variable udata is not in thread 0\n");
#endif
    }

    if (errflag) {
	printf("Failure: Thread %d errflag %d\n",MYTHREAD,errflag);
    } else if (MYTHREAD == 0) {
	printf("Success: Thread 0\n");
    }

    return(errflag);
 
} 


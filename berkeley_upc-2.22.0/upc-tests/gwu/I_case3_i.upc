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
   Test: I_case3_i - Declaration of shared structures
   Purpose: To check that the shared struct has affinity to thread 0 
            and that it is, as well as its members, accessible by all
            the threads.
   Type: Positive.
   How : -  Declare a shared structure made of two or more fields,
            thread 0 initialize members to some predefined values. 
         -  All threads check that they can see the same values
            Otherwise, an error message should be returned.
         -  Check that the struct variable has affinity to thread 0, using
            upc_threadof(). If it is different from 0, an error message 
            should be returned. 
         -  Check affinity of (&structure field),particularly, when the field 
            is an array. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <upc.h>
#include <errno.h>

#define MAX_THREADS 100

shared struct foo { 
  int a[MAX_THREADS]; 
  float b[MAX_THREADS]; 
} data;

int
main()
{
    int i;
    int errflag=0;
    if (THREADS>MAX_THREADS) {
	printf("Too many threads.\n");
	exit(1);
    }
    //
    // thread 0 to set shared structure variable
    //
    if (MYTHREAD==0)
	for(i=0; i<THREADS; i++) {
    	    data.a[i]=i;
	    data.b[i]=i*10.0;
	}
    upc_barrier 1;
    //
    // all threads check whether they can see the setting or not.
    //

    for(i=0; i<THREADS; i++) {
	if (data.a[i]!=i){
	    errflag=1; 
#ifdef VERBOSE0
	    printf(" Thread %d can not see the data.a[%d]\n",MYTHREAD,i);
#endif
	}
	if (data.b[i]!=i*10.0) {
	    errflag=1;
#ifdef VERBOSE0
	    printf(" Thread %d can not see the data.b[%d]\n",MYTHREAD,i);
#endif
	}
    }
    upc_barrier 2;

    //
    // to check the structure variable affinity
    //
    if (upc_threadof(&data)==0){
#ifdef VERBOSE0
	printf("The structure variable data is in thread 0\n");
#endif
    } else {
	errflag|=2; 
#ifdef VERBOSE0
	printf("Error: The structure variable data is not in thread 0\n");
#endif
    }
    //
    // to check the affinity of the structure field. especially array field.
    //
    if (upc_threadof(&data.a[0])!=0)
	errflag|=4;

#ifdef VERBOSE0
    if (errflag&4)
	printf("The affinity of the structure field is not in thread 0.\n");
    else 
	printf("The affinity of the structure field is in thread 0.\n");
#endif

    if (errflag) {
	printf("Failure: Thread %d error flag %d\n",MYTHREAD,errflag);
    } else if (MYTHREAD == 0) {
	printf("Success: Thread %d\n",MYTHREAD);
    }

    return(errflag);  
}

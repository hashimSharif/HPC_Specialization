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
   Test: VII_case4_i   - work between notify and wait.
   Purpose:
         To check that shared work can be done between upc_notify and upc_wait.
   Type: Positive.
   How : - Declare a shared array, a, of integers of size THREADS. 
           This array will be automatically initialized to 0.
         - Right after the upc_notify statement, every thread sets 
           a[MYTHREAD] to 1.
         - After upc_wait ,every thread computes the sum of the elements 
           of the array.
*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <upc.h>


#define MAX_THREADS 100

shared int a[THREADS];
shared int x[THREADS][MAX_THREADS];

int main(int argc, char** argv)
{
    int i,pe=MYTHREAD;
    int sum=0;
    int errflag=0;
  
    if (THREADS>MAX_THREADS) {
	printf("Too many threads.\n");
	exit(1);
    }
    
    sleep(MYTHREAD/2); 
    a[pe]=1;

    upc_notify 1;

    for(i=0; i<10; i++)
	x[MYTHREAD][i] += a[MYTHREAD];  // The accesses to x are not local
  
    upc_wait 1;

    for (i=0; i<THREADS; i++) 
	sum+=a[i];
  
    if (sum!=THREADS)
	errflag=1;
 
    if (errflag) {
	printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
    } else if (MYTHREAD == 0) {
	printf("Success: on Thread %d \n",MYTHREAD);
    }

    return(errflag); 
}



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
   Test: I_case5_ii  -- Test the blocked array of structures. 
   Purpose: To check that the elements of the blocked array of a structure can 
            be accessed by all threads and the affinity of the members of the 
            structure in the shared array.
   Type: Positive.
   How : -  Declare a blocked array of structure.
         -  Assign the initial value to the elements of the array by each thread,
            with forall statement.
         -  All threads check that they can see the same values. 
            Otherwise, an error message should be returned.
         -  Check the affinity of the elements of the array  
            using upc_threadof(). If its affinity is not correct, an 
            error message should be returned.
*/

#include <stdio.h>
#include <upc.h>
#include <errno.h>

#define NUMBER 100
#define BLOCK 8

struct foo { 
  char No;
  int  a[NUMBER]; 
};

shared[BLOCK] struct foo barray[THREADS];

int main()
{
   int i,j, pe=MYTHREAD;
   int errflag=0;
   int sum;
   shared [] char *pNo;
   shared [] int *psa; 

   //
   // the value of the blocked shared array of structure value 
   // is set by thread 0. 
   //
   if (pe==0) {
     for(i=0; i<THREADS; i++){
       barray[i].No=i;
       for(j=0; j<NUMBER; j++)
         barray[i].a[j]=i*NUMBER+j; 
     }
  }
   upc_barrier 1;
   //
   // to check the variable can be accessed by all threads
   // 0+1+...+(THREADS*NUMBER-1)=(THREADS*NUMBER)*(THREADS*NUMBER-1)/2
   //
   sum=0;
   for (i=0; i<THREADS; i++)
     for(j=0; j<NUMBER; j++)
       sum+=barray[i].a[j];
   if (sum!=(THREADS*NUMBER)*(THREADS*NUMBER-1)/2){
     errflag=1;
     #ifdef VERBOSE1
       printf("The elements of the block array of structure are accessed error!\n");
     #endif
   } else
     #ifdef VERBOSE1
       printf("The elements of the block array of structure are accessed OK!\n");
     #endif
   //
   // check the affinity of the elements of shared array of structure
   // for each item in its fields.
   //
   for(i=0; i<THREADS; i++){
     pNo=&barray[i].No;
     if (upc_threadof(pNo)!=(i/BLOCK)%THREADS) {
       errflag=2;
       #ifdef VERBOSE1
         printf("Error in the test for affinity of the blocked array of struct!\n");
       #endif
     }
     for(j=0; j<NUMBER; j++){
       psa=&barray[i].a[j];
       if (upc_threadof(psa)!=(i/BLOCK)%THREADS){
         errflag=3;
         #ifdef VERBOSE1
           printf("Error in the test for affinity of the blocked array of struct!\n");
         #endif
       }
     }
     if ((errflag!=2)||(errflag!=3)) {
       #ifdef VERBOSE1
         printf("Test for the affinity of the blocked array of struct is OK!\n");
       #endif
     }
   }

   if (errflag) {
       printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
   } else if (MYTHREAD == 0) {
       printf("Success: on Thread %d \n",MYTHREAD);
   }

   return(errflag);
} 


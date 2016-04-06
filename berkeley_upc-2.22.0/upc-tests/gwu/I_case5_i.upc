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
   Test: I_case5_i  -- Test the shared array of structures. 
   Purpose: To check that the elements of the shared array of structure can 
            be accessed by all threads and the affinity of the members of 
            structure in the shared array.
   Type: Positive.
   How : -  Declare a shared array of structure.
         -  Assign the initial value to the elements of the array by each thread,
            with a forall statement.
         -  All threads check that they can see the same values. 
            Otherwise, an error message should be returned.
         -  Check the affinity of the elements of the array  
            using upc_threadof(). If its affinity is not correct, an 
            error message should be returned.
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define NUMBER 100

struct foo { 
  char No;
  int  a[NUMBER]; 
};

shared struct foo sarray[THREADS];

int main()
{
   int i, j;
   int errflag=0;
   int sum;
   shared [] char *pNo;
   shared [] int *psa; 

   /*
    * the value of shared array of structure value is set by each thread. 
    */
   upc_forall(i=0; i<THREADS; i++; i){
     sarray[i].No=i;
     for(j=0; j<NUMBER; j++)
       sarray[i].a[j] = MYTHREAD*NUMBER+j; 
   }
   upc_barrier 1;
   /*
    * to check the variable can be accessed by all threads
    * 0+1+...+(THREADS*NUMBER-1)=(THREADS*NUMBER)*(THREADS*NUMBER-1)/2
    */
   sum=0;
   for (i=0; i<THREADS; i++)
     for(j=0; j<NUMBER; j++)
       sum+=sarray[i].a[j];

   if (sum!=(THREADS*NUMBER)*(THREADS*NUMBER-1)/2)
     errflag=1;

#ifdef VERBOSE1
   if (errflag)
     printf("The elements of the shared array of structure are accessed error!\n");
   else
     printf("The elements of the shared array of structure are accessed OK!\n");
#endif
   
   /*
    * check the shared array of structure's affinity
    */
   for(i=0; i<THREADS; i++) {
     pNo=&sarray[i].No;
     if ((upc_threadof(pNo)!=i) && (!(errflag&2))) {
       errflag|=2;
       #ifdef VERBOSE1
         printf("Error in the test for affinity of the shared array of struct!\n");
       #endif
       i=THREADS-1;	/* leave the for loop */
     }
     for(j=0; j<NUMBER; j++){
       psa=&sarray[i].a[j];
       if (upc_threadof(psa)!=i){
         errflag|=4;
         #ifdef VERBOSE1
           printf("Error in the test for affinity of the shared array of struct!\n");
         #endif
         j=NUMBER-1;	/* leave the for loop */
       }
     }
     if ((errflag!=2)||(errflag!=3)) {
       #ifdef VERBOSE1
         printf("Test for the affinity of the shared array of struct is OK!\n");
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

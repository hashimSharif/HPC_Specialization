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
   Test: I_case1_v  - Declaration of shared scalars with static storage class. 
   Purpose: To check that a shared variable has affinity to thread 0, and it 
         is accessible to the other threads. 
   Type: Positive.
   How : - Declare a shared scalar, have it initialized by thread 0 
           to a certain value, every thread to check the variable's value and
           determine whether the variable has a affinity to thread 0.
*/


#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define DATA 100

shared int x;

int main()
{
   int i, pe=MYTHREAD;
   int errflag=0;

   if (pe==0) x=DATA;
   upc_barrier 1;

   // check the value of the variable
   if (x!=DATA) {
     #ifdef VERBOSE1
       printf("thread %d check error! x=%d\n",pe,x);
     #endif
     errflag=1;
   }
   else {
     #ifdef VERBOSE0
       printf("thread %d check OK! x=%d\n",pe,DATA);
     #endif
   }

   // check the affinity of the variable
   i=upc_threadof(&x);
   if (i!=0) {
#ifdef VERBOSE0
     printf("error: x is not allocated in thread 0.\n");
#endif
     errflag=1;
   }
   else{
#ifdef VERBOSE0
     printf("OK! x is allocated in thread 0.\n");
#endif
   }

   if (errflag) {
       printf("Failure: Thread %d errflag %d\n",MYTHREAD,errflag);
   } else if (MYTHREAD == 0) {
       printf("Success: Thread %d\n",MYTHREAD);
   }
   return(errflag);
}

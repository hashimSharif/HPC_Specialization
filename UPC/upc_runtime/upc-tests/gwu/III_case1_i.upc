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
   Test: III_case1_i -- Qualifying an object as "shared shared"
   Purpose: To check that the qualifying an object as "shared shared" 
         through the usage of typedef is permitted. 
   Type: Positive
   How : - Define a new type shared_integer as being shared integer.
         - Declare a shared variable of type shared_integer.
         - Test the affinity to thread 0. 
         - Check that a specific value written into the variable by 
           thread 0 can be seen by all threads.
*/

#include <stdio.h>
#include <errno.h>
#include <upc.h>

typedef shared int shared_integer;

shared_integer x;

int main()
{
  int pe=MYTHREAD;
  int errflag=0;

  if (pe==0) x=10;
  upc_barrier 1;

  if (upc_threadof(&x)!=0){
    errflag=1;
  }

  if (x!=10){
    errflag=1;
  }
  
  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}

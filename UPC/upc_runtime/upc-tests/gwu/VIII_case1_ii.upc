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
   Test: VIII_case1_ii  - forall test(integer constant)
   Purpose:
         To check that only the thread, whose number is specified in this 
         field, will execute the actual iteration of the forall loop
         (requires at least two threads).
   Type: Positive.
   How : - In the forall statement, check that thread, which is executing 
           the current iteration, is the one specified by the 
           integer constant. If (MYTHREAD!=constant), an error message 
           should be returned.
*/


#include <stdio.h>
#include <errno.h>
#include <upc.h>

shared int a[THREADS];

int
main()
{
  int i,pe=MYTHREAD;
  int sum=0;
  int errflag=0;

  if (THREADS<2)
  { printf("This test can not be performed with less than 2 threads.\n");
    return 1;
  }

  upc_forall(i=0; i<THREADS; i++; 1)
    if (pe!=1){
      errflag=1;   
    } 
  
  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag); 
}

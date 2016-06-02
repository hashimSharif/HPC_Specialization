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
   Test: VII_case3_i   - implicit barrier test.
   Purpose:
         To check that all threads are already created at the beginning of the
         program.
   Type: Positive.
   How : - Declare a shared array, a, of integers of size THREADS. 
           This array will automatically be initialized to 0.
         - Every thread reads the elements of the array, right at the beginning
           of the program. This ensures that all the threads have been created
           and that their shared address space is available for use to all the
           threads.
         - If a thread cannot access an element of the array that has affinity
           to another thread, this means that this other thread has not been 
           created yet. Therefore, the implicit barrier at the beginning of the
           program is not working properly.
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
 
  for(i=0; i<THREADS; i++) 
     sum+=a[i];
   
  if (sum!=0) 
     errflag=1;

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}



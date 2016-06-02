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
   Test: IX_case1_i   -  Automatic initialization of shared objects
   Purpose:
         To check that the shared object are automatically initialized to 0.
   Type: Positive.
   How : - Declare a shared array of integer.
         - at the beginning of main(), check that all array values are equal 
           to 0. An error message should be generated, otherwise.
*/

#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define N 100

shared int a[N][THREADS];

int
main()
{
  int i,j,pe=MYTHREAD;
  int errflag=0;

  for(i=0; i<N;  i++)
     for (j=0; j<THREADS; j++)
        if (a[i][j]!=0)
          errflag=1;
    
  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);   
}



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
   Test: V_case1_i  - Assignement of shared to private
   Purpose: To check the assignment from shared to private objects. 
   Type: Positive.
   How : - Define a shared integer and a private integer variable.
         - Thread 0 assigns initial predefined value to the shared variable.
         - All the threads assign this value to their local integer variable
           and check that they see the same value.
*/
 
#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define CONST 10

shared int k;

int main()
{
  int x,pe=MYTHREAD;
  int errflag=0;
  
  if (pe==0) k=CONST; 
  
  upc_barrier 1;

  x=k;

  if (x!=CONST)
    errflag=1;

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);
}



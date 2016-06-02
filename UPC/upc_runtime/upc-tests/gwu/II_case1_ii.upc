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
   Test: II_case1_ii - Set shared pointer to point to private scalar
   Purpose: 
         To check that the shared pointers can not point to private scalars. 
   Type: Negative (compilation error)
   How : -  Declare a shared pointer and a non shared scalar,
         -  Make the pointer point to the private scalar.
*/

#define MARK 100

#include <stdio.h>
#include <upc.h>
#include <errno.h>

int x=MARK;
shared int *ptr;

int
main()
{
  int i, pe=MYTHREAD;
  int errflag=0;

  ptr=(shared int *)&x;  // here should be a compiler error!
  
  if (*ptr!=MARK)
    errflag=1;

  #ifdef VERBOSE0
    if (errflag==0)
	printf("Test for the shared pointer point the private variable is OK!\n");
    else 
	printf("Err in test for the shared pointer point the private variable!\n");
  #endif
  return(errflag); 
}


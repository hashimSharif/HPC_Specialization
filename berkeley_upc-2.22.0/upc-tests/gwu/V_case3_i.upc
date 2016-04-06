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
   Test: V_case3_i  - Assignment of private pointers to non blocked
                      shared pointers
   Purpose: To check the assignment of private pointers to shared 
   Type: Negative - compilation error.
   How : - Define a pointer to shared and a private pointer
           to private data.
         - Assigment the private pointer to the shared pointer. (Here
           should be a compilation error message). 
*/
 
#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define COUNT 100

int a[COUNT];
int *pptr;
shared int *sptr;

int main()
{
  int pe=MYTHREAD;
 
  pptr=a; // point the private data
 
  sptr=(shared int *)pptr; // There should be a compilation error message here.

#ifdef VERBOSE0
  printf("test program is OK!\n");
#endif

  return(0); // if no compiler error!
}

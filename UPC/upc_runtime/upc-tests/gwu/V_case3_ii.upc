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
   Test: V_case3_ii  - Assignment of private pointers to blocked 
                      shared pointers
   Purpose: To check the assignment of private pointers to 
         blocked shared pointers.
   Type: Negative.
   How : - Define a pointer to blocked-shared and a private  
           pointer to private data.
         - Make the private pointer point to the private data. 
         - All threads assigns the private pointer to the shared 
           blocked pointer and there will be a compilation error message.
*/
 
#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define BLOCK 10
#define COUNT 100

int a[COUNT];
int *pptr;
shared [BLOCK] int *sptr;

int
main()
{
  int pe=MYTHREAD;
  int errflag=0;
 
  pptr=a;
 
  sptr=(shared [BLOCK] int *)pptr; // here should be a compilation error

#ifdef VERBOSE0
  printf("test program is OK!\n");
#endif

  return(errflag);
}

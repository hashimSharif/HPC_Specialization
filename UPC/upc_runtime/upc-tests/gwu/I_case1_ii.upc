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
   Test: I_case1_ii  -- Usage of shared scalars as function parameter.
   Purpose:  To check that the function parameters can not be shared scalars. 
   Type: Negative (compilation)
   How : - Declare function parameters with shared type qualifier. 
   Passing criteria:
         Object and executable files are not generated and an error message
         is produced by compiler.
*/

#include <upc.h>
#include <stdio.h>
#include <errno.h>

shared int k;

int func(shared int k)
{
  return(k+1);
}

int main()
{
   int pe=MYTHREAD;

   int x;  // declare a shared in main function

   upc_barrier 1;
   if (pe==0) k=10;  
   x=func(k);
   #ifdef VERBOSE1
     if (!MYTHREAD)
       printf(" Program compiled and shared variables x and k are created and set");
     printf("thread=%d k=%d x=%d\n",pe,k,x);
   #endif
   return(0); // if here can be reached, it is OK!   
}

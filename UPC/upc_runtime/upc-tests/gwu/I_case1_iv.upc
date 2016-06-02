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
   Test: I_case1_iv  - Declaration of shared scalars
			within unions
   Purpose: To check that shared scalars can not be declared within unions. 
   Type: Negative (compilation)
   How:  - Declaration of a shared scalar within a union.
   Passing criteria:
         Object and executable files are not generated and an error 
         message is produced by compiler.
*/

#include <upc.h>
#include <stdio.h>
#include <errno.h>

union ut {
  shared int x;
  shared double y;
} udata;

int main()
{
   int pe=MYTHREAD;

   if (pe==0) udata.x=pe;

   #ifdef VERBOSE1     
     printf("The union field: udata.x=%d\n",udata.x);
   #endif
   return(0); // if here can be reached, it is OK!
}

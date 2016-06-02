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
   Test: I_case1_iii - Declaration of shared scalars
		       within structures
   Purpose: To check that shared scalars can not be declared within a structure.
   Type: Negative (compilation)
   How:  - Declare a shared scalar within a structure 
   Passing criteria:
         Object and executable files are not generated and an error
         message is produced by compiler.
*/

#include <upc.h>
#include <stdio.h>
#include <errno.h>

#define Data 10.0

struct st {
  shared int x;
  shared double y;
} sdata;

int main()
{
   int pe=MYTHREAD;

   if (pe==0) {
     sdata.x=pe;
     sdata.y=Data;
     #ifdef VERBOSE1
       printf("sdata.x=%d sdata.y=%8.3f\n",sdata.x,sdata.y);
     #endif
   }
   return(0);
}


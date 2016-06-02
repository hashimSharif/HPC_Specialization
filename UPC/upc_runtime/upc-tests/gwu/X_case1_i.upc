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
   Test: X_case1_i - upc_global_exit
   Purpose: To check that upc_global_exit terminates the execution
   Type: Positive.
   How : - Call upc_global_exit before returning from the main function.
*/

#include <stdio.h>
#include <errno.h>
#include <upc.h>

int main()
{
  upc_global_exit(0);  // Returns the value 0 : test executed correctly.

  printf("Failure: on Thread %d \n",MYTHREAD);

  return(1);           // If this point is reached, it produces an error.
}

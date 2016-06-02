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
   Test: V_case5_i - Assignment of shared-pointers-to-shared to 
                     private-pointers-to-shared with different 
                     blocking factors. 
   Purpose: To check that the phase becomes 0 and that pointer arithmetic 
          obeys the original type of the shared pointer to be manipulated. 
   Type: Positive.
   How : - Declare two blocked shared pointers to integer, with different 
           blocking factors,
         - Do the Cast.
         - Check that the phase is equal to 0, for the assigned pointer.
         - Increment the pointer by a certain value.
         - Check the pointer value, through the use of upc_addrfield().
*/

#include <stdio.h>
#include <errno.h>
#include <upc.h>

#define BLOCK1 8
#define BLOCK2 12

shared [BLOCK2] int array[THREADS*BLOCK2*10];

shared [BLOCK1] int *sptr1;
shared [BLOCK2] int *shared sptr2;

int main()
{
  int errflag=0;

  if (!MYTHREAD) sptr2=&array[BLOCK2-1];

  upc_barrier 0;

  /* the pointer &sptr[BLOCK2-1] should have a phase of BLOCK2-1 */
  if (upc_phaseof(sptr2)!=BLOCK2-1) errflag=1;

  sptr1=(shared[BLOCK1] int *)sptr2;

  upc_barrier 1;

  if (upc_phaseof(sptr1)!=0) errflag|=2;

  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

#if 0
  if (errflag&1)
    printf("Error in the phase of the blocked pointer.\n");
  if (errflag&2)
    printf("Error in casting block pointers with different blocking factor.\n");
#endif 

  return(errflag);
}

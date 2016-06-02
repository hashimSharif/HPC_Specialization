/*
UPC nqueens
Copyright (C) 2000 Sebastien Chauvin, Tarek El-Ghazawi

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

#include <stdlib.h>
#include <stdio.h>
#include <upc.h>
#include <upc_strict.h>
#include "defs.h"

int sched(int n, int level, int method)
{ int l,j,c;
  int nsols=0;
  int njobs=1;
  sol_t solutions;

  int job;
  int valid;
  msk_t msk;
  unsigned long colstk;

  for(l=0;l<level;l++) njobs*=n;  // Calculate the number of jobs

  if (njobs>MAX_JOBS) return -1;  // Too many jobs

#ifdef DEBUG0 
  printf("njobs = %d\n", njobs);
#endif

  upc_forall(j=0;j<njobs;j++;(method==METH_ROUND)?(j%THREADS):
                                              (j*THREADS)/njobs)
  { job=j;
    valid=1;
    msk=0;
    colstk=0;

#ifdef DEBUG0 
    printf("job = %d\n", j);
#endif
    for(l=0;l<level;l++)          // Unpack the job number
    { c=job%n;                    // Compute the col number
      job/=n;                     // Prepare for the next level
      colstk<<=4;
      colstk|=c;                  // Push the column

               // Check the validity of the queen position
      if (msk&(BASECOLMSK<<c))            
      { valid=0;                  
        break;
      }
      msk|=BASECOLMSK<<c;   // Place the queen

                            // Compute the diagonals shifts
      msk = (msk&CXMASK) + ((msk&D1MASK) << 1) + ((msk&D2MASK) >> 1);
    }
    if (valid)
    {
#ifdef DEBUG
      printf("gen (jobs = %d)\n", j);
#endif 
      nsols+=gen(colstk, l, msk, n, &solutions);  // Start the seq algorithm
    }
  }

  // upc_free does not seem to be in the librairy now.
  // upc_free(solutions.sol);

  // Work around :
  // As it was allocated locally we can cast it and free it locally.

//  free((void*)solutions.sol);

  return nsols;
}

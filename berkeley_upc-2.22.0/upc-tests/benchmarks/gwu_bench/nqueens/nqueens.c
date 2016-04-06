/*
UPC nqueens
Copyright(C) 2000-2001 Sebastien Chauvin, Tarek El-Ghazawi.

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

#include <upc.h>
#include <upc_strict.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "defs.h"

/* ITERATION_NUM: number of iterations of the N-Queens algorithm. Running
 * the algorithm several times allows to get a more accurate execution time.
 */
#define ITERATION_NUM 40.0

shared int init_ok;
shared int number_sols[THREADS];

shared int n,l;
shared int method;

int main(int argc, char** argv)
{ int i;
  int nsols;

  clock_t clk;

  /*
   * Due to current implementation of mask, sizeof(msk_t) has to be 8 bytes!
   */
  assert(sizeof(msk_t)==8);

  init_ok=1;

  setbuf(stdout,NULL);

  if (MYTHREAD==0)
  { if ((argc!=2) && (argc!=4))
    { fprintf(stderr, "Usage: %s n [level job_distribution]\n", argv[0]);
      fprintf(stderr, "\tn                 chessboard edge size, 0 < n <=16\n"
                      "\tlevel             job distribution depth level\n"
                      "\tjob_distribution  one of `chunking' or `round_robin'\n");
      init_ok = 0;
      exit(1);
    }
    n=atoi(argv[1]);
    if ((n<=0) || (n>16))
    { fprintf(stderr,"0<n<%i\n", 16);
      init_ok = 0;
    }

	if(argc==4)
	{
	    l=atoi(argv[2]);
	    if ((l<0) || (l>=n))
	    { fprintf(stderr,"0<=l<n\n");
	      init_ok = 0;
	    }
	
	    if (!strcmp(argv[3],"chunking"))
	      method = METH_CHUNKING;
	    else if (!strcmp(argv[3],"round_robin"))
	      method = METH_ROUND;
	    else 
	    { fprintf(stderr,"chunking or round_robin\n");
	      init_ok = 0;
	    }
    }
	else
	{	/* Default parameters */
		l=2;
		method=METH_ROUND;
	}
  }

  upc_barrier(-1);

  if (!init_ok) return 1;

  clock();
  
  for(i=0;i<ITERATION_NUM;i++)
  { number_sols[MYTHREAD] = sched(n,l,method);
    upc_barrier(i);
  }

     //                 Reduction to determine the total number of solutions
  nsols=0;

  if (MYTHREAD==0)
  { int i;
    for(i=0;i<THREADS;i++)
    { nsols+=number_sols[i];
    }
  }

#ifdef DEBUG
  printf("time computation\n");
#endif

  if (MYTHREAD==0)
  { clk = clock();

    printf("%d solutions found\n", nsols);
    printf("time = %g seconds\n", ((double)clk)/((double)(CLOCKS_PER_SEC*ITERATION_NUM)));
    printf("done.\n");
  }
  return 0;
}

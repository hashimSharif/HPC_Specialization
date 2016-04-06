/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void add(void)
{
  int c, i, j, k, m;

  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/
  
  /*--------------------------------------------------------------------
    c addition of update to the vector u
    c-------------------------------------------------------------------*/
  for (c = 0; c < ncells; c++ )
    {
      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	{
	  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
	    {
	      for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		{
		  for (m = 0; m < 5; m++)
		    {
		      u_priv_d(c,i+2,j+2,k+2,m) = 
			u_priv_d(c,i+2,j+2,k+2,m) + 
			rhs_priv_d(c,i+1,j+1,k+1,m);
		    }
		}
	    }
	}
    }
}

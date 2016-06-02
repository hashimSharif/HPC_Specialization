/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void lhsinit(void)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  int i, j, k, d, c, m, n;

  for (c = 0; c < ncells; c++ )
    {
      for (d = 0; d < 3; d++ )
	{
	  if( cell_coord[c][d] == 1 )
	    startc[c][d] = 1;
	  else
	    startc[c][d] = 0;

	  if( cell_coord[c][d] == ncells )
	    endc[c][d] = 1;
	  else
	    endc[c][d] = 0;
	}

      /*--------------------------------------------------------------------
	c     zero the whole left hand side for starters
	c-------------------------------------------------------------------*/
      for (i = 0; i < cell_size[c][0]; i++)
	{
	  for (j = 0; j < cell_size[c][1]; j++)
	    {
	      for (k = 0; k < cell_size[c][2]; k++)
		{
		  for (n = 0; n < 5; n++)
		    {
		      for (m = 0; m < 5; m++)
			{
			  lhs_priv_d(c,i+1,j+1,k+1,0,n,m) = 0.0;
			  lhs_priv_d(c,i+1,j+1,k+1,1,n,m) = 0.0;
			  lhs_priv_d(c,i+1,j+1,k+1,2,n,m) = 0.0;
			}
		    }
		}
	    }
	}

      /*--------------------------------------------------------------------
	c      next, set all diagonal values to 1. This is overkill, but 
	c      convenient
	c-------------------------------------------------------------------*/
      for (i = 0; i < cell_size[c][0]; i++)
	{
	  for (j = 0; j < cell_size[c][1]; j++)
	    {
	      for (k = 0; k < cell_size[c][2]; k++)
		{
		  for (m = 0; m < 5; m++)
		    {
		      lhs_priv_d(c,i+1,j+1,k+1,1,m,m) = 1.0;
		    }
		}
	    }
	}
    }
}

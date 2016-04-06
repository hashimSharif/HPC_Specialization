/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void rhs_norm(double *rms)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  int c, i, j, k, d, m;
  double add, rms_work[5];
  double gp, val;
  double *rms_priv_arr;
  shared [] double *rms_sh_arr;

  rms_priv_arr = (double *) &sr_d_s[MYTHREAD].t[0];

  for (m = 0; m < 5; m++)
    {
      rms_work[m] = 0.0;
    }

  for (c = 0; c < ncells; c++)
    {
      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	{
	  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
	    {
	      for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		{
		  for (m = 0; m < 5; m++)
		    {
		      add = rhs_priv_d(c,i+1,j+1,k+1,m);
		      rms_work[m] = rms_work[m] + add*add;
		    }
		}
	    }
	}
    }

  // MPI_ALL_REDUCE
  for( m=0; m<5; m++ )
    {
      //sr_d_s[MYTHREAD].t[m] = rms_work[m];
      rms_priv_arr[m] = rms_work[m];
    }
  upc_barrier;

  // MPI_ALL_REDUCE
  if( MYTHREAD == 0 )
    {
      for( m=0; m<5; m++ )
	{
	  rms[m] = 0.0;
	  for ( d=0; d<THREADS; d++ )
	    {
	      rms_sh_arr = (shared [] double *) &sr_d_s[d].t[0];
              val = rms_sh_arr[m];
              rms[m] = rms[m] + val;
	      //rms[m] += sr_d_s[d].t[m];
	    }
	}
      
      for (m = 0; m < 5; m++)
	{
	  for (d = 0; d < 3; d++)
	    {
	      gp = grid_points[d]-2;
              rms[m] = rms[m] / gp;
	      //rms[m] = rms[m] / (double)(grid_points[d]-2);
	    }
	  rms[m] = sqrt(rms[m]);
	}
    }
}

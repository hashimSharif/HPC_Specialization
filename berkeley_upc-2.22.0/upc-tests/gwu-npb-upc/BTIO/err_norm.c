/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void error_norm(double *rms)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c this function computes the norm of the difference between the
    c computed solution and the exact solution
    c-------------------------------------------------------------------*/

  int c, i, j, k, m, d, ii, jj, kk;
  double xi, eta, zeta, u_exact[5], rms_work[5], add;
  double gp, val;
  double *rms_priv_arr;
  shared [] double *rms_sh_arr;

  rms_priv_arr = (double *) &sr_d_s[MYTHREAD].t[0];

  for (m = 0; m < 5; m++)
    {
      rms_work[m] = 0.0;
    }

  for (c = 0; c < ncells; c++ )
    {
      ii = 0;
      for (i = cell_low[c][0]; i <= cell_high[c][0]; i++)
	{
	  xi = (double)i * dnxm1;
	  jj = 0;
	  for (j = cell_low[c][1]; j <= cell_high[c][1]; j++)
	    {
	      eta = (double)j * dnym1;
	      kk = 0;
	      for (k = cell_low[c][2]; k <= cell_high[c][2]; k++)
		{
		  zeta = (double)k * dnzm1;
		  //exact_solution(xi, eta, zeta, u_exact);
		  exact_solution(zeta, eta, xi, u_exact);
		  for (m = 0; m < 5; m++)
		    {
		      if(iotype == 0 || iotype == 3)
		        add = u_priv_d(c,ii+2,jj+2,kk+2,m) - u_exact[m];
		      else
		        add = u_priv_d(c,kk+2,jj+2,ii+2,m) - u_exact[m];
		      rms_work[m] = rms_work[m] + add*add;
		    }
		  kk = kk + 1;
		}
	      jj = jj + 1;
	    }
	  ii = ii + 1;
	}
    }

  for( m=0; m<5; m++ )
    {
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

	    }
	}
      
      for (m = 0; m < 5; m++)
	{
	  for (d = 0; d < 3; d++)
	    {
	      gp = grid_points[d]-2;
              rms[m] = rms[m] / gp;

	    }
	  rms[m] = sqrt(rms[m]);
	}
    }
}



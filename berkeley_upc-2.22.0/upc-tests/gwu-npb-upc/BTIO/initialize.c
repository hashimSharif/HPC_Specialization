/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void initialize(void)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c This subroutine initializes the field variable u using 
    c tri-linear transfinite interpolation of the boundary values     
    c-------------------------------------------------------------------*/
  
  int c, i, j, k, m, ii, jj, kk, ix, iy, iz;
  double xi, eta, zeta, Pface[2][3][5], Pxi, Peta, Pzeta, temp[5];

  /*--------------------------------------------------------------------
    c  Later (in compute_rhs) we compute 1/u for every element. A few of 
    c  the corner elements are not used, but it convenient (and faster) 
    c  to compute the whole thing with a simple loop. Make sure those 
    c  values are nonzero by initializing the whole thing here. 
    c-------------------------------------------------------------------*/
  
  m = c = 0;
  kk = jj = ii = 1;
  while (c < ncells )
    {
      u_priv_d(c,ii,jj,kk,m) = 1.0;
      m++;
      if( m == 5 )
	{
	  m = 0;
	  kk++;
	  if( kk == (KMAX+3) )
	    {
	      kk = 1;
	      jj++;
	      if( jj == (JMAX+3) )
		{
		  jj = 1;
		  ii++;
		  if( ii == (IMAX+3) )
		    {
		      ii = 1;
		      c++;
		    }
		}
	    }
	}
    }

  /*
  for (c = 0; c < ncells; c++ )
    {
      for ( m = 0; m < 5; m++ )
	{
	  for (ii = -1; ii <= IMAX; ii++)
	    {
	      for (jj = -1; jj <= JMAX; jj++)
		{
		  for (kk = -1; kk <= KMAX; kk++)
		    {
		      u_priv_d(c,ii+2,jj+2,kk+2,m) = 1.0;
		    }
		}
	    }
	}
    }
  */
  //printf("TH%02d: (D) initialize() -- 1\n", MYTHREAD ); 

  /*--------------------------------------------------------------------
    c first store the "interpolated" values everywhere on the grid    
    c-------------------------------------------------------------------*/

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
                  
		  for (ix = 0; ix < 2; ix++)
		    {
		      exact_solution((double)ix, eta, zeta, 
				     &Pface[ix][0][0]);
		    }

		  for (iy = 0; iy < 2; iy++)
		    {
		      exact_solution(xi, (double)iy , zeta, 
				     &Pface[iy][1][0]);
		    }

		  for (iz = 0; iz < 2; iz++)
		    {
		      exact_solution(xi, eta, (double)iz,   
				     &Pface[iz][2][0]);
		    }

		  for (m = 0; m < 5; m++)
		    {
		      Pxi = xi * Pface[1][0][m] + 
			(1.0-xi) * Pface[0][0][m];
		      Peta = eta * Pface[1][1][m] + 
			(1.0-eta) * Pface[0][1][m];
		      Pzeta = zeta * Pface[1][2][m] + 
			(1.0-zeta) * Pface[0][2][m];
 
		      u_priv_d(c,ii+2,jj+2,kk+2,m) = Pxi + Peta + Pzeta - 
			Pxi*Peta - Pxi*Pzeta - Peta*Pzeta + 
			Pxi*Peta*Pzeta;
		    }
		  kk = kk + 1;
		}
	      jj = jj + 1;
	    }
	  ii = ii + 1;
	}
    }

  //printf("TH%02d: (D) initialize() -- 2\n", MYTHREAD ); 

  /*--------------------------------------------------------------------
    c now store the exact values on the boundaries        
    c-------------------------------------------------------------------*/

#if( DEBUG == TRUE )
  printf(" slice X : %d / %d\n", slice[0][0], slice[ncells-1][0]);
  printf(" slice Y : %d / %d\n", slice[0][1], slice[ncells-1][1]);
  printf(" slice Z : %d / %d\n", slice[0][2], slice[ncells-1][2]);
#endif

  /*--------------------------------------------------------------------
    c west face                                                  
    c-------------------------------------------------------------------*/
  
  c = slice[0][0];
  ii = 0;
  xi = 0.0;
  jj = 0;
  for (j = cell_low[c][1]; j <= cell_high[c][1]; j++)
    {
      eta = (double)j * dnym1;
      kk = 0;
      for (k = cell_low[c][2]; k <= cell_high[c][2]; k++)
	{
	  zeta = (double)k * dnzm1;
	  exact_solution(xi, eta, zeta, temp);
	  for (m = 0; m < 5; m++)
	    {
	      u_priv_d(c,ii+2,jj+2,kk+2,m) = temp[m];
	    }
	  kk = kk + 1;
	}
      jj = jj + 1;
    }

  /*--------------------------------------------------------------------
    c east face                                                      
    c-------------------------------------------------------------------*/

  c = slice[ncells-1][0];
  ii = cell_size[c][0]-1;
  xi = 1.0;
  jj = 0;
  for (j = cell_low[c][1]; j <= cell_high[c][1]; j++)
    {
      eta = (double)j * dnym1;
      kk = 0;
      for (k = cell_low[c][2]; k <= cell_high[c][2]; k++)
	{
	  zeta = (double)k * dnzm1;
	  exact_solution(xi, eta, zeta, temp);
	  for (m = 0; m < 5; m++)
	    {
	      u_priv_d(c,ii+2,jj+2,kk+2,m) = temp[m];
	    }
	  kk = kk + 1;
	}
      jj = jj + 1;
    }

  /*--------------------------------------------------------------------
    c south face                                                 
    c-------------------------------------------------------------------*/

  c = slice[0][1];
  eta = 0.0;
  jj = 0;
  ii = 0;
  for (i = cell_low[c][0]; i <= cell_high[c][0]; i++)
    {
      xi = (double)i * dnxm1;
      kk = 0;
      for (k = cell_low[c][2]; k <= cell_high[c][2]; k++)
	{
	  zeta = (double)k * dnzm1;
	  exact_solution(xi, eta, zeta, temp);
	  for (m = 0; m < 5; m++)
	    {
	      u_priv_d(c,ii+2,jj+2,kk+2,m) = temp[m];
	    }
	  kk = kk + 1;
	}
      ii = ii + 1;
    }

  /*--------------------------------------------------------------------
    c north face                                    
    c-------------------------------------------------------------------*/
  
  c = slice[ncells-1][1];
  eta = 1.0;
  jj = cell_size[c][1]-1;
  ii = 0;
  for (i = cell_low[c][0]; i <= cell_high[c][0]; i++)
    {
      xi = (double)i * dnxm1;
      kk = 0;
      for (k = cell_low[c][2]; k <= cell_high[c][2]; k++)
	{
	  zeta = (double)k * dnzm1;
	  exact_solution(xi, eta, zeta, temp);
	  for (m = 0; m < 5; m++)
	    {
	      u_priv_d(c,ii+2,jj+2,kk+2,m) = temp[m];
	    }
	  kk = kk + 1;
	}
      ii = ii + 1;
    }

  /*--------------------------------------------------------------------
    c bottom face                                       
    c-------------------------------------------------------------------*/

  c = slice[0][2];
  kk = 0;
  zeta = 0.0;
  ii = 0;
  for (i = cell_low[c][0]; i <= cell_high[c][0]; i++)
    {
      xi = (double)i *dnxm1;
      jj = 0;
      for (j = cell_low[c][1]; j <= cell_high[c][1]; j++)
	{
	  eta = (double)j * dnym1;
	  exact_solution(xi, eta, zeta, temp);
	  for (m = 0; m < 5; m++)
	    {
	      u_priv_d(c,ii+2,jj+2,kk+2,m) = temp[m];
	    }
	  jj = jj + 1;
	}
      ii = ii + 1;
    }

  /*--------------------------------------------------------------------
    c top face     
    c-------------------------------------------------------------------*/

  c = slice[ncells-1][2];
  zeta = 1.0;
  kk = cell_size[c][2]-1;
  ii = 0;
  for (i = cell_low[c][0]; i <= cell_high[c][0]; i++)
    {
      xi = (double)i * dnxm1;
      jj = 0;
      for (j = cell_low[c][1]; j <= cell_high[c][1]; j++)
	{
	  eta = (double)j * dnym1;
	  exact_solution(xi, eta, zeta, temp);
	  for (m = 0; m < 5; m++)
	    {
	      u_priv_d(c,ii+2,jj+2,kk+2,m) = temp[m];
	    }
	  jj = jj + 1;
	}
      ii = ii + 1;
    }
}


/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void compute_rhs(void)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  int c, i, j, k, m;
  double rho_inv, uijk, up1, um1, vijk, vp1, vm1;
  double aaa;
  double wijk, wp1, wm1;

  /*--------------------------------------------------------------------
    c      compute the reciprocal of density, and the kinetic energy, 
    c      and the speed of sound. 
    c-------------------------------------------------------------------*/

  for (c = 0; c < ncells; c++ )
    {
#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs() - cell %d - init()\n", c);
#endif

      for (i = -1; i <= cell_size[c][0]; i++)
	{
	  for (j = -1; j <= cell_size[c][1]; j++)
	    {
	      for (k = -1; k <= cell_size[c][2]; k++)
		{
		  aaa=u_priv_d(c,i+2,j+2,k+2,0);
		  rho_inv = 1.0/aaa;
		  rho_i[c][i+1][j+1][k+1] = rho_inv;
		  us[c][i+1][j+1][k+1] = u_priv_d(c,i+2,j+2,k+2,1) * rho_inv;
		  vs[c][i+1][j+1][k+1] = u_priv_d(c,i+2,j+2,k+2,2) * rho_inv;
		  ws[c][i+1][j+1][k+1] = u_priv_d(c,i+2,j+2,k+2,3) * rho_inv;
		  square[c][i+1][j+1][k+1] = 0.5* (u_priv_d(c,i+2,j+2,k+2,1)*u_priv_d(c,i+2,j+2,k+2,1) + 
						   u_priv_d(c,i+2,j+2,k+2,2)*u_priv_d(c,i+2,j+2,k+2,2) +
						   u_priv_d(c,i+2,j+2,k+2,3)*u_priv_d(c,i+2,j+2,k+2,3) ) * rho_inv;
		  qs[c][i+1][j+1][k+1] = square[c][i+1][j+1][k+1] * rho_inv;
		}
	    }
	}

      /*--------------------------------------------------------------------
	c copy the exact forcing term to the right hand side;  because 
	c this forcing term is known, we can store it on the whole grid
	c including the boundary                   
	c-------------------------------------------------------------------*/

#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs() - cell %d - init_2()\n", c);
#endif

      for (m = 0; m < 5; m++)
	{
	  for (i = 0; i < cell_size[c][0]; i++)
	    {
	      for (j = 0; j < cell_size[c][1]; j++)
		{
		  for (k = 0; k <= cell_size[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = forcing[c][m][i][j][k];
		    }
		}
	    }
	}

      /*--------------------------------------------------------------------
	c      compute xi-direction fluxes 
	c-------------------------------------------------------------------*/

#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs() - cell %d - xi()\n", c);
#endif

      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	{
	  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
	    {
	      for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		{
		  uijk = us[c][i+1][j+1][k+1];
		  up1  = us[c][i+1+1][j+1][k+1];
		  um1  = us[c][i-1+1][j+1][k+1];

		  rhs_priv_d(c,i+1,j+1,k+1,0) = rhs_priv_d(c,i+1,j+1,k+1,0) + dx1tx1 * 
		    (u_priv_d(c,i+1+2,j+2,k+2,0) - 2.0*u_priv_d(c,i+2,j+2,k+2,0) + 
		     u_priv_d(c,i-1+2,j+2,k+2,0)) -
		    tx2 * (u_priv_d(c,i+1+2,j+2,k+2,1) - u_priv_d(c,i-1+2,j+2,k+2,1));

		  rhs_priv_d(c,i+1,j+1,k+1,1) = rhs_priv_d(c,i+1,j+1,k+1,1) + dx2tx1 * 
		    (u_priv_d(c,i+1+2,j+2,k+2,1) - 2.0*u_priv_d(c,i+2,j+2,k+2,1) + 
		     u_priv_d(c,i-1+2,j+2,k+2,1)) +
		    xxcon2*con43 * (up1 - 2.0*uijk + um1) -
		    tx2 * (u_priv_d(c,i+1+2,j+2,k+2,1)*up1 - 
			   u_priv_d(c,i-1+2,j+2,k+2,1)*um1 +
			   (u_priv_d(c,i+1+2,j+2,k+2,4)- square[c][i+1+1][j+1][k+1]-
			    u_priv_d(c,i-1+2,j+2,k+2,4)+ square[c][i-1+1][j+1][k+1])*
			   c2);

		  rhs_priv_d(c,i+1,j+1,k+1,2) = rhs_priv_d(c,i+1,j+1,k+1,2) + dx3tx1 * 
		    (u_priv_d(c,i+1+2,j+2,k+2,2) - 2.0*u_priv_d(c,i+2,j+2,k+2,2) +
		     u_priv_d(c,i-1+2,j+2,k+2,2)) +
		    xxcon2 * (vs[c][i+1+1][j+1][k+1] - 2.0*vs[c][i+1][j+1][k+1] +
			      vs[c][i-1+1][j+1][k+1]) -
		    tx2 * (u_priv_d(c,i+1+2,j+2,k+2,2)*up1 - 
			   u_priv_d(c,i-1+2,j+2,k+2,2)*um1);

		  rhs_priv_d(c,i+1,j+1,k+1,3) = rhs_priv_d(c,i+1,j+1,k+1,3) + dx4tx1 * 
		    (u_priv_d(c,i+1+2,j+2,k+2,3) - 2.0*u_priv_d(c,i+2,j+2,k+2,3) +
		     u_priv_d(c,i-1+2,j+2,k+2,3)) +
		    xxcon2 * (ws[c][i+1+1][j+1][k+1] - 2.0*ws[c][i+1][j+1][k+1] +
			      ws[c][i-1+1][j+1][k+1]) -
		    tx2 * (u_priv_d(c,i+1+2,j+2,k+2,3)*up1 - 
			   u_priv_d(c,i-1+2,j+2,k+2,3)*um1);
		  
		  rhs_priv_d(c,i+1,j+1,k+1,4) = rhs_priv_d(c,i+1,j+1,k+1,4) + dx5tx1 * 
		    (u_priv_d(c,i+1+2,j+2,k+2,4) - 2.0*u_priv_d(c,i+2,j+2,k+2,4) +
		     u_priv_d(c,i-1+2,j+2,k+2,4)) +
		    xxcon3 * (qs[c][i+1+1][j+1][k+1] - 2.0*qs[c][i+1][j+1][k+1] +
			      qs[c][i-1+1][j+1][k+1]) +
		    xxcon4 * (up1*up1 - 2.0*uijk*uijk + 
			      um1*um1) +
		    xxcon5 * (u_priv_d(c,i+1+2,j+2,k+2,4)*rho_i[c][i+1+1][j+1][k+1] - 
			      2.0*u_priv_d(c,i+2,j+2,k+2,4)*rho_i[c][i+1][j+1][k+1] +
			      u_priv_d(c,i-1+2,j+2,k+2,4)*rho_i[c][i-1+1][j+1][k+1]) -
		    tx2 * ( (c1*u_priv_d(c,i+1+2,j+2,k+2,4) - 
			     c2*square[c][i+1+1][j+1][k+1])*up1 -
			    (c1*u_priv_d(c,i-1+2,j+2,k+2,4) - 
			     c2*square[c][i-1+1][j+1][k+1])*um1 );
		}
	    }
	}
      
      /*--------------------------------------------------------------------
	c      add fourth order xi-direction dissipation               
	c-------------------------------------------------------------------*/

#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs() - cell %d - xi_2nd()\n", c);
#endif

      if( startc[c][0] > 0 )
	{
	  i = 1;
	  for (m = 0; m < 5; m++)
	    {
	      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp * 
			( 5.0*u_priv_d(c,i+2,j+2,k+2,m) - 4.0*u_priv_d(c,i+1+2,j+2,k+2,m) +
			  u_priv_d(c,i+2+2,j+2,k+2,m));
		    }
		}
	    }
	  
	  i = 2;
	  for (m = 0; m < 5; m++)
	    {
	      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp * 
			(-4.0*u_priv_d(c,i-1+2,j+2,k+2,m) + 6.0*u_priv_d(c,i+2,j+2,k+2,m) -
			 4.0*u_priv_d(c,i+1+2,j+2,k+2,m) + u_priv_d(c,i+2+2,j+2,k+2,m));
		    }
		}
	    }
	}

      for (m = 0; m < 5; m++)
	{
	  for (i = 3*startc[c][0]; i < cell_size[c][0]-3*endc[c][0]; i++)
	    {
	      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp * 
			(  u_priv_d(c,i-2+2,j+2,k+2,m) - 4.0*u_priv_d(c,i-1+2,j+2,k+2,m) + 
			   6.0*u_priv_d(c,i+2,j+2,k+2,m) - 4.0*u_priv_d(c,i+1+2,j+2,k+2,m) + 
			   u_priv_d(c,i+2+2,j+2,k+2,m) );
		    }
		}
	    }
	}

      if( endc[c][0] > 0 )
	{
	  i = cell_size[c][0]-3;
	  for (m = 0; m < 5; m++)
	    {
	      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp *
			( u_priv_d(c,i-2+2,j+2,k+2,m) - 4.0*u_priv_d(c,i-1+2,j+2,k+2,m) + 
			  6.0*u_priv_d(c,i+2,j+2,k+2,m) - 4.0*u_priv_d(c,i+1+2,j+2,k+2,m) );
		    }
		}
	    }

	  i = cell_size[c][0]-2;
	  for (m = 0; m < 5; m++)
	    {
	      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp *
			( u_priv_d(c,i-2+2,j+2,k+2,m) - 4.0*u_priv_d(c,i-1+2,j+2,k+2,m) +
			  5.0*u_priv_d(c,i+2,j+2,k+2,m) );
		    }
		}
	    }
	}

      /*--------------------------------------------------------------------
	c      compute eta-direction fluxes 
	c-------------------------------------------------------------------*/

#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs() - cell %d - eta()\n", c);
#endif

      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	{
	  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
	    {
	      for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		{
		  vijk = vs[c][i+1][j+1][k+1];
		  vp1  = vs[c][i+1][j+1+1][k+1];
		  vm1  = vs[c][i+1][j-1+1][k+1];

		  rhs_priv_d(c,i+1,j+1,k+1,0) = rhs_priv_d(c,i+1,j+1,k+1,0) + dy1ty1 * 
		    (u_priv_d(c,i+2,j+1+2,k+2,0) - 2.0*u_priv_d(c,i+2,j+2,k+2,0) + 
		     u_priv_d(c,i+2,j-1+2,k+2,0)) -
		    ty2 * (u_priv_d(c,i+2,j+1+2,k+2,2) - u_priv_d(c,i+2,j-1+2,k+2,2));

		  rhs_priv_d(c,i+1,j+1,k+1,1) = rhs_priv_d(c,i+1,j+1,k+1,1) + dy2ty1 * 
		    (u_priv_d(c,i+2,j+1+2,k+2,1) - 2.0*u_priv_d(c,i+2,j+2,k+2,1) + 
		     u_priv_d(c,i+2,j-1+2,k+2,1)) +
		    yycon2 * (us[c][i+1][j+1+1][k+1] - 2.0*us[c][i+1][j+1][k+1] + 
			      us[c][i+1][j-1+1][k+1]) -
		    ty2 * (u_priv_d(c,i+2,j+1+2,k+2,1)*vp1 - 
			   u_priv_d(c,i+2,j-1+2,k+2,1)*vm1);

		  rhs_priv_d(c,i+1,j+1,k+1,2) = rhs_priv_d(c,i+1,j+1,k+1,2) + dy3ty1 * 
		    (u_priv_d(c,i+2,j+1+2,k+2,2) - 2.0*u_priv_d(c,i+2,j+2,k+2,2) + 
		     u_priv_d(c,i+2,j-1+2,k+2,2)) +
		    yycon2*con43 * (vp1 - 2.0*vijk + vm1) -
		    ty2 * (u_priv_d(c,i+2,j+1+2,k+2,2)*vp1 - 
			   u_priv_d(c,i+2,j-1+2,k+2,2)*vm1 +
			   (u_priv_d(c,i+2,j+1+2,k+2,4) - square[c][i+1][j+1+1][k+1] - 
			    u_priv_d(c,i+2,j-1+2,k+2,4) + square[c][i+1][j-1+1][k+1])
			   *c2);

		  rhs_priv_d(c,i+1,j+1,k+1,3) = rhs_priv_d(c,i+1,j+1,k+1,3) + dy4ty1 * 
		    (u_priv_d(c,i+2,j+1+2,k+2,3) - 2.0*u_priv_d(c,i+2,j+2,k+2,3) + 
		     u_priv_d(c,i+2,j-1+2,k+2,3)) +
		    yycon2 * (ws[c][i+1][j+1+1][k+1] - 2.0*ws[c][i+1][j+1][k+1] + 
			      ws[c][i+1][j-1+1][k+1]) -
		    ty2 * (u_priv_d(c,i+2,j+1+2,k+2,3)*vp1 - 
			   u_priv_d(c,i+2,j-1+2,k+2,3)*vm1);

		  rhs_priv_d(c,i+1,j+1,k+1,4) = rhs_priv_d(c,i+1,j+1,k+1,4) + dy5ty1 * 
		    (u_priv_d(c,i+2,j+1+2,k+2,4) - 2.0*u_priv_d(c,i+2,j+2,k+2,4) + 
		     u_priv_d(c,i+2,j-1+2,k+2,4)) +
		    yycon3 * (qs[c][i+1][j+1+1][k+1] - 2.0*qs[c][i+1][j+1][k+1] + 
			      qs[c][i+1][j-1+1][k+1]) +
		    yycon4 * (vp1*vp1 - 2.0*vijk*vijk + 
			      vm1*vm1) +
		    yycon5 * (u_priv_d(c,i+2,j+1+2,k+2,4)*rho_i[c][i+1][j+1+1][k+1] - 
			      2.0*u_priv_d(c,i+2,j+2,k+2,4)*rho_i[c][i+1][j+1][k+1] +
			      u_priv_d(c,i+2,j-1+2,k+2,4)*rho_i[c][i+1][j-1+1][k+1]) -
		    ty2 * ((c1*u_priv_d(c,i+2,j+1+2,k+2,4) - 
			    c2*square[c][i+1][j+1+1][k+1]) * vp1 -
			   (c1*u_priv_d(c,i+2,j-1+2,k+2,4) - 
			    c2*square[c][i+1][j-1+1][k+1]) * vm1);
		}
	    }
	}

      /*--------------------------------------------------------------------
	c      add fourth order eta-direction dissipation         
	c-------------------------------------------------------------------*/
      
#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs() - cell %d - eta_2nd()\n", c);
#endif

      if( startc[c][1] > 0 )
	{
	  j = 1;
	  for (m = 0; m < 5; m++)
	    {
	      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m)- dssp * 
			( 5.0*u_priv_d(c,i+2,j+2,k+2,m) - 4.0*u_priv_d(c,i+2,j+1+2,k+2,m) +
			  u_priv_d(c,i+2,j+2+2,k+2,m));
		    }
		}
	    }

	  j = 2;
	  for (m = 0; m < 5; m++)
	    {
	      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp * 
			(-4.0*u_priv_d(c,i+2,j-1+2,k+2,m) + 6.0*u_priv_d(c,i+2,j+2,k+2,m) -
			 4.0*u_priv_d(c,i+2,j+1+2,k+2,m) + u_priv_d(c,i+2,j+2+2,k+2,m));
		    }
		}
	    }
	}

      for (m = 0; m < 5; m++)
	{
	  for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	    {
	      for (j = 3*startc[c][1]; j < cell_size[c][1]-3*endc[c][1]; j++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp * 
			(  u_priv_d(c,i+2,j-2+2,k+2,m) - 4.0*u_priv_d(c,i+2,j-1+2,k+2,m) + 
			   6.0*u_priv_d(c,i+2,j+2,k+2,m) - 4.0*u_priv_d(c,i+2,j+1+2,k+2,m) + 
			   u_priv_d(c,i+2,j+2+2,k+2,m) );
		    }
		}
	    }
	}
      
      if( endc[c][1] > 0 )
	{
	  j = cell_size[c][1]-3;
	  for (m = 0; m < 5; m++)
	    {
	      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp *
			( u_priv_d(c,i+2,j-2+2,k+2,m) - 4.0*u_priv_d(c,i+2,j-1+2,k+2,m) + 
			  6.0*u_priv_d(c,i+2,j+2,k+2,m) - 4.0*u_priv_d(c,i+2,j+1+2,k+2,m) );
		    }
		}
	    }
	  
	  j = cell_size[c][1]-2;
	  for (m = 0; m < 5; m++)
	    {
	      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp *
			( u_priv_d(c,i+2,j-2+2,k+2,m) - 4.0*u_priv_d(c,i+2,j-1+2,k+2,m) +
			  5.0*u_priv_d(c,i+2,j+2,k+2,m) );
		    }
		}
	    }
	}

      /*--------------------------------------------------------------------
	c      compute zeta-direction fluxes 
	c-------------------------------------------------------------------*/

#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs() - cell %d - zeta()\n", c);
#endif

      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	{
	  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
	    {
	      for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		{
		  wijk = ws[c][i+1][j+1][k+1];
		  wp1  = ws[c][i+1][j+1][k+1+1];
		  wm1  = ws[c][i+1][j+1][k-1+1];
		  
		  rhs_priv_d(c,i+1,j+1,k+1,0) = rhs_priv_d(c,i+1,j+1,k+1,0) + dz1tz1 * 
		    (u_priv_d(c,i+2,j+2,k+1+2,0) - 2.0*u_priv_d(c,i+2,j+2,k+2,0) + 
		     u_priv_d(c,i+2,j+2,k-1+2,0)) -
		    tz2 * (u_priv_d(c,i+2,j+2,k+1+2,3) - u_priv_d(c,i+2,j+2,k-1+2,3));

		  rhs_priv_d(c,i+1,j+1,k+1,1) = rhs_priv_d(c,i+1,j+1,k+1,1) + dz2tz1 * 
		    (u_priv_d(c,i+2,j+2,k+1+2,1) - 2.0*u_priv_d(c,i+2,j+2,k+2,1) + 
		     u_priv_d(c,i+2,j+2,k-1+2,1)) +
		    zzcon2 * (us[c][i+1][j+1][k+1+1] - 2.0*us[c][i+1][j+1][k+1] + 
			      us[c][i+1][j+1][k-1+1]) -
		    tz2 * (u_priv_d(c,i+2,j+2,k+1+2,1)*wp1 - 
			   u_priv_d(c,i+2,j+2,k-1+2,1)*wm1);

		  rhs_priv_d(c,i+1,j+1,k+1,2) = rhs_priv_d(c,i+1,j+1,k+1,2) + dz3tz1 * 
		    (u_priv_d(c,i+2,j+2,k+1+2,2) - 2.0*u_priv_d(c,i+2,j+2,k+2,2) + 
		     u_priv_d(c,i+2,j+2,k-1+2,2)) +
		    zzcon2 * (vs[c][i+1][j+1][k+1+1] - 2.0*vs[c][i+1][j+1][k+1] + 
			      vs[c][i+1][j+1][k-1+1]) -
		    tz2 * (u_priv_d(c,i+2,j+2,k+1+2,2)*wp1 - 
			   u_priv_d(c,i+2,j+2,k-1+2,2)*wm1);

		  rhs_priv_d(c,i+1,j+1,k+1,3) = rhs_priv_d(c,i+1,j+1,k+1,3) + dz4tz1 * 
		    (u_priv_d(c,i+2,j+2,k+1+2,3) - 2.0*u_priv_d(c,i+2,j+2,k+2,3) + 
		     u_priv_d(c,i+2,j+2,k-1+2,3)) +
		    zzcon2*con43 * (wp1 - 2.0*wijk + wm1) -
		    tz2 * (u_priv_d(c,i+2,j+2,k+1+2,3)*wp1 - 
			   u_priv_d(c,i+2,j+2,k-1+2,3)*wm1 +
			   (u_priv_d(c,i+2,j+2,k+1+2,4) - square[c][i+1][j+1][k+1+1] - 
			    u_priv_d(c,i+2,j+2,k-1+2,4) + square[c][i+1][j+1][k-1+1])
			   *c2);

		  rhs_priv_d(c,i+1,j+1,k+1,4) = rhs_priv_d(c,i+1,j+1,k+1,4) + dz5tz1 * 
		    (u_priv_d(c,i+2,j+2,k+1+2,4) - 2.0*u_priv_d(c,i+2,j+2,k+2,4) + 
		     u_priv_d(c,i+2,j+2,k-1+2,4)) +
		    zzcon3 * (qs[c][i+1][j+1][k+1+1] - 2.0*qs[c][i+1][j+1][k+1] + 
			      qs[c][i+1][j+1][k-1+1]) +
		    zzcon4 * (wp1*wp1 - 2.0*wijk*wijk + 
			      wm1*wm1) +
		    zzcon5 * (u_priv_d(c,i+2,j+2,k+1+2,4)*rho_i[c][i+1][j+1][k+1+1] - 
			      2.0*u_priv_d(c,i+2,j+2,k+2,4)*rho_i[c][i+1][j+1][k+1] +
			      u_priv_d(c,i+2,j+2,k-1+2,4)*rho_i[c][i+1][j+1][k-1+1]) -
		    tz2 * ( (c1*u_priv_d(c,i+2,j+2,k+1+2,4) - 
			     c2*square[c][i+1][j+1][k+1+1])*wp1 -
			    (c1*u_priv_d(c,i+2,j+2,k-1+2,4) - 
			     c2*square[c][i+1][j+1][k-1+1])*wm1);
		}
	    }
	}

      /*--------------------------------------------------------------------
	c      add fourth order zeta-direction dissipation                
	c-------------------------------------------------------------------*/
      
#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs() - cell %d - zeta_2nd()\n", c);
#endif
      if( startc[c][2] > 0 )
	{
	  k = 1;
	  for (m = 0; m < 5; m++)
	    {
	      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
		{
		  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m)- dssp * 
			( 5.0*u_priv_d(c,i+2,j+2,k+2,m) - 4.0*u_priv_d(c,i+2,j+2,k+1+2,m) +
			  u_priv_d(c,i+2,j+2,k+2+2,m));
		    }
		}
	    }

	  k = 2;
	  for (m = 0; m < 5; m++)
	    {
	      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
		{
		  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp * 
			(-4.0*u_priv_d(c,i+2,j+2,k-1+2,m) + 6.0*u_priv_d(c,i+2,j+2,k+2,m) -
			 4.0*u_priv_d(c,i+2,j+2,k+1+2,m) + u_priv_d(c,i+2,j+2,k+2+2,m));
		    }
		}
	    }
	}

      for (m = 0; m < 5; m++)
	{
	  for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	    {
	      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		{
		  for (k = 3*startc[c][2]; k < cell_size[c][2]-3*endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp * 
			(  u_priv_d(c,i+2,j+2,k-2+2,m) - 4.0*u_priv_d(c,i+2,j+2,k-1+2,m) + 
			   6.0*u_priv_d(c,i+2,j+2,k+2,m) - 4.0*u_priv_d(c,i+2,j+2,k+1+2,m) + 
			   u_priv_d(c,i+2,j+2,k+2+2,m) );
		    }
		}
	    }
	}
 
      if( endc[c][2] > 0 )
	{
	  k = cell_size[c][2]-3;
	  for (m = 0; m < 5; m++)
	    {
	      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
		{
		  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp *
			( u_priv_d(c,i+2,j+2,k-2+2,m) - 4.0*u_priv_d(c,i+2,j+2,k-1+2,m) + 
			  6.0*u_priv_d(c,i+2,j+2,k+2,m) - 4.0*u_priv_d(c,i+2,j+2,k+1+2,m) );
		    }
		}
	    }
	  
	  k = cell_size[c][2]-2;
	  for (m = 0; m < 5; m++)
	    {
	      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
		{
		  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) - dssp *
			( u_priv_d(c,i+2,j+2,k-2+2,m) - 4.0*u_priv_d(c,i+2,j+2,k-1+2,m) +
			  5.0*u_priv_d(c,i+2,j+2,k+2,m) );
		    }
		}
	    }
	}

#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs() - cell %d - finalize()\n", c);
#endif
      for (m = 0; m < 5; m++)
	{
	  for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	    {
	      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m) * dt;
		    }
		}
	    }
	}
    }
}



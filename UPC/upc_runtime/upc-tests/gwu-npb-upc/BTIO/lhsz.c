/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"
 
void lhsz(int c)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  int i, j, k;
  
  /*--------------------------------------------------------------------
    c This function computes the left hand side for the three z-factors
    c-------------------------------------------------------------------*/
  
  /*--------------------------------------------------------------------
    c treat only cell c
    c-------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c Compute the indices for storing the tri-diagonal matrix;
    c determine a (labeled f) and n jacobians for cell c
    c-------------------------------------------------------------------*/

  for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
    {
      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
	{
	  for (k = startc[c][2]-1; k <= cell_size[c][2]-endc[c][2]; k++)
	    {
	      tmp1 = 1.0 / u_priv_d(c,i+2,j+2,k+2,0);
	      tmp2 = tmp1 * tmp1;
	      tmp3 = tmp1 * tmp2;

	      fjac[i+2][j+2][k+2][0][0] = 0.0;
	      fjac[i+2][j+2][k+2][1][0] = 0.0;
	      fjac[i+2][j+2][k+2][2][0] = 0.0;
	      fjac[i+2][j+2][k+2][3][0] = 1.0;
	      fjac[i+2][j+2][k+2][4][0] = 0.0;

	      fjac[i+2][j+2][k+2][0][1] = - ( u_priv_d(c,i+2,j+2,k+2,1)*u_priv_d(c,i+2,j+2,k+2,3) ) 
		* tmp2;
	      fjac[i+2][j+2][k+2][1][1] = u_priv_d(c,i+2,j+2,k+2,3) * tmp1;
	      fjac[i+2][j+2][k+2][2][1] = 0.0;
	      fjac[i+2][j+2][k+2][3][1] = u_priv_d(c,i+2,j+2,k+2,1) * tmp1;
	      fjac[i+2][j+2][k+2][4][1] = 0.0;

	      fjac[i+2][j+2][k+2][0][2] = - ( u_priv_d(c,i+2,j+2,k+2,2)*u_priv_d(c,i+2,j+2,k+2,3) )
		* tmp2;
	      fjac[i+2][j+2][k+2][1][2] = 0.0;
	      fjac[i+2][j+2][k+2][2][2] = u_priv_d(c,i+2,j+2,k+2,3) * tmp1;
	      fjac[i+2][j+2][k+2][3][2] = u_priv_d(c,i+2,j+2,k+2,2) * tmp1;
	      fjac[i+2][j+2][k+2][4][2] = 0.0;

	      fjac[i+2][j+2][k+2][0][3] = - (u_priv_d(c,i+2,j+2,k+2,3)*u_priv_d(c,i+2,j+2,k+2,3) * tmp2 ) 
		+ 0.50 * c2 * ( (  u_priv_d(c,i+2,j+2,k+2,1) * u_priv_d(c,i+2,j+2,k+2,1)
				   + u_priv_d(c,i+2,j+2,k+2,2) * u_priv_d(c,i+2,j+2,k+2,2)
				   + u_priv_d(c,i+2,j+2,k+2,3) * u_priv_d(c,i+2,j+2,k+2,3) ) * tmp2 );
	      fjac[i+2][j+2][k+2][1][3] = - c2 *  u_priv_d(c,i+2,j+2,k+2,1) * tmp1;
	      fjac[i+2][j+2][k+2][2][3] = - c2 *  u_priv_d(c,i+2,j+2,k+2,2) * tmp1;
	      fjac[i+2][j+2][k+2][3][3] = ( 2.0 - c2 )
		*  u_priv_d(c,i+2,j+2,k+2,3) * tmp1;
	      fjac[i+2][j+2][k+2][4][3] = c2;

	      fjac[i+2][j+2][k+2][0][4] = ( c2 * (  u_priv_d(c,i+2,j+2,k+2,1) * u_priv_d(c,i+2,j+2,k+2,1)
						    + u_priv_d(c,i+2,j+2,k+2,2) * u_priv_d(c,i+2,j+2,k+2,2)
						    + u_priv_d(c,i+2,j+2,k+2,3) * u_priv_d(c,i+2,j+2,k+2,3) )
					    * tmp2
					    - c1 * ( u_priv_d(c,i+2,j+2,k+2,4) * tmp1 ) )
		* ( u_priv_d(c,i+2,j+2,k+2,3) * tmp1 );
	      fjac[i+2][j+2][k+2][1][4] = - c2 * ( u_priv_d(c,i+2,j+2,k+2,1)*u_priv_d(c,i+2,j+2,k+2,3) )
		* tmp2;
	      fjac[i+2][j+2][k+2][2][4] = - c2 * ( u_priv_d(c,i+2,j+2,k+2,2)*u_priv_d(c,i+2,j+2,k+2,3) )
		* tmp2;
	      fjac[i+2][j+2][k+2][3][4] = c1 * ( u_priv_d(c,i+2,j+2,k+2,4) * tmp1 )
		- 0.50 * c2
		* ( (  u_priv_d(c,i+2,j+2,k+2,1)*u_priv_d(c,i+2,j+2,k+2,1)
		       + u_priv_d(c,i+2,j+2,k+2,2)*u_priv_d(c,i+2,j+2,k+2,2)
		       + 3.0*u_priv_d(c,i+2,j+2,k+2,3)*u_priv_d(c,i+2,j+2,k+2,3) )
		    * tmp2 );
	      fjac[i+2][j+2][k+2][4][4] = c1 * u_priv_d(c,i+2,j+2,k+2,3) * tmp1;

	      njac[i+2][j+2][k+2][0][0] = 0.0;
	      njac[i+2][j+2][k+2][1][0] = 0.0;
	      njac[i+2][j+2][k+2][2][0] = 0.0;
	      njac[i+2][j+2][k+2][3][0] = 0.0;
	      njac[i+2][j+2][k+2][4][0] = 0.0;

	      njac[i+2][j+2][k+2][0][1] = - c3c4 * tmp2 * u_priv_d(c,i+2,j+2,k+2,1);
	      njac[i+2][j+2][k+2][1][1] =   c3c4 * tmp1;
	      njac[i+2][j+2][k+2][2][1] =   0.0;
	      njac[i+2][j+2][k+2][3][1] =   0.0;
	      njac[i+2][j+2][k+2][4][1] =   0.0;

	      njac[i+2][j+2][k+2][0][2] = - c3c4 * tmp2 * u_priv_d(c,i+2,j+2,k+2,2);
	      njac[i+2][j+2][k+2][1][2] =   0.0;
	      njac[i+2][j+2][k+2][2][2] =   c3c4 * tmp1;
	      njac[i+2][j+2][k+2][3][2] =   0.0;
	      njac[i+2][j+2][k+2][4][2] =   0.0;

	      njac[i+2][j+2][k+2][0][3] = - con43 * c3c4 * tmp2 * u_priv_d(c,i+2,j+2,k+2,3);
	      njac[i+2][j+2][k+2][1][3] =   0.0;
	      njac[i+2][j+2][k+2][2][3] =   0.0;
	      njac[i+2][j+2][k+2][3][3] =   con43 * c3 * c4 * tmp1;
	      njac[i+2][j+2][k+2][4][3] =   0.0;

	      njac[i+2][j+2][k+2][0][4] = - (  c3c4
					       - c1345 ) * tmp3 * (pow2(u_priv_d(c,i+2,j+2,k+2,1)))
		- ( c3c4 - c1345 ) * tmp3 * (pow2(u_priv_d(c,i+2,j+2,k+2,2)))
		- ( con43 * c3c4
		    - c1345 ) * tmp3 * (pow2(u_priv_d(c,i+2,j+2,k+2,3)))
		- c1345 * tmp2 * u_priv_d(c,i+2,j+2,k+2,4);

	      njac[i+2][j+2][k+2][1][4] = (  c3c4 - c1345 ) * tmp2 * u_priv_d(c,i+2,j+2,k+2,1);
	      njac[i+2][j+2][k+2][2][4] = (  c3c4 - c1345 ) * tmp2 * u_priv_d(c,i+2,j+2,k+2,2);
	      njac[i+2][j+2][k+2][3][4] = ( con43 * c3c4
					    - c1345 ) * tmp2 * u_priv_d(c,i+2,j+2,k+2,3);
	      njac[i+2][j+2][k+2][4][4] = ( c1345 )* tmp1;
	    }
	}
    }

  /*--------------------------------------------------------------------
    c now jacobians set, so form left hand side in z direction
    c-------------------------------------------------------------------*/

  for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
    {
      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
	{
	  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
	    {
	      tmp1 = dt * tz1;
	      tmp2 = dt * tz2;

	      lhs_priv_d(c,i+1,j+1,k+1,AA,0,0) = - tmp2 * fjac[i+2][j+2][k-1+2][0][0]
		- tmp1 * njac[i+2][j+2][k-1+2][0][0]
		- tmp1 * dz1;
	      lhs_priv_d(c,i+1,j+1,k+1,AA,1,0) = - tmp2 * fjac[i+2][j+2][k-1+2][1][0]
		- tmp1 * njac[i+2][j+2][k-1+2][1][0];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,2,0) = - tmp2 * fjac[i+2][j+2][k-1+2][2][0]
		- tmp1 * njac[i+2][j+2][k-1+2][2][0];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,3,0) = - tmp2 * fjac[i+2][j+2][k-1+2][3][0]
		- tmp1 * njac[i+2][j+2][k-1+2][3][0];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,4,0) = - tmp2 * fjac[i+2][j+2][k-1+2][4][0]
		- tmp1 * njac[i+2][j+2][k-1+2][4][0];

	      lhs_priv_d(c,i+1,j+1,k+1,AA,0,1) = - tmp2 * fjac[i+2][j+2][k-1+2][0][1]
		- tmp1 * njac[i+2][j+2][k-1+2][0][1];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,1,1) = - tmp2 * fjac[i+2][j+2][k-1+2][1][1]
		- tmp1 * njac[i+2][j+2][k-1+2][1][1]
		- tmp1 * dz2;
	      lhs_priv_d(c,i+1,j+1,k+1,AA,2,1) = - tmp2 * fjac[i+2][j+2][k-1+2][2][1]
		- tmp1 * njac[i+2][j+2][k-1+2][2][1];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,3,1) = - tmp2 * fjac[i+2][j+2][k-1+2][3][1]
		- tmp1 * njac[i+2][j+2][k-1+2][3][1];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,4,1) = - tmp2 * fjac[i+2][j+2][k-1+2][4][1]
		- tmp1 * njac[i+2][j+2][k-1+2][4][1];

	      lhs_priv_d(c,i+1,j+1,k+1,AA,0,2) = - tmp2 * fjac[i+2][j+2][k-1+2][0][2]
		- tmp1 * njac[i+2][j+2][k-1+2][0][2];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,1,2) = - tmp2 * fjac[i+2][j+2][k-1+2][1][2]
		- tmp1 * njac[i+2][j+2][k-1+2][1][2];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,2,2) = - tmp2 * fjac[i+2][j+2][k-1+2][2][2]
		- tmp1 * njac[i+2][j+2][k-1+2][2][2]
		- tmp1 * dz3;
	      lhs_priv_d(c,i+1,j+1,k+1,AA,3,2) = - tmp2 * fjac[i+2][j+2][k-1+2][3][2]
		- tmp1 * njac[i+2][j+2][k-1+2][3][2];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,4,2) = - tmp2 * fjac[i+2][j+2][k-1+2][4][2]
		- tmp1 * njac[i+2][j+2][k-1+2][4][2];

	      lhs_priv_d(c,i+1,j+1,k+1,AA,0,3) = - tmp2 * fjac[i+2][j+2][k-1+2][0][3]
		- tmp1 * njac[i+2][j+2][k-1+2][0][3];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,1,3) = - tmp2 * fjac[i+2][j+2][k-1+2][1][3]
		- tmp1 * njac[i+2][j+2][k-1+2][1][3];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,2,3) = - tmp2 * fjac[i+2][j+2][k-1+2][2][3]
		- tmp1 * njac[i+2][j+2][k-1+2][2][3];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,3,3) = - tmp2 * fjac[i+2][j+2][k-1+2][3][3]
		- tmp1 * njac[i+2][j+2][k-1+2][3][3]
		- tmp1 * dz4;
	      lhs_priv_d(c,i+1,j+1,k+1,AA,4,3) = - tmp2 * fjac[i+2][j+2][k-1+2][4][3]
		- tmp1 * njac[i+2][j+2][k-1+2][4][3];

	      lhs_priv_d(c,i+1,j+1,k+1,AA,0,4) = - tmp2 * fjac[i+2][j+2][k-1+2][0][4]
		- tmp1 * njac[i+2][j+2][k-1+2][0][4];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,1,4) = - tmp2 * fjac[i+2][j+2][k-1+2][1][4]
		- tmp1 * njac[i+2][j+2][k-1+2][1][4];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,2,4) = - tmp2 * fjac[i+2][j+2][k-1+2][2][4]
		- tmp1 * njac[i+2][j+2][k-1+2][2][4];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,3,4) = - tmp2 * fjac[i+2][j+2][k-1+2][3][4]
		- tmp1 * njac[i+2][j+2][k-1+2][3][4];
	      lhs_priv_d(c,i+1,j+1,k+1,AA,4,4) = - tmp2 * fjac[i+2][j+2][k-1+2][4][4]
		- tmp1 * njac[i+2][j+2][k-1+2][4][4]
		- tmp1 * dz5;

	      lhs_priv_d(c,i+1,j+1,k+1,BB,0,0) = 1.0
		+ tmp1 * 2.0 * njac[i+2][j+2][k+2][0][0]
		+ tmp1 * 2.0 * dz1;
	      lhs_priv_d(c,i+1,j+1,k+1,BB,1,0) = tmp1 * 2.0 * njac[i+2][j+2][k+2][1][0];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,2,0) = tmp1 * 2.0 * njac[i+2][j+2][k+2][2][0];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,3,0) = tmp1 * 2.0 * njac[i+2][j+2][k+2][3][0];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,4,0) = tmp1 * 2.0 * njac[i+2][j+2][k+2][4][0];

	      lhs_priv_d(c,i+1,j+1,k+1,BB,0,1) = tmp1 * 2.0 * njac[i+2][j+2][k+2][0][1];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,1,1) = 1.0
		+ tmp1 * 2.0 * njac[i+2][j+2][k+2][1][1]
		+ tmp1 * 2.0 * dz2;
	      lhs_priv_d(c,i+1,j+1,k+1,BB,2,1) = tmp1 * 2.0 * njac[i+2][j+2][k+2][2][1];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,3,1) = tmp1 * 2.0 * njac[i+2][j+2][k+2][3][1];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,4,1) = tmp1 * 2.0 * njac[i+2][j+2][k+2][4][1];

	      lhs_priv_d(c,i+1,j+1,k+1,BB,0,2) = tmp1 * 2.0 * njac[i+2][j+2][k+2][0][2];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,1,2) = tmp1 * 2.0 * njac[i+2][j+2][k+2][1][2];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,2,2) = 1.0
		+ tmp1 * 2.0 * njac[i+2][j+2][k+2][2][2]
		+ tmp1 * 2.0 * dz3;
	      lhs_priv_d(c,i+1,j+1,k+1,BB,3,2) = tmp1 * 2.0 * njac[i+2][j+2][k+2][3][2];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,4,2) = tmp1 * 2.0 * njac[i+2][j+2][k+2][4][2];

	      lhs_priv_d(c,i+1,j+1,k+1,BB,0,3) = tmp1 * 2.0 * njac[i+2][j+2][k+2][0][3];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,1,3) = tmp1 * 2.0 * njac[i+2][j+2][k+2][1][3];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,2,3) = tmp1 * 2.0 * njac[i+2][j+2][k+2][2][3];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,3,3) = 1.0
		+ tmp1 * 2.0 * njac[i+2][j+2][k+2][3][3]
		+ tmp1 * 2.0 * dz4;
	      lhs_priv_d(c,i+1,j+1,k+1,BB,4,3) = tmp1 * 2.0 * njac[i+2][j+2][k+2][4][3];

	      lhs_priv_d(c,i+1,j+1,k+1,BB,0,4) = tmp1 * 2.0 * njac[i+2][j+2][k+2][0][4];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,1,4) = tmp1 * 2.0 * njac[i+2][j+2][k+2][1][4];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,2,4) = tmp1 * 2.0 * njac[i+2][j+2][k+2][2][4];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,3,4) = tmp1 * 2.0 * njac[i+2][j+2][k+2][3][4];
	      lhs_priv_d(c,i+1,j+1,k+1,BB,4,4) = 1.0
		+ tmp1 * 2.0 * njac[i+2][j+2][k+2][4][4]
		+ tmp1 * 2.0 * dz5;

	      lhs_priv_d(c,i+1,j+1,k+1,CC,0,0) =  tmp2 * fjac[i+2][j+2][k+1+2][0][0]
		- tmp1 * njac[i+2][j+2][k+1+2][0][0]
		- tmp1 * dz1;
	      lhs_priv_d(c,i+1,j+1,k+1,CC,1,0) =  tmp2 * fjac[i+2][j+2][k+1+2][1][0]
		- tmp1 * njac[i+2][j+2][k+1+2][1][0];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,2,0) =  tmp2 * fjac[i+2][j+2][k+1+2][2][0]
		- tmp1 * njac[i+2][j+2][k+1+2][2][0];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,3,0) =  tmp2 * fjac[i+2][j+2][k+1+2][3][0]
		- tmp1 * njac[i+2][j+2][k+1+2][3][0];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,4,0) =  tmp2 * fjac[i+2][j+2][k+1+2][4][0]
		- tmp1 * njac[i+2][j+2][k+1+2][4][0];

	      lhs_priv_d(c,i+1,j+1,k+1,CC,0,1) =  tmp2 * fjac[i+2][j+2][k+1+2][0][1]
		- tmp1 * njac[i+2][j+2][k+1+2][0][1];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,1,1) =  tmp2 * fjac[i+2][j+2][k+1+2][1][1]
		- tmp1 * njac[i+2][j+2][k+1+2][1][1]
		- tmp1 * dz2;
	      lhs_priv_d(c,i+1,j+1,k+1,CC,2,1) =  tmp2 * fjac[i+2][j+2][k+1+2][2][1]
		- tmp1 * njac[i+2][j+2][k+1+2][2][1];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,3,1) =  tmp2 * fjac[i+2][j+2][k+1+2][3][1]
		- tmp1 * njac[i+2][j+2][k+1+2][3][1];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,4,1) =  tmp2 * fjac[i+2][j+2][k+1+2][4][1]
		- tmp1 * njac[i+2][j+2][k+1+2][4][1];

	      lhs_priv_d(c,i+1,j+1,k+1,CC,0,2) =  tmp2 * fjac[i+2][j+2][k+1+2][0][2]
		- tmp1 * njac[i+2][j+2][k+1+2][0][2];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,1,2) =  tmp2 * fjac[i+2][j+2][k+1+2][1][2]
		- tmp1 * njac[i+2][j+2][k+1+2][1][2];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,2,2) =  tmp2 * fjac[i+2][j+2][k+1+2][2][2]
		- tmp1 * njac[i+2][j+2][k+1+2][2][2]
		- tmp1 * dz3;
	      lhs_priv_d(c,i+1,j+1,k+1,CC,3,2) =  tmp2 * fjac[i+2][j+2][k+1+2][3][2]
		- tmp1 * njac[i+2][j+2][k+1+2][3][2];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,4,2) =  tmp2 * fjac[i+2][j+2][k+1+2][4][2]
		- tmp1 * njac[i+2][j+2][k+1+2][4][2];

	      lhs_priv_d(c,i+1,j+1,k+1,CC,0,3) =  tmp2 * fjac[i+2][j+2][k+1+2][0][3]
		- tmp1 * njac[i+2][j+2][k+1+2][0][3];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,1,3) =  tmp2 * fjac[i+2][j+2][k+1+2][1][3]
		- tmp1 * njac[i+2][j+2][k+1+2][1][3];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,2,3) =  tmp2 * fjac[i+2][j+2][k+1+2][2][3]
		- tmp1 * njac[i+2][j+2][k+1+2][2][3];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,3,3) =  tmp2 * fjac[i+2][j+2][k+1+2][3][3]
		- tmp1 * njac[i+2][j+2][k+1+2][3][3]
		- tmp1 * dz4;
	      lhs_priv_d(c,i+1,j+1,k+1,CC,4,3) =  tmp2 * fjac[i+2][j+2][k+1+2][4][3]
		- tmp1 * njac[i+2][j+2][k+1+2][4][3];

	      lhs_priv_d(c,i+1,j+1,k+1,CC,0,4) =  tmp2 * fjac[i+2][j+2][k+1+2][0][4]
		- tmp1 * njac[i+2][j+2][k+1+2][0][4];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,1,4) =  tmp2 * fjac[i+2][j+2][k+1+2][1][4]
		- tmp1 * njac[i+2][j+2][k+1+2][1][4];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,2,4) =  tmp2 * fjac[i+2][j+2][k+1+2][2][4]
		- tmp1 * njac[i+2][j+2][k+1+2][2][4];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,3,4) =  tmp2 * fjac[i+2][j+2][k+1+2][3][4]
		- tmp1 * njac[i+2][j+2][k+1+2][3][4];
	      lhs_priv_d(c,i+1,j+1,k+1,CC,4,4) =  tmp2 * fjac[i+2][j+2][k+1+2][4][4]
		- tmp1 * njac[i+2][j+2][k+1+2][4][4]
		- tmp1 * dz5;
	    }
	}
    }
}



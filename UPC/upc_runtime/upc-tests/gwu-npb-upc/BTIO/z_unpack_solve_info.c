/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void z_unpack_solve_info( int c, int c2 )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c Unpack C'(-1) and rhs'(-1) for
    c all i and j
    --------------------------------------------------------------------*/
  int i, j, kstart;

  kstart = 0;
  
  rhs_th_arr = (shared [] double *)&rhs[predecessor[2]].local[0][0][0][0][0];
  lhs_th_arr = (shared [] double *)&lhs[predecessor[2]].local[0][0][0][0][0][0][0];

  upc_wait;

  for( i=0; i<IMAX; i++ )
    {
      for( j=0; j<JMAX; j++ )
	{
	  /*
	  upc_memget(&lhs_priv->local[c][i+1][j+1][kstart-1+1][CC][0][0],
		     &lhs[predecessor[2]].local[c2][i+1][j+1][sh_cell_size[predecessor[2]][c2][2]][CC][0][0],
		     sizeof(double)* BLOCK_SIZE * BLOCK_SIZE);
 
	  upc_memget(&rhs_priv->local[c][i+1][j+1][kstart-1+1][0],
		     &rhs[predecessor[2]].local[c2][i+1][j+1][sh_cell_size[predecessor[2]][c2][2]][0],
		     sizeof(double)* BLOCK_SIZE);
	  */
	  upc_memget(&lhs_priv_d(c,i+1,j+1,kstart,CC,0,0),
		     &lhs_th_d(c2,i+1,j+1,sh_cell_size[predecessor[2]][c2][2],CC,0,0),
		     sizeof(double)* BLOCK_SIZE * BLOCK_SIZE);
 
	  upc_memget(&rhs_priv_d(c,i+1,j+1,kstart,0),
		     &rhs_th_d(c2,i+1,j+1,sh_cell_size[predecessor[2]][c2][2],0),
		     sizeof(double)* BLOCK_SIZE);
	}
    }

  upc_notify;
}


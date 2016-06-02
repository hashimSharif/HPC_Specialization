/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void y_unpack_solve_info( int c, int c2 )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c Unpack C'(-1) and rhs'(-1) for
    c all i and k
    --------------------------------------------------------------------*/
  int i, k, jstart;

  jstart = 0;
  rhs_th_arr = (shared [] double *)&rhs[predecessor[1]].local[0][0][0][0][0];
  lhs_th_arr = (shared [] double *)&lhs[predecessor[1]].local[0][0][0][0][0][0][0];

  upc_wait;

  for( i=0; i<IMAX; i++ )
    {
      for( k=0; k<KMAX; k++ )
	{
	  /*
	  upc_memget(&lhs_priv->local[c][i+1][jstart-1+1][k+1][CC][0][0],
		     &lhs[predecessor[1]].local[c2][i+1][sh_cell_size[predecessor[1]][c2][1]][k+1][CC][0][0],
		     sizeof(double)* BLOCK_SIZE * BLOCK_SIZE);
	  */
	  upc_memget(&lhs_priv_d(c,i+1,jstart-1+1,k+1,CC,0,0),
		     &lhs_th_d(c2,i+1,sh_cell_size[predecessor[1]][c2][1],k+1,CC,0,0),
		     sizeof(double)* BLOCK_SIZE * BLOCK_SIZE);	  
	}	 

      /*
      upc_memget(&rhs_priv->local[c][i+1][jstart-1+1][1][0],
		 &rhs[predecessor[1]].local[c2][i+1][sh_cell_size[predecessor[1]][c2][1]][1][0],
		 (sizeof(double)) * BLOCK_SIZE * KMAX);	
      */
      upc_memget(&rhs_priv_d(c,i+1,jstart-1+1,1,0),
		 &rhs_th_d(c2,i+1,sh_cell_size[predecessor[1]][c2][1],1,0),
		 (sizeof(double)) * BLOCK_SIZE * KMAX);	
    }

  upc_notify;
}

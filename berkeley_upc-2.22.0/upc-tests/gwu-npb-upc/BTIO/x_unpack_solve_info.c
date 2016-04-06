/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void x_unpack_solve_info( int c, int stage, int c2 )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c Unpack C'(-1) and rhs'(-1) for
    c all j and k
    --------------------------------------------------------------------*/
  int j, k, istart;
  istart = 0;

  rhs_th_arr = (shared [] double *)&rhs[predecessor[0]].local[0][0][0][0][0];
  lhs_th_arr = (shared [] double *)&lhs[predecessor[0]].local[0][0][0][0][0][0][0];
 
  upc_wait;
  //upc_barrier;

  for( j=0; j<JMAX; j++ )
    {
      for( k=0; k<KMAX; k++ )
	{
	  /*
	  upc_memget(&lhs_priv_d(c,istart-1+1,j+1,k+1,CC,0,0),
		     &lhs[predecessor[0]].local[c2][sh_cell_size[predecessor[0]][c2][0]][j+1][k+1][CC][0][0],
		     sizeof(double)* BLOCK_SIZE * BLOCK_SIZE);
	  */
	  upc_memget(&lhs_priv_d(c,istart-1+1,j+1,k+1,CC,0,0),
		     &lhs_th_d(c2,sh_cell_size[predecessor[0]][c2][0],j+1,k+1,CC,0,0),
		     sizeof(double)* BLOCK_SIZE * BLOCK_SIZE);	  
	}
    }
  
  for( j=0; j<JMAX; j++ )
    {
      /*
      upc_memget(&rhs_priv_d(c,istart-1+1,j+1,1,0),
		 &rhs[predecessor[0]].local[c2][sh_cell_size[predecessor[0]][c2][0]][j+1][1][0],
		 (sizeof(double))* BLOCK_SIZE * KMAX );
      */
      upc_memget(&rhs_priv_d(c,istart-1+1,j+1,1,0),
		 &rhs_th_d(c2,sh_cell_size[predecessor[0]][c2][0],j+1,1,0),
		 (sizeof(double))* BLOCK_SIZE * KMAX );
    }

  //printf("TH%02d: notify\n", MYTHREAD );
  upc_notify; /* wait in x_solve_cell() for i=isize-last */
}


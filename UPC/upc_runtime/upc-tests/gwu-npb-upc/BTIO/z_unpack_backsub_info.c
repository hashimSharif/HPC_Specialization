/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void z_unpack_backsub_info( int c, int c2 )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c unpack U(ksize) for
    c all i and j
    --------------------------------------------------------------------*/
  int j, i;

  rhs_th_arr = (shared [] double *)&rhs[successor[2]].local[0][0][0][0][0];

  upc_barrier;
  for( i=0; i<IMAX; i++ )
    {
      for( j=0; j<JMAX; j++ )
	{
	  /*
	  upc_memget( &backsub_info_priv_d(c,i,j,0), 
		    &rhs[successor[2]].local[c2][1+i][j+1][1][0], 
		    (sizeof(double)) * BLOCK_SIZE );
	  */
	  upc_memget( &backsub_info_priv_d(c,i,j,0), 
		      &rhs_th_d(c2,1+i,j+1,1,0), 
		      (sizeof(double)) * BLOCK_SIZE );
	}
    }
  upc_notify;
}

/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void x_unpack_backsub_info( int c, int c2 )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c unpack U(isize) for
    c all j and k
    --------------------------------------------------------------------*/
  int j;

  rhs_th_arr = (shared [] double *)&rhs[successor[0]].local[0][0][0][0][0];
  upc_barrier;

  for( j=0; j<JMAX; j++ )
    {
      /*
      upc_memget(&backsub_info_priv_d(c,j,0,0), 
		 &rhs[successor[0]].local[c][1][j+1][1][0], 
		 (sizeof(double)) * BLOCK_SIZE * KMAX );
      */
      upc_memget(&backsub_info_priv_d(c,j,0,0), 
		 &rhs_th_d(c,1,j+1,1,0), 
		 (sizeof(double)) * BLOCK_SIZE * KMAX );
    }
    
  upc_notify;
}

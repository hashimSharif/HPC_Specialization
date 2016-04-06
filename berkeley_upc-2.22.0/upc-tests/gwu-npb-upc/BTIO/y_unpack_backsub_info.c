/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void y_unpack_backsub_info( int c, int c2 )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c unpack U(jsize) for
    c all i and k
    --------------------------------------------------------------------*/
  int i;

  rhs_th_arr = (shared [] double *)&rhs[successor[1]].local[0][0][0][0][0];

  upc_barrier;
  for( i=0; i<IMAX; i++ )
    {
      /*
	upc_memget( &backsub_info_priv_d(c,i,0,0), 
	&rhs[successor[1]].local[c][i+1][1][1][0],
	(sizeof(double)) * BLOCK_SIZE * KMAX );
      */
      upc_memget( &backsub_info_priv_d(c,i,0,0), 
		  &rhs_th_d(c,i+1,1,1,0),
		  (sizeof(double)) * BLOCK_SIZE * KMAX );
    }

  upc_notify;
  //upc_barrier;
}

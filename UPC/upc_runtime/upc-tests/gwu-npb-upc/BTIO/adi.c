/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void adi(void)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) copy_faces()\n");
#endif
  copy_faces();
  
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) x_solve()\n");
#endif
  x_solve();

#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) y_solve()\n");
#endif
  y_solve();

#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) z_solve()\n");
#endif
  z_solve();

#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) add()\n");
#endif
  add();
}

/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void x_solve(void)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c 
    c Performs line solves in X direction by first factoring
    c the block-tridiagonal matrix into an upper triangular matrix,
    c and then performing back substitution to solve for the unknown
    c vectors of each line.
    c 
    c Make sure we treat elements zero to cell_size in the direction
    c of the sweep.
    c 
    --------------------------------------------------------------------*/

  int c, istart, stage, first, last, isize, jsize, ksize;
  int c2;
  
  /*--------------------------------------------------------------------
    c in our terminology stage is the number of the cell in the x-direction
    c i.e. stage = 1 means the start of the line stage=ncells means end
    c-------------------------------------------------------------------*/
  istart = 0;
  for( stage=1; stage<=ncells; stage ++ )
    {
      c = slice[stage-1][0];

      isize = cell_size[c][0] - 1;
      jsize = cell_size[c][1] - 1;
      ksize = cell_size[c][2] - 1;

      /*--------------------------------------------------------------------
	c set last-cell flag
	c-------------------------------------------------------------------*/
      
      if( stage == ncells )
	last = 1;
      else
	last = 0;

      if( stage == 1 )
	{
	  /*--------------------------------------------------------------------
	    c This is the first cell, so solve without receiving data
	    c-------------------------------------------------------------------*/
	  first = 1;
#if( DEBUG == TRUE )
	  if( MYTHREAD == 0 )
	    printf(" (D) x_solve() - cell %d - 1st stage - lhsx()\n", c);
#endif

	  lhsx( c );

#if( DEBUG == TRUE )
	  if( MYTHREAD == 0 )
	    printf(" (D) x_solve() - cell %d - 1st stage - x_solve_cell()\n", c);
#endif
	  //upc_notify;
	  
	  x_solve_cell( first, last, c );
	}
      else
	{
	  /*--------------------------------------------------------------------
	    c Not the first cell of this line, so receive info from
	    c processor working on preceeding cell
	    c-------------------------------------------------------------------*/
	  upc_notify;
	  first = 0;

	  /*--------------------------------------------------------------------
	    c Overlap computations and communications
	    c-------------------------------------------------------------------*/
#if( DEBUG == TRUE )
	  if( MYTHREAD == 0 )
	    printf(" (D) x_solve() - cell %d - lhsx()\n", c);
#endif
	  lhsx( c );

	  /*--------------------------------------------------------------------
	    c wait for completion
	    c-------------------------------------------------------------------*/
	  //upc_wait;
	  /*--------------------------------------------------------------------
	    c install C'(istart) and rhs'(istart) to be used in this cell
	    c-------------------------------------------------------------------*/
#if( DEBUG == TRUE )
	  if( MYTHREAD == 0 )
	    printf(" (D) x_solve() - cell %d - x_unpack_solve_info()\n", c);
#endif
	  c2=sh_slice[predecessor[0]][stage-2][0];
	  x_unpack_solve_info( c , stage, c2 );

	  //upc_notify;
#if( DEBUG == TRUE )
	  if( MYTHREAD == 0 )
	    printf(" (D) x_solve() - cell %d - x_solve_cell()\n", c);
#endif
	  x_solve_cell( first, last, c );
	}
    }

  //  upc_notify;
  /*--------------------------------------------------------------------
    c Now perform backsubstitution in reverse direction
    c-------------------------------------------------------------------*/
  for( stage=ncells; stage>0; stage-- )
    {
      c = slice[stage-1][0];
      isize = cell_size[c][0] - 1;
      jsize = cell_size[c][1] - 1;
      ksize = cell_size[c][2] - 1;
  
      if( stage == 1 )
	first = 1;
      else
	first = 0;

      if( stage == ncells )
	{
	  last = 1;
	  /*--------------------------------------------------------------------
	    c last cell, so perform back substitute without waiting
	    c-------------------------------------------------------------------*/
#if( DEBUG == TRUE )
	  if( MYTHREAD == 0 )
	    printf(" (D) x_solve() - cell %d - x_backsubstitute()\n", c);
#endif
	  x_backsubstitute( first, last, c );
	}
      else
	{
	  last = 0;
	  //upc_wait;
#if( DEBUG == TRUE )
	  if( MYTHREAD == 0 )
	    printf(" (D) x_solve() - cell %d - x_unpack_backsub_info()\n", c);
#endif
	  c2 = sh_slice[successor[0]][stage][0];
	  x_unpack_backsub_info( c, c2 );
	  //upc_notify;
#if( DEBUG == TRUE )
	  if( MYTHREAD == 0 )
	    printf(" (D) x_solve() - cell %d - x_backsubstitute()\n", c);
#endif
	  x_backsubstitute( first, last, c );
	}
    }
}

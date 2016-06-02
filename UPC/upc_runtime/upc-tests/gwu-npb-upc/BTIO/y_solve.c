/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void y_solve(void)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c 
    c Performs line solves in Y direction by first factoring
    c the block-tridiagonal matrix into an upper triangular matrix,
    c and then performing back substitution to solve for the unknown
    c vectors of each line.
    c 
    c Make sure we treat elements zero to cell_size in the direction
    c of the sweep.
    c 
    --------------------------------------------------------------------*/

  int c, c2, jstart, stage, first, last, isize, jsize, ksize;
  
  /*--------------------------------------------------------------------
    c in our terminology stage is the number of the cell in the y-direction
    c i.e. stage = 1 means the start of the line stage=ncells means end
    c-------------------------------------------------------------------*/
  jstart = 0;
  for( stage=1; stage<=ncells; stage ++ )
    {
      c = slice[stage-1][1];
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
	  lhsy( c );
	  y_solve_cell( first, last, c );
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
	  lhsy( c );

	  /*--------------------------------------------------------------------
	    c wait for completion
	    c-------------------------------------------------------------------*/
	  //upc_wait;
	  /*--------------------------------------------------------------------
	    c install C'(jstart+1) and rhs'(jstart+1) to be used in this cell
	    c-------------------------------------------------------------------*/
	  c2 = sh_slice[predecessor[1]][stage-2][1];
	  y_unpack_solve_info( c, c2 );
	  //upc_notify;
	  y_solve_cell( first, last, c );
	}
    }

  /*--------------------------------------------------------------------
    c Now perform backsubstitution in reverse direction
    c-------------------------------------------------------------------*/
  for( stage=ncells; stage>0; stage-- )
    {
      c = slice[stage-1][1];
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
	  y_backsubstitute( first, last, c );
	}
      else
	{
	  last = 0;
	  //upc_wait;
	  c2 = sh_slice[successor[1]][stage][1];
	  y_unpack_backsub_info( c, c2 );
	  //upc_notify;
	  y_backsubstitute( first, last, c );
	}
    }
}


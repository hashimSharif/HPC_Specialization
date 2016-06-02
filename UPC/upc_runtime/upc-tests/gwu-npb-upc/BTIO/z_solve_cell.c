/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void z_solve_cell( int first, int last, int c )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c performs guassian elimination on this cell
    c 
    c assumes that unpacking routines for non-first cells
    c preload C' and rhs' from previous cell.
    c 
    c assumed send happens outside this routine, but that
    c c'(KMAX) and rhs'(KMAX) will be sent to next cell
    --------------------------------------------------------------------*/
  int i, j, isize, jsize, ksize, kstart;
  int k;

  k = 0;
  kstart = 0;
  isize = cell_size[c][0] - endc[c][0] - 1;
  jsize = cell_size[c][1] - endc[c][1] - 1;
  ksize = cell_size[c][2] - 1;

  /*--------------------------------------------------------------------
    c outer most do loops - sweeping in i direction
    c-------------------------------------------------------------------*/
  if( first == 1 )
    {
      for( i=startc[c][0]; i<=isize; i++ )
	{
	  for( j=startc[c][1]; j<=jsize; j++ )
	    {
	      /*--------------------------------------------------------------------
		c multiply c(i,j,kstart) by b_inverse and copy back to c
		c multiply rhs(kstart) by b_inverse(kstart) and copy to rhs
		c-------------------------------------------------------------------*/
	      binvcrhs( &lhs_priv_d(c,i+1,j+1,kstart+1,BB,0,0),
			&lhs_priv_d(c,i+1,j+1,kstart+1,CC,0,0),
			&rhs_priv_d(c,i+1,j+1,kstart+1,0) );
	    }
	}
    }

  /*--------------------------------------------------------------------
    c begin inner most do loop
    c do all the elements of the cell unless last
    c-------------------------------------------------------------------*/
  for( i=startc[c][0]; i<=isize; i++ )
    {
      for( j=startc[c][1]; j<=jsize; j++ )
	{
	  for( k=kstart+first; k<ksize-last; k++ )
	    {
	      /*--------------------------------------------------------------------
		c rhs(k) -= A*rhs(k-1)
		c-------------------------------------------------------------------*/
	      matvec_sub( &lhs_priv_d(c,i+1,j+1,k+1,AA,0,0),
			  &rhs_priv_d(c,i+1,j+1,k-1+1,0),
			  &rhs_priv_d(c,i+1,j+1,k+1,0) );

	      /*--------------------------------------------------------------------
		c B(k) -= C(k-1)*A(k)
		c-------------------------------------------------------------------*/
	      matmul_sub( &lhs_priv_d(c,i+1,j+1,k+1,AA,0,0),
			  &lhs_priv_d(c,i+1,j+1,k-1+1,CC,0,0),
			  &lhs_priv_d(c,i+1,j+1,k+1,BB,0,0) );

	      /*--------------------------------------------------------------------
		c multiply c(i,j,k) by b_inverse and copy back to c
		c multiply rhs(i,j,k) by b_inverse(i,j,k) and copy to rhs
		c-------------------------------------------------------------------*/
	      binvcrhs( &lhs_priv_d(c,i+1,j+1,k+1,BB,0,0),
			&lhs_priv_d(c,i+1,j+1,k+1,CC,0,0),
			&rhs_priv_d(c,i+1,j+1,k+1,0) );
	    }
	}
    }

  if( first == 0 )
    upc_wait;

  for( i=startc[c][0]; i<=isize; i++ )
    {
      for( j=startc[c][1]; j<=jsize; j++ )
	{
	  /*--------------------------------------------------------------------
	    c rhs(k) -= A*rhs(k-1)
	    c-------------------------------------------------------------------*/
	  matvec_sub( &lhs_priv_d(c,i+1,j+1,k+1,AA,0,0),
		      &rhs_priv_d(c,i+1,j+1,k-1+1,0),
		      &rhs_priv_d(c,i+1,j+1,k+1,0) );

	  /*--------------------------------------------------------------------
	    c B(k) -= C(k-1)*A(k)
	    c-------------------------------------------------------------------*/
	  matmul_sub( &lhs_priv_d(c,i+1,j+1,k+1,AA,0,0),
		      &lhs_priv_d(c,i+1,j+1,k-1+1,CC,0,0),
		      &lhs_priv_d(c,i+1,j+1,k+1,BB,0,0) );

	  /*--------------------------------------------------------------------
	    c multiply c(i,j,k) by b_inverse and copy back to c
	    c multiply rhs(i,j,k) by b_inverse(i,j,k) and copy to rhs
	    c-------------------------------------------------------------------*/
	  binvcrhs( &lhs_priv_d(c,i+1,j+1,k+1,BB,0,0),
		    &lhs_priv_d(c,i+1,j+1,k+1,CC,0,0),
		    &rhs_priv_d(c,i+1,j+1,k+1,0) );
	}
    }
  k++;

  /*--------------------------------------------------------------------
    c Now finish up special cases for last cell
    c-------------------------------------------------------------------*/
  if( last == 1 )
    {
      for( i=startc[c][0]; i<=isize; i++ )
	{  
	  for( j=startc[c][1]; j<=jsize; j++ )
	    {
	      /*--------------------------------------------------------------------
		c rhs(ksize) -= A*rhs(ksize-1)
		c-------------------------------------------------------------------*/
	      matvec_sub( &lhs_priv_d(c,i+1,j+1,ksize+1,AA,0,0),
			  &rhs_priv_d(c,i+1,j+1,ksize-1+1,0),
			  &rhs_priv_d(c,i+1,j+1,ksize+1,0) );

	      /*--------------------------------------------------------------------
		c B(ksize) -= C(ksize-1)*A(ksize)
		c-------------------------------------------------------------------*/
	      matmul_sub( &lhs_priv_d(c,i+1,j+1,ksize+1,AA,0,0),
			  &lhs_priv_d(c,i+1,j+1,ksize-1+1,CC,0,0),
			  &lhs_priv_d(c,i+1,j+1,ksize+1,BB,0,0) );

	      /*--------------------------------------------------------------------
		c multiply rhs() by b_inverse() and copy to rhs
		c-------------------------------------------------------------------*/
	      binvrhs( &lhs_priv_d(c,i+1,j+1,k+1,BB,0,0),
		       &rhs_priv_d(c,i+1,j+1,k+1,0) );
	    }
	}
    }
}

/*--------------------------------------------------------------------
--------------------------------------------------------------------*/

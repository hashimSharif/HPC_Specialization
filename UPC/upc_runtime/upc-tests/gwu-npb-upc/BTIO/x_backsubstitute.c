/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void x_backsubstitute( int first, int last, int c )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c back solve : if last cell, then generate U(isize)=rhs(isize)
    c else assume U(isize) is loaded in un_pack backsub_info
    c so just use it
    c after call u(istart) will be sent to next cell
    --------------------------------------------------------------------*/
  int i, j, k, m, n, isize, jsize, ksize, istart;

  istart = 0;
  isize = cell_size[c][0] - 1;
  jsize = cell_size[c][1] - endc[c][1] - 1;
  ksize = cell_size[c][2] - endc[c][2] - 1;

  if( last == 0 )
    {
      for( j=startc[c][1]; j<=jsize; j++ )
	{
	  for( k=startc[c][2]; k<=ksize; k++ )
	    {
	      /*--------------------------------------------------------------------
		c U(isize) uses info from previous cell if not last cell
		c-------------------------------------------------------------------*/
	      for( n=0; n<BLOCK_SIZE; n++ )
		{
		  for( m=0; m<BLOCK_SIZE; m++ )
		    {
		      rhs_priv_d(c,isize+1,j+1,k+1,m) = 
			rhs_priv_d(c,isize+1,j+1,k+1,m)
			- lhs_priv_d(c,isize+1,j+1,k+1,CC,n,m)*
			backsub_info_priv_d(c,j,k,n);
		      /*--------------------------------------------------------------------
			c rhs(c,isize,j,k,m) -= lhs(c,isize,j,k,CC,n,m)*rhs(c,isize+1,j,k,n)
			c-------------------------------------------------------------------*/
		    }
		}
	    }
	}
    }

  for( i=isize-1; i>istart; i-- )
    {
      for( j=startc[c][1]; j<=jsize; j++ )
	{
	  for( k=startc[c][2]; k<=ksize; k++ )
	    {
	      for( n=0; n<BLOCK_SIZE; n++ )
		{
		  for( m=0; m<BLOCK_SIZE; m++ )
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = 
			rhs_priv_d(c,i+1,j+1,k+1,m)
			- lhs_priv_d(c,i+1,j+1,k+1,CC,n,m) * 
			rhs_priv_d(c,i+1+1,j+1,k+1,n);
		    }
		}
	    }
	}
    }
  
  if( last == 0 )
    upc_wait; /* safe for writing (x_unpack_backsub_info() */

  for( j=startc[c][1]; j<=jsize; j++ )
    {
      for( k=startc[c][2]; k<=ksize; k++ )
	{
	  for( n=0; n<BLOCK_SIZE; n++ )
	    {
	      for( m=0; m<BLOCK_SIZE; m++ )
		{
		  rhs_priv_d(c,i+1,j+1,k+1,m) = 
		    rhs_priv_d(c,i+1,j+1,k+1,m)
		    - lhs_priv_d(c,i+1,j+1,k+1,CC,n,m) * 
		    rhs_priv_d(c,i+1+1,j+1,k+1,n);
		}
	    }
	}
    }
}

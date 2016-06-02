/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void z_backsubstitute( int first, int last, int c )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c back solve : if last cell, then generate U(ksize)=rhs(ksize)
    c else assume U(ksize) is loaded in un_pack backsub_info
    c so just use it
    c after call u(kstart) will be sent to next cell
    --------------------------------------------------------------------*/
  int i, j, k, m, n, isize, jsize, ksize, kstart;

  k = 0;
  kstart = 0;
  isize = cell_size[c][0] - endc[c][0] - 1;
  jsize = cell_size[c][1] - endc[c][1] - 1;
  ksize = cell_size[c][2] - 1;

  if( last == 0 )
    {
      for( i=startc[c][0]; i<=isize; i++ )
	{
	  for( j=startc[c][1]; j<=jsize; j++ )
	    {
	      /*--------------------------------------------------------------------
		c U(ksize) uses info from previous cell if not last cell
		c-------------------------------------------------------------------*/
	      for( n=0; n<BLOCK_SIZE; n++ )
		{
		  for( m=0; m<BLOCK_SIZE; m++ )
		    {
		      rhs_priv_d(c,i+1,j+1,ksize+1,m) = rhs_priv_d(c,i+1,j+1,ksize+1,m)
			- lhs_priv_d(c,i+1,j+1,ksize+1,CC,n,m)*
			backsub_info_priv_d(c,i,j,n);
		      /*--------------------------------------------------------------------
			c rhs(c,i,j,ksize,m) -= lhs(c,i,j,ksize,CC,n,m)*rhs(c,i,j,ksize+1,n)
			c-------------------------------------------------------------------*/
		    }
		}
	    }
	}
    }

  for( i=startc[c][0]; i<=isize; i++ )
    {
      for( j=startc[c][1]; j<=jsize; j++ )
	{
	  for( k=ksize-1; k>kstart; k-- )
	    {
	      for( n=0; n<BLOCK_SIZE; n++ )
		{
		  for( m=0; m<BLOCK_SIZE; m++ )
		    {
		      rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m)
			- lhs_priv_d(c,i+1,j+1,k+1,CC,n,m) * 
			rhs_priv_d(c,i+1,j+1,k+1+1,n);
		    }
		}
	    }
	}
    }

  if( last == 0 )
    upc_wait;

  for( i=startc[c][0]; i<=isize; i++ )
    {
      for( j=startc[c][1]; j<=jsize; j++ )
	{
	  for( n=0; n<BLOCK_SIZE; n++ )
	    {
	      for( m=0; m<BLOCK_SIZE; m++ )
		{
		  rhs_priv_d(c,i+1,j+1,k+1,m) = rhs_priv_d(c,i+1,j+1,k+1,m)
		    - lhs_priv_d(c,i+1,j+1,k+1,CC,n,m) * 
		    rhs_priv_d(c,i+1,j+1,k+1+1,n);
		}
	    }
	}
    }
}

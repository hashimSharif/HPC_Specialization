/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void y_backsubstitute( int first, int last, int c )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c back solve : if last cell, then generate U(jsize)=rhs(jsize)
    c else assume U(jsize) is loaded in un_pack backsub_info
    c so just use it
    c after call u(jstart) will be sent to next cell
    --------------------------------------------------------------------*/
  int i, j, k, m, n, isize, jsize, ksize, jstart;

  j = 0;
  jstart = 0;
  isize = cell_size[c][0] - endc[c][0] - 1;
  jsize = cell_size[c][1] - 1;
  ksize = cell_size[c][2] - endc[c][2] - 1;

  if( last == 0 )
    {
      for( i=startc[c][0]; i<=isize; i++ )
	{
	  for( k=startc[c][2]; k<=ksize; k++ )
	    {
	      /*--------------------------------------------------------------------
		c U(jsize) uses info from previous cell if not last cell
		c-------------------------------------------------------------------*/
	      for( n=0; n<BLOCK_SIZE; n++ )
		{
		  for( m=0; m<BLOCK_SIZE; m++ )
		    {
		      rhs_priv_d(c,i+1,jsize+1,k+1,m) = 
			rhs_priv_d(c,i+1,jsize+1,k+1,m)
			- lhs_priv_d(c,i+1,jsize+1,k+1,CC,n,m)*
			backsub_info_priv_d(c,i,k,n);
		      /*--------------------------------------------------------------------
			c rhs(c,i,jsize,k,m) -= lhs(c,i,jsize,k,CC,n,m)*rhs(c,i,jsize+1,k,n)
			c-------------------------------------------------------------------*/
		    }
		}
	    }
	}
    }

  for( i=startc[c][0]; i<=isize; i++ )
    {
      for( j=jsize-1; j>jstart; j-- )
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
			rhs_priv_d(c,i+1,j+1+1,k+1,n);
		    }
		}
	    }
	}
    }

  if( last == 0 )
    upc_wait;

  for( i=startc[c][0]; i<=isize; i++ )
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
		    rhs_priv_d(c,i+1,j+1+1,k+1,n);
		}
	    }
	}
    }
}

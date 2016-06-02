/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void matvec_sub( double *ablock, 
		 double *avec, 
		 double *bvec )
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c substracts bvec -= ablock*avec
    c-------------------------------------------------------------------*/
  int i;


  for (i = 0; i < 5; i++)
    {
      /*--------------------------------------------------------------------
	c            rhs(i,ic,jc,kc,ccell) = rhs(i,ic,jc,kc,ccell) 
	c     $           - lhs(i,1,ablock,ia,ja,ka,acell)*
	c-------------------------------------------------------------------*/
      bvec[i] = bvec[i] - ablock[i]*avec[0]
	- ablock[5+i]*avec[1]
	- ablock[10+i]*avec[2]
	- ablock[15+i]*avec[3]
	- ablock[20+i]*avec[4];
    }
}



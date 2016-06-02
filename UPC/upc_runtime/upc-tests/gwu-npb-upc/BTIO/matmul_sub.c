/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void matmul_sub( double *ablock,
		 double *bblock, 
		 double *cblock )
{
  /*--------------------------------------------------------------------
    c     subtracts a(i,j,k) X b(i,j,k) from c(i,j,k)
    c-------------------------------------------------------------------*/
  int j;

  for (j = 0; j < 5; j++)
    {
      cblock[(j*5)] = cblock[(j*5)] - ablock[0]*bblock[(j*5)]
	- ablock[5]*bblock[(j*5)+1]
	- ablock[10]*bblock[(j*5)+2]
	- ablock[15]*bblock[(j*5)+3]
	- ablock[20]*bblock[(j*5)+4];
      cblock[(j*5)+1] = cblock[(j*5)+1] - ablock[1]*bblock[(j*5)]
	- ablock[6]*bblock[(j*5)+1]
	- ablock[11]*bblock[(j*5)+2]
	- ablock[16]*bblock[(j*5)+3]
	- ablock[21]*bblock[(j*5)+4];
      cblock[(j*5)+2] = cblock[(j*5)+2] - ablock[2]*bblock[(j*5)]
	- ablock[7]*bblock[(j*5)+1]
	- ablock[12]*bblock[(j*5)+2]
	- ablock[17]*bblock[(j*5)+3]
	- ablock[22]*bblock[(j*5)+4];
      cblock[(j*5)+3] = cblock[(j*5)+3] - ablock[3]*bblock[(j*5)]
	- ablock[8]*bblock[(j*5)+1]
	- ablock[13]*bblock[(j*5)+2]
	- ablock[18]*bblock[(j*5)+3]
	- ablock[23]*bblock[(j*5)+4];
      cblock[(j*5)+4] = cblock[(j*5)+4] - ablock[4]*bblock[(j*5)]
	- ablock[9]*bblock[(j*5)+1]
	- ablock[14]*bblock[(j*5)+2]
	- ablock[19]*bblock[(j*5)+3]
	- ablock[24]*bblock[(j*5)+4];
    }
}

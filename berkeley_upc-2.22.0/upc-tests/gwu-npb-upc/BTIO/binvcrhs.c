/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void binvcrhs(double *lh, double *c, double *r)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/
  
  double pivot, coeff;
  
  /*--------------------------------------------------------------------
    c     
    c-------------------------------------------------------------------*/
  
  pivot = 1.00/lh[0];
  lh[5+0] = lh[5+0]*pivot;
  lh[10+0] = lh[10+0]*pivot;
  lh[15+0] = lh[15+0]*pivot;
  lh[20+0] = lh[20+0]*pivot;
  c[0] = c[0]*pivot;
  c[5+0] = c[5+0]*pivot;
  c[10+0] = c[10+0]*pivot;
  c[15+0] = c[15+0]*pivot;
  c[20+0] = c[20+0]*pivot;
  r[0]   = r[0]  *pivot;

  coeff = lh[1];
  lh[5+1]= lh[5+1] - coeff*lh[5+0];
  lh[10+1]= lh[10+1] - coeff*lh[10+0];
  lh[15+1]= lh[15+1] - coeff*lh[15+0];
  lh[20+1]= lh[20+1] - coeff*lh[20+0];
  c[1] = c[1] - coeff*c[0];
  c[5+1] = c[5+1] - coeff*c[5+0];
  c[10+1] = c[10+1] - coeff*c[10+0];
  c[15+1] = c[15+1] - coeff*c[15+0];
  c[20+1] = c[20+1] - coeff*c[20+0];
  r[1]   = r[1]   - coeff*r[0];

  coeff = lh[2];
  lh[5+2]= lh[5+2] - coeff*lh[5+0];
  lh[10+2]= lh[10+2] - coeff*lh[10+0];
  lh[15+2]= lh[15+2] - coeff*lh[15+0];
  lh[20+2]= lh[20+2] - coeff*lh[20+0];
  c[2] = c[2] - coeff*c[0];
  c[5+2] = c[5+2] - coeff*c[5+0];
  c[10+2] = c[10+2] - coeff*c[10+0];
  c[15+2] = c[15+2] - coeff*c[15+0];
  c[20+2] = c[20+2] - coeff*c[20+0];
  r[2]   = r[2]   - coeff*r[0];

  coeff = lh[3];
  lh[5+3]= lh[5+3] - coeff*lh[5+0];
  lh[10+3]= lh[10+3] - coeff*lh[10+0];
  lh[15+3]= lh[15+3] - coeff*lh[15+0];
  lh[20+3]= lh[20+3] - coeff*lh[20+0];
  c[3] = c[3] - coeff*c[0];
  c[5+3] = c[5+3] - coeff*c[5+0];
  c[10+3] = c[10+3] - coeff*c[10+0];
  c[15+3] = c[15+3] - coeff*c[15+0];
  c[20+3] = c[20+3] - coeff*c[20+0];
  r[3]   = r[3]   - coeff*r[0];

  coeff = lh[4];
  lh[5+4]= lh[5+4] - coeff*lh[5+0];
  lh[10+4]= lh[10+4] - coeff*lh[10+0];
  lh[15+4]= lh[15+4] - coeff*lh[15+0];
  lh[20+4]= lh[20+4] - coeff*lh[20+0];
  c[4] = c[4] - coeff*c[0];
  c[5+4] = c[5+4] - coeff*c[5+0];
  c[10+4] = c[10+4] - coeff*c[10+0];
  c[15+4] = c[15+4] - coeff*c[15+0];
  c[20+4] = c[20+4] - coeff*c[20+0];
  r[4]   = r[4]   - coeff*r[0];


  pivot = 1.00/lh[5+1];
  lh[10+1] = lh[10+1]*pivot;
  lh[15+1] = lh[15+1]*pivot;
  lh[20+1] = lh[20+1]*pivot;
  c[1] = c[1]*pivot;
  c[5+1] = c[5+1]*pivot;
  c[10+1] = c[10+1]*pivot;
  c[15+1] = c[15+1]*pivot;
  c[20+1] = c[20+1]*pivot;
  r[1]   = r[1]  *pivot;

  coeff = lh[5+0];
  lh[10+0]= lh[10+0] - coeff*lh[10+1];
  lh[15+0]= lh[15+0] - coeff*lh[15+1];
  lh[20+0]= lh[20+0] - coeff*lh[20+1];
  c[0] = c[0] - coeff*c[1];
  c[5+0] = c[5+0] - coeff*c[5+1];
  c[10+0] = c[10+0] - coeff*c[10+1];
  c[15+0] = c[15+0] - coeff*c[15+1];
  c[20+0] = c[20+0] - coeff*c[20+1];
  r[0]   = r[0]   - coeff*r[1];

  coeff = lh[5+2];
  lh[10+2]= lh[10+2] - coeff*lh[10+1];
  lh[15+2]= lh[15+2] - coeff*lh[15+1];
  lh[20+2]= lh[20+2] - coeff*lh[20+1];
  c[2] = c[2] - coeff*c[1];
  c[5+2] = c[5+2] - coeff*c[5+1];
  c[10+2] = c[10+2] - coeff*c[10+1];
  c[15+2] = c[15+2] - coeff*c[15+1];
  c[20+2] = c[20+2] - coeff*c[20+1];
  r[2]   = r[2]   - coeff*r[1];

  coeff = lh[5+3];
  lh[10+3]= lh[10+3] - coeff*lh[10+1];
  lh[15+3]= lh[15+3] - coeff*lh[15+1];
  lh[20+3]= lh[20+3] - coeff*lh[20+1];
  c[3] = c[3] - coeff*c[1];
  c[5+3] = c[5+3] - coeff*c[5+1];
  c[10+3] = c[10+3] - coeff*c[10+1];
  c[15+3] = c[15+3] - coeff*c[15+1];
  c[20+3] = c[20+3] - coeff*c[20+1];
  r[3]   = r[3]   - coeff*r[1];

  coeff = lh[5+4];
  lh[10+4]= lh[10+4] - coeff*lh[10+1];
  lh[15+4]= lh[15+4] - coeff*lh[15+1];
  lh[20+4]= lh[20+4] - coeff*lh[20+1];
  c[4] = c[4] - coeff*c[1];
  c[5+4] = c[5+4] - coeff*c[5+1];
  c[10+4] = c[10+4] - coeff*c[10+1];
  c[15+4] = c[15+4] - coeff*c[15+1];
  c[20+4] = c[20+4] - coeff*c[20+1];
  r[4]   = r[4]   - coeff*r[1];


  pivot = 1.00/lh[10+2];
  lh[15+2] = lh[15+2]*pivot;
  lh[20+2] = lh[20+2]*pivot;
  c[2] = c[2]*pivot;
  c[5+2] = c[5+2]*pivot;
  c[10+2] = c[10+2]*pivot;
  c[15+2] = c[15+2]*pivot;
  c[20+2] = c[20+2]*pivot;
  r[2]   = r[2]  *pivot;

  coeff = lh[10+0];
  lh[15+0]= lh[15+0] - coeff*lh[15+2];
  lh[20+0]= lh[20+0] - coeff*lh[20+2];
  c[0] = c[0] - coeff*c[2];
  c[5+0] = c[5+0] - coeff*c[5+2];
  c[10+0] = c[10+0] - coeff*c[10+2];
  c[15+0] = c[15+0] - coeff*c[15+2];
  c[20+0] = c[20+0] - coeff*c[20+2];
  r[0]   = r[0]   - coeff*r[2];

  coeff = lh[10+1];
  lh[15+1]= lh[15+1] - coeff*lh[15+2];
  lh[20+1]= lh[20+1] - coeff*lh[20+2];
  c[1] = c[1] - coeff*c[2];

  c[5+1] = c[5+1] - coeff*c[5+2];
  c[10+1] = c[10+1] - coeff*c[10+2];
  c[15+1] = c[15+1] - coeff*c[15+2];
  c[20+1] = c[20+1] - coeff*c[20+2];
  r[1]   = r[1]   - coeff*r[2];

  coeff = lh[10+3];
  lh[15+3]= lh[15+3] - coeff*lh[15+2];
  lh[20+3]= lh[20+3] - coeff*lh[20+2];
  c[3] = c[3] - coeff*c[2];
  c[5+3] = c[5+3] - coeff*c[5+2];
  c[10+3] = c[10+3] - coeff*c[10+2];
  c[15+3] = c[15+3] - coeff*c[15+2];
  c[20+3] = c[20+3] - coeff*c[20+2];
  r[3]   = r[3]   - coeff*r[2];

  coeff = lh[10+4];
  lh[15+4]= lh[15+4] - coeff*lh[15+2];
  lh[20+4]= lh[20+4] - coeff*lh[20+2];
  c[4] = c[4] - coeff*c[2];
  c[5+4] = c[5+4] - coeff*c[5+2];
  c[10+4] = c[10+4] - coeff*c[10+2];
  c[15+4] = c[15+4] - coeff*c[15+2];
  c[20+4] = c[20+4] - coeff*c[20+2];
  r[4]   = r[4]   - coeff*r[2];


  pivot = 1.00/lh[15+3];
  lh[20+3] = lh[20+3]*pivot;
  c[3] = c[3]*pivot;
  c[5+3] = c[5+3]*pivot;
  c[10+3] = c[10+3]*pivot;
  c[15+3] = c[15+3]*pivot;
  c[20+3] = c[20+3]*pivot;
  r[3]   = r[3]  *pivot;

  coeff = lh[15+0];
  lh[20+0]= lh[20+0] - coeff*lh[20+3];
  c[0] = c[0] - coeff*c[3];
  c[5+0] = c[5+0] - coeff*c[5+3];
  c[10+0] = c[10+0] - coeff*c[10+3];
  c[15+0] = c[15+0] - coeff*c[15+3];
  c[20+0] = c[20+0] - coeff*c[20+3];
  r[0]   = r[0]   - coeff*r[3];

  coeff = lh[15+1];
  lh[20+1]= lh[20+1] - coeff*lh[20+3];
  c[1] = c[1] - coeff*c[3];
  c[5+1] = c[5+1] - coeff*c[5+3];
  c[10+1] = c[10+1] - coeff*c[10+3];
  c[15+1] = c[15+1] - coeff*c[15+3];
  c[20+1] = c[20+1] - coeff*c[20+3];
  r[1]   = r[1]   - coeff*r[3];

  coeff = lh[15+2];
  lh[20+2]= lh[20+2] - coeff*lh[20+3];
  c[2] = c[2] - coeff*c[3];
  c[5+2] = c[5+2] - coeff*c[5+3];
  c[10+2] = c[10+2] - coeff*c[10+3];
  c[15+2] = c[15+2] - coeff*c[15+3];
  c[20+2] = c[20+2] - coeff*c[20+3];
  r[2]   = r[2]   - coeff*r[3];

  coeff = lh[15+4];
  lh[20+4]= lh[20+4] - coeff*lh[20+3];
  c[4] = c[4] - coeff*c[3];
  c[5+4] = c[5+4] - coeff*c[5+3];
  c[10+4] = c[10+4] - coeff*c[10+3];
  c[15+4] = c[15+4] - coeff*c[15+3];
  c[20+4] = c[20+4] - coeff*c[20+3];
  r[4]   = r[4]   - coeff*r[3];


  pivot = 1.00/lh[20+4];
  c[4] = c[4]*pivot;
  c[5+4] = c[5+4]*pivot;
  c[10+4] = c[10+4]*pivot;
  c[15+4] = c[15+4]*pivot;
  c[20+4] = c[20+4]*pivot;
  r[4]   = r[4]  *pivot;

  coeff = lh[20+0];
  c[0] = c[0] - coeff*c[4];
  c[5+0] = c[5+0] - coeff*c[5+4];
  c[10+0] = c[10+0] - coeff*c[10+4];
  c[15+0] = c[15+0] - coeff*c[15+4];
  c[20+0] = c[20+0] - coeff*c[20+4];
  r[0]   = r[0]   - coeff*r[4];

  coeff = lh[20+1];
  c[1] = c[1] - coeff*c[4];
  c[5+1] = c[5+1] - coeff*c[5+4];
  c[10+1] = c[10+1] - coeff*c[10+4];
  c[15+1] = c[15+1] - coeff*c[15+4];
  c[20+1] = c[20+1] - coeff*c[20+4];
  r[1]   = r[1]   - coeff*r[4];

  coeff = lh[20+2];
  c[2] = c[2] - coeff*c[4];
  c[5+2] = c[5+2] - coeff*c[5+4];
  c[10+2] = c[10+2] - coeff*c[10+4];
  c[15+2] = c[15+2] - coeff*c[15+4];
  c[20+2] = c[20+2] - coeff*c[20+4];
  r[2]   = r[2]   - coeff*r[4];

  coeff = lh[20+3];
  c[3] = c[3] - coeff*c[4];
  c[5+3] = c[5+3] - coeff*c[5+4];
  c[10+3] = c[10+3] - coeff*c[10+4];
  c[15+3] = c[15+3] - coeff*c[15+4];
  c[20+3] = c[20+3] - coeff*c[20+4];
  r[3]   = r[3]   - coeff*r[4];
}


/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void set_constants(void)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  ce[0][0]  = 2.0;
  ce[1][0]  = 0.0;
  ce[2][0]  = 0.0;
  ce[3][0]  = 4.0;
  ce[4][0]  = 5.0;
  ce[5][0]  = 3.0;
  ce[6][0]  = 0.5;
  ce[7][0]  = 0.02;
  ce[8][0]  = 0.01;
  ce[9][0] = 0.03;
  ce[10][0] = 0.5;
  ce[11][0] = 0.4;
  ce[12][0] = 0.3;
 
  ce[0][1]  = 1.0;
  ce[1][1]  = 0.0;
  ce[2][1]  = 0.0;
  ce[3][1]  = 0.0;
  ce[4][1]  = 1.0;
  ce[5][1]  = 2.0;
  ce[6][1]  = 3.0;
  ce[7][1]  = 0.01;
  ce[8][1]  = 0.03;
  ce[9][1] = 0.02;
  ce[10][1] = 0.4;
  ce[11][1] = 0.3;
  ce[12][1] = 0.5;

  ce[0][2]  = 2.0;
  ce[1][2]  = 2.0;
  ce[2][2]  = 0.0;
  ce[3][2]  = 0.0;
  ce[4][2]  = 0.0;
  ce[5][2]  = 2.0;
  ce[6][2]  = 3.0;
  ce[7][2]  = 0.04;
  ce[8][2]  = 0.03;
  ce[9][2] = 0.05;
  ce[10][2] = 0.3;
  ce[11][2] = 0.5;
  ce[12][2] = 0.4;

  ce[0][3]  = 2.0;
  ce[1][3]  = 2.0;
  ce[2][3]  = 0.0;
  ce[3][3]  = 0.0;
  ce[4][3]  = 0.0;
  ce[5][3]  = 2.0;
  ce[6][3]  = 3.0;
  ce[7][3]  = 0.03;
  ce[8][3]  = 0.05;
  ce[9][3] = 0.04;
  ce[10][3] = 0.2;
  ce[11][3] = 0.1;
  ce[12][3] = 0.3;

  ce[0][4]  = 5.0;
  ce[1][4]  = 4.0;
  ce[2][4]  = 3.0;
  ce[3][4]  = 2.0;
  ce[4][4]  = 0.1;
  ce[5][4]  = 0.4;
  ce[6][4]  = 0.3;
  ce[7][4]  = 0.05;
  ce[8][4]  = 0.04;
  ce[9][4] = 0.03;
  ce[10][4] = 0.1;
  ce[11][4] = 0.3;
  ce[12][4] = 0.2;

  c1 = 1.4;
  c2 = 0.4;
  c3 = 0.1;
  c4 = 1.0;
  c5 = 1.4;

  bt = sqrt(0.5);

  dnxm1 = 1.0 / (double)(grid_points[0]-1);
  dnym1 = 1.0 / (double)(grid_points[1]-1);
  dnzm1 = 1.0 / (double)(grid_points[2]-1);

  c1c2 = c1 * c2;
  c1c5 = c1 * c5;
  c3c4 = c3 * c4;
  c1345 = c1c5 * c3c4;

  conz1 = (1.0-c1c5);

  tx1 = dnxm1*dnxm1;
  tx1 = 1.0 / tx1;
  tx2 = 2.0 * dnxm1;
  tx2 = 1.0 / tx2;
  //tx1 = 1.0 / (dnxm1 * dnxm1);
  //tx2 = 1.0 / (2.0 * dnxm1);
  tx3 = 1.0 / dnxm1;

  ty1 = dnym1*dnym1;
  ty1 = 1.0 / ty1;
  ty2 = 2.0 * dnym1;
  ty2 = 1.0 / ty2;
  //ty1 = 1.0 / (dnym1 * dnym1);
  //ty2 = 1.0 / (2.0 * dnym1);
  ty3 = 1.0 / dnym1;
 
  tz1 = dnzm1*dnzm1;
  tz1 = 1.0 / tz1;
  tz2 = 2.0 * dnzm1;
  tz2 = 1.0 / tz2;
  //tz1 = 1.0 / (dnzm1 * dnzm1);
  //tz2 = 1.0 / (2.0 * dnzm1);
  tz3 = 1.0 / dnzm1;

  dx1 = 0.75;
  dx2 = 0.75;
  dx3 = 0.75;
  dx4 = 0.75;
  dx5 = 0.75;

  dy1 = 0.75;
  dy2 = 0.75;
  dy3 = 0.75;
  dy4 = 0.75;
  dy5 = 0.75;

  dz1 = 1.0;
  dz2 = 1.0;
  dz3 = 1.0;
  dz4 = 1.0;
  dz5 = 1.0;

  dxmax = max(dx3, dx4);
  dymax = max(dy2, dy4);
  dzmax = max(dz2, dz3);

  dssp = 0.25 * max(dx1, max(dy1, dz1) );

  c4dssp = 4.0 * dssp;
  c5dssp = 5.0 * dssp;

  dttx1 = dt*tx1;
  dttx2 = dt*tx2;
  dtty1 = dt*ty1;
  dtty2 = dt*ty2;
  dttz1 = dt*tz1;
  dttz2 = dt*tz2;

  c2dttx1 = 2.0*dttx1;
  c2dtty1 = 2.0*dtty1;
  c2dttz1 = 2.0*dttz1;

  dtdssp = dt*dssp;

  comz1  = dtdssp;
  comz4  = 4.0*dtdssp;
  comz5  = 5.0*dtdssp;
  comz6  = 6.0*dtdssp;

  c3c4tx3 = c3c4*tx3;
  c3c4ty3 = c3c4*ty3;
  c3c4tz3 = c3c4*tz3;

  dx1tx1 = dx1*tx1;
  dx2tx1 = dx2*tx1;
  dx3tx1 = dx3*tx1;
  dx4tx1 = dx4*tx1;
  dx5tx1 = dx5*tx1;
        
  dy1ty1 = dy1*ty1;
  dy2ty1 = dy2*ty1;
  dy3ty1 = dy3*ty1;
  dy4ty1 = dy4*ty1;
  dy5ty1 = dy5*ty1;
        
  dz1tz1 = dz1*tz1;
  dz2tz1 = dz2*tz1;
  dz3tz1 = dz3*tz1;
  dz4tz1 = dz4*tz1;
  dz5tz1 = dz5*tz1;

  c2iv  = 2.5;
  con43 = 4.0/3.0;
  con16 = 1.0/6.0;
        
  xxcon1 = c3c4tx3*con43*tx3;
  xxcon2 = c3c4tx3*tx3;
  xxcon3 = c3c4tx3*conz1*tx3;
  xxcon4 = c3c4tx3*con16*tx3;
  xxcon5 = c3c4tx3*c1c5*tx3;

  yycon1 = c3c4ty3*con43*ty3;
  yycon2 = c3c4ty3*ty3;
  yycon3 = c3c4ty3*conz1*ty3;
  yycon4 = c3c4ty3*con16*ty3;
  yycon5 = c3c4ty3*c1c5*ty3;

  zzcon1 = c3c4tz3*con43*tz3;
  zzcon2 = c3c4tz3*tz3;
  zzcon3 = c3c4tz3*conz1*tz3;
  zzcon4 = c3c4tz3*con16*tz3;
  zzcon5 = c3c4tz3*c1c5*tz3;
}


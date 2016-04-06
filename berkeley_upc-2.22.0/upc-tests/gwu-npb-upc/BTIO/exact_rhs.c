/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void exact_rhs(void)
{
  /*--------------------------------------------------------------------
    --------------------------------------------------------------------*/

  /*--------------------------------------------------------------------
    c compute the right hand side based on exact solution
    c-------------------------------------------------------------------*/
  
  double dtemp[5], xi, eta, zeta, dtpp;
  int c, m, i, j, k, ip1, im1, jp1, jm1, km1, kp1;

  /*--------------------------------------------------------------------
    c      initialize                                  
    c-------------------------------------------------------------------*/
  for (c = 0; c < ncells; c++ )
    {
      for (m = 0; m < 5; m++)
	{
	  for (i = 0; i <= cell_size[c][0]-1; i++)
	    {
	      for (j = 0; j <= cell_size[c][1]-1; j++)
		{
		  for (k= 0; k <= cell_size[c][2]-1; k++)
		    {
		      forcing[c][m][i][j][k] = 0.0;
		    }
		}
	    }
	}

      /*--------------------------------------------------------------------
	c      xi-direction flux differences                      
	c-------------------------------------------------------------------*/
      for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
	{
	  zeta = (double)(k + cell_low[c][2]) * dnzm1;
	  for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
	    {
	      eta = (double)(j + cell_low[c][1]) * dnym1;

	      for (i = -2*(1-startc[c][0]); i <= (cell_size[c][0]+1-2*endc[c][0]); i++)
		{
		  xi = (double)(i + cell_low[c][0]) * dnxm1;

		  exact_solution(xi, eta, zeta, dtemp);
		  for (m = 0; m < 5; m++)
		    {
		      ue[m][i+2] = dtemp[m];
		    }

		  dtpp = 1.0 / dtemp[0];

		  for (m = 1; m < 5; m++)
		    {
		      buf[m][i+2] = dtpp * dtemp[m];
		    }

		  cuf[i+2] = buf[1][i+2] * buf[1][i+2];
		  buf[0][i+2] = cuf[i+2] + buf[2][i+2] * buf[2][i+2] + buf[3][i+2] * buf[3][i+2];
		  q[i+2] = 0.5 * (buf[1][i+2]*ue[1][i+2] + buf[2][i+2]*ue[2][i+2]
				+ buf[3][i+2]*ue[3][i+2]);
		}
 
	      for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
		{
		  im1 = i-1;
		  ip1 = i+1;

		  forcing[c][0][i][j][k] = forcing[c][0][i][j][k] -
		    tx2*( ue[1][ip1+2]-ue[1][im1+2] )+
		    dx1tx1*(ue[0][ip1+2]-2.0*ue[0][i+2]+ue[0][im1+2]);

		  forcing[c][1][i][j][k] = forcing[c][1][i][j][k]
		    - tx2 * ((ue[1][ip1+2]*buf[1][ip1+2]+c2*(ue[4][ip1+2]-q[ip1+2]))-
			     (ue[1][im1+2]*buf[1][im1+2]+c2*(ue[4][im1+2]-q[im1+2])))+
		    xxcon1*(buf[1][ip1+2]-2.0*buf[1][i+2]+buf[1][im1+2])+
		    dx2tx1*( ue[1][ip1+2]-2.0* ue[1][i+2]+ue[1][im1+2]);

		  forcing[c][2][i][j][k] = forcing[c][2][i][j][k]
		    - tx2 * (ue[2][ip1+2]*buf[1][ip1+2]-ue[2][im1+2]*buf[1][im1+2])+
		    xxcon2*(buf[2][ip1+2]-2.0*buf[2][i+2]+buf[2][im1+2])+
		    dx3tx1*( ue[2][ip1+2]-2.0*ue[2][i+2] +ue[2][im1+2]);
                  
		  forcing[c][3][i][j][k] = forcing[c][3][i][j][k]
		    - tx2*(ue[3][ip1+2]*buf[1][ip1+2]-ue[3][im1+2]*buf[1][im1+2])+
		    xxcon2*(buf[3][ip1+2]-2.0*buf[3][i+2]+buf[3][im1+2])+
		    dx4tx1*( ue[3][ip1+2]-2.0* ue[3][i+2]+ ue[3][im1+2]);

		  forcing[c][4][i][j][k] = forcing[c][4][i][j][k]
		    - tx2*(buf[1][ip1+2]*(c1*ue[4][ip1+2]-c2*q[ip1+2])-
			   buf[1][im1+2]*(c1*ue[4][im1+2]-c2*q[im1+2]))+
		    0.5*xxcon3*(buf[0][ip1+2]-2.0*buf[0][i+2]+
				buf[0][im1+2])+
		    xxcon4*(cuf[ip1+2]-2.0*cuf[i+2]+cuf[im1+2])+
		    xxcon5*(buf[4][ip1+2]-2.0*buf[4][i+2]+buf[4][im1+2])+
		    dx5tx1*( ue[4][ip1+2]-2.0* ue[4][i+2]+ ue[4][im1+2]);
		}

	      /*--------------------------------------------------------------------
		c            Fourth-order dissipation                         
		c-------------------------------------------------------------------*/

	      if( startc[c][0] > 0 )
		{
		  for (m = 0; m < 5; m++)
		    {
		      i = 1;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(5.0*ue[m][i+2] - 4.0*ue[m][i+1+2] +ue[m][i+2+2]);
		      i = 2;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(-4.0*ue[m][i-1+2] + 6.0*ue[m][i+2] -
			 4.0*ue[m][i+1+2] +     ue[m][i+2+2]);
		    }
		}

	      for (m = 0; m < 5; m++)
		{
		  for (i = startc[c][0]*3; i < cell_size[c][0]-3*endc[c][0]; i++)
		    {
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp*
			(ue[m][i-2+2] - 4.0*ue[m][i-1+2] +
			 6.0*ue[m][i+2] - 4.0*ue[m][i+1+2] + ue[m][i+2+2]);
		    }
		}

	      if( endc[c][0] > 0 )
		{
		  for (m = 0; m < 5; m++)
		    {
		      i = cell_size[c][0]-3;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(ue[m][i-2+2] - 4.0*ue[m][i-1+2] +
			 6.0*ue[m][i+2] - 4.0*ue[m][i+1+2]);
		      i = cell_size[c][0]-2;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(ue[m][i-2+2] - 4.0*ue[m][i-1+2] + 5.0*ue[m][i+2]);
		    }
		}
	    }
	}

      /*--------------------------------------------------------------------
	c  eta-direction flux differences             
	c-------------------------------------------------------------------*/
      for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
	{
	  zeta = (double)(k + cell_low[c][2]) * dnzm1;
	  for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	    {
	      xi = (double)(i + cell_low[c][0]) * dnxm1;

	      for (j = -2*(1-startc[c][1]); j <= (cell_size[c][1]+1-2*endc[c][1]); j++)
		{
		  eta = (double)(j + cell_low[c][1]) * dnym1;

		  exact_solution(xi, eta, zeta, dtemp);
		  for (m = 0; m < 5; m++)
		    {
		      ue[m][j+2] = dtemp[m];
		    }
		  dtpp = 1.0/dtemp[0];

		  for (m = 1; m < 5; m++)
		    {
		      buf[m][j+2] = dtpp * dtemp[m];
		    }

		  cuf[j+2] = buf[2][j+2] * buf[2][j+2];
		  buf[0][j+2] = cuf[j+2] + buf[1][j+2] * buf[1][j+2] + 
		    buf[3][j+2] * buf[3][j+2];
		  q[j+2] = 0.5*(buf[1][j+2]*ue[1][j+2] + buf[2][j+2]*ue[2][j+2] +
			      buf[3][j+2]*ue[3][j+2]);
		}

	      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		{
		  jm1 = j-1;
		  jp1 = j+1;
                  
		  forcing[c][0][i][j][k] = forcing[c][0][i][j][k] -
		    ty2*( ue[2][jp1+2]-ue[2][jm1+2] )+
		    dy1ty1*(ue[0][jp1+2]-2.0*ue[0][j+2]+ue[0][jm1+2]);
		  
		  forcing[c][1][i][j][k] = forcing[c][1][i][j][k]
		    - ty2*(ue[1][jp1+2]*buf[2][jp1+2]-ue[1][jm1+2]*buf[2][jm1+2])+
		    yycon2*(buf[1][jp1+2]-2.0*buf[1][j+2]+buf[1][jm1+2])+
		    dy2ty1*( ue[1][jp1+2]-2.0* ue[1][j+2]+ ue[1][jm1+2]);
		  
		  forcing[c][2][i][j][k] = forcing[c][2][i][j][k]
		    - ty2*((ue[2][jp1+2]*buf[2][jp1+2]+c2*(ue[4][jp1+2]-q[jp1+2]))-
			   (ue[2][jm1+2]*buf[2][jm1+2]+c2*(ue[4][jm1+2]-q[jm1+2])))+
		    yycon1*(buf[2][jp1+2]-2.0*buf[2][j+2]+buf[2][jm1+2])+
		    dy3ty1*( ue[2][jp1+2]-2.0*ue[2][j+2] +ue[2][jm1+2]);
		  
		  forcing[c][3][i][j][k] = forcing[c][3][i][j][k]
		    - ty2*(ue[3][jp1+2]*buf[2][jp1+2]-ue[3][jm1+2]*buf[2][jm1+2])+
		    yycon2*(buf[3][jp1+2]-2.0*buf[3][j+2]+buf[3][jm1+2])+
		    dy4ty1*( ue[3][jp1+2]-2.0*ue[3][j+2]+ ue[3][jm1+2]);

		  forcing[c][4][i][j][k] = forcing[c][4][i][j][k]
		    - ty2*(buf[2][jp1+2]*(c1*ue[4][jp1+2]-c2*q[jp1+2])-
			   buf[2][jm1+2]*(c1*ue[4][jm1+2]-c2*q[jm1+2]))+
		    0.5*yycon3*(buf[0][jp1+2]-2.0*buf[0][j+2]+
				buf[0][jm1+2])+
		    yycon4*(cuf[jp1+2]-2.0*cuf[j+2]+cuf[jm1+2])+
		    yycon5*(buf[4][jp1+2]-2.0*buf[4][j+2]+buf[4][jm1+2])+
		    dy5ty1*(ue[4][jp1+2]-2.0*ue[4][j+2]+ue[4][jm1+2]);
		}

	      /*--------------------------------------------------------------------
		c            Fourth-order dissipation                      
		c-------------------------------------------------------------------*/
	      if( startc[c][1] > 0 )
		{
		  for (m = 0; m < 5; m++)
		    {
		      j = 1;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(5.0*ue[m][j+2] - 4.0*ue[m][j+1+2] +ue[m][j+2+2]);
		      j = 2;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(-4.0*ue[m][j-1+2] + 6.0*ue[m][j+2] -
			 4.0*ue[m][j+1+2] + ue[m][j+2+2]);
		    }
		}

	      for (m = 0; m < 5; m++)
		{
		  for (j = startc[c][1]*3; j < cell_size[c][1]-3*endc[c][1]; j++)
		    {
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp*
			(ue[m][j-2+2] - 4.0*ue[m][j-1+2] +
			 6.0*ue[m][j+2] - 4.0*ue[m][j+1+2] + ue[m][j+2+2]);
		    }
		}

	      if( endc[c][1] > 0 )
		{
		  for (m = 0; m < 5; m++)
		    {
		      j = cell_size[c][1]-3;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(ue[m][j-2+2] - 4.0*ue[m][j-1+2] +
			 6.0*ue[m][j+2] - 4.0*ue[m][j+1+2]);
		      j = cell_size[c][1]-2;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(ue[m][j-2+2] - 4.0*ue[m][j-1+2] + 5.0*ue[m][j+2]);
		    }
		}
	    }
	}

      /*--------------------------------------------------------------------
	c      zeta-direction flux differences                      
	c-------------------------------------------------------------------*/
      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
	{
	  eta = (double)(j + cell_low[c][1]) * dnym1;
	  for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	    {
	      xi = (double)(i + cell_low[c][0]) * dnxm1;

	      for (k = -2*(1-startc[c][2]); k <= (cell_size[c][2]+1-2*endc[c][2]); k++)
		{
		  zeta = (double)(k + cell_low[c][2]) * dnzm1;

		  exact_solution(xi, eta, zeta, dtemp);
		  for (m = 0; m < 5; m++)
		  {
		    ue[m][k+2] = dtemp[m];
		  }

		  dtpp = 1.0/dtemp[0];

		  for (m = 1; m < 5; m++)
		  {
		    buf[m][k+2] = dtpp * dtemp[m];
		  }

		  cuf[k+2] = buf[3][k+2] * buf[3][k+2];
		  buf[0][k+2] = cuf[k+2] + buf[1][k+2] * buf[1][k+2] + 
		  buf[2][k+2] * buf[2][k+2];
		  q[k+2] = 0.5*(buf[1][k+2]*ue[1][k+2] + buf[2][k+2]*ue[2][k+2] +
				buf[3][k+2]*ue[3][k+2]);
		}		  

	      for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		{
		  km1 = k-1;
		  kp1 = k+1;
                  
		  forcing[c][0][i][j][k] = forcing[c][0][i][j][k] -
		    tz2*( ue[3][kp1+2]-ue[3][km1+2] )+
		    dz1tz1*(ue[0][kp1+2]-2.0*ue[0][k+2]+ue[0][km1+2]);

		  forcing[c][1][i][j][k] = forcing[c][1][i][j][k]
		    - tz2 * (ue[1][kp1+2]*buf[3][kp1+2]-ue[1][km1+2]*buf[3][km1+2])+
		    zzcon2*(buf[1][kp1+2]-2.0*buf[1][k+2]+buf[1][km1+2])+
		    dz2tz1*( ue[1][kp1+2]-2.0* ue[1][k+2]+ ue[1][km1+2]);

		  forcing[c][2][i][j][k] = forcing[c][2][i][j][k]
		    - tz2 * (ue[2][kp1+2]*buf[3][kp1+2]-ue[2][km1+2]*buf[3][km1+2])+
		    zzcon2*(buf[2][kp1+2]-2.0*buf[2][k+2]+buf[2][km1+2])+
		    dz3tz1*(ue[2][kp1+2]-2.0*ue[2][k+2]+ue[2][km1+2]);

		  forcing[c][3][i][j][k] = forcing[c][3][i][j][k]
		    - tz2 * ((ue[3][kp1+2]*buf[3][kp1+2]+c2*(ue[4][kp1+2]-q[kp1+2]))-
			     (ue[3][km1+2]*buf[3][km1+2]+c2*(ue[4][km1+2]-q[km1+2])))+
		    zzcon1*(buf[3][kp1+2]-2.0*buf[3][k+2]+buf[3][km1+2])+
		    dz4tz1*( ue[3][kp1+2]-2.0*ue[3][k+2] +ue[3][km1+2]);

		  forcing[c][4][i][j][k] = forcing[c][4][i][j][k]
		    - tz2 * (buf[3][kp1+2]*(c1*ue[4][kp1+2]-c2*q[kp1+2])-
			     buf[3][km1+2]*(c1*ue[4][km1+2]-c2*q[km1+2]))+
		    0.5*zzcon3*(buf[0][kp1+2]-2.0*buf[0][k+2]
				+buf[0][km1+2])+
		    zzcon4*(cuf[kp1+2]-2.0*cuf[k+2]+cuf[km1+2])+
		    zzcon5*(buf[4][kp1+2]-2.0*buf[4][k+2]+buf[4][km1+2])+
		    dz5tz1*( ue[4][kp1+2]-2.0*ue[4][k+2]+ ue[4][km1+2]);
		}
	      
	      /*--------------------------------------------------------------------
		c            Fourth-order dissipation                        
		c-------------------------------------------------------------------*/
	      if( startc[c][2] > 0 )
		{
		  for (m = 0; m < 5; m++)
		    {
		      k = 1;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(5.0*ue[m][k+2] - 4.0*ue[m][k+1+2] +ue[m][k+2+2]);
		      k = 2;
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
			(-4.0*ue[m][k-1+2] + 6.0*ue[m][k+2] -
			 4.0*ue[m][k+1+2] + ue[m][k+2+2]);
		    }
		}

	      for (m = 0; m < 5; m++)
		{
		  for (k = startc[c][2]*3; k < cell_size[c][2]-3*endc[c][2]; k++)
		    {
		      forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp*
			(ue[m][k-2+2] - 4.0*ue[m][k-1+2] +
			 6.0*ue[m][k+2] - 4.0*ue[m][k+1+2] + ue[m][k+2+2]);
		    }
		}
	      
	      if( endc[c][2] > 0 )
		{
		  for (m = 0; m < 5; m++)
		    {
		      k = cell_size[c][2]-3;
		    forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
		      (ue[m][k-2+2] - 4.0*ue[m][k-1+2] +
		       6.0*ue[m][k+2] - 4.0*ue[m][k+1+2]);
		    k = cell_size[c][2]-2;
		    forcing[c][m][i][j][k] = forcing[c][m][i][j][k] - dssp *
		      (ue[m][k-2+2] - 4.0*ue[m][k-1+2] + 5.0*ue[m][k+2]);
		    }
		}
	    }
	}

      /*--------------------------------------------------------------------
	c now change the sign of the forcing function, 
	c-------------------------------------------------------------------*/
      for (m = 0; m < 5; m++)
	{
	  for (i = startc[c][0]; i < cell_size[c][0]-endc[c][0]; i++)
	    {
	      for (j = startc[c][1]; j < cell_size[c][1]-endc[c][1]; j++)
		{
		  for (k = startc[c][2]; k < cell_size[c][2]-endc[c][2]; k++)
		    {
		      forcing[c][m][i][j][k] = -1.0 * forcing[c][m][i][j][k];
		    }
		}
	    }
	}
    }
}

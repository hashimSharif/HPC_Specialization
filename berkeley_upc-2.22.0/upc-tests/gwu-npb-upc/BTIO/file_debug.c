/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void file_debug( void )
{
  int i, j, k, c, m, n, l;
  FILE *outf;
  
  if( MYTHREAD == 0 )
    {
      outf = fopen("bt.O3.txt", "wt");
      if( outf == NULL )
	printf(" error opening ...\n" );
      else
	{
	  fprintf(outf, "     dt = %24.12lf\n", dt );
	  for( m=0; m<5; m++ )
	    {
	      fprintf( outf, "ce[][m=%d] = [ ", m );
	      for( i=0; i<13; i++ )
		{
		  fprintf(outf, "%24.12lf ", ce[i][m] );
		}
	      fprintf( outf, "]\n");
	    }
	  fprintf(outf, "      c = %24.12lf %24.12lf %24.12lf %24.12lf %24.12lf\n",
		  c1, c2, c3, c4, c5 );
	  fprintf(outf, "     bt = %24.12lf\n", bt );
	  fprintf(outf, "  dn?m1 = %24.12lf, %24.12lf, %24.12lf\n",
		  dnxm1, dnym1, dnzm1 );
	  fprintf(outf, "     cp = %24.12lf %24.12lf %24.12lf %24.12lf %24.12lf\n",
		  c1c2, c1c5, c3c4, c1345, conz1 );
	  fprintf(outf, "    tx? = %24.12lf, %24.12lf, %24.12lf\n",
		  tx1, tx2, tx3 );
	  fprintf(outf, "    ty? = %24.12lf, %24.12lf, %24.12lf\n",
		  ty1, ty2, ty3 );
	  fprintf(outf, "    tz? = %24.12lf, %24.12lf, %24.12lf\n",
		  tz1, tz2, tz3 );
	  fprintf(outf, "    dx? = %24.12lf, %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  dx1, dx2, dx3, dx4, dx5 );
	  fprintf(outf, "    dy? = %24.12lf, %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  dy1, dy2, dy3, dy4, dy5 );
	  fprintf(outf, "    dz? = %24.12lf, %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  dz1, dz2, dz3, dz4, dz5 );
	  fprintf(outf, "  d?max = %24.12lf, %24.12lf, %24.12lf\n",
		  dxmax, dymax, dzmax );
	  fprintf(outf, "   dssp = %24.12lf %24.12lf %24.12lf\n", 
		  dssp, c4dssp, c5dssp );
	  fprintf(outf, "  dtt?? = [%24.12lf, %24.12lf] [%24.12lf, %24.12lf] [%24.12lf, %24.12lf]\n",
		  dttx1, dttx2, dtty1, dtty2, dttz1, dttz2 );
	  fprintf(outf, "c2dtt?1 = %24.12lf, %24.12lf, %24.12lf\n",
		  c2dttx1, c2dtty1, c2dttz1 );
	  fprintf(outf, "  comz? = %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  comz1, comz4, comz5, comz6 );
	  fprintf(outf, "c3c4t?3 = %24.12lf, %24.12lf, %24.12lf\n",
		  c3c4tx3, c3c4ty3, c3c4tz3 );
	  fprintf(outf, " dx?tx1 = %24.12lf, %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  dx1tx1, dx2tx1, dx3tx1, dx4tx1, dx5tx1 );
	  fprintf(outf, " dy?ty1 = %24.12lf, %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  dy1ty1, dy2ty1, dy3ty1, dy4ty1, dy5ty1 );
	  fprintf(outf, " dz?tz1 = %24.12lf, %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  dz1tz1, dz2tz1, dz3tz1, dz4tz1, dz5tz1 );
	  fprintf(outf, "c2iv,co = %24.12lf, %24.12lf, %24.12lf\n",
		  c2iv, con43, con16 );
	  fprintf(outf, " xxcon? = %24.12lf, %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  xxcon1, xxcon2, xxcon3, xxcon4, xxcon5 );
	  fprintf(outf, " yycon? = %24.12lf, %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  yycon1, yycon2, yycon3, yycon4, yycon5 );
	  fprintf(outf, " zzcon? = %24.12lf, %24.12lf, %24.12lf, %24.12lf, %24.12lf\n",
		  zzcon1, zzcon2, zzcon3, zzcon4, zzcon5 );

	  for (c = 0; c < ncells; c++ )
	    {
	      for( i=0; i<THREADS; i++ )
		{
		  fprintf( outf, " cell[%d]: TH%02d: size=[%d %d %d]\n",
			   (c+1), i, 
			   sh_cell_size[i][c][0],
			   sh_cell_size[i][c][1],
			   sh_cell_size[i][c][2]);
		}
	      fprintf( outf, " cell[%d]: low =[%d %d %d], high=[%d %d %d], startc=[%d %d %d], endc=[%d %d %d]\n",
		       (c+1),
		       cell_low[c][0],
		       cell_low[c][1],
		       cell_low[c][2],
		       cell_high[c][0],
		       cell_high[c][1],
		       cell_high[c][2],
		       startc[c][0],
		       startc[c][1],
		       startc[c][2],
		       endc[c][0],
		       endc[c][1],
		       endc[c][2] );

	      for( i=0; i<IMAX+2; i++ )
		{
		  for( j=0; j<JMAX+2; j++ )
		    {
		      for( k=0; k<KMAX+2; k++ )
			{
			  fprintf(outf, " us[%3d%3d%3d%3d] =%24.12lf\n",
				  (c+1), i, j, k, 
				  us[c][i][j][k] );
			  fprintf(outf, " vs[%3d%3d%3d%3d] =%24.12lf\n",
				  (c+1), i, j, k, 
				  vs[c][i][j][k] );
			  fprintf(outf, " ws[%3d%3d%3d%3d] =%24.12lf\n",
				  (c+1), i, j, k, 
				  ws[c][i][j][k] );
			  fprintf(outf, " qs[%3d%3d%3d%3d] =%24.12lf\n",
				  (c+1), i, j, k, 
				  qs[c][i][j][k] );
			  fprintf(outf, " rho_i[%3d%3d%3d%3d] =%24.12lf\n",
				  (c+1), i, j, k, 
				  rho_i[c][i][j][k] );
			  fprintf(outf, " square[%3d%3d%3d%3d] =%24.12lf\n",
				  (c+1), i, j, k, 
				  square[c][i][j][k] );
			}
		    }
		}

	      for( i=0; i<IMAX+4; i++ )
		{
		  for( j=0; j<JMAX+4; j++ )
		    {
		      for( k=0; k<KMAX+4; k++ )
			{
			  for (m = 0; m < 5; m++ )
			    {
			      fprintf(outf, " u[MYTHREAD].local[%3d%3d%3d%3d%3d] =%24.12lf\n",
				      (c+1), (m+1), i, j, k, 
				      u_priv_d(c,i,j,k,m) );
			    }
			}
		    }
		}

	      for (m = 0; m < 5; m++ )
		{
		  for( i=0; i<IMAX; i++ )
		    {
		      for( j=0; j<JMAX; j++ )
			{
			  for( k=0; k<KMAX; k++ )
			    {
			      fprintf(outf, " forcing[%3d%3d%3d%3d%3d] =%24.12lf\n",
				      (c+1), (m+1), i, j, k, 
				      forcing[c][m][i][j][k] );
			    }
			}
		    }
		}

	      for (m = 0; m < 5; m++ )
		{
		  for( i=0; i<IMAX+1; i++ )
		    {
		      for( j=0; j<JMAX+1; j++ )
			{
			  for( k=0; k<KMAX+1; k++ )
			    {
			      fprintf(outf, " rhs[MYTHREAD].local[%3d%3d%3d%3d%3d] =%24.12lf\n",
				      (c+1), (m+1), i, j, k, 
				      rhs_priv_d(c,i,j,k,m) );
			    }
			}
		    }
		}
	      for( m=0; m<5; m++ )
		{
		  for( n=0; n<5; n++ )
		    {
		      for( i=0; i<IMAX+1; i++ )
			{
			  for( j=0; j<JMAX+1; j++ )
			    {
			      for( k=0; k<KMAX+1; k++ )
				{
				  fprintf(outf, " fjac[%3d%3d%3d%3d%3d] =%32.12lf\n",
					  (m+1), (n+1), i, j, k, 
					  fjac[i][j][k][n][m] );
				  fprintf(outf, " njac[%3d%3d%3d%3d%3d] =%32.12lf\n",
					  (m+1), (n+1), i, j, k, 
					  njac[i][j][k][n][m] );
				}
			    }
			}
		    }
		}
	      for( m=0; m<5; m++ )
		{
		  for( n=0; n<5; n++ )
		    {
		      for( l=0; l<3; l++ )
			    {
			      for( i=0; i<IMAX+1; i++ )
				{
				  for( j=0; j<JMAX+1; j++ )
				    {
				      for( k=0; k<KMAX+1; k++ )
					{
					  fprintf(outf, " lhs[MYTHREAD].local[%3d%3d%3d%3d%3d%3d%3d] =%16.12lf\n",
					      (c+1), m+1, n+1, l+1, i, j, k, 
					      lhs_priv_d(c,i,j,k,l,n,m) );
				    }
				}
			    }
			}
		    }
		}
	    }
	  fclose( outf );
	}
    }
}

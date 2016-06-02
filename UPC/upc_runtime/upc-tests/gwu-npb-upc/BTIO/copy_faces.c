/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void copy_faces(void)
{
  int i1, j1, k1, c1,i2,j2,k2,c2,i,j,c,p4, p5, b_size[6];
  int suc0,suc1,suc2,pre0,pre1,pre2;
  int ss[6], sr[6];
  double *sh_buf_priv;
  shared [] double *sh_arr;

  if( THREADS == 1 )
    {
#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs()\n");
#endif
      compute_rhs();
    }
  else
    {
      ss[0] = start_send_east;
      ss[1] = start_send_west;
      ss[2] = start_send_north;
      ss[3] = start_send_south;
      ss[4] = start_send_top;
      ss[5] = start_send_bottom;
      
      sr[0] = start_recv_east;
      sr[1] = start_recv_west;
      sr[2] = start_recv_north;
      sr[3] = start_recv_south;
      sr[4] = start_recv_top;
      sr[5] = start_recv_bottom;
      
      b_size[4] = top_size;
      b_size[5] = bottom_size;

      upc_barrier;
      
      //BLOCK1
      suc0= successor[0];
      u_th_arr = (shared [] double *)&u[suc0].local[0][0][0][0][0];

      for (c = 0; c <ncells ; c++)
	{
	  if(sh_cell_coord[MYTHREAD][c][0]!=ncells)
	    {
	      for(i=0;i<2;i++)
		{
		  for(j=0;j< sh_cell_size[MYTHREAD][c][1];j++)
		    {			
		      /*
		      upc_memput(&u[suc0].local[c][i][j+2][2][0],
				 &u_priv->local[c][i+sh_cell_size[MYTHREAD][c][0]][j+2][2][0],
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]) );
		      */
		      /*
		      upc_memcpy(&u[suc0].local[c][i][j+2][2][0],
				 &u[MYTHREAD].local[c][i+sh_cell_size[MYTHREAD][c][0]][j+2][2][0],
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]) );
		      */
		      upc_memput(&u_th_d(c,i,j+2,2,0),
				 &u_priv_d(c,i+sh_cell_size[MYTHREAD][c][0],j+2,2,0),
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]) );
		    }
		}
	    }
	}

      //BLOCK2
      pre0= predecessor[0];
      u_th_arr = (shared [] double *)&u[pre0].local[0][0][0][0][0];

      for (c=0;c<ncells;c++)
	{
	  if(sh_cell_coord[MYTHREAD][c][0]!=1)
	    {
	      for(i=0;i<2;i++)
		{
		  for(j=0;j<sh_cell_size[MYTHREAD][c][1];j++)
		    {
		      /*
		      upc_memput(&u[pre0].local[c][i+sh_cell_size[pre0][c][0]+2][j+2][2][0],
				 &u_priv_d(c,i+2,j+2,2,0),
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]) );
		      */
		      /*
		      upc_memcpy(&u[pre0].local[c][i+sh_cell_size[pre0][c][0]+2][j+2][2][0],
				 &u[MYTHREAD].local[c][i+2][j+2][2][0],
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]) );
		      */
		      upc_memput(&u_th_d(c,i+sh_cell_size[pre0][c][0]+2,j+2,2,0),
				 &u_priv_d(c,i+2,j+2,2,0),
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]) );
		    }
		}
	    }
	}

      //BLOCK-3
      suc1=successor[1];
      u_th_arr = (shared [] double *)&u[suc1].local[0][0][0][0][0];

      for(c=0;c<ncells;c++)
	{
	  if (sh_cell_coord[MYTHREAD][c][1]!=ncells)
	    {
	      for(i=0;i<sh_cell_size[MYTHREAD][c][0];i++)
		{
		  for(j=0;j<2;j++)
		    {	
		      /*
		      upc_memput(&u[suc1].local[c][i+2][j][2][0],
				 &u_priv_d(c,i+2,j+sh_cell_size[MYTHREAD,c,1)][2][0],
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]));
		      */
		      /*
		      upc_memcpy(&u[suc1].local[c][i+2][j][2][0],
				 &u[MYTHREAD].local[c][i+2][j+sh_cell_size[MYTHREAD][c][1]][2][0],
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]));
		      */
		      upc_memput(&u_th_d(c,i+2,j,2,0),
				 &u_priv_d(c,i+2,j+sh_cell_size[MYTHREAD][c][1],2,0),
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]) );
		    }
		}
	    }
	}

      //BLOCK-4
      pre1=predecessor[1];
      u_th_arr = (shared [] double *)&u[pre1].local[0][0][0][0][0];

      for(c=0;c<ncells;c++)
	{
	  if(sh_cell_coord[MYTHREAD][c][1]!=1)
	    {
	      for(i=0;i<sh_cell_size[MYTHREAD][c][0];i++)
		{
		  for(j=0;j<2;j++)
		    {
		      /*
		      upc_memput(&u[pre1].local[c][i+2][j+sh_cell_size[pre1][c][1]+2][2][0],
				 &u_priv_d(c,i+2,j+2,2,0),
				 sizeof(double)*5 *(sh_cell_size[MYTHREAD][c][2]));
		      */
		      /*
		      upc_memcpy(&u[pre1].local[c][i+2][j+sh_cell_size[pre1][c][1]+2][2][0],
				 &u[MYTHREAD].local[c][i+2][j+2][2][0],
				 sizeof(double)*5 *(sh_cell_size[MYTHREAD][c][2]));
		      */
		      upc_memput(&u_th_d(c,i+2,j+sh_cell_size[pre1][c][1]+2,2,0),
				 &u_priv_d(c,i+2,j+2,2,0),
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]) );
		    }
		}
	    }
	}
	
      //BLOCK-5 (packing)
      suc2=successor[2];

      for( c1=0, p4=0; c1<ncells; c1++ )
	{
	  if( sh_cell_coord[MYTHREAD][c1][2] != ncells )
	    {
	      k1 = sh_cell_size[MYTHREAD][c1][2];
	      for( i1=2; i1<sh_cell_size[MYTHREAD][c1][0]+2; i1++ )
		{
		  for( j1=2; j1<sh_cell_size[MYTHREAD][c1][1]+2; j1++, p4+=10 )
		    {
		      priv_buf[p4] = u_priv_d(c1,i1,j1,k1,0);
		      priv_buf[p4+1] = u_priv_d(c1,i1,j1,k1,1);
		      priv_buf[p4+2] = u_priv_d(c1,i1,j1,k1,2);
		      priv_buf[p4+3] = u_priv_d(c1,i1,j1,k1,3);
		      priv_buf[p4+4] = u_priv_d(c1,i1,j1,k1,4);

		      priv_buf[p4+5] = u_priv_d(c1,i1,j1,k1+1,0);
		      priv_buf[p4+6] = u_priv_d(c1,i1,j1,k1+1,1);
		      priv_buf[p4+7] = u_priv_d(c1,i1,j1,k1+1,2);
		      priv_buf[p4+8] = u_priv_d(c1,i1,j1,k1+1,3);
		      priv_buf[p4+9] = u_priv_d(c1,i1,j1,k1+1,4);
		    }
		}
	    }
	}

      upc_memput( &sh_buf[suc2][0],
		  &priv_buf[0],
		  sizeof(double)* b_size[4]);


      //BLOCK-6 (packing)
      pre2=predecessor[2];
      for( c1=0, p5=BUF_SIZE; c1<ncells; c1++ )
	{
	  if( sh_cell_coord[MYTHREAD][c1][2] != 1 )
	    {
	      for( i1=2; i1<sh_cell_size[MYTHREAD][c1][0]+2; i1++ )
		{
		  for( j1=2; j1<sh_cell_size[MYTHREAD][c1][1]+2; j1++, p5+=10 )
		    {
		      priv_buf[p5]   = u_priv_d(c1,i1,j1,2,0);
		      priv_buf[p5+1] = u_priv_d(c1,i1,j1,2,1);
		      priv_buf[p5+2] = u_priv_d(c1,i1,j1,2,2);
		      priv_buf[p5+3] = u_priv_d(c1,i1,j1,2,3);
		      priv_buf[p5+4] = u_priv_d(c1,i1,j1,2,4);

		      priv_buf[p5+5] = u_priv_d(c1,i1,j1,3,0);
		      priv_buf[p5+6] = u_priv_d(c1,i1,j1,3,1);
		      priv_buf[p5+7] = u_priv_d(c1,i1,j1,3,2);
		      priv_buf[p5+8] = u_priv_d(c1,i1,j1,3,3);
		      priv_buf[p5+9] = u_priv_d(c1,i1,j1,3,4);
		    }
		}
	    }
	}

      upc_memput( &sh_buf[pre2][BUF_SIZE],
		  &priv_buf[BUF_SIZE],
		  sizeof(double)* b_size[5]);

      upc_barrier;

      sh_buf_priv = (double *) &sh_buf[MYTHREAD][0];

      // BLOCK 5 (unpacking)
      for( c2=0, p4=0; c2<ncells; c2++ )
	{
	  if( sh_cell_coord[MYTHREAD][c2][2] != 1 )
	    {
	      for( i2=2; i2<sh_cell_size[MYTHREAD][c2][0]+2; i2++ )
		{
		  for( j2=2; j2<sh_cell_size[MYTHREAD][c2][1]+2; j2++, p4+=10 )
		    {
		      u_priv_d(c2,i2,j2,0,0) = sh_buf_priv[p4];
		      u_priv_d(c2,i2,j2,0,1) = sh_buf_priv[p4+1];
		      u_priv_d(c2,i2,j2,0,2) = sh_buf_priv[p4+2];
		      u_priv_d(c2,i2,j2,0,3) = sh_buf_priv[p4+3];
		      u_priv_d(c2,i2,j2,0,4) = sh_buf_priv[p4+4];
			
		      u_priv_d(c2,i2,j2,1,0) = sh_buf_priv[p4+5];
		      u_priv_d(c2,i2,j2,1,1) = sh_buf_priv[p4+6];
		      u_priv_d(c2,i2,j2,1,2) = sh_buf_priv[p4+7];
		      u_priv_d(c2,i2,j2,1,3) = sh_buf_priv[p4+8];
		      u_priv_d(c2,i2,j2,1,4) = sh_buf_priv[p4+9];
		    }
		}
	    }
	}

      sh_buf_priv += BUF_SIZE;
      // BLOCK 6 (unpacking)
      for( c2=0, p5=0; c2<ncells; c2++ )
	{
	  if( sh_cell_coord[MYTHREAD][c2][2] != ncells )
	    {
	      k2 = sh_cell_size[MYTHREAD][c2][2] + 2;
	      for( i2=2; i2<sh_cell_size[MYTHREAD][c2][0]+2; i2++ )
		{
		  for( j2=2; j2<sh_cell_size[MYTHREAD][c2][1]+2; j2++, p5+=10 )
		    {
		      u_priv_d(c2,i2,j2,k2,0) = sh_buf_priv[p5];
		      u_priv_d(c2,i2,j2,k2,1) = sh_buf_priv[p5+1];
		      u_priv_d(c2,i2,j2,k2,2) = sh_buf_priv[p5+2];
		      u_priv_d(c2,i2,j2,k2,3) = sh_buf_priv[p5+3];
		      u_priv_d(c2,i2,j2,k2,4) = sh_buf_priv[p5+4];
			
		      u_priv_d(c2,i2,j2,k2+1,0) = sh_buf_priv[p5+5];
		      u_priv_d(c2,i2,j2,k2+1,1) = sh_buf_priv[p5+6];
		      u_priv_d(c2,i2,j2,k2+1,2) = sh_buf_priv[p5+7];
		      u_priv_d(c2,i2,j2,k2+1,3) = sh_buf_priv[p5+8];
		      u_priv_d(c2,i2,j2,k2+1,4) = sh_buf_priv[p5+9];
		    }
		}
	    }
	}

#if (DEBUG == TRUE)
      if( MYTHREAD == 0 )
	printf(" (D) compute_rhs()\n");
#endif
      compute_rhs();
    }
}

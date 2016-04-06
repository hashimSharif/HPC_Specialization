/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void make_set(void)
{
  int p, i, j, c, dir, size, excess;
  int me = MYTHREAD;
  double d;

  d = THREADS;
  ncells = (int) (sqrt( d + 0.00001 ));
  //  ncells = (int) (sqrt( ((double) THREADS) + 0.00001));

  p = ncells;

  cell_coord[0][0] = me%p;
  cell_coord[0][1] = me/p;
  cell_coord[0][2] = 0;

  for (c = 1; c < p; c++ )
    {
      cell_coord[c][0] = (cell_coord[c-1][0]+1)%p;
      cell_coord[c][1] = (cell_coord[c-1][1]-1+p)%p;
      cell_coord[c][2] = c;
    }

  for (dir = 0; dir < 3; dir++ )
    {
      for (c = 0; c < p; c++ )
	{
	  cell_coord[c][dir] = cell_coord[c][dir] + 1;
	}
    }

  for (dir = 0; dir < 3; dir++ )
    {
      for (c = 0; c < p; c++ )
	{
	  slice[cell_coord[c][dir]-1][dir] = c;
	  slice_sh[MYTHREAD][cell_coord[c][dir]-1][dir] = c;
	}
    }
  upc_barrier;
  for(i=0;i<THREADS;i++)
    {
      for (c = 0; c < p; c++ )
	{
	  for (dir = 0; dir < 3; dir++ )
	    sh_slice[i][c][dir] = slice_sh[i][c][dir] ;
	}
    }
  upc_barrier;

  i = cell_coord[0][0] - 1;
  j = cell_coord[0][1] - 1;
  predecessor[0] = ((i-1+p)%p) + p*j;
  predecessor[1] = i + p*((j-1+p)%p);
  predecessor[2] = ((i+1)%p) + p*((j-1+p)%p);
  successor[0] = ((i+1)%p) + p*j;
  successor[1] = i + p*((j+1)%p);
  successor[2] = ((i-1+p)%p) + p*((j+1)%p);
#if( DEBUG == TRUE )
    printf(" (D) -- SUCCESSORs : %d %d %d / PREDECESSORs : %d %d %d --\n",
	   successor[0], successor[1], successor[2],
	   predecessor[0], predecessor[1], predecessor[2]);
#endif

  for (dir = 0; dir < 3; dir++ )
    {
      size = grid_points[dir]/p;
      excess = grid_points[dir]%p;
      for (c = 0; c < ncells; c++ )
	{
	  if( cell_coord[c][dir] <= excess )
	    {
	      cell_size[c][dir] = size+1;
	      cell_low[c][dir] = (cell_coord[c][dir]-1)*(size+1);
	      cell_high[c][dir] = cell_low[c][dir]+size;
	    }
	  else
	    {
	      cell_size[c][dir] = size;
	      cell_low[c][dir] = excess*(size+1) +
		(cell_coord[c][dir]-excess-1)*size;
	      cell_high[c][dir] = cell_low[c][dir]+size-1;
	    }

	  if( cell_size[c][dir] <= 2 )
	    printf(" ERROR : Cell size too small ... Min size is 3\n" );
	}
    }

#if( DEBUG == TRUE )
  for (c = 0; c < ncells; c++ )
    {
      printf("TH%02d: cell %d : (X) %d to %d / (Y) %d to %d / (Z) %d to %d\n",
	     MYTHREAD, c+1, cell_low[c][0], cell_high[c][0],
	     cell_low[c][1], cell_high[c][1],
	     cell_low[c][2], cell_high[c][2] );
      printf("TH%02d: cell %d : coord %4d %4d %4d\n",
	     MYTHREAD, c+1, cell_coord[c][0], cell_coord[c][1], cell_coord[c][2]);
      printf("TH%02d: cell %d : size %4d %4d %4d\n",
	     MYTHREAD, c+1, cell_size[c][0], cell_size[c][1], cell_size[c][2]);
    }
#endif
}

/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#include <stdio.h>
#include <upc_relaxed.h>
#include "functions.h"

void compute_buffer_size(int dim)
{
  int c, face_size;

  for (c = 0; c < 6; c++ )
    {
      sr_s[MYTHREAD].t[c] = 0;
    }

  if( ncells == 1 )
    return;

  west_size = 0;
  east_size = 0;

  for (c = 0; c < ncells; c++ )
    {
      face_size = cell_size[c][1] * cell_size[c][2] * dim * 2;
      if( cell_coord[c][0] != 1 )
	west_size = west_size + face_size;
      if( cell_coord[c][0] != ncells )
	east_size = east_size + face_size;
    }

  north_size = 0;
  south_size = 0;

  for (c = 0; c < ncells; c++ )
    {
      face_size = cell_size[c][0] * cell_size[c][2] * dim * 2;
      if( cell_coord[c][1] != 1 )
	south_size = south_size + face_size;
      if( cell_coord[c][1] != ncells )
	north_size = north_size + face_size;
    }

  top_size = 0;
  bottom_size = 0;

  for (c = 0; c < ncells; c++ )
    {
      face_size = cell_size[c][0] * cell_size[c][1] * dim * 2;
      if( cell_coord[c][2] != 1 )
	bottom_size = bottom_size + face_size;
      if( cell_coord[c][2] != ncells )
	top_size = top_size + face_size;
    }

  start_send_west = 1;
  start_send_east = start_send_west + west_size;
  start_send_south = start_send_east + east_size;
  start_send_north = start_send_south + south_size;
  start_send_bottom = start_send_north + north_size;
  start_send_top = start_send_bottom + bottom_size;

  start_recv_west = 1;
  start_recv_east = start_recv_west + west_size;
  start_recv_south = start_recv_east + east_size;
  start_recv_north = start_recv_south + south_size;
  start_recv_bottom = start_recv_north + north_size;
  start_recv_top = start_recv_bottom + bottom_size;

  // now full up the shared arrays
  sr_s[MYTHREAD].t[0] = start_recv_east;
  sr_s[MYTHREAD].t[1] = start_recv_west;
  sr_s[MYTHREAD].t[2] = start_recv_north;
  sr_s[MYTHREAD].t[3] = start_recv_south;
  sr_s[MYTHREAD].t[4] = start_recv_top;
  sr_s[MYTHREAD].t[5] = start_recv_bottom;
  upc_barrier;

  // local copy
  for (c = 0; c < THREADS; c++ )
    {
      upc_barrier;
      upc_memget( &sr_c[c][0], &sr_s[c].t[0], sizeof( int [6] ));
    }
}

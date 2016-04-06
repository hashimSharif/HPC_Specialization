/*--------------------------------------------------------------------

  NAS Parallel Benchmarks 2.3 UPC versions - BT

  This benchmark is an UPC version of the NPB BT code.

  The UPC versions are developed by HPCL-GWU and are derived from
  the OpenMP version (developed by RWCP) and from the MPI version
  (developed by NAS).

  Permission to use, copy, distribute and modify this software for any
  purpose with or without fee is hereby granted.
  This software is provided "as is" without express or implied warranty.

  Information on the UPC project at GWU is available at:

           http://upc.gwu.edu

  Information on NAS Parallel Benchmarks 2.3 is available at:

           http://www.nas.nasa.gov/NAS/NPB/

--------------------------------------------------------------------*/
/*---- FULLY OPTIMIZED VERSION (privatized&prefetching) - DEC 2003 -*/
/*--------------------------------------------------------------------
  UPC version:  F. Cantonnet  - GWU - HPCL (fcantonn@gwu.edu)
                S. Annareddy  - GWU - HPCL (asmita@gwu.edu)
                T. El-Ghazawi - GWU - HPCL (tarek@gwu.edu)

  Authors(NAS): R. Van der Wijngaart
                W. Saphir
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. This program
 can be freely redistributed provided that you conspicuously and
 appropriately publish on each copy an appropriate referral notice to
 the authors and disclaimer of warranty; keep intact all the notices
 that refer to this License and to the absence of any warranty; and
 give any other recipients of the Program a copy of this License along
 with the Program.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
--------------------------------------------------------------------*/

#include <string.h>
#include <upc.h>
#include <upc_io.h>
#include "upc_timers.h"

#include "functions.h"

/* global variables */
#if 0
#include "npbparams.h"

//#define MAX_CELL_DIM (PROBLEM_SIZE/maxcells)+1
//#define BUF_SIZE     (MAX_CELL_DIM*MAX_CELL_DIM*(maxcells-1)*60)+1

#define DEBUG FALSE
#define FILE_DEBUG 0

#define AA      0
#define BB      1
#define CC      2
#define BLOCK_SIZE 5
#define	IMAX	MAX_CELL_DIM
#define	JMAX	MAX_CELL_DIM
#define	KMAX	MAX_CELL_DIM

typedef struct sr_sd_s sr_sd_t;
typedef struct sr_s_s sr_s_t;

struct sr_s_s 
{
  int t[6];
};

struct sr_sd_s 
{
  double t[5];
};

typedef struct U_shared u_t;
struct U_shared
{
  double local[maxcells][IMAX+4][JMAX+4][KMAX+4][5];
};

typedef struct lhs_s lhs_t;
struct lhs_s
{
  double local[maxcells][IMAX+1][JMAX+1][KMAX+1][3][5][5];
};

typedef struct rhs_s rhs_t;
struct rhs_s
{
  double local[maxcells][IMAX+1][JMAX+1][KMAX+1][5];
};

typedef struct backsub_info_s backsub_info_t;

struct backsub_info_s
{
  //double local[maxcells][5][MAX_CELL_DIM+1][MAX_CELL_DIM+1];
  double local[maxcells][MAX_CELL_DIM+1][MAX_CELL_DIM+1][5];
};
#endif

shared double dt_s;

shared int grid_points_s[3], niter_s;

shared sr_sd_t sr_d_s[THREADS];
shared sr_s_t sr_s[THREADS];

int ncells, grid_points[3];
int sr_c[THREADS][6];

double tx1, tx2, tx3, ty1, ty2, ty3, tz1, tz2, tz3, 
              dx1, dx2, dx3, dx4, dx5, dy1, dy2, dy3, dy4, 
              dy5, dz1, dz2, dz3, dz4, dz5, dssp, dt, 
              ce[13][5], dxmax, dymax, dzmax, xxcon1, xxcon2, 
              xxcon3, xxcon4, xxcon5, dx1tx1, dx2tx1, dx3tx1,
              dx4tx1, dx5tx1, yycon1, yycon2, yycon3, yycon4,
              yycon5, dy1ty1, dy2ty1, dy3ty1, dy4ty1, dy5ty1,
              zzcon1, zzcon2, zzcon3, zzcon4, zzcon5, dz1tz1, 
              dz2tz1, dz3tz1, dz4tz1, dz5tz1, dnxm1, dnym1, 
              dnzm1, c1c2, c1c5, c3c4, c1345, conz1, c1, c2, 
              c3, c4, c5, c4dssp, c5dssp, dtdssp, dttx1, bt,
              dttx2, dtty1, dtty2, dttz1, dttz2, c2dttx1, 
              c2dtty1, c2dttz1, comz1, comz4, comz5, comz6, 
              c3c4tx3, c3c4ty3, c3c4tz3, c2iv, con43, con16;


int cell_coord[maxcells][3], cell_size[maxcells][3], cell_low[maxcells][3];
int cell_high[maxcells][3], grid_size[3];
int slice[maxcells][3], startc[maxcells][3], endc[maxcells][3];

int predecessor[3], successor[3];

double        us      [maxcells][IMAX+2][JMAX+2][KMAX+2],
              vs      [maxcells][IMAX+2][JMAX+2][KMAX+2],
              ws      [maxcells][IMAX+2][JMAX+2][KMAX+2],
              qs      [maxcells][IMAX+2][JMAX+2][KMAX+2],
              rho_i   [maxcells][IMAX+2][JMAX+2][KMAX+2],
	      square  [maxcells][IMAX+2][JMAX+2][KMAX+2],
              forcing [maxcells][5][IMAX][JMAX][KMAX];

double fjac[IMAX+4][JMAX+4][KMAX+4][5][5], njac[IMAX+4][JMAX+4][KMAX+4][5][5],
       tmp1, tmp2, tmp3, tmp_block[5][5], b_inverse[5][5], tmp_vec[5];

double          cv[MAX_CELL_DIM+4], rhon[MAX_CELL_DIM+4],
              rhos[MAX_CELL_DIM+4], rhoq[MAX_CELL_DIM+4],
              cuf[MAX_CELL_DIM+4], q[MAX_CELL_DIM+4],
              ue[5][MAX_CELL_DIM+4], buf[5][MAX_CELL_DIM+4];

int west_size, east_size, bottom_size, top_size, north_size, south_size;
int start_send_west, start_send_east, start_send_bottom, start_send_top,
           start_send_north, start_send_south;
int start_recv_west, start_recv_east, start_recv_bottom, start_recv_top,
           start_recv_north, start_recv_south;
int idump;

//for prefetching
double priv_buf[BUF_SIZE*2];
shared [BUF_SIZE*2] double sh_buf[THREADS][BUF_SIZE*2]; 
//------------
shared u_t *u;

shared lhs_t *lhs;

shared rhs_t *rhs;

shared backsub_info_t *backsub_info;

shared int cell_size_sh[THREADS][maxcells][3],
  cell_coord_sh[THREADS][maxcells][3];

double *u_priv_arr, *lhs_priv_arr, *rhs_priv_arr, *backsub_info_priv_arr;

shared [] double *u_th_arr;

shared [] double *rhs_th_arr;

shared [] double *lhs_th_arr;

//private copy

int sh_cell_size[THREADS][maxcells][3],
  sh_cell_coord[THREADS][maxcells][3];


shared int slice_sh[THREADS][maxcells][3];
int sh_slice[THREADS][maxcells][3];

u_t *u_priv;
lhs_t *lhs_priv;
rhs_t *rhs_priv;
backsub_info_t *backsub_info_priv;

shared int wr_interval;

/*--------------------------------------------------------------------
       program BT
c-------------------------------------------------------------------*/
int main(int argc, char **argv)
{
  int niter, step, n3,i;
  double mflops, tmax, navg;
  int c;
  boolean verified;
  char class;
  FILE *fp;
  int wr_interval_p;

  u = (shared u_t *) upc_all_alloc( THREADS, sizeof( u_t ));
  MEM_OK(u);
  lhs = (shared lhs_t *) upc_all_alloc( THREADS, sizeof( lhs_t ));
  MEM_OK(lhs);
  rhs = (shared rhs_t *) upc_all_alloc( THREADS, sizeof( rhs_t ));
  MEM_OK(rhs);
  backsub_info = (shared backsub_info_t *) upc_all_alloc( THREADS, sizeof( backsub_info_t ));
  MEM_OK(backsub_info);

  /* privatization init. */
  u_priv_arr = (double *)&u[MYTHREAD].local[0][0][0][0][0];
  lhs_priv_arr = (double *)&lhs[MYTHREAD].local[0][0][0][0][0][0][0];
  rhs_priv_arr = (double *)&rhs[MYTHREAD].local[0][0][0][0][0];
  backsub_info_priv_arr = (double *)&backsub_info[MYTHREAD].local[0][0][0][0];

  u_priv = (u_t *) &u[MYTHREAD];
  lhs_priv = (lhs_t *) &lhs[MYTHREAD];
  rhs_priv = (rhs_t *) &rhs[MYTHREAD];
  backsub_info_priv = (backsub_info_t *) &backsub_info[MYTHREAD];

  if( MYTHREAD == 0 )
    {
      printf("\n\n NAS Parallel Benchmarks 2.3 UPC version"
	     " - BT Benchmark \n\n");
    }

  if( MYTHREAD == 0 )
    {
      /*--------------------------------------------------------------------
	c      Read input file (if it exists), else take
	c      defaults from parameters
	c-------------------------------------------------------------------*/
      fp = fopen("inputbt.data", "r");
      if (fp != NULL)
	{
	  printf(" Reading from input file inputbt.data\n");
	  fscanf(fp, "%d", &niter);
	  while (fgetc(fp) != '\n');
	  fscanf(fp, "%lf", &dt);
	  while (fgetc(fp) != '\n');
	  fscanf(fp, "%d%d%d",
		 &grid_points[0], &grid_points[1], &grid_points[2]);
          if(iotype != 0)
          {
                while (fgetc(fp) != '\n');
                fscanf(fp, "%d", &wr_interval_p);
		wr_interval = wr_interval_p;
          }
	  fclose(fp);
	}
      else
	{
	  printf(" No input file inputsp.data. Using compiled defaults");
	  
	  niter = NITER_DEFAULT;
	  dt = DT_DEFAULT;
	  grid_points[0] = PROBLEM_SIZE;
	  grid_points[1] = PROBLEM_SIZE;
	  grid_points[2] = PROBLEM_SIZE;
	  wr_interval = 5;
	}
      
      printf(" Size: %3dx%3dx%3d\n",
	     grid_points[0], grid_points[1], grid_points[2]);
      printf(" Iterations: %3d   dt: %10.6f\n", niter, dt);
      
      grid_points_s[0] = grid_points[0];
      grid_points_s[1] = grid_points[1];
      grid_points_s[2] = grid_points[2];
      dt_s = dt;
      niter_s = niter;
    }
  // synchronization point
  upc_barrier;
  
  // get global params
  grid_points[0] = grid_points_s[0];
  grid_points[1] = grid_points_s[1];
  grid_points[2] = grid_points_s[2];
  dt = dt_s;
  niter = niter_s;

#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) make_set()\n");
#endif
  make_set();
  
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" cell_nb = %d\n", ncells );
#endif
  for( c=0; c<ncells; c++ )
    {
      if( DEBUG )
	printf("TH%02d: cell_size[%d] %d %d %d\n", 
	       MYTHREAD, c, 
	       cell_size[c][0], cell_size[c][1], cell_size[c][2] );
      
      if ( (cell_size[c][0] > IMAX) ||
	   (cell_size[c][1] > JMAX) ||
	   (cell_size[c][2] > KMAX) )
	{
	  printf("%d, %d, %d\n", cell_size[c][0], cell_size[c][1], cell_size[c][2] );
	  printf(" Problem size too big for compiled array sizes\n");
	  exit(1);
	}
    }
  //CHANGES -------------> Dec 19th
  for( c=0; c<ncells; c++ )
    {
      cell_size_sh[MYTHREAD][c][0] = cell_size[c][0];
      cell_size_sh[MYTHREAD][c][1] = cell_size[c][1];
      cell_size_sh[MYTHREAD][c][2] = cell_size[c][2];

      cell_coord_sh[MYTHREAD][c][0] = cell_coord[c][0];
      cell_coord_sh[MYTHREAD][c][1] = cell_coord[c][1];
      cell_coord_sh[MYTHREAD][c][2] = cell_coord[c][2];
    }  
  upc_barrier;
  // optimiziation for Ver O1
  
  for(i=0;i<THREADS;i++)
    {
      for( c=0; c<ncells; c++ )
	{
	  sh_cell_size[i][c][0] = cell_size_sh[i][c][0];
	  sh_cell_size[i][c][1] = cell_size_sh[i][c][1];
	  sh_cell_size[i][c][2] = cell_size_sh[i][c][2];
	  
	  sh_cell_coord[i][c][0] = cell_coord_sh[i][c][0];
	  sh_cell_coord[i][c][1] = cell_coord_sh[i][c][1];
	  sh_cell_coord[i][c][2] = cell_coord_sh[i][c][2];
	}
    }
  
  
  //CHANGES ------------------>
  upc_barrier;
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) set_constants()\n");
#endif
  set_constants();
  
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) initialize()\n");
#endif
  initialize();
  
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) setup_btio()\n");
#endif
  setup_btio();
  idump = 0;

#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) lhsinit()\n");
#endif
  lhsinit();
  
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) exact_rhs()\n");
#endif
  exact_rhs();
  
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    {
      printf(" (D) compute_buffer_size()\n");
    }
#endif
  compute_buffer_size( 5 );
  
  //--------------------------------------------------------------------
  //c      do one time step to touch all code, and reinitialize
  //c-------------------------------------------------------------------
  upc_barrier;
  
  adi();
  
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) initialize()\n");
#endif
  initialize();
  
  upc_barrier;
  
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) -----------------------\n");
#endif
  
  timer_clear(1);
  timer_start(1);
  
  for (step = 1; step <= niter; step++)
    {
      if( (step % 20 == 0 || step == 1) && (MYTHREAD == 0) )
	{
	  printf(" Time step %4d\n", step);
	}
      adi();
  
      if (iotype != 0)
      {
              if ((step%wr_interval==0) || (step==niter))
              {
                  if (MYTHREAD == 0)
                      printf("Writing data set, time step %d\n", step);
                  output_timestep();
                  idump++;
              }
      }
    }

  btio_cleanup();

  if( FILE_DEBUG )
    {
      file_debug();
    }

  timer_stop(1);
  tmax = timer_read(1);
  
#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    printf(" (D) -----------------------\n");
#endif
  
  // get time max
  sr_d_s[MYTHREAD].t[0] = tmax;
  upc_barrier;
  if( MYTHREAD == 0 )
    {
      tmax = sr_d_s[MYTHREAD].t[0];
      for( c=0; c<THREADS; c++ )
	{
	  if( tmax < sr_d_s[c].t[0] )
	    {
	      tmax = sr_d_s[c].t[0];
	    }
	}
    }

#if( DEBUG == TRUE )
  if( MYTHREAD == 0 )
    {
      printf(" (D) verify()\n");
    }
#endif
  
  verify(niter, &class, &verified);
  
  if( MYTHREAD == 0 )
    {
      n3 = grid_points[0] * grid_points[1] * grid_points[2];
      navg = ( grid_points[0] + grid_points[1] + grid_points[2] ) / 3.0;

      if (tmax != 0)
	{
	  mflops = 1.0e-6 * (double)niter *
	    ( 3478.8 * (double)n3 - 17655.7 * pow2( navg )
	      + 28023.7 * navg ) / tmax;
	}
      else
	{
	  mflops = 0.0;
	}
      
      c_print_results("BT", class, grid_points[0],
		      grid_points[1], grid_points[2], niter, THREADS,
		      tmax, mflops, "          floating point", 
		      verified, NPBVERSION, COMPILETIME, NPB_CS1, NPB_CS2, NPB_CS3, NPB_CS4, NPB_CS5, 
		      NPB_CS6, "(none)");
    }
  return 0;
}

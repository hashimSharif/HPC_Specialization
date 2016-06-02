/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#ifndef __H__FUNCTIONS_
#define __H__FUNCTIONS_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* CLASS = B */
/* THREADS = 1 */
/*
c  This file is generated automatically by the setparams utility.
c  It sets the number of processors and the class of the NPB
c  in this directory. Do not modify it by hand.
*/
#define	PROBLEM_SIZE	102
#define	NITER_DEFAULT	200
#define	DT_DEFAULT	0.0003
#define	maxcells	1
#define	MAX_CELL_DIM	103
#define	BUF_SIZE	1
#define	CONVERTDOUBLE	FALSE
#define COMPILETIME "13 Apr 2004"
#define NPBVERSION "2.3"
#define CS1 "$(UPCC)"
#define CS2 "$(UPCC)"
#define CS3 "(none)"
#define CS4 "-I../common"
#define CS5 "-T ${NP}"
#define CS6 "-v -save-all-temps -T ${NP}"
#define CS7 "randdp"

typedef int boolean;
typedef struct { 
  double real; 
  double imag; 
} dcomplex;

#define MEM_OK(var) {                                         \
  if( var == NULL )                                           \
    {                                                         \
      printf("TH%02d: ERROR: %s == NULL\n", MYTHREAD, #var ); \
      upc_global_exit(1);                                     \
    } }

#define TRUE	1
#define FALSE	0

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define	pow2(a) ((a)*(a))

#define get_real(c) c.real
#define get_imag(c) c.imag
#define cadd(c,a,b) (c.real = a.real + b.real, c.imag = a.imag + b.imag)
#define csub(c,a,b) (c.real = a.real - b.real, c.imag = a.imag - b.imag)
#define cmul(c,a,b) (c.real = a.real * b.real - a.imag * b.imag, \
                     c.imag = a.real * b.imag + a.imag * b.real)
#define crmul(c,a,b) (c.real = a.real * b, c.imag = a.imag * b)

extern double randlc(double *, double);
extern void vranlc(int, double *, double, double *);
extern void timer_clear(int);
extern void timer_start(int);
extern void timer_stop(int);
extern double timer_read(int);

extern void c_print_results(char *name, char class, int n1, int n2,
			    int n3, int niter, int nthreads, double t,
			    double mops, char *optype, int passed_verification,
			    char *npbversion, char *compiletime, char *cc,
			    char *clink, char *c_lib, char *c_inc,
			    char *cflags, char *clinkflags, char *rand);


/*--------------------------------------------------------------------
c The following include file is generated automatically by the
c "setparams" utility. It defines 
c      problem_size:  12, 64, 102, 162 (for class T, A, B, C)
c      dt_default:    default time step for this problem size if no
c                     config file
c      niter_default: default number of iterations for this problem size
c AND ALSO
c      maxcells: sqrt(THREADS)
c    MAX_CELL_DIM & BUF_SIZE
c-------------------------------------------------------------------*/

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

extern shared double dt_s;

/* common /global */
extern shared int grid_points_s[3], niter_s;

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

extern shared sr_sd_t sr_d_s[THREADS];
extern shared sr_s_t sr_s[THREADS];

// local copies or pointers
extern int ncells, grid_points[3];
extern int sr_c[THREADS][6];
extern double *b_in_ptr;
extern double *b_out_ptr;

/* common /constants/ */
extern double tx1, tx2, tx3, ty1, ty2, ty3, tz1, tz2, tz3, 
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


extern int cell_coord[maxcells][3], cell_size[maxcells][3], cell_low[maxcells][3];
extern int cell_high[maxcells][3], grid_size[3];
extern int slice[maxcells][3], startc[maxcells][3], endc[maxcells][3];

extern int predecessor[3], successor[3];

/*--------------------------------------------------------------------
c   To improve cache performance, first two dimensions padded by 1 
c   for even number sizes only
c-------------------------------------------------------------------*/

/* common /fields/ */
extern double     us      [maxcells][IMAX+2][JMAX+2][KMAX+2],
                  vs      [maxcells][IMAX+2][JMAX+2][KMAX+2],
                  ws      [maxcells][IMAX+2][JMAX+2][KMAX+2],
                  qs      [maxcells][IMAX+2][JMAX+2][KMAX+2],
                  rho_i   [maxcells][IMAX+2][JMAX+2][KMAX+2],
                  square  [maxcells][IMAX+2][JMAX+2][KMAX+2],
                  forcing [maxcells][5][IMAX][JMAX][KMAX];
          
extern double fjac[IMAX+4][JMAX+4][KMAX+4][5][5], njac[IMAX+4][JMAX+4][KMAX+4][5][5],
  tmp1, tmp2, tmp3, tmp_block[5][5], b_inverse[5][5], tmp_vec[5];

/* common /work_1d/ */
extern double     cv[MAX_CELL_DIM+4], rhon[MAX_CELL_DIM+4],
                  rhos[MAX_CELL_DIM+4], rhoq[MAX_CELL_DIM+4],
                  cuf[MAX_CELL_DIM+4], q[MAX_CELL_DIM+4],
                  ue[5][MAX_CELL_DIM+4], buf[5][MAX_CELL_DIM+4];

extern int west_size, east_size, bottom_size, top_size, north_size, south_size;
extern int start_send_west, start_send_east, start_send_bottom, start_send_top,
           start_send_north, start_send_south;
extern int start_recv_west, start_recv_east, start_recv_bottom, start_recv_top,
           start_recv_north, start_recv_south;

typedef struct U_shared u_t;
struct U_shared
{
  double local[maxcells][IMAX+4][JMAX+4][KMAX+4][5];
};
extern shared u_t *u;

typedef struct lhs_s lhs_t;
struct lhs_s
{
  double local[maxcells][IMAX+1][JMAX+1][KMAX+1][3][5][5];
};

extern shared lhs_t *lhs;

typedef struct rhs_s rhs_t;
struct rhs_s
{
  double local[maxcells][IMAX+1][JMAX+1][KMAX+1][5];
};

extern shared rhs_t *rhs;

typedef struct backsub_info_s backsub_info_t;

struct backsub_info_s
{
  //double local[maxcells][5][MAX_CELL_DIM+1][MAX_CELL_DIM+1];
  double local[maxcells][MAX_CELL_DIM+1][MAX_CELL_DIM+1][5];
};

extern shared backsub_info_t *backsub_info;

extern shared int cell_size_sh[THREADS][maxcells][3],
  cell_coord_sh[THREADS][maxcells][3];

//private copy of cell_size_sh & cell_coord_sh ---->perf. improvement(Ver O1) 
extern  int sh_cell_size[THREADS][maxcells][3],
  sh_cell_coord[THREADS][maxcells][3];


// for prefetching --Ver O3...Dec 22
extern double priv_buf[BUF_SIZE*2];
extern shared [BUF_SIZE*2] double sh_buf[THREADS][BUF_SIZE*2];

extern u_t *u_priv;
extern lhs_t *lhs_priv;
extern rhs_t *rhs_priv;
extern backsub_info_t *backsub_info_priv;
extern shared int slice_sh[THREADS][maxcells][3];
extern int sh_slice[THREADS][maxcells][3];

/* function declarations */
extern void make_set(void);
extern void compute_buffer_size(int dim);
extern void copy_faces(void);
extern void add(void);
extern void adi(void);
extern void file_debug( void );
extern void error_norm(double rms[5]);
extern void rhs_norm(double rms[5]);
extern void exact_rhs(void);
extern void exact_solution(double xi, double eta, double zeta,
			   double dtemp[5]);
extern void initialize(void);
extern void lhsinit(void);
extern void lhsx(int c);
extern void lhsy(int c);
extern void lhsz(int c);
extern void compute_rhs(void);
extern void set_constants(void);
extern void verify(int no_time_steps, char *class, boolean *verified);
extern void x_solve(void);
extern void x_unpack_solve_info( int c , int stage, int c2 );
extern void x_unpack_backsub_info( int c , int c2 );
extern void x_backsubstitute( int first, int last, int c );
extern void x_solve_cell( int first, int last, int c );

extern void matvec_sub( double *, 
			double *, 
			double * );
extern void matmul_sub( double *, 
			double *, 
			double * );

extern void y_solve(void);
extern void y_unpack_solve_info( int c, int c2 );
extern void y_unpack_backsub_info( int c, int c2 );
extern void y_backsubstitute( int first, int last, int c );
extern void y_solve_cell( int first, int last, int c );

extern void z_solve(void);
extern void z_unpack_solve_info( int c, int c2 );
extern void z_unpack_backsub_info( int c , int c2 );
extern void z_backsubstitute( int first, int last, int c );
extern void z_solve_cell( int first, int last, int c );

extern void binvcrhs( double *, 
		      double *, 
		      double * );
extern void binvrhs( double *, 
		     double * );

#endif

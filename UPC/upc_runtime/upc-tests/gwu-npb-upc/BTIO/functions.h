/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC version - BT source code tree
  2004 - GWU - HPCL -- check bt.c for complete information
  --------------------------------------------------------------------*/

#ifndef __H__FUNCTIONS_
#define __H__FUNCTIONS_

#include "header.h"

/* function declarations */
extern void make_set(void);
extern void compute_buffer_size(int dim);
extern void copy_faces(void);
extern void add(void);
extern void adi(void);
extern void file_debug( void );
extern void error_norm(double *rms);
extern void rhs_norm(double *rms);
extern void exact_rhs(void);
extern void exact_solution(double xi, double eta, double zeta,
			   double *dtemp);
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

/* BTIO related functions */
extern void setup_btio();
extern void output_timestep();
extern void clear_timestep();
extern void btio_cleanup();
extern void accumulate_norms(double * xce_acc);

#endif

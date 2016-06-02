#include <upc_relaxed.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "npb-C.h"
#include "upc_timers.h"
#include "npbparams.h"

/* Layout distribution parameters:
 * 2D processor array -> 2D grid decomposition (by pencils)
 * If processor array is 1xN or -> 1D grid decomposition (by planes)
 * If processor array is 1x1 -> 0D grid decomposition */
int np2;
int layout_type; // 0 = layout_0D, 1 = layout_1D, 2 = layout_2D

/* If processor array is 1x1 -> 0D grid decomposition

   Cache blocking params. These values are good for most
   RISC processors.
   FFT parameters:
   fftblock controls how many ffts are done at a time.
   The default is appropriate for most cache-based machines
   On vector machines, the FFT can be vectorized with vector
   length equal to the block size, so the block size should
   be as large as possible. This is the size of the smallest
   dimension of the problem: 128 for class A, 256 for class B and
   512 for class C. */
#define FFTBLOCK_DEFAULT 16
#define FFTBLOCKPAD_DEFAULT 18

#define FFTBLOCK FFTBLOCK_DEFAULT
#define FFTBLOCKPAD FFTBLOCKPAD_DEFAULT

/* COMMON block: blockinfo */
int fftblock;
int fftblockpad;

#define TRANSBLOCK 32
#define TRANSBLOCKPAD 34

/* we need a bunch of logic to keep track of how
   arrays are laid out.

Note: this serial version is the derived from the parallel 0D case
of the ft NPB.
The computation proceeds logically as

set up initial conditions
fftx(1)
transpose(1->2)
ffty(2)
transpose(2->3)
fftz(3)
time evolution
fftz(3)
transpose(3->2)
ffty(2)
transpose(2->1)
fftx(1)
compute residual(1)

for the 0D, 1D, 2D strategies, the layouts look like xxx

0D        1D        2D
1:        xyz       xyz       xyz
2:        xyz       xyz       yxz
3:        xyz       zyx       zxy

the array dimensions are stored in dims(coord, phase) */

/* COMMON block: layout */
int dims[3][3];
int xstart[3];
int ystart[3];
int zstart[3];
int xend[3];
int yend[3];
int zend[3];

#define T_TOTAL     0
#define T_SETUP     1
#define T_FFT       2
#define T_EVOLVE    3
#define T_CHECKSUM  4
#define T_FFTLOW    5
#define T_FFTCOPY   6
#define T_TRANSPOSE 7
#define T_ALLTOALL  8
#define T_MAX       9

/* other stuff */
#define SEED 314159265.0
#define A 1220703125.0
#define PI 3.141592653589793238
#define ALPHA 1.0e-6

/* COMMON block: ucomm */
/* used in fft_init(), cfftz(), fftz2() */
dcomplex u[NX];

/* for checksum data */
/* COMMON block: sumcomm */
shared dcomplex sums[NITER_DEFAULT + 1];    /* sums(0:niter_default) */
upc_lock_t *sum_write;

#ifndef BUPC_TEST_HARNESS // conflicts with defn in upc_timers.h
shared double timer[THREADS*T_MAX];
#endif

/* shared problem variables */
typedef struct d_cell_s d_cell_t;
struct d_cell_s {
    double cell[NTDIVNP];
};

typedef struct dcomplex_cell_s dcomplex_cell_t;
struct dcomplex_cell_s {
    dcomplex cell[NTDIVNP];
};

/* function declarations */
void allocate_memory();
void set_x_ptr_xout_ptr(shared dcomplex_cell_t *x_arr,
        shared dcomplex_cell_t *xout_arr);
void setup();
void compute_indexmap(int d[3]);
void compute_initial_conditions(shared dcomplex_cell_t *u0_arr, int d[3]);
void fft_init(int n);
void ipow46(double a, int exp_1, int exp_2, double *result);
int ilog2(int n);
void evolve(shared dcomplex_cell_t *u0_arr,
        shared dcomplex_cell_t *u1_arr, int d[3]);
void checksum(int i, shared dcomplex_cell_t *u1_arr, int d[3]);
void verify(int d1, int d2, int d3, int nt, boolean * verified, char *class);
void print_timers(void);
void fft(int dir, shared dcomplex_cell_t *x1_arr,
        shared dcomplex_cell_t *x2_arr);
void cffts1(int is, int d[3], shared dcomplex_cell_t *x_arr,
        shared dcomplex_cell_t *xout_arr, dcomplex y0[NX][FFTBLOCKPAD],
        dcomplex y1[NX][FFTBLOCKPAD]);
void cffts2(int is, int d[3], shared dcomplex_cell_t *x_arr,
        shared dcomplex_cell_t *xout_arr, dcomplex y0[NX][FFTBLOCKPAD],
        dcomplex y1[NX][FFTBLOCKPAD]);
void cffts3(int is, int d[3], shared dcomplex_cell_t *x_arr,
        shared dcomplex_cell_t *xout_arr, dcomplex y0[NX][FFTBLOCKPAD],
        dcomplex y1[NX][FFTBLOCKPAD]);
void cfftz(int is, int m, int n, dcomplex x_arr[NX][FFTBLOCKPAD],
        dcomplex y_arr[NX][FFTBLOCKPAD]);
void fftz2(int is, int l, int m, int n, int ny, int ny1, dcomplex u_arr[NX],
        dcomplex x_arr[NX][FFTBLOCKPAD], dcomplex y_arr[NX][FFTBLOCKPAD]);
void transpose_x_yz(int l1, int l2, shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst);
void transpose_xy_z(int l1, int l2, shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst);
void transpose2_local(int n1, int n2, shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst);
void transpose2_global(shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst);
void transpose2_finish(int n1, int n2, shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst);


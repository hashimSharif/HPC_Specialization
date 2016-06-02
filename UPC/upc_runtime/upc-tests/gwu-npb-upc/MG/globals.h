#ifndef __H_GLOBALS_
#define __H_GLOBALS_
/* Parameter lm (declared and set in "npbparams.h") is the log-base2 of 
  the edge size max for the partition on a given node, so must be changed 
  either to save space (if running a small case) or made bigger for larger 
  cases, for example, 512^3. Thus lm=7 means that the largest dimension 
  of a partition that can be solved on a node is 2^7 = 128. lm is set 
  automatically in npbparams.h
  Parameters ndim1, ndim2, ndim3 are the local problem dimensions.  */

#include "npbparams.h"

/* actual dimension including ghost cells for communications */
#define	NM	(2+(2<<(LM-1)))
/* size of rhs array */
#define	NV	(2+(2<<(NDIM1-1))*(2+(2<<(NDIM2-1)))*(2+(2<<(NDIM3-1))))
/* size of residual array */
#define	NR	((8*(NV+(NM*NM)+5*NM+7*LM))/7)
/* size of communication buffer */
#define	NM2	(2*NM*NM)
/* maximum number of levels */
#define	MAXLEVEL	11

#define DIRm1   0
#define DIRp1   1
#define MM	10

#define LT_DEFAULT_I LT_DEFAULT+1

struct sh_arr_s {
  shared [] double *arr;
};

typedef struct sh_arr_s sh_arr_t;

extern int nx[MAXLEVEL+1], ny[MAXLEVEL+1], nz[MAXLEVEL+1];

extern char Class;

extern int debug_vec[8];

extern int lt, lb;

extern int ir[MAXLEVEL];

extern int m1[MAXLEVEL+1], m2[MAXLEVEL+1], m3[MAXLEVEL+1];
extern int nbr[4][2][MAXLEVEL+1];
extern int dead[MAXLEVEL+1], give_ex[4][MAXLEVEL+1], take_ex[4][MAXLEVEL+1];

extern shared double sh_a[4], sh_c[4];
extern shared int sh_nit, sh_nx, sh_ny, sh_nz, sh_debug_vec[8], sh_lt, sh_lb;
extern shared double s, max;

extern shared sh_arr_t sh_u[THREADS*(LT_DEFAULT_I)], sh_r[THREADS*(LT_DEFAULT_I)];
extern shared sh_arr_t sh_v[THREADS];

extern shared int jg[4][MM][2];
extern shared double red_best, red_winner;

/* allocate a prefetch buffer for left-right transfers in comm3
   is valid for (in this order): send_left, send_right, 
                                 recv_left, recv_right */
extern shared sh_arr_t prefetch_buffer[THREADS];
extern double         *prefetch_buffer_ptr;

/* Set at m=1024, can handle cases up to 1024^3 case */
#define	M	1037

#endif

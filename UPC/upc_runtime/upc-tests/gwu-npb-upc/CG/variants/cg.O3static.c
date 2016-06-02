/*NAS Parallel Benchmarks 2.4 UPC versions - CG

  This benchmark is an UPC version of the NPB CG code.

  The UPC versions are developed by HPCL-GWU and are derived from
  the OpenMP version (developed by RWCP) and from the MPI version
  (developed by NAS).

  Permission to use, copy, distribute and modify this software for any
  purpose with or without fee is hereby granted.
  This software is provided "as is" without express or implied warranty.

  Information on the UPC project at GWU is available at:
           http://upc.gwu.edu

  Information on NAS Parallel Benchmarks is available at:
           http://www.nas.nasa.gov/Software/NPB/

--------------------------------------------------------------------*/
/* FULLY OPTIMIZED VERSION (privatized&prefetching) */
/*--------------------------------------------------------------------
  UPC version:  F. Cantonnet  - GWU - HPCL (fcantonn@gwu.edu)
                Y. Yao        - GWU - HPCL (yyy@gwu.edu)
                T. El-Ghazawi - GWU - HPCL (tarek@gwu.edu)

  Authors(NAS): R. F. Van der Wijngaart
                M. Yarrow
                C. Kuszmaul
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

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <upc.h>
#include <upc_relaxed.h>

#include "npb-C.h"
#include "npbparams.h"

#define MAX_TIMERS 4
#include "upc_timers.h"

#define TIMER_TOTALTIME  0
#define TIMER_ALLREDUCE  1
#define TIMER_ALLREDUCE2 2
#define TIMER_ALLREDUCEB 3

#define NZ      (NA*(NONZER+1)*(NONZER+1)/THREADS)+(NA*(NONZER+2+(THREADS/256))\
        /NUM_PROC_COLS)

/* global variables */

/* common /partit_size/ */
int naa;
int nzz;
int nr_row;
int npcols, nprows;

/* thread relative */
int firstrow, lastrow;
int firstcol, lastcol;
int l2npcols;
int exchange_thread;
/* global view  */
int firstrow_g[THREADS], lastrow_g[THREADS];
int firstcol_g[THREADS], lastcol_g[THREADS];
int proc_col_g[THREADS], proc_row_g[THREADS];
int l2npcols_g[THREADS];
int send_start_g[THREADS], send_len_g[THREADS];
int exchange_thread_g[THREADS], exchange_len_g[THREADS];
int reduce_threads_g[THREADS][NUM_PROC_COLS];
int reduce_send_start_g[THREADS][NUM_PROC_COLS];
int reduce_send_len_g[THREADS][NUM_PROC_COLS];
int reduce_recv_start_g[THREADS][NUM_PROC_COLS];

/* common /main_int_mem/ */
int colidx[NZ];         /* colidx[0:NZ-1] */
int rowstr[NA+1];       /* rowstr[0:NA] */
int iv[2*NA+1];         /* iv[0:2*NA] */
int arow[NZ];           /* arow[0:NZ-1] */
int acol[NZ];           /* acol[0:NZ-1] */

/* common /main_flt_mem/ */
double v[NA+1];                         /* v[0:NA] */
double aelt[NZ];                        /* aelt[0:NZ-1] */
double a[NZ];                           /* a[0:NZ-1] */
double x[NA/NUM_PROC_ROWS+2];           /* x[0:NA+1] */
double z[NA/NUM_PROC_ROWS+2];           /* z[0:NA+1] */
double p[NA/NUM_PROC_ROWS+2];           /* p[0:NA+1] */
double q[NA/NUM_PROC_ROWS+2];           /* q[0:NA+1] */
double r[NA/NUM_PROC_ROWS+2];           /* r[0:NA+1] */

/* common /urando/ */
double amult;
double tran;

/* shared structures */
struct w_s {
    double arr[NA/NUM_PROC_ROWS+2];
};

typedef struct w_s w_t;
shared w_t w[THREADS];
shared w_t w_tmp[THREADS];

/* reduce stuff */
typedef struct cg_reduce_s cg_reduce_t;

struct cg_reduce_s {
    double v[2][NUM_PROC_COLS];
};

shared cg_reduce_t sh_reduce[THREADS];

/* Private pointers to local shared areas */
double *sh_reduce_ptr[2];

/* function declarations */
double *init_prefetch( void );
void setup_submatrix_info( void );
void makea(int n, int nz, double a[], int colidx[], int rowstr[],
        int nonzer, int firstrow, int lastrow, int firstcol,
        int lastcol, double rcond, int arow[], int acol[],
        double aelt[], double v[], int iv[], double shift );
void sprnvc(int n, int nz, double v[], int iv[], int nzloc[],
        int mark[]);
int icnvrt(double x, int ipwr2);
void vecset(int n, double v[], int iv[], int *nzv, int i, double val);
void sparse(double a[], int colidx[], int rowstr[], int n,
        int arow[], int acol[], double aelt[],
        int firstrow, int lastrow,
        double x[], boolean mark[], int nzloc[], int nnza);
void conj_grad(int colidx[], int rowstr[], double x[], double z[],
        double a[], double p[], double q[], double r[],
        shared w_t *w, shared w_t *w1, double *rnorm,
        double *prefetch_buffer);
double reduce_sum( double rs_a );
void reduce_sum_2( double rs_a, double rs_b );

int main(int argc, char **argv)
{
    int     i, j, k, it;
    double  zeta;
    double  rnorm;
    double  norm_temp11;
    double  norm_temp12;
    double  t, mflops;
    char    class;
    boolean verified;
    double  zeta_verify_value, epsilon;
    double  max_timer[MAX_TIMERS];
    double  *pref_buffer;

    /* initialize the timers */
    timer_clear(TIMER_TOTALTIME);
    timer_clear(TIMER_ALLREDUCE);
    timer_clear(TIMER_ALLREDUCE2);
    timer_clear(TIMER_ALLREDUCEB);

    /* initialize the verification constants */
    if (NA == 1400 && NONZER == 7 && NITER == 15 && SHIFT == 10.0)
    {
        class = 'S';
        zeta_verify_value = 8.5971775078648;
    }
    else if (NA == 7000 && NONZER == 8 && NITER == 15 && SHIFT == 12.0)
    {
        class = 'W';
        zeta_verify_value = 10.362595087124;
    }
    else if (NA == 14000 && NONZER == 11 && NITER == 15 && SHIFT == 20.0)
    {
        class = 'A';
        zeta_verify_value = 17.130235054029;
    }
    else if (NA == 75000 && NONZER == 13 && NITER == 75 && SHIFT == 60.0)
    {
        class = 'B';
        zeta_verify_value = 22.712745482631;
    }
    else if (NA == 150000 && NONZER == 15 && NITER == 75 && SHIFT == 110.0)
    {
        class = 'C';
        zeta_verify_value = 28.973605592845;
    }
    else if (NA == 1500000 && NONZER == 21 && NITER == 100 && SHIFT == 500.0)
    {
        class = 'D';
        zeta_verify_value = 52.5145321058;
    }
    else
    {
        class = 'U';
    }

    if( MYTHREAD == 0 )
    {
        printf("\n\n NAS Parallel Benchmarks 2.4 UPC version"
                " - CG Benchmark - GWU/HPCL\n");
        printf(" Size: %10d\n", NA);
        printf(" Iterations: %5d\n", NITER);
        printf(" Number of processors involved: %2d\n", THREADS);
        printf(" Number of nonzeroes per row: %8d\n", NONZER );
        printf(" Eigenvalue shift: %8.3f\n", SHIFT );
    }

    naa = NA;
    nzz = NZ;

    /* Initialize random number generator */
    tran    = 314159265.0;
    amult   = 1220703125.0;
    zeta    = randlc( &tran, amult );

    /* Split the matrix into something smaller */
    setup_submatrix_info();

    /* Allocate the memory for the prefetching buffer */
    if( l2npcols != 0 )
    { /* BUG fix -- 04/16/04 -- against calloc(0) buggy implementations */
        pref_buffer = init_prefetch();
        MEM_OK( pref_buffer );
    }
    else
        pref_buffer = NULL;

    upc_barrier;

    /* Initialize the private pointers to local shared data */
    sh_reduce_ptr[0] = ((double *) &sh_reduce[MYTHREAD].v[0][0]);
    sh_reduce_ptr[1] = ((double *) &sh_reduce[MYTHREAD].v[1][0]);
    nr_row = MYTHREAD / NUM_PROC_COLS;

    upc_barrier;

    makea(naa, nzz, a, colidx, rowstr, NONZER,
            firstrow, lastrow, firstcol, lastcol,
            RCOND, arow, acol, aelt, v, iv, SHIFT);

    /*Note: as a result of the above call to makea:
      values of j used in indexing rowstr go from 1 --> lastrow-firstrow+1
      values of colidx which are col indexes go from firstcol --> lastcol
So:
Shift the col index vals from actual (firstcol --> lastcol )
to local, i.e., (1 --> lastcol-firstcol+1) */
    for (j = 0; j <= lastrow - firstrow; j++)
    {
        for (k = rowstr[j]; k < rowstr[j+1]; k++)
        {
            colidx[k-1] = colidx[k-1] - firstcol + 1;
        }
    }

    /* set starting vector to (1, 1, .... 1) */
    memset( x, 0, sizeof( x ));
    for (i = 0; i <= NA/NUM_PROC_ROWS; i++)
    {
        x[i] = 1.0;
    }
    zeta  = 0.0;

    /* Do one iteration untimed to init all code and data page tables (then reinit, start timing, to niter its) */

    /* The call to the conjugate gradient routine: */
    upc_barrier;

    conj_grad(colidx, rowstr, x, z, a, p, q, r, w, w_tmp, &rnorm, pref_buffer);

    /* zeta = shift + 1/(x.z)
       So, first: (x.z)
       Also, find norm of z
       So, first: (z.z) */

    upc_barrier;

    norm_temp11 = 0.0;
    norm_temp12 = 0.0;

    /*  - compute - */
    for (j = 0; j <= lastcol-firstcol; j++)
    {
        norm_temp11 = norm_temp11 + x[j]*z[j];
        norm_temp12 = norm_temp12 + z[j]*z[j];
    }

    reduce_sum_2( norm_temp11, norm_temp12 );

    /*  -  flush  - */
    norm_temp11 = 0.0;
    norm_temp12 = 0.0;
    for( i=0; i<NUM_PROC_COLS; i++ )
    {
        norm_temp11 += sh_reduce_ptr[0][i];
        norm_temp12 += sh_reduce_ptr[1][i];
    }

    norm_temp12 = 1.0 / sqrt( norm_temp12 );

    /* Normalize z to obtain x */
    for (j = 0; j <= lastcol-firstcol; j++)
    {
        x[j] = norm_temp12*z[j];
    }

    /* set starting vector to (1, 1, .... 1) */
    for (i = 0; i <= NA/NUM_PROC_ROWS+1; i++)
    {
        x[i] = 1.0;
    }
    zeta  = 0.0;

    timer_clear(TIMER_TOTALTIME);
    timer_clear(TIMER_ALLREDUCE);
    timer_clear(TIMER_ALLREDUCE2);
    timer_clear(TIMER_ALLREDUCEB);

    upc_barrier;

    timer_start(TIMER_TOTALTIME);

    /* Main Iteration for inverse power method */
    for (it = 1; it <= NITER; it++)
    {
        /* The call to the conjugate gradient routine: */
        conj_grad(colidx, rowstr, x, z, a, p, q, r, w, w_tmp, &rnorm, pref_buffer);

        /* zeta = shift + 1/(x.z)
           So, first: (x.z)
           Also, find norm of z
           So, first: (z.z) */

        norm_temp11 = 0.0;
        norm_temp12 = 0.0;

        /*  - compute - */
        for (j = 0; j <= lastcol-firstcol; j++)
        {
            norm_temp11 = norm_temp11 + x[j]*z[j];
            norm_temp12 = norm_temp12 + z[j]*z[j];
        }

        reduce_sum_2( norm_temp11, norm_temp12 );

        /*  -  flush  - */
        norm_temp11 = 0.0;
        norm_temp12 = 0.0;

        for( i=0; i<NUM_PROC_COLS; i++ )
        {
            norm_temp11 += sh_reduce_ptr[0][i];
            norm_temp12 += sh_reduce_ptr[1][i];
        }

        norm_temp12 = 1.0 / sqrt( norm_temp12 );

        if( MYTHREAD == 0 )
        {
            zeta = SHIFT + 1.0 / norm_temp11;

            if( it == 1 )
            {
                printf("   iteration           ||r||                 zeta\n");
            }
            printf("    %5d       %20.14e%20.13e\n", it, rnorm, zeta);
        }

        /* Normalize z to obtain x */
        for (j = 0; j <= lastcol-firstcol; j++)
        {
            x[j] = norm_temp12*z[j];
        }
    }

    timer_stop( TIMER_TOTALTIME );

    /* prepare for timers_reduce() */
    for( i=0; i<MAX_TIMERS; i++ )
        timer[i][MYTHREAD] = timer_read(i);

    upc_barrier;

    if( MYTHREAD == 0 )
    {
        /* End of timed section */
        timers_reduce( max_timer );

        t = max_timer[TIMER_TOTALTIME];

        printf(" Benchmark completed\n");

        epsilon = 1.0e-10;
        if (class != 'U')
        {
            if (fabs(zeta - zeta_verify_value) <= epsilon)
            {
                verified = TRUE;
                printf(" VERIFICATION SUCCESSFUL\n");
                printf(" Zeta is    %20.12e\n", zeta);
                printf(" Error is   %20.12e\n", zeta - zeta_verify_value);
            }
            else
            {
                verified = FALSE;
                printf(" VERIFICATION FAILED\n");
                printf(" Zeta                %20.12e\n", zeta);
                printf(" The correct zeta is %20.12e\n", zeta_verify_value);
            }
        }
        else
        {
            verified = FALSE;
            printf(" Problem size unknown\n");
            printf(" NO VERIFICATION PERFORMED\n");
        }

        if ( t != 0.0 )
        {
            mflops = (2.0*NITER*NA)
                * (3.0+(NONZER*(NONZER+1)) + 25.0*(5.0+(NONZER*(NONZER+1))) + 3.0 )
                / t / 1000000.0;
        }
        else
        {
            mflops = 0.0;
        }

        c_print_results("CG", class, NA, 0, 0, NITER, THREADS, t,
                mflops, "          floating point",
                verified, NPBVERSION, COMPILETIME,
                NPB_CS1, NPB_CS2, NPB_CS3, NPB_CS4, NPB_CS5, NPB_CS6, NPB_CS7);

        printf("\n");
        printf("      total time: %.6f\n", max_timer[TIMER_TOTALTIME]);
        printf("      reduce_all: %.6f\n", max_timer[TIMER_ALLREDUCE]);
        printf("     reduce_all2: %.6f\n", max_timer[TIMER_ALLREDUCE2]);
        printf("  reduce_all_big: %.6f\n", max_timer[TIMER_ALLREDUCEB]);
        printf("-----------------\n");
        printf("TOTAL collective: %.6f\n", max_timer[TIMER_ALLREDUCE] +
                max_timer[TIMER_ALLREDUCE2] + max_timer[TIMER_ALLREDUCEB]);
    }

    return 0;
}

double *init_prefetch( void )
{
    double *buf;
    long int memsize;
    int i;

    /* find the maximum memory size required */
    memsize = reduce_send_len_g[reduce_threads_g[MYTHREAD][0]][0];
    for( i=1; i<l2npcols; i++ )
    {
        if( reduce_send_len_g[reduce_threads_g[MYTHREAD][i]][i] > memsize )
            memsize = reduce_send_len_g[reduce_threads_g[MYTHREAD][i]][i];
    }

    /* and malloc it */
    buf = calloc( memsize, sizeof( double ));

    return buf;
}

void setup_submatrix_info( void )
{
    int col_size, row_size;
    int t, i, j;
    int div_factor;

    npcols = NUM_PROC_COLS;
    nprows = NUM_PROC_ROWS;

    for( t=0; t<THREADS; t++ )
    {
        proc_row_g[t] = t / npcols;
        proc_col_g[t] = t - (proc_row_g[t]*npcols);

        if( (naa/(npcols*npcols)) == naa )
        {
            col_size = naa/npcols;
            firstcol_g[t] = proc_col_g[t]*col_size + 1;
            lastcol_g[t] = firstcol_g[t] - 1 + col_size;
            row_size = naa / nprows;
            firstrow_g[t] = proc_row_g[t]*row_size + 1;
            lastrow_g[t] = firstrow_g[t] - 1 + row_size;
        }
        else
        {
            if( proc_row_g[t] < (naa - (naa / (nprows*nprows))) )
            {
                row_size = (naa / nprows); // + 1;
                firstrow_g[t] = (proc_row_g[t] * row_size) + 1;
                lastrow_g[t] = firstrow_g[t] - 1 + row_size;
            }
            else
            {
                row_size = naa / nprows;
                firstrow_g[t] = (naa - (naa/(nprows*nprows))) * (row_size + 1)
                    + (proc_row_g[t] - (naa - (naa/(nprows * nprows)))
                            * row_size) + 1;
                lastrow_g[t] = firstrow_g[t] - 1 + row_size;
            }

            if( npcols == nprows )
            {
                if( proc_col_g[t] < (naa - (naa / (npcols*npcols))) )
                {
                    col_size = (naa / npcols); // + 1;
                    firstcol_g[t] = (proc_col_g[t] * col_size) + 1;
                    lastcol_g[t] = firstcol_g[t] - 1 + col_size;
                }
                else
                {
                    col_size = naa / npcols;
                    firstcol_g[t] = (naa - (naa/(npcols*npcols))) * (col_size + 1)
                        + (proc_col_g[t] - (naa - (naa/(npcols * npcols)))
                                * col_size) + 1;
                    lastcol_g[t] = firstcol_g[t] - 1 + col_size;
                }
            }
            else
            {
                if( (proc_col_g[t]/2) < (naa - (naa / ((npcols/2)*(npcols/2)))) )
                {
                    col_size = naa / (npcols/2); // + 1;
                    firstcol_g[t] = (proc_col_g[t]/2) * col_size + 1;
                    lastcol_g[t] = firstcol_g[t] - 1 + col_size;
                }
                else
                {
                    col_size = naa / (npcols/2);
                    firstcol_g[t] = (naa - (naa/((npcols/2)*(npcols/2)))) * (col_size + 1)
                        + ((proc_col_g[t]/2) - (naa - (naa/((npcols/2) * (npcols/2))))
                                * col_size) + 1;
                    lastcol_g[t] = firstcol_g[t] - 1 + col_size;
                }

                if( (t%2) == 0 )
                    lastcol_g[t] = firstcol_g[t] - 1 + (col_size-1)/2 + 1;
                else
                {
                    {
                        firstcol_g[t] = firstcol_g[t] + (col_size-1)/2 + 1;
                        lastcol_g[t] = firstcol_g[t] - 1 + col_size/2;
                    }
                }
            }
        }
        if( npcols == nprows )
        {
            send_start_g[t] = 1;
            send_len_g[t] = lastrow_g[t] - firstrow_g[t] + 1;
        }
        else
        {
            if( (t%2) == 0 )
            {
                send_start_g[t] = 1;
                send_len_g[t] = (1 + lastrow_g[t]-firstrow_g[t]+1)/2;
            }
            else
            {
                send_start_g[t] = (1 + lastrow_g[t]-firstrow_g[t]+1)/2 + 1;
                send_len_g[t] = (lastrow_g[t]-firstrow_g[t]+1)/2;
            }
        }

        if( npcols == nprows )
        {
            exchange_thread_g[t] = ((t%nprows) * nprows) + (t / nprows);
        }
        else
        {
            exchange_thread_g[t] = (2 * ((((t/2)%nprows) * nprows) + (t/2/nprows))) + (t%2);
        }

        i = npcols / 2;
        l2npcols_g[t] = 0;
        while( i > 0 )
        {
            l2npcols_g[t] ++;
            i /= 2;
        }

        div_factor = npcols;
        for( i=0; i<l2npcols_g[t]; i++ )
        {
            j = (proc_col_g[t] + (div_factor/2))%div_factor;
            j += (proc_col_g[t] / div_factor)*div_factor;
            reduce_threads_g[t][i] = (proc_row_g[t]*npcols) + j;

            div_factor = div_factor/2;
        }

        for( i=(l2npcols_g[t]-1); i>=0; i-- )
        {
            if( nprows == npcols )
            {
                reduce_send_start_g[t][i] = send_start_g[t];
                reduce_send_len_g[t][i] = send_len_g[t];
            }
            else
            {
                if( i == (l2npcols_g[t]-1) )
                {
                    reduce_send_len_g[t][i] = lastrow_g[t]-firstrow_g[t]+1 - send_len_g[t];
                    if( (t/2*2) == t )
                    {
                        reduce_send_start_g[t][i] = send_start_g[t] + send_len_g[t];
                    }
                    else
                    {
                        reduce_send_start_g[t][i] = 1;
                    }
                }
                else
                {
                    reduce_send_len_g[t][i] = send_len_g[t];
                    reduce_send_start_g[t][i] = send_start_g[t];
                }
            }

            reduce_recv_start_g[t][i] = send_start_g[t];
        }

        exchange_len_g[t] = lastcol_g[t] - firstcol_g[t] + 1;
    }

    /* make local copy */
    firstcol = firstcol_g[MYTHREAD];
    firstrow = firstrow_g[MYTHREAD];
    lastcol = lastcol_g[MYTHREAD];
    lastrow = lastrow_g[MYTHREAD];
    exchange_thread = exchange_thread_g[MYTHREAD];
    l2npcols = l2npcols_g[MYTHREAD];
}

/* generate the test problem for benchmark 6
   makea generates a sparse matrix with a
   prescribed sparsity distribution

   parameter    type        usage

   input

   n            i           number of cols/rows of matrix
   nz           i           nonzeros as declared array size
   rcond        r*8         condition number
   shift        r*8         main diagonal shift

   output

   a            r*8         array for nonzeros
   colidx       i           col indices
   rowstr       i           row pointers

   workspace

   iv, arow, acol i
   v, aelt        r*8 */
void makea(
        int n,
        int nz,
        double a[],          /* a[0:nz-1] */
        int colidx[],        /* colidx[0:nz-1] */
        int rowstr[],        /* rowstr[0:n] */
        int nonzer,
        int firstrow,
        int lastrow,
        int firstcol,
        int lastcol,
        double rcond,
        int arow[],          /* arow[0:nz-1] */
        int acol[],          /* acol[0:nz-1] */
        double aelt[],       /* aelt[0:nz-1] */
        double v[],          /* v[0:n] */
        int iv[],            /* iv[0:2*n] */
        double shift )
{
    int i, nnza, iouter, ivelt, ivelt1, irow, nzv;

    /* nonzer is approximately  (int(sqrt(nnza /n))); */
    double size, ratio, scale;
    int jcol;

    size = 1.0;
    ratio = pow(rcond, (1.0 / (double)n));
    nnza = 0;

    /* Initialize colidx(n .. 2n-1) to zero.  Used by sprnvc to mark nonzero positions */
    for (i = 1; i <= n; i++)
    {
        colidx[n+i-1] = 0;
    }
    for (iouter = 1; iouter <= n; iouter++)
    {
        nzv = nonzer;
        sprnvc(n, nzv, v, iv, &(colidx[0]), &(colidx[n]));
        vecset(n, v, iv, &nzv, iouter, 0.5);
        for (ivelt = 1; ivelt <= nzv; ivelt++)
        {
            jcol = iv[ivelt-1];
            if (jcol >= firstcol && jcol <= lastcol)
            {
                scale = size * v[ivelt-1];
                for (ivelt1 = 1; ivelt1 <= nzv; ivelt1++)
                {
                    irow = iv[ivelt1-1];
                    if (irow >= firstrow && irow <= lastrow)
                    {
                        nnza = nnza + 1;
                        if (nnza > nz)
                        {
                            printf("Space for matrix elements exceeded in"
                                    " makea\n");
                            printf("nnza, nzmax = %d, %d\n", nnza, nz);
                            printf("iouter = %d\n", iouter);
                            exit(1);
                        }
                        acol[nnza-1] = jcol;
                        arow[nnza-1] = irow;
                        aelt[nnza-1] = v[ivelt1-1] * scale;
                    }
                }
            }
        }
        size = size * ratio;
    }

    /* ... add the identity * rcond to the generated matrix to bound
       the smallest eigenvalue from below by rcond */
    for (i = firstrow; i <= lastrow; i++)
    {
        if (i >= firstcol && i <= lastcol)
        {
            iouter = n + i;
            nnza = nnza + 1;
            if (nnza > nz)
            {
                printf("Space for matrix elements exceeded in makea\n");
                printf("nnza, nzmax = %d, %d\n", nnza, nz);
                printf("iouter = %d\n", iouter);
                exit(1);
            }
            acol[nnza-1] = i;
            arow[nnza-1] = i;
            aelt[nnza-1] = rcond - shift;
        }
    }

    /* ... make the sparse matrix from list of elements with duplicates
       (v and iv are used as  workspace) */
    sparse(a, colidx, rowstr, n, arow, acol, aelt,
            firstrow, lastrow, v, &(iv[0]), &(iv[n]), nnza);
}

/* generate a sparse n-vector (v, iv)
   having nzv nonzeros

   mark(i) is set to 1 if position i is nonzero.
   mark is all zero on entry and is reset to all zero before exit
   this corrects a performance bug found by John G. Lewis, caused by
   reinitialization of mark on every one of the n calls to sprnvc */
void sprnvc(
        int n,
        int nz,
        double v[],         /* v[0:*] */
        int iv[],           /* iv[0:*] */
        int nzloc[],        /* nzloc[0:n-1] */
        int mark[] )        /* mark[0:n-1] */
{
    int nn1;
    int nzrow, nzv, ii, i;
    double vecelt, vecloc;

    nzv = 0;
    nzrow = 0;
    nn1 = 1;
    do {
        nn1 = 2 * nn1;
    } while (nn1 < n);

    /* nn1 is the smallest power of two not less than n */
    while (nzv < nz)
    {
        vecelt = randlc(&tran, amult);
        /* generate an integer between 1 and n in a portable manner */
        vecloc = randlc(&tran, amult);
        i = icnvrt(vecloc, nn1) + 1;
        if (i > n)
            continue;

        /* was this integer generated already? */
        if (mark[i-1] == 0)
        {
            mark[i-1] = 1;
            nzrow = nzrow + 1;
            nzloc[nzrow-1] = i;
            nzv = nzv + 1;
            v[nzv-1] = vecelt;
            iv[nzv-1] = i;
        }
    }

    for (ii = 1; ii <= nzrow; ii++)
    {
        i = nzloc[ii-1];
        mark[i-1] = 0;
    }
}

/* scale a double precision number x in (0,1) by a power of 2 and chop it */
int icnvrt(double x, int ipwr2)
{
    return ((int)(ipwr2 * x));
}

/* set ith element of sparse vector (v, iv) with
   nzv nonzeros to val */
void vecset(
        int n,
        double v[], /* v[0:*] */
        int iv[],   /* iv[0:*] */
        int *nzv,
        int i,
        double val)
{
    int k;
    boolean set;

    set = FALSE;
    for (k = 1; k <= *nzv; k++)
    {
        if (iv[k-1] == i)
        {
            v[k-1] = val;
            set  = TRUE;
        }
    }
    if (set == FALSE)
    {
        *nzv = *nzv + 1;
        v[*nzv-1] = val;
        iv[*nzv-1] = i;
    }
}

/* generate a sparse matrix from a list of
   [col, row, element] tri */
void sparse(
        double a[],         /* a[0:*] */
        int colidx[],       /* colidx[0:*] */
        int rowstr[],       /* rowstr[0:*] */
        int n,
        int arow[],         /* arow[0:*] */
        int acol[],         /* acol[0:*] */
        double aelt[],      /* aelt[0:*] */
        int firstrow,
        int lastrow,
        double x[],         /* x[0:n-1] */
        boolean mark[],     /* mark[0:n-1] */
        int nzloc[],        /* nzloc[0:n-1] */
        int nnza)
{
    /* rows range from firstrow to lastrow
       the rowstr pointers are defined for nrows = lastrow-firstrow+1 values */
    int nrows;
    int i, j, jajp1, nza, k, nzrow;
    double xi;

    /* how many rows of result ? */
    nrows = lastrow - firstrow + 1;

    /* ...count the number of triples in each row */
    for (j = 1; j <= n; j++)
    {
        rowstr[j-1] = 0;
        mark[j-1] = FALSE;
    }
    rowstr[n] = 0;

    for (nza = 1; nza <= nnza; nza++)
    {
        j = (arow[nza-1] - firstrow + 1) + 1;
        rowstr[j-1] = rowstr[j-1] + 1;
    }

    rowstr[0] = 1;
    for (j = 2; j <= nrows+1; j++)
    {
        rowstr[j-1] = rowstr[j-1] + rowstr[j-2];
    }

    /* ... rowstr(j) now is the location of the first nonzero of row j of a */
    /* ... do a bucket sort of the triples on the row index */
    for (nza = 1; nza <= nnza; nza++)
    {
        j = arow[nza-1] - firstrow + 1;
        k = rowstr[j-1];
        a[k-1] = aelt[nza-1];
        colidx[k-1] = acol[nza-1];
        rowstr[j-1] = rowstr[j-1] + 1;
    }

    /* ... rowstr(j) now points to the first element of row j+1 */
    for (j = nrows; j >= 1; j--)
    {
        rowstr[j] = rowstr[j-1];
    }
    rowstr[0] = 1;

    /* ... generate the actual output rows by adding elements */
    nza = 0;
    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
        mark[i] = FALSE;
    }

    jajp1 = rowstr[0];
    for (j = 1; j <= nrows; j++)
    {
        nzrow = 0;

        /* ...loop over the jth row of a */
        for (k = jajp1; k < rowstr[j]; k++)
        {
            i = colidx[k-1];
            x[i-1] = x[i-1] + a[k-1];
            if ( mark[i-1] == FALSE && x[i-1] != 0.0)
            {
                mark[i-1] = TRUE;
                nzrow = nzrow + 1;
                nzloc[nzrow-1] = i;
            }
        }

        /* ... extract the nonzeros of this row */
        for (k = 1; k <= nzrow; k++)
        {
            i = nzloc[k-1];
            mark[i-1] = FALSE;
            xi = x[i-1];
            x[i-1] = 0.0;
            if (xi != 0.0)
            {
                nza = nza + 1;
                a[nza-1] = xi;
                colidx[nza-1] = i;
            }
        }
        jajp1 = rowstr[j];
        rowstr[j] = nza + rowstr[0];
    }
}

void conj_grad (
        int colidx[],           /* colidx[0:nzz-1] */
        int rowstr[],           /* rowstr[0:naa] */
        double x[],             /* x[*] */
        double z[],             /* z[*] */
        double a[],             /* a[0:nzz-1] */
        double p[],             /* p[*] */
        double q[],             /* q[*] */
        double r[],             /* r[*] */
        shared w_t *w,
        shared w_t *w1,
        double *rnorm,
        double *prefetch_buffer )
{
    /*Floating point arrays here are named as in NPB1 spec discussion of CG algorithm */
    double d, sum, rho, rho0, alpha, beta;
    int i, j, k, l, m;
    int cgit, cgitmax = 25;
    double *w_ptr, *w1_ptr;

    /* Initialize the private pointers to access local shared data */
    w_ptr = (double *) &w[MYTHREAD].arr[0];
    w1_ptr = (double *) &w1[MYTHREAD].arr[0];

    /* Initialize the CG algorithm */
    memset( q, 0, sizeof(double) * ((naa/nprows)+1));
    memset( z, 0, sizeof(double) * ((naa/nprows)+1));
    memcpy( r, x, sizeof(double) * ((naa/nprows)+1));
    memcpy( p, x, sizeof(double) * ((naa/nprows)+1));
    memset( w_ptr, 0, sizeof( double ) * ((naa/nprows)+1));
    memset( w1_ptr, 0, sizeof( double ) * ((naa/nprows)+1));

    /* rho = r.r
       Now, obtain the norm of r: First, sum squares of r elements locally...  */

    sum = 0.0;

    /*  - compute - */
    for (j = 0; j <= lastcol-firstcol; j++)
    {
        sum = sum + r[j]*r[j];
    }

    rho = reduce_sum( sum );

    /*  -  flush  - */
    rho = 0.0;
    for( i=0; i<NUM_PROC_COLS; i++ )
    {
        rho += sh_reduce_ptr[0][i];
    }

    /* The conj grad iteration loop */
    for (cgit = 1; cgit <= cgitmax; cgit++)
    {
        rho0 = rho;
        rho = 0.0;
        /* q = A.p
           The partition submatrix-vector multiply: use workspace w

NOTE: this version of the multiply is actually (slightly: maybe %5)
faster on the sp2 on 16 nodes than is the unrolled-by-2 version
below.   On the Cray t3d, the reverse is true, i.e., the
unrolled-by-two version is some 10% faster.
The unrolled-by-8 version below is significantly faster
on the Cray t3d - overall speed of code is 1.5 times faster.  */

        /* rolled version */
        for (j = 0; j <= lastrow-firstrow; j++)
        {
            sum = 0.0;
            for (k = rowstr[j]; k < rowstr[j+1]; k++)
            {
                sum = sum + a[k-1]*p[colidx[k-1]-1];
            }

            w1_ptr[j] = sum;
            w_ptr[j] = sum;
        }

        upc_barrier;
        TIMER_START(TIMER_ALLREDUCEB);

        for( i=(l2npcols-1); i>=0; i-- )
        {
            k = reduce_threads_g[MYTHREAD][i];
            l = reduce_recv_start_g[MYTHREAD][i]-1;
            m = reduce_send_start_g[k][i]-1;

            upc_memget( prefetch_buffer, &w1[k].arr[m],
                    sizeof( double ) * reduce_send_len_g[k][i] );

            upc_notify;

            for( j=0; j<reduce_send_len_g[k][i]; j++)
            {
                w_ptr[l+j] += prefetch_buffer[j];
            }

            upc_wait;

            if( i != 0 )
            {
                memcpy( &w1_ptr[l],
                        &w_ptr[l],
                        sizeof( double ) * (reduce_send_len_g[k][i]) );
            }
            upc_barrier;
        }

        if( l2npcols == 0 )
        {
            memcpy( &q[0], &w_ptr[0], sizeof( double ) *
                    exchange_len_g[MYTHREAD] );
        }
        else
        {
            upc_memget( &q[0],
                    &w[exchange_thread].arr[send_start_g[exchange_thread]-1],
                    sizeof( double ) * exchange_len_g[exchange_thread] );
        }

        TIMER_STOP(TIMER_ALLREDUCEB);

        /* Obtain p.q */
        d = 0.0;

        /*  - compute - */
        for (j = 0; j <= lastcol-firstcol; j++)
        {
            d = d + p[j]*q[j];
        }

        d = reduce_sum( d );

        /*  -  flush  - */
        d = 0.0;
        for( i=0; i<NUM_PROC_COLS; i++ )
        {
            d += sh_reduce_ptr[0][i];
        }

        /* Obtain alpha = rho / (p.q) */
        alpha = rho0 / d;

        /* Obtain z = z + alpha*p    and    r = r - alpha*q */
        for (j = 0; j <= lastcol-firstcol; j++)
        {
            z[j] = z[j] + alpha*p[j];
            r[j] = r[j] - alpha*q[j];
        }

        /* rho = r.r
           Now, obtain the norm of r: First, sum squares of r elements locally...  */

        /*  - compute - */
        for (j = 0; j <= lastcol-firstcol; j++)
        {
            rho = rho + r[j]*r[j];
        }

        rho = reduce_sum( rho );

        /*  -  flush  - */
        rho = 0.0;
        for( i=0; i<NUM_PROC_COLS; i++ )
        {
            rho += sh_reduce_ptr[0][i];
        }

        /* Obtain beta: */
        beta = rho / rho0;

        /* p = r + beta*p */
        for (j = 0; j <= lastcol-firstcol; j++)
        {
            p[j] = r[j] + beta*p[j];
        }
    }

    /* Compute residual norm explicitly:  ||r|| = ||x - A.z||
       First, form A.z
       The partition submatrix-vector multiply */
    for (j = 0; j <= lastrow-firstrow; j++)
    {
        d = 0.0;
        for (k = rowstr[j]-1; k < rowstr[j+1]-1; k++)
        {
            d = d + a[k]*z[colidx[k]-1];
        }

        w_ptr[j] = d;
        w1_ptr[j] = d;
    }

    TIMER_START(TIMER_ALLREDUCEB);

    for( i=(l2npcols-1); i>=0; i-- )
    {
        k = reduce_threads_g[MYTHREAD][i];
        l = reduce_recv_start_g[MYTHREAD][i]-1;
        m = reduce_send_start_g[k][i]-1;

        upc_memget( prefetch_buffer, &w1[k].arr[m],
                sizeof( double ) * reduce_send_len_g[k][i] );

        upc_notify;

        for( j=0; j<reduce_send_len_g[k][i]; j++)
        {
            w_ptr[l+j] += prefetch_buffer[j];
        }

        upc_wait;

        if( i != 0 )
        {
            memcpy( &w1_ptr[l],
                    &w_ptr[l],
                    sizeof( double ) * (reduce_send_len_g[k][i]) );
        }
        upc_barrier;
    }

    if( l2npcols == 0 )
    {
        memcpy( &r[0], &w_ptr[0], sizeof( double ) *
                exchange_len_g[MYTHREAD] );
    }
    else
    {
        upc_memget( &r[0],
                &w[exchange_thread].arr[send_start_g[exchange_thread]-1],
                sizeof( double ) * exchange_len_g[exchange_thread] );
    }

    TIMER_STOP(TIMER_ALLREDUCEB);

    /* At this point, r contains A.z */
    sum = 0.0;

    /*  - compute - */
    for (j = 0; j <= lastcol-firstcol; j++)
    {
        d = x[j] - r[j];
        sum = sum + d*d;
    }

    sum = reduce_sum( sum );

    /*  -  flush  - */
    sum = 0.0;
    for( i=0; i<NUM_PROC_COLS; i++ )
    {
        sum += sh_reduce_ptr[0][i];
    }

    (*rnorm) = sqrt(sum);
}

double reduce_sum( double rs_a )
{
    int rs_i;
    int rs_o;

    TIMER_START(TIMER_ALLREDUCE);

    upc_barrier;

    rs_o = (nr_row * NUM_PROC_COLS);
    for( rs_i=rs_o; rs_i<(rs_o+NUM_PROC_COLS); rs_i++ )
    {
        if( rs_i == MYTHREAD )
        {
            sh_reduce_ptr[0][MYTHREAD-rs_o] = rs_a;
        }
        else
        {
            sh_reduce[rs_i].v[0][MYTHREAD-rs_o] = rs_a;
        }
    }

    TIMER_STOP(TIMER_ALLREDUCE);

    upc_barrier;

    return rs_a;
}

void reduce_sum_2( double rs_a, double rs_b )
{
    int rs_i;
    int rs_o;

    TIMER_START(TIMER_ALLREDUCE2);

    upc_barrier;

    rs_o = (nr_row * NUM_PROC_COLS);
    for( rs_i=rs_o; rs_i<(rs_o+NUM_PROC_COLS); rs_i++ )
    {
        if( rs_i == MYTHREAD )
        {
            sh_reduce_ptr[0][MYTHREAD-rs_o] = rs_a;
            sh_reduce_ptr[1][MYTHREAD-rs_o] = rs_b;
        }
        else
        {
            sh_reduce[rs_i].v[0][MYTHREAD-rs_o] = rs_a;
            sh_reduce[rs_i].v[1][MYTHREAD-rs_o] = rs_b;
        }
    }

    TIMER_STOP(TIMER_ALLREDUCE2);

    upc_barrier;
}

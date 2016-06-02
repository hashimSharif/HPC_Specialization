/*NAS Parallel Benchmarks 2.4 UPC versions - FT

  This benchmark is an UPC version of the NPB FT code.

  The UPC versions are developed by HPCL-GWU and are derived from
  the OpenMP version (developed by RWCP).

  Permission to use, copy, distribute and modify this software for any
  purpose with or without fee is hereby granted.
  This software is provided "as is" without express or implied warranty.

  Information on the UPC project at GWU is available at:
           http://upc.gwu.edu

  Information on NAS Parallel Benchmarks is available at:
           http://www.nas.nasa.gov/Software/NPB/

--------------------------------------------------------------------*/
/* FULLY OPTIMIZED VERSION (privatized) - STATIC MEM */
/*--------------------------------------------------------------------
  UPC version:  F. Cantonnet  - GWU - HPCL (fcantonn@gwu.edu)
                T. El-Ghazawi - GWU - HPCL (tarek@gwu.edu)
                S. Chauvin

  Authors(NAS): D. Bailey
                W. Saphir
                R. F. Van der Wijngaart
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
--------------------------------------------------------------------*/

#include "ft-common-1.h"

#define twid(z,y,x) twiddle_ptr[z*d[1]*d[0] + y*d[0] + x]
#define u0(z,y,x)   u0_ptr[z*d[1]*d[0] + y*d[0] + x]
#define u1(z,y,x)   u1_ptr[z*d[1]*d[0] + y*d[0] + x]
#define x(z,y,x)    x_ptr[z*d[1]*d[0] + y*d[0] + x]
#define xout(z,y,x) xout_ptr[z*d[1]*d[0] + y*d[0] + x]

dcomplex *x_ptr = NULL;
dcomplex *xout_ptr = NULL;

shared dcomplex dbg_sum;
shared d_cell_t twiddle[THREADS];
shared dcomplex_cell_t sh_u0[THREADS];
shared dcomplex_cell_t sh_u1[THREADS];
shared dcomplex_cell_t sh_u2[THREADS];

double *twiddle_ptr = NULL;

#include "ft-common-2.h"

void allocate_memory(){
    int i;

    for( i=0; i<NITER_DEFAULT+1; i++ ){
        sums[i].real = 0;
        sums[i].imag = 0;
    }

    twiddle_ptr = (double *) &twiddle[MYTHREAD].cell[0];
}

void set_x_ptr_xout_ptr(shared dcomplex_cell_t *x_arr,
        shared dcomplex_cell_t *xout_arr){
    x_ptr = (dcomplex *)&x_arr[MYTHREAD].cell[0];
    xout_ptr = (dcomplex *)&xout_arr[MYTHREAD].cell[0];
}

void evolve(shared dcomplex_cell_t *u0_arr,
        shared dcomplex_cell_t *u1_arr, int d[3]){
    /* evolve u0 -> u1 (t time steps) in fourier space */
    int i, j, k;
    dcomplex *u0_ptr, *u1_ptr;

    u0_ptr = (dcomplex *) &u0_arr[MYTHREAD].cell[0];
    u1_ptr = (dcomplex *) &u1_arr[MYTHREAD].cell[0];

    for (k = 0; k < d[2]; k++){
        for (j = 0; j < d[1]; j++){
            for (i = 0; i < d[0]; i++){
                u0(k,j,i).real *= twid(k,j,i);
                u0(k,j,i).imag *= twid(k,j,i);
                u1(k,j,i) = u0(k,j,i);
            }
        }
    }
}

void checksum(int i, shared dcomplex_cell_t *u1_arr, int d[3]){
    int j, q, r, s;
    int ox, oy, oz;
    dcomplex chk;
    dcomplex *u1_ptr = (dcomplex *) &u1_arr[MYTHREAD].cell[0];

    chk.real = 0.0;
    chk.imag = 0.0;

    /* Work on the local data */
    for (j = 1; j <= 1024; j++){
        q = (j % NX) + 1;
        if (q >= xstart[0] && q <= xend[0]){
            r = ((3 * j) % NY) + 1;
            if (r >= ystart[0] && r <= yend[0]){
                s = ((5 * j) % NZ) + 1;
                if (s >= zstart[0] && s <= zend[0]){
                    oz = s-zstart[0];
                    oy = r-ystart[0];
                    ox = q-xstart[0];
                    cadd( chk, chk, u1(oz, oy, ox) );
                }
            }
        }
    }

    dbg_sum.real = 0;
    dbg_sum.imag = 0;
    upc_barrier;

    upc_lock(sum_write);
    dbg_sum.real += chk.real;
    dbg_sum.imag += chk.imag;
    upc_unlock(sum_write);

    upc_barrier;

    if (MYTHREAD == upc_threadof (&sums[i])){
        dcomplex* mysum = (dcomplex*)&sums[i];

        mysum->real += dbg_sum.real;
        mysum->imag += dbg_sum.imag;

        mysum->real = mysum->real / NTOTAL_F;
        mysum->imag = mysum->imag / NTOTAL_F;

        printf("T = %5d     Checksum = %22.12e %22.12e\n",
                i, mysum->real, mysum->imag);
    }

    upc_barrier;
}

void transpose2_local(int n1, int n2, shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst){
    int i, j;
    dcomplex *src_ptr, *dst_ptr;

    src_ptr = (dcomplex *) &src[MYTHREAD].cell[0];
    dst_ptr = (dcomplex *) &dst[MYTHREAD].cell[0];

    if (n1 >= n2)   /* XXX was (n1>n2) but Fortran says (n1 .ge. n2) */
        for (j = 0; j < n2; j++)
            for (i = 0; i < n1; i++)
                dst_ptr[i * n2 + j] = src_ptr[j * n1 + i];
    else
        for (i = 0; i < n1; i++)
            for (j = 0; j < n2; j++)
                dst_ptr[i * n2 + j] = src_ptr[j * n1 + i];
}

void transpose2_global(shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst ){
    int i;
    long unsigned int chunk = NTDIVNP / THREADS;

    TIMER_START( T_ALLTOALL );
    upc_barrier;

    for (i = 0; i < THREADS; i++)
    {
        upc_memget( (dcomplex *)&dst[MYTHREAD].cell[chunk*i],
                &src[i].cell[chunk*MYTHREAD], sizeof( dcomplex ) * chunk );
    }

    upc_barrier;
    TIMER_STOP( T_ALLTOALL );
}

void transpose2_finish(int n1, int n2, shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst){
    int p, i, j;
    dcomplex *src_ptr, *dst_ptr;

    src_ptr = (dcomplex *) &src[MYTHREAD].cell[0];
    dst_ptr = (dcomplex *) &dst[MYTHREAD].cell[0];

    /* Data layout from Fortran:
     *   xin [np2][n1/np2][n2]
     *   xin  [p]   [j]   [i]
     *   xout[n1/np2][n2*np2]
     *   xout [j]       [i] */
    for (p = 0; p < np2; p++)
        for (j = 0; j < n1 / np2; j++)
            for (i = 0; i < n2; i++)
                dst_ptr[j * (n2 * np2) + p * n2 + i] = src_ptr[p * n2 * (n1 / np2) + j * n2 + i];
}


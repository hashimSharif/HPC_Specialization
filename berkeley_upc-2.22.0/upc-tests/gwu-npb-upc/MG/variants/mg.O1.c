/*NAS Parallel Benchmarks 2.4 UPC versions - MG

  This benchmark is an UPC version of the NPB MG code.

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
/* OPTIMIZED VERSION (privatized) */
/*--------------------------------------------------------------------
  UPC version: F. Cantonnet  - GWU - HPCL (fcantonn@gwu.edu)
               V. Baydogan   - GWU - HPCL (vbdogan@gwu.edu)
               T. El-Ghazawi - GWU - HPCL (tarek@gwu.edu)
               S. Chauvin

  Authors(NAS): R. F. Van der Wijngaart
                E. Barszcz
                P. Frederickson
                A. Woo
                M. Yarrow
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

#include "mg-common-1.h"

void allocate_memory(int n2, int n3){

}

void psinv( shared sh_arr_t *r, shared sh_arr_t *u, int n1, int n2,
        int n3, double c[4], int k)
{
    /* psinv applies an approximate inverse as smoother:  u = u + Cr

       This  implementation costs  15A + 4M per result, where
       A and M denote the costs of Addition and Multiplication.
       Presuming coefficient c(3) is zero (the NPB assumes this,
       but it is thus not a general case), 2A + 1M may be eliminated,
       resulting in 13A + 3M.
       Note that this vectorizes, and is also fine for cache
       based machines.  */
#define u(iz,iy,ix) u_ptr[iz*n2*n1 + iy*n1 + ix]
#define r(iz,iy,ix) r_ptr[iz*n2*n1 + iy*n1 + ix]
    int i3, i2, i1;
    double r1[M], r2[M];
    double *u_ptr, *r_ptr;

    u_ptr = (double *) &u[MYTHREAD].arr[0];
    r_ptr = (double *) &r[MYTHREAD].arr[0];

    for (i3 = 1; i3 < n3-1; i3++)
    {
        for (i2 = 1; i2 < n2-1; i2++)
        {
            for (i1 = 0; i1 < n1; i1++)
            {
                r1[i1] = r(i3, (i2-1), i1) + r(i3, (i2+1), i1)
                    + r((i3-1), i2, i1) + r((i3+1), i2, i1);
                r2[i1] = r((i3-1), (i2-1), i1) + r((i3-1), (i2+1), i1)
                    + r((i3+1), (i2-1), i1) + r((i3+1), (i2+1), i1);
            }
            for (i1 = 1; i1 < n1-1; i1++)
            {
                u(i3, i2, i1) = u(i3, i2, i1)
                    + c[0] * r(i3, i2, i1)
                    + c[1] * ( r(i3, i2, (i1-1)) + r(i3, i2, (i1+1))
                            + r1[i1] )
                    + c[2] * ( r2[i1] + r1[i1-1] + r1[i1+1] );
                /* Assume c(3) = 0    (Enable line below if c(3) not= 0)
                   + c(3) * ( r2(i1-1) + r2(i1+1) ) */
            }
        }
    }

    /* exchange boundary points */
    comm3( u, n1, n2, n3, k );

    if (debug_vec[0] >= 1 )
        rep_nrm( u, n1, n2, n3, "   psinv", k );

    if (MYTHREAD == 0)
    {
        if ( debug_vec[3] >= k )
        {
            showall( u, n1, n2, n3 );
        }
    }
#undef u
#undef r
}

void resid( shared sh_arr_t *u, shared sh_arr_t *v, shared sh_arr_t *r,
        int n1, int n2, int n3, double a[4], int k )
{
    /* resid computes the residual:  r = v - Au

       This  implementation costs  15A + 4M per result, where
       A and M denote the costs of Addition (or Subtraction) and
       Multiplication, respectively.
       Presuming coefficient a(1) is zero (the NPB assumes this,
       but it is thus not a general case), 3A + 1M may be eliminated,
       resulting in 12A + 3M.
       Note that this vectorizes, and is also fine for cache
       based machines. */
#define u(iz,iy,ix) u_ptr[iz*n2*n1 + iy*n1 + ix]
#define v(iz,iy,ix) v_ptr[iz*n2*n1 + iy*n1 + ix]
#define r(iz,iy,ix) r_ptr[iz*n2*n1 + iy*n1 + ix]
    int i3, i2, i1;
    double u1[M], u2[M];
    double *u_ptr, *v_ptr, *r_ptr;

    u_ptr = (double *) &u[MYTHREAD].arr[0];
    v_ptr = (double *) &v[MYTHREAD].arr[0];
    r_ptr = (double *) &r[MYTHREAD].arr[0];

    for (i3 = 1; i3 < n3-1; i3++)
    {
        for (i2 = 1; i2 < n2-1; i2++)
        {
            for (i1 = 0; i1 < n1; i1++)
            {
                u1[i1] = u( i3, (i2-1), i1) + u( i3, (i2+1), i1)
                    + u((i3-1), i2, i1) + u((i3+1), i2, i1);
                u2[i1] = u((i3-1), (i2-1), i1) + u((i3-1), (i2+1), i1)
                    + u((i3+1), (i2-1), i1) + u((i3+1), (i2+1), i1);
            }

            for (i1 = 1; i1 < n1-1; i1++)
            {
                r(i3, i2, i1) = v(i3, i2, i1)
                    - a[0] * u(i3, i2, i1)
                    /* Assume a(1) = 0      (Enable 2 lines below if a(1) not= 0)
                       >                     - a(1) * ( u(i1-1,i2,i3) + u(i1+1,i2,i3)
                       >                              + u1(i1) ) */
                    - a[2] * ( u2[i1] + u1[i1-1] + u1[i1+1] )
                    - a[3] * ( u2[i1-1] + u2[i1+1] );
            }
        }
    }

    /* exchange boundary data */
    comm3( r, n1, n2, n3, k );
    if (debug_vec[0] >= 1)
        rep_nrm( r, n1, n2, n3, "   resid", k );

    if (MYTHREAD == 0)
    {
        if ( debug_vec[2] >= k )
        {
            showall( r, n1, n2, n3 );
        }
    }
#undef u
#undef v
#undef r
}

void rprj3( shared sh_arr_t *r, int m1k, int m2k, int m3k,
        shared sh_arr_t *s, int m1j, int m2j, int m3j, int k )
{
    /* rprj3 projects onto the next coarser grid,
       using a trilinear Finite Element projection:  s = r' = P r

       This  implementation costs  20A + 4M per result, where
       A and M denote the costs of Addition and Multiplication.
       Note that this vectorizes, and is also fine for cache
       based machines. */
#define r(iz,iy,ix) r_ptr[iz*m2k*m1k + iy*m1k + ix]
#define s(iz,iy,ix) s_ptr[iz*m2j*m1j + iy*m1j + ix]
    int j3, j2, j1, i3, i2, i1, d1, d2, d3;
    double x1[M], y1[M], x2, y2;
    double *r_ptr, *s_ptr;

    r_ptr = (double *) &r[MYTHREAD].arr[0];
    s_ptr = (double *) &s[MYTHREAD].arr[0];

    if (m1k == 3)
    {
        d1 = 2;
    }
    else
    {
        d1 = 1;
    }

    if (m2k == 3)
    {
        d2 = 2;
    }
    else
    {
        d2 = 1;
    }

    if (m3k == 3)
    {
        d3 = 2;
    }
    else
    {
        d3 = 1;
    }
    for (j3 = 1; j3 < m3j-1; j3++)
    {
        i3 = 2*j3-d3;

        for (j2 = 1; j2 < m2j-1; j2++)
        {
            i2 = 2*j2-d2;

            for (j1 = 1; j1 < m1j; j1++)
            {
                i1 = 2*j1-d1;

                x1[i1] = r((i3+1), i2, i1) + r((i3+1), (i2+2), i1)
                    + r(i3, (i2+1), i1) + r((i3+2), (i2+1), i1);
                y1[i1] = r(i3, i2, i1) + r((i3+2), i2, i1)
                    + r(i3, (i2+2), i1) + r((i3+2), (i2+2), i1);
            }

            for (j1 = 1; j1 < m1j-1; j1++)
            {
                i1 = 2*j1-d1;

                y2 = r(i3, i2, (i1+1)) + r((i3+2), i2, (i1+1))
                    + r(i3, (i2+2), (i1+1)) + r((i3+2), (i2+2), (i1+1));
                x2 = r((i3+1), i2, (i1+1)) + r((i3+1), (i2+2), (i1+1))
                    + r(i3, (i2+1), (i1+1)) + r((i3+2), (i2+1), (i1+1));
                s(j3, j2, j1) =
                    0.5 * r((i3+1), (i2+1), (i1+1))
                    + 0.25 * ( r((i3+1), (i2+1), i1) + r((i3+1), (i2+1), (i1+2)) + x2)
                    + 0.125 * ( x1[i1] + x1[i1+2] + y2)
                    + 0.0625 * ( y1[i1] + y1[i1+2] );
            }
        }
    }

    comm3( s, m1j, m2j, m3j, k-1 );
    if (debug_vec[0] >= 1)
        rep_nrm( s, m1j, m2j, m3j, "   rprj3", k-1 );

    if (MYTHREAD == 0)
    {
        if (debug_vec[4] >= k )
        {
            showall( s, m1j, m2j, m3j );
        }
    }
#undef r
#undef s
}

void interp( shared sh_arr_t *z, int mm1, int mm2, int mm3,
        shared sh_arr_t *u, int n1, int n2, int n3, int k )
{
    /* interp adds the trilinear interpolation of the correction
       from the coarser grid to the current approximation:  u = u + Qu'

       Observe that this  implementation costs  16A + 4M, where
       A and M denote the costs of Addition and Multiplication.
       Note that this vectorizes, and is also fine for cache
       based machines.  Vector machines may get slightly better
       performance however, with 8 separate "do i1" loops, rather than 4.  */
#define z(iz,iy,ix) z_ptr[iz*mm2*mm1 + iy*mm1 + ix]
#define u(iz,iy,ix) u_ptr[iz*n2*n1 + iy*n1 + ix]
    int i3, i2, i1, d1, d2, d3, t1, t2, t3;
    double *z_ptr, *u_ptr;
    double z1[M], z2[M], z3[M];

    z_ptr = (double *) &z[MYTHREAD].arr[0];
    u_ptr = (double *) &u[MYTHREAD].arr[0];

    /* note that m = 1037 in globals.h but for this only need to be 535 to handle up to 1024^3
       integer m
       parameter( m=535 ) */
    if( (n1 != 3) && (n2 != 3) && (n3 != 3) )
    {
        for (i3 = 0; i3 < mm3-1; i3++)
        {
            for (i2 = 0; i2 < mm2-1; i2++)
            {
                for (i1 = 0; i1 < mm1; i1++)
                {
                    z1[i1] = z(i3, (i2+1), i1) + z(i3, i2, i1);
                    z2[i1] = z((i3+1), i2, i1) + z(i3, i2, i1);
                    z3[i1] = z((i3+1), (i2+1), i1) + z((i3+1), i2, i1) + z1[i1];
                }

                for (i1 = 0; i1 < mm1-1; i1++)
                {
                    u((2*i3), (2*i2), (2*i1)) = u((2*i3), (2*i2), (2*i1))
                        + z(i3, i2, i1);
                    u((2*i3), (2*i2), (2*i1+1)) = u((2*i3), (2*i2), (2*i1+1))
                        +0.5*(z(i3, i2, (i1+1)) + z(i3, i2, i1));
                }

                for (i1 = 0; i1 < mm1-1; i1++)
                {
                    u((2*i3), (2*i2+1), (2*i1)) = u((2*i3), (2*i2+1), (2*i1))
                        +0.5 * z1[i1];
                    u((2*i3), (2*i2+1), (2*i1+1)) = u((2*i3), (2*i2+1), (2*i1+1))
                        +0.25*( z1[i1] + z1[i1+1] );
                }

                for (i1 = 0; i1 < mm1-1; i1++)
                {
                    u((2*i3+1), (2*i2), (2*i1)) = u((2*i3+1), (2*i2), (2*i1))
                        +0.5 * z2[i1];
                    u((2*i3+1), (2*i2), (2*i1+1)) = u((2*i3+1), (2*i2), (2*i1+1))
                        +0.25*( z2[i1] + z2[i1+1] );
                }

                for (i1 = 0; i1 < mm1-1; i1++)
                {
                    u((2*i3+1), (2*i2+1), (2*i1)) = u((2*i3+1), (2*i2+1), (2*i1))
                        +0.25* z3[i1];
                    u((2*i3+1), (2*i2+1), (2*i1+1)) = u((2*i3+1), (2*i2+1), (2*i1+1))
                        +0.125*( z3[i1] + z3[i1+1] );
                }
            }
        }
    }
    else
    {
        if (n1 == 3)
        {
            d1 = 2;
            t1 = 1;
        }
        else
        {
            d1 = 1;
            t1 = 0;
        }

        if (n2 == 3)
        {
            d2 = 2;
            t2 = 1;
        }
        else
        {
            d2 = 1;
            t2 = 0;
        }

        if (n3 == 3)
        {
            d3 = 2;
            t3 = 1;
        }
        else
        {
            d3 = 1;
            t3 = 0;
        }

        for ( i3 = d3; i3 <= mm3-1; i3++)
        {
            for ( i2 = d2; i2 <= mm2-1; i2++)
            {
                for ( i1 = d1; i1 <= mm1-1; i1++)
                {
                    u((2*i3-d3-1), (2*i2-d2-1), (2*i1-d1-1)) =
                        u((2*i3-d3-1), (2*i2-d2-1), (2*i1-d1-1))
                        +z((i3-1), (i2-1), (i1-1));
                }

                for ( i1 = 1; i1 <= mm1-1; i1++)
                {
                    u((2*i3-d3-1), (2*i2-d2-1), (2*i1-t1-1)) =
                        u((2*i3-d3-1), (2*i2-d2-1), (2*i1-t1-1))
                        +0.5*(z((i3-1), (i2-1), i1)+z((i3-1), (i2-1), (i1-1)));
                }
            }
            for ( i2 = 1; i2 <= mm2-1; i2++)
            {
                for ( i1 = d1; i1 <= mm1-1; i1++)
                {
                    u((2*i3-d3-1), (2*i2-t2-1), (2*i1-d1-1)) =
                        u((2*i3-d3-1), (2*i2-t2-1), (2*i1-d1-1))
                        +0.5*(z((i3-1), i2, (i1-1))+z((i3-1), (i2-1), (i1-1)));
                }

                for ( i1 = 1; i1 <= mm1-1; i1++)
                {
                    u((2*i3-d3-1), (2*i2-t2-1), (2*i1-t1-1)) =
                        u((2*i3-d3-1), (2*i2-t2-1), (2*i1-t1-1))
                        +0.25*(z((i3-1), i2, i1)+z((i3-1), (i2-1), i1)
                                +z((i3-1), i2, (i1-1))+z((i3-1), (i2-1), (i1-1)));
                }
            }
        }

        for ( i3 = 1; i3 <= mm3-1; i3++)
        {
            for ( i2 = d2; i2 <= mm2-1; i2++)
            {
                for ( i1 = d1; i1 <= mm1-1; i1++)
                {
                    u((2*i3-t3-1), (2*i2-d2-1), (2*i1-d1-1)) =
                        u((2*i3-t3-1), (2*i2-d2-1), (2*i1-d1-1))
                        +0.5*(z(i3, (i2-1), (i1-1))+z((i3-1), (i2-1), (i1-1)));
                }

                for ( i1 = 1; i1 <= mm1-1; i1++)
                {
                    u((2*i3-t3-1), (2*i2-d2-1), (2*i1-t1-1)) =
                        u((2*i3-t3-1), (2*i2-d2-1), (2*i1-t1-1))
                        +0.25*(z(i3, (i2-1), i1)+z(i3, (i2-1), (i1-1))
                                +z((i3-1), (i2-1), i1)+z((i3-1), (i2-1), (i1-1)));
                }
            }
            for ( i2 = 1; i2 <= mm2-1; i2++)
            {
                for ( i1 = d1; i1 <= mm1-1; i1++)
                {
                    u((2*i3-t3-1), (2*i2-t2-1), (2*i1-d1-1)) =
                        u((2*i3-t3-1), (2*i2-t2-1), (2*i1-d1-1))
                        +0.25*(z(i3, i2, (i1-1))+z(i3, (i2-1), (i1-1))
                                +z((i3-1), i2, (i1-1))+z((i3-1), (i2-1), (i1-1)));
                }

                for ( i1 = 1; i1 <= mm1-1; i1++)
                {
                    u((2*i3-t3-1), (2*i2-t2-1), (2*i1-t1-1)) =
                        u((2*i3-t3-1), (2*i2-t2-1), (2*i1-t1-1))
                        +0.125*(z(i3, i2, i1)+z(i3, (i2-1), i1)
                                +z(i3, i2, (i1-1))+z(i3, (i2-1), (i1-1))
                                +z((i3-1), i2, i1)+z((i3-1), (i2-1), i1)
                                +z((i3-1), i2, (i1-1))+z((i3-1), (i2-1), (i1-1)));
                }
            }
        }
    }

    if (debug_vec[0] >= 1)
    {
        rep_nrm( z, mm1, mm2, mm3, "z: inter", k-1 );
        rep_nrm( u, n1, n2, n3, "u: inter", k );
    }

    if (MYTHREAD == 0)
    {
        if ( debug_vec[5] >= k )
        {
            showall( z, mm1, mm2, mm3 );
            showall( u, n1, n2, n3 );
        }
    }
#undef z
#undef u
}

void norm2u3(shared sh_arr_t *r, int n1, int n2, int n3,
        double *rnm2, double *rnmu, int nx, int ny, int nz)
{
    /* norm2u3 evaluates approximations to the L2 norm and the
       uniform (or L-infinity or Chebyshev) norm, under the
       assumption that the boundaries are periodic or zero.  Add the
       boundaries in with half weight (quarter weight on the edges
       and eighth weight at the corners) for inhomogeneous boundaries.  */
#define r(iz,iy,ix) r_ptr[iz*n2*n1 + iy*n1 + ix]
    double tmp;
    int i3, i2, i1, n;
    double p_s = 0, p_a = 0;
    double *r_ptr;

    r_ptr = (double *) &r[MYTHREAD].arr[0];

    n = nx*ny*nz;

    for (i3 = 1; i3 < n3-1; i3++)
    {
        for (i2 = 1; i2 < n2-1; i2++)
        {
            for (i1 = 1; i1 < n1-1; i1++)
            {
                p_s = p_s + r(i3, i2, i1) * r(i3, i2, i1);
                tmp = fabs( r(i3, i2, i1) );
                if (tmp > p_a)
                    p_a = tmp;
            }
        }
    }

    upc_lock(critical_lock);

    s += p_s;
    if (p_a > max)
        max = p_a;

    upc_unlock(critical_lock);

    upc_barrier 20;

    *rnm2 = sqrt(s/(double)n);
    *rnmu = max;

    upc_barrier 1234;

    if (MYTHREAD == 0)
    {
        max = 0;
        s = 0.0;
    }
#undef r
}

void rep_nrm( shared sh_arr_t *u, int n1, int n2, int n3,
        const char *title, int kk)
{
    /* report on norm */
    double rnm2, rnmu;

    norm2u3( u, n1, n2, n3, &rnm2, &rnmu, nx[kk], ny[kk], nz[kk]);
    if( MYTHREAD == 0 )
        printf(" Level%2d in %8s: norms =%21.14e%21.14e\n",
            kk, title, rnm2, rnmu);
}

double lbuff[NM2];

void comm3( shared sh_arr_t *u, int n1, int n2, int n3, int kk)
{
    /* comm3 organizes the communication on all borders */
#define u_th(th,iz,iy,ix) u[th].arr[iz*n2*n1 + iy*n1 + ix]
#define u(iz,iy,ix) u_ptr[iz*n2*n1 + iy*n1 + ix]
    int fellow;
    int i2, i3;
    double *u_ptr;

    u_ptr = (double *) &u[MYTHREAD].arr[0];

    if( dead[kk] == 0 )
    {
        if( THREADS > 1 )
        {
            upc_barrier 64000;

            fellow = nbr[1][DIRm1][kk];
            for(i3=1; i3<n3-1; i3++)
            {
                for(i2=0; i2<n2; i2++)
                {
                    u_th(fellow, i3, i2, (n1-1)) = u( i3, i2, 1 );
                }
            }

            fellow = nbr[1][DIRp1][kk];
            for(i3=1; i3<n3-1; i3++)
            {
                for(i2=0; i2<n2; i2++)
                {
                    u_th(fellow, i3, i2, 0) = u( i3, i2, (n1-2) );
                }
            }

            upc_barrier 64001;

            fellow = nbr[2][DIRm1][kk];
            for(i3=1; i3<n3-1; i3++)
            {
                upc_memput( &u_th( fellow, i3, (n2-1), 0 ),
                        &u( i3, 1, 0 ),
                        n1 * sizeof( double ));
            }

            fellow = nbr[2][DIRp1][kk];
            for(i3=1; i3<n3-1; i3++)
            {
                upc_memput( &u_th( fellow, i3, 0, 0 ),
                        &u( i3, (n2-2), 0 ),
                        n1 * sizeof( double ));
            }

            upc_barrier 64002;

            fellow = nbr[3][DIRm1][kk];
            upc_memput( &u_th( fellow, (n3-1), 0, 0 ),
                    &u( 1, 0, 0 ),
                    n2 * n1 * sizeof( double ));

            fellow = nbr[3][DIRp1][kk];
            upc_memput( &u_th( fellow, 0, 0, 0 ),
                    &u( (n3-2), 0, 0 ),
                    n2 * n1 * sizeof( double ));

            upc_barrier 65000;
        }
        else
        {
            /* axis = 1 */
            for( i3 = 1; i3 < n3-1; i3++)
            {
                for( i2 = 1; i2 < n2-1; i2++)
                {
                    u(i3, i2, (n1-1)) = u(i3, i2, 1);
                    u(i3, i2, 0) = u(i3, i2, (n1-2));
                }
            }

            /* axis = 2 */
            for( i3 = 1; i3 < n3-1; i3++)
            {
                memcpy( &u( i3, (n2-1), 0 ),
                        &u( i3, 1, 0 ),
                        n1 * sizeof( double ));
                memcpy( &u( i3, 0, 0 ),
                        &u( i3, (n2-2), 0 ),
                        n1 * sizeof( double ));
            }

            /* axis = 3 */
            memcpy( &u( (n3-1), 0, 0 ),
                    &u( 1, 0, 0 ),
                    n1 * n2 * sizeof( double ) );
            memcpy( &u( 0, 0, 0 ),
                    &u( (n3-2), 0, 0 ),
                    n1 * n2 * sizeof( double ) );
        }
    }
    else
    {
        zero3(u, n1, n2, n3);

        upc_barrier 64000; // Need to stay in sync
        upc_barrier 64001;
        upc_barrier 64002;
        upc_barrier 65000;
    }
#undef u
}

void zran3( shared sh_arr_t *z, int n1, int n2, int n3,
        int nx, int ny, int k)
{
    /* zran3  loads +1 at ten randomly chosen points,
       loads -1 at a different ten random points,
       and zero elsewhere.  */
#define z(iz,iy,ix) z_ptr[iz*n2*n1 + iy*n1 + ix]
#define A pow(5.0,13)
#define X 314159265.e0

    int i0, m0, m1;
    int i1, i2, i3, d1, e1, e2, e3;
    double xx, x0, x1, a1, a2, ai;
    double ten[MM][2], best;
    int i, j1[MM][2], j2[MM][2], j3[MM][2];
    double rdummy;
    double *z_ptr;

    z_ptr = (double *) &z[MYTHREAD].arr[0];

    a1 = power( A, nx );
    a2 = power( A, nx*ny );

    zero3( z, n1, n2, n3 );

    i = is1-1+nx*(is2-1+ny*(is3-1));

    ai = power( A, i );
    d1 = ie1 - is1 + 1;
    e1 = ie1 - is1 + 2;
    e2 = ie2 - is2 + 2;
    e3 = ie3 - is3 + 2;
    x0 = X;
    rdummy = randlc( &x0, ai );

    for (i3 = 1; i3 < e3; i3++)
    {
        x1 = x0;
        for (i2 = 1; i2 < e2; i2++)
        {
            xx = x1;
            vranlc( d1, &xx, A, (double *) &(z(i3,i2,0)) );
            rdummy = randlc( &x1, a1 );
        }
        rdummy = randlc( &x0, a2 );
    }

    /* each processor looks for twenty candidates */
    for (i = 0; i < MM; i++)
    {
        ten[i][1] = 0.0;
        j1[i][1] = 0;
        j2[i][1] = 0;
        j3[i][1] = 0;
        ten[i][0] = 1.0;
        j1[i][0] = 0;
        j2[i][0] = 0;
        j3[i][0] = 0;
    }

    for (i3 = 1; i3 < n3-1; i3++)
    {
        for (i2 = 1; i2 < n2-1; i2++)
        {
            for (i1 = 1; i1 < n1-1; i1++)
            {
                if( z(i3, i2, i1) > ten[0][1] )
                {
                    ten[0][1] = z(i3, i2, i1);
                    j1[0][1] = i1;
                    j2[0][1] = i2;
                    j3[0][1] = i3;
                    bubble( ten, j1, j2, j3, MM, 1 );
                }
                if( z(i3, i2, i1) < ten[0][0] )
                {
                    ten[0][0] = z( i3, i2, i1 );
                    j1[0][0] = i1;
                    j2[0][0] = i2;
                    j3[0][0] = i3;
                    bubble( ten, j1, j2, j3, MM, 0 );
                }
            }
        }
    }

    for( i1=0; i1<4; i1++ )
    {
        for( i=0; i<MM; i++ )
        {
            upc_forall(i0=0; i0<2; i0++; &jg[i1][i][i0])
            {
                jg[i1][i][i0]=0;
            }
        }
    }

    upc_barrier 30;

    /* Now which of these are globally best?  */
    i1 = MM - 1;
    i0 = MM - 1;

    for (i = MM - 1 ; i >= 0; i--)
    {
        best = z( j3[i1][1], j2[i1][1], j1[i1][1] );

        if( MYTHREAD == 0 )
            red_best=0;

        upc_barrier 20;

        upc_lock(critical_lock);
        if (red_best<best)
        {
            red_best=best;
            red_winner=MYTHREAD;
        }
        upc_unlock(critical_lock);

        upc_barrier 21;

        best=red_best;
        if (red_winner==MYTHREAD)
        {
            jg[0][i][1] = MYTHREAD;
            jg[1][i][1] = is1 - 1 + j1[i1][1];
            jg[2][i][1] = is2 - 1 + j2[i1][1];
            jg[3][i][1] = is3 - 1 + j3[i1][1];
            i1 = i1-1;
        }
        upc_barrier;

        ten[i][1] = best;

        best = z( j3[i0][0], j2[i0][0], j1[i0][0] );

        if( MYTHREAD == 0 )
            red_best=1;

        upc_barrier 22;

        upc_lock(critical_lock);
        if (red_best>best)
        {
            red_best=best;
            red_winner=MYTHREAD;
        }
        upc_unlock(critical_lock);

        upc_barrier 23;

        best=red_best;
        if (red_winner==MYTHREAD)
        {
            jg[0][i][0] = MYTHREAD;
            jg[1][i][0] = is1 - 1 + j1[i0][0];
            jg[2][i][0] = is2 - 1 + j2[i0][0];
            jg[3][i][0] = is3 - 1 + j3[i0][0];
            i0 = i0-1;
        }
        ten[i][0] = best;

        upc_barrier;
    }

    m1 = i1+1;
    m0 = i0+1;

    zero3( z,n1,n2,n3 );

    for (i = MM-1; i >= m0; i--)
    {
        z( j3[i][0], j2[i][0], j1[i][0]) = -1.0;
    }
    for (i = MM-1; i >= m1; i--)
    {
        z( j3[i][1], j2[i][1], j1[i][1]) = 1.0;
    }

    comm3( z, n1, n2, n3, k );
#undef z
}

void showall( shared sh_arr_t *z, int n1, int n2, int n3)
{
#define z(iz,iy,ix) z_ptr[iz*n2*n1 + iy*n1 + ix]
    int i1,i2,i3;
    int m1, m2, m3;
    double *z_ptr;

    z_ptr = (double *) &z[MYTHREAD].arr[0];

    m1 = min(n1,18);
    m2 = min(n2,14);
    m3 = min(n3,18);

    printf("\n");
    for (i3 = 0; i3 < m3; i3++)
    {
        for (i1 = 0; i1 < m1; i1++)
        {
            for (i2 = 0; i2 < m2; i2++)
            {
                printf("%6.3f", z(i3, i2, i1));
            }
            printf("\n");
        }
        printf(" - - - - - - - \n");
    }
    printf("\n");
#undef z
}

void zero3( shared sh_arr_t *z, int n1, int n2, int n3)
{
#define z(iz,iy,ix) z_ptr[iz*n2*n1 + iy*n1 + ix]
    double *z_ptr;

    z_ptr = (double *) &z[MYTHREAD].arr[0];

    memset( z_ptr, 0, n1 * n2 * n3 * sizeof( double ));
}


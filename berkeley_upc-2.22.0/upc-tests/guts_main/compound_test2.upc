/*
 * The GWU Unified Testing Suite (GUTS) 
 * Latest modifications and integration to GUTS framework
 *  
 * Copyright (C) 2007 ... Abdullah Kayi
 * Copyright (C) 2007 ... Tarek El-Ghazawi 
 * Copyright (C) 2007 ... The George Washington University
 *
 * ---------------------------------------------------------------------------
 *
 * UPC Testing Suite Original Development
 *
 * Copyright (C) 2003 ... Francois Cantonnet, Ashrujit Mohanty, Tarek El-Ghazawi
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include <upc.h>
#include <gula.h>
#include <stdio.h>

#define N 5
#define M 5
#define O 5

/* global variables */

struct mystruct_a_s {
    double cell[M][N][O];
};

shared struct mystruct_a_s A[THREADS];

struct mystruct_b_s {
    double cell[M*N*O];
};

shared struct mystruct_b_s B[THREADS];

int
main()
{
    /*
     * To check the declaration of shared structures
     */

    int error ,th ,i, j , k ;
    th=0;
    error=0;
    for ( i =0 ; i < M ; i++){
        for ( j=0 ; j < N ; j++ ){
            for (k=0 ; k < O ; k++){
                A[MYTHREAD].cell[i][j][k] =(k+j*O+i*O*N)+(MYTHREAD*M*N*O);
            }
        }
    }

    for ( i =0 ; i < M ; i++){
        for ( j=0 ; j < N ; j++ ){
            for (k=0 ; k < O ; k++){
                B[MYTHREAD].cell[i*O*N+j*O+k] =(k+j*O+i*O*N)+(MYTHREAD*M*N*O);
            }
        }
    }

    upc_barrier;

    if(MYTHREAD==0){
        for (th = 0 ; th < THREADS ; th++ ){
            for ( i =0 ; i < M ; i++){
                for ( j=0 ; j < N ; j++ ){
                    for (k=0 ; k < O ; k++){
                        if(  (A[th].cell[i][j][k] !=  B[th].cell[i*O*N+j*O+k]) ||(A[th].cell[i][j][k]  != (k+j*O+i*O*N)+(th*M*N*O)))
                            error = 1;
                    }
                }
            }
        }
    }

    if(MYTHREAD==0){
        if(error==1)
            GULA_FAIL("failed to declare shared structures properly");
    }

    upc_barrier;

#ifdef BUPC_TEST_HARNESS
    upc_barrier;

    if (!MYTHREAD)
        printf ("Passed.\n");

#endif /* BUPC_TEST_HARNESS */
    return 0;
}

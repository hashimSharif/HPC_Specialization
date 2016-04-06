/*--------------------------------------------------------------------
  NAS Parallel Benchmarks 2.3 UPC versions - CG

  This version of UPC CG was developed by the high performance
  computing group in the Computer Science Department in the
  University of North Carolina. It was derivated from the 
  Fortran versions in "NPB 2.3-serial" developed by NAS and 
  the Openmp ersion developed by RWCP. 
  
  We hereby grant the permission to use, copy, distribute and 
  modify this software for any purpose with/without fee.
  This software is provided in "as is" fashion. No explicit or 
  implied warranty may be derived. 

  Please send comments on the UPC versions to prins@cs.unc.edu
  For RWCP OpenMp implementation, refer to website at:
           http://pdplab.trc.rwcp.or.jp/pdperf/Omni/
  NASA's NPB benchmark is on line at:
           http://www.nas.nasa.gov/NAS/NPB/
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
  Authors: Luke Huan
           Jeff Feasel
           Jan Prins
----------------------------------------------------------------------*/
#include "upc_relaxed.h"
#include "upc.h"
#include "npb-C.h"
#include "npbparams.h"
#define NZ      NA*(NONZER+1)*(NONZER+1)+NA*(NONZER+2)
#define NONZER_SQ (NONZER+1)*(NONZER+2) + 1
#define BLOCK_LIMT 1000
#define BLOCK_V  100
//#define BLOCK_S (BLOCK_LIMT / (NONZER_SQ) * (NONZER_SQ))
#define BLOCK_S 1000
#define PARAL_F (BLOCK_S / (NONZER_SQ))
#define LOOP_C(a, i) a[i] 
#define LOOP_C1(i, j) (i/j) 
#define UNBALANCE_F 1.5
#define FIRST_FIT(i,j, k) ((i) <= (k))
#define LAST__FIT(i,j, k) ((i+j) <= (k))
#define BEST_FIT(i,j, k)  ((i+(j)/2)) <= (k))
#define TRUE 1
#define FALSE 0
#define MAPPING(i) (((i)% (BLOCK_S *THREADS)) / BLOCK_S)
#define DEBUGGING FALSE
#define STATISTICS TRUE

/* global variables */
/* common /partit_size/ */
static int naa;
static int nzz;
static int firstrow;
static int lastrow;
static int firstcol;
static int lastcol;
/* common /main_int_mem/ */
shared [BLOCK_S] static int colidx[NZ+1];        /* colidx[1:NZ] */
//shared [BLOCK_S] static int rowstr[NA+1+1];      /* rowstr[1:NA+1] */
shared [BLOCK_S] static int rowstr[NA+1+1];
static int af[NA+1+1];          /* affinity table*/
static int budy[NA+1+1];    
static int cross[NA+1+1];
static int iv[2*NA+1+1];        /* iv[1:2*NA+1] */
static int arow[NZ+1];          /* arow[1:NZ] */
static int acol[NZ+1];          /* acol[1:NZ] */
/* common /main_flt_mem/ */
static double v[NA+1+1];        /* v[1:NA+1] */
static double aelt[NZ+1];       /* aelt[1:NZ] */
/*shared a - sparse matrix*/
shared [BLOCK_S]static double a[NZ+1];   /* a[1:NZ] */
shared [BLOCK_V]static double sx[NA+2+1];        /* x[1:NA+2] */
shared [BLOCK_V]static double sz[NA+2+1];        /* z[1:NA+2] */

//shared [BLOCK_S]static double sp[NA+2+1];        /* p[1:NA+2] */
//shared [BLOCK_S]static double sq[NA+2+1];        /* q[1:NA+2] */
//shared [BLOCK_S]static double sr[NA+2+1];        /* r[1:NA+2] */
//shared [BLOCK_S]static double sw[NA+2+1];        /* w[1:NA+2] */


/*shared object need to be reducted*/
shared static double  sarho[THREADS];  /*the patial arho is calculated by each thread*/

/*template for reduction variable*/
shared [THREADS] static double sharevalary[THREADS];
shared static double shareval;
shared [BLOCK_S] static double st[NA+2+1];
shared static double sharedTwoDarray[NA+2+1][THREADS];

/*local variables*/
static int local_rowstr[NA+2+1]; 
#if 0 /* Illegal (not integral constant) dimension (BUPC bug 2713) AND UNUSED! -PHH */
static double local_a[(int)(NZ/THREADS*UNBALANCE_F)];
#endif

/*extra memory working space*/
static int work1[NA+1];
static int work2[NA+1];

/* common /urando/ */
static double amult;
static double tran;

/* function declarations */
static int  debugging();
static int  statistics();
static void reduction_vector(double p[], int af[]);
static void reduction_share(double *value_p);
static void floatcopyin(double * dest, shared [BLOCK_S] double * sorc, int size, int block_size);
static void floatcopyin2(double * dest, shared [BLOCK_V] double * sorc, int size, int block_size);
static void intcopyin(int  * dest, shared  [BLOCK_S] int * sorc, int size, int block_size );
static void intcopyout(shared  [BLOCK_S] int * dest, int * sorc, int size, int block_size);
static void floatcopyout(shared  [BLOCK_S] double * dest, double * sorc, int size, int block_size);
static void reduction_TwoDarray(double p[], int af[], int cross[]);
static void conj_grad (shared [BLOCK_S] int colidx[], 
                       int rowstr[], 
                       shared [BLOCK_S] double a[], int af[], double *rnorm);
static void makea(int n, int nz, double a[], int colidx[], 
                  int rowstr[], int nonzer, int firstrow, int lastrow, int firstcol,
                  int lastcol, double rcond, int arow[], int acol[],
                  double aelt[], double v[], int iv[], double shift );
static void sparse(double a[], int colidx[], 
                   int rowstr[], int n,
                   int arow[], int acol[], double aelt[],
                   int firstrow, int lastrow,
                   double x[], boolean mark[], int nzloc[], int nnza);
static void sprnvc(int n, int nz, double v[], int iv[], int nzloc[], int mark[]);
static int icnvrt(double x, int ipwr2);
static void vecset(int n, double v[], int iv[], int *nzv, int i, double val);


/*--------------------------------------------------------------------
      program cg
--------------------------------------------------------------------*/
int main(int argc, char **argv) {
    int i, j, k, it;
    int nthreads = 1;
    int current_boundary;
    int current_p, size;
    double zeta;
    double rnorm;
    double norm_temp11;
    double norm_temp12;
    double t, mflops, t1;
    char class;
    boolean verified;
    double zeta_verify_value, epsilon; 
    int mem_size;
    int lcross;
    static double local_a[NZ+1];
    static int local_colidx[NZ+1];

    firstrow = 1;
    lastrow  = NA;
    firstcol = 1;
    lastcol  = NA;

    if (NA == 1400 && NONZER == 7 && NITER == 15 && SHIFT == 10.0) {
        class = 'S';
        zeta_verify_value = 8.5971775078648;
    } else if (NA == 7000 && NONZER == 8 && NITER == 15 && SHIFT == 12.0) {
        class = 'W';
        zeta_verify_value = 10.362595087124;
    } else if (NA == 14000 && NONZER == 11 && NITER == 15 && SHIFT == 20.0) {
        class = 'A';
        zeta_verify_value = 17.130235054029;
    } else if (NA == 75000 && NONZER == 13 && NITER == 75 && SHIFT == 60.0) {
        class = 'B';
        zeta_verify_value = 22.712745482631;
    } else if (NA == 150000 && NONZER == 15 && NITER == 75 && SHIFT == 110.0) {
        class = 'C';
        zeta_verify_value = 28.973605592845;
    } else {
        class = 'U';
    }

 
    if (MYTHREAD == 0 ){
      printf("\n\n NAS Parallel Benchmarks 2.3 UPC version"
           " - CG Benchmark\n");
      printf(" Size: %10d\n", NA);
      printf(" Iterations: %5d\n", NITER);
      naa = NA;
      nzz = NZ; 
      timer_clear( 20 );  
      timer_clear( 21 );  
      timer_clear( 22 );

    }
 

/*--------------------------------------------------------------------
c  Initialize random number generator
c-------------------------------------------------------------------*/
    tran    = 314159265.0;
    amult   = 1220703125.0;
    zeta    = randlc( &tran, amult );
/*--------------------------------------------------------------------
c  
c-------------------------------------------------------------------*/
    if( statistics() ){
          timer_start( 20 );
    }

    if (MYTHREAD == 0 ){
      makea(naa, nzz, local_a, local_colidx, local_rowstr, NONZER,
          firstrow, lastrow, firstcol, lastcol, 
          RCOND, arow, acol, aelt, v, iv, SHIFT);
    }

       
    //submit the local copy of local_rowstr to the shared copy
    if (MYTHREAD == 0){ 
      floatcopyout(a, local_a, NZ+1, BLOCK_S);
      intcopyout(colidx, local_colidx, NZ+1, BLOCK_S);
      intcopyout(rowstr, local_rowstr, (NA+2), BLOCK_S);
    }
    upc_barrier;

   
    //copy into local rowstr
    //not for the master thread
    upc_forall (j=1; j<THREADS; j++; j){
      intcopyin(local_rowstr, rowstr, NA+2, BLOCK_S);
    }

    if( statistics() ){
       timer_stop( 20 );
    }

    if( statistics() ){
       timer_start( 21);
    }

    //calculate the af table, we just let each thread to calculate 
    //the af (redundent work, but there is no need
    //for the master to calculate and copy to each thread
    //which involves synchronization of all threads
     for(i = 1; i<= lastrow - firstrow +1; i++){
       current_p = rowstr[i];   
       size = rowstr[i+1] - rowstr[i];
       current_boundary = (current_p/ BLOCK_S +1) * BLOCK_S;
       budy[i] = rowstr[i+1] > current_boundary ? current_boundary - current_p : size;
       lcross = 0;

       af[i] = MAPPING(current_p);
       current_p += budy[i];

       while ( current_p < rowstr[i+1] ){
          lcross++;  
          current_p += BLOCK_S;
       }

       cross[i] = lcross;

     }
     
     //set the boundary
     af[0] = THREADS;
     af[NA+1] = (af[NA] +  1 )% THREADS;
    
     if( statistics() ){
       timer_stop( 21 );
     } 
/*---------------------------------------------------------------------
c  Note: as a result of the above call to makea:
c        values of j used in indexing rowstr go from 1 --> lastrow-firstrow+1
c        values of colidx which are col indexes go from firstcol --> lastcol
c        So:
c        Shift the col index vals from actual (firstcol --> lastcol ) 
c        to local, i.e., (1 --> lastcol-firstcol+1)
c---------------------------------------------------------------------*/

 
/*--------------------------------------------------------------------
c  set starting vector to (1, 1, .... 1)
c-------------------------------------------------------------------*/

    upc_forall (i = 1; i <= NA+1; i++;i/BLOCK_V ) {
      *((double*)&sx[i]) = 1.0;
    }

   
    upc_barrier;

    zeta  = 0.0;
  
    
/*-------------------------------------------------------------------
c---->
c  Do one iteration untimed to init all code and data page tables
c---->                    (then reinit, start timing, to niter its)
c-------------------------------------------------------------------*/
    if( statistics() ){
          timer_start( 22 );
    }

    for (it = 1; it <= 1; it++) {
/*--------------------------------------------------------------------
c  The call to the conjugate gradient routine:
c-------------------------------------------------------------------*/
        
     conj_grad (colidx, local_rowstr, a, af, &rnorm);

/*--------------------------------------------------------------------
c  zeta = shift + 1/(x.z)
c  So, first: (x.z)
c  Also, find norm of z
c  So, first: (z.z)
c-------------------------------------------------------------------*/

     norm_temp11 = 0.0;
     norm_temp12 = 0.0;

     /*#pragma omp for reduction(+:norm_temp11,norm_temp12)*/
     upc_forall (j = 1; j <= lastcol-firstcol+1; j++; j/BLOCK_V) {
       norm_temp11 = norm_temp11 + sx[j]*sz[j];
       norm_temp12 = norm_temp12 + sz[j]*sz[j];          
     }


     reduction_share(&norm_temp12);
     reduction_share(&norm_temp11);

     if ( debugging() ){
       printf("the norm_temp12 %e\n", norm_temp12);
       printf("the norm_temp11 %e\n", norm_temp11);
     }


     norm_temp12 = 1.0 / sqrt( norm_temp12 );
	 

/*--------------------------------------------------------------------
c  Normalize z to obtain x
c-------------------------------------------------------------------*/
    
     upc_forall (j = 1; j <= lastcol-firstcol+1; j++; (j-1)/BLOCK_V) {
        sx[j] = norm_temp12*sz[j];
     }
        
     /*synchronization*/
     upc_barrier;

        
    } /* end of do one iteration untimed */

    if (DEBUGGING )    
      return 0;
/*--------------------------------------------------------------------
c  set starting vector to (1, 1, .... 1)
c-------------------------------------------------------------------*/
 
    upc_forall (i = 1; i <= NA+1; i++; i/BLOCK_V) {
      *((double*)&sx[i]) = 1.0;
    }
    
    //synchronize all thread
    upc_barrier;

    zeta  = 0.0;

    if( statistics() ){
       timer_stop( 22 );
    } 

/*--------------------------------------------------------------------
c---->
c  Main Iteration for inverse power method
c---->
c-------------------------------------------------------------------*/

  //initialize the timer for the performance analysis
  if(MYTHREAD == 0){
      timer_clear( 1 );
      timer_clear( 2 );
      timer_clear( 3 );
      timer_clear( 4);
      timer_clear( 5 );
      timer_clear( 6 );
      timer_clear( 7 );
      timer_clear( 8 );
      timer_clear( 9 );
      timer_clear( 10 );
      timer_clear( 11 );
      timer_clear( 12 );
      timer_clear( 13 );
      timer_clear( 14 );
      timer_clear( 15 );
      timer_clear( 16 ); 
      timer_clear( 17 );  
      timer_clear( 18 );  
      timer_clear( 19 );
  }


  if(MYTHREAD ==0 )
      timer_start( 1 );

   for (it = 1; it <=NITER; it++) {
  /*------------------------------------------------------------------
c  The call to the conjugate gradient routine:
c-------------------------------------------------------------------*/
     if( statistics() ){
       timer_start( 2 );
     }

     conj_grad(colidx, local_rowstr, a, af, &rnorm);

     if( statistics() ){
       timer_stop( 2 );
     }

/*--------------------------------------------------------------------
c  zeta = shift + 1/(x.z)
c  So, first: (x.z)
c  Also, find norm of z
c  So, first: (z.z)
c-------------------------------------------------------------------*/


     norm_temp11 = 0.0;
     norm_temp12 = 0.0;

     if( statistics() ){
       timer_start( 15 );
     }

     upc_forall (j = 1; j <= lastcol-firstcol+1; j++; j/BLOCK_V) {
       norm_temp11 = norm_temp11 + sx[j]*sz[j];
       norm_temp12 = norm_temp12 + sz[j]*sz[j];
     }
    
     reduction_share(&norm_temp12);
     reduction_share(&norm_temp11);

     if( statistics() ){
        timer_stop( 15 );
     }


     /*#pragma omp single*/	  
     norm_temp12 = 1.0 / sqrt( norm_temp12 );
     zeta = SHIFT + 1.0 / norm_temp11;
	
     if (MYTHREAD == 0) /*#pragma omp master*/{
	if( it == 1 ) {
	    printf("   iteration           ||r||                 zeta\n");
	}
        printf("    %5d       %20.14e%20.13e\n", it, rnorm, zeta);
      }
/*--------------------------------------------------------------------
c  Normalize z to obtain x
c-------------------------------------------------------------------*/
      
      if( statistics() ){
        timer_start( 16 );
      } 

      upc_forall (j = 1; j <= lastcol-firstcol+1; j++; j/BLOCK_V) {
          sx[j] = norm_temp12*sz[j];
      }

      /*synchronization*/
      upc_barrier; 
  
      if( statistics() ){
          timer_stop( 16 );
      }
   } /* end of main iter inv pow meth */


   if(MYTHREAD ==0 ){
     timer_stop( 1 );
     t = timer_read( 1 );
    }
/*--------------------------------------------------------------------
c  End of timed section
c-------------------------------------------------------------------*/

    if(MYTHREAD ==0 ){
      printf(" Benchmark completed\n");

      epsilon = 1.0e-10;
      if (class != 'U') {
        if (fabs(zeta - zeta_verify_value) <= epsilon) {
            verified = TRUE;
            printf(" VERIFICATION SUCCESSFUL\n");
            printf(" Zeta is    %20.12e\n", zeta);
            printf(" Error is   %20.12e\n", zeta - zeta_verify_value);
        } else {
            verified = FALSE;
            printf(" VERIFICATION FAILED\n");
            printf(" Zeta                %20.12e\n", zeta);
            printf(" The correct zeta is %20.12e\n", zeta_verify_value);
        }
      } else {
        verified = FALSE;
        printf(" Problem size unknown\n");
        printf(" NO VERIFICATION PERFORMED\n");
     }

     if ( t != 0.0 ) {
        mflops = (2.0*NITER*NA)
            * (3.0+(NONZER*(NONZER+1)) + 25.0*(5.0+(NONZER*(NONZER+1))) + 3.0 )
            / t / 1000000.0;
     } else {
        mflops = 0.0;
     }

    if( statistics() ){
      t1 = timer_read( 1 );
        printf("total time %e \n", t1);
      t1 = timer_read( 2 );
        printf("conj time %e \n", t1);
      t1 = timer_read( 3 );
        printf("a * p  %e \n", t1);
      t1 = timer_read( 4 );
        printf("reduction q %e \n", t1);
       t1 = timer_read( 5 );
        printf("d %e \n", t1);
      t1 = timer_read( 6 );
        printf("r  z %e \n", t1);
      t1 = timer_read( 7 );
        printf("rho %e \n", t1);
      t1 = timer_read( 8 );
        printf("update p and reduction %e \n", t1);
      t1 = timer_read( 9 );
        printf("reduction z %e \n", t1);
      t1 = timer_read( 10 );
        printf("a * z %e \n", t1);
      t1 = timer_read( 11 );
        printf("sum %e \n", t1); 
      t1 = timer_read( 12);
        printf("sx szupdate %e \n", t1); 
      t1 = timer_read( 13 );
        printf("sx copy in %e \n", t1); 
      t1 = timer_read( 14 );
        printf("calculate rho0 %e \n", t1 ); 
      t1 = timer_read( 15 );
        printf("calculate norm %e \n", t1); 
      t1 = timer_read( 16 );
        printf("update sx %e \n", t1 );
      t1 = timer_read( 17 );
        printf("submit %e \n", t1 ); 
      t1 = timer_read( 18 );
        printf("sum up %e \n", t1); 
      t1 = timer_read( 19 );
        printf("copyin %e \n", t1 );
      t1 = timer_read( 20 );
        printf("make a  %e \n", t1); 
      t1 = timer_read( 21 );
        printf("calculate cross %e \n", t1 );
      t1 = timer_read( 22 );
        printf("first conj_grad  %e \n", t1 );

     }
     c_print_results("CG", class, NA, 0, 0, NITER, nthreads, t, 
                    mflops, "          floating point", 
                    verified, NPBVERSION, COMPILETIME,
                    NPB_CS1, NPB_CS2, NPB_CS3, NPB_CS4, NPB_CS5, NPB_CS6, NPB_CS7);

    }
}

/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
static void conj_grad (
    shared [BLOCK_S] int colidx[],       /* colidx[1:nzz] */
    int rowstr[],       /* rowstr[1:naa+1] */
    shared [BLOCK_S] double a[],         /* a[1:nzz] */
    int af[],
    double *rnorm )
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
    
/*---------------------------------------------------------------------
c  Floaging point arrays here are named as in NPB1 spec discussion of 
c  CG algorithm
c---------------------------------------------------------------------*/
{
    static double d, sum, rho, rho0, alpha, beta;
    int i, j, k;
    int cgit, cgitmax = 25;
    static double x[NA+2+1];        /* x[1:NA+2] */
    static double z[NA+2+1];        /* z[1:NA+2] */
    static double p[NA+2+1];        /* p[1:NA+2] */
    static double q[NA+2+1];        /* q[1:NA+2] */
    static double r[NA+2+1];        /* r[1:NA+2] */
    static double w[NA+2+1];        /* w[1:NA+2] */
    double t0, t;
    static double local_a[NA+2+1];
    static int    local_colidx[NA+2+1];
    int start_p, boundary;
    int *local_colidx_p;
    double *local_a_p;
    double * local_q , *local_r;

    /*#pragma omp single nowait*/
    rho = 0.0;
    
/*--------------------------------------------------------------------
c  Initialize the CG algorithm:
c-------------------------------------------------------------------*/
 
    /*initialization which need to be updated later*/ 
    if( statistics() ){
       timer_start( 13 );
    }

    floatcopyin2(x, sx, NA+2, BLOCK_V);
    for(j=1; j<= NA+1; j++){
       q[j] = 0.0;
       z[j] = 0.0;
       r[j] = x[j];
       p[j] = r[j];
       w[j] = 0.0;
    } 
 
    if( statistics() ){
       timer_stop (13 );
    }

 /*--------------------------------------------------------------------
c  rho = r.r
c  Now, obtain the norm of r: First, sum squares of r elements locally...
c-------------------------------------------------------------------*/

    if( statistics() ){
      timer_start( 14 );
    }
    upc_forall (j = 1; j <= lastcol-firstcol+1; j++; LOOP_C(af, j) ) {
      rho = rho + x[j]*x[j];
    }

    reduction_share(&rho);
    if( statistics() ){
      timer_stop( 14 );
    }
    
    
    if ( debugging() )
      printf("finished rho %d : %e \n", MYTHREAD, rho); 

/*--------------------------------------------------------------------
c---->
c  The conj grad iteration loop
c---->
c-------------------------------------------------------------------*/
   if ( DEBUGGING )  cgitmax = 1;

   for (cgit = 1; cgit <=cgitmax; cgit++) {

       rho0 = rho;
       d = 0.0;
       rho = 0.0;

      
/*--------------------------------------------------------------------
c  q = A.p
c  The partition submatrix-vector multiply: use workspace w
c---------------------------------------------------------------------
C
C  NOTE: this version of the multiply is actually (slightly: maybe %5) 
C        faster on the sp2 on 16 nodes than is the unrolled-by-2 version 
C        below.   On the Cray t3d, the reverse is true, i.e., the 
C        unrolled-by-two version is some 10% faster.  
C        The unrolled-by-8 version below is significantly faster
C        on the Cray t3d - overall speed of code is 1.5 times faster.
*/

    if( statistics() ){
       timer_start( 3 );
    }
  
    //use the memory for the reduction
    local_q = (double*) &sharedTwoDarray[0][MYTHREAD];
    for(j = 1; j <= lastrow-firstrow+1; j++) {
       sum = 0.0;
           
       for(i =af[j]; i<= af[j] + cross[j]; i++){

          //MYTHREAD has affinity to this row 
          if (MYTHREAD == i % THREADS){ 
          
          //start point and boundary 
          if ( i == af[j])  //the first thread
              start_p = rowstr[j];
          else 
              start_p = rowstr[j] + budy[j] + (i-af[j]-1) * BLOCK_S;
 
          //boundary
          boundary = rowstr[j] + budy[j] + (i - af[j]) * BLOCK_S;

          local_a_p = (double*) &a[start_p];
          local_colidx_p = (int*) &colidx[start_p];

          //partial sum
          for (k = 0; ( k < (rowstr[j+1] -start_p) && k < (boundary-start_p) ); k++) {
               sum = sum + *(local_a_p+k)*p[*(local_colidx_p+k)];
          }
          //q[j] = sum; 
          local_q[j]  =sum;
        }
     }
  }

  if( statistics() ){
     timer_stop( 3 );
  }


  if( statistics() ){
     timer_start( 4 );
  }

  if (THREADS != 1)
    reduction_TwoDarray(q, af, cross);

  if( statistics() ){
    timer_stop( 4 );
  }
        
/* unrolled-by-two version
#pragma omp for private(i,k)
        for (j = 1; j <= lastrow-firstrow+1; j++) {
            int iresidue;
            double sum1, sum2;
            i = rowstr[j]; 
            iresidue = (rowstr[j+1]-i) % 2;
            sum1 = 0.0;
            sum2 = 0.0;
            if (iresidue == 1) sum1 = sum1 + a[i]*p[colidx[i]];
            for (k = i+iresidue; k <= rowstr[j+1]-2; k += 2) {
                sum1 = sum1 + a[k]   * p[colidx[k]];
                sum2 = sum2 + a[k+1] * p[colidx[k+1]];
            }
            w[j] = sum1 + sum2;
        }
*/
/* unrolled-by-8 version
#pragma omp for private(i,k,sum)
        for (j = 1; j <= lastrow-firstrow+1; j++) {
            int iresidue;
            i = rowstr[j]; 
            iresidue = (rowstr[j+1]-i) % 8;
            sum = 0.0;
            for (k = i; k <= i+iresidue-1; k++) {
                sum = sum +  a[k] * p[colidx[k]];
            }
            for (k = i+iresidue; k <= rowstr[j+1]-8; k += 8) {
                sum = sum + a[k  ] * p[colidx[k  ]]
                          + a[k+1] * p[colidx[k+1]]
                          + a[k+2] * p[colidx[k+2]]
                          + a[k+3] * p[colidx[k+3]]
                          + a[k+4] * p[colidx[k+4]]
                          + a[k+5] * p[colidx[k+5]]
                          + a[k+6] * p[colidx[k+6]]
                          + a[k+7] * p[colidx[k+7]];
            }
            w[j] = sum;
        }
*/
        
	/*#pragma omp for*/
	/*        for (j = 1; j <= lastcol-firstcol+1; j++) {
            q[j] = w[j];
        }*/

/*--------------------------------------------------------------------
c  Clear w for reuse...
c-------------------------------------------------------------------*/
	/*#pragma omp for nowait*/
	/* for (j = 1; j <= lastcol-firstcol+1; j++) {
            w[j] = 0.0;
        }*/

/*--------------------------------------------------------------------
c  Obtain p.q
c-------------------------------------------------------------------*/
    if( statistics() ){
      timer_start( 5 );
    }

    //upc_forall (j = 1; j <= lastcol-firstcol+1; j++; LOOP_C(af, j)) {
    for  (j = 1; j <= lastcol-firstcol+1; j++){
       //d = d + p[j]*q[j];
       d = d + p[j]*local_q[j];
    }

    //then do the sum and copy back
    //reduction_share(&d);

    if( statistics() ){
       timer_stop( 5 );
    }


    if (debugging() ) 
      printf("finished d %d : %e \n", MYTHREAD, d);

/*--------------------------------------------------------------------
c  Obtain alpha = rho / (p.q)
c-------------------------------------------------------------------*/
     if( statistics() ){
       timer_start( 6 );
     }

     alpha = rho0 / d;
        
     if ( debugging() ) 
       printf("finished alpha %d : %e \n", MYTHREAD, alpha); 

/*--------------------------------------------------------------------
c  Save a temporary of rho
c-------------------------------------------------------------------*/

/*---------------------------------------------------------------------
c  Obtain z = z + alpha*p
c  and    r = r - alpha*q
c---------------------------------------------------------------------*/

     //upc_forall (j = 1; j <= lastcol-firstcol+1; j++; LOOP_C(af, j)) {
     for(j = 1; j <= lastcol-firstcol+1; j++){
        z[j] = z[j] + alpha*p[j];
        r[j] = r[j] - alpha*local_q[j];
     }
            
     if( statistics() ){
        timer_stop( 6 );
     }
/*---------------------------------------------------------------------
c  rho = r.r
c  Now, obtain the norm of r: First, sum squares of r elements locally...
c---------------------------------------------------------------------*/

     if( statistics() ){
        timer_start( 7 );
     }


     //upc_forall (j = 1; j <= lastcol-firstcol+1; j++; LOOP_C(af, j) ) { 
     for (j = 1; j <= lastcol-firstcol+1; j++) {
        rho = rho + r[j]*r[j];
     }
        
     /*shared value for reduction*/
     //reduction_share(&rho);

     if( statistics() ){
        timer_stop( 7 );
     }

        
     if ( debugging() ){	
        printf("finished rho %d : %e \n", MYTHREAD, rho); 
        printf("finished rho0 %d : %e \n", MYTHREAD, rho0); 
     }
/*--------------------------------------------------------------------
c  Obtain beta:
c-------------------------------------------------------------------*/

     beta = rho / rho0;
        
        
     if ( debugging() )
	printf("finished beta %d : %e \n", MYTHREAD, beta); 

/*--------------------------------------------------------------------
c  p = r + beta*p
c-------------------------------------------------------------------*/   
     if( statistics() ){
        timer_start( 8 );
     }

     //upc_forall (j = 1; j <= lastcol-firstcol+1; j++; LOOP_C(af, j) ) {
     for (j = 1; j <= lastcol-firstcol+1; j++ ) {
       p[j] = r[j] + beta*p[j];
     }

        //make sure every thread will get the same copy of p
     /*if (THREADS > 1)
      reduction_vector(p, af);  */

     if( statistics() ){
        timer_stop( 8 );
     }

  } /* end of do cgit=1,cgitmax */

/*---------------------------------------------------------------------
c  Compute residual norm explicitly:  ||r|| = ||x - A.z||
c  First, form A.z
c  The partition submatrix-vector multiply
c---------------------------------------------------------------------*/
   
    sum = 0.0;
    
    /* we need to synchronize Z also*/
    if( statistics() ){
      timer_start( 9 );
    }

    if (THREADS >1)
      reduction_vector(z, af);  
    
    if( statistics() ){
          timer_stop( 9 );
    }

    /*the last a * Z*/
    if( statistics() ){
       timer_start( 10 );
    }

    local_r = (double*) &sharedTwoDarray[0][MYTHREAD];
    for(j = 1; j <= lastrow-firstrow+1; j++) {
        sum = 0.0;
           
        for(i =af[j]; i<= af[j] + cross[j]; i++){

            //MYTHREAD has affinity to this row 
            if (MYTHREAD == i % THREADS){ 
               //start point and boundary 
               if ( i == af[j])  //the first thread
                 start_p = rowstr[j];
               else 
                 start_p = rowstr[j] + budy[j] + (i-af[j]-1) * BLOCK_S;
 
               //boundary
               boundary = rowstr[j] + budy[j] + (i - af[j]) * BLOCK_S;

               local_a_p = (double*) &a[start_p];
               local_colidx_p = (int*) &colidx[start_p];

               //partial sum
               for (k = 0; ( k < (rowstr[j+1] -start_p) && k < (boundary-start_p) ); k++) {
                  sum = sum + *(local_a_p+k)*z[*(local_colidx_p+k)];
               }
               //r[j] = sum;
               local_r[j] = sum; 
            }// if (MYTHREAD == i % THREADS)
        } // for (i =af[j]; i<= af[j] + cross[j]; i++)
    }

    if (THREADS != 1)
      reduction_TwoDarray(r, af, cross);

    if( statistics() ){
      timer_stop( 10 );
    }

/*--------------------------------------------------------------------
c  At this point, r contains A.z
c-------------------------------------------------------------------*/
    if( statistics() ){
      timer_start( 11 );
    }

    sum = 0.0;
    upc_forall (j = 1; j <= lastcol-firstcol+1; j++; LOOP_C(af, j)) {
      //d = x[j] - r[j];
      d = x[j] - local_r[j];
      sum = sum + d*d;
    }

    /*we need to synchronize the sum*/
    reduction_share(&sum);

    if( statistics() ){
       timer_stop( 11 );
    }

    if (debugging() )
      printf("finished sum %d : %e \n", MYTHREAD, sum); 

    if (MYTHREAD == 0)
    {
      (*rnorm) = sqrt(sum);
    } /* end single */

     
   /*copyout the vector z and x*/
    if( statistics() ){
       timer_start( 12 );
    }

   upc_forall (j = 1; j <= lastcol-firstcol+1; j++; LOOP_C(af, j)) {
      sx[j] = x[j];
      sz[j] = z[j];
   } 



   //need to synchronize
   upc_barrier;

   if( statistics() ){
      timer_stop( 12 );
    }

   if( debugging()  ){
      printf("return:  %e\n", *rnorm);      
   }

    
}

/*---------------------------------------------------------------------
c       generate the test problem for benchmark 6
c       makea generates a sparse matrix with a
c       prescribed sparsity distribution
c
c       parameter    type        usage
c
c       input
c
c       n            i           number of cols/rows of matrix
c       nz           i           nonzeros as declared array size
c       rcond        r*8         condition number
c       shift        r*8         main diagonal shift
c
c       output
c
c       a            r*8         array for nonzeros
c       colidx       i           col indices
c       rowstr       i           row pointers
c
c       workspace
c
c       iv, arow, acol i
c       v, aelt        r*8
c---------------------------------------------------------------------*/
static void makea(
    int n,
    int nz,
    double a[],         /* a[1:nz] */
    int colidx[],       /* colidx[1:nz] */
    int rowstr[],       /* rowstr[1:n+1] */
    int nonzer,
    int firstrow,
    int lastrow,
    int firstcol,
    int lastcol,
    double rcond,
    int arow[],         /* arow[1:nz] */
    int acol[],         /* acol[1:nz] */
    double aelt[],      /* aelt[1:nz] */
    double v[],         /* v[1:n+1] */
    int iv[],           /* iv[1:2*n+1] */
    double shift )
{
    int i, nnza, iouter, ivelt, ivelt1, irow, nzv;

/*--------------------------------------------------------------------
c      nonzer is approximately  (int(sqrt(nnza /n)));
c-------------------------------------------------------------------*/

    double size, ratio, scale;
    int jcol;

    size = 1.0;
    ratio = pow(rcond, (1.0 / (double)n));
    nnza = 0;

/*---------------------------------------------------------------------
c  Initialize colidx(n+1 .. 2n) to zero.
c  Used by sprnvc to mark nonzero positions
c---------------------------------------------------------------------*/
    /*#pragma omp parallel for */
    for (i = 1; i <= n; i++) {
        colidx[n+i] = 0;
        work2[i]= 0;
    }
    for (iouter = 1; iouter <= n; iouter++) {
        nzv = nonzer;
        sprnvc(n, nzv, v, iv, work1, work2);
     vecset(n, v, iv, &nzv, iouter, 0.5);
        for (ivelt = 1; ivelt <= nzv; ivelt++) {
            jcol = iv[ivelt];
            if (jcol >= firstcol && jcol <= lastcol) {
                scale = size * v[ivelt];
                for (ivelt1 = 1; ivelt1 <= nzv; ivelt1++) {
                    irow = iv[ivelt1];
                    if (irow >= firstrow && irow <= lastrow) {
                        nnza = nnza + 1;
                        if (nnza > nz) {
                            printf("Space for matrix elements exceeded in"
                                   " makea\n");
                            printf("nnza, nzmax = %d, %d\n", nnza, nz);
                            printf("iouter = %d\n", iouter);
                            exit(1);
                        }
                        acol[nnza] = jcol;
                        arow[nnza] = irow;
                        aelt[nnza] = v[ivelt1] * scale;
                    }
                }
            }
        }
        size = size * ratio;
    }

/*---------------------------------------------------------------------
c       ... add the identity * rcond to the generated matrix to bound
c           the smallest eigenvalue from below by rcond
c---------------------------------------------------------------------*/
    for (i = firstrow; i <= lastrow; i++) {
        if (i >= firstcol && i <= lastcol) {
            iouter = n + i;
            nnza = nnza + 1;
            if (nnza > nz) {
                printf("Space for matrix elements exceeded in makea\n");
                printf("nnza, nzmax = %d, %d\n", nnza, nz);
                printf("iouter = %d\n", iouter);
                exit(1);
            }
            acol[nnza] = i;
            arow[nnza] = i;
            aelt[nnza] = rcond - shift;
        }
    }

/*---------------------------------------------------------------------
c       ... make the sparse matrix from list of elements with duplicates
c           (v and iv are used as  workspace)
c---------------------------------------------------------------------*/
    sparse(a, colidx, rowstr, n, arow, acol, aelt,
           firstrow, lastrow, v, &(iv[0]), &(iv[n]), nnza);
}

/*---------------------------------------------------
c       generate a sparse matrix from a list of
c       [col, row, element] tri
c---------------------------------------------------*/
static void sparse(
    double a[],         /* a[1:*] */
    int colidx[],       /* colidx[1:*] */
    int rowstr[],       /* rowstr[1:*] */
    int n,
    int arow[],         /* arow[1:*] */
    int acol[],         /* acol[1:*] */
    double aelt[],      /* aelt[1:*] */
    int firstrow,
    int lastrow,
    double x[],         /* x[1:n] */
    boolean mark[],     /* mark[1:n] */
    int nzloc[],        /* nzloc[1:n] */
    int nnza)
/*---------------------------------------------------------------------
c       rows range from firstrow to lastrow
c       the rowstr pointers are defined for nrows = lastrow-firstrow+1 values
c---------------------------------------------------------------------*/
{
    int nrows;
    int i, j, jajp1, nza, k, nzrow;
    double xi;

/*--------------------------------------------------------------------
c    how many rows of result
c-------------------------------------------------------------------*/
    nrows = lastrow - firstrow + 1;

/*--------------------------------------------------------------------
c     ...count the number of triples in each row
c-------------------------------------------------------------------*/
    /*#pragma omp parallel for */    
    for (j = 1; j <= n; j++) {
        rowstr[j] = 0;
        mark[j] = FALSE;
    }
    rowstr[n+1] = 0;
    
    for (nza = 1; nza <= nnza; nza++) {
        j = (arow[nza] - firstrow + 1) + 1;
        rowstr[j] = rowstr[j] + 1;
    }

    rowstr[1] = 1;
    for (j = 2; j <= nrows+1; j++) {
        rowstr[j] = rowstr[j] + rowstr[j-1];
    }

/*---------------------------------------------------------------------
c     ... rowstr(j) now is the location of the first nonzero
c           of row j of a
c---------------------------------------------------------------------*/
    
/*--------------------------------------------------------------------
c     ... do a bucket sort of the triples on the row index
c-------------------------------------------------------------------*/
    for (nza = 1; nza <= nnza; nza++) {
        j = arow[nza] - firstrow + 1;
        k = rowstr[j];
        a[k] = aelt[nza];
        colidx[k] = acol[nza];
        rowstr[j] = rowstr[j] + 1;
    }

/*--------------------------------------------------------------------
c       ... rowstr(j) now points to the first element of row j+1
c-------------------------------------------------------------------*/
    for (j = nrows; j >= 1; j--) {
        rowstr[j+1] = rowstr[j];
    }
    rowstr[1] = 1;

/*--------------------------------------------------------------------
c       ... generate the actual output rows by adding elements
c-------------------------------------------------------------------*/
    nza = 0;
    //#pragma omp parallel for    
    for (i = 1; i <= n; i++) {
        x[i] = 0.0;
        mark[i] = FALSE;
    }

    jajp1 = rowstr[1];
    for (j = 1; j <= nrows; j++) {
        nzrow = 0;
/*--------------------------------------------------------------------
c          ...loop over the jth row of a
c-------------------------------------------------------------------*/
        for (k = jajp1; k < rowstr[j+1]; k++) {
            i = colidx[k];
            x[i] = x[i] + a[k];
            if ( mark[i] == FALSE && x[i] != 0.0) {
                mark[i] = TRUE;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i;
            }
        }

/*--------------------------------------------------------------------
c          ... extract the nonzeros of this row
c-------------------------------------------------------------------*/
        for (k = 1; k <= nzrow; k++) {
            i = nzloc[k];
            mark[i] = FALSE;
            xi = x[i];
            x[i] = 0.0;
            if (xi != 0.0) {
                nza = nza + 1;
                a[nza] = xi;
                colidx[nza] = i;
            }
        }
        jajp1 = rowstr[j+1];
        rowstr[j+1] = nza + rowstr[1];
    }
}

/*---------------------------------------------------------------------
c       generate a sparse n-vector (v, iv)
c       having nzv nonzeros
c
c       mark(i) is set to 1 if position i is nonzero.
c       mark is all zero on entry and is reset to all zero before exit
c       this corrects a performance bug found by John G. Lewis, caused by
c       reinitialization of mark on every one of the n calls to sprnvc
---------------------------------------------------------------------*/
static void sprnvc(
    int n,
    int nz,
    double v[],         /* v[1:*] */
    int iv[],           /* iv[1:*] */
    int nzloc[],        /* nzloc[1:n] */
    int mark[] )        /* mark[1:n] */
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

/*--------------------------------------------------------------------
c    nn1 is the smallest power of two not less than n
c-------------------------------------------------------------------*/

    while (nzv < nz) {
        vecelt = randlc(&tran, amult);

/*--------------------------------------------------------------------
c   generate an integer between 1 and n in a portable manner
c-------------------------------------------------------------------*/
        vecloc = randlc(&tran, amult);
        i = icnvrt(vecloc, nn1) + 1;
        if (i > n) continue;

/*--------------------------------------------------------------------
c  was this integer generated already?
c-------------------------------------------------------------------*/
        if (mark[i] == 0) {
            mark[i] = 1;
            nzrow = nzrow + 1;
            nzloc[nzrow] = i;
            nzv = nzv + 1;
            v[nzv] = vecelt;
            iv[nzv] = i;
        }
    }
  for (ii = 1; ii <= nzrow; ii++) {
        i = nzloc[ii];
        mark[i] = 0;
    }
}

/*---------------------------------------------------------------------
* scale a double precision number x in (0,1) by a power of 2 and chop it
*---------------------------------------------------------------------*/
static int icnvrt(double x, int ipwr2) {
    return ((int)(ipwr2 * x));
}

/*--------------------------------------------------------------------
c       set ith element of sparse vector (v, iv) with
c       nzv nonzeros to val
c-------------------------------------------------------------------*/
static void vecset(
    int n,
    double v[], /* v[1:*] */
    int iv[],   /* iv[1:*] */
    int *nzv,
    int i,
    double val)
{
    int k;
    boolean set;

    set = FALSE;
    for (k = 1; k <= *nzv; k++) {
        if (iv[k] == i) {
            v[k] = val;
            set  = TRUE;
        }
    }
    if (set == FALSE) {
        *nzv = *nzv + 1;
        v[*nzv] = val;
        iv[*nzv] = i;
    }
}

static void reduction_share(double * value_p)
{
  int i;
  double sum = 0;

  //submit the local copy
  //*((double*)&(sharevalary[MYTHREAD])) = *value_p;
  sharevalary[MYTHREAD] = *value_p;

  //synchronization
  upc_barrier;
 
  //sum up only in master thread
  if ( MYTHREAD== 0 ){
    double *ptr = (double*)&sharevalary[0];

    for(i=0; i<THREADS; i++){
      sum = sum + *(ptr+i);
    }
    
    shareval = sum;
  }

  //synchronization
  upc_barrier;

  //copy back to local value
  *(value_p) = shareval;

}

static void reduction_vector(double vec[], int af[])
{
  int j;
  int start_size;
  int stop_size;
  int median_size;
  int size;

  
  upc_forall (j = 1; j <= lastcol-firstcol+1; j++; LOOP_C(af, j) ) {
    if ( af[j-1] != af[j] ) start_size = j;
    if ( af[j+1] != af[j] ){
       stop_size =j;
       if (start_size /BLOCK_S != stop_size /BLOCK_S){
         median_size = (start_size /BLOCK_S +1) * BLOCK_S; 
         size = median_size - start_size;
         upc_memput(&st[start_size], &vec[start_size], size * sizeof( double));
         size = stop_size - median_size+1;
         upc_memput(&st[median_size],  &vec[median_size], 
                 size * sizeof( double));
	}
	else{
	  size = stop_size - start_size+1;
	  upc_memput(&st[start_size], &vec[start_size], size * sizeof( double));
       }
    }
  }
  
  //synchronization
  upc_barrier;     

  //copy back to local value
  floatcopyin(vec, st, NA+2, BLOCK_S);
  
}


static void floatcopyin(double * dest, shared [BLOCK_S] double * sorc, int size, int block_size)
{
  int copy_size = 0;
  int mem_size = 0;
  
  //copy the memory by block into the local copy 
  do{
      copy_size = (block_size < size - mem_size) ? block_size : size - mem_size;
      upc_memget(&dest[mem_size], &sorc[mem_size],  copy_size*sizeof(double)); 
      mem_size += copy_size;
  }while (mem_size <size);

}
 
static void floatcopyin2(double * dest, shared [BLOCK_V] double * sorc, int size, int block_size)
{
  int copy_size = 0;
  int mem_size = 0;
  
  //copy the memory by block into the local copy 
  do{
      copy_size = (block_size < size - mem_size) ? block_size : size - mem_size;
      upc_memget(&dest[mem_size], &sorc[mem_size],  copy_size*sizeof(double)); 
      mem_size += copy_size;
  }while (mem_size <size);

}

static void intcopyin(int * dest, shared  [BLOCK_S] int * sorc, int size, int block_size )
{
  //  int copy_size = 0;
  //int mem_size = 0;
  int i;

  //copy the memory by block into the local copy 
  /*  do{
      copy_size = (block_size < size - mem_size) ? block_size : size - mem_size;
      upc_memget(&dest[mem_size], &sorc[mem_size],  copy_size*sizeof(int)); 
      mem_size += copy_size;
      }while (mem_size <size);  */

  //copy the memory by block into the local copy
  for(i =0; i<size; i++)
    dest[i] =  sorc[i]; 

}

static void intcopyout(shared  [BLOCK_S] int * dest, int * sorc, int size, int block_size)
{
  int copy_size = 0;
  int mem_size = 0;
  
  //copy the memory by block into the local copy 
  do{
      copy_size = (block_size < size - mem_size) ? block_size : size - mem_size;
      upc_memput(&dest[mem_size], &sorc[mem_size],  copy_size*sizeof(*sorc)); 
      mem_size += copy_size;
  }while (mem_size <size); 

}

static void floatcopyout(shared  [BLOCK_S] double * dest, double * sorc, int size, int block_size)
{
  int copy_size = 0;
  int mem_size = 0;
  
  //copy the memory by block into the local copy 
  do{
      copy_size = (block_size < size - mem_size) ? block_size : size - mem_size;
      upc_memput(&dest[mem_size], &sorc[mem_size],  copy_size*sizeof(*sorc)); 
      mem_size += copy_size;
  }while (mem_size <size); 

}


static int  debugging()
{
  return (MYTHREAD == 0 && DEBUGGING);
}

static int  statistics()
{
  return (MYTHREAD == 0 && STATISTICS);
}

static void reduction_TwoDarray(double p[], int af[], int cross[])
{
  int i, j;
  double sum;
  double *local_p;

  if( statistics() ){
     timer_start( 17 );
  }
  //submission of the local data
  local_p = (double*) &sharedTwoDarray[0][MYTHREAD];
  /*for(i=1; i<= NA ; i++){
    if(cross[i] >0)
      *( local_p + i ) = p[i];  //submit data only when multiple threads are involved
      }*/

  upc_barrier; 

  if( statistics() ){
     timer_stop (17 );
  }

 
  if( statistics() ){
     timer_start( 18 );
  }

  upc_forall(i=1; i<=NA; i++; LOOP_C(af, i)){

    // calculating only when multiple threads are involved
    if(cross[i] >0){
      //sum = p[i];
      sum = local_p[i];
      for(j=MYTHREAD+1; j<=MYTHREAD + cross[i]; j++){
        sum += sharedTwoDarray[i][j%THREADS];
      } 
      //p[i] = sum;   //put back to the same vector
      local_p[i] = sum;
    }
 
  }
  
  upc_barrier;
  if( statistics() ){
      timer_stop ( 18);
  }

  if( statistics() ){
      timer_start( 19 );
  }
  //copyout the array
  reduction_vector(local_p, af);

  if( statistics() ){
      timer_stop( 19 );
  }
}

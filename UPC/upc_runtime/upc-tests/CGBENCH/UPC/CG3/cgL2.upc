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
-------------------------------------------------------------------*/
#include "upc_relaxed.h"
#include "upc.h"
#include "npb-C.h"
#include "npbparams.h"
#define NZ      NA*(NONZER+1)*(NONZER+1)/THREADS+NA*(NONZER+2)
#define BLOCK_V  1000
#define BLOCK_S 1000
#define TRUE 1
#define FALSE 0
#define DEBUGGING  FALSE
#define STATISTICS FALSE
#define ceil_div(n,d) (((n)+(d)-1)/(d))

/* global variables */
static int naa;
static int nzz;
static int firstrow;
static int lastrow;
static int firstcol;
static int lastcol;
static int index_i;
static int index_j;
static int log2np_row;

struct chunk_
{
	double d[NA + 2];
};
typedef struct chunk_ chunk;
static shared chunk xfer[THREADS];

int np_row, np_column;
int rowindex[THREADS+2];
int columnindex[THREADS+2];

/* common /main_int_mem/ */
static int colidx[NZ+1];        /* colidx[1:NZ] */
static int rowstr[NA+1+1];
static int iv[2*NA+1+1];        /* iv[1:2*NA+1] */
static int arow[NZ+1];          /* arow[1:NZ] */
static int acol[NZ+1];          /* acol[1:NZ] */

/* common /main_flt_mem/ */
static double v[NA+1+1];        /* v[1:NA+1] */
static double aelt[NZ+1];       /* aelt[1:NZ] */

/*shared a - sparse matrix*/
static double a[NZ+1];   /* a[1:NZ] */
shared [BLOCK_V]static double sx[NA+2+1];        /* x[1:NA+2] */
shared [BLOCK_V]static double sz[NA+2+1];        /* z[1:NA+2] */

/*template for reduction variable*/
shared static double sharevalary[THREADS];
shared static double shareval;
shared [BLOCK_S] static double st[NA+2+1];
shared static double sharedTwoDarray[NA+2+1][THREADS];

/*extra memory working space*/
static int work1[NA+1];
static int work2[NA+1];

/* common /urando/ */
static double amult;
static double tran;


/* function declarations */
static int  debugging();
static int  statistics();
static int  lpow2(int k);
static int  need_transpose( int index_i , int index_j, int * target_p);
static void vector_reduction(int size[], double working[]);
static void reduction_share(double *value_p);
static double  vector_dot_product(double *x, double *y, int size);
static void floatcopyin2(double * dest, shared [BLOCK_V] double * sorc, int size, int block_size);
static void floatcopyout2(shared  [BLOCK_V] double * dest, double * sorc, int size, int block_size);
static void reduction_TwoDarray(double working[]);
static void conj_grad (int colidx[], int rowstr[], double a[], double * zeta_p, 
                       double *rnorm);
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
    int nthreads=THREADS;
    double zeta;
    double rnorm;
    double t, mflops, t1;
    char class;
    boolean verified;
    double zeta_verify_value, epsilon; 
    int NITER1, logt;

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

    //found the np_row and np_column
    i = 1; logt =0;
    while( THREADS > i ){
      i = 2*i;  logt++;
    }
    
    if( THREADS != i){  //not a power of 2
       printf("Sorry, the number of threads much be power of 2!\n");
       return 1;
    }

    if (MYTHREAD == 0 ){
      printf("\n\n NAS Parallel Benchmarks 2.3 UPC version"
           " - CG Benchmark\n");
      printf(" Size: %10d\n", NA);
      printf(" Iterations: %5d\n", NITER);
      timer_clear( 20 );  
      timer_clear( 21 );  
      timer_clear( 22 );

    }

    naa = NA;
    nzz = NZ; 

   if (logt /2 * 2 == logt){  //even #
      np_row = (int)(pow(2, logt/2));
      np_column = (int)(pow(2, logt/2));
    }
    else{
      np_row = (int)(pow(2, (logt+1)/2));
      np_column = (int)(pow(2, (logt-1)/2));
    }
   
    
    log2np_row = (logt+1)/2;
    
    index_i = MYTHREAD / np_row + 1;
    index_j = MYTHREAD % np_row + 1;
    

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

    for( i=1; i<=np_column+1; i++){
	rowindex[i] = (i-1) * NA/np_column + 1;
    }

    for( i=1; i<=np_row+1; i++){
	columnindex[i] = (i-1) * NA/np_row + 1;
    }
    

    firstrow = rowindex[index_i];
    lastrow  = rowindex[index_i+1] - 1;
    firstcol = columnindex[index_j];
    lastcol  = columnindex[index_j+1] - 1;

     makea(naa, nzz, a, colidx, rowstr, NONZER,
          firstrow, lastrow, firstcol, lastcol, 
          RCOND, arow, acol, aelt, v, iv, SHIFT);
     

    if( statistics() ){
       timer_stop( 20 );
    }

/*---------------------------------------------------------------------
c  Note: as a result of the above call to makea:
c        values of j used in indexing rowstr go from 1 --> lastrow-firstrow+1
c        values of colidx which are col indexes go from firstcol --> lastcol
c        So:
c        Shift the col index vals from actual (firstcol --> lastcol ) 
c        to local, i.e., (1 --> lastcol-firstcol+1)
c---------------------------------------------------------------------*/
    for ( i =1; i<= lastrow-firstrow+1; i++){
	for( k =rowstr[i]; k<rowstr[i+1]; k++){
		colidx[k] = colidx[k] - firstcol + 1;
	}
    }


/*--------------------------------------------------------------------
c  set starting vector to (1, 1, .... 1)
c-------------------------------------------------------------------*/

    if (MYTHREAD == 0){
      for (i = 1; i <= NA+1; i++) {
        sx[i] = 1.0;
      }
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
        
  
     conj_grad (colidx, rowstr, a, &zeta,  &rnorm);

/*--------------------------------------------------------------------
c  zeta = shift + 1/(x.z)
c  So, first: (x.z)
c  Also, find norm of z
c  So, first: (z.z)
c-------------------------------------------------------------------*/
   
    } /* end of do one iteration untimed */

  
/*--------------------------------------------------------------------
c  set starting vector to (1, 1, .... 1)
c-------------------------------------------------------------------*/
 
    if (MYTHREAD == 0){
      for (i = 1; i <= NA+1; i++) {
          sx[i] = 1.0;
      }
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
      timer_clear( 23 );
      timer_clear( 24 );
  }
  timer_clear( 25 );

  if(MYTHREAD ==0 )
      timer_start( 1 );

  if ( debugging() )    
    return 0;

  for (it = 1; it <=NITER; it++) {
  /*------------------------------------------------------------------
c  The call to the conjugate gradient routine:
c-------------------------------------------------------------------*/
     if( statistics() ){
       timer_start( 2 );
     }

     conj_grad(colidx, rowstr, a, &zeta, &rnorm);
     upc_barrier; 

     if( statistics() ){
       timer_stop( 2 );
     }

/*--------------------------------------------------------------------
c  zeta = shift + 1/(x.z)
c  So, first: (x.z)
c  Also, find norm of z
c  So, first: (z.z)
c-------------------------------------------------------------------*/

     if (MYTHREAD == 0) /*#pragma omp master*/{
	if( it == 1 ) {
	    printf("   iteration           ||r||                 zeta\n");
	}
        printf("    %5d       %20.14e%20.13e\n", it, rnorm, zeta);
      }
/*--------------------------------------------------------------------
c  Normalize z to obtain x
c-------------------------------------------------------------------*/
      

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
        printf("reduction/transpose q %e \n", t1);
       t1 = timer_read( 5 );
        printf("calculating d %e \n", t1);
      t1 = timer_read( 6 );
        printf("r  z update %e \n", t1);
      t1 = timer_read( 7 );
        printf("rho %e \n", t1);
      t1 = timer_read( 8 );
        printf("update p  %e \n", t1);
      //t1 = timer_read( 9 );
      //  printf("reduction z %e \n", t1);
      t1 = timer_read( 10 );
        printf("a * z %e \n", t1);
      t1 = timer_read( 11 );
        printf("sum %e \n", t1); 
      //t1 = timer_read( 12);
      //  printf("sx szupdate %e \n", t1); 
      t1 = timer_read( 13 );
        printf("sx copy in %e \n", t1); 
      t1 = timer_read( 14 );
        printf("calculate rho0 %e \n", t1 ); 
      t1 = timer_read( 15 );
        printf("calculate norm %e \n", t1); 
      t1 = timer_read( 16 );
        printf("sx copyout %e \n", t1 );
      t1 = timer_read( 17 );
        printf("vector reduction total %e \n", t1 ); 
      t1 = timer_read( 18 );
        printf("vector reduction - loop %e \n", t1); 
      t1 = timer_read( 19 );
        printf("transpose %e \n", t1 );
      t1 = timer_read( 20 );
        printf("make a  %e \n", t1); 
      t1 = timer_read( 22 );
        printf("first conj_grad  %e \n", t1 );
      t1 = timer_read( 23 );
        printf("before we get to matrix * vector  %e \n", t1 );
       t1 = timer_read( 24 );
        printf("after  we get to matrix * vector  %e \n", t1 );
       
     }
 
     c_print_results("CG", class, NA, 0, 0, NITER, nthreads, t, 
                    mflops, "          floating point", 
                    verified, NPBVERSION, COMPILETIME,
                    NPB_CS1, NPB_CS2, NPB_CS3, NPB_CS4, NPB_CS5, NPB_CS6, NPB_CS7);

    }

    fflush(NULL); /* DOB: reduce output scrambling */
    upc_barrier;

    //finally report the time spend on A * p
    t1 = timer_read( 25 );
    printf("the total time spend on matrix * vector is %f %d\n", t1, MYTHREAD);
    

}

/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
static void conj_grad (
    int colidx[],       /* colidx[1:nzz] */
    int rowstr[],       /* rowstr[1:naa+1] */
    double a[],         /* a[1:nzz] */
    double *zeta_p,
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
    int start_p;
    double temp1, temp2;
    chunk  * myxfer = (chunk*)&xfer[MYTHREAD];
    double * myp = myxfer->d;
    int    tsize = columnindex[index_j+1] - columnindex[index_j];
    int    * temps = (int*)malloc( (np_column+2) * sizeof(int));
    int    * temps1 = (int*)malloc( (np_column+2) * sizeof(int));
    double tbuff[3];


    if (debugging() ) {
    	printf("CG starts\n");
    }
    /*#pragma omp single nowait*/
    rho = 0.0;
    
    for (j=1; j<=np_column+1; j++){
       temps[j] = j;
    }  
    for (j=1; j<=np_column+1; j++){
       temps1[j] = 2*j;
    }      
/*--------------------------------------------------------------------
c  Initialize the CG algorithm:
c-------------------------------------------------------------------*/
 
    /*initialization which need to be updated later*/ 
    if( statistics() ){
       timer_start( 13 );
    }

    floatcopyin2(&(x[1]), &(sx[firstcol]), tsize, BLOCK_V);
    for(j=1; j<= tsize; j++){
       q[j] = 0.0;
       z[j] = 0.0;
       r[j] = x[j];
       p[j] = r[j];
       w[j] = 0.0;
    } 

   upc_barrier;
   if (debugging() ) {
    	printf("CG complete initialization\n");
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
    
    rho =  vector_dot_product(x, x, tsize); 

    reduction_share(&rho);

    if( statistics() ){
      timer_stop( 14 );
    }
      

/*--------------------------------------------------------------------
c---->
c  The conj grad iteration loop
c---->
c-------------------------------------------------------------------*/
    if ( DEBUGGING )  cgitmax = 2;

   for (cgit = 1; cgit <=cgitmax; cgit++) {

       rho0 = rho;
       d = 0.0;
       rho = 0.0;
   
       //printf("completed one cycle\n");
      
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
        timer_start( 23 );
       }
        upc_barrier;
        upc_barrier;
        upc_barrier;
        upc_barrier;
        upc_barrier;
      if( statistics() ){
        timer_stop( 23 );
      }

      if( statistics() ){
       timer_start( 3 );
      }
  
      timer_start(25); 

      //use the memory for the reduction
      for(j = 1; j <=lastrow-firstrow+1; j++) {
        sum = 0.0;
        for (k = rowstr[j]; k<rowstr[j+1]; k++) {
            sum = sum + a[k]*p[colidx[k]];
        }
        myp[j-1] = sum;
      }

      timer_stop(25);
 
      //printf("complted the a*q\n");

      if( statistics() ){
        timer_stop( 3 );
      }

      if( statistics() ){
        timer_start( 24 );
       }
        upc_barrier;
      
      if( statistics() ){
        timer_stop( 24 );
      }

      if( statistics() ){
        timer_start( 4 );
      }

      reduction_TwoDarray(q);

      if( statistics() ){
         timer_stop( 4 );
      }
        
/*--------------------------------------------------------------------
c  Obtain p.q
c-------------------------------------------------------------------*/
    if( statistics() ){
      timer_start( 5 );
    }

    d = vector_dot_product(p, q, tsize);
    reduction_share(&d);

    //return;

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

     //return;

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

     for(j = 1; j <= tsize; j++){
        z[j] = z[j] + alpha*p[j];
        r[j] = r[j] - alpha*q[j];
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


     //rho = vector_dot_product(r, r, tsize);
     rho = vector_dot_product(r, r, tsize);
     reduction_share(&rho);

     if( statistics() ){
        timer_stop( 7 );
     }

        
     if ( debugging() ){	
        printf("finished rho %d : %e \n", MYTHREAD, rho); 
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

     for (j = 1; j <= tsize; j++ ) {
       p[j] = r[j] + beta*p[j];
     }


     if( statistics() ){
        timer_stop( 8 );
     }

  } /* end of do cgit=1,cgitmax */

/*---------------------------------------------------------------------
c  Compute residual norm explicitly:  ||r|| = ||x - A.z||
c  First, form A.z
c  The partition submatrix-vector multiply
c---------------------------------------------------------------------*/
       

    /*the last a * Z*/
    if( statistics() ){
       timer_start( 10 );
    }

    for(j = 1; j <=lastrow-firstrow+1; j++) {
        sum = 0.0;
        for (k = rowstr[j]; k<rowstr[j+1]; k++) {
            sum = sum + a[k]*z[colidx[k]];
        }
        myp[j-1]  = sum;     
     }

    if( statistics() ){
      timer_stop( 10 );
    }

/*--------------------------------------------------------------------
c  At this point, r contains A.z
c-------------------------------------------------------------------*/
    if( statistics() ){
      timer_start( 11 );
    }
    
    reduction_TwoDarray(r);
    //vector_reduction(columnindex, r);

    sum = 0.0;
    for(j = 1; j <=tsize ; j++) {
      d = x[j] - r[j];
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
    } 

   /*copyout the vector z and x*/

    if( statistics() ){
       timer_start( 15 );
    }

    myp[0] = vector_dot_product(x, z, tsize); 
    myp[1] = vector_dot_product(z, z, tsize); 
    vector_reduction(temps1, tbuff);
    temp1 = tbuff[1];
    temp2 = tbuff[2];
      
     if( debugging()  ){
      printf("temp1: %e\n", temp1);
      printf("temp2: %e\n", temp2);
     }

     temp2 = 1.0 / sqrt( temp2 );
     *zeta_p = SHIFT + 1.0 / temp1;

     if( statistics() ){
        timer_stop( 15 );
     }

    if( statistics() ){
        timer_start( 16 );
     }

     for (j = 1;  j <=tsize; j++) {
        x[j] = temp2*z[j];
     }

     //copy out x
     if( index_i == 1)
       floatcopyout2(&sx[firstcol], &x[1], tsize, BLOCK_V);
     
     //need to synchronize
     upc_barrier;

     if( statistics() ){
       timer_stop( 16 );
     }

     if( debugging()  ){
       printf("return:  %e\n", *rnorm);   
       printf("zeta:  %e\n", *zeta_p);             
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
   chunk  * myxfer = (chunk*)&xfer[MYTHREAD];
   double * myp = myxfer->d;
   int    * temps = (int*)malloc( (np_column+2) * sizeof(int));
   double tbuff[3];
   int    j;

   for (j=1; j<=np_column+1; j++){
       temps[j] = j;
   }  
   myp[0] = *value_p;
   vector_reduction(temps, tbuff);
   *value_p = tbuff[1];
}

static void floatcopyin2(double * dest, shared [BLOCK_V] double * sorc, int size, int block_size)
{
  int copy_size = 0;
  int mem_size = 0;
  int head = upc_phaseof(sorc);

  copy_size = ( (block_size - head) < (size - mem_size) ) ? block_size - head : size - mem_size;
  //copy the memory by block into the local copy 
  do{
      upc_memget(&dest[mem_size], &sorc[mem_size],  copy_size*sizeof(double)); 
      mem_size += copy_size;
      copy_size = (block_size < size - mem_size) ? block_size : size - mem_size;
  }while (mem_size <size);

}

static void floatcopyout2(shared  [BLOCK_V] double * dest, double * sorc, int size, int block_size)
{
  int copy_size = 0;
  int mem_size = 0;
  int head = upc_phaseof(dest);

  //do the block boundary checking
  copy_size = ( (block_size - head) < (size - mem_size) ) ? block_size -head : size - mem_size;  

  //copy the memory by block into the local copy 
  do{
      upc_memput(&dest[mem_size], &sorc[mem_size],  copy_size*sizeof(*sorc)); 
      mem_size += copy_size;  
      copy_size = (block_size < size - mem_size) ? block_size : size - mem_size;
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


static double  vector_dot_product(double *x, double *y, int size)
{
  int i;
  double sum=0;

  for(i=1; i<=size; i++){
    sum += x[i] * y[i];
  }
  
  return sum;
}


static void reduction_TwoDarray(double working[])
{
   int target;
   int tsize, start;

   if( statistics() ){
     timer_start( 17 );
    }

   //first do the vector reduction
   vector_reduction(rowindex, working);

   if( statistics() ){
     timer_stop( 17 );
   }
 
   if( statistics() ){
     timer_start( 19 );
   }
   //do the transpose
   if(  need_transpose( index_i, index_j, &target) )
   {

        tsize = columnindex[index_j + 1] - columnindex[index_j] ;

	if ( index_j /2 *2 != index_j || np_row == np_column ) 
	   start = 0; 
        else
	   start = columnindex[index_j] -  columnindex[index_j - 1] ;

        //printf("the transpose setting %d %d %d %d %d\n ", target, start, tsize, index_i, index_j);
        upc_memget(&working[1], &(xfer[target].d[start]), tsize *sizeof(double));
   }
   
  
   //not necessary a barrier;
   upc_barrier;
   
   if( statistics() ){
     timer_stop( 19 );
   }
}


static void vector_reduction(int size[], double working[])
{
   int target;
   int i, cj;
   int k, tsize= size[index_i+1] - size[index_i] ;
   double * local_p = (double*) &(xfer[MYTHREAD].d[0]);

   upc_barrier;

   //log P reduction  
   if( statistics() ){
     timer_start( 18 );
    }
   for( i=1; i<=log2np_row; i++){
      cj = (index_j + lpow2( log2np_row-i ) ) %  np_row;
      if ( cj == 0) cj = np_row;
      target = (index_i -1) * np_row + cj -1;
    
      upc_memget(&working[0], &(xfer[target].d[0]), tsize *sizeof(double));	
      
      upc_barrier;  
      
      //sumup
      for ( k = 0; k<tsize; k++){
	local_p[k] += working[k];
      }
      upc_barrier;       
   }      
   if( statistics() ){
     timer_stop( 18 );
   }
	
   //shift to 1 index after the reduction
   for( i= 1; i <= tsize; i++){
       working[i] = local_p[i-1];
   }
   upc_barrier; 
 
}


int need_transpose( int index_i , int index_j, int * target_p)
{
   int t_i, t_j;

   if( np_row == np_column){
      t_i = index_j; t_j = index_i;
      *target_p = (t_i - 1) * np_row + (t_j-1);
   }
   else{
      t_i = (index_j+1)/2; 
      if( index_j /2 *2 == index_j) //j is a even #
        t_j = 2*index_i; 
      else
	t_j = 2*index_i -1;
	   
      *target_p = (t_i - 1) * np_row + (t_j-1);
   }
  
   return TRUE;

}

int lpow2(int k)
{
  int p, i;
 
  p = 1;
  for(i=1; i<=k; i++){
    p = p *2;
  }
  
  return p;
}

#include <stdio.h>
#include <string.h>
#include <upc.h>
#include <upc_relaxed.h>

#include "npb-C.h"
#define MAX_TIMERS      2
#include "upc_timers.h"
#include "globals.h"

#define TIMER_BENCH	0
#define	TIMER_INIT	1

/* global variables */
shared double timer[MAX_TIMERS][THREADS];
shared int jg[4][MM][2];
shared double red_best, red_winner;
shared double sh_a[4], sh_c[4];
shared int sh_nit, sh_nx, sh_ny, sh_nz, sh_debug_vec[8], sh_lt, sh_lb;
shared double s, max;
int is1, is2, is3, ie1, ie2, ie3;

upc_lock_t *critical_lock;

void allocate_memory(int n2, int n3);
void setup(int *n1, int *n2, int *n3, int lt);
double power( double a, int n );
void bubble( double ten[M][2], int j1[M][2], int j2[M][2],
        int j3[M][2], int m, int ind );

int nx[MAXLEVEL+1], ny[MAXLEVEL+1], nz[MAXLEVEL+1];

char Class;

int debug_vec[8];

int lt, lb;

int ir[MAXLEVEL];

int m1[MAXLEVEL+1], m2[MAXLEVEL+1], m3[MAXLEVEL+1];
int nbr[4][2][MAXLEVEL+1];
int dead[MAXLEVEL+1], give_ex[4][MAXLEVEL+1], take_ex[4][MAXLEVEL+1];

shared sh_arr_t sh_u[THREADS*(LT_DEFAULT_I)], sh_r[THREADS*(LT_DEFAULT_I)];
shared sh_arr_t sh_v[THREADS];

void zero3( shared sh_arr_t *z, int n1, int n2, int n3);
void zran3( shared sh_arr_t *z, int n1, int n2, int n3, int nx, int ny, int k);
void comm3( shared sh_arr_t *u, int n1, int n2, int n3, int kk);
void norm2u3(shared sh_arr_t *r, int n1, int n2, int n3,
        double *rnm2, double *rnmu, int nx, int ny, int nz);
void resid( shared sh_arr_t *u, shared sh_arr_t *v, shared sh_arr_t *r,
        int n1, int n2, int n3, double a[4], int k );
void rep_nrm( shared sh_arr_t *u, int n1, int n2, int n3,
        const char *title, int kk);
void showall( shared sh_arr_t *z, int n1, int n2, int n3);
void mg3P(shared sh_arr_t *u, shared sh_arr_t *v, shared sh_arr_t *r,
        double a[4], double c[4], int n1, int n2, int n3, int k);
void rprj3( shared sh_arr_t *r, int m1k, int m2k, int m3k,
        shared sh_arr_t *s, int m1j, int m2j, int m3j, int k );
void psinv( shared sh_arr_t *r, shared sh_arr_t *u,
        int n1, int n2, int n3, double c[4], int k);
void interp( shared sh_arr_t *z, int mm1, int mm2, int mm3,
        shared sh_arr_t *u, int n1, int n2, int n3, int k );

#include "file_output.h"
#define FILE_DEBUG FALSE

int main(int argc, char *argv[]){
    /* k is the current level. It is passed down through subroutine args
       and is NOT global. it is the current iteration */
    int it;
    double t, tinit, mflops;
    double a[4], c[4];
    double rnm2;
    double rnmu;

    /* These arrays are in common because they are quite large
       and probably shouldn't be allocated on the stack. They
       are always passed as subroutine args.  */
    double epsilon = 1.0e-8;
    int n1, n2, n3, nit;
    double verify_value;
    boolean verified;
    int i, l;
    int nn;
    FILE *fp;
    double max_timer[MAX_TIMERS];

    // UPC Specific initializations
    critical_lock = upc_all_lock_alloc();
    MEM_OK( critical_lock );

    // Parameters
    timer_clear(TIMER_BENCH);
    timer_clear(TIMER_INIT);
    timer_start(TIMER_INIT);

    if( MYTHREAD == 0 )
    {
        /* Read in and broadcast input data */
        printf("\n\n NAS Parallel Benchmarks 2.4 UPC version"
                " - MG Benchmark - GWU/HPCL\n\n");

        fp = fopen("mg.input", "r");
        if (fp != NULL)
        {
            printf(" Reading from input file mg.input\n");
            fscanf(fp, "%d", &lt);
            while(fgetc(fp) != '\n');
            fscanf(fp, "%d%d%d", &nx[lt], &ny[lt], &nz[lt]);
            while(fgetc(fp) != '\n');
            fscanf(fp, "%d", &nit);
            while(fgetc(fp) != '\n');
            for (i = 0; i <= 7; i++)
            {
                fscanf(fp, "%d", &debug_vec[i]);
            }
            fclose(fp);
        }
        else
        {
            printf(" No input file. Using compiled defaults\n");

            lt = LT_DEFAULT;
            nit = NIT_DEFAULT;
            nx[lt] = NX_DEFAULT;
            ny[lt] = NY_DEFAULT;
            nz[lt] = NZ_DEFAULT;

            for (i = 0; i <= 7; i++)
                debug_vec[i] = DEBUG_DEFAULT;
        }

        sh_nx=nx[lt];    sh_ny=ny[lt];    sh_nz=nz[lt];
        sh_lt=lt; sh_nit=nit;

        for (i = 0; i <= 7; i++)
            sh_debug_vec[i]=debug_vec[i];

        if ( (nx[lt] != ny[lt]) || (nx[lt] != nz[lt]) )
            Class = 'U';
        else if( nx[lt] == 32 && nit == 4 )
            Class = 'S';
        else if( nx[lt] == 64 && nit == 40 )
            Class = 'W';
        else if( nx[lt] == 256 && nit == 4 )
            Class = 'A';
        else if( nx[lt] == 256 && nit == 20 )
            Class = 'B';
        else if( nx[lt] == 512 && nit == 20 )
            Class = 'C';
        else if( nx[lt] == 1024 && nit == 50 )
            Class = 'D';
        else
            Class = 'U';

        /* Use these for debug info:
           debug_vec(0) = 1 !=> report all norms
           debug_vec(1) = 1 !=> some setup information
           debug_vec(1) = 2 !=> more setup information
           debug_vec(2) = k => at level k or below, show result of resid
           debug_vec(3) = k => at level k or below, show result of psinv
           debug_vec(4) = k => at level k or below, show result of rprj
           debug_vec(5) = k => at level k or below, show result of interp
           debug_vec(6) = 1 => (unused)
           debug_vec(7) = 1 => (unused) */

        sh_a[0] = -8.0/3.0;
        sh_a[1] =  0.0;
        sh_a[2] =  1.0/6.0;
        sh_a[3] =  1.0/12.0;

        if (Class == 'A' || Class == 'S' || Class =='W')
        {
            /* Coefficients for the S(a) smoother */
            sh_c[0] =  -3.0/8.0;
            sh_c[1] =  1.0/32.0;
            sh_c[2] =  -1.0/64.0;
            sh_c[3] =   0.0;
        }
        else
        {
            /* Coefficients for the S(b) smoother */
            sh_c[0] =  -3.0/17.0;
            sh_c[1] =  1.0/33.0;
            sh_c[2] =  -1.0/61.0;
            sh_c[3] =   0.0;
        }

        sh_lb = 1;
    }
    upc_barrier 1;

    lt=sh_lt;
    nit=sh_nit;
    lb=sh_lb;
    nx[lt]=sh_nx;ny[lt]=sh_ny;nz[lt]=sh_nz;

    for (i = 0; i <= 7; i++)
        debug_vec[i]=sh_debug_vec[i];

    a[0]=sh_a[0]; a[1]=sh_a[1]; a[2]=sh_a[2]; a[3]=sh_a[3];
    c[0]=sh_c[0]; c[1]=sh_c[1]; c[2]=sh_c[2]; c[3]=sh_c[3];

    setup(&n1,&n2,&n3,lt);

    for( l=lt; l>=1; l-- ){
        sh_u[MYTHREAD+(l*THREADS)].arr = (shared [] double *)
            upc_alloc((m3[l]*m2[l]*m1[l]) * sizeof(double));
        MEM_OK( sh_u[MYTHREAD+(l*THREADS)].arr );
        sh_r[MYTHREAD+(l*THREADS)].arr = (shared [] double *)
            upc_alloc((m3[l]*m2[l]*m1[l]) * sizeof(double));
        MEM_OK( sh_r[MYTHREAD+(l*THREADS)].arr );
    }

    sh_v[MYTHREAD].arr = (shared [] double *)
        upc_alloc((m3[lt]*m2[lt]*m1[lt]) * sizeof(double));
    MEM_OK( sh_v[MYTHREAD].arr );

    allocate_memory(n2, n3);

    zero3( &sh_u[lt*THREADS], n1, n2, n3);
    zran3( sh_v, n1, n2, n3, nx[lt], ny[lt], lt);

    norm2u3( sh_v, n1, n2, n3,
            &rnm2, &rnmu, nx[lt], ny[lt], nz[lt]);

    if (MYTHREAD == 0)
    {
        printf(" Size: %3dx%3dx%3d (class %1c)\n",
                nx[lt], ny[lt], nz[lt], Class);
        printf(" Iterations: %3d\n", nit);
    }

    resid( &sh_u[lt*THREADS], sh_v, &sh_r[lt*THREADS], n1, n2, n3, a, lt);
    norm2u3( &sh_r[lt*THREADS], n1, n2, n3,
            &rnm2, &rnmu, nx[lt], ny[lt], nz[lt]);

    /* One iteration for startup */
    mg3P( sh_u, sh_v, sh_r, a, c, n1, n2, n3, lt);

    resid( &sh_u[lt*THREADS], sh_v, &sh_r[lt*THREADS], n1, n2, n3, a, lt);

    setup(&n1,&n2,&n3,lt);

    zero3( &sh_u[lt*THREADS], n1, n2, n3 );

    zran3( sh_v, n1, n2, n3, nx[lt], ny[lt], lt );

    upc_barrier 17;

    timer_stop(TIMER_INIT);
    timer_start(TIMER_BENCH);

    resid( &sh_u[lt*THREADS], sh_v, &sh_r[lt*THREADS], n1, n2, n3, a, lt);
    norm2u3( &sh_r[lt*THREADS], n1, n2, n3,
            &rnm2, &rnmu, nx[lt], ny[lt], nz[lt] );

    for ( it = 1; it <= nit; it++){
        if( MYTHREAD == 0 )
            printf(" %4d\n", it );
        mg3P( sh_u, sh_v, sh_r, a, c, n1, n2, n3, lt );
        resid( &sh_u[lt*THREADS], sh_v,
                &sh_r[lt*THREADS], n1, n2, n3, a, lt );
    }

    norm2u3( &sh_r[lt*THREADS], n1, n2, n3,
            &rnm2, &rnmu, nx[lt], ny[lt], nz[lt] );

    timer_stop(TIMER_BENCH);

    /* prepare for timers_reduce() */
    for( i=0; i<MAX_TIMERS; i++ )
        timer[i][MYTHREAD] = timer_read(i);

    upc_barrier 18;

#if( FILE_DEBUG == TRUE )
    file_output();
#endif

    if (MYTHREAD == 0)
    {
        timers_reduce( max_timer );

        t = max_timer[TIMER_BENCH];
        tinit = max_timer[TIMER_INIT];

        verified = FALSE;
        verify_value = 0.0;

        printf(" Initialization time: %15.3f seconds\n", tinit);
        printf(" Benchmark completed\n");

        if (Class != 'U')
        {
            if (Class == 'S')
                verify_value = 0.530770700573e-04;
            else if (Class == 'W')
                verify_value = 0.250391406439e-17;  /* 40 iterations*/
                /*    0.183103168997d-044 iterations*/
            else if (Class == 'A')
                verify_value = 0.2433365309e-5;
            else if (Class == 'B')
                verify_value = 0.180056440132e-5;
            else if (Class == 'C')
                verify_value = 0.570674826298e-06;
            else if (Class == 'D')
                verify_value = 0.158327506042e-9;

            if ( fabs( rnm2 - verify_value ) <= epsilon ){
                verified = TRUE;
                printf(" VERIFICATION SUCCESSFUL\n");
                printf(" L2 Norm is %20.12e\n", rnm2);
                printf(" Error is   %20.12e\n", rnm2 - verify_value);
            }else{
                verified = FALSE;
                printf(" VERIFICATION FAILED\n");
                printf(" L2 Norm is             %20.12e\n", rnm2);
                printf(" The correct L2 Norm is %20.12e\n", verify_value);
            }
        }else{
            verified = FALSE;
            printf(" Problem size unknown\n");
            printf(" NO VERIFICATION PERFORMED\n");
        }

        if ( t != 0.0 ){
            nn = nx[lt]*ny[lt]*nz[lt];
            mflops = 58.*nit*nn*1.0e-6 / t;
        }
        else
            mflops = 0.0;

        c_print_results("MG", Class, nx[lt], ny[lt], nz[lt],
                nit, THREADS, t, mflops, "          floating point",
                verified, NPBVERSION, COMPILETIME,
                NPB_CS1, NPB_CS2, NPB_CS3, NPB_CS4, NPB_CS5, NPB_CS6, NPB_CS7);
    }
    return 0;
}

void setup(int *n1, int *n2, int *n3, int lt){
    int k;
    int dx, dy, log_p, i, j;
    int ax, next[4],mi[4][MAXLEVEL+1],mip[4][MAXLEVEL+1];
    int ng[4][MAXLEVEL+1];
    int idi[4], pi[4], idin[4][2];
    int dir;

    ng[1][lt] = nx[lt];
    ng[2][lt] = ny[lt];
    ng[3][lt] = nz[lt];

    for(ax=1; ax<4; ax++)
    {
        next[ax] = 1;

        for(k=lt-1; k>0; k--)
            ng[ax][k] = ng[ax][k+1]/2;
    }

    for(k=lt-1; k>0; k--)
    {
        nx[k] = ng[1][k];
        ny[k] = ng[2][k];
        nz[k] = ng[3][k];
    }

    log_p  = log(((float)THREADS)+0.0001)/log(2.0);

    dx     = log_p/3;
    pi[1]  = power(2,dx);
    idi[1] = MYTHREAD % pi[1];

    dy     = (log_p-dx)/2;
    pi[2]  = power(2,dy);
    idi[2] = (MYTHREAD/pi[1]) % pi[2];

    pi[3]  = THREADS/(pi[1]*pi[2]);
    idi[3] = MYTHREAD / (pi[1]*pi[2]);

    for(k=lt; k>0; k--)
    {
        dead[k] = 0;

        for(ax=1; ax<4; ax++)
        {
            take_ex[ax][k] = 0;
            give_ex[ax][k] = 0;

            mi[ax][k] = 2 +
                ((idi[ax]+1)*ng[ax][k])/pi[ax] -
                ((idi[ax]+0)*ng[ax][k])/pi[ax];

            mip[ax][k] = 2 +
                ((next[ax]+idi[ax]+1)*ng[ax][k])/pi[ax] -
                ((next[ax]+idi[ax]+0)*ng[ax][k])/pi[ax];

            if (mip[ax][k]==2 || mi[ax][k]==2)
                next[ax] = 2*next[ax];

            if( k+1 < lt )
            {
                if ((mip[ax][k]==2) && (mi[ax][k]==3))
                {
                    give_ex[ax][k+1] = 1;
                }

                if ((mip[ax][k]==3)&&(mi[ax][k]==2))
                {
                    take_ex[ax][k+1] = 1;
                }
            }
        }

        if( mi[1][k]==2 || mi[2][k]==2 || mi[3][k]==2 )
            dead[k] = 1;

        m1[k] = mi[1][k];
        m2[k] = mi[2][k];
        m3[k] = mi[3][k];

        for (ax=1; ax<4; ax++)
        {
            idin[ax][DIRm1] = (idi[ax]+next[ax]+pi[ax]) % pi[ax];
            idin[ax][DIRp1] = (idi[ax]-next[ax]+pi[ax]) % pi[ax];
        }

        for (dir=0; dir<2; dir++)
        {
            nbr[1][dir][k] = idin[1][dir] + pi[1] * (idi[2] + pi[2] * idi[3]);
            nbr[2][dir][k] = idi[1] + pi[1] * (idin[2][dir] + pi[2] * idi[3]);
            nbr[3][dir][k] = idi[1] + pi[1] * (idi[2] + pi[2] * idin[3][dir]);
        }
    }

    k=lt;

    is1 = 1 + ng[1][k] - ((pi[1]  -idi[1])*ng[1][lt])/pi[1];
    ie1 = 0 + ng[1][k] - ((pi[1]-1-idi[1])*ng[1][lt])/pi[1];
    *n1 = 3 + ie1 - is1;

    is2 = 1 + ng[2][k] - ((pi[2]  -idi[2])*ng[2][lt])/pi[2];
    ie2 = 0 + ng[2][k] - ((pi[2]-1-idi[2])*ng[2][lt])/pi[2];
    *n2 = 3 + ie2 - is2;

    is3 = 1 + ng[3][k] - ((pi[3]  -idi[3])*ng[3][lt])/pi[3];
    ie3 = 0 + ng[3][k] - ((pi[3]-1-idi[3])*ng[3][lt])/pi[3];
    *n3 = 3 + ie3 - is3;

    ir[lt]=1;

    for(j = lt-1 ; j>0; j--)
        ir[j]=ir[j+1] + m1[j+1]*m2[j+1]*m3[j+1];

    if (debug_vec[1] >=  1 )
    {
        if (MYTHREAD == 0){
            printf(" in setup, \n");
            printf("  P#  lt  nx  ny  nz  n1  n2  n3 is1 is2 is3 ie1 ie2 ie3\n");
        }
        upc_barrier 67;

        printf("%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n",
                MYTHREAD,lt,nx[lt],ny[lt],nz[lt],*n1,*n2,*n3,is1,is2,is3,ie1,ie2,ie3);
    }

    if (debug_vec[1] >=  2 )
    {
        for(i=0; i<THREADS; i++)
        {	
            if( MYTHREAD == i )
            {
                printf("\nprocesssor = %d\n", MYTHREAD);
                for (k=lt; k>0; k--)
                {
                    printf("%didi=%4d%4d%4d", k,idi[1], idi[2], idi[3]);
                    printf("nbr=%4d%4d   %4d%4d   %4d%4d ",
                            nbr[1][DIRm1][k], nbr[1][DIRp1][k],
                            nbr[2][DIRm1][k], nbr[2][DIRp1][k],
                            nbr[3][DIRm1][k], nbr[3][DIRp1][k]);
                    printf("mi=%4d%4d%4d\n", mi[1][k],mi[2][k],mi[3][k]);
                }
                printf("idi(s) = %10d%10d%10d\n", idi[1],idi[2],idi[3]);
                printf("dead(2), dead(1) = %2d%2d\n", dead[2], dead[1]);
                for(ax=1; ax<4; ax++)
                {
                    printf("give_ex[%d][2]= %d", ax, give_ex[ax][2]);
                    printf("  take_ex[%d][2]= %d\n", ax, take_ex[ax][2]);
                }
            }
            upc_barrier 68;
        }
    }
    k = lt;
}

void mg3P(shared sh_arr_t *u, shared sh_arr_t *v, shared sh_arr_t *r,
        double a[4], double c[4], int n1, int n2, int n3, int k){
    /* multigrid V-cycle routine */
    int j;

    /* down cycle. restrict the residual from the find grid to the coarse */
    for (k = lt; k >= lb+1; k--){
        j = k-1;
        rprj3( &r[k*THREADS], m1[k], m2[k], m3[k],
                &r[j*THREADS], m1[j], m2[j], m3[j], k);
    }

    k = lb;
    /* compute an approximate solution on the coarsest grid */
    zero3( &u[k*THREADS], m1[k], m2[k], m3[k]);
    psinv( &r[k*THREADS], &u[k*THREADS], m1[k], m2[k], m3[k], c, k);

    for (k = lb+1; k <= lt-1; k++){
        j = k-1;
        /* prolongate from level k-1  to k */
        zero3( &u[k*THREADS], m1[k], m2[k], m3[k]);
        interp( &u[j*THREADS], m1[j], m2[j], m3[j],
                &u[k*THREADS], m1[k], m2[k], m3[k], k);
        /* compute residual for level k */
        resid( &u[k*THREADS], &r[k*THREADS], &r[k*THREADS],
                m1[k], m2[k], m3[k], a, k);
        /* apply smoother */
        psinv( &r[k*THREADS], &u[k*THREADS], m1[k], m2[k], m3[k], c, k);
    }

    j = lt - 1;
    k = lt;
    interp( &u[j*THREADS], m1[j], m2[j], m3[j],
            &u[lt*THREADS], n1, n2, n3, k);
    resid( &u[lt*THREADS], v, &r[lt*THREADS], n1, n2, n3, a, k);
    psinv( &r[lt*THREADS], &u[lt*THREADS], n1, n2, n3, c, k);
}

double power( double a, int n ){
    /* power raises an integer, disguised as a double
       precision real, to an integer power */
    double aj;
    int nj;
    double rdummy;
    double power;

    power = 1.0;
    nj = n;
    aj = a;

    while (nj != 0){
        if( (nj%2) == 1 )
            rdummy = randlc( &power, aj );
        rdummy = randlc( &aj, aj );
        nj = nj/2;
    }

    return power;
}

void bubble( double ten[M][2], int j1[M][2], int j2[M][2],
        int j3[M][2], int m, int ind ){
    /* bubble        does a bubble sort in direction dir */
    double temp;
    int i, j_temp;

    if ( ind == 1 )
    {
        for (i = 0; i < m-1; i++)
        {
            if ( ten[i][ind] > ten[i+1][ind] )
            {
                temp = ten[i+1][ind];
                ten[i+1][ind] = ten[i][ind];
                ten[i][ind] = temp;

                j_temp = j1[i+1][ind];
                j1[i+1][ind] = j1[i][ind];
                j1[i][ind] = j_temp;

                j_temp = j2[i+1][ind];
                j2[i+1][ind] = j2[i][ind];
                j2[i][ind] = j_temp;

                j_temp = j3[i+1][ind];
                j3[i+1][ind] = j3[i][ind];
                j3[i][ind] = j_temp;
            }
            else
                return;
        }
    }
    else
    {
        for (i = 0; i < m-1; i++)
        {
            if ( ten[i][ind] < ten[i+1][ind] )
            {
                temp = ten[i+1][ind];
                ten[i+1][ind] = ten[i][ind];
                ten[i][ind] = temp;

                j_temp = j1[i+1][ind];
                j1[i+1][ind] = j1[i][ind];
                j1[i][ind] = j_temp;

                j_temp = j2[i+1][ind];
                j2[i+1][ind] = j2[i][ind];
                j2[i][ind] = j_temp;

                j_temp = j3[i+1][ind];
                j3[i+1][ind] = j3[i][ind];
                j3[i][ind] = j_temp;
            }
            else
                return;
        }
    }
}


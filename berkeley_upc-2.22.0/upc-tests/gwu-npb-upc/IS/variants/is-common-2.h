shared send_info send_infos_shd[THREADS][THREADS];

/* Partial verif info */
INT_TYPE test_index_array[TEST_ARRAY_SIZE],
         test_rank_array[TEST_ARRAY_SIZE],

    S_test_index_array[TEST_ARRAY_SIZE] = {48427, 17148, 23627, 62548, 4431},
    S_test_rank_array[TEST_ARRAY_SIZE] = {0, 18, 346, 64917, 65463},

    W_test_index_array[TEST_ARRAY_SIZE] = {357773, 934767, 875723, 898999, 404505},
    W_test_rank_array[TEST_ARRAY_SIZE] = {1249, 11698, 1039987, 1043896, 1048018},

    A_test_index_array[TEST_ARRAY_SIZE] = {2112377, 662041, 5336171, 3642833, 4250760},
    A_test_rank_array[TEST_ARRAY_SIZE] = {104, 17523, 123928, 8288932, 8388264},

    B_test_index_array[TEST_ARRAY_SIZE] = {41869, 812306, 5102857, 18232239, 26860214},
    B_test_rank_array[TEST_ARRAY_SIZE] = {33422937, 10244, 59149, 33135281, 99},

    C_test_index_array[TEST_ARRAY_SIZE] = {44172927, 72999161, 74326391, 129606274, 21736814},
    C_test_rank_array[TEST_ARRAY_SIZE] = {61147, 882988, 266290, 133997595, 133525895};

double randlc_is(double *, double *);
void full_verify(void);

/* FUNCTION RANDLC_IS (X, A)

   This routine returns a uniform pseudorandom double precision number in the
   range (0, 1) by using the linear congruential generator

   x_{k+1} = a x_k  (mod 2^46)

   where 0 < x_k < 2^46 and 0 < a < 2^46.  This scheme generates 2^44 numbers
   before repeating.  The argument A is the same as 'a' in the above formula,
   and X is the same as x_0.  A and X must be odd double precision integers
   in the range (1, 2^46).  The returned value RANDLC_IS is normalized to be
   between 0 and 1, i.e. RANDLC_IS = 2^(-46) * x_1.  X is updated to contain
   the new seed x_1, so that subsequent calls to RANDLC_IS using the same
   arguments will generate a continuous sequence.

   This routine should produce the same results on any computer with at least
   48 mantissa bits in double precision floating point data.  On Cray systems,
   double precision should be disabled.

   David H. Bailey     October 26, 1990

   IMPLICIT DOUBLE PRECISION (A-H, O-Z)
   SAVE KS, R23, R46, T23, T46
   DATA KS/0/

   If this is the first call to RANDLC_IS, compute R23 = 2 ^ -23, R46 = 2 ^ -46,
   T23 = 2 ^ 23, and T46 = 2 ^ 46.  These are computed in loops, rather than
   by merely using the ** operator, in order to insure that the results are
   exact on all systems.  This code assumes that 0.5D0 is represented exactly.  */
double randlc_is(double *X, double *A)
{
    static int KS=0;
    static double R23, R46, T23, T46;
    double T1, T2, T3, T4;
    double A1;
    double A2;
    double X1;
    double X2;
    double Z;
    int i, j;

    if (KS == 0){
        R23 = 1.0;
        R46 = 1.0;
        T23 = 1.0;
        T46 = 1.0;

        for (i=1; i<=23; i++){
            R23 = 0.50 * R23;
            T23 = 2.0 * T23;
        }
        for (i=1; i<=46; i++){
            R46 = 0.50 * R46;
            T46 = 2.0 * T46;
        }
        KS = 1;
    }

    /* Break A into two parts such that A = 2^23 * A1 + A2 and set X = N. */
    T1 = R23 * *A;
    j  = T1;
    A1 = j;
    A2 = *A - T23 * A1;

    /* Break X into two parts such that X = 2^23 * X1 + X2, compute
     Z = A1 * X2 + A2 * X1  (mod 2^23), and then
     X = 2^23 * Z + A2 * X2  (mod 2^46). */
    T1 = R23 * *X;
    j  = T1;
    X1 = j;
    X2 = *X - T23 * X1;
    T1 = A1 * X2 + A2 * X1;

    j  = R23 * T1;
    T2 = j;
    Z = T1 - T23 * T2;
    T3 = T23 * Z + A2 * X2;
    j  = R46 * T3;
    T4 = j;
    *X = T3 - T46 * T4;

    return(R46 * *X);
}

/* Create a random number sequence of total length nn residing
 * on np number of processors.  Each processor will therefore have a
 * subsequence of length nn/np.  This routine returns that random
 * number which is the first random number for the subsequence belonging
 * to processor rank kn, and which is used as seed for proc kn ran # gen. */
double find_my_seed(long kn,    /* my processor rank, 0<=kn<=num procs */
        long np,                /* np = num procs                      */
        long nn,                /* total num of ran numbers, all procs */
        double s,               /* Ran num seed, for ex.: 314159265.00 */
        double a){              /* Ran num gen mult, try 1220703125.00 */
    long i;
    double t1, t2, t3, an;
    long mq, nq, kk, ik;

    nq = nn / np;

    for( mq=0; nq>1; mq++,nq/=2 )
        ;

    t1 = a;

    for( i=1; i<=mq; i++ )
        t2 = randlc_is( &t1, &t1 );

    an = t1;

    kk = kn;
    t1 = s;
    t2 = an;

    for( i=1; i<=100; i++ ){
        ik = kk / 2;
        if( 2 * ik !=  kk )
            t3 = randlc_is( &t1, &t2 );
        if( ik == 0 )
            break;
        t3 = randlc_is( &t2, &t2 );
        kk = ik;
    }

    return t1;
}

void create_seq(double seed, double a){
    double x;
    int i, k;

    k = MAX_KEY/4;

    for (i=0; i<NUM_KEYS; i++){
        x = randlc_is(&seed, &a);
        x += randlc_is(&seed, &a);
        x += randlc_is(&seed, &a);
        x += randlc_is(&seed, &a);

        key_array[i] = k*x;
    }
}


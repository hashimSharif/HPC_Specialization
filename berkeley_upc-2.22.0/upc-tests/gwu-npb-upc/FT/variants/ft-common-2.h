int main(int argc, char **argv){
    /* u0, u1, u2 are the main arrays in the problem.
       Depending on the decomposition, these arrays will have different
       dimensions. To accomodate all possibilities, we allocate them as
       one-dimensional arrays and pass them to subroutines for different
       views
       - u0 contains the initial (transformed) initial condition
       - u1 and u2 are working arrays
       - indexmap maps i,j,k of u0 to the correct i^2+j^2+k^2 for the
       time evolution operator. */

    /* Large arrays are in common so that they are allocated on the
       heap rather than the stack. This common block is not
       referenced directly anywhere else. Padding is to avoid accidental
       cache problems, since all array sizes are powers of two. */
    int iter;
    double total_time, mflops;
    boolean verified;
    char class;
    int i;

    allocate_memory();

    /* Run the entire problem once to make sure all data is touched.
       This reduces variable startup costs, which is important for such a
       short benchmark. The other NPB 2 implementations are similar. */
    for (i = 0; i < T_MAX; i++)
        timer_clear(i);

    setup();

    /* All the processors compute the indexmap (we need a private copy) */
    compute_indexmap(dims[2]);
    compute_initial_conditions(sh_u1, dims[0]);
    fft_init(dims[0][0]);
    fft(1, sh_u1, sh_u0);

    /* Start over from the beginning. Note that all operations must
       be timed, in contrast to other benchmarks. */
    for (i = 0; i < T_MAX; i++)
        timer_clear(i);

    upc_barrier;

    timer_start(T_TOTAL);
    TIMER_START(T_SETUP);

    compute_indexmap(dims[2]);
    compute_initial_conditions(sh_u1, dims[0]);
    fft_init(dims[0][0]);

    upc_barrier;
    TIMER_STOP(T_SETUP);

    TIMER_START(T_FFT);
    fft(1, sh_u1, sh_u0);
    TIMER_STOP(T_FFT);

    for (iter = 1; iter <= NITER_DEFAULT; iter++){
        TIMER_START(T_EVOLVE);
        evolve(sh_u0, sh_u1, dims[0]);
        TIMER_STOP(T_EVOLVE);

        TIMER_START(T_FFT);
        fft(-1, sh_u1, sh_u2);
        TIMER_STOP(T_FFT);

        upc_barrier;
        TIMER_START(T_CHECKSUM);
        checksum(iter, sh_u2, dims[0]);
        TIMER_STOP(T_CHECKSUM);
    }

    if (MYTHREAD == 0)
        verify(NX, NY, NZ, NITER_DEFAULT, &verified, &class);

    timer_stop(T_TOTAL);
    total_time = timer_read(T_TOTAL);

    if (MYTHREAD == 0){
        if (total_time != 0.0)
            mflops = 1.0e-6 * NTOTAL_F * (14.8157 + 7.19641 * log (NTOTAL_F)
                 + (5.23518 + 7.21113 * log (NTOTAL_F)) * NITER_DEFAULT) / total_time;
        else
            mflops = 0.0;

        c_print_results("FT", class, NX, NY, NZ, NITER_DEFAULT, THREADS,
                total_time, mflops, "          floating point", verified,
                NPBVERSION, COMPILETIME,
                NPB_CS1, NPB_CS2, NPB_CS3, NPB_CS4, NPB_CS5, NPB_CS6, NPB_CS7);
    }

    print_timers();

    return 0;
}

void setup(){
    int i, np1 = 0;

    if( MYTHREAD == 0 )
        printf("\n\n NAS Parallel Benchmarks 2.4 UPC version"
                " - FT Benchmark - GWU/HPCL\n\n");

    /* Determine layout type */
    if (THREADS == 1){
        np1 = 1;
        np2 = 1;
        layout_type = 0;
    }else if (THREADS < NZ){
        np1 = 1;
        np2 = THREADS;
        layout_type = 1;
    }else{
        np1 = NZ;
        np2 = NZ / THREADS;
        layout_type = 2;
        printf(" ft.c: setup(): layout_type == 2: IS NOT SUPPORTED !!!\n");
        printf("                Must have NZ > THREADS\n");
        exit( 1 );
    }

    switch (layout_type){
        case 0:
            for (i = 0; i < 3; i++){
                dims[i][0] = NX;
                dims[i][1] = NY;
                dims[i][2] = NZ;
            }
            break;
        case 1:
            dims[0][0] = NX;
            dims[0][1] = NY;
            dims[0][2] = NZ;

            dims[1][0] = NX;
            dims[1][1] = NY;
            dims[1][2] = NZ;

            dims[2][0] = NZ;
            dims[2][1] = NX;
            dims[2][2] = NY;
            break;
    }

    int me2 = MYTHREAD % np2;

    upc_barrier;                  /* MPI_Comm_split */

    for (i = 0; i < 3; i++){
        dims[i][1] = dims[i][1] / np1;
        dims[i][2] = dims[i][2] / np2;
    }

    switch (layout_type){
        case 0:
            for (i = 0; i < 3; i++){
                xstart[i] = 1;
                xend[i] = NX;
                ystart[i] = 1;
                yend[i] = NY;
                zstart[i] = 1;
                zend[i] = NZ;
            }
            break;
        case 1:
            xstart[0] = 1;
            xend[0] = NX;
            ystart[0] = 1;
            yend[0] = NY;
            zstart[0] = 1 + me2 * NZ / np2;
            zend[0] = (me2 + 1) * NZ / np2;

            xstart[1] = 1;
            xend[1] = NX;
            ystart[1] = 1;
            yend[1] = NY;
            zstart[1] = 1 + me2 * NZ / np2;
            zend[1] = (me2 + 1) * NZ / np2;

            xstart[2] = 1;
            xend[2] = NX;
            ystart[2] = 1 + me2 * NY / np2;
            yend[2] = (me2 + 1) * NY / np2;
            zstart[2] = 1;
            zend[2] = NZ;
            break;
    };

    /* Set up info for blocking of ffts and transposes.  This improves
       performance on cache-based systems. Blocking involves
       working on a chunk of the problem at a time, taking chunks
       along the first, second, or third dimension.

       - In cffts1 blocking is on 2nd dimension (with fft on 1st dim)
       - In cffts2/3 blocking is on 1st dimension (with fft on 2nd and 3rd dims)

       Since 1st dim is always in processor, we'll assume it's long enough
       (default blocking factor is 16 so min size for 1st dim is 16)
       The only case we have to worry about is cffts1 in a 2d decomposition.
       so the blocking factor should not be larger than the 2nd dimension. */

    fftblock = FFTBLOCK_DEFAULT;
    fftblockpad = FFTBLOCKPAD_DEFAULT;

    if (fftblock != FFTBLOCK_DEFAULT)
        fftblockpad = fftblock + 3;

    if( MYTHREAD == 0 ){
        printf(" Size                : %4dx%4dx%4d\n", NX, NY, NZ);
        printf(" Iterations          :     %7d\n", NITER_DEFAULT);
    }

    /* Initialize the lock */
    sum_write = upc_all_lock_alloc();
    assert( sum_write != NULL );

    /* not really necessary */
    upc_barrier;
}

void compute_indexmap(int d[3]){
    /* compute function from local (i,j,k) to ibar^2+jbar^2+kbar^2
       for time evolution exponent. */
    int i, j, k, ii, ii2, jj, ij2, kk;
    double ap;

    /* basically we want to convert the fortran indices
       1 2 3 4 5 6 7 8
       to
       0 1 2 3 -4 -3 -2 -1
       The following magic formula does the trick:
       mod(i-1+n/2, n) - n/2 */
    ap = -4.0 * ALPHA * PI * PI;

    switch (layout_type){
        case 0:
            for (i = 0; i < dims[2][0]; i++){
                ii = (i + 1 + xstart[2] - 2 + NX / 2) % NX - NX / 2;
                ii2 = ii * ii;
                for (j = 0; j < dims[2][1]; j++){
                    jj = (j + 1 + ystart[2] - 2 + NY / 2) % NY - NY / 2;
                    ij2 = jj * jj + ii2;
                    for (k = 0; k < dims[2][2]; k++){
                        kk = (k + 1 + zstart[2] - 2 + NZ / 2) % NZ - NZ / 2;

                        twid(k, j, i) = exp( ap * ((double) (kk*kk + ij2)) );
                    }
                }
            }
            break;

        case 1:
            for (i = 0; i < dims[2][1]; i++){
                ii = (i + 1 + xstart[2] - 2 + NX / 2) % NX - NX / 2;
                ii2 = ii * ii;
                for (j = 0; j < dims[2][2]; j++){
                    jj = (j + 1 + ystart[2] - 2 + NY / 2) % NY - NY / 2;
                    ij2 = jj * jj + ii2;
                    for (k = 0; k < dims[2][0]; k++){
                        kk = (k + 1 + zstart[2] - 2 + NZ / 2) % NZ - NZ / 2;

                        twid(j, i, k) = exp( ap * ((double) (kk*kk + ij2)) );
                    }
                }
            }
            break;
    }
}

void compute_initial_conditions(shared dcomplex_cell_t *u0_arr, int d[3]){
    /* Fill in array u0 with initial conditions from
       random number generator */
    int k;
    double x0, start, an, dummy;

    start = SEED;
    /* Jump to the starting element for our first plane. */
    ipow46( A, 2*NX, (zstart[0]-1)*NY + (ystart[0]-1), &an );
    dummy = randlc(&start, an);
    ipow46( A, 2*NX, NY, &an );

    /* Go through by z planes filling in one square at a time. */
    for (k = 0; k < d[2]; k++){
        x0 = start;

        /* vranlc() starts filling up the destination array from index 1 and 
           not 0 as expected in C */
        vranlc(2*NX*d[1], &x0, A, ((double *)&u0_arr[MYTHREAD].cell[k*d[1]*d[0]])-1 );

        if (k != d[2])
            dummy = randlc(&start, an);
    }
}

void fft_init(int n){
    /* compute the roots-of-unity array that will be used for subsequent FFTs.*/
    int m, ku, i, j, ln;
    double t, ti;

    /* Initialize the U array with sines and cosines in a manner that permits
       stride one access at each FFT iteration. */
    m = ilog2(n);
    u[0].real = (double)m;
    u[0].imag = 0.0;
    ku = 1;
    ln = 1;

    for (j = 1; j <= m; j++){
        t = PI / ln;

        for (i = 0; i <= ln - 1; i++){
            ti = i * t;
            u[i + ku].real = cos(ti);
            u[i + ku].imag = sin(ti);
        }

        ku = ku + ln;
        ln = 2 * ln;
    }
}

void ipow46(double a, int exp_1, int exp_2, double *result){
    /* compute a^exponent mod 2^46 */
    double dummy, q, r;
    int n, n2;
    int two_pow;

    /* Use
       a^n = a^(n/2)*a^(n/2) if n even else
       a^n = a*a^(n-1)       if n odd */
    *result = 1;
    if( (exp_2 == 0) || (exp_1 == 0) )
        return;
    q = a;
    r = 1;
    n = exp_1;
    two_pow = 1;

    while (two_pow){
        n2 = n / 2;
        if (n2 * 2 == n){
            dummy = randlc(&q, q);
            n = n2;
        }else{
            n = n * exp_2;
            two_pow = 0;
        }
    }

    while (n > 1){
        n2 = n / 2;
        if (n2 * 2 == n){
            dummy = randlc(&q, q);
            n = n2;
        }else{
            dummy = randlc(&r, q);
            n--;
        }
    }

    dummy = randlc(&r, q);
    *result = r;
}

int ilog2(int n){
    int nn, lg;

    if (n == 1)
        return 0;
    lg = 1;
    nn = 2;
    while (nn < n){
        nn = nn << 1;
        lg++;
    }

    return lg;
}

void verify(int d1, int d2, int d3, int nt, boolean * verified, char *class){
    int i;
    double err, epsilon;
    /* Sample size reference checksums */

    /* Class S size reference checksums */
    double vdata_real_s[6 + 1] =
    {0.0,
        5.546087004964e+02,
        5.546385409189e+02,
        5.546148406171e+02,
        5.545423607415e+02,
        5.544255039624e+02,
        5.542683411902e+02};
    double vdata_imag_s[6 + 1] =
    {0.0,
        4.845363331978e+02,
        4.865304269511e+02,
        4.883910722336e+02,
        4.901273169046e+02,
        4.917475857993e+02,
        4.932597244941e+02};
    /* Class W size reference checksums */
    double vdata_real_w[6 + 1] =
    {0.0,
        5.673612178944e+02,
        5.631436885271e+02,
        5.594024089970e+02,
        5.560698047020e+02,
        5.530898991250e+02,
        5.504159734538e+02};
    double vdata_imag_w[6 + 1] =
    {0.0,
        5.293246849175e+02,
        5.282149986629e+02,
        5.270996558037e+02,
        5.260027904925e+02,
        5.249400845633e+02,
        5.239212247086e+02};
    /* Class A size reference checksums */
    double vdata_real_a[6 + 1] =
    {0.0,
        5.046735008193e+02,
        5.059412319734e+02,
        5.069376896287e+02,
        5.077892868474e+02,
        5.085233095391e+02,
        5.091487099959e+02};
    double vdata_imag_a[6 + 1] =
    {0.0,
        5.114047905510e+02,
        5.098809666433e+02,
        5.098144042213e+02,
        5.101336130759e+02,
        5.104914655194e+02,
        5.107917842803e+02};
    /* Class B size reference checksums */
    double vdata_real_b[20 + 1] =
    {0.0,
        5.177643571579e+02,
        5.154521291263e+02,
        5.146409228649e+02,
        5.142378756213e+02,
        5.139626667737e+02,
        5.137423460082e+02,
        5.135547056878e+02,
        5.133910925466e+02,
        5.132470705390e+02,
        5.131197729984e+02,
        5.130070319283e+02,
        5.129070537032e+02,
        5.128182883502e+02,
        5.127393733383e+02,
        5.126691062020e+02,
        5.126064276004e+02,
        5.125504076570e+02,
        5.125002331720e+02,
        5.124551951846e+02,
        5.124146770029e+02};
    double vdata_imag_b[20 + 1] =
    {0.0,
        5.077803458597e+02,
        5.088249431599e+02,
        5.096208912659e+02,
        5.101023387619e+02,
        5.103976610617e+02,
        5.105948019802e+02,
        5.107404165783e+02,
        5.108576573661e+02,
        5.109577278523e+02,
        5.110460304483e+02,
        5.111252433800e+02,
        5.111968077718e+02,
        5.112616233064e+02,
        5.113203605551e+02,
        5.113735928093e+02,
        5.114218460548e+02,
        5.114656139760e+02,
        5.115053595966e+02,
        5.115415130407e+02,
        5.115744692211e+02};
    /* Class C size reference checksums */
    double vdata_real_c[20 + 1] =
    {0.0,
        5.195078707457e+02,
        5.155422171134e+02,
        5.144678022222e+02,
        5.140150594328e+02,
        5.137550426810e+02,
        5.135811056728e+02,
        5.134569343165e+02,
        5.133651975661e+02,
        5.132955192805e+02,
        5.132410471738e+02,
        5.131971141679e+02,
        5.131605205716e+02,
        5.131290734194e+02,
        5.131012720314e+02,
        5.130760908195e+02,
        5.130528295923e+02,
        5.130310107773e+02,
        5.130103090133e+02,
        5.129905029333e+02,
        5.129714421109e+02};
    double vdata_imag_c[20 + 1] =
    {0.0,
        5.149019699238e+02,
        5.127578201997e+02,
        5.122251847514e+02,
        5.121090289018e+02,
        5.121143685824e+02,
        5.121496764568e+02,
        5.121870921893e+02,
        5.122193250322e+02,
        5.122454735794e+02,
        5.122663649603e+02,
        5.122830879827e+02,
        5.122965869718e+02,
        5.123075927445e+02,
        5.123166486553e+02,
        5.123241541685e+02,
        5.123304037599e+02,
        5.123356167976e+02,
        5.123399592211e+02,
        5.123435588985e+02,
        5.123465164008e+02};
    double vdata_real_d[25 + 1] =
    {0.0,
        5.122230065252e+02,
        5.120463975765e+02,
        5.119865766760e+02,
        5.119518799488e+02,
        5.119269088223e+02,
        5.119082416858e+02,
        5.118943814638e+02,
        5.118842385057e+02,
        5.118769435632e+02,
        5.118718203448e+02,
        5.118683569061e+02,
        5.118661708593e+02,
        5.118649768950e+02,
        5.118645605626e+02,
        5.118647586618e+02,
        5.118654451572e+02,
        5.118665212451e+02,
        5.118679083821e+02,
        5.118695433664e+02,
        5.118713748264e+02,
        5.118733606701e+02,
        5.118754661974e+02,
        5.118776626738e+02,
        5.118799262314e+02,
        5.118822370068e+02};
    double vdata_imag_d[25 + 1] =
    {0.0,
        5.118534037109e+02,
        5.117061181082e+02,
        5.117096364601e+02,
        5.117373863950e+02,
        5.117680347632e+02,
        5.117967875532e+02,
        5.118225281841e+02,
        5.118451629348e+02,
        5.118649119387e+02,
        5.118820803844e+02,
        5.118969781011e+02,
        5.119098918835e+02,
        5.119210777066e+02,
        5.119307604484e+02,
        5.119391362671e+02,
        5.119463757241e+02,
        5.119526269238e+02,
        5.119580184108e+02,
        5.119626617538e+02,
        5.119666538138e+02,
        5.119700787219e+02,
        5.119730095953e+02,
        5.119755100241e+02,
        5.119776353561e+02,
        5.119794338060e+02};

    epsilon = 1.0e-12;
    *verified = TRUE;
    *class = 'U';

    double *vdata_real = NULL;
    double *vdata_imag = NULL;

    if (d1 == 64 && d2 == 64 && d3 == 64 && nt == 6){
        *class = 'S';
        vdata_real = vdata_real_s;
        vdata_imag = vdata_imag_s;
    }
    else if (d1 == 128 && d2 == 128 && d3 == 32 && nt == 6){
        *class = 'W';
        vdata_real = vdata_real_w;
        vdata_imag = vdata_imag_w;
    }
    else if (d1 == 256 && d2 == 256 && d3 == 128 && nt == 6){
        *class = 'A';
        vdata_real = vdata_real_a;
        vdata_imag = vdata_imag_a;
    }
    else if (d1 == 512 && d2 == 256 && d3 == 256 && nt == 20){
        *class = 'B';
        vdata_real = vdata_real_b;
        vdata_imag = vdata_imag_b;
    }
    else if (d1 == 512 && d2 == 512 && d3 == 512 && nt == 20){
        *class = 'C';
        vdata_real = vdata_real_c;
        vdata_imag = vdata_imag_c;
    }
    else if (d1 == 2048 && d2 == 1024 && d3 == 1024 && nt == 25){
        *class = 'D';
        vdata_real = vdata_real_d;
        vdata_imag = vdata_imag_d;
    }

    for (i = 1; i <= nt; i++){
        err = (get_real(sums[i]) - vdata_real[i]) / vdata_real[i];
        if( isnan(err) || fabs(err) > epsilon ){
            *verified = FALSE;
            break;
        }

        err = (get_imag(sums[i]) - vdata_imag[i]) / vdata_imag[i];
        if( isnan(err) || fabs(err) > epsilon ){
            *verified = FALSE;
            break;
        }
    }

    if ((*class != 'U') && (*verified))
        printf("Result verification successful\n");
    else
        printf("Result verification failed\n");

    printf("class = %1c\n", *class);
}

void print_timers(void){
    int i, j;
    double max_timers[T_MAX];
    const char *tstrings[] = {
        "          total ",
        "          setup ",
        "            fft ",
        "         evolve ",
        "       checksum ",
        "         fftlow ",
        "        fftcopy ",
        "      transpose ",
        "     all_to_all "
    };

    for( i=0; i<T_MAX; i++ )
#ifdef BUPC_TEST_HARNESS
        timer[i][MYTHREAD] = timer_read( i );
#else
        timer[(MYTHREAD*T_MAX)+i] = timer_read( i );
#endif

    upc_barrier;

    if( MYTHREAD == 0 ){
        for( i=0; i<T_MAX; i++ ){
#ifdef BUPC_TEST_HARNESS
            max_timers[i] = timer[i][0];
            for( j=1; j<THREADS; j++ )
                if( timer[i][j] > max_timers[i] )
                    timer[i][j] = max_timers[i];
#else
            max_timers[i] = timer[i];
            for( j=0; j<THREADS; j++ )
                if( timer[(j*T_MAX)+i] > max_timers[i] )
                    timer[(j*T_MAX)+i] = max_timers[i];
#endif
        }

        printf("\n");
        printf(" Timer report:\n");
        for (i = 0; i < T_MAX; i++)
            printf("%s = %10.3f\n", tstrings[i], max_timers[i]);
    }
}

void fft(int dir, shared dcomplex_cell_t *x1_arr, 
        shared dcomplex_cell_t *x2_arr){
    dcomplex y0[NX][FFTBLOCKPAD];
    dcomplex y1[NX][FFTBLOCKPAD];

    /* note: args x1, x2 must be different arrays
       note: args for cfftsx are (direction, layout, xin, xout, scratch)
       xin/xout may be the same and it can be somewhat faster if they are */
    if (dir == 1){
        switch (layout_type){
            case 0:
                cffts1(1, dims[0], x1_arr, x1_arr, y0, y1);      /* x1 -> x1 */
                cffts2(1, dims[1], x1_arr, x1_arr, y0, y1);      /* x1 -> x1 */
                cffts3(1, dims[2], x1_arr, x2_arr, y0, y1);      /* x1 -> x2 */
                break;

            case 1:
                cffts1(1, dims[0], x1_arr, x1_arr, y0, y1);      /* x1 -> x1 */
                cffts2(1, dims[1], x1_arr, x1_arr, y0, y1);      /* x1 -> x1 */

                TIMER_START(T_TRANSPOSE);
                transpose_xy_z(1, 2, x1_arr, x2_arr);
                TIMER_STOP(T_TRANSPOSE);

                cffts1(1, dims[2], x2_arr, x2_arr, y0, y1);      /* x2 -> x2 */
                break;
        }
    }else{
        switch (layout_type){
            case 0:
                cffts3(-1, dims[2], x1_arr, x1_arr, y0, y1);     /* x1 -> x1 */
                cffts2(-1, dims[1], x1_arr, x1_arr, y0, y1);     /* x1 -> x1 */
                cffts1(-1, dims[0], x1_arr, x2_arr, y0, y1);     /* x1 -> x2 */
                break;

            case 1:
                cffts1(-1, dims[2], x1_arr, x1_arr, y0, y1);     /* x1 -> x1 */

                TIMER_START(T_TRANSPOSE);
                transpose_x_yz(2, 1, x1_arr, x2_arr);
                TIMER_STOP(T_TRANSPOSE);

                cffts2(-1, dims[1], x2_arr, x2_arr, y0, y1);     /* x2 -> x2 */
                cffts1(-1, dims[0], x2_arr, x2_arr, y0, y1);     /* x2 -> x2 */
                break;
        }
    }
}

void cfftz(int is, int m, int n, dcomplex x_arr[NX][FFTBLOCKPAD],
        dcomplex y_arr[NX][FFTBLOCKPAD]){
    /* Computes NY N-point complex-to-complex FFTs of X using an algorithm due
       to Swarztrauber.  X is both the input and the output array, while Y is a
       scratch array.  It is assumed that N = 2^M.  Before calling CFFTZ to
       perform FFTs, the array U must be initialized by calling CFFTZ with IS
       set to 0 and M set to MX, where MX is the maximum value of M for any
       subsequent call. */
    int i, j, l, mx;

    /* Check if input parameters are invalid. */
    mx = (int)(u[0].real);
    if ((is != 1 && is != -1) || m < 1 || m > mx){
        printf("CFFTZ: Either U has not been initialized, or else\n"
                "one of the input parameters is invalid%5d%5d%5d\n",
                is, m, mx);
        exit(1);
    }

    /* Perform one variant of the Stockham FFT. */
    for (l = 1; l <= m; l += 2){
        fftz2(is, l, m, n, fftblock, fftblockpad, u, x_arr, y_arr);
        if (l == m)
            break;
        fftz2(is, l + 1, m, n, fftblock, fftblockpad, u, y_arr, x_arr);
    }

    /* Copy Y to X. */
    if (m % 2 == 1){
        for (j = 0; j < n; j++){
            for (i = 0; i < fftblock; i++){
                x_arr[j][i].real = y_arr[j][i].real;
                x_arr[j][i].imag = y_arr[j][i].imag;
            }
        }
    }
}

void fftz2(int is, int l, int m, int n, int ny, int ny1, dcomplex u_arr[NX],
        dcomplex x_arr[NX][FFTBLOCKPAD], dcomplex y_arr[NX][FFTBLOCKPAD]){
    /* Performs the L-th iteration of the second variant of the Stockham FFT. */
    int k, n1, li, lj, lk, ku, i, j, i11, i12, i21, i22;
    dcomplex u1;

    /* Set initial parameters. */
    n1 = n / 2;
    if (l - 1 == 0)
        lk = 1;
    else
        lk = 2 << ((l - 1) - 1);

    if (m - l == 0)
        li = 1;
    else
        li = 2 << ((m - l) - 1);

    lj = 2 * lk;
    ku = li;

    for (i = 0; i < li; i++){
        i11 = i * lk;
        i12 = i11 + n1;
        i21 = i * lj;
        i22 = i21 + lk;
        if (is >= 1){
            u1.real = u_arr[ku + i].real;
            u1.imag = u_arr[ku + i].imag;
        }else{
            u1.real = u_arr[ku + i].real;
            u1.imag = -u_arr[ku + i].imag;
        }

        /* This loop is vectorizable. */
        for (k = 0; k < lk; k++){
            for (j = 0; j < ny; j++){
                double x11real, x11imag;
                double x21real, x21imag;
                x11real = x_arr[i11 + k][j].real;
                x11imag = x_arr[i11 + k][j].imag;
                x21real = x_arr[i12 + k][j].real;
                x21imag = x_arr[i12 + k][j].imag;
                y_arr[i21 + k][j].real = x11real + x21real;
                y_arr[i21 + k][j].imag = x11imag + x21imag;
                y_arr[i22 + k][j].real = u1.real * (x11real - x21real)
                    - u1.imag * (x11imag - x21imag);
                y_arr[i22 + k][j].imag = u1.real * (x11imag - x21imag)
                    + u1.imag * (x11real - x21real);
            }
        }
    }
}

void cffts1(int is, int d[3], shared dcomplex_cell_t *x_arr,
        shared dcomplex_cell_t *xout_arr, dcomplex y0[NX][FFTBLOCKPAD],
        dcomplex y1[NX][FFTBLOCKPAD]){
    int logd[3];
    int i, j, k, jj, i_j;

    set_x_ptr_xout_ptr(x_arr, xout_arr);

    for (i = 0; i < 3; i++)
        logd[i] = ilog2(d[i]);

    for (k = 0; k < d[2]; k++){
        for (jj = 0; jj <= d[1] - fftblock; jj += fftblock){
            TIMER_START(T_FFTCOPY);
            for (j = 0; j < fftblock; j++){
                i_j = j+jj;
                for (i = 0; i < d[0]; i++){
                    y0[i][j].real = x(k,i_j,i).real;
                    y0[i][j].imag = x(k,i_j,i).imag;
                }
            }
            TIMER_STOP(T_FFTCOPY);

            TIMER_START(T_FFTLOW);
            cfftz(is, logd[0], d[0], y0, y1);
            TIMER_STOP(T_FFTLOW);

            TIMER_START(T_FFTCOPY);
            for (j = 0; j < fftblock; j++){
                i_j = j+jj;
                for (i = 0; i < d[0]; i++){
                    xout(k,i_j,i).real = y0[i][j].real;
                    xout(k,i_j,i).imag = y0[i][j].imag;
                }
            }
            TIMER_STOP(T_FFTCOPY);
        }
    }
}

void cffts2(int is, int d[3], shared dcomplex_cell_t *x_arr,
        shared dcomplex_cell_t *xout_arr, dcomplex y0[NX][FFTBLOCKPAD],
        dcomplex y1[NX][FFTBLOCKPAD]){
    int logd[3];
    int i, j, k, ii, i_i;

    set_x_ptr_xout_ptr(x_arr, xout_arr);

    for (i = 0; i < 3; i++)
        logd[i] = ilog2(d[i]);

    for (k = 0; k < d[2]; k++){
        for (ii = 0; ii <= d[0] - fftblock; ii += fftblock){
            TIMER_START(T_FFTCOPY);

            for (j = 0; j < d[1]; j++){
                for (i = 0; i < fftblock; i++){
                    i_i = i+ii;
                    y0[j][i].real = x(k,j,i_i).real;
                    y0[j][i].imag = x(k,j,i_i).imag;
                }
            }
            TIMER_STOP(T_FFTCOPY);

            TIMER_START(T_FFTLOW);
            cfftz(is, logd[1], d[1], y0, y1);
            TIMER_STOP(T_FFTLOW);

            TIMER_START(T_FFTCOPY);
            for (j = 0; j < d[1]; j++){
                for (i = 0; i < fftblock; i++){
                    i_i = i+ii;
                    xout(k,j,i_i).real = y0[j][i].real;
                    xout(k,j,i_i).imag = y0[j][i].imag;
                }
            }
            TIMER_STOP(T_FFTCOPY);
        }
    }
}

void cffts3(int is, int d[3], shared dcomplex_cell_t *x_arr,
        shared dcomplex_cell_t *xout_arr, dcomplex y0[NX][FFTBLOCKPAD],
        dcomplex y1[NX][FFTBLOCKPAD]){
    int logd[3];
    int i, j, k, ii, i_i;

    set_x_ptr_xout_ptr(x_arr, xout_arr);

    for (i = 0; i < 3; i++)
        logd[i] = ilog2(d[i]);

    for (j = 0; j < d[1]; j++){
        for (ii = 0; ii <= d[0] - fftblock; ii += fftblock){
            TIMER_START(T_FFTCOPY);
            for (k = 0; k < d[2]; k++){
                for (i = 0; i < fftblock; i++){
                    i_i = i+ii;
                    y0[k][i].real = x(k,j,i_i).real;
                    y0[k][i].imag = x(k,j,i_i).imag;
                }
            }
            TIMER_STOP(T_FFTCOPY);

            TIMER_START(T_FFTLOW);
            cfftz(is, logd[2], d[2], y0, y1);
            TIMER_STOP(T_FFTLOW);

            TIMER_START(T_FFTCOPY);
            for (k = 0; k < d[2]; k++){
                for (i = 0; i < fftblock; i++){
                    i_i = i+ii;
                    xout(k,j,i_i).real = y0[k][i].real;
                    xout(k,j,i_i).imag = y0[k][i].imag;
                }
            }
            TIMER_STOP(T_FFTCOPY);
        }
    }
}

void transpose_x_yz(int l1, int l2, shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst){
    transpose2_local(dims[l1][0], dims[l1][1] * dims[l1][2], src, dst );
    transpose2_global(dst, src);
    transpose2_finish(dims[l1][0], dims[l1][1] * dims[l1][2], src, dst);
}

void transpose_xy_z(int l1, int l2, shared dcomplex_cell_t *src,
        shared dcomplex_cell_t *dst){
    transpose2_local(dims[l1][0] * dims[l1][1], dims[l1][2], src, dst );
    transpose2_global(dst, src);
    transpose2_finish(dims[l1][0] * dims[l1][1], dims[l1][2], src, dst);
}


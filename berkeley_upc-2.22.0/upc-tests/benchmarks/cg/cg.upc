#include <upc_relaxed.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "mmio.h"

#include "bupc_timers.h"

/*******
 *
 * Type definitions 
 */

typedef struct {
    double *data;
    double block_size;
} poisson_jacobi_t;

typedef struct csr_matrix_t {

    /* Dimensions, number of nonzeros 
     * (m == n for square, m < n for a local "slice") */
    int m, n, nz;

    /* Start of the rows owned by each thread */
    int start[THREADS + 1];

    /* Starts of rows owned by local processor
     * row_start[0] == 0 == offset of first nz in row start[MY_THREAD] 
     */
    int *row_start;

    /* Column indices and values of matrix elements at local processor */
    int *col_idx;
    double *val;

} csr_matrix_t;

typedef struct csr_jacobi_t {
    int n;
    int block_size;
    double *factored_blocks;
} csr_jacobi_t;

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif

/* Test problem: 1-d Poisson operator
 *
 * Assume each processor has some contiguous chunk of the variables,
 * with processor 0 at the start and processor MYTHREADS at the end.
 * CAVEAT: Each processor must have *some* variables, or the code
 * to handle the boundaries is going to get messed up.
 */
void poisson_matvec(double *Ax, void *Adata, double *x, int n)
{
    int i;
    static shared double left_edge[THREADS];
    static shared double right_edge[THREADS];

    /* Communicate the boundary values */
    left_edge[MYTHREAD] = x[0];
    right_edge[MYTHREAD] = x[n - 1];

    /* Split-phase barrier with the local part of the computation
     * inside.  This should take enough time to hide the communication
     * of the boundary values
     */
    upc_notify;

    Ax[0] = 2 * x[0] - x[1];
    for (i = 1; i < n - 1; ++i)
        Ax[i] = -x[i - 1] + 2 * x[i] - x[i + 1];
    Ax[n - 1] = -x[n - 2] + 2 * x[n - 1];

    upc_wait;

    /* Now incorporate the contributions from boundaries between
     * processors, synchronize, and move forward
     */
    if (MYTHREAD > 0)
        Ax[0] -= right_edge[MYTHREAD - 1];

    if (MYTHREAD < THREADS - 1)
        Ax[n - 1] -= left_edge[MYTHREAD + 1];

    upc_barrier;
}


/****************************************
 *
 * CSR code
 */

typedef struct {
    int i, j;
    double val;
} matrix_entry_t;

int entry_comparison(const void *e1, const void *e2)
{
    const matrix_entry_t *entry1 = (const matrix_entry_t *) e1;
    const matrix_entry_t *entry2 = (const matrix_entry_t *) e2;

    if (entry1->i < entry2->i)
        return -1;
    else if (entry1->i > entry2->i)
        return 1;

    if (entry1->j < entry2->j)
        return -1;
    else if (entry1->j > entry2->j)
        return 1;

    return 0;
}


csr_matrix_t *csr_mm_load(char *filename)
{
    int ret_code;
    MM_typecode matcode;
    FILE *f;

    int entry_count;
    int i, M, N, nz;
    matrix_entry_t *entries;
    matrix_entry_t *entry;

    int *row_start;
    int *col_index;
    double *val;

    csr_matrix_t *A;

    if ((f = fopen(filename, "r")) == NULL)
        exit(1);

    if (mm_read_banner(f, &matcode) != 0) {
        printf("Could not process Matrix Market banner.\n");
        exit(1);
    }

    if (!mm_is_sparse(matcode) || !mm_is_symmetric(matcode) ||
        !mm_is_real(matcode)) {

        printf("Sorry, this application does not support ");
        printf("Market Market type: [%s]\n", mm_typecode_to_str(matcode));
        exit(1);
    }

    /* find out size of sparse matrix .... */

    if ((ret_code = mm_read_mtx_crd_size(f, &M, &N, &nz)) != 0)
        exit(1);


    /* reserve memory for matrices */

    row_start = (int *) malloc((M + 1) * sizeof(int));
    col_index = (int *) malloc((2 * nz - M) * sizeof(int));
    val = (double *) malloc((2 * nz - M) * sizeof(double));

    entries =
        (matrix_entry_t *) malloc((2 * nz - M) * sizeof(matrix_entry_t));


    /* NOTE: when reading in doubles, ANSI C requires the use of the "l"  */
    /*   specifier as in "%lg", "%lf", "%le", otherwise errors will occur */
    /*  (ANSI C X3.159-1989, Sec. 4.9.6.2, p. 136 lines 13-15)            */

    entry = entries;
    entry_count = 0;

    for (i = 0; i < nz; i++) {

        int row, col;
        double val;

        fscanf(f, "%d %d %lg\n", &row, &col, &val);
        --row;                  /* adjust to 0-based */
        --col;

        //assert(row >= 0 && col >= 0);
        //assert(entry_count++ < 2 * nz - M);
        entry->i = row;
        entry->j = col;
        entry->val = val;
        ++entry;

        if (row != col) {       /* Fill out the other half... */
	  //assert(entry_count++ < 2 * nz - M);
            entry->i = col;
            entry->j = row;
            entry->val = val;
            ++entry;
        }
    }

    if (f != stdin)
        fclose(f);

    /**********************************/
    /* now make CSR version of matrix */
    /**********************************/

    nz = 2 * nz - M;
    qsort(entries, nz, sizeof(matrix_entry_t), entry_comparison);

    entry = entries;

    row_start[0] = 0;
    for (i = 0; i < nz; ++i) {
        row_start[entry->i + 1] = i + 1;
        col_index[i] = entry->j;
        val[i] = entry->val;
        ++entry;
    }

    free(entries);

    A = (csr_matrix_t *) malloc(sizeof(csr_matrix_t));
    A->m = M;
    A->n = N;
    A->nz = nz;
    A->row_start = row_start;
    A->col_idx = col_index;
    A->val = val;

    return A;
}

/* Load a sparse matrix in Matrix Market format and distribute
 * the values among processors
 */
csr_matrix_t *csr_mm_upc_load(char *filename)
{
    csr_matrix_t *initial_matrix = NULL;
    csr_matrix_t *local_matrix = NULL;
    int *start;
    int i;
    int n_per_proc, nlocal, nzlocal;
    long long first_nz;

    long long tmp = 0, tmp1 = 0;

    static shared long long n;
    static shared long long row_start[10000];
    static shared long long col_idx[100000];
    static shared double val[100000];

    /* Read the initial matrix at processor 0 and copy it
     * into shared space
     */
    if (MYTHREAD == 0) {
        int nz;

        initial_matrix = csr_mm_load(filename);
        n = initial_matrix->n;
        nz = initial_matrix->nz;

        //assert(nz < 100000);
        //assert(n < 10000);

        for (i = 0; i <= n; ++i)
            row_start[i] = initial_matrix->row_start[i];

        for (i = 0; i < nz; ++i) {
            col_idx[i] =  initial_matrix->col_idx[i];
            val[i] = initial_matrix->val[i];
        }

        free(initial_matrix->val);
        free(initial_matrix->col_idx);
        free(initial_matrix->row_start);
        free(initial_matrix);
    }

    upc_barrier;


    /* Share out sections of the matrix to each processor */

    local_matrix = (csr_matrix_t *) malloc(sizeof(csr_matrix_t));
    tmp = n;	
    local_matrix->n = (int) tmp;

    n_per_proc = local_matrix->n / THREADS;
    start = local_matrix->start;
    for (i = 0; i < THREADS; ++i) {
        start[i] = i * n_per_proc;
    }
    start[THREADS] = (int) tmp;
    nlocal = start[MYTHREAD + 1] - start[MYTHREAD];
    local_matrix->m = nlocal;

    local_matrix->row_start = (int *) malloc((nlocal + 1) * sizeof(int)); 
    first_nz = row_start[start[MYTHREAD]]; 
    for (i = 0; i <= nlocal; ++i) { 
      local_matrix->row_start[i] = 
	row_start[start[MYTHREAD] + i] - first_nz; 
    } 
    
    nzlocal = row_start[start[MYTHREAD + 1]] - row_start[start[MYTHREAD]]; 
    local_matrix->nz = nzlocal; 
    local_matrix->col_idx = (int *) malloc(nzlocal * sizeof(int)); 
    local_matrix->val = (double *) malloc(nzlocal * sizeof(double)); 
    assert(local_matrix->col_idx != NULL); 
    assert(local_matrix->val != NULL); 
    for (i = 0; i < nzlocal; ++i) { 
        local_matrix->col_idx[i] = col_idx[first_nz + i]; 
        local_matrix->val[i] = val[first_nz + i]; 
    } 

    upc_barrier;

    return local_matrix;
}

/* Multiply by a matrix in compressed sparse row format
 */
void csr_matvec(double *Ax, void *Adata, double *x, int n)
{
    int i, j;

    csr_matrix_t *Acsr = (csr_matrix_t *) Adata;
    double *Aval = Acsr->val;
    int *Arow = Acsr->row_start;
    int *Acol = Acsr->col_idx;
    int my_start = Acsr->start[MYTHREAD];

    static shared double xglobal[100000];

    /* Copy local vector section into shared memory */
    for (i = 0; i < n; ++i) {
        xglobal[my_start + i] = x[i];
    }
    //upc_memput(&xglobal[my_start], x, n * sizeof(double));
    upc_barrier;

    for (i = 0; i < n; ++i) {
        Ax[i] = 0;
        for (j = Arow[i]; j < Arow[i + 1]; ++j) {
            int col = *Acol++;
            double Aelement = *Aval++;
            Ax[i] += Aelement * xglobal[col];
        }
    }
    upc_barrier;
}

/**********************************************
 *
 * Dot product code
 */

/* Compute alpha*x + y and store in dest (daxpy-like operation)
 *
 * Arguments:
 *  dest  - destination vector.  Can be the same as x or y.
 *  alpha - scalar multiplier
 *  x, y  - vector inputs
 *  n     - vector size
 */
void axpy(double *dest, double alpha, double *x, double *y, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        dest[i] = alpha * x[i] + y[i];
}


/* Compute the dot product of two vectors x'*y
 * (Each thread passes in the local part of x and y)
 *
 * Arguments:
 *  x, y - vector inputs (local part)
 *  n    - vector size   (local part)
 */
double ddot(double *x, double *y, int n)
{
    int i;
    double final_sum = 0;
    double local_sum = 0;
    static shared double thread_sums[THREADS];

    upc_notify;
    local_sum = 0;
    for (i = 0; i < n; ++i)
        local_sum += x[i] * y[i];
    upc_wait;

    thread_sums[MYTHREAD] = local_sum;
    upc_barrier;

    final_sum = 0;
    for (i = 0; i < THREADS; ++i)
        final_sum += thread_sums[i];

    return final_sum;
}


/* Solve Ax = b using a preconditioned conjugate-gradient iteration.
 * 
 * Arguments:
 *  matvec(Ax,    Adata, x, n) - Multiply A*x into Ax
 *  psolve(Minvx, Mdata, x, n) - Apply preconditioner (solve M\x into Minvx)
 *  Adata - Opaque pointer to data used by matvec
 *  Mdata - Opaque pointer to data used by psolve
 *  b     - System right-hand side (local part)
 *  x     - Result                 (local part)
 *  rtol  - Tolerance on the relative residual (||r||/||b||)
 *  n     - System size            (local part)
 *  rhist   - Residual norm history.  Should be at least maxiter doubles
 *            if it is not NULL.
 *  maxiter - Maximum number of iterations before returning
 *
 * Returns:
 *  Iteration count on success, -1 on failure
 */
int precond_cg(void (*matvec) (double *Ax, void *Adata, double *x, int n),
               void (*psolve) (double *Minvx, void *Adata, double *x,
                               int n), void *Adata, void *Mdata, double *b,
               double *x, double rtol, int n, double *rhist, int maxiter)
{
    const int nbytes = n * sizeof(double);

    double bnorm2;              /* ||b||^2 */
    double rnorm2;              /* Residual norm squared */
    double rz, rzold;           /* r'*z from two successive iterations */
    double alpha, beta;

    double *s;                  /* Search direction */
    double *r;                  /* Residual         */
    double *z;                  /* Temporary vector */

    int i = 0;                  /* Current iteration */

    upc_barrier;

    s = (double *) malloc(nbytes);
    r = (double *) malloc(nbytes);
    z = (double *) malloc(nbytes);

    bnorm2 = ddot(b, b, n);
    memset(x, 0, nbytes);
    memcpy(r, b, nbytes);
    psolve(z, Mdata, r, n);
    memcpy(s, z, nbytes);

    rz = ddot(r, z, n);
    rnorm2 = ddot(r, r, n);

    for (i = 0; i < maxiter && rnorm2 > bnorm2 * rtol * rtol; ++i) {

        if (rhist != NULL)
            rhist[i] = sqrt(rnorm2 / bnorm2);

        matvec(z, Adata, s, n);
        alpha = rz / ddot(s, z, n);
        axpy(x, alpha, s, x, n);
        axpy(r, -alpha, z, r, n);

        psolve(z, Mdata, r, n);
        rzold = rz;
        rz = ddot(r, z, n);
        rnorm2 = ddot(r, r, n);

        beta = -rz / rzold;
        axpy(s, -beta, s, z, n);

    }

    free(z);
    free(r);
    free(s);

    if (i >= maxiter)
        return -1;

    if (rhist != NULL)
        rhist[i] = sqrt(rnorm2 / bnorm2);

    upc_barrier;

    return i;
}


/* Dummy preconditioner... just the identity
 */
void dummy_psolve(double *Minvx, void *Mdata, double *x, int n)
{
    memcpy(Minvx, x, n * sizeof(double));
}

/* Main routine -- test out the code on a sample problem
 */
void driver(int *start, int maxiter,
            void (*matvec) (double *, void *, double *, int), void *Adata,
            void (*psolve) (double *, void *, double *, int), void *Mdata)
{
    int N = start[THREADS] - start[0];
    static shared double *shared xglobal;

    int n = start[MYTHREAD + 1] - start[MYTHREAD];
    double *b = (double *) malloc(n * sizeof(double));
    double *x = (double *) malloc(n * sizeof(double));
    double *rhist = NULL;

    double rtol = 1e-3;

    int i, retval = 0;

    FILE *rhist_fp = NULL;
    FILE *x_fp = NULL;

    /* I/O related initialization at thread 0 */
    if (MYTHREAD == 0) {
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
      xglobal = (shared double *) upc_alloc(sizeof(double) * N);
#else
      xglobal = (shared double *) upc_local_alloc(sizeof(double), N);
#endif
      rhist = (double *) malloc(maxiter * sizeof(double));
      //rhist_fp = fopen("rhist.out", "w");
      //x_fp = fopen("x.out", "w");
    }


    upc_barrier;

    /* Set up the (local) RHS */
    for (i = 0; i < n; ++i)
        b[i] = 1;

    /* Do CG */
    retval = precond_cg(matvec, psolve, Adata, Mdata,
                        b, x, rtol, n, rhist, maxiter);

    /* Put local parts of the solution into the global space */
    //for (i = 0; i < n; ++i)
    //    xglobal[start[MYTHREAD] + i] = x[i];

    upc_barrier;

    /* I/O related output at thread 0 */
    if (MYTHREAD == 0) {

      //for (i = 0; i < n; ++i)
      //    fprintf(x_fp, "%g\n", xglobal[i]);

        if (retval < 0) {
            printf("Iteration failed to converge!\n");
            //for (i = 0; i < maxiter; ++i)
            //    fprintf(rhist_fp, "%g\n", rhist[i]);
        } else {
            printf("Converged after %d iterations\n", retval);
            //for (i = 0; i <= retval; ++i)
            //    fprintf(rhist_fp, "%g\n", rhist[i]);
        }

        //fclose(x_fp);
        //fclose(rhist_fp);
        free(rhist);
        upc_free(xglobal);
    }

    free(x);
    free(b);

    upc_barrier;
}

int main(int argc, char **argv)
{
    if (MYTHREAD == 0) {
        printf("Processor 0!\n");
    }
    
    timer_clear(0);
    timer_clear(1);
    timer_clear(2);

    if (argc <= 1) {
        const int problem_size = 500;
        const int block_size = 20;

        int i;
        int start[THREADS + 1];
        int n_per_proc = problem_size / THREADS;

        if (MYTHREAD == 0)
            printf("Using default 1-d Poisson on a %d point mesh\n",
                   problem_size);

        start[THREADS] = 500;
        for (i = 0; i < THREADS; ++i)
            start[i] = i * n_per_proc;

	timer_start(1);
        driver(start, 500, poisson_matvec, NULL, dummy_psolve, NULL);
	timer_stop(1);
	printf("time for 500 possion matrix without precond: %f\n", timer_read(1));
    } else {
        int block_size = 60;
	csr_matrix_t *A;

        if (MYTHREAD == 0)
            printf("Loading...\n");
        A = csr_mm_upc_load(argv[1]);

        if (MYTHREAD == 0)
	  printf("Vanilla CG:        ");
	timer_start(1);
        driver(A->start, 2000, csr_matvec, A, dummy_psolve, NULL);
	timer_stop(1);
	printf("time for %s with block jacobi: %f\n", argv[1], timer_read(1));
    }
    return 0;
}

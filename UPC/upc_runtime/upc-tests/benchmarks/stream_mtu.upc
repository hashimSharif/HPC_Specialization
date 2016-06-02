/* Program: stream_upc.c
 * Author: Zhang Zhang (zhazhang@mtu.edu)
 * Date: 07/01/04
 *
 * Based on stream_omp.c (by John McCalpin) and stream.c (by Sebastien Chauvin)
 *
 * Run this with at least 2 threads.
 */

/*-----------------------------------------------------------------------*/
/* Program: Stream                                                       */
/* $Source: bitbucket.org:berkeleylab/upc-runtime.git/upc-tests/benchmarks/stream_mtu.upc $ */
/* Original code developed by John D. McCalpin                           */
/* Programmers: John D. McCalpin                                         */
/*              Joe R. Zagar                                             */
/*                                                                       */
/* This program measures memory transfer rates in MB/s for simple        */
/* computational kernels coded in C.                                     */
/*-----------------------------------------------------------------------*/
/* Copyright 1991-2003: John D. McCalpin                                 */
/*-----------------------------------------------------------------------*/
/* License:                                                              */
/*  1. You are free to use this program and/or to redistribute           */
/*     this program.                                                     */
/*  2. You are free to modify this program for your own use,             */
/*     including commercial use, subject to the publication              */
/*     restrictions in item 3.                                           */
/*  3. You are free to publish results obtained from running this        */
/*     program, or from works that you derive from this program,         */
/*     with the following limitations:                                   */
/*     3a. In order to be referred to as "STREAM benchmark results",     */
/*         published results must be in conformance to the STREAM        */
/*         Run Rules, (briefly reviewed below) published at              */
/*         http://www.cs.virginia.edu/stream/ref.html                    */
/*         and incorporated herein by reference.                         */
/*         As the copyright holder, John McCalpin retains the            */
/*         right to determine conformity with the Run Rules.             */
/*     3b. Results based on modified source code or on runs not in       */
/*         accordance with the STREAM Run Rules must be clearly          */
/*         labelled whenever they are published.  Examples of            */
/*         proper labelling include:                                     */
/*         "tuned STREAM benchmark results"                              */
/*         "based on a variant of the STREAM benchmark code"             */
/*         Other comparable, clear and reasonable labelling is           */
/*         acceptable.                                                   */
/*     3c. Submission of results to the STREAM benchmark web site        */
/*         is encouraged, but not required.                              */
/*  4. Use of this program or creation of derived works based on this    */
/*     program constitutes acceptance of these licensing restrictions.   */
/*  5. Absolutely no warranty is expressed or implied.                   */
/*-----------------------------------------------------------------------*/
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/time.h>

# include <limits.h>

/* measures only the RELAXED mode */
#include <upc_relaxed.h>

/* INSTRUCTIONS:
 *
 *	1) Stream requires a good bit of memory to run.  Adjust the
 *          value of 'N' (below) to give a 'timing calibration' of 
 *          at least 20 clock-ticks.  This will provide rate estimates
 *          that should be good to about 5% precision.
 */

#define N 200000
#define NTESTS 11

#define NTIMES	10
#define OFFSET	0

#ifdef ELEM_T
typedef ELEM_T elem_t;
#else
typedef double elem_t;
#endif


# define HLINE "-------------------------------------------------------------------------------\n"

# ifndef MIN
# define MIN(x,y) ((x)<(y)?(x):(y))
# endif
# ifndef MAX
# define MAX(x,y) ((x)>(y)?(x):(y))
# endif

shared unsigned int th_one, th_two;

//shared elem_t local[N*THREADS];
shared [] elem_t *shared sh_a[THREADS];
shared [] elem_t *shared sh_b[THREADS];
shared [] elem_t *shared sh_c[THREADS];
shared [] elem_t *a;
shared [] elem_t *b;
shared [] elem_t *c;
elem_t arr1[N];
elem_t arr2[N];
elem_t arr3[N];

static double	avgtime[NTESTS], 
              maxtime[NTESTS],
              mintime[NTESTS];

static int disable_test[NTESTS] = {
                              1, /*Local read */
                              1, /*Local set */
                              0, /*Stride-1 read */
                              0, /*Random read */
                              1, /*Stride-n read */
                              0, /*Stride-1 set */
                              0, /*Random set */
                              1, /*Stride-n set */
                              1, /*Stride-1 copy */
                              1, /*Random copy */
                              1  /*Stride-n copy */
};

static const char *label[NTESTS] = {
                              "Local read:      ",
                              "Local set:       ",
                              "Stride-1 read:   ",
                              "Random read:     ",
                              "Stride-n read:   ",
                              "Stride-1 set:    ",
                              "Random set:      ",
                              "Stride-n set:    ",
                              "Stride-1 copy:   ",
                              "Random copy:     ",
                              "Stride-n copy:   "
};

static unsigned long indices[N];
static double	refs[NTESTS] = {
    1 * N,
    1 * N,
    1 * N,
    1 * N,
    1 * N,
    1 * N,
    1 * N,
    1 * N,
    2 * N,
    2 * N,
    2 * N
};

double mysecond();
int checktick();


int main()
{
    int			quantum; 
    int			BytesPerWord;
    register int	i, j, k;
    double	scalar, t, times[NTESTS][NTIMES];
    int     dim1 = 1000, dim2 = N/dim1;

    /* --- SETUP --- determine precision and check timing --- */
    for (j = 0; j < NTESTS; j++)
    {
      avgtime[j] = (double) 0;
      maxtime[j] = (double) 0;
      mintime[j] = (double) ULONG_MAX;
    }

    if (!MYTHREAD) {
      if (THREADS == 1)
      {
        printf ("This benchmark needs at least two UPC threads. Exit...\n");
        upc_global_exit (0);
      }
      printf(HLINE);
      BytesPerWord = sizeof(double);
      printf("This system uses %d bytes per DOUBLE PRECISION word.\n", BytesPerWord);

      printf(HLINE);
      printf("Array size = %d, Offset = %d\n" , N*THREADS, OFFSET);
      printf("Total memory required = %.1f MB.\n",
              (3.0 * sizeof(elem_t) * (double) N * THREADS) / 1048576.0);
      printf("Each test is run %d times, but only\n", NTIMES);
      printf("the *best* time for each is used.\n");
      printf(HLINE);
      printf ("Number of Threads = %i. \n", THREADS);
      th_one = random () % THREADS;
      do {
        th_two = random () % THREADS;
      } while (th_one == th_two);
    } /* if !MYTHREAD */

    /* Allocate shared arrays. */
    sh_a[MYTHREAD] = (shared [] elem_t*) upc_alloc (N * sizeof(elem_t));
    sh_b[MYTHREAD] = (shared [] elem_t*) upc_alloc (N * sizeof(elem_t));
    sh_c[MYTHREAD] = (shared [] elem_t*) upc_alloc (N * sizeof(elem_t));
    //upc_barrier;

    /* Get initial value for system clock. */
    for (j = 0; j < N; j++)
    {
      sh_a[MYTHREAD][j] = 1.0;
      sh_b[MYTHREAD][j] = 2.0;
      sh_c[MYTHREAD][j] = 3.0;
    }
    //upc_barrier;

    if (!MYTHREAD) {
      printf(HLINE);
      if  ( (quantum = checktick()) >= 1) 
        printf("Your clock granularity/precision appears to be "
            "%d microseconds.\n", quantum);
      else
        printf("Your clock granularity appears to be "
            "less than one microsecond.\n");
    } /* if !MYTHREAD */
    upc_barrier;
    
    /*	--- MAIN LOOP --- repeat test cases NTIMES times --- */

  for (k = 0; k < NTIMES; k++)
  {
    if (MYTHREAD == th_one) {
      printf("|%d\n",k);

      /* Generate random access indices */
      srandom ((unsigned int) mysecond());
      for (j = 0; j < N; j++)
        indices[j] = random () % N;

      a = (shared [] elem_t*) sh_a[th_one];
      //a = (shared [] elem_t*) &(local[MYTHREAD]);
      
      /* Local read */
      if (!disable_test[0]) {
        times[0][k] = mysecond();
        for (j = 0; j < N; j++)
          arr1[j] = a[j];
        times[0][k] = mysecond() - times[0][k];
      }

      /* Local set */
      if (!disable_test[1]) {
        times[1][k] = mysecond();
        for (j = 0; j < N; j++)
          a[j] = 1.0 + 5.5;
        times[1][k] = mysecond() - times[1][k];
      }

      a = (shared [] elem_t*) sh_a[th_two];
      b = (shared [] elem_t*) sh_b[th_two];
      c = (shared [] elem_t*) sh_c[th_two];
      upc_fence; 

      /* Stride-1 read */
      if (!disable_test[2]) {
        times[2][k] = mysecond();
        for (j = 0; j < N; j++)
          arr1[j] = a[j];
        upc_fence; 
        times[2][k] = mysecond() - times[2][k];
      }

      /* Random read */
      if (!disable_test[3]) {
        times[3][k] = mysecond();
        for (j = 0; j < N; j++)
          arr2[j] = b[indices[j]];
        upc_fence; 
        times[3][k] = mysecond() - times[3][k];
      }

      /* Stride-n read */
      if (!disable_test[4]) {
        refs[4] = 1 * dim1 * dim2;
        times[4][k] = mysecond();
        for (j = 0; j < dim1; j++)
        {
          for (i = 0; i < dim2; i++)
            arr3[i*dim1+j] = c[i*dim1+j];
        }
        upc_fence; 
        times[4][k] = mysecond() - times[4][k];
      }

      /* Stride-1 set */
      if (!disable_test[5]) {
        times[5][k] = mysecond();
        for (j = 0; j < N; j++)
          a[j] = 1.0 + 5.5;
        upc_fence; 
        times[5][k] = mysecond() - times[5][k];
      }

      /* Random set */
      if (!disable_test[6]) {
        times[6][k] = mysecond();
        for (j = 0; j < N; j++)
          b[indices[j]] = 2.0 + 5.5;
        upc_fence; 
        times[6][k] = mysecond() - times[6][k];
      }

      /* Stride-n set */
      if (!disable_test[7]) {
        refs[7] = 1 * dim1 * dim2;
        times[7][k] = mysecond();
        for (j = 0; j < dim1; j++)
        {
          for (i = 0; i < dim2; i++)
            c[i*dim1+j] = 3.0 + 5.5;
        }
        upc_fence; 
        times[7][k] = mysecond() - times[7][k];
      }
      
      /* Stride-1 copy */
      if (!disable_test[8]) {
        times[8][k] = mysecond();
        for (j = 0; j < N; j++)
          c[j] = a[j];
        upc_fence; 
        times[8][k] = mysecond() - times[8][k];
      }

      /* Random copy */
      if (!disable_test[9]) {
        times[9][k] = mysecond();
        for (j = 0; j < N; j++)
          a[indices[j]] = b[indices[j]];
        upc_fence; 
        times[9][k] = mysecond() - times[9][k];
      }

      /* Stride-n copy */
      if (!disable_test[10]) {
        refs[10] = 2 * dim1 * dim2;
        times[10][k] = mysecond();
        for (j = 0; j < dim1; j++)
        {
          for (i = 0; i < dim2; i++)
            b[i*dim1+j] = c[i*dim1+j];
        }
        upc_fence; 
        times[10][k] = mysecond() - times[10][k];
      }
    } /* if MYTHREAD == th_one */

    upc_barrier k; 
  } /* for k */

    /*	--- SUMMARY --- */

  if (MYTHREAD == th_one) {
    for (k=1; k<NTIMES; k++) /* note -- skip first iteration */
    {
      for (j=0; j<NTESTS; j++)
      {
        if (!disable_test[j]) {
          avgtime[j] = avgtime[j] + times[j][k];
          mintime[j] = MIN(mintime[j], times[j][k]);
          maxtime[j] = MAX(maxtime[j], times[j][k]);
        }
      }
    }

    printf("Function          Rate (Refs/s)   Avg time     Min time     Max time\n");
    for (j=0; j<NTESTS; j++) {
      if (!disable_test[j]) {
        avgtime[j] = avgtime[j]/(double)(NTIMES-1);

        printf("%s%11.0f  %11.4f  %11.4f  %11.4f\n", label[j],
               refs[j]/mintime[j],
               avgtime[j],
               mintime[j],
               maxtime[j]);
      }
    }
    printf(HLINE);
    printf("done\n");
  } /* if MYTHREAD */

  upc_free ((shared void*) sh_a[MYTHREAD]);
  upc_free ((shared void*) sh_b[MYTHREAD]);
  upc_free ((shared void*) sh_c[MYTHREAD]);

  return 0;
}

# define	M	20
int
checktick()
    {
    int		i, minDelta, Delta;
    double	t1, t2, timesfound[M];

/*  Collect a sequence of M unique time values from the system. */

    for (i = 0; i < M; i++) {
	t1 = mysecond();
	while( ((t2=mysecond()) - t1) < 1.0E-6 )
	    ;
	timesfound[i] = t1 = t2;
	}

/*
 * Determine the minimum difference between these M values.
 * This result will be our estimate (in microseconds) for the
 * clock granularity.
 */

    minDelta = 1000000;
    for (i = 1; i < M; i++) {
	Delta = (int)( 1.0E6 * (timesfound[i]-timesfound[i-1]));
	minDelta = MIN(minDelta, MAX(Delta,0));
	}

   return(minDelta);
    }

/* A gettimeofday routine to give access to the wall
   clock timer on most UNIX-like systems.  */

double mysecond()
{
  struct timeval tp;
  /*struct timezone tzp;*/
  volatile int i;

  /*i = gettimeofday(&tp,&tzp);*/
  i = gettimeofday(&tp,NULL);
  return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6 );
}


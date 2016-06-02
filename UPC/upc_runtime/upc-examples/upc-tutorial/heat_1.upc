#include <stdio.h>
#include <math.h>
#include <sys/time.h>
/* UPC Header file */
#include <upc_relaxed.h>

#define N 30

/* ----------------------------------------------------------------- */
/* Complete the grids declarations to be shared and blocked as the 
   biggest chunk of rows */
shared [(N+2)*(N+2)/THREADS] double grid[N+2][N+2], new_grid[N+2][N+2];
/* add a new shared array, in which each thread will maintain its local
   execution time */
shared double runtimes[THREADS];
/* now declare dTmax_local, array of THREADS elements, as shared. This
   variable is used to reduce dTmax across THREADS */
shared double dTmax_local[THREADS];
/* ----------------------------------------------------------------- */

void initialize(void)
{
  int j;

  for( j=1; j<N+2; j++ )
  {
    grid[0][j] = new_grid[0][j] = 1.0;
  }
}

int main(void)
{
  struct timeval ts_st, ts_end;
  /* adapt the declaration of time to be now used to keep the overall
     (max) execution time across THREADS */
  double dTmax, dT, epsilon, max_time;
  int finished, i, j, k, l;
  double T;
  int nr_iter;

/* ----------------------------------------------------------------- */
  /* sequential execution of initialize(), only by THREAD 0 */
  if( MYTHREAD == 0 )
/* ----------------------------------------------------------------- */
    initialize();

  epsilon  = 0.0001;
  finished = 0;
  nr_iter = 0;

/* ----------------------------------------------------------------- */
  /* synchronize to ensure that all threads reached this point */
  upc_barrier;
/* ----------------------------------------------------------------- */

  gettimeofday( &ts_st, NULL );

  do
  {
    dTmax = 0.0;
/* ----------------------------------------------------------------- */
    /* use a upc_forall() to do the work sharing, across the rows and
       following the affinity of the most accessed row of grid[][] */
    upc_forall( i=1; i<N+1; i++; i*THREADS/(N+2) )
/* ----------------------------------------------------------------- */
    {
      for( j=1; j<N+1; j++ )
      {
        T = 0.25 *
            (grid[i+1][j] + grid[i-1][j] +
             grid[i][j-1] + grid[i][j+1]);
        dT = T - grid[i][j];
        new_grid[i][j] = T;
        if( dTmax < fabs(dT) )
          dTmax = fabs(dT);
      }
    }

/* ----------------------------------------------------------------- */
    /* set the value dTmax_local in the current thread to dTmax */
    dTmax_local[MYTHREAD] = dTmax;
    /* synchronize to be sure that everybody has updated dTmax */
    upc_barrier;
    /* reduce to get the max of dTmax - complete the fields of for
       and indices of dTmax_local such that all elements of 
       dTmax_local (0  THREADS-1) are considered */
    dTmax = dTmax_local[0];
    for( j=1; j<THREADS; j++ )
      if( dTmax < dTmax_local[j] )
        dTmax = dTmax_local[j];
/* ----------------------------------------------------------------- */

    if( dTmax < epsilon )
      finished = 1;
    else
      {
/* ----------------------------------------------------------------- */
        /* use a upc_forall() to do worksharing, following the
           affinity of grid[][] and new_grid[][] */
        upc_forall( k=0; k<N+2; k++; k*THREADS/(N+2) )
/* ----------------------------------------------------------------- */
          for( l=0; l<N+2; l++ )
            grid[k][l] = new_grid[k][l];

/* ----------------------------------------------------------------- */
        /* and synchronize to ensure all threads reached this point */
        upc_barrier;
/* ----------------------------------------------------------------- */
      }
    nr_iter++;
  } while( finished == 0 );

  gettimeofday( &ts_end, NULL );

/* ----------------------------------------------------------------- */
  /* compute the local execution time and save it in the shared array,
     at the right place */
  runtimes[MYTHREAD] = ts_end.tv_sec + (ts_end.tv_usec / 1000000.0);
  runtimes[MYTHREAD] -= ts_st.tv_sec + (ts_st.tv_usec / 1000000.0);
/* ----------------------------------------------------------------- */

/* ----------------------------------------------------------------- */
  /* synchronize to ensure all threads reached this point */
  upc_barrier;
/* ----------------------------------------------------------------- */

/* ----------------------------------------------------------------- */
  /* sequential execution, by THREAD 0 */
  if( MYTHREAD == 0 )
  {
    /* reduce execution time  to get the maximal 
       execution time across the THREADS */
    max_time = runtimes[MYTHREAD];
    for( i=1; i<THREADS; i++ )
      if( max_time < runtimes[i] )
        max_time = runtimes[i];
/* ----------------------------------------------------------------- */
    printf("%d iterations in %.3f sec\n", nr_iter,
            max_time );
  }

  printf("done.\n");
  return 0;
}

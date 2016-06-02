#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <upc_relaxed.h>

#define N 30

shared [(N+2)*(N+2)/THREADS] double grid[N+2][N+2];
shared [(N+2)*(N+2)/THREADS] double new_grid[N+2][N+2];
shared double runtimes[THREADS];
shared double dTmax_local[THREADS];
shared [(N+2)*(N+2)/THREADS] double *ptr[N+2], *new_ptr[N+2], *tmp_ptr;

/* ----------------------------------------------------------------- */
/* duplicate the previous pointers, by declaring them private. The size
   of *ptr_priv[] and *new_ptr_priv[] is only the number of "local" 
   rows, not the total number of rows */
#define PRIV_SIZE ((N+2)/THREADS)
double *ptr_priv[PRIV_SIZE], *new_ptr_priv[PRIV_SIZE], *tmp_ptr_priv;
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
  double dTmax, dT, epsilon, max_time;
  int finished, i, j, k, l;
  double T;
  int nr_iter;

  if( MYTHREAD == 0 )
    initialize();

  for( i=0; i<N+2; i++ )
  {
    ptr[i] = &grid[i][0];
    new_ptr[i] = &new_grid[i][0];
  }
/* ----------------------------------------------------------------- */
  /* initialize the pointers ptr_priv[] and ptr_new_priv[] - remember 
     that it is real privatization step, a type casting has to be 
     present. (i.e. priv_var = (double *)&shared_var;) */
  for( i=0; i<PRIV_SIZE; i++ )
  {
    ptr_priv[i] = (double *)&grid[i+(MYTHREAD*PRIV_SIZE)][0];
    new_ptr_priv[i] = (double *)&new_grid[i+(MYTHREAD*PRIV_SIZE)][0];
  }
/* ----------------------------------------------------------------- */

  epsilon  = 0.0001;
  finished = 0;
  nr_iter = 0;

  upc_barrier;

  gettimeofday( &ts_st, NULL );

  do
  {
    dTmax = 0.0;
/* ----------------------------------------------------------------- */
    /* this section has to be changed, to replacing the upc_forall() by 
       3 separate loops (when possible ), as following:
       Note: take in consideration that the 'old' upc_forall() is
       starting from 1 (not 0) and finishing in N (not N-1)*/
    /* processing of the first line in the local chunk */
    if( MYTHREAD != 0 )
/* ----------------------------------------------------------------- */
    {
      i=0;
      for( j=1; j<N+1; j++ )
      {
/* ----------------------------------------------------------------- */
        /* this section has to be changed, to use ptr_priv[][] 
           and new_ptr_priv[][] when possible (it is possible when a
           local-shared access is performed)
           Be sure to compute the right (global) indices for remote
           shared memory accesses */
        T = 0.25 *
            (ptr_priv[i+1][j] + ptr[(MYTHREAD*PRIV_SIZE)-1][j] +
             ptr_priv[i][j-1] + ptr_priv[i][j+1]);
        dT = T - ptr_priv[i][j];
        new_ptr_priv[i][j] = T;
/* ----------------------------------------------------------------- */
        if( dTmax < fabs(dT) )
          dTmax = fabs(dT);
      }
    }

/* ----------------------------------------------------------------- */
    /* processing of the middle part of the local chunk */
    for( i=1; i<PRIV_SIZE-1; i++ )
/* ----------------------------------------------------------------- */
    {
      for( j=1; j<N+1; j++ )
      {
/* ----------------------------------------------------------------- */
        /* this section has to be changed, to use ptr_priv[][] 
           and new_ptr_priv[][] for all accesses, since no boundaries
           here*/
        T = 0.25 *
            (ptr_priv[i+1][j] + ptr_priv[i-1][j] +
             ptr_priv[i][j-1] + ptr_priv[i][j+1]);
        dT = T - ptr_priv[i][j];
        new_ptr_priv[i][j] = T;
/* ----------------------------------------------------------------- */
        if( dTmax < fabs(dT) )
          dTmax = fabs(dT);
      }
    }

/* ----------------------------------------------------------------- */
    /* processing of the last line in the local chunk */
    if( MYTHREAD != THREADS-1 )
/* ----------------------------------------------------------------- */
    {
      for( j=1; j<N+1; j++ )
      {
/* ----------------------------------------------------------------- */
        /* this section has to be changed, to use ptr_priv[][] 
           and new_ptr_priv[][] when possible (it is possible when a
           local-shared access is performed)
           Be sure to compute the right (global) indices for remote
           shared memory accesses */
        T = 0.25 *
            (ptr[(MYTHREAD+1)*PRIV_SIZE][j] + ptr_priv[i-1][j] +
             ptr_priv[i][j-1] + ptr_priv[i][j+1]);
        dT = T - ptr_priv[i][j];
        new_ptr_priv[i][j] = T;
/* ----------------------------------------------------------------- */
        if( dTmax < fabs(dT) )
          dTmax = fabs(dT);
      }
    }

    dTmax_local[MYTHREAD] = dTmax;
    upc_barrier;
    dTmax = dTmax_local[0];
    for( i=1; i<THREADS; i++ )
      if( dTmax < dTmax_local[i] )
        dTmax = dTmax_local[i];
   /* DOB: the next barrier is required to ensure no threads race ahead,
      perform the next iteration and modify their entry in dTmax_local
      before some other threads have read the dTmax_local value for this iteration
      An alternative solution would be to maintain two copies of the dTmax_local
      array and leapfrog between them on each iteration based on iteratio_count % 2
   */
    upc_barrier; 

    if( dTmax < epsilon )
      finished = 1;
    else
      {
        for( k=0; k<N+2; k++ )
        {
          tmp_ptr    = ptr[k];
          ptr[k]     = new_ptr[k];
          new_ptr[k] = tmp_ptr;
        }
/* ----------------------------------------------------------------- */
        /* here swap the pointers ptr_priv[] and new_ptr_priv[] 
           Note: a private pivot pointer has to be declared */
        for( k=0; k<PRIV_SIZE; k++ )
        {
          tmp_ptr_priv    = ptr_priv[k];
          ptr_priv[k]     = new_ptr_priv[k];
          new_ptr_priv[k] = tmp_ptr_priv;
        }
/* ----------------------------------------------------------------- */
      }
    nr_iter++;
  } while( finished == 0 );

  gettimeofday( &ts_end, NULL );

  runtimes[MYTHREAD] = ts_end.tv_sec + (ts_end.tv_usec / 1000000.0);
  runtimes[MYTHREAD] -= ts_st.tv_sec + (ts_st.tv_usec / 1000000.0);

  upc_barrier;

  if( MYTHREAD == 0 )
  {
    max_time = runtimes[MYTHREAD];
    for( i=1; i<THREADS; i++ )
      if( max_time < runtimes[i] )
        max_time = runtimes[i];
    printf("%d iterations in %.3f sec\n", nr_iter,
            max_time );
  }

  printf("done.\n");
  return 0;
}

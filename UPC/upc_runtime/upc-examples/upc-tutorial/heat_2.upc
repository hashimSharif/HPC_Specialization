#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <upc_relaxed.h>

#define N 30

shared [(N+2)*(N+2)/THREADS] double grid[N+2][N+2];
shared [(N+2)*(N+2)/THREADS] double new_grid[N+2][N+2];
shared double runtimes[THREADS];
shared double dTmax_local[THREADS];

/* ----------------------------------------------------------------- */
/* Declare two new arrays of shared pointers, having same block sizes as grid[][] and new_grid[][] - The dimension of each pointer can be only N+2 since each pointer only needs to point to the beginning of each row of grid[][] or new_grid[][].
A single shared pointer can also be declared for temporary use in the pointer swapping operation (we mean by shared arrays of pointers here private arrays of pointers, each element pointing to a shared area)*/
shared [(N+2)*(N+2)/THREADS] double *ptr[N+2], *new_ptr[N+2], *tmp_ptr;
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

/* ----------------------------------------------------------------- */
  /* The next for loop is to initialize the pointers ptr[] and 
     ptr_new[] */
  for( i=0; i<N+2; i++ )
  {
    ptr[i] = &grid[i][0];
    new_ptr[i] = &new_grid[i][0];
  }
/* ----------------------------------------------------------------- */

#if 0
  epsilon  = 0.0001;
#else
/* DOB: speed up convergeance for test suite */
  epsilon  = 0.01;
#endif

  finished = 0;
  nr_iter = 0;

  upc_barrier;

  gettimeofday( &ts_st, NULL );

  do
  {
    dTmax = 0.0;
    upc_forall( i=1; i<N+1; i++; i*THREADS/(N+2) )
    {
      for( j=1; j<N+1; j++ )
      {
/* ----------------------------------------------------------------- */
        /* this section has to be changed, to use ptr[][] 
           and new_ptr[][] */
        T = 0.25 *
            (ptr[i+1][j] + ptr[i-1][j] +
             ptr[i][j-1] + ptr[i][j+1]);
        dT = T - ptr[i][j];
        new_ptr[i][j] = T;
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
/* ----------------------------------------------------------------- */
        /* here swap the pointers ptr[] and new_ptr[] thru tmp_ptr
           Note: a shared pivot pointer has to be declared */
        for( k=0; k<N+2; k++ )
        {
          tmp_ptr    = ptr[k];
          ptr[k]     = new_ptr[k];
          new_ptr[k] = tmp_ptr;
        }
/* ----------------------------------------------------------------- */

        /* the barrier can be removed here since each thread has its
           own private pointers to grid[][] and new_grid[][] whereas
           the previous case we wanted to wait till copying 
           new_grid[][] to grid[][] is completed by all threads */ 
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

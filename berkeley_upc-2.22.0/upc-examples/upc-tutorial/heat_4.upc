#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <upc_relaxed.h>
/* add stdlib.h (for malloc) */
#include <stdlib.h>

/* N has to be removed here */

shared double runtimes[THREADS];
shared double dTmax_local[THREADS];

/* ----------------------------------------------------------------- */
/* Since N is unknown at compile time, no blocking factor can be    
   expressed. One solution is to declare a structure in which the local
   shared data of each thread will be allocated. The blocking factor of
   such structure is known, and equals 1. This structure, declared as
   shared, is used for grid[] and new_grid[] */
shared struct {
  shared [] double *local;
} grid[THREADS], new_grid[THREADS];
/* All pointer tables need to be declared, without any dependencies to
   N. The memory allocation for ptr and tmp_ptr will be done in the
   main() */
shared [] double **ptr, **new_ptr, *tmp_ptr;
/* ----------------------------------------------------------------- */
double **ptr_priv, **new_ptr_priv, *tmp_ptr_priv;
/* To make our life easier, let us define N and PRIV_SIZE, for later */
int N, PRIV_SIZE;

void initialize(void)
{
  int i, j;

/* ----------------------------------------------------------------- */
  /* to be changed to use new_ptr[][] and ptr[][] instead of grid[][] 
     and new_grid[][] 
     The data grid must be initialized (to 0) */
  for( i=0; i<N+2; i++ )
    for( j=0; j<N+2; j++ )
      new_ptr[i][j] = ptr[i][j] = 0.0;

  for( j=1; j<N+2; j++ )
  {
    ptr[0][j] = new_ptr[0][j] = 1.0;
/* ----------------------------------------------------------------- */
  }
}

/* We need to get the command-line arguments */
int main(int argc, char **argv)
{
  struct timeval ts_st, ts_end;
  double dTmax, dT, epsilon, max_time;
  int finished, i, j, k, l;
  double T;
  int nr_iter;

  /* test if !=1 argument (other than program name) then error */
  if( argc > 2 )
  {
    if( MYTHREAD == 0 ) printf("Usage: %s [N]\n", argv[0]);
    upc_global_exit(0);
  }

  if (argc == 2) {
  /* get N and compute PRIV_SIZE */
  sscanf( argv[1], "%d", &N );
  } else N = (100*THREADS)-2;
  if( (N+2)%THREADS != 0 )
  {
    if( MYTHREAD == 0 ) printf("(N+2)%%THREADS must be == 0\n");
    upc_global_exit(0);
  }
  PRIV_SIZE = (N+2)/THREADS;

/* ----------------------------------------------------------------- */
  /* memory allocation of grid[MYTHREAD].local[] and
     new_grid[MYTHREAD].local[] */
  grid[MYTHREAD].local = (shared [] double *) upc_alloc(
      PRIV_SIZE * (N+2) * sizeof( double ));
  if( grid[MYTHREAD].local == NULL )
/* ----------------------------------------------------------------- */
  {
    printf("TH%02d: grid[MYTHREAD].local == NULL\n", MYTHREAD );
    upc_global_exit(0);
  }

/* ----------------------------------------------------------------- */
  new_grid[MYTHREAD].local = (shared [] double *) upc_alloc(
      PRIV_SIZE * (N+2) * sizeof( double ));
  if( new_grid[MYTHREAD].local == NULL )
/* ----------------------------------------------------------------- */
  {
    printf("TH%02d: grid[MYTHREAD].local == NULL\n", MYTHREAD );
    upc_global_exit(0);
  }

  /* memory allocation of *ptr[] and *new_ptr[] */
/* ----------------------------------------------------------------- */
  ptr = (shared [] double **) upc_alloc(
      (N+2) * sizeof( shared [] double * ));
/* ----------------------------------------------------------------- */

  if( ptr == NULL )
  {
    printf("TH%02d: ptr == NULL\n", MYTHREAD );
    upc_global_exit(0);
  }

/* ----------------------------------------------------------------- */
  new_ptr = (shared [] double **) upc_alloc(
      (N+2) * sizeof( shared [] double * ));
/* ----------------------------------------------------------------- */

  if( new_ptr == NULL )
  {
    printf("TH%02d: new_ptr == NULL\n", MYTHREAD );
    upc_global_exit(0);
  }

  /* memory allocation of *ptr_priv[] and *new_ptr_priv[] */
/* ----------------------------------------------------------------- */
  ptr_priv = (double **) malloc( PRIV_SIZE * sizeof( double * ));
/* ----------------------------------------------------------------- */

  if( ptr_priv == NULL )
  {
    printf("TH%02d: ptr_priv == NULL\n", MYTHREAD );
    upc_global_exit(0);
  }

/* ----------------------------------------------------------------- */
  new_ptr_priv = (double **) malloc( PRIV_SIZE * sizeof( double * ));
/* ----------------------------------------------------------------- */

  if( new_ptr_priv == NULL )
  {
    printf("TH%02d: new_ptr_priv == NULL\n", MYTHREAD );
    upc_global_exit(0);
  }

  /* add a synchronization barrier, to be sure that all threads have
     Allocated their buffers */
  upc_barrier;

  /* notice initialize() has been moved after the pointer
     Initializations, so it can use them */

/* ----------------------------------------------------------------- */
  /* change the pointer initialization expressions to use the new
     format of grid[].local[] and new_grid[].local[] */
  for( i=0; i<N+2; i++ )
  {
    ptr[i] = &grid[i/PRIV_SIZE].local[(i%PRIV_SIZE)*(N+2)];
    new_ptr[i] = &new_grid[i/PRIV_SIZE].local[(i%PRIV_SIZE)*(N+2)];
  }
  for( i=0; i<PRIV_SIZE; i++ )
  {
    ptr_priv[i] = (double *)&grid[MYTHREAD].local[i*(N+2)];
    new_ptr_priv[i] = (double *)&new_grid[MYTHREAD].local[i*(N+2)];
  }
/* ----------------------------------------------------------------- */

  /* change initialize() to use ptr[][] and new_ptr[][] instead of
     grid[][] and new_grid[][] */
  if( MYTHREAD == 0 )
    initialize();

  epsilon  = 0.0001;
  finished = 0;
  nr_iter = 0;

  upc_barrier;

  gettimeofday( &ts_st, NULL );

  do
  {
    dTmax = 0.0;
    if( MYTHREAD != 0 )
    {
      i=0;
      for( j=1; j<N+1; j++ )
      {
        T = 0.25 *
            (ptr_priv[i+1][j] + ptr[(MYTHREAD*PRIV_SIZE)-1][j] +
             ptr_priv[i][j-1] + ptr_priv[i][j+1]);
        dT = T - ptr_priv[i][j];
        new_ptr_priv[i][j] = T;
        if( dTmax < fabs(dT) )
          dTmax = fabs(dT);
      }
    }

    for( i=1; i<PRIV_SIZE-1; i++ )
    {
      for( j=1; j<N+1; j++ )
      {
        T = 0.25 *
            (ptr_priv[i+1][j] + ptr_priv[i-1][j] +
             ptr_priv[i][j-1] + ptr_priv[i][j+1]);
        dT = T - ptr_priv[i][j];
        new_ptr_priv[i][j] = T;
        if( dTmax < fabs(dT) )
          dTmax = fabs(dT);
      }
    }

    if( MYTHREAD != THREADS-1 )
    {
      for( j=1; j<N+1; j++ )
      {
        T = 0.25 *
            (ptr[(MYTHREAD+1)*PRIV_SIZE][j] + ptr_priv[i-1][j] +
             ptr_priv[i][j-1] + ptr_priv[i][j+1]);
        dT = T - ptr_priv[i][j];
        new_ptr_priv[i][j] = T;
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
        for( k=0; k<PRIV_SIZE; k++ )
        {
          tmp_ptr_priv    = ptr_priv[k];
          ptr_priv[k]     = new_ptr_priv[k];
          new_ptr_priv[k] = tmp_ptr_priv;
        }
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

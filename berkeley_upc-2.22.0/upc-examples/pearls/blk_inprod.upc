/* Same as inprod.c except that we block the arrays. */

#include <stdio.h>
#include <math.h>
#include <upc_relaxed.h>

#define NperTHREAD 100
#define SIZE  (NperTHREAD * THREADS)
#define BLOCK  NperTHREAD

shared float inprod;
shared [BLOCK] float x[SIZE], y[SIZE];

upc_lock_t *flag;

int main ()
{
  int i;
  float mysum = 0.0f;
  flag = upc_all_lock_alloc();

  upc_forall( i=0; i< SIZE; i++; &x[i] ){
      x[i] =  sqrt( (float) i );
      y[i] = x[i];
  }
  upc_barrier;
  
  upc_forall( i=0; i< SIZE; i++; &x[i] )
      mysum += x[i] * y[i];

  printf ("Thread %2d of %d holds %g\n", MYTHREAD, THREADS, mysum);

  upc_lock(flag);
  inprod = inprod + mysum;
  upc_unlock(flag);

  upc_barrier;

  if( MYTHREAD == 0 )
    printf("Dot product is  %g\n", inprod);
  printf("done.\n");
  return 0;
}

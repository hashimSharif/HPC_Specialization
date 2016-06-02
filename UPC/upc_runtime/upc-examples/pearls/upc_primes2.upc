//
//   -- All the integers start out positive
//   -- We have thread 0 find the next sieve 
//   -- Once the sieve is determined,  
//        all threads use the sieve to zero out 
//        the multiples that they own
//   
//   Note: If THREADS is even, 
//         the affinity issues here are pretty bad
//

#include <stdio.h>
#include <upc_relaxed.h>

#define SqrtN 10
#define MaxN (SqrtN*SqrtN)

shared int z[MaxN];
shared int sieve;

int main ()
{
  int i;

  upc_forall( i=2; i< MaxN; i++; &z[i] )
      z[i] =  i;

  upc_barrier;

  sieve = 1;
  while(1){
    if( MYTHREAD == 0 ) {    // find the sieve prime
       for( i=sieve+1; i<SqrtN; i++){
          if( z[i] > 0 ) {   // found it 
             sieve = z[i];
             break;
          }
       }
       if( i >= SqrtN )  // we are done
         sieve = 0;
    }
    upc_barrier;  // everybody waits for the new sieve
    if( sieve == 0 ) 
       break;

    // here is the parallel part
    upc_forall( i = 2*sieve; sieve && i<MaxN; i += sieve ; &z[i])
      z[i] = 0;
    upc_barrier;

  }

  if( MYTHREAD == 0 )
    for(i=2; i<MaxN; i++) {
      if( z[i] != 0 )
         printf("%d\n", z[i]);
    }
  upc_barrier;
  printf("done.\n");
  return 0;
}



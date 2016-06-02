// The Plan:  
//   -- All the integers start out positive
//  All the threads loop through the following steps
//   - get the lock on the critical section to find its sieve prime
//     A candidate sieve prime is anything not yet zeroed out
//     - Check that it is, in fact, a prime and then set it to 
//         its negative so that the other threads looking 
//         for a candidate will skip it.
//   - Release the lock and zero out multiples of the sieve
//
// Note: This demo is about locks and sharing work,  we don't
//       worry at all about affinity 
//       Thinking about affinity issues in this case is interesting
//        because of the distribution of primes.

#include <stdio.h>
#include <upc_strict.h>

#define MaxN 100
#define SqrtN 10
shared int z[MaxN];

upc_lock_t *flag;

int main ()
{
  int i, j;
  int sieve;

  flag = upc_all_lock_alloc();

  upc_forall( i=2; i< MaxN; i++; &z[i] )
      z[i] =  i;
  upc_barrier(1);

  do {
    // find my sieve prime
    upc_lock(flag);
      sieve = 0;
      for( i=2; i<SqrtN; i++){
         sieve = z[i];
         if( sieve > 0 ) {  // found next candidate
            for ( j=i-1; j>1 ; j-- )
                if( z[j] < 0 ) {  // check against this prime
                   if( sieve % z[j] == 0 ){ // somebody hasn't got here yet
                                  // this works even with (z[j] < 0) 
                      sieve = 0;   // indicator to keep looking
                      break;
                   } 
                } 
                if( sieve > 0 ) { // found one
                    printf("%d: sieve is %d\n", MYTHREAD, sieve);
                    z[i] = -1 * z[i];
                    break;
                }
         }
      }
    upc_unlock(flag);

    for( i = 2*sieve; sieve && i<MaxN; i += sieve )
      z[i] = 0;

  } while( sieve );

  upc_barrier(2);

  if( MYTHREAD == 0 )
    for(i=2; i<MaxN; i++) {
      if( z[i] != 0 )
         printf("%d\n", z[i]);
    }

  upc_barrier(3);

  printf("done.\n");
  return 0;
}



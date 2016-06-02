#include <stdio.h>
#include <upc_relaxed.h>

#define N 30

int main(void)
{
  int finished=1, i, k;
  int nr_iter = 0;
  int cnt=0;
  do {
    upc_forall( i=1; i<N+1; i++; i*THREADS/(N+2) ) {
    }

    for( k=0; k<N+2; k++ ) {
     cnt++;
    }
    nr_iter++;
  } while( finished == 0 );
  if (nr_iter != 1) printf("ERROR on %s:%i\n",__FILE__,__LINE__);
  if (cnt != N+2) printf("ERROR on %s:%i\n",__FILE__,__LINE__);
  printf("done.\n");
  return 0;
}

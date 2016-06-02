#include <stdio.h>
#include <upc_strict.h>


#define NPP 4
#define N (NPP*THREADS)
#define NT 2


shared double r[NPP*THREADS];
shared double v[NPP*THREADS];
shared double a[NPP*THREADS];


int
main(void)
{
  int i, j, it;
  int sum = 0;
  
  for (it=0; it<1; it++) { 
    upc_forall(i=0; i<N; i++; i) {
      r[i] = r[i] + v[i]; 
    }
    
    for (i=0; i<=10; i++) {
      printf("In %d i=%d\n", MYTHREAD, i);
      sum += i;
    } 
    
    for (j=0; j<=10; j++) {
      printf("In %d j=%d\n", MYTHREAD, j);
      sum += j;
    } 
  } 
  upc_barrier;
  if (sum != 110) printf("ERROR on THREAD %i, sum= %i\n",MYTHREAD, sum);
  else printf("SUCCESS\n");
  return 0;
}

#include <upc.h>
#include <stdio.h>
#include "bug41a.uph"
#include "bug41b.h"
#include "bug41c.h"

/* a,c,d,f are shared ints */
/* b,e are C-mode ints */
/* g,h,i,j are UPC-mode thread-local ints */

int main() {
  if (a != 10 || upc_threadof(&a) != 0) printf("ERROR on %i\n", __LINE__);
  if (c != 30 || upc_threadof(&c) != 0) printf("ERROR on %i\n", __LINE__);
  if (d != 40 || upc_threadof(&d) != 0) printf("ERROR on %i\n", __LINE__);
  if (f != 60 || upc_threadof(&f) != 0) printf("ERROR on %i\n", __LINE__);

  if (b != 20) printf("ERROR on %i\n", __LINE__); 
  if (e != 50) printf("ERROR on %i\n", __LINE__); 

  if (g != 70 ) printf("ERROR on %i\n", __LINE__);
  if (h != 80 ) printf("ERROR on %i\n", __LINE__);
  if (i != 90 ) printf("ERROR on %i\n", __LINE__);
  if (j != 100) printf("ERROR on %i\n", __LINE__);


  upc_barrier;

  if (MYTHREAD == 0) {
    a *= 10;
    c *= 10;
    d *= 10;
    f *= 10;
  }

  b *= MYTHREAD; 
  e *= MYTHREAD;  

  g *= MYTHREAD;
  h *= MYTHREAD;
  i *= MYTHREAD;
  j *= MYTHREAD;
 
  upc_barrier;
 
  if (a != 100 ) printf("ERROR on %i\n", __LINE__);
  if (c != 300 ) printf("ERROR on %i\n", __LINE__);
  if (d != 400 ) printf("ERROR on %i\n", __LINE__);
  if (f != 600 ) printf("ERROR on %i\n", __LINE__);

#if !defined(__BERKELEY_UPC_PTHREADS__) \
    && !defined(__UPC_PTHREADS_MODEL_TLS__)
  if (b != 20*MYTHREAD) printf("ERROR on %i\n", __LINE__); /* may fail with pthreads */
  if (e != 50*MYTHREAD) printf("ERROR on %i\n", __LINE__); /* may fail with pthreads */
#endif

  if (g != 70*MYTHREAD) printf("ERROR on %i\n", __LINE__);
  if (h != 80*MYTHREAD) printf("ERROR on %i\n", __LINE__);
  if (i != 90*MYTHREAD) printf("ERROR on %i\n", __LINE__);
  if (j != 100*MYTHREAD) printf("ERROR on %i\n", __LINE__);

  upc_barrier;

  printf("done.\n");

  return 0;
}

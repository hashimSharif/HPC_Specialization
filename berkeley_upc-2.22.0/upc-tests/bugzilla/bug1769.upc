#include <upc.h>
#include <stdio.h>
#include <assert.h>

shared [1] int x[THREADS];
#if __BERKELEY_UPC__
void *upcr_shared_to_processlocal(shared void *);
#endif

int main() {
#if __BERKELEY_UPC__
  void *p = upcr_shared_to_processlocal(&(x[MYTHREAD]));
  printf("%i: %p\n",MYTHREAD,p);
  assert((void *)&(x[MYTHREAD]) == p);
  upc_barrier;
  #ifdef TEST_ERR
  { int peer = (MYTHREAD+1)%THREADS;
    void *p = upcr_shared_to_processlocal(&(x[peer])); 
    printf("%i: %p\n",peer,p);
  }
  #endif
#endif
  printf("done.\n");
}

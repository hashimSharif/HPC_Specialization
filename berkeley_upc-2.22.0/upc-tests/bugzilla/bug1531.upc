#include <upc.h>
#include <unistd.h>
#include <stdio.h>

strict shared int cnt;

int main() {
  int me = -1;
  upc_lock_t *l;

  if (MYTHREAD == 0) {
    cnt = 0;
  }
  l = upc_all_lock_alloc();
  upc_barrier;
  
  int done = 0;
  while (!done) {
    upc_lock(l);
    if (cnt == (THREADS * 5)) {
      done = 1;
    } else {
      me = cnt++;
    }
    upc_unlock(l);
    /* !!!!!!! */
#ifdef USE_POLL
    bupc_poll();
#endif

    if (!done) {
      fprintf(stderr, "%d doing %d\n", MYTHREAD, me);
      sleep(1);
    }  
  }
  /* fairness check - upc locks do *not* guarantee fairness, but 
   * given the sleeps above I really should have acquired at least once */
  if (me == -1) printf("ERROR: thread %i never got the lock\n",MYTHREAD);
  printf("done.\n");
  return 0;
}


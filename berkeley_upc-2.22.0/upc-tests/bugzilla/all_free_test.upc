#include <upc.h>
#include <stdio.h>

/* Until these extensions are in the spec: */
#if defined __BERKELEY_UPC_RUNTIME__
  // In 2.16.0 and later
#elif defined _CRAYC
  #include <upc_cray.h>
#else
  /* Add more compilers here as needed */
#endif

#define ITERS 1000

shared int fail = 0;
shared int counter = 0;

int main(void) {
  // Dynamically allocated cyclic arrays of pointers to shared int(s):
  shared int * shared *pArray = upc_all_alloc(ITERS, sizeof(shared void *));
  shared int * shared *qArray = upc_all_alloc(ITERS, sizeof(shared void *));

  // Dynamically allocared cyclic array of pointers to upc_lock_t
  upc_lock_t * shared *lArray = upc_all_alloc(ITERS, sizeof(upc_lock_t *));


  // Check the non-collective allocation cases:
  upc_forall ( int i = 0; i < ITERS; ++i; i ) {
    pArray[i] = upc_alloc(sizeof(int));
    qArray[i] = upc_global_alloc(THREADS, sizeof(int));
    lArray[i] = upc_global_lock_alloc();
  }
  upc_barrier; // to ensure allocations have completed
  for ( int i = 0; i < ITERS; ++i ) {
    if ((i % THREADS == MYTHREAD)) *pArray[i] = MYTHREAD;
    upc_all_free(pArray[i]);

    qArray[i][MYTHREAD] = MYTHREAD;
    upc_all_free(qArray[i]);

    if (upc_lock_attempt(lArray[i])) upc_unlock(lArray[i]);
    upc_all_lock_free(lArray[i]);
  }


  // Use upc_all_free() to release our temporaries, too.
  upc_all_free(pArray);
  upc_all_free(qArray);
  upc_all_free(lArray);


  // Check the corner cases:
  upc_all_free(NULL);
  upc_all_lock_free(NULL);


  // Check the collective-allocation cases:
  for ( int i = 0; i < ITERS; ++i ) {
    shared int *p = upc_all_alloc(THREADS, sizeof(int));
    upc_forall ( int j = 0; j < THREADS; ++j; j) {
      p[j] = MYTHREAD;
    }
    int my_fail = (p[MYTHREAD] != MYTHREAD); // any access to p
    upc_all_free(p);

    upc_lock_t *lp = upc_all_lock_alloc();
    upc_lock(lp);
      counter += MYTHREAD;
      fail |= my_fail;
    upc_unlock(lp);
    if (upc_lock_attempt(lp)) upc_unlock(lp); // an "extra" access to lp
    upc_all_lock_free(lp);
  }
  if (0 == MYTHREAD) {
    /* No barrier is impllied by upc_all_lock_free().
       However, the following holds since all the lock acquisions completed. */
    if (counter != (int)(ITERS * (THREADS * (THREADS - 1)) / 2)) fail = 1;
    puts ( fail ? "FAIL" : "PASS" );
  }


  return !!fail;
}

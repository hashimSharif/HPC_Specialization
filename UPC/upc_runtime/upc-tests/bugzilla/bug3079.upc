#include <upc.h>
#include <upc_castable.h>
#include <stdio.h>

shared int X[THREADS];

int main(void) {
  shared int *A = upc_all_alloc(THREADS*THREADS, sizeof(int));
  shared int *p;
  int i,th;

  for (th=0; th<THREADS; ++th) {
    if (th == MYTHREAD) { // Orderly output
      // Dynamic local-heap allocation (inverse cast must fail)
      int *s = malloc(sizeof(int));
      p = bupc_inverse_cast(s);
      free(s);
      printf("th%d sees private %p p=(%d,%p) %s\n", th, s,
             (int)upc_threadof(p), (void *)(uintptr_t)upc_addrfield(p), 
             (p==NULL)?"PASS":"FAIL");

      // Dynamic shared-heap from upc_alloc() (inverse cast must pass)
      #define N 4
      #define M 100
      shared int *B[N];
      for (i=0; i<N; ++i) {
        shared int *q = B[i] = upc_alloc(M * sizeof(int));
        if (upc_cast(q)) {
          p = bupc_inverse_cast(upc_cast(q));
          printf("th%d sees B[%d]=(%d,%p) p=(%d,%p) %s\n", MYTHREAD, i,
                 (int)upc_threadof(q), (void *)(uintptr_t)upc_addrfield(q),
                 (int)upc_threadof(p), (void *)(uintptr_t)upc_addrfield(p),
                 (p==q)?"PASS":"FAIL");
        } else {
          printf("th%d sees B[%d]=(%d,%p) as remote - FAIL\n", MYTHREAD, i,
                 (int)upc_threadof(q), (void *)(uintptr_t)upc_addrfield(q));
        }
      }
      for (i=0; i<N; ++i) upc_free(B[i]);

      // Dynamic shared-heap from upc_all_alloc() (inverse cast must pass if local)
      for (i=0; i<THREADS; ++i) {
        int idx = i*(THREADS+1);
        shared int *q = &A[idx];
        if (upc_cast(q)) {
          p = bupc_inverse_cast(upc_cast(q));
          printf("th%d sees &A[%d]=(%d,%p) p=(%d,%p) %s\n", MYTHREAD, idx,
                 (int)upc_threadof(q), (void *)(uintptr_t)upc_addrfield(q),
                 (int)upc_threadof(p), (void *)(uintptr_t)upc_addrfield(p),
                 (p==q)?"PASS":"FAIL");
        } else if (bupc_thread_distance(MYTHREAD, upc_threadof(q)) <= BUPC_THREADS_VERYNEAR) {
          printf("th%d sees &A[%d]=(%d,%p) as remote - FAIL\n", MYTHREAD, idx,
                 (int)upc_threadof(q), (void *)(uintptr_t)upc_addrfield(q));
        }
      }

      // Static shared-heap array (inverse cast must pass if local)
      for (i=0; i<THREADS; ++i) {
        int idx = i;
        shared int *q = &X[idx];
        if (upc_cast(q)) {
          p = bupc_inverse_cast(upc_cast(q));
          printf("th%d sees &X[%d]=(%d,%p) p=(%d,%p) %s\n", MYTHREAD, idx,
                 (int)upc_threadof(q), (void *)(uintptr_t)upc_addrfield(q),
                 (int)upc_threadof(p), (void *)(uintptr_t)upc_addrfield(p),
                 (p==q)?"PASS":"FAIL");
        } else if (bupc_thread_distance(MYTHREAD, upc_threadof(q)) <= BUPC_THREADS_VERYNEAR) {
          printf("th%d sees &X[%d]=(%d,%p) as remote - FAIL\n", MYTHREAD, idx,
                 (int)upc_threadof(q), (void *)(uintptr_t)upc_addrfield(q));
        }
      }

      fflush(stdout);
    }
    upc_barrier;
  }

  if (!MYTHREAD) puts("done.");

  return 0;
}

#include <upc.h>
#include <stdio.h>

int main(void) {
  shared void *p, *q;
  upc_lock_t *lock;

  p = upc_global_alloc(1, sizeof(int));
  printf("Thread %d completed upc_global_alloc() call\n", MYTHREAD);

  q = upc_all_alloc(THREADS, sizeof(int));
  printf("Thread %d completed upc_all_alloc() call\n", MYTHREAD);

  upc_barrier;

  upc_free(p);
  if (!MYTHREAD) upc_free(q);

  if (!MYTHREAD) printf("PASS\n");

  return 0;
}

#include <upc.h>
#include <stdio.h>

int main(void) {
  shared void *p;
  upc_lock_t *lock;

  p = upc_global_alloc(1, sizeof(int));
  printf("Thread %d completed upc_global_alloc() call\n", MYTHREAD);

  lock = upc_all_lock_alloc();
  printf("Thread %d completed upc_all_lock_alloc() call\n", MYTHREAD);

  upc_barrier;

  upc_free(p);
  if (!MYTHREAD) upc_lock_free(lock);

  if (!MYTHREAD) printf("PASS\n");

  return 0;
}

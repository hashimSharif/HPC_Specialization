#include <upc.h>
#include <upc_atomic.h>
#include <stdio.h>

shared int sum = 0;

int main() {
  upc_atomicdomain_t *dom = upc_all_atomicdomain_alloc(UPC_INT, UPC_ADD, 0);

  int val = 1;
  int fetch;
  upc_atomic_relaxed(dom, &fetch, UPC_ADD, &sum, &val, 0);

  printf("%i: %i\n",MYTHREAD, fetch);
  if (fetch < 0 || fetch >= THREADS) printf("ERROR\n");

  upc_barrier;
  if (!MYTHREAD) { 
    printf("Result: %i\n", sum);
    if (sum == THREADS) {
      printf("SUCCESS\n");
    } else {
      printf("FAILED\n");
    }
  }
  upc_all_atomicdomain_free(dom);
  return 0;
}

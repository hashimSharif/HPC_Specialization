#include <upc.h>
#include <stdio.h>

#define EQUAL(t1,t2) do { \
  if (!bupc_assert_type(t1,t2)) { \
    fprintf(stderr,"ERROR line %i: types mismatched: (%s) != (%s)\n", \
        __LINE__,#t1, #t2); \
    fail = 1; \
   } \
  } while (0)

shared int fail = 0;

int main(void) {
  EQUAL(size_t, upc_blocksizeof(shared     int [THREADS]));
  EQUAL(size_t, upc_blocksizeof(shared [1] int [THREADS]));
  EQUAL(size_t, upc_blocksizeof(shared [2] int [2*THREADS]));
  EQUAL(size_t, upc_blocksizeof(shared []  int [10]));

  upc_barrier;

  if (!MYTHREAD) puts(fail ? "FAIL" : "PASS");
  return fail;
}

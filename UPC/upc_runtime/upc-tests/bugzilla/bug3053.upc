#include <upc.h>
#include <upc_collective.h>
#include <stdio.h>

#define SIZE 100
static shared [0] int SRC0[SIZE], DST0[SIZE];
static shared [1] int SRC1[SIZE], DST1[SIZE];
static shared [2] int SRC2[SIZE], DST2[SIZE];
static shared [3] int SRC3[SIZE], DST3[SIZE];
static shared     int D[THREADS];

static int mysum(int a, int b) { return a + b; }

int main(void)
{
  shared void *srcs[] = {(shared void*)SRC0, (shared void*)SRC1,
                         (shared void*)SRC2, (shared void*)SRC3};
  shared void *dsts[] = {(shared void*)DST0, (shared void*)DST1,
                         (shared void*)DST2, (shared void*)DST3};

  for (int bs = 0; bs < 4; ++bs) {
    if (MYTHREAD == 0) {
      printf("Testing block size %d\n", bs);
      fflush(stdout);
    }

    shared void * src = srcs[bs];
    shared void * dst = dsts[bs];
    upc_all_reduceI(D, src, UPC_ADD, SIZE, bs, NULL, 0);
    upc_all_reduceI(D, src, UPC_FUNC, SIZE, bs, &mysum, 0);
    upc_all_reduceI(D, src, UPC_NONCOMM_FUNC, SIZE, bs, &mysum, 0);
    upc_all_prefix_reduceI(dst, src, UPC_ADD, SIZE, bs, NULL, 0);
    upc_all_prefix_reduceI(dst, src, UPC_FUNC, SIZE, bs, &mysum, 0);
    upc_all_prefix_reduceI(dst, src, UPC_NONCOMM_FUNC, SIZE, bs, &mysum, 0);
#ifdef __BERKELEY_UPC_RUNTIME__
    bupc_all_reduce_allI(&D, src, UPC_ADD, SIZE, bs, NULL, 0);
    bupc_all_reduce_allI(&D, src, UPC_FUNC, SIZE, bs, &mysum, 0);
    bupc_all_reduce_allI(&D, src, UPC_NONCOMM_FUNC, SIZE, bs, &mysum, 0);
#endif
  }

  upc_barrier;
  if (MYTHREAD == 0) {
    puts("PASS");
    fflush(stdout);
  }
  upc_barrier;

  return 0;
}

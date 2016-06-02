#include <upc_relaxed.h>
#include <upc_tick.h>
#include <inttypes.h>
#include <stdio.h>

shared uint64_t X = 0;


void test(int threads, int iters, upc_lock_t *L) {
  int i;
  upc_tick_t T1, T2;

  for (i = 0; i < 10; ++i) {
    bupc_atomicU64_fetchadd_relaxed(&X, 1); /* warmup */
  }

  upc_barrier;
  T1 = upc_ticks_now();
  if (MYTHREAD < threads) {
    for (i = 0; i < iters; ++i) {
      bupc_atomicU64_fetchadd_relaxed(&X, 1);
    }
  }
  upc_barrier;
  T1 = upc_ticks_now() - T1;


  for (i = 0; i < 10; ++i) {
    upc_lock(L); X += 1; upc_unlock(L); /* warmup */
  }

  upc_barrier;
  T2 = upc_ticks_now();
  if (MYTHREAD < threads) {
    for (i = 0; i < iters; ++i) {
      upc_lock(L); X += 1; upc_unlock(L);
    }
  }
  upc_barrier;
  T2 = upc_ticks_now() - T2;

  if (!MYTHREAD) printf("%i\t%g\t%g\n", threads, (1e3*iters)/upc_ticks_to_ns(T1), (1e3*iters)/upc_ticks_to_ns(T2));
}

int main(int argc, char **argv) {
  upc_lock_t *L;
  int iters = 100;
  int i;

  if (argc > 1) {
    iters = atoi(argv[1]);
  }
  L = upc_all_lock_alloc();

  if (!MYTHREAD) printf("Update rate in Mop/s/thread\nTHREADS\tAMOs\tLOCKs\n");
  for (i = 1; i <= THREADS; ++i) test(i, iters, L);

  if (!MYTHREAD) printf("done.\n");
  upc_barrier;

  return 0;
}

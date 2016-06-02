#include <stdio.h>
#ifdef USE_RELAXED
#include <upc_relaxed.h>
#else
#include <upc_strict.h>
#endif

#ifndef DTYPE
#define DTYPE float
#endif

shared DTYPE a;


int main() {
    DTYPE b = 1.0 + MYTHREAD;
    DTYPE expect = 0.0;

    printf("TH%d: a = %.2f b = %.2f\n", MYTHREAD, a, b);
    upc_barrier;

  for (int i=0; i < THREADS; i++) {
    DTYPE tmp = 1.0 + i;
    expect += tmp;
    upc_barrier i;
    if (i == MYTHREAD) {
      DTYPE x = a;
      printf("TH%d: a = %.2f b = %.2f x_pre=%.2f\n", MYTHREAD, a, b, x);
      x += b;
      printf("TH%d: a = %.2f b = %.2f x_post=%.2f\n", MYTHREAD, a, b, x);
      a = x;
      printf("TH%d: a = %.2f b = %.2f\n", MYTHREAD, a, b);
    }
    upc_barrier i;
  }

    upc_barrier;
    printf("TH%d: a = %.2f b = %.2f\n", MYTHREAD, a, b);
    if (a != expect) printf("ERROR: a=%f expect=%f\n",a,expect);
    else printf("done.\n");

    return 0;
}


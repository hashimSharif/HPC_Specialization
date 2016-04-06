#include <upc.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int iters = 10;
  int maxsz = 10;
  if (THREADS % 2 != 0) { 
    exit(1);
  }
  /* -------------------------- */
  { 
    int x = 45;
    if (!(MYTHREAD&1)) { 
      for (int i=0; i < iters; i++) {
      }
    } else { 
    }

    upc_barrier;

    if (!(MYTHREAD&1)) {
       exit(0);
    }
  }
  /* -------------------------- */
  #define DOIT() do {                           \
    for (int sz = 1; sz <= maxsz; sz *= 2) {    \
      if (!(MYTHREAD&1)) {                      \
      } else {                                  \
        for (int i=0; i < iters; i++) {         \
        }                                       \
      }                                         \
    }                                           \
  } while (0)
  DOIT();
  DOIT();
  return 0;
}

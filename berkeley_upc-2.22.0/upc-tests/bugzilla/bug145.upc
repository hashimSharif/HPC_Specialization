#include <stdio.h>
#include <upc.h>
#define SIZE (10*THREADS)

shared int              IntData[SIZE];

int main() {
  int i;
  upc_forall(i = 0; i < SIZE; i++; &IntData[i]) {
   IntData[i] = 0;
  }
  upc_barrier;
  upc_forall(i = 0; i < SIZE; i++; &IntData[i]) {
   IntData[i] = IntData[i] + 1;
  }
  upc_barrier;
  if (MYTHREAD == 0) {
    for (i = 0; i < SIZE; i++) {
     if (IntData[i] != 1) printf("ERROR\n");
    }
  }
  printf("done.\n");
  return 0;
}

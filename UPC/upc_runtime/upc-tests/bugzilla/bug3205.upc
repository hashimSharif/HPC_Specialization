#include <upc.h>
#include <stdio.h>

shared int x;

int side_effect() {
  fprintf(stderr, "ERROR 1\n");
  return 1;
}

int main () {
  int y;
  shared void *p = &x;

  if (upc_threadof(p) == 20 && side_effect()) fprintf(stderr, "ERROR 2\n");
  if (upc_threadof(p) == MYTHREAD && (int *)p == &y) fprintf(stderr, "ERROR 3\n");
  upc_barrier;

  if (!MYTHREAD) printf("done.\n");
  return 0;
}

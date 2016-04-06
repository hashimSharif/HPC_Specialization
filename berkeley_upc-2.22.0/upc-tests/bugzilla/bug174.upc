#include <upc.h>
#include <stdio.h>

shared char x[10*THREADS];

int main() {
  printf("%i\n", (int)upc_elemsizeof(x));
  return 0;
}

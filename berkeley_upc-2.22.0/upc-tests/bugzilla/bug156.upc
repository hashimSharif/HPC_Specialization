#include <upc.h>
#include <stdio.h>

struct foo {
  char No;
  int  a[20];
};

shared [10] struct foo f;
int main() {
  printf("%i\n",(int)upc_blocksizeof(*&(f.No)));
  printf("%i\n",(int)upc_blocksizeof(*&(f.a)));
  { shared [] char * x = &(f.No);
    *x = '\0';
  }
  printf("done.\n");
  return 0;
}

#include <upc.h>
#include <stdio.h>
#include <inttypes.h>

shared void *p;
typedef struct {
    shared void *addr;
    int len;
} s_t;

shared [100] uint64_t A[10*100*THREADS];

void test(s_t srclist[]) {
  p = &(A[1]);
  printf("upc_threadof(p)=%i\n",(int)upc_threadof(p));
  srclist[1].addr = &(A[1]);
  printf("upc_threadof(srclist[1].addr)=%i\n",(int)upc_threadof(srclist[1].addr));
  int x = 7;
  srclist[x].addr = &(A[1]);
  printf("upc_threadof(srclist[x].addr)=%i\n",(int)upc_threadof(srclist[x].addr));
  shared void *q = srclist[x].addr;
  printf("upc_threadof(q)=%i\n",(int)upc_threadof(q));
  printf("upc_threadof(srclist[x].addr)=%i\n",(int)upc_threadof(srclist[x].addr));
  size_t res = upc_threadof(srclist[x].addr);
  if (res == 0) {
    printf("done.\n");
  } else {
    printf("ERROR.\n");
  }
}

int main() {
  s_t sa[10];
  test(sa);
}

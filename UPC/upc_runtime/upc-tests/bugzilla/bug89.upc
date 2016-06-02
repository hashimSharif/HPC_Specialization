#include <stdio.h>
#include <upc.h>

#define CHECK(ptr, phase, thread) do { \
  int p = upc_phaseof(ptr);\
  int t = upc_threadof(ptr);\
  if (p != phase) {\
    printf("ERROR: line %i: upc_phaseof(%s)=%i, should be %i\n", \
         __LINE__, #ptr, p, phase); \
  } \
  if (t != thread) { \
    printf("ERROR: line %i: upc_threadof(%s)=%i, should be %i\n", \
         __LINE__, #ptr, t, thread); \
  }\
} while(0)

int main() {
  shared [10] int *p1;
  shared [20] int *p2;
  shared [] int *p3;
  shared int *p4;
  shared void *p5;

  p1 = upc_all_alloc(100, 10);
  CHECK(p1,0,0);
  p1 = &p1[1];
  CHECK(p1,1,0);
  p2 = (shared [20] int *)p1;
  CHECK(p2,0,0);
  p3 = (shared [] int *)p1;
  CHECK(p3,0,0);
  p4 = (shared int *)p1;
  CHECK(p4,0,0);
  p5 = p1;
  CHECK(p5,1,0);

  p1 = p5;
  p2 = p5;
  p3 = p5;
  p4 = p5;
  CHECK(p1,1,0);
  CHECK(p2,1,0);
  CHECK(p3,0,0);
  CHECK(p4,0,0);

  p5 = p1;
  p2 = p5;
  CHECK(p2,1,0);

  p2 = (shared void *)p1;
  CHECK(p2,1,0);

  printf("done.\n"); 
}

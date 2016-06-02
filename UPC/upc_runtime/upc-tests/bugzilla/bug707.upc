#include <stdio.h>
#include <upc.h>
#include <assert.h>

struct S {
int x;
};

struct S s1 = { 10 };

int main() {
  static struct S s2 = { 20 };
  assert(s1.x == 10);
  assert(s2.x == 20);
  upc_barrier;
  s1.x = MYTHREAD; 
  s2.x = 100*MYTHREAD; 
  upc_barrier;
  assert(s1.x == MYTHREAD);
  assert(s2.x == 100*MYTHREAD);
  upc_barrier;
  printf("done.\n");
 return 0;
}

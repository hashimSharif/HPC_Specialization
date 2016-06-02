#include <stdio.h>
#include <upc.h>
#include <assert.h>

shared [] int *p1 = NULL;
shared [] int *p2;
shared [10] int *s1;
shared [10] int *s2 = NULL;
int main() {
  shared [] int *p3 = NULL;
  shared [10] int *s3 = NULL;

  assert(p1 == NULL);
  assert(p2 == NULL);
  assert(p1 == p2);
  assert(s1 == NULL);
  assert(s2 == NULL);
  assert(s1 == s2);
  assert((shared void *)p1 == s1);
  assert((shared void *)p2 == s2);
  assert((shared void *)p3 == s3);
  assert((shared [] int *)s1 == p1);
  assert((shared [] int *)s2 == p2);
  assert((shared [] int *)s3 == p3);
  //assert(upc_threadof(NULL) == 0);
  assert(upc_threadof(p1) == 0);
  assert(upc_threadof(p2) == 0);
  assert(upc_threadof(p3) == 0);
  assert(upc_threadof(s1) == 0);
  assert(upc_threadof(s2) == 0);
  assert(upc_threadof(s3) == 0);
  printf("done.\n");
  return 0;
}

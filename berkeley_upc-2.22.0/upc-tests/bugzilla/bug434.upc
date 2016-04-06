#include <upc.h>
#include <stdlib.h>
#include <stdio.h>

shared strict int *ip1 = 0;
shared int *ip2 = NULL;
shared const void *vp = NULL;
shared void *vp2 = 0;

int main() {
  void *p1;
  void *p2 = NULL;
  p1 = (void *)ip1;
  if (p1 != p2) printf("ERROR on %i\n", __LINE__);
  p1 = (void *)ip2;
  if (p1 != p2) printf("ERROR on %i\n", __LINE__);
  p1 = (void *)vp;
  if (p1 != p2) printf("ERROR on %i\n", __LINE__);
  p1 = (void *)vp2;
  if (p1 != p2) printf("ERROR on %i\n", __LINE__);
  return 0;
}

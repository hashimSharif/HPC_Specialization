#include <upc.h>
#include <stdio.h>

shared [10] int ablocked[10*THREADS];

int main() {
  int id0 = 2;
  int id1 = (THREADS-1)*10;
 
  shared [10] int *p0 = &ablocked[2];
  shared [10] int *p1 = &ablocked[(THREADS-1)*10];

  if (id0 > id1) printf("TEST SKIPPED - REQUIRES > 1 THREAD\ndone.\n");
  else {
    if (p0 > p1) {
      printf("TEST FAILED!!!\n");
    } else printf("done.\n");
  }
}
  

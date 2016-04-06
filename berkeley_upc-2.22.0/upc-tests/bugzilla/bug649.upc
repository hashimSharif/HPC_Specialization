#include <stdio.h>
#include <string.h>

#define NX 5000
#define NY 4

int bigArray[NY][NX];
int smallArray[NX];

int main(void) {
  int i;

  for (i = 0; i < NY; ++i) {
    memcpy(bigArray[i], smallArray, NX*sizeof(int));
  }
  
  printf ("done.\n");
  return 0;
}

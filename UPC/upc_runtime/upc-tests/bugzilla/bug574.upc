#include <stdio.h>
#include <upc.h>
#include <inttypes.h>

shared [] uint64_t s_A[11][12][13]; /* shared array */
void stridedtest() {

  {
    for (int i=0; i < 11; i++)
    for (int j=0; j < 12; j++)
    for (int k=0; k < 13; k++)
      s_A[i][j][k] = (((uint64_t)i) << 32) + (((uint64_t)j) << 16) + k;
  }

  for (int i=0; i < 11; i++)
  for (int j=0; j < 12; j++)
  for (int k=0; k < 13; k++) {
    uint64_t actual = s_A[i][j][k];
    uint64_t expected = (((uint64_t)i) << 32) + (((uint64_t)j) << 16) + k;
    if (actual != expected) {
      printf("%i: ERROR - s_A[%i][%i][%i]=%llu, should be %llu\n", MYTHREAD, 
             i,j,k,
             (unsigned long long)actual, (unsigned long long)expected);
    }
  }
}

int main() {
  int i;
  if (MYTHREAD == 0) printf("Starting...\n");
  upc_barrier;

    stridedtest();

  upc_barrier;
  if (MYTHREAD == 0) printf("done.\n");
  return 0;
}

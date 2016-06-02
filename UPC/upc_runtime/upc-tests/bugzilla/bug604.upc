#include <stdio.h>
#include <stdlib.h>

#define SZ 1000
shared [SZ] int nums[2][THREADS][SZ];

int main() {
  if (MYTHREAD==0) printf("generating...\n");
  for (int i=0; i < SZ; i++) {
    nums[0][MYTHREAD][i] = rand();
  }
  upc_barrier;
  if (MYTHREAD==0) printf("cross-checking...\n");
  for (int i=0; i < SZ; i++) {
    int mine = nums[0][MYTHREAD][i];
    int his = nums[0][(MYTHREAD+1)%THREADS][i];
    if (mine != his) printf("%i : ERROR at line %i i=%i, mine=0x%08x his=0x%08x\n", 
                             MYTHREAD, __LINE__, i, mine, his);
  }
  upc_barrier;
  if (MYTHREAD==0) printf("trying default seed...\n");
  srand(1);
  for (int i=0; i < SZ; i++) {
    nums[1][MYTHREAD][i] = rand();
  }
  upc_barrier;
  if (MYTHREAD==0) printf("verifying...\n");
  for (int i=0; i < SZ; i++) {
    int mine = nums[1][MYTHREAD][i];
    int old = nums[0][MYTHREAD][i];
    if (mine != old) printf("%i : ERROR at line %i i=%i, mine=0x%08x old=0x%08x\n", 
                             MYTHREAD, __LINE__, i, mine, old);
  }
  upc_barrier;
  for (int seed = 10; seed < 20; seed++) {
    srand(seed);
    if (MYTHREAD==0) printf("generating...\n");
    for (int i=0; i < SZ; i++) {
      nums[0][MYTHREAD][i] = rand();
    }
    upc_barrier;
    if (MYTHREAD==0) printf("cross-checking...\n");
    for (int i=0; i < SZ; i++) {
      int mine = nums[0][MYTHREAD][i];
      int his = nums[0][(MYTHREAD+1)%THREADS][i];
      if (mine != his) printf("%i : ERROR at line %i i=%i, mine=0x%08x his=0x%08x\n", 
          MYTHREAD, __LINE__, i, mine, his);
    }
    upc_barrier;
  }
  if (MYTHREAD==0) printf("done.\n");
  return 0;
}

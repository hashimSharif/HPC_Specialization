#include <upc.h>
#include <inttypes.h>
#include <assert.h>
#include <stdio.h>


#define BLKSZ 200
shared [BLKSZ] uint64_t A[BLKSZ*THREADS];

void ilisttest() {
  shared const void * srclist[] = {
          &(A[14]), &(A[15]), &(A[16]),   
          &(A[100]), &(A[110])            
        };
  assert(srclist[0] == &(A[14]));
  assert(srclist[1] == &(A[15]));
  assert(srclist[2] == &(A[16]));
  assert(srclist[3] == &(A[100]));
  assert(srclist[4] == &(A[110]));
}

int main() {
  int i;
  if (MYTHREAD == 0) printf("Starting...\n");

    ilisttest();

  upc_barrier;
  if (MYTHREAD == 0) printf("done.\n");
  return 0;
}

#include <upc.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>


#define BLKSZ 100
shared [BLKSZ] uint64_t A[3*BLKSZ*THREADS];

typedef struct _memvec {
shared void *addr;
size_t len;
} memvec_t;

int main() {
    memvec_t srclist[4];
    int zero = 0;
    int one = 1;
    int elemsz = (int)((char *)&srclist[one] - (char*)&srclist[zero]);

    printf("sizeof(memvec_t)=%i\n",(int)sizeof(memvec_t));
    printf("sizeof(void*)=%i\n",(int)sizeof(void*));
    printf("sizeof(size_t)=%i\n",(int)sizeof(size_t));
    printf("sizeof(srclist[0])=%i\n",elemsz);

    srclist[0].addr = &(A[0]);
    srclist[0].len = 0*sizeof(uint64_t);
    srclist[1].addr = &(A[1]);
    srclist[1].len = 1*sizeof(uint64_t);
    srclist[2].addr = &(A[2]);
    srclist[2].len = 2*sizeof(uint64_t);
    srclist[3].addr = &(A[3]);
    srclist[3].len = 3*sizeof(uint64_t);

   for (int i=0; i < 4; i++) { 
    assert(srclist[i].addr == &(A[i]));
    assert(srclist[i].len == i*sizeof(uint64_t));
   }

  assert(sizeof(memvec_t) == elemsz);

  upc_barrier;
  if (MYTHREAD == 0) printf("done.\n");
  return 0;
}

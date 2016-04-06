/* a correctness test to exercise some corner cases of upc_memcpy
   Dan Bonachea <bonachea@cs.berkeley.edu>
 */
#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>


#define TEST_VAL(iter, idx) \
        ((((uint64_t)MYTHREAD)<<48)+(((uint64_t)iter)<<20)+(uint64_t)(idx))

void setvals(uint64_t *ptr, int iter, int numvals) {
  for (int i = 0; i < numvals; i++) {
    ptr[i] = TEST_VAL(iter, i);
  }
}

void checkvals(uint64_t *ptr, int iter, int numvals, int isclear, const char *context) {
  for (int i = 0; i < numvals; i++) {
    uint64_t expect = (isclear ? 0 : TEST_VAL(iter, i));
    uint64_t actual = ptr[i];
    if (actual != expect) {
      printf("%i: ERROR in %s: data[%i]=%016llx, should be %016llx\n", 
             MYTHREAD, context, i,
             (unsigned long long)actual, (unsigned long long)expect);
      fflush(stdout);
    }
  }
}

/* usage: memcpy_async <num_iters> <elems_per_chunk> <num_chunks> */
int main(int argc, char **argv) {
  int iters = 0, chunksz = 0, numchunks = 0;

  if (argc > 1) iters = atoi(argv[1]);
  if (iters < 1) iters = 10;
  if (argc > 2) chunksz = atoi(argv[2]);
  if (chunksz < 1) chunksz = 100;
  if (argc > 3) numchunks = atoi(argv[3]);
  if (numchunks < 1) numchunks = 100;

  if (MYTHREAD == 0) {
    printf("Running memcpy correctness test on %i threads: iters=%i chunksz=%i numchunks=%i\n", 
      (int)THREADS, iters, chunksz, numchunks);
    if (THREADS < 2) {
      printf("NOTE: this test requires more than one thread for good coverage\n");
    }
  }
  upc_barrier;

  #define CHUNKBYTES (chunksz*8)
  #define TOTALBYTES (numchunks*CHUNKBYTES)
  #define TOTALELEMS (chunksz*numchunks)
  #define ELEMOFFSET (chunkidx*chunksz)

  shared uint64_t *arr1 = upc_all_alloc(THREADS, THREADS*TOTALBYTES);
  shared [] uint64_t *myarr1 = (shared [] uint64_t *)(arr1+MYTHREAD);
  shared [] uint64_t *mytmp1 = upc_alloc(TOTALBYTES);
  shared [] uint64_t *mytmp2 = upc_alloc(TOTALBYTES);

  /* outer iteration loop for entire test */
  for (int iter = 0; iter < iters; iter++) {

    /* threads take turns performing the test */
    for (int worker = 0; worker < THREADS; worker ++) {

      upc_barrier;

      upc_memset(myarr1, 0, TOTALBYTES); // clean all slates 

      checkvals((uint64_t *)myarr1, iter, TOTALELEMS, 1, "slate clear");

      upc_barrier;

      if (worker == MYTHREAD) {

        setvals((uint64_t *)mytmp1, iter, TOTALELEMS); // make the data
        checkvals((uint64_t *)mytmp1, iter, TOTALELEMS, 0, "init");
      
        upc_memcpy(myarr1, mytmp1, TOTALBYTES); // put it in my area
        checkvals((uint64_t *)myarr1, iter, TOTALELEMS, 0, "local copy");

        for (int i = 0; i < THREADS-1; i++) { // pass it around the threads via remote memcpy
          int peerA = (MYTHREAD+i)%THREADS;
          int peerB = (MYTHREAD+i+1)%THREADS;
          shared [] uint64_t *peerarr1A = (shared [] uint64_t *)(arr1+peerA);
          shared [] uint64_t *peerarr1B = (shared [] uint64_t *)(arr1+peerB);

          if (iter % 2 == 0) { // chunkwise
            for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {
               upc_memcpy(peerarr1B+ELEMOFFSET, peerarr1A+ELEMOFFSET, CHUNKBYTES);
            }
          } else { // bulk
            upc_memcpy(peerarr1B, peerarr1A, TOTALBYTES);
          }

          upc_memset(mytmp2, 0, TOTALBYTES);
          checkvals((uint64_t *)mytmp2, iter, TOTALELEMS, 1, "prefetch clear");

          upc_memcpy(mytmp2, peerarr1B, TOTALBYTES); // fetch it back
          char desc[255];
          sprintf(desc, "post-copy check peerA=%i peerB=%i", peerA, peerB);
          checkvals((uint64_t *)mytmp2, iter, TOTALELEMS, 0, desc);
        }
      }

      upc_barrier;
    }

  }


  upc_barrier;
  if (MYTHREAD == 0) printf("done.\n");
  return 0;
}

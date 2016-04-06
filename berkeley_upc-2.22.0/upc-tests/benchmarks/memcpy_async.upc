/* a correctness test to fully exercise the capabilities of the contiguous 
   bupc_mem* functions (blocking and async)
   Dan Bonachea <bonachea@cs.berkeley.edu>
 */
#ifndef BUPC_USE_UPC_NAMESPACE
#define BUPC_USE_UPC_NAMESPACE 1
#endif
#include <upc.h>
#include <upc_nb.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
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
  #define DATASZ (chunksz*numchunks*8)
  int iters = 0, chunksz = 0, numchunks = 0;

  if (argc > 1) iters = atoi(argv[1]);
  if (iters < 1) iters = 10;
  if (argc > 2) chunksz = atoi(argv[2]);
  if (chunksz < 1) chunksz = 100;
  if (argc > 3) numchunks = atoi(argv[3]);
  if (numchunks < 1) numchunks = 100;

  if (MYTHREAD == 0) {
    printf("Running memcpy extensions test on %i threads: iters=%i chunksz=%i numchunks=%i\n", 
      (int)THREADS, iters, chunksz, numchunks);
    if (THREADS > 1 && THREADS % 2 != 0) { 
      printf("ERROR: THREADS must be unary or even\n");
      upc_global_exit(-1);
    }
  }
  upc_barrier;

  int peer = (THREADS == 1 ? 0 : (MYTHREAD ^ 0x1));
  shared uint64_t *arr1 = upc_all_alloc(THREADS, THREADS*DATASZ);
  shared uint64_t *arr2 = upc_all_alloc(THREADS, THREADS*DATASZ);
  shared [] uint64_t *peerarr1 = (shared [] uint64_t *)(arr1+peer);
  /*shared [] uint64_t *peerarr2 = (shared [] uint64_t *)(arr2+peer);*/
  /*shared [] uint64_t *myarr1 = (shared [] uint64_t *)(arr1+MYTHREAD);*/
  shared [] uint64_t *myarr2 = (shared [] uint64_t *)(arr2+MYTHREAD);
  /*uint64_t *mylarr1 = (uint64_t *)myarr1;*/
  uint64_t *mylarr2 = (uint64_t *)myarr2;
  uint64_t *myltmp = malloc(DATASZ);

  #define CHUNKBYTES (chunksz*8)
  #define TOTALBYTES (numchunks*CHUNKBYTES)
  #define TOTALELEMS (chunksz*numchunks)
  #define ELEMOFFSET (chunkidx*chunksz)

  #define DOTEST(DOPUT, DOGET, DOCPY, DOSET, DOPRE, DOPOST, CONTEXTSTR) do { \
    /*-------------------------------------------------------*/              \
    /* put arr2 -> arr1 */                                                   \
    setvals(mylarr2, iter, TOTALELEMS);                                      \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOPUT(peerarr1+ELEMOFFSET, mylarr2+ELEMOFFSET, CHUNKBYTES);            \
    }                                                                        \
    DOPOST;                                                                  \
    memset(mylarr2,0,TOTALBYTES);                                            \
    /* get arr2 <- arr1 */                                                   \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOGET(mylarr2+ELEMOFFSET,peerarr1+ELEMOFFSET, CHUNKBYTES);             \
    }                                                                        \
    DOPOST;                                                                  \
    checkvals(mylarr2, iter, TOTALELEMS, 0,                                  \
              CONTEXTSTR" in-seg put then in-seg get test");                 \
    /*-------------------------------------------------------*/              \
    /* put tmp -> arr1 */                                                    \
    setvals(myltmp, iter, TOTALELEMS);                                       \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOPUT(peerarr1+ELEMOFFSET, myltmp+ELEMOFFSET, CHUNKBYTES);             \
    }                                                                        \
    DOPOST;                                                                  \
    memset(myltmp,0,TOTALBYTES);                                             \
    /* get tmp <- arr1 */                                                    \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOGET(myltmp+ELEMOFFSET,peerarr1+ELEMOFFSET, CHUNKBYTES);              \
    }                                                                        \
    DOPOST;                                                                  \
    checkvals(myltmp, iter, TOTALELEMS, 0,                                   \
              CONTEXTSTR" out-seg put then out-seg get test");               \
    /*-------------------------------------------------------*/              \
    /* put tmp -> arr1 */                                                    \
    setvals(myltmp, iter, TOTALELEMS);                                       \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOPUT(peerarr1+ELEMOFFSET, myltmp+ELEMOFFSET, CHUNKBYTES);             \
    }                                                                        \
    DOPOST;                                                                  \
    memset(mylarr2,0,TOTALBYTES);                                            \
    /* get arr2 <- arr1 */                                                   \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOGET(mylarr2+ELEMOFFSET,peerarr1+ELEMOFFSET, CHUNKBYTES);             \
    }                                                                        \
    DOPOST;                                                                  \
    checkvals(mylarr2, iter, TOTALELEMS, 0,                                  \
              CONTEXTSTR" out-seg put then in-seg get test");                \
    /*-------------------------------------------------------*/              \
    /* put arr2 -> arr1 */                                                   \
    setvals(mylarr2, iter, TOTALELEMS);                                      \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOPUT(peerarr1+ELEMOFFSET, mylarr2+ELEMOFFSET, CHUNKBYTES);            \
    }                                                                        \
    DOPOST;                                                                  \
    memset(myltmp,0,TOTALBYTES);                                             \
    /* get tmp <- arr1 */                                                    \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOGET(myltmp+ELEMOFFSET,peerarr1+ELEMOFFSET, CHUNKBYTES);              \
    }                                                                        \
    DOPOST;                                                                  \
    checkvals(myltmp, iter, TOTALELEMS, 0,                                   \
              CONTEXTSTR" in-seg put then out-seg get test");                \
    /*-------------------------------------------------------*/              \
    /* cpy arr2 -> arr1 */                                                   \
    setvals(mylarr2, iter, TOTALELEMS);                                      \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOCPY(peerarr1+ELEMOFFSET, myarr2+ELEMOFFSET, CHUNKBYTES);             \
    }                                                                        \
    DOPOST;                                                                  \
    /* set local arr2 (clear) */                                             \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOSET(myarr2+ELEMOFFSET, 0, CHUNKBYTES);                               \
    }                                                                        \
    DOPOST;                                                                  \
    /* check local clear */                                                  \
    checkvals(mylarr2, iter, TOTALELEMS, 1,                                  \
              CONTEXTSTR" local clear test");                                \
    /* cpy arr2 <- arr1 */                                                   \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOCPY(myarr2+ELEMOFFSET, peerarr1+ELEMOFFSET, CHUNKBYTES);             \
    }                                                                        \
    DOPOST;                                                                  \
    checkvals(mylarr2, iter, TOTALELEMS, 0,                                  \
              CONTEXTSTR" cpy then cpy back test");                          \
    /* set remote arr1 (clear) */                                            \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOSET(peerarr1+ELEMOFFSET, 0, CHUNKBYTES);                             \
    }                                                                        \
    DOPOST;                                                                  \
    /* cpy arr2 <- arr1 */                                                   \
    DOPRE;                                                                   \
    for (int chunkidx = 0; chunkidx < numchunks; chunkidx++) {               \
      DOCPY(myarr2+ELEMOFFSET, peerarr1+ELEMOFFSET, CHUNKBYTES);             \
    }                                                                        \
    DOPOST;                                                                  \
    /* check remote clear */                                                 \
    checkvals(mylarr2, iter, TOTALELEMS, 1,                                  \
              CONTEXTSTR" remote clear test");                               \
    /*-------------------------------------------------------*/              \
  } while (0)

  upc_handle_t *handles = malloc(numchunks*sizeof(upc_handle_t));

  /* outer iteration loop for entire test */
  for (int iter = 0; iter < iters; iter++) {

    upc_barrier;

    /* check completion behavior for empty handle arrays */
    assert(upc_sync_attempt(UPC_COMPLETE_HANDLE));
    upc_sync(UPC_COMPLETE_HANDLE);
    for (int i=0; i < numchunks; i++) handles[i] = UPC_COMPLETE_HANDLE;
    assert(upc_trysync_some(handles,numchunks));
    for (int i=0; i < numchunks; i++) assert(handles[i] == UPC_COMPLETE_HANDLE);
    assert(upc_trysync_all(handles,numchunks));
    for (int i=0; i < numchunks; i++) assert(handles[i] == UPC_COMPLETE_HANDLE);
    upc_waitsync_some(handles,numchunks);
    for (int i=0; i < numchunks; i++) assert(handles[i] == UPC_COMPLETE_HANDLE);
    upc_waitsync_all(handles,numchunks);
    for (int i=0; i < numchunks; i++) assert(handles[i] == UPC_COMPLETE_HANDLE);

    upc_barrier;

    /* check completion behavior with some real handles */

    /* fill array of handles */
    #define POPULATE() do {                                                      \
      for (int chunkidx=0; chunkidx < numchunks; chunkidx++) {                   \
        handles[chunkidx] =                                                      \
          upc_memput_nb(peerarr1+ELEMOFFSET, mylarr2+ELEMOFFSET, CHUNKBYTES); \
      }                                                                          \
    } while (0)

    POPULATE();
    for (int i=0; i < numchunks; i++) upc_sync(handles[i]);

    POPULATE();
    for (int i=0; i < numchunks; i++) {
      while (!upc_sync_attempt(handles[i])) upc_fence; 
    }

    POPULATE();
    upc_waitsync_all(handles, numchunks);

    POPULATE();
    while (!upc_trysync_all(handles, numchunks)) upc_fence;
    for (int i=0; i < numchunks; i++) assert(handles[i] == UPC_COMPLETE_HANDLE);

    POPULATE();
    { int done = 0;
      while (done < numchunks) {
        int thisdone = 0;
        upc_waitsync_some(handles, numchunks);
        for (int i=0; i < numchunks; i++) { /* count number complete */
          if (handles[i] == UPC_COMPLETE_HANDLE) thisdone++;
        }
        assert(thisdone > done); /* ensure it increased */
        done = thisdone;
      }
    }

    POPULATE();
    { int done = 0;
      while (done < numchunks) {
        int thisdone = 0;
        int result = upc_trysync_some(handles, numchunks);
        for (int i=0; i < numchunks; i++) { /* count number complete */
          if (handles[i] == UPC_COMPLETE_HANDLE) thisdone++;
        }
        if (result) assert(thisdone > done); /* try indicated increased */
        else assert(thisdone == done); /* try indicated no change */
        done = thisdone;
      }
    }

    upc_barrier;

    /* run put/get correctness tests to validate data movement ops */

    DOTEST(upc_memput,upc_memget,upc_memcpy,upc_memset,{},{},"blocking");

    DOTEST(handles[chunkidx] = upc_memput_nb,
           handles[chunkidx] = upc_memget_nb,
           handles[chunkidx] = upc_memcpy_nb,
           handles[chunkidx] = upc_memset_nb,
           {},upc_waitsync_all(handles, numchunks),"nb");

    DOTEST(upc_memput_nbi,
           upc_memget_nbi,
           upc_memcpy_nbi,
           upc_memset_nbi,
           {},upc_synci(),"nbi");

    DOTEST(upc_memput_nbi,
           upc_memget_nbi,
           upc_memcpy_nbi,
           upc_memset_nbi,
           upc_begin_accessregion(),
           upc_sync(upc_end_accessregion()),
           "accessregion");

  }

  upc_barrier;
  if (MYTHREAD == 0) printf("done.\n");
  return 0;
}

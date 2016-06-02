#ifndef BUPC_USE_UPC_NAMESPACE
#define BUPC_USE_UPC_NAMESPACE 1
#endif
#include <upc.h>
#include <upc_nb.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <assert.h>

#define TEST_CONTIG 1
#define TEST_ILIST 1
#define TEST_VLIST 1
#define TEST_STRIDED 1

#define BLKSZ 100
shared [BLKSZ] uint64_t A[3*BLKSZ*THREADS];

#define TEST_VAL(blockid, idx) (1000*(blockid)+(idx))

/* hokey workaround for an optimizer bug in Intel C (bug702) */
uint64_t IntelCOptimizerBug(int i, int j, int k) {
  return (((uint64_t)i+5) << 32) + (((uint64_t)j+6) << 16) + k+7;
}


#if TEST_CONTIG
void contigtest() {
  if (MYTHREAD == 0) { printf("contigtest...\n"); fflush(stdout); sleep(1); }
  upc_barrier;
  uint64_t leftdata[BLKSZ];
  uint64_t rightdata[BLKSZ];
  upc_handle_t leftfetch_handle = UPC_COMPLETE_HANDLE;
  upc_handle_t rightfetch_handle = UPC_COMPLETE_HANDLE;

  if (MYTHREAD > 0) /* initiate fetch of data from left neighbor */
    leftfetch_handle =  upc_memget_nb(leftdata, &(A[BLKSZ*(MYTHREAD-1)]), BLKSZ*sizeof(uint64_t));
  if (MYTHREAD < THREADS-1)  /* initiate fetch of data from right neighbor */
    rightfetch_handle = upc_memget_nb(rightdata, &(A[BLKSZ*(MYTHREAD+1)]), BLKSZ*sizeof(uint64_t));

  /* perform some independent computations here */

  upc_sync(leftfetch_handle); /* block for completion of communication, if necessary */
  upc_sync(rightfetch_handle);

  /* now safe to operate on leftdata and rightdata */
  if (MYTHREAD > 0) {
    for (int i=0; i < BLKSZ; i++) {
      uint64_t actual = leftdata[i];
      uint64_t expected = TEST_VAL((MYTHREAD-1),i);
      if (actual != expected) {
        printf("%i: ERROR - leftdata[%i]=%016llx, should be %016llx\n", MYTHREAD, i,
               (unsigned long long)actual, (unsigned long long)expected);
        fflush(stdout);
      }
    }
  }
  if (MYTHREAD < THREADS-1) {
    for (int i=0; i < BLKSZ; i++) {
      uint64_t actual = rightdata[i];
      uint64_t expected = TEST_VAL((MYTHREAD+1),i);
      if (actual != expected) {
        printf("%i: ERROR - rightdata[%i]=%016llx, should be %016llx\n", MYTHREAD, i,
               (unsigned long long)actual, (unsigned long long)expected);
        fflush(stdout);
      }
    }
  }
}
#endif

#if TEST_VLIST
void vlisttest() {
  if (MYTHREAD == 0) { printf("vlisttest...\n"); fflush(stdout); sleep(1); }
  upc_barrier;
  uint64_t mybuf[52+BLKSZ];
  #if 1
    upc_smemvec_t srclist[] = {
            { &(A[14]), sizeof(uint64_t) },     /* element 14 (from block 0) */
            { &(A[20]), sizeof(uint64_t) },     /* element 20 (from block 0) */
            { &(A[100]), 50*sizeof(uint64_t) }, /* elements 100..149 (from block 1) */
            { &(A[2*BLKSZ]), BLKSZ*sizeof(uint64_t) } /* entire block (from block 2) */
          };
    upc_pmemvec_t dstlist[] = { { mybuf, sizeof(mybuf) } };
  #else /* alternate code to do the same setup */
    upc_smemvec_t srclist[4];
    upc_pmemvec_t dstlist[1];
    dstlist[0].addr = mybuf;
    dstlist[0].len = sizeof(mybuf);
    srclist[0].addr = &(A[14]);
    srclist[0].len = sizeof(uint64_t);
    srclist[1].addr = &(A[20]);
    srclist[1].len = sizeof(uint64_t);
    srclist[2].addr = &(A[100]);
    srclist[2].len = 50*sizeof(uint64_t);
    srclist[3].addr = &(A[2*BLKSZ]);
    srclist[3].len = BLKSZ*sizeof(uint64_t);
  #endif

  upc_handle_t handle = upc_memget_vlist_async(1, dstlist, 4, srclist);
  /* perform some independent computations here */
  upc_sync(handle);
  /* now safe to operate on result */

  #define CHECK(idx, expected) do {                                             \
      uint64_t actual = mybuf[idx];                                             \
      if (actual != expected) {                                                 \
        printf("%i: ERROR - mybuf[%i]=%016llx, should be %016llx\n", MYTHREAD, (idx), \
               (unsigned long long)actual, (unsigned long long)expected);       \
        fflush(stdout);                                                         \
      }                                                                         \
    } while(0)
  int i;
  CHECK(0, TEST_VAL(0,14));
  CHECK(1, TEST_VAL(0,20));
  for ( i=0; i < 50; i++) {
    CHECK(i+2, TEST_VAL(1,i));
  }
  for ( i=0; i < BLKSZ; i++) {
    CHECK(i+52, TEST_VAL(2,i));
  }
  #undef CHECK
}
#endif

#if TEST_ILIST
void ilisttest() {
  if (MYTHREAD == 0) { printf("ilisttest...\n"); fflush(stdout); sleep(1); }
  upc_barrier;
  uint64_t mybuf[5];
  void * dstlist[] = { &mybuf };
  #if 1
    shared const void * srclist[] = {
            &(A[14]), &(A[15]), &(A[16]),   /* element 14..16 (from thread 0) */
            &(A[100]), &(A[110])            /* element 100 and 110 (from thread 1) */
          };
  #else /* alternate code to do the same setup */
    shared const void * srclist[5];
    srclist[0] =  &(A[14]);
    srclist[1] =  &(A[15]);
    srclist[2] =  &(A[16]);
    srclist[3] =  &(A[100]);
    srclist[4] =  &(A[110]);
  #endif

  assert(srclist[0] == &(A[14]));
  assert(srclist[1] == &(A[15]));
  assert(srclist[2] == &(A[16]));
  assert(srclist[3] == &(A[100]));
  assert(srclist[4] == &(A[110]));

  upc_handle_t handle = upc_memget_ilist_async(1, dstlist, 5*sizeof(uint64_t),
                                               5, srclist, sizeof(uint64_t));
  /* perform some independent computations here */
  upc_sync(handle);
  /* now safe to operate on result */
  #define CHECK(idx, expected) do {                                             \
      uint64_t actual = mybuf[idx];                                             \
      if (actual != expected) {                                                 \
        printf("%i: ERROR - mybuf[%i]=%016llx, should be %016llx\n", MYTHREAD, (idx), \
               (unsigned long long)actual, (unsigned long long)expected);       \
        fflush(stdout);                                                         \
      }                                                                         \
    } while(0)
  int i;
  CHECK(0, TEST_VAL(0,14));
  CHECK(1, TEST_VAL(0,15));
  CHECK(2, TEST_VAL(0,16));
  CHECK(3, TEST_VAL(1,0));
  CHECK(4, TEST_VAL(1,10));
  #undef CHECK
}
#endif

#if TEST_STRIDED
shared [] uint64_t s_A[11][12][13]; /* shared array */
uint64_t s_B[14][15][16]; /* local array */
void stridedtest() {
  if (MYTHREAD == 0) { printf("stridedtest...\n"); fflush(stdout); sleep(1); }
  upc_barrier;
  int i,j,k;
  int zero = 0; /* this gross hack required to workaround bug577 */

  shared void * srcaddr;
  void * dstaddr;
  size_t srcstrides[2];
  size_t dststrides[2];
  size_t count[3];
  size_t stridelevels;

  if (MYTHREAD == 0) {
    for (i=0; i < 11; i++)
    for (j=0; j < 12; j++)
    for (k=0; k < 13; k++)
      s_A[i][j][k] = (((uint64_t)i) << 32) + (((uint64_t)j) << 16) + k;
  }
  upc_barrier;

  srcaddr = &(s_A[5+zero][6+zero][7+zero]); 
  srcstrides[0] = 13 * sizeof(uint64_t);      /* stride in bytes for the rightmost dimension */
  srcstrides[1] = 12 * 13 * sizeof(uint64_t); /* stride in bytes for the middle dimension */
  dstaddr = &(s_B[8+zero][9+zero][10+zero]);
  dststrides[0] = 16 * sizeof(uint64_t);      /* stride in bytes for the rightmost dimension */
  dststrides[1] = 15 * 16 * sizeof(uint64_t); /* stride in bytes for the middle dimension */
  count[0] = 4 * sizeof(uint64_t); /* number of bytes of contiguous data (width in rightmost dimension) */
  count[1] = 3; /* width in middle dimension */
  count[2] = 2; /* width in leftmost dimension */
  stridelevels = 2;

  upc_handle_t handle = upc_memget_strided_async(dstaddr, dststrides, srcaddr, srcstrides, count, stridelevels);
  /* perform some independent computations here */
  upc_sync(handle);
  /* now safe to operate on result */
  for (i=0; i < 2; i++)
  for (j=0; j < 3; j++)
  for (k=0; k < 4; k++) {
    uint64_t actual = s_B[i+8][j+9][k+10];
    uint64_t expected;
    //expected = (((uint64_t)i+5) << 32) + (((uint64_t)j+6) << 16) + k+7;
    expected = IntelCOptimizerBug(i,j,k);

    if (actual != expected) {
      printf("%i: ERROR - s_B[%i][%i][%i]=%016llx, should be %016llx\n", MYTHREAD, 
             i+8,j+9,k+10,
             (unsigned long long)actual, (unsigned long long)expected);
      fflush(stdout);
    }
  }
}
#endif

int main() {
  if (MYTHREAD == 0) {
    printf("Running memcpy extensions test on %i threads...\n", (int)THREADS);
    if (THREADS < 3) { 
      printf("warning: for best test coverage, this test should be run with 3 or more threads\n");
    }
  }
  upc_barrier;
  upc_forall(int i=0; i < sizeof(A)/upc_elemsizeof(A); i++; &A[i]) {
    A[i] = TEST_VAL(((int)(i/upc_blocksizeof(A))),(i%upc_blocksizeof(A)));
  }
  upc_barrier;

  #if TEST_CONTIG
    contigtest();
  #endif

  #if TEST_VLIST
    vlisttest();
  #endif

  #if TEST_ILIST
    ilisttest();
  #endif

  #if TEST_STRIDED
    stridedtest();
  #endif

  upc_barrier;
  if (MYTHREAD == 0) printf("done.\n");
  return 0;
}

#ifndef BUPC_USE_UPC_NAMESPACE
#define BUPC_USE_UPC_NAMESPACE 1
#endif
#include <upc.h>
#include <upc_types.h>
#include <upc_nb.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <assert.h>

#define TEST_CONTIG 1
#define TEST_ILIST 1
#define TEST_VLIST 1
#define TEST_STRIDED 1
#define TEST_FSTRIDED 1

#define BLKSZ 100
shared [BLKSZ] uint64_t A[10*BLKSZ*THREADS];

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
  uint64_t mybuf[300];
  upc_smemvec_t srclist[20];
  upc_pmemvec_t dstlist[20];
  int dstcnt=0, srccnt=0;

  dstlist[dstcnt].addr = &(mybuf[0]);
  dstlist[dstcnt].len = sizeof(uint64_t);
  dstcnt++;
  dstlist[dstcnt].addr = &(mybuf[2]);
  dstlist[dstcnt].len = sizeof(uint64_t);
  dstcnt++;
  dstlist[dstcnt].addr = &(mybuf[4]);
  dstlist[dstcnt].len = 4*sizeof(uint64_t);
  dstcnt++;
  dstlist[dstcnt].addr = &(mybuf[10]);
  dstlist[dstcnt].len = 3*sizeof(uint64_t);
  dstcnt++;
  dstlist[dstcnt].addr = &(mybuf[20]);
  dstlist[dstcnt].len = 50*sizeof(uint64_t);
  dstcnt++;
  dstlist[dstcnt].addr = &(mybuf[100]);
  dstlist[dstcnt].len = BLKSZ*sizeof(uint64_t);
  dstcnt++;
  dstlist[dstcnt].addr = &(mybuf[200]);
  dstlist[dstcnt].len = 4*sizeof(uint64_t);
  dstcnt++;
  dstlist[dstcnt].addr = &(mybuf[250]);
  dstlist[dstcnt].len = 6*sizeof(uint64_t);
  dstcnt++;

  srclist[srccnt].addr = &(A[1]);
  srclist[srccnt].len = sizeof(uint64_t);
  srccnt++;
  srclist[srccnt].addr = &(A[3]);
  srclist[srccnt].len = sizeof(uint64_t);
  srccnt++;
  srclist[srccnt].addr = &(A[14]);
  srclist[srccnt].len = 2*sizeof(uint64_t);
  srccnt++;
  srclist[srccnt].addr = &(A[20]);
  srclist[srccnt].len = 5*sizeof(uint64_t);
  srccnt++;
  srclist[srccnt].addr = &(A[100]);
  srclist[srccnt].len = 50*sizeof(uint64_t);
  srccnt++;
  srclist[srccnt].addr = &(A[2*BLKSZ]);
  srclist[srccnt].len = BLKSZ*sizeof(uint64_t);
  srccnt++;
  srclist[srccnt].addr = &(A[300]);
  srclist[srccnt].len = 2*sizeof(uint64_t);
  srccnt++;
  srclist[srccnt].addr = &(A[400]);
  srclist[srccnt].len = 4*sizeof(uint64_t);
  srccnt++;
  srclist[srccnt].addr = &(A[500]);
  srclist[srccnt].len = 2*sizeof(uint64_t);
  srccnt++;
  srclist[srccnt].addr = &(A[600]);
  srclist[srccnt].len = 2*sizeof(uint64_t);
  srccnt++;

  assert(srccnt <= sizeof(srclist)/sizeof(upc_smemvec_t));
  assert(dstcnt <= sizeof(dstlist)/sizeof(upc_pmemvec_t));

  upc_handle_t handle = upc_memget_vlist_async(dstcnt, dstlist, srccnt, srclist);
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
  CHECK(0, TEST_VAL(0,1));
  CHECK(2, TEST_VAL(0,3));
  CHECK(4, TEST_VAL(0,14));
  CHECK(5, TEST_VAL(0,15));
  CHECK(6, TEST_VAL(0,20));
  CHECK(7, TEST_VAL(0,21));
  CHECK(10, TEST_VAL(0,22));
  CHECK(11, TEST_VAL(0,23));
  CHECK(12, TEST_VAL(0,24));

  for ( i=0; i < 50; i++) {
    CHECK(i+20, TEST_VAL(1,i));
  }
  for ( i=0; i < BLKSZ; i++) {
    CHECK(i+100, TEST_VAL(2,i));
  }
  CHECK(200, TEST_VAL(3,0));
  CHECK(201, TEST_VAL(3,1));
  CHECK(202, TEST_VAL(4,0));
  CHECK(203, TEST_VAL(4,1));
  CHECK(250, TEST_VAL(4,2));
  CHECK(251, TEST_VAL(4,3));
  CHECK(252, TEST_VAL(5,0));
  CHECK(253, TEST_VAL(5,1));
  CHECK(254, TEST_VAL(6,0));
  CHECK(255, TEST_VAL(6,1));
  #undef CHECK
}
#endif

#if TEST_ILIST
void ilisttest() {
  #define CHECK(idx, expected) do {                                             \
      uint64_t actual = mybuf[idx];                                             \
      if (actual != expected) {                                                 \
        printf("%i: ERROR - mybuf[%i]=%016llx, should be %016llx\n", MYTHREAD, (idx), \
               (unsigned long long)actual, (unsigned long long)expected);       \
        fflush(stdout);                                                         \
      }                                                                         \
    } while(0)
  int srccnt, dstcnt;
  uint64_t mybuf[1000];
  void * dstlist[100];
  shared const void * srclist[100];
  upc_handle_t handle;

  /* ------------------ single remote ------------- */
  if (MYTHREAD == 0) { printf("ilisttest (single remote)...\n"); fflush(stdout); sleep(1); }
  upc_barrier;
  srccnt = 0; dstcnt = 0;
  dstlist[dstcnt++] =  &(mybuf[10]);
  dstlist[dstcnt++] =  &(mybuf[11]);
  dstlist[dstcnt++] =  &(mybuf[15]);
  dstlist[dstcnt++] =  &(mybuf[20]);
  srclist[srccnt++] =  &(A[205]);

  assert(srccnt <= sizeof(srclist)/sizeof(shared const void *));
  assert(dstcnt <= sizeof(dstlist)/sizeof(void *));

  handle = upc_memget_ilist_async(dstcnt, dstlist, sizeof(uint64_t),
                                   srccnt, srclist, 4*sizeof(uint64_t));
  /* perform some independent computations here */
  upc_sync(handle);
  /* now safe to operate on result */
  CHECK(10, TEST_VAL(2,5));
  CHECK(11, TEST_VAL(2,6));
  CHECK(15, TEST_VAL(2,7));
  CHECK(20, TEST_VAL(2,8));

  /* ------------------ remotelen % locallen == 0 ------------- */
  if (MYTHREAD == 0) { printf("ilisttest (remotelen %% locallen == 0)...\n"); fflush(stdout); sleep(1); }
  upc_barrier;
  srccnt = 0; dstcnt = 0;
  dstlist[dstcnt++] =  &(mybuf[10]);
  dstlist[dstcnt++] =  &(mybuf[15]);
  srclist[srccnt++] =  &(A[50]);

  dstlist[dstcnt++] =  &(mybuf[20]);
  dstlist[dstcnt++] =  &(mybuf[25]);
  srclist[srccnt++] =  &(A[80]);

  dstlist[dstcnt++] =  &(mybuf[30]);
  dstlist[dstcnt++] =  &(mybuf[35]);
  srclist[srccnt++] =  &(A[110]);

  dstlist[dstcnt++] =  &(mybuf[40]);
  dstlist[dstcnt++] =  &(mybuf[45]);
  srclist[srccnt++] =  &(A[48]);

  assert(srccnt <= sizeof(srclist)/sizeof(shared const void *));
  assert(dstcnt <= sizeof(dstlist)/sizeof(void *));

  handle = upc_memget_ilist_async(dstcnt, dstlist, 2*sizeof(uint64_t),
                                   srccnt, srclist, 4*sizeof(uint64_t));
  /* perform some independent computations here */
  upc_sync(handle);
  /* now safe to operate on result */
  CHECK(10, TEST_VAL(0,50));
  CHECK(11, TEST_VAL(0,51));
  CHECK(15, TEST_VAL(0,52));
  CHECK(16, TEST_VAL(0,53));

  CHECK(20, TEST_VAL(0,80));
  CHECK(21, TEST_VAL(0,81));
  CHECK(25, TEST_VAL(0,82));
  CHECK(26, TEST_VAL(0,83));

  CHECK(30, TEST_VAL(1,10));
  CHECK(31, TEST_VAL(1,11));
  CHECK(35, TEST_VAL(1,12));
  CHECK(36, TEST_VAL(1,13));

  CHECK(40, TEST_VAL(0,48));
  CHECK(41, TEST_VAL(0,49));
  CHECK(45, TEST_VAL(0,50));
  CHECK(46, TEST_VAL(0,51));

  /* ------------------ locallen % remotelen == 0 ------------- */
  if (MYTHREAD == 0) { printf("ilisttest (locallen %% remotelen == 0)...\n"); fflush(stdout); sleep(1); }
  upc_barrier;
  srccnt = 0, dstcnt = 0;
  dstlist[dstcnt++] =  &(mybuf[0]);
  srclist[srccnt++] =  &(A[14]);
  srclist[srccnt++] =  &(A[15]);
  srclist[srccnt++] =  &(A[16]);

  dstlist[dstcnt++] =  &(mybuf[10]);
  srclist[srccnt++] =  &(A[20]);
  srclist[srccnt++] =  &(A[25]);
  srclist[srccnt++] =  &(A[110]);

  dstlist[dstcnt++] =  &(mybuf[20]);
  srclist[srccnt++] =  &(A[120]);
  srclist[srccnt++] =  &(A[150]);
  srclist[srccnt++] =  &(A[180]);

  dstlist[dstcnt++] =  &(mybuf[30]);
  srclist[srccnt++] =  &(A[204]);
  srclist[srccnt++] =  &(A[307]);
  srclist[srccnt++] =  &(A[410]);

  assert(srccnt <= sizeof(srclist)/sizeof(shared const void *));
  assert(dstcnt <= sizeof(dstlist)/sizeof(void *));

  handle = upc_memget_ilist_async(dstcnt, dstlist, 3*sizeof(uint64_t),
                                   srccnt, srclist, sizeof(uint64_t));
  /* perform some independent computations here */
  upc_sync(handle);
  /* now safe to operate on result */
  CHECK(0, TEST_VAL(0,14));
  CHECK(1, TEST_VAL(0,15));
  CHECK(2, TEST_VAL(0,16));

  CHECK(10, TEST_VAL(0,20));
  CHECK(11, TEST_VAL(0,25));
  CHECK(12, TEST_VAL(1,10));

  CHECK(20, TEST_VAL(1,20));
  CHECK(21, TEST_VAL(1,50));
  CHECK(22, TEST_VAL(1,80));

  CHECK(30, TEST_VAL(2,4));
  CHECK(31, TEST_VAL(3,7));
  CHECK(32, TEST_VAL(4,10));

  /* ------------------ general case, no relation btw remotelen, locallen ------------- */
  if (MYTHREAD == 0) { printf("ilisttest (general case)...\n"); fflush(stdout); sleep(1); }
  upc_barrier;
  srccnt = 0, dstcnt = 0;
  dstlist[dstcnt++] =  &(mybuf[0]);
  dstlist[dstcnt++] =  &(mybuf[10]);
  srclist[srccnt++] =  &(A[10]);
  srclist[srccnt++] =  &(A[20]);
  srclist[srccnt++] =  &(A[30]);

  dstlist[dstcnt++] =  &(mybuf[20]);
  dstlist[dstcnt++] =  &(mybuf[30]);
  srclist[srccnt++] =  &(A[110]);
  srclist[srccnt++] =  &(A[120]);
  srclist[srccnt++] =  &(A[130]);

  dstlist[dstcnt++] =  &(mybuf[40]);
  dstlist[dstcnt++] =  &(mybuf[50]);
  srclist[srccnt++] =  &(A[110]);
  srclist[srccnt++] =  &(A[220]);
  srclist[srccnt++] =  &(A[230]);

  dstlist[dstcnt++] =  &(mybuf[60]);
  dstlist[dstcnt++] =  &(mybuf[70]);
  srclist[srccnt++] =  &(A[310]);
  srclist[srccnt++] =  &(A[420]);
  srclist[srccnt++] =  &(A[530]);

  assert(srccnt <= sizeof(srclist)/sizeof(shared const void *));
  assert(dstcnt <= sizeof(dstlist)/sizeof(void *));

  handle = upc_memget_ilist_async(dstcnt, dstlist, 3*sizeof(uint64_t),
                                   srccnt, srclist,2*sizeof(uint64_t));
  /* perform some independent computations here */
  upc_sync(handle);
  /* now safe to operate on result */
  CHECK(0,  TEST_VAL(0,10));
  CHECK(1,  TEST_VAL(0,11));
  CHECK(2,  TEST_VAL(0,20));
  CHECK(10, TEST_VAL(0,21));
  CHECK(11, TEST_VAL(0,30));
  CHECK(12, TEST_VAL(0,31));

  CHECK(20,  TEST_VAL(1,10));
  CHECK(21,  TEST_VAL(1,11));
  CHECK(22,  TEST_VAL(1,20));
  CHECK(30, TEST_VAL(1,21));
  CHECK(31, TEST_VAL(1,30));
  CHECK(32, TEST_VAL(1,31));

  CHECK(40,  TEST_VAL(1,10));
  CHECK(41,  TEST_VAL(1,11));
  CHECK(42,  TEST_VAL(2,20));
  CHECK(50, TEST_VAL(2,21));
  CHECK(51, TEST_VAL(2,30));
  CHECK(52, TEST_VAL(2,31));

  CHECK(60,  TEST_VAL(3,10));
  CHECK(61,  TEST_VAL(3,11));
  CHECK(62,  TEST_VAL(4,20));
  CHECK(70, TEST_VAL(4,21));
  CHECK(71, TEST_VAL(5,30));
  CHECK(72, TEST_VAL(5,31));

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

#if TEST_FSTRIDED
shared [] uint64_t fs_A[1000]; /* shared array */
uint64_t fs_B[1000]; /* local array */
void fstridedtest() {
  if (MYTHREAD == 0) { printf("fstridedtest...\n"); fflush(stdout); sleep(1); }
  upc_barrier;
  int i,j;
  uint64_t val = 0;
  size_t dstchunklen = 10;
  size_t dstchunkstride = 20;
  size_t dstchunkcount = 40;
  size_t srcchunklen = 20;
  size_t srcchunkstride = 40;
  size_t srcchunkcount = 20;

  if (MYTHREAD == 0) {
    for (i=0; i < 1000; i++) fs_A[i] = i;
  }
  upc_barrier;

  upc_handle_t handle = upc_memget_fstrided_async(fs_B, dstchunklen*sizeof(uint64_t), dstchunkstride*sizeof(uint64_t), dstchunkcount,
                                                  fs_A, srcchunklen*sizeof(uint64_t), srcchunkstride*sizeof(uint64_t), srcchunkcount);
  /* perform some independent computations here */
  upc_sync(handle);
  /* now safe to operate on result */
  for (i=0; i < dstchunkcount; i++) {
    for (j=0; j < dstchunklen; j++) {
      uint64_t actual = fs_B[i*dstchunkstride+j];
      if (actual != val) {
        printf("%i: ERROR - fs_B[%i*%i+%i]=%016llx, should be %016llx\n", MYTHREAD, 
               i,(int)dstchunkstride,j,
               (unsigned long long)actual, (unsigned long long)val);
        fflush(stdout);
      }
      if (val % srcchunklen == srcchunklen-1) { val -= srcchunklen-1; val += srcchunkstride; }
      else val++;
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

  #if TEST_FSTRIDED
    fstridedtest();
  #endif

  upc_barrier;
  if (MYTHREAD == 0) printf("done.\n");
  return 0;
}

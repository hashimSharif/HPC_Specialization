/*    $Source: bitbucket.org:berkeleylab/upc-runtime.git/upc-tests/benchmarks/upc_io_test.upc $ */
/*  Description: UPC I/O test */
/*  Copyright 2004, Dan Bonachea <bonachea@cs.berkeley.edu> */

#include <upc_relaxed.h>
#include <upc_io.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <time.h>
#include <inttypes.h>

#define VAL_T int32_t
#define VAL_SZ sizeof(VAL_T)
#define VAL(idx) (VAL_T)(idx)
#ifndef SZ
#define SZ 100
#endif

#ifndef TEST_LISTIO
#define TEST_LISTIO 1
#endif

#ifndef MIN
#define MIN(x,y)  ((x)<(y)?(x):(y))
#endif
#ifndef MAX
#define MAX(x,y)  ((x)>(y)?(x):(y))
#endif

shared [1]  VAL_T arr_cyclic[SZ*THREADS];
shared [SZ] VAL_T arr_blocked[SZ*THREADS];
shared [SZ] VAL_T arr_blockcyclic[SZ*SZ*THREADS];
shared []   VAL_T arr_indef[SZ];
int combined_shared_sz;
VAL_T larr[SZ];
VAL_T larr2[SZ];
 
shared [1] int errs[THREADS];
shared [] int tmp[100];

void setup_vals();
void clear_vals();
void verify_vals(int vershared, int verlocal, int allzero);

void setup_vals() {
  VAL_T i=0;
  #define SETUP_ARR(array) do {                                                                \
    upc_forall(int idx=0; idx < sizeof(array)/upc_elemsizeof(array); idx++,i++; &array[idx]) { \
      array[idx] = VAL(i);                                                                     \
    } } while (0)

  //MSG0("setting up values...\n");
  SETUP_ARR(arr_cyclic);
  SETUP_ARR(arr_blocked);
  SETUP_ARR(arr_blockcyclic);
  SETUP_ARR(arr_indef);

  for(int idx=0; idx < SZ; idx++,i++) {
    larr[idx] = VAL(MYTHREAD*SZ+i);
  }
  i += THREADS*SZ;
  for(int idx=0; idx < SZ; idx++,i++) {
    larr2[idx] = VAL(MYTHREAD*SZ+i);
  }
  i += THREADS*SZ;

  upc_barrier;
  verify_vals(1, 1, 0);
  upc_barrier;
}
void clear_vals() {
  #define CLEAR_ARR(array, mybaseidx)  \
    upc_memset(&(array[mybaseidx]), 0, \
      upc_affinitysize(sizeof(array),upc_elemsizeof(array)*upc_blocksizeof(array),MYTHREAD))

  CLEAR_ARR(arr_cyclic, MYTHREAD);
  CLEAR_ARR(arr_blocked, MYTHREAD*SZ);
  CLEAR_ARR(arr_blockcyclic, MYTHREAD*SZ);
  if (MYTHREAD == 0) CLEAR_ARR(arr_indef, 0);

  memset(larr, 0, sizeof(larr));
  memset(larr2, 0, sizeof(larr2));
}

#define MSG0(str) do {           \
  if (MYTHREAD == 0) {           \
    printf(str); fflush(stdout); \
  } } while(0)

static void check_fail() { /* allow for debugger breakpt */
  static double x = 1.001;
  x *= 1.001;
  #ifdef FAIL_ABORT
    abort();
  #endif
}

#define CHECK_ACTION(expr, failaction) do {                        \
  if ((expr) == 0) {                                               \
    printf("ERROR on thread %i, at %s:%i: failed check %s, "       \
           "errno = %s(%i)\n",                                     \
           (int)MYTHREAD, __FILE__, (int)__LINE__,                 \
           #expr, strerror(errno), (int)errno);                    \
    fflush(stdout);                                                \
    check_fail();                                                  \
    failaction;                                                    \
  } } while(0)

#define CHECK(expr) CHECK_ACTION(expr, errs[MYTHREAD]++ ; errno = 0)

#if 1
  /* disable the errno checks - turns out one cannot rely on the value of
     errno remaining zero in an error-free program, because C99 unfortunately
     allows libraries to set errno to non-zero upon successful completion
     (and apparently some actually do so in practice - at least in Linux)
   */
  #define CHECKERRNO() 
#else
  #define CHECKERRNO() CHECK_ACTION(errno == 0, errs[MYTHREAD]++ ; errno = 0)
#endif

/* used to verify an action that succeeded did not also set errno */
#define CHECK2(expr) do { CHECK(expr); CHECKERRNO(); } while (0)

void verify_vals(int vershared, int verlocal, int allzero) {
  #define VERIFY(array, idx, i) do {                            \
    VAL_T expected = (allzero?0:VAL(i));                        \
    if (array[idx] != expected) {                               \
      printf("ERROR on thread %i: %s[%i] = %i, expected: %i\n", \
        MYTHREAD, #array, idx, (int)array[idx], (int)expected); \
      errs[MYTHREAD]++;                                         \
    } } while (0)

  VAL_T i=0;
  upc_forall(int idx=0; idx < (SZ*THREADS); idx++,i++; &arr_cyclic[idx]) {
    if (vershared) VERIFY(arr_cyclic, idx, i);
  }
  upc_forall(int idx=0; idx < (SZ*THREADS); idx++,i++; &arr_blocked[idx]) {
    if (vershared) VERIFY(arr_blocked, idx, i);
  }
  upc_forall(int idx=0; idx < (SZ*SZ*THREADS); idx++,i++; &arr_blockcyclic[idx]) {
    if (vershared) VERIFY(arr_blockcyclic, idx, i);
  }
  upc_forall(int idx=0; idx < SZ; idx++,i++; 0) {
    if (vershared) VERIFY(arr_indef, idx, i);
  }
  for(int idx=0; idx < SZ; idx++,i++) {
    if (verlocal) VERIFY(larr, idx, MYTHREAD*SZ+i);
  }
  i += THREADS*SZ;
  for(int idx=0; idx < SZ; idx++,i++) {
    if (verlocal) VERIFY(larr2, idx, MYTHREAD*SZ+i);
  }
  i += THREADS*SZ;
}

#ifdef VERBOSE
  #define STATUS(msg)  do {                                                            \
    printf("%i at %s:%-4i: %s\n", MYTHREAD, __FILE__, __LINE__, msg ); fflush(stdout); \
  } while (0)
#else
  #define STATUS(msg)
#endif

#define IO_SAFE(expr) do {                          \
    STATUS(#expr);                                  \
    CHECK_ACTION((expr) != -1, upc_global_exit(1)); \
    CHECKERRNO();                                   \
    STATUS(#expr " COMPLETED");                     \
  } while (0)

#define CHECK_FILESZ(fd, sz) do {           \
    upc_off_t cursz;                        \
    IO_SAFE(cursz = upc_all_fget_size(fd)); \
    CHECK(cursz == sz);                     \
  } while (0)

#define CHECK_FP(fd, pos) do {                            \
    upc_off_t _curpos;                                     \
    IO_SAFE(_curpos = upc_all_fseek(fd, 0, UPC_SEEK_CUR)); \
    CHECK(_curpos == pos);                                 \
  } while (0)

#if __UPC_IO__ >= 2
  #define ASYNCNAME(fnname) fnname
  #define ASYNCFLAG  | UPC_ASYNC
#else
  #define ASYNCNAME(fnname) fnname##_async
  #define ASYNCFLAG  
#endif

void do_listio_test(const char *fname, int async, int isshared, int isread);

void doit(int async) { 
  const char *fname = "upc_io_test.tmp";
  {
    errno = 0;
    setup_vals();
    int flags = UPC_RDWR|UPC_COMMON_FP|UPC_CREATE|UPC_TRUNC;
    struct upc_hint *openhints = NULL;
    upc_file_t *fd = upc_all_fopen(fname, flags, 0, openhints);
    CHECK_ACTION(fd != NULL, upc_global_exit(1));
    CHECKERRNO();
    CHECK_FILESZ(fd, 0);
    CHECK_FP(fd, 0);

    #define READWRITE_SHARED(readwrite, array) do {                            \
      upc_off_t curpos;                                                        \
      upc_off_t result;                                                        \
      IO_SAFE(curpos = upc_all_fseek(fd, 0, UPC_SEEK_CUR)); /* fetch pos */    \
      if (async) {                                                             \
        ASYNCNAME(upc_all_f##readwrite##_shared)(fd, array, upc_blocksizeof(array), \
          upc_elemsizeof(array), sizeof(array)/upc_elemsizeof(array),          \
          UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC ASYNCFLAG);                           \
        CHECKERRNO();                                                          \
        CHECK2(upc_all_fcntl(fd, UPC_ASYNC_OUTSTANDING, NULL) == 1);           \
        IO_SAFE(result = upc_all_fwait_async(fd));                             \
      } else {                                                                 \
        IO_SAFE(result =                                                       \
        upc_all_f##readwrite##_shared(fd, array, upc_blocksizeof(array),       \
          upc_elemsizeof(array), sizeof(array)/upc_elemsizeof(array),          \
          UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC));                                    \
      }                                                                        \
      CHECK(result == sizeof(array));                                          \
      CHECK_FP(fd, curpos + sizeof(array));                                    \
    } while (0)

    MSG0("fwrite_shared, COMMONFP...\n");
    READWRITE_SHARED(write, arr_cyclic);
    READWRITE_SHARED(write, arr_blocked);
    READWRITE_SHARED(write, arr_blockcyclic);
    READWRITE_SHARED(write, arr_indef);
    clear_vals();
    IO_SAFE(upc_all_fsync(fd));
    IO_SAFE(upc_all_fseek(fd, 0, UPC_SEEK_SET));
    /*  read them back and check */
    MSG0("fread_shared, COMMONFP...\n");
    READWRITE_SHARED(read, arr_cyclic);
    READWRITE_SHARED(read, arr_blocked);
    READWRITE_SHARED(read, arr_blockcyclic);
    READWRITE_SHARED(read, arr_indef);
    verify_vals(1,0,0);

    /*  check file size manipulations work */
    MSG0("file size manip...\n");
    CHECK_FILESZ(fd, combined_shared_sz);
    IO_SAFE(upc_all_fset_size(fd, combined_shared_sz/2)); /*  truncate */
    CHECK_FILESZ(fd, combined_shared_sz/2);
    IO_SAFE(upc_all_fset_size(fd, 0)); /*  truncate */
    CHECK_FILESZ(fd, 0);
    CHECK2(upc_all_fwrite_shared(fd, &tmp, 0, 1, 1, UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC) == 1); /*  write one byte to zero extend */
    CHECK_FILESZ(fd, combined_shared_sz+1);
    MSG0("read extended file...\n");
    IO_SAFE(upc_all_fseek(fd, 0, UPC_SEEK_SET));
    READWRITE_SHARED(read, arr_cyclic);
    READWRITE_SHARED(read, arr_blocked);
    READWRITE_SHARED(read, arr_blockcyclic);
    READWRITE_SHARED(read, arr_indef);
    verify_vals(1,0,1);
    CHECK2(upc_all_fread_shared(fd, &tmp, 0, 1024, 1, UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC) == 1); /*  check read to EOF */
    CHECK_FP(fd, combined_shared_sz+1);
    setup_vals();

    IO_SAFE(upc_all_fset_size(fd, 0)); /*  truncate */
    CHECK_FILESZ(fd, 0);
    IO_SAFE(upc_all_fset_size(fd, combined_shared_sz)); /*  set size to extend */
    CHECK_FILESZ(fd, combined_shared_sz);
    MSG0("read extended file...\n");
    IO_SAFE(upc_all_fseek(fd, 0, UPC_SEEK_SET));
    READWRITE_SHARED(read, arr_cyclic);
    READWRITE_SHARED(read, arr_blocked);
    READWRITE_SHARED(read, arr_blockcyclic);
    READWRITE_SHARED(read, arr_indef);
  #if 0
    /* extended region has undefined contents */
    verify_vals(1,0,1);
  #endif

    IO_SAFE(upc_all_fpreallocate(fd, combined_shared_sz)); /*  no-op preallocate */
    CHECK_FILESZ(fd, combined_shared_sz);
    IO_SAFE(upc_all_fpreallocate(fd, combined_shared_sz/2)); /*  no-op preallocate */
    CHECK_FILESZ(fd, combined_shared_sz);
    IO_SAFE(upc_all_fpreallocate(fd, combined_shared_sz*2)); /*  grow preallocate */
    CHECK_FILESZ(fd, combined_shared_sz*2);

    MSG0("fcntl tests...\n");
    CHECK2(upc_all_fcntl(fd, UPC_GET_CA_SEMANTICS, NULL) == 0);
    IO_SAFE(upc_all_fcntl(fd, UPC_SET_STRONG_CA_SEMANTICS, NULL));
    CHECK2(upc_all_fcntl(fd, UPC_GET_CA_SEMANTICS, NULL) == UPC_STRONG_CA);
    IO_SAFE(upc_all_fcntl(fd, UPC_SET_WEAK_CA_SEMANTICS, NULL));
    CHECK2(upc_all_fcntl(fd, UPC_GET_CA_SEMANTICS, NULL) == 0);

    CHECK2(upc_all_fcntl(fd, UPC_GET_FL, NULL) == flags);

    IO_SAFE(upc_all_fseek(fd, 100, UPC_SEEK_SET));
    CHECK2(upc_all_fcntl(fd, UPC_GET_FP, NULL) == UPC_COMMON_FP);
    CHECK_FP(fd, 100);
    IO_SAFE(upc_all_fcntl(fd, UPC_SET_INDIVIDUAL_FP, NULL));
    CHECK_FP(fd, 0);
    CHECK2(upc_all_fcntl(fd, UPC_GET_FP, NULL) == UPC_INDIVIDUAL_FP);
    int modflags = (flags & ~(UPC_COMMON_FP)) | UPC_INDIVIDUAL_FP;
    CHECK2(upc_all_fcntl(fd, UPC_GET_FL, NULL) == modflags);
    IO_SAFE(upc_all_fseek(fd, 100, UPC_SEEK_SET));
    CHECK_FP(fd, 100);
    IO_SAFE(upc_all_fcntl(fd, UPC_SET_COMMON_FP, NULL));
    CHECK_FP(fd, 0);
    CHECK2(upc_all_fcntl(fd, UPC_GET_FP, NULL) == UPC_COMMON_FP);
    IO_SAFE(upc_all_fseek(fd, 100, UPC_SEEK_SET));
    CHECK_FP(fd, 100);
    IO_SAFE(upc_all_fcntl(fd, UPC_SET_COMMON_FP, NULL));
    CHECK_FP(fd, 0);
    CHECK2(upc_all_fcntl(fd, UPC_GET_FP, NULL) == UPC_COMMON_FP);


    CHECK2(upc_all_fcntl(fd, UPC_GET_FL, NULL) == flags);
    const char *name;
    IO_SAFE(upc_all_fcntl(fd, UPC_GET_FN, &name));
    CHECK(!strcmp(name, fname));

    const struct upc_hint *hints;
    int numhints;
    IO_SAFE(numhints = upc_all_fcntl(fd, UPC_GET_HINTS, &hints));
    CHECK(numhints == 0);
    struct upc_hint myhint = { "collective buffering", "true" };
    IO_SAFE(numhints = upc_all_fcntl(fd, UPC_SET_HINT, &myhint));
    IO_SAFE(numhints = upc_all_fcntl(fd, UPC_GET_HINTS, &hints));
    CHECK(numhints <= 1);
    if (numhints > 0) {
      CHECK(&hints[0] != &myhint);
      CHECK(!strcmp(hints[0].key, myhint.key));
      CHECK(!strcmp(hints[0].value, myhint.value));
    }
    CHECK2(upc_all_fcntl(fd, UPC_ASYNC_OUTSTANDING, NULL) == 0);

    IO_SAFE(upc_all_fset_size(fd, 0)); /*  truncate */
    CHECK_FILESZ(fd, 0);
    IO_SAFE(upc_all_fclose(fd)); /*  close */
  }

  {
    setup_vals();
    struct upc_hint *openhints = NULL;
    upc_file_t *fd = upc_all_fopen(fname, 
        UPC_RDWR|UPC_INDIVIDUAL_FP|UPC_CREATE|UPC_TRUNC, 
        0, openhints);
    CHECK_ACTION(fd != NULL, upc_global_exit(1));
    CHECKERRNO();
    CHECK_FILESZ(fd, 0);
    CHECK_FP(fd, 0);

    #define READWRITE_LOCAL(readwrite, array) do {                          \
      upc_off_t curpos;                                                     \
      upc_off_t result;                                                     \
      IO_SAFE(curpos = upc_all_fseek(fd, 0, UPC_SEEK_CUR)); /* fetch pos */ \
      if (async) {                                                          \
        ASYNCNAME(upc_all_f##readwrite##_local)(fd, array, 1, sizeof(array),     \
          UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC ASYNCFLAG);                        \
        CHECKERRNO();                                                       \
        CHECK2(upc_all_fcntl(fd, UPC_ASYNC_OUTSTANDING, NULL) == 1);        \
        IO_SAFE(result = upc_all_fwait_async(fd));                          \
      } else {                                                              \
        IO_SAFE(result =                                                    \
        upc_all_f##readwrite##_local(fd, array, 1, sizeof(array),           \
          UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC));                                 \
      }                                                                     \
      CHECK(result == sizeof(array));                                       \
      CHECK_FP(fd, curpos + sizeof(array));                                 \
    } while (0)

    MSG0("fwrite_local, INDIVIDUALFP...\n");
    IO_SAFE(upc_all_fseek(fd, MYTHREAD*2*SZ*sizeof(VAL_T), UPC_SEEK_SET));
    CHECK_FP(fd, MYTHREAD*2*SZ*sizeof(VAL_T));
    CHECK_FILESZ(fd, 0);
    READWRITE_LOCAL(write, larr);
    READWRITE_LOCAL(write, larr2);
    CHECK_FP(fd, (MYTHREAD+1)*2*SZ*sizeof(VAL_T));
    CHECK_FILESZ(fd, THREADS*2*SZ*sizeof(VAL_T));
    MSG0("fread_local, INDIVIDUALFP...\n");
    clear_vals();
    IO_SAFE(upc_all_fsync(fd));
    IO_SAFE(upc_all_fseek(fd, MYTHREAD*2*SZ*sizeof(VAL_T), UPC_SEEK_SET));
    CHECK_FP(fd, MYTHREAD*2*SZ*sizeof(VAL_T));
    READWRITE_LOCAL(read, larr);
    READWRITE_LOCAL(read, larr2);
    CHECK_FP(fd, (MYTHREAD+1)*2*SZ*sizeof(VAL_T));
    CHECK_FILESZ(fd, THREADS*2*SZ*sizeof(VAL_T));
    verify_vals(0,1,0);
    IO_SAFE(upc_all_fset_size(fd, 0)); /*  truncate */
    CHECK_FILESZ(fd, 0);
    if (MYTHREAD == THREADS-1) {  /*  extend */
      int tmp;
      CHECK2(upc_all_fwrite_local(fd, &tmp, 1, 1, UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC) == 1); /*  write one byte to zero extend */
    } else {
      CHECK2(upc_all_fwrite_local(fd, NULL, 0, 0, UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC) == 0); /*  write one byte to zero extend */
    }
    CHECK_FILESZ(fd, THREADS*2*SZ*sizeof(VAL_T)+1);
    IO_SAFE(upc_all_fsync(fd));
    IO_SAFE(upc_all_fseek(fd, MYTHREAD*2*SZ*sizeof(VAL_T), UPC_SEEK_SET));
    CHECK_FP(fd, MYTHREAD*2*SZ*sizeof(VAL_T));
    READWRITE_LOCAL(read, larr); /*  read undefined data */
    READWRITE_LOCAL(read, larr2);
    CHECK_FP(fd, (MYTHREAD+1)*2*SZ*sizeof(VAL_T));
    CHECK_FILESZ(fd, THREADS*2*SZ*sizeof(VAL_T)+1);
  #if 0
    /* extended region has undefined contents */
    verify_vals(0,1,1);  
  #endif

    #define READWRITE_SHARED_NOOP(readwrite) do {                           \
      upc_off_t curpos;                                                     \
      upc_off_t result;                                                     \
      IO_SAFE(curpos = upc_all_fseek(fd, 0, UPC_SEEK_CUR)); /* fetch pos */ \
      if (async) {                                                          \
        ASYNCNAME(upc_all_f##readwrite##_shared)(fd, NULL, 0, 0, 0,         \
          UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC ASYNCFLAG);                        \
        CHECKERRNO();                                                       \
        CHECK2(upc_all_fcntl(fd, UPC_ASYNC_OUTSTANDING, NULL) == 1);        \
        IO_SAFE(result = upc_all_fwait_async(fd));                          \
      } else {                                                              \
        IO_SAFE(result =                                                    \
        upc_all_f##readwrite##_shared(fd, NULL, 0, 0, 0,                    \
          UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC));                                 \
      }                                                                     \
      CHECK(result == 0);                                                   \
      CHECK_FP(fd, curpos);                                                 \
    } while (0)

    MSG0("fread_shared/fwrite_shared, INDIVIDUALFP...\n");
    for (int active=0; active < THREADS; active++) {
      IO_SAFE(upc_all_fset_size(fd, 0)); /*  truncate */
      IO_SAFE(upc_all_fseek(fd, 0, UPC_SEEK_SET));
      if (MYTHREAD == 0) printf("active thread = %i\n",active);
      setup_vals();
      if (MYTHREAD == active) {
        READWRITE_SHARED(write, arr_cyclic);
        READWRITE_SHARED(write, arr_blocked);
        READWRITE_SHARED(write, arr_blockcyclic);
        READWRITE_SHARED(write, arr_indef);
      } else {
        READWRITE_SHARED_NOOP(write);
        READWRITE_SHARED_NOOP(write);
        READWRITE_SHARED_NOOP(write);
        READWRITE_SHARED_NOOP(write);
      }
      clear_vals();
      IO_SAFE(upc_all_fseek(fd, 0, UPC_SEEK_SET));
      if (MYTHREAD == active) {
        READWRITE_SHARED(read, arr_cyclic);
        READWRITE_SHARED(read, arr_blocked);
        READWRITE_SHARED(read, arr_blockcyclic);
        READWRITE_SHARED(read, arr_indef);
      } else {
        READWRITE_SHARED_NOOP(read);
        READWRITE_SHARED_NOOP(read);
        READWRITE_SHARED_NOOP(read);
        READWRITE_SHARED_NOOP(read);
      }
      verify_vals(1,0,0);
    }

    IO_SAFE(upc_all_fset_size(fd, 0)); /*  truncate */
    CHECK_FILESZ(fd, 0);
    IO_SAFE(upc_all_fclose(fd)); /*  close */
  }

  { /* list I/O tests */
    /* ensure the datatypes are available */
    struct upc_filevec fv = { 10, 20 };
    struct upc_shared_memvec smv = { NULL, 0, 100 };
    struct upc_local_memvec lmv = { NULL, 100 };
    upc_barrier;
    #if TEST_LISTIO
      do_listio_test(fname, async, 0, 0);
      do_listio_test(fname, async, 0, 1);
      do_listio_test(fname, async, 1, 0);
      do_listio_test(fname, async, 1, 1);
    #endif
    upc_barrier;
  }

  upc_barrier;
  return;
}

int _test_rand(int low, int high) {
  int result;
  assert(low <= high);
  result = low+(int)(((double)(high-low+1))*rand()/(RAND_MAX+1.0));
  assert(result >= low && result <= high);
  return result;
}
#define TEST_RAND(low,high) _test_rand((low), (high))
#define TEST_RAND_PICK(a,b) (TEST_RAND(0,1)==1?(a):(b))
#define TEST_SRAND(seed)    srand(seed)
#define TEST_RAND_ONEIN(p)  (TEST_RAND(1,p) == 1)

/* shuffle the ordering in a list */
#define SHUFFLE_ARRAY(T, list, cnt) do {  \
    size_t _i;                            \
    for (_i=0;_i<(cnt);_i++) {            \
      size_t _a = TEST_RAND(_i, (cnt)-1); \
      T _tmp = (list)[_a];                \
      (list)[_a] = (list)[_i];            \
      (list)[_i] = _tmp;                  \
    }                                     \
  } while(0)

#define MAX_VECLEN 1000

#define make_xvec_datasz(x, T)                        \
  upc_off_t get_##x##vec_datasz(size_t cnt, T *vec) { \
    upc_off_t sz = 0;                                 \
    for (size_t i = 0; i < cnt; i++) {                \
      assert(vec[i].len >= 0);                        \
      sz += vec[i].len;                               \
    }                                                 \
    return sz;                                        \
  }
make_xvec_datasz(smem, struct upc_shared_memvec)
make_xvec_datasz(pmem, struct upc_local_memvec)
make_xvec_datasz(f, struct upc_filevec)

#define make_fvec(cnt,vec,min,max,allowoverlap) do {        \
    size_t fcnt;                                            \
    vec = rand_offsetlen(&fcnt, min, max, allowoverlap, 0); \
    cnt = fcnt;                                             \
  } while (0)

#define make_smemvec(cnt,vec,arr,blocksz,allowoverlap) do {                               \
    size_t fcnt;                                                                          \
    /* size_t blocksz = upc_blocksizeof(arr)*upc_elemsizeof(arr);                         \
           -- compiler bug workaround */                                                  \
    struct upc_filevec *flst = rand_offsetlen(&fcnt, 0,                                   \
                            sizeof(arr)/upc_elemsizeof(arr)-1, allowoverlap, 1);          \
    struct upc_shared_memvec *lst;                                                        \
    if (fcnt == 0) lst = NULL;                                                            \
    else {                                                                                \
      lst = malloc(fcnt*sizeof(struct upc_shared_memvec));                                \
      for (size_t i = 0; i < fcnt; i++) {                                                 \
        assert(flst->offset % VAL_SZ == 0);                                               \
        lst[i].baseaddr = &((arr)[flst->offset/upc_elemsizeof(arr)]);                     \
        lst[i].blocksize = blocksz;                                                       \
        assert(flst->len % VAL_SZ == 0);                                                  \
        if (lst[i].blocksize > VAL_SZ && flst->offset % lst[i].blocksize != 0)            \
          lst[i].len = MIN(flst->len, /* dont allow wrapping if base has nonzero phase */ \
                    lst[i].blocksize - (flst->offset % lst[i].blocksize));                \
        else                                                                              \
          lst[i].len = flst->len;                                                         \
        assert(lst[i].blocksize == 0 || flst->offset % lst[i].blocksize == 0 ||           \
               (flst->offset % lst[i].blocksize) + lst[i].len <= lst[i].blocksize);       \
        assert(lst[i].blocksize % VAL_SZ == 0);                                           \
        assert(lst[i].len % VAL_SZ == 0);                                                 \
        flst++;                                                                           \
      }                                                                                   \
    }                                                                                     \
    cnt = fcnt;                                                                           \
    vec = lst;                                                                            \
  } while(0)

#define make_pmemvec(cnt,vec,arr,allowoverlap) do {                 \
    size_t fcnt;                                                    \
    struct upc_filevec *flst = rand_offsetlen(&fcnt, 0,             \
                            sizeof(arr)/VAL_SZ-1, allowoverlap, 1); \
    struct upc_local_memvec *lst;                                   \
    if (fcnt == 0) lst = NULL;                                      \
    else {                                                          \
      lst = malloc(fcnt*sizeof(struct upc_local_memvec));           \
      for (size_t i = 0; i < fcnt; i++) {                           \
        lst[i].baseaddr = &((arr)[flst->offset/VAL_SZ]);            \
        assert(flst->len % VAL_SZ == 0);                            \
        lst[i].len = flst->len;                                     \
        assert(lst[i].len % VAL_SZ == 0);                           \
        flst++;                                                     \
      }                                                             \
    }                                                               \
    cnt = fcnt;                                                     \
    vec = lst;                                                      \
  } while(0)

/* generate and return a randomized list of byte offset/length tuples, with the 
   given properties. {low,high}_offset are the element offsets that vecs should target
   *cnt gets the size of the returned array
*/
struct upc_filevec *rand_offsetlen(size_t *cnt, size_t low_offset, size_t high_offset, 
                              int allowoverlap, int allowunordered) {
  struct upc_filevec *retval;
  size_t elemlen = high_offset - low_offset + 1;
  size_t count = TEST_RAND_PICK(TEST_RAND(1, MIN(MAX_VECLEN,elemlen)),
                 TEST_RAND(1, TEST_RAND(1, TEST_RAND(1, MIN(MAX_VECLEN,elemlen)))));
  size_t per = 0;
  if (TEST_RAND_ONEIN(20)) count = 0;
  if (count == 0) {
    *cnt = 0;
    return NULL;
  }
  per = elemlen / count; 
  retval = malloc(count*sizeof(struct upc_filevec));
  assert(retval != NULL);

  if (allowoverlap && allowunordered) {
    size_t i;
    for (i = 0; i < count; i++) {
      size_t offset = TEST_RAND(0, elemlen-1);
      size_t len = TEST_RAND(0, MIN(per,elemlen-offset));
      if (TEST_RAND_ONEIN(20)) {
        retval[i].offset = 0;
        retval[i].len = 0;
      } else {
        retval[i].offset = (low_offset+offset)*VAL_SZ;
        retval[i].len = len*VAL_SZ;
      }
      assert(retval[i].offset >= 0);
      assert(retval[i].len >= 0);
    }
  } else {
    /* build non-overlapping, monotonically increasing vectors */
    if (TEST_RAND_PICK(0,1)) {
      size_t i;
      size_t lim = 0;
      for (i = 0; i < count; i++) {
        if (TEST_RAND_ONEIN(20)) {
          retval[i].offset = 0;
          retval[i].len = 0;
        } else {
          size_t offset = TEST_RAND(lim, per*(i+1)-1);
          size_t len = TEST_RAND(0, per*(i+1)-offset);
          retval[i].offset = (low_offset+offset)*VAL_SZ;
          retval[i].len = len*VAL_SZ;
          lim = offset + len;
          assert(lim <= per*(i+1) && lim <= elemlen);
        }
        assert(retval[i].offset >= 0);
        assert(retval[i].len >= 0);
      }
    } else {
      size_t i;
      size_t lim = 0;
      for (i = 0; i < count; i++) {
        if (TEST_RAND_ONEIN(20)) {
          retval[i].offset = 0;
          retval[i].len = 0;
        } else {
          size_t offset = TEST_RAND(lim, lim+(elemlen-lim)/4);
          size_t len = TEST_RAND(0, (elemlen-offset)/2);
          retval[i].offset = (low_offset+offset)*VAL_SZ;
          retval[i].len = len*VAL_SZ;
          lim = offset + len;
          assert(lim <= elemlen);
        }
        assert(retval[i].offset >= 0);
        assert(retval[i].len >= 0);
      }
    }
  }

  { size_t i;
    for (i = 0; i < count; i++) {
      assert(retval[i].offset >= 0);
      assert(retval[i].len >= 0);
    }
  }
  if (allowunordered) SHUFFLE_ARRAY(struct upc_filevec, retval, count);
  *cnt = count;
  return retval;
}

/* not a fully general blocked addition fn - just the cases we need */
shared void *add_shared(shared void *ptr, size_t blocksz_bytes, size_t inc_bytes) {
  assert(inc_bytes % VAL_SZ == 0);
  switch (blocksz_bytes) {
    case 0: {
      shared [] VAL_T *p = ptr;
      return p + (inc_bytes/VAL_SZ);
    }
    case VAL_SZ: {
      shared [1] VAL_T *p = ptr;
      return p + (inc_bytes/VAL_SZ);
    }
    case SZ*VAL_SZ: {
      shared [SZ] VAL_T *p = ptr;
      return p + (inc_bytes/VAL_SZ);
    }
    default: abort();
  }
  { shared void *null = NULL;
    return null;
  }
}

#if TEST_LISTIO
void do_listio_test(const char *fname, int isasync, int isshared, int isread) {
  int flags = UPC_RDWR|UPC_INDIVIDUAL_FP|UPC_CREATE|UPC_TRUNC;
  struct upc_hint *openhints = NULL;
  upc_file_t *fd = upc_all_fopen(fname, flags, 0, openhints);
  CHECK_ACTION(fd != NULL, upc_global_exit(1));
  CHECKERRNO();
  CHECK_FILESZ(fd, 0);
  CHECK_FP(fd, 0);

  if (MYTHREAD == 0) printf("listIO %s %s...\n", (isshared?"shared":"local"), (isread?"read":"write"));
  upc_barrier;
  
  #ifdef __UPC_IO_TYPEDEFS__ 
  if (0) { /* the deprecated UPC-IO types - don't actually execute this code, just ensure it typechecks */
    upc_shared_memvec_t sm;
    upc_local_memvec_t lm;
    upc_filevec_t fv;
    upc_hint_t hint;
    upc_all_fopen(NULL, 0, 1, &hint);
    upc_all_fread_list_shared(fd, 1, &sm, 1, &fv, 0);
    upc_all_fread_list_local(fd, 1, &lm, 1, &fv, 0);
  }
  #endif

  { /* setup array vecs */
    #define NUM_SARR 4
    struct upc_local_memvec *pmemvec = NULL;
    size_t pmemvec_cnt;
    static size_t shared [1] pmemvec_datasz[THREADS];
    static size_t shared full_smemvec_datasz;
    static size_t shared full_smemvec_cnt = 0;
    static struct upc_shared_memvec shared [] * shared full_smemvec = NULL;
    size_t smemvec_datasz;
    size_t smemvec_cnt = 0;
    struct upc_shared_memvec *smemvec = NULL;
    static struct upc_filevec shared [] * shared full_filevec = NULL;
    static size_t shared full_filevec_cnt;
    static size_t shared full_filevec_datasz;
    struct upc_filevec *filevec;
    size_t filevec_cnt;
    size_t filevec_datasz;
    upc_off_t upper_file_sz;
    if (isshared && MYTHREAD == 0) {
      struct upc_shared_memvec *arr_smemvec[NUM_SARR];
      size_t arr_smemvec_cnt[NUM_SARR];
      struct upc_shared_memvec shared [] * tmp;
     do {
      memset(arr_smemvec, 0, sizeof(struct upc_shared_memvec*)*NUM_SARR);
      memset(arr_smemvec_cnt, 0, sizeof(size_t)*NUM_SARR);
      make_smemvec(arr_smemvec_cnt[0], arr_smemvec[0], arr_cyclic, VAL_SZ*1, !isread);
      make_smemvec(arr_smemvec_cnt[1], arr_smemvec[1], arr_blocked, VAL_SZ*SZ, !isread);
      make_smemvec(arr_smemvec_cnt[2], arr_smemvec[2], arr_blockcyclic, VAL_SZ*SZ, !isread);
      make_smemvec(arr_smemvec_cnt[3], arr_smemvec[3], arr_indef, 0, !isread);
      full_smemvec_cnt = 0;
      for (int i=0; i < NUM_SARR; i++) full_smemvec_cnt += arr_smemvec_cnt[i];
      full_smemvec = upc_alloc(sizeof(struct upc_shared_memvec)*full_smemvec_cnt);
      tmp = full_smemvec; /* concat the memvecs into full_smemvec */
      for (int i=0; i < NUM_SARR; i++) {
        upc_memput(tmp, arr_smemvec[i], sizeof(struct upc_shared_memvec)*arr_smemvec_cnt[i]);
        free(arr_smemvec[i]);
        tmp += arr_smemvec_cnt[i];
      }
      full_smemvec_datasz = get_smemvec_datasz(full_smemvec_cnt, (struct upc_shared_memvec*)full_smemvec);
      assert(full_smemvec_datasz % VAL_SZ == 0);
     } while (full_smemvec_datasz == 0); /* ensure non-empty for simplicity */
    }
    if (!isshared) {
      make_pmemvec(pmemvec_cnt, pmemvec, larr, !isread);
      pmemvec_datasz[MYTHREAD] = get_pmemvec_datasz(pmemvec_cnt, pmemvec);
      assert(pmemvec_datasz[MYTHREAD] % VAL_SZ == 0);
    }
    upc_barrier;
    if (MYTHREAD == 0) { /* make a file vec */
      upc_off_t neededsz = 0;
      upc_off_t neededsz_bytes = 0;
      upc_off_t low, high;
      struct upc_filevec *filevec;

      if (isshared) neededsz_bytes += full_smemvec_datasz;
      else for (int i=0; i < THREADS; i++) neededsz_bytes += pmemvec_datasz[i];
      assert(neededsz_bytes % VAL_SZ == 0);
      neededsz = neededsz_bytes/VAL_SZ;
      while (1) {
        low = TEST_RAND(0, neededsz);
        high = TEST_RAND(low+(int)(1.10*neededsz), low+4*neededsz);
        make_fvec(full_filevec_cnt, filevec, low, high, isread);
        full_filevec_datasz = get_fvec_datasz(full_filevec_cnt, filevec);
        assert(full_filevec_datasz % VAL_SZ == 0);
        if (full_filevec_datasz > 0 &&
            full_filevec_datasz >= neededsz_bytes) break;
        free(filevec);
      }
      assert(full_filevec_cnt > 0); /* for simplicity */
      full_filevec = upc_alloc(sizeof(struct upc_filevec)*full_filevec_cnt);
      for (int i = 0; i < full_filevec_cnt; i++) {
        full_filevec[i] = filevec[i];
        assert(full_filevec[i].offset >= 0);
        assert(full_filevec[i].len >= 0);
        if (filevec[i].len >= neededsz_bytes) {
          full_filevec[i].len = neededsz_bytes;
          full_filevec_cnt = i+1;
          break;
        } 
        neededsz_bytes -= filevec[i].len;
      }
      full_filevec_datasz = get_fvec_datasz(full_filevec_cnt, (struct upc_filevec*)full_filevec);
      assert(full_filevec_datasz % VAL_SZ == 0);
      assert(full_filevec_datasz == neededsz*VAL_SZ);
      free(filevec);
    }    
    upc_barrier;
    
    /* split full_smemvec and full_filevec amongst threads into smemvec and filevec */
    if (isshared) { 
    #if 0
      /* this algorithm breaks vecs without regard to blocksize boundaries - BAD */
      static size_t shared smemvec_split[THREADS];
      if (MYTHREAD == 0) {
        size_t per = full_smemvec_datasz / THREADS;
        size_t pos = 0;
        for (int i = 0; i < THREADS; i++) {
          size_t mysz = TEST_RAND(0, MIN(per,full_smemvec_datasz-pos)/VAL_SZ)*VAL_SZ;
          pos += mysz;
          smemvec_split[i] = mysz;
        }
        smemvec_split[THREADS-1] += full_smemvec_datasz-pos;
      }
      upc_barrier;
      { size_t pos = 0;
        size_t full_smemvec_idx = 0;
        size_t mypos = 0;
        size_t myendpos = 0;
        for (int i=0; i < MYTHREAD; i++) mypos += smemvec_split[i];
        myendpos = mypos + smemvec_split[MYTHREAD];
        while (pos < mypos &&
               pos + full_smemvec[full_smemvec_idx].len <= mypos) {
          pos += full_smemvec[full_smemvec_idx].len;
          full_smemvec_idx++;
        }
        smemvec = malloc(sizeof(struct upc_shared_memvec)*full_smemvec_cnt);
        smemvec_cnt = 0;
        if (pos < mypos) { /* break prev entry */
          size_t thisoff = (mypos-pos);
          size_t thislen = MIN(full_smemvec[full_smemvec_idx].len - thisoff, myendpos-mypos);
          smemvec[smemvec_cnt].baseaddr = 
            add_shared(full_smemvec[full_smemvec_idx].baseaddr, 
                       full_smemvec[full_smemvec_idx].blocksize,
                       thisoff);
          smemvec[smemvec_cnt].blocksize = full_smemvec[full_smemvec_idx].blocksize;
          smemvec[smemvec_cnt].len = thislen;
          pos += thisoff+thislen;
          smemvec_cnt++;
          full_smemvec_idx++;
          assert(smemvec_cnt <= full_smemvec_cnt);
          assert(full_smemvec_idx <= full_smemvec_cnt);
        }
        assert(pos >= mypos);
        while (pos < myendpos &&
               full_smemvec[full_smemvec_idx].len <= myendpos) {
          smemvec[smemvec_cnt] = full_smemvec[full_smemvec_idx];
          pos += full_smemvec[full_smemvec_idx].len;
          smemvec_cnt++;
          full_smemvec_idx++;
          assert(smemvec_cnt <= full_smemvec_cnt);
          assert(full_smemvec_idx <= full_smemvec_cnt);
        }
        if (pos < myendpos) { /* break next entry */
          size_t thislen = (myendpos-pos);
          smemvec[smemvec_cnt] = full_smemvec[full_smemvec_idx];
          assert(smemvec[smemvec_cnt].len >= thislen);
          smemvec[smemvec_cnt].len = thislen;
          pos += thislen;
          smemvec_cnt++;
          full_smemvec_idx++;
          assert(smemvec_cnt <= full_smemvec_cnt);
          assert(full_smemvec_idx <= full_smemvec_cnt);
        }
        assert(pos == myendpos);
        assert(smemvec_cnt <= full_smemvec_cnt);
        assert(full_smemvec_idx <= full_smemvec_cnt);
        smemvec_datasz = get_smemvec_datasz(smemvec_cnt, smemvec);
        assert(smemvec_datasz == smemvec_split[MYTHREAD]);
      }
    #else
      { /* simpler, but correct splitting algorithm */
        size_t shared [] *smemvec_split = upc_all_alloc(1, sizeof(size_t)*full_smemvec_cnt);
        if (MYTHREAD == 0) {
          for (int i = 0; i < full_smemvec_cnt; i++) {
            smemvec_split[i] = TEST_RAND(0,THREADS-1);
          }
        }
        upc_barrier;
        smemvec = malloc(sizeof(struct upc_shared_memvec)*full_smemvec_cnt);
        smemvec_cnt = 0;
        for (int i = 0; i < full_smemvec_cnt; i++) {
          if (smemvec_split[i] == MYTHREAD) {
            smemvec[smemvec_cnt] = full_smemvec[i];
            smemvec_cnt++;
          }
        }
        assert(smemvec_cnt <= full_smemvec_cnt);
        smemvec_datasz = get_smemvec_datasz(smemvec_cnt, smemvec);
        assert(smemvec_datasz % VAL_SZ == 0);
        upc_barrier;
        if (MYTHREAD == 0) upc_free(smemvec_split);
      }
    #endif
    }

    /* split file */
    { static size_t shared file_split[THREADS];
      if (isshared) file_split[MYTHREAD] = get_smemvec_datasz(smemvec_cnt, smemvec);
      else file_split[MYTHREAD] = get_pmemvec_datasz(pmemvec_cnt, pmemvec);
      upper_file_sz = 1;
      for (int i=0; i < full_filevec_cnt; i++) 
        upper_file_sz = MAX(upper_file_sz, full_filevec[i].offset+full_filevec[i].len);
      upc_barrier;
      { size_t pos = 0;
        size_t full_filevec_idx = 0;
        size_t mypos = 0;
        size_t myendpos = 0;
        for (int i=0; i < MYTHREAD; i++) mypos += file_split[i];
        myendpos = mypos + file_split[MYTHREAD];
        while (pos < mypos &&
               pos + full_filevec[full_filevec_idx].len <= mypos) {
          pos += full_filevec[full_filevec_idx].len;
          full_filevec_idx++;
          assert(full_filevec_idx <= full_filevec_cnt);
        }
        filevec = malloc(sizeof(struct upc_filevec)*full_filevec_cnt);
        filevec_cnt = 0;
        if (pos < mypos) { /* break prev entry */
          size_t thisoff = (mypos-pos);
          size_t thislen = MIN(full_filevec[full_filevec_idx].len - thisoff, myendpos-mypos);
          assert(thisoff < full_filevec[full_filevec_idx].len);
          filevec[filevec_cnt].offset = full_filevec[full_filevec_idx].offset + thisoff;
          filevec[filevec_cnt].len = thislen;
          assert(filevec[filevec_cnt].offset >= 0);
          assert(filevec[filevec_cnt].len >= 0);
          pos += thisoff+thislen;
          filevec_cnt++;
          full_filevec_idx++;
          assert(filevec_cnt <= full_filevec_cnt);
          assert(full_filevec_idx <= full_filevec_cnt);
        }
        assert(pos >= mypos);
        while (pos < myendpos &&
               pos + full_filevec[full_filevec_idx].len < myendpos) {
          filevec[filevec_cnt] = full_filevec[full_filevec_idx];
          assert(filevec[filevec_cnt].offset >= 0);
          assert(filevec[filevec_cnt].len >= 0);
          pos += full_filevec[full_filevec_idx].len;
          filevec_cnt++;
          full_filevec_idx++;
          assert(filevec_cnt <= full_filevec_cnt);
          assert(full_filevec_idx <= full_filevec_cnt);
        }
        if (pos < myendpos) { /* break next entry */
          size_t thislen = myendpos-pos;
          filevec[filevec_cnt] = full_filevec[full_filevec_idx];
          filevec[filevec_cnt].len = thislen;
          assert(filevec[filevec_cnt].offset >= 0);
          assert(filevec[filevec_cnt].len >= 0);
          pos += thislen;
          filevec_cnt++;
          full_filevec_idx++;
          assert(filevec_cnt <= full_filevec_cnt);
          assert(full_filevec_idx <= full_filevec_cnt);
        }
        assert(pos == myendpos);
        assert(full_filevec_idx <= full_filevec_cnt);
        assert(filevec_cnt <= full_filevec_cnt);
        filevec_datasz = get_fvec_datasz(filevec_cnt, filevec);
        assert(filevec_datasz == file_split[MYTHREAD]);
      }
      upc_barrier;
    }

    /* prepare file */
    if (isread) {
      /* write known values to the file */
      if (MYTHREAD == 0) {
        VAL_T *tmp = malloc(upper_file_sz);
        upc_off_t elems = upper_file_sz/VAL_SZ;
        for (upc_off_t i = 0; i < elems; i++) {
          tmp[i] = VAL(i);
        }
        IO_SAFE(upc_all_fwrite_local(fd, tmp, 1, upper_file_sz, UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC));
        free(tmp);
      } else {
        IO_SAFE(upc_all_fwrite_local(fd, NULL, 0, 0, UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC));
      }
      IO_SAFE(upc_all_fseek(fd, 0, UPC_SEEK_SET));
    }

    /* prepare data arrays */
    if (isread) clear_vals();
    else setup_vals();

    { /* perform list IO */
      size_t result;
      CHECK(filevec_datasz == get_fvec_datasz(filevec_cnt, filevec));
      if (isshared) {
        CHECK(smemvec_datasz == get_smemvec_datasz(smemvec_cnt, smemvec));
        CHECK(smemvec_datasz == filevec_datasz);
      } else {
        CHECK(pmemvec_datasz[MYTHREAD] == get_pmemvec_datasz(pmemvec_cnt, pmemvec));
        CHECK(pmemvec_datasz[MYTHREAD] == filevec_datasz);
      }
      if (isread) {
        if (isshared) {
          if (isasync) ASYNCNAME(upc_all_fread_list_shared)(fd, smemvec_cnt, smemvec, filevec_cnt, filevec, 0 ASYNCFLAG);
          else IO_SAFE(result = upc_all_fread_list_shared(fd, smemvec_cnt, smemvec, filevec_cnt, filevec, 0));
        } else { /* islocal */
          if (isasync) ASYNCNAME(upc_all_fread_list_local)(fd, pmemvec_cnt, pmemvec, filevec_cnt, filevec, 0 ASYNCFLAG);
          else IO_SAFE(result = upc_all_fread_list_local(fd, pmemvec_cnt, pmemvec, filevec_cnt, filevec, 0));
        }
      } else { /* write */
        if (isshared) {
          if (isasync)  ASYNCNAME(upc_all_fwrite_list_shared)(fd, smemvec_cnt, smemvec, filevec_cnt, filevec, 0 ASYNCFLAG);
          else IO_SAFE(result = upc_all_fwrite_list_shared(fd, smemvec_cnt, smemvec, filevec_cnt, filevec, 0));
        } else { /* islocal */
          if (isasync)  ASYNCNAME(upc_all_fwrite_list_local)(fd, pmemvec_cnt, pmemvec, filevec_cnt, filevec, 0 ASYNCFLAG);
          else IO_SAFE(result = upc_all_fwrite_list_local(fd, pmemvec_cnt, pmemvec, filevec_cnt, filevec, 0));
        }
      }
      if (isasync) {
        CHECKERRNO();
        IO_SAFE(result = upc_all_fwait_async(fd)); 
      }

      CHECK_FP(fd, 0); /* listIO should not affect FPs */
      CHECK(result == filevec_datasz);
    }

    /* verify result */
    { VAL_T *tmp = NULL;
      if (!isread) {  /* read back result into temp */
        tmp = calloc(1,upper_file_sz);
        IO_SAFE(upc_all_fread_local(fd, tmp, 1, upper_file_sz, UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC));
      }
      /* check arrays against vecs */
      if (isshared) {
        size_t filevec_idx = 0;
        size_t filevec_offset = 0;
        for (int i = 0; i < smemvec_cnt; i++) {
        for (int j = 0; j < smemvec[i].len/VAL_SZ; j++) {
          upc_off_t curoff;
          VAL_T fileval;
          VAL_T shared *arrpos;
          VAL_T arrval;
          while (filevec_offset >= filevec[filevec_idx].len) {
            filevec_idx++;
            filevec_offset = 0;
          }
          assert(filevec_idx < filevec_cnt);
          curoff = (filevec[filevec_idx].offset + filevec_offset)/VAL_SZ;
          if (isread) fileval = VAL(curoff);
          else fileval = tmp[curoff];
          arrpos = add_shared(smemvec[i].baseaddr, smemvec[i].blocksize, j*VAL_SZ);
          arrval = *arrpos;
          CHECK(arrval == fileval);
          filevec_offset += VAL_SZ;
        }
        }
      } else { /* islocal */
        size_t filevec_idx = 0;
        size_t filevec_offset = 0;
        for (int i = 0; i < pmemvec_cnt; i++) {
        for (int j = 0; j < pmemvec[i].len/VAL_SZ; j++) {
          upc_off_t curoff;
          VAL_T fileval;
          VAL_T *arrpos;
          while (filevec_offset >= filevec[filevec_idx].len) {
            filevec_idx++;
            filevec_offset = 0;
          }
          assert(filevec_idx < filevec_cnt);
          curoff = (filevec[filevec_idx].offset + filevec_offset)/VAL_SZ;
          if (isread) fileval = VAL(curoff);
          else fileval = tmp[curoff];
          arrpos = (VAL_T*)pmemvec[i].baseaddr;
          CHECK(arrpos[j] == fileval);
          filevec_offset += VAL_SZ;
        }
        }
      }

      if (!isread) free(tmp);
    }
    upc_barrier;

    /* cleanup */
    if (MYTHREAD == 0) {
      #if 0
        /* umalloc intermittently reports a shared heap corruption here, 
           although nothing appears to be wrong - not sure where the problem might be */
        upc_free(full_smemvec);
        upc_free(full_filevec);
      #endif
    }
    free(smemvec);
    free(pmemvec);
    free(filevec);
  }

  upc_barrier;
  IO_SAFE(upc_all_fclose(fd));
  return;
}
#endif
/* ------------------------------------------------------------------------------------ */
int main(int argc, char **argv) {
  uint16_t seed = 0;
  if (argc > 1) seed = atoi(argv[1]);
  if (seed == 0) {
    time_t tm;
    uint16_t *p = (uint16_t *)&tm;
    time(&tm);
    for (int i=0; i < sizeof(time_t)/2; i++) {
      seed = seed ^ p[i];
    }
  }
  TEST_SRAND(MYTHREAD+seed);
  combined_shared_sz = sizeof(arr_cyclic) + sizeof(arr_blocked) + sizeof(arr_blockcyclic) + sizeof(arr_indef);
  if (MYTHREAD == 0) printf("Running UPC-IO tester, THREADS=%i seed=%i\n", THREADS, seed);
  MSG0("*** blocking tests ***\n");
  upc_barrier;
  doit(0);
  upc_barrier;
  MSG0("*** async tests ***\n");
  doit(1);
  upc_barrier;
  if (MYTHREAD == 0) {
    int errsum = 0;
    for (int i = 0; i < THREADS; i++) errsum += errs[i];
    if (errsum) {
      printf("FAILED: detected %i errors\n", errsum);
      upc_global_exit(-1);
    } else {
      printf("SUCCESS: all tests passed\n");
      upc_global_exit(0);
    }
  } else return 0;
}

/* ------------------------------------------------------------------------------------ */



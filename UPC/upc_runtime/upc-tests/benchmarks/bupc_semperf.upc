#include <upc.h>
#include <upc_tick.h>
#include <upc_nb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

#ifndef MIN
#define MIN(x,y)  ((x)<(y)?(x):(y))
#endif
#ifndef MAX
#define MAX(x,y)  ((x)>(y)?(x):(y))
#endif

int shared strict intflags[THREADS];
int partnerid;

/* ---------------------------------------------------------------- */
/* Signalling memput implemented using strict flag write */
void memput_signal(shared void *dst, void *src, size_t nbytes, bupc_sem_t *dummy, size_t dummy2) {
  upc_memput(dst, src, nbytes);
  intflags[partnerid] = 1;    
}
void memput_wait() {
  while (!intflags[MYTHREAD]) {
    bupc_poll();
  }
  intflags[MYTHREAD] = 0;
}

/* ---------------------------------------------------------------- */
/* Signalling memput implemented using a pipelined flag write 
   Note this version is UNSAFE by the UPC memory model, and furthermore only 
   happens to work on some networks which provide ordered delivery, in the 
   absence of compiler optimizations.
 */
void memput_signal_unsafe(shared void *dst, void *src, size_t nbytes, bupc_sem_t *dummy, size_t dummy2) {
  static upc_handle_t myhandle = UPC_COMPLETE_HANDLE;
  if (myhandle != UPC_COMPLETE_HANDLE) upc_sync(myhandle);
  myhandle = upc_memput_nb(dst, src, nbytes);
  intflags[partnerid] = 1;    
}
#define memput_wait_unsafe memput_wait

/* ---------------------------------------------------------------- */
bupc_sem_t * shared allflags[THREADS];
/* Usage: bupc_semperf <max_iters> <maxN> <max_sz> [PFSDWC] 
   P = ping-pong tests
   F = flood tests
   S = post/wait pure sync tests
   D = memput_signal data transfer tests
   W = disable warmup
   C = disable correctness checks
   I = do int-flags perf tests
   T = do sem_t perf tests
*/ 
int main(int argc, char **argv) {
  if (THREADS % 2 != 0) { 
    if (!MYTHREAD) printf("ERROR: this test requires an even thread count\n"); 
    exit(1);
  }
  partnerid = MYTHREAD^1;
  int maxiters = 0, maxN = 0, iters, N;
  int dopingpong = -1, doflood = -1, dosync = -1, dodata = -1, dointflags = -1, dosemt = -1;
  int docheck = 1, dowarm = 1;
  uint64_t maxsz = 0;
  if (argc > 1) maxiters = atoi(argv[1]);
  if (maxiters < 1) maxiters = 1000;
  if (argc > 2) maxN = atoi(argv[2]);
  if (maxN < 1) maxN = 100;
  maxN = MIN(maxN, BUPC_SEM_MAXVALUE);
  if (argc > 3) maxsz = atol(argv[3]);
  if (maxsz < 1) maxsz = 2*1024*1024;
  iters = maxiters;
  N = maxN;
  if (argc > 4) {
    char *p = argv[4];
    for ( ; *p ; p++) {
      switch (toupper(*p)) {
        case 'P': dopingpong = 1; if (doflood < 0)    doflood = 0; break;
        case 'F': doflood = 1;    if (dopingpong < 0) dopingpong = 0; break;
        case 'S': dosync = 1;     if (dodata < 0)     dodata = 0; break;
        case 'D': dodata = 1;     if (dosync < 0)     dosync = 0; break;
        case 'I': dointflags = 1; if (dosemt < 0)     dosemt = 0; break;
        case 'T': dosemt = 1;     if (dointflags < 0) dointflags = 0; break;
        case 'W': dowarm = 0;     break;
        case 'C': docheck = 0;     break;
      }
    }
  }

  shared char *all_bufs = upc_all_alloc(THREADS, maxsz);
  shared [] char *partner_buf = (shared [] char *)&(all_bufs[partnerid]);
  char *mysrc = malloc(maxsz);
  char *mydst = (char *)&(all_bufs[MYTHREAD]);
  bupc_sem_t *myflag;
  bupc_sem_t *partnerflag;

  if (docheck) { 
    static shared int tmp1[THREADS];
    int tmp2;
    int flagm;
    int checkiters = MAX(1,iters/10);

    if (!MYTHREAD) { printf("Initial check...\n"); fflush(stdout); }
   for (flagm = 0; flagm <= 8; flagm++) {
    int flags = 0;
    if (flagm < 8) {
      if (flagm & 0x1) flags |= BUPC_SEM_SPRODUCER;
      else             flags |= BUPC_SEM_MPRODUCER;
      if (flagm & 0x2) flags |= BUPC_SEM_SCONSUMER;
      else             flags |= BUPC_SEM_MCONSUMER;
      if (flagm & 0x3) flags |= BUPC_SEM_INTEGER;
      else             flags |= BUPC_SEM_BOOLEAN;
    }
    upc_barrier;
    myflag = bupc_sem_alloc(flags); 
    /* serial tests */
    bupc_sem_post(myflag);
    bupc_sem_wait(myflag);
    if ((flags & BUPC_SEM_BOOLEAN) == 0) {
      bupc_sem_postN(myflag,5);
      bupc_sem_waitN(myflag,5);
    }
    bupc_sem_post(myflag);
    if (!bupc_sem_try(myflag)) printf("ERROR: try failed\n");
    if (bupc_sem_try(myflag)) printf("ERROR: try worked\n");
    if ((flags & BUPC_SEM_BOOLEAN) == 0) {
      bupc_sem_postN(myflag,N);
      if (!bupc_sem_tryN(myflag,N)) printf("ERROR: try failed\n");
      if (bupc_sem_tryN(myflag,N)) printf("ERROR: try worked\n");
    }
    tmp2 = 13;
    bupc_memput_signal(&tmp1[MYTHREAD], &tmp2, sizeof(tmp2), myflag, 1);
    bupc_sem_wait(myflag);
    assert(tmp1[MYTHREAD] == tmp2);
    tmp2 = 14;
    bupc_memput_signal_async(&tmp1[MYTHREAD], &tmp2, sizeof(tmp2), myflag, 1);
    bupc_sem_wait(myflag);
    assert(tmp1[MYTHREAD] == tmp2);

    /* parallel tests */
    upc_barrier;
    allflags[MYTHREAD] = myflag;
    upc_barrier;
    partnerflag = allflags[partnerid]; /* fetch ptr from remote */
    for (int sz = 0; sz < maxsz; sz = (sz ? sz * 2 : 1)) {
      for (int i=0; i < checkiters; i++) {
        char val = i&0xFF;
        if (((i ^ MYTHREAD) & 0x1) == 0) { /* even threads on even iters */
          memset(mysrc, val, sz);
          bupc_memput_signal(partner_buf, mysrc, sz, partnerflag, 1);
        } else {
          bupc_sem_wait(myflag);
          for (int j = sz-1; j >= 0; j--) {
            char const tval = mydst[j];
            if (tval != val) {
               fprintf(stderr,"ERROR: mismatch on th%i at sz=%i i=%i j=%i: tval=%02x val=%02x\n",
                      MYTHREAD,sz,i,j,(int)tval,(int)val);
            }
          }
        }
      }
    }
    upc_barrier;
    if ((flags & BUPC_SEM_MPRODUCER)) { // run a mproducer test where everybody signals zero
      bupc_sem_t *zsem = allflags[0];
      shared [] int *zints = upc_all_alloc(1,sizeof(int)*THREADS);
      for (int i=0; i < checkiters; i++) {
        if (!MYTHREAD) upc_memset(zints, -1, sizeof(int)*THREADS);
        upc_barrier;
        int myth = MYTHREAD+1000;
        if ((flags & BUPC_SEM_INTEGER) || (i%THREADS) == MYTHREAD) {
          bupc_memput_signal(&(zints[MYTHREAD]), &myth, sizeof(int), zsem, 1);
        }
        if (!MYTHREAD) {
          if (flags & BUPC_SEM_INTEGER) {
            bupc_sem_waitN(myflag,THREADS);
            for (int j=0; j < THREADS; j++) {
              int val = zints[j];
              if (val != j+1000) {
               fprintf(stderr,"ERROR: mismatch on multi-test/bool i=%i j=%i val=%04x expected=%04x\n",
                             i,j,val,j+1000);
              }
            }
          } else {
            bupc_sem_wait(myflag);
            int val = zints[i%THREADS];
            if (val != (i%THREADS)+1000) {
               fprintf(stderr,"ERROR: mismatch on multi-test/bool i=%i val=%04x expected=%04x\n",
                             i,val,(i%THREADS)+1000);
            }
          }
        }
        upc_barrier;
      }
      upc_barrier;
      if (!MYTHREAD) upc_free(zints);
    }

    assert(BUPC_SEM_MAXVALUE >= 65535);
    bupc_sem_free(myflag);
    upc_barrier;
   }
    if (!MYTHREAD) printf("Initial check complete.\n\n");
  }

  /* create semaphores and exchange information */
  upc_barrier;
  myflag = bupc_sem_alloc(BUPC_SEM_SPRODUCER|BUPC_SEM_SCONSUMER); 
  allflags[MYTHREAD] = myflag;
  upc_barrier;
  partnerflag = allflags[partnerid]; /* fetch ptr from remote */

  for (int i = 0; i < maxsz; i++) { /* fill area with some fixed data of mixed byte values */
    mysrc[i] = (char)i;
  }

  /* ------------------------------------------------------------------------------------ */
  if (dowarm) { /* warm-up code */
    int warmiters = MIN(BUPC_SEM_MAXVALUE, iters/10);
    upc_barrier;
    for (int i=0; i < warmiters; i++) {
      bupc_sem_post(partnerflag); /* send notification */
    }
    bupc_sem_waitN(myflag,warmiters);
    upc_barrier;
    int cnt = 0;
    for (int sz = 1; sz < maxsz; sz *= 2) {
      cnt++;
      bupc_memput_signal(partner_buf, mysrc, sz, partnerflag, 1);
    }
    bupc_sem_waitN(myflag,cnt);
    upc_barrier;
    cnt = 0;
    for (int sz = 1; sz < maxsz; sz *= 2) {
      cnt++;
      bupc_memput_signal_async(partner_buf, mysrc, sz, partnerflag, 1);
    }
    bupc_sem_waitN(myflag,cnt);
    upc_barrier;
  }
  /* ------------------------------------------------------------------------------------ */
  if (dosync && dopingpong && dosemt) { 
    upc_barrier;
    if (!MYTHREAD) 
      printf("Measuring bupc_sem_post/wait ping-pong latency, iters=%i\n", iters);
    upc_barrier;

    /* play ping-pong with semaphores to measure latency */
    upc_tick_t ticks = upc_ticks_now();
    if (!(MYTHREAD&1)) { /* even threads */
      for (int i=0; i < iters; i++) {
        bupc_sem_post(partnerflag); /* send notification */
        bupc_sem_wait(myflag); /* wait for response */
      }
    } else { /* odd threads */
       for (int i=0; i < iters; i++) {
        bupc_sem_wait(myflag); /* wait for notification from partner */
        bupc_sem_post(partnerflag); /* bounce it back to partner */
      }
    }
    ticks = upc_ticks_now() - ticks;

    upc_barrier;

    if (!(MYTHREAD&1)) {
      double timeus = upc_ticks_to_ns(ticks) / 1000;
      printf("%i: Total time=%5.3f sec   one-way latency:    %7.3f us\n\n",
              MYTHREAD, timeus/1E6, timeus/iters/2); fflush(NULL);
    }
  }
  /* ------------------------------------------------------------------------------------ */
  if (dosync && doflood && dosemt) { 
    int iters = MIN(maxiters, BUPC_SEM_MAXVALUE);
    upc_barrier;
    if (!MYTHREAD) 
      printf("Measuring bupc_sem_post/wait one-way flood throughput, iters=%i\n", iters);
    upc_barrier;

    /* send a semaphore post flood to measure thoughput */
    upc_tick_t ticks = upc_ticks_now();
    if (!(MYTHREAD&1)) { /* even threads */
      for (int i=0; i < iters; i++) {
        bupc_sem_post(partnerflag); /* notify partner */
      }
    } else { /* odd threads */
      for (int i=0; i < iters; i++) {
        bupc_sem_wait(myflag); /* wait for notification from partner */
      }
    }
    upc_barrier; /* ensure remote side has recvd all the signals */
    ticks = upc_ticks_now() - ticks;

    upc_barrier;

    if (!(MYTHREAD&1)) {
      double timeus = upc_ticks_to_ns(ticks) / 1000;
      printf("%i: Total time=%5.3f sec   inverse throughput: %7.3f us\n\n",
              MYTHREAD, timeus/1E6, timeus/iters); fflush(NULL);
    }
  }
  /* ------------------------------------------------------------------------------------ */
  if (dosync && dopingpong && dosemt) { 
    upc_barrier;
    if (!MYTHREAD) 
      printf("Measuring bupc_sem_postN/waitN ping-pong latency, iters=%i, N=%i\n", iters, N);
    upc_barrier;

    /* play ping-pong with semaphores to measure latency */
    upc_tick_t ticks = upc_ticks_now();
    if (!(MYTHREAD&1)) { /* even threads */
      for (int i=0; i < iters; i++) {
        bupc_sem_postN(partnerflag,N); /* send notification */
        bupc_sem_waitN(myflag,N); /* wait for response */
      }
    } else { /* odd threads */
       for (int i=0; i < iters; i++) {
        bupc_sem_waitN(myflag,N); /* wait for notification from partner */
        bupc_sem_postN(partnerflag,N); /* bounce it back to partner */
      }
    }
    ticks = upc_ticks_now() - ticks;

    upc_barrier;

    if (!(MYTHREAD&1)) {
      double timeus = upc_ticks_to_ns(ticks) / 1000;
      printf("%i: Total time=%5.3f sec   one-way latency:    %7.3f us\n\n",
              MYTHREAD, timeus/1E6, timeus/iters/2); fflush(NULL);
    }
  }
  /* ------------------------------------------------------------------------------------ */
  if (dosync && doflood && dosemt) { 
    int N = MAX(2,MIN(((int64_t)maxN)*maxiters, BUPC_SEM_MAXVALUE)/maxiters);
    int iters = MIN(((int64_t)N)*maxiters, BUPC_SEM_MAXVALUE)/N;
    upc_barrier;
    if (!MYTHREAD) 
      printf("Measuring bupc_sem_postN/waitN one-way flood throughput, iters=%i, N=%i\n", iters, N);
    upc_barrier;

    /* send a semaphore post flood to measure thoughput */
    upc_tick_t ticks = upc_ticks_now();
    if (!(MYTHREAD&1)) { /* even threads */
      for (int i=0; i < iters; i++) {
        bupc_sem_postN(partnerflag,N); /* notify partner */
      }
    } else { /* odd threads */
      for (int i=0; i < iters; i++) {
        bupc_sem_waitN(myflag,N); /* wait for notification from partner */
      }
    }
    upc_barrier; /* ensure remote side has recvd all the signals */
    ticks = upc_ticks_now() - ticks;

    upc_barrier;

    if (!(MYTHREAD&1)) {
      double timeus = upc_ticks_to_ns(ticks) / 1000;
      printf("%i: Total time=%5.3f sec   inverse throughput: %7.3f us\n\n",
              MYTHREAD, timeus/1E6, timeus/iters); fflush(NULL);
    }
  }
  /* ------------------------------------------------------------------------------------ */
  #define PINGPONG_PUT(DESC_STR,PUT_OP,WAIT_OP) do {                                       \
    upc_barrier;                                                                           \
    if (!MYTHREAD)                                                                         \
      printf("Measuring "DESC_STR" ping-pong latency/throughput test, iters=%i\n", iters); \
    upc_barrier;                                                                           \
    int sz, i;                                                                             \
    for (sz = 1; sz <= maxsz; sz *= 2) {                                                   \
      upc_tick_t ticks = upc_ticks_now();                                                  \
      if (!(MYTHREAD&1)) { /* even threads */                                              \
        for (i=0; i < iters; i++) {                                                        \
          PUT_OP(partner_buf, mysrc, sz, partnerflag, 1); /* send data/notification */     \
          WAIT_OP; /* wait for response */                                                 \
        }                                                                                  \
      } else { /* odd threads */                                                           \
         for (i=0; i < iters; i++) {                                                       \
          WAIT_OP; /* wait for notification from partner */                                \
          PUT_OP(partner_buf, mysrc, sz, partnerflag, 1); /* send data/notification */     \
        }                                                                                  \
      }                                                                                    \
      ticks = upc_ticks_now() - ticks;                                                     \
      upc_barrier;                                                                         \
      if (!(MYTHREAD&1)) {                                                                 \
        double timeus = upc_ticks_to_ns(ticks) / 1000;                                     \
        printf("%i: %8i bytes  one-way latency:    %10.3f us (%8.3f MB/sec)\n",            \
                MYTHREAD, sz, timeus/iters/2,                                              \
                ((double)sz)*2*iters/(1024*1024)/(timeus/1E6)); fflush(NULL);              \
      }                                                                                    \
    }                                                                                      \
    if (!MYTHREAD) printf("\n");                                                           \
  } while (0)
if (dodata && dopingpong) {
 if (dosemt) {
  PINGPONG_PUT("bupc_memput_signal", bupc_memput_signal, bupc_sem_wait(myflag));
  PINGPONG_PUT("bupc_memput_signal_async", bupc_memput_signal_async, bupc_sem_wait(myflag));
 }
 if (dointflags) {
  PINGPONG_PUT("upc_memput & strict int flag", memput_signal, memput_wait());
  PINGPONG_PUT("upc_memput_nb & strict int flag (UNSAFE)", memput_signal_unsafe, memput_wait_unsafe());
 }
}
  /* ------------------------------------------------------------------------------------ */
  #define FLOOD_PUT(DESC_STR,PUT_OP) do {                                              \
    int iters = MIN(maxiters, BUPC_SEM_MAXVALUE);                                      \
    upc_barrier;                                                                       \
    if (!MYTHREAD)                                                                     \
      printf("Measuring "DESC_STR" flood throughput test, iters=%i\n", iters);         \
    upc_barrier;                                                                       \
    int sz,i;                                                                          \
    for (sz = 1; sz <= maxsz; sz *= 2) {                                               \
      upc_tick_t ticks = upc_ticks_now();                                              \
      if (!(MYTHREAD&1)) { /* even threads */                                          \
        for (i=0; i < iters; i++) {                                                    \
          PUT_OP(partner_buf, mysrc, sz, partnerflag, 1); /* send data/notification */ \
        }                                                                              \
      } else { /* odd threads */                                                       \
        for (i=0; i < iters; i++) {                                                    \
          bupc_sem_wait(myflag); /* wait for notification from partner */              \
        }                                                                              \
      }                                                                                \
      upc_barrier; /* ensure remote side has recvd all the messages */                 \
      ticks = upc_ticks_now() - ticks;                                                 \
      upc_barrier;                                                                     \
      if (!(MYTHREAD&1)) {                                                             \
        double timeus = upc_ticks_to_ns(ticks) / 1000;                                 \
        printf("%i: %8i bytes  inverse throughput: %10.3f us (%8.3f MB/sec)\n",        \
                MYTHREAD, sz, timeus/iters,                                            \
                ((double)sz)*iters/(1024*1024)/(timeus/1E6)); fflush(NULL);            \
      }                                                                                \
    }                                                                                  \
    if (!MYTHREAD) printf("\n");                                                       \
  } while (0)
  if (dodata && doflood && dosemt) {
  FLOOD_PUT("bupc_memput_signal", bupc_memput_signal);
  FLOOD_PUT("bupc_memput_signal_async", bupc_memput_signal_async);
//  FLOOD_PUT("upc_memput & strict int flag", memput_signal, memput_wait());
  }
  /* ------------------------------------------------------------------------------------ */

  upc_barrier;
  if (!MYTHREAD) upc_free(all_bufs);
  free(mysrc);
  bupc_sem_free(myflag);
  if (!MYTHREAD) printf("done.\n");
  return 0;
}

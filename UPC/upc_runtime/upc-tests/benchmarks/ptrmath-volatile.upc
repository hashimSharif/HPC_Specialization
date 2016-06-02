//#include <upc_strict.h>
#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <inttypes.h>
/* #include <stdint.h> */

#if __UPC_TICK__
#include <upc_tick.h>
#endif

static int64_t mygetMicrosecondTimeStamp(void)
{
#if __UPC_TICK__
    return upc_ticks_to_ns(upc_ticks_now()) / 1000;
#else
    int64_t retval;
    struct timeval tv;
    if (gettimeofday(&tv, NULL)) {
        perror("gettimeofday");
        abort();
    }
    retval = ((int64_t)tv.tv_sec) * 1000000 + tv.tv_usec;
    return retval;
#endif
}

#define TIME() mygetMicrosecondTimeStamp()

shared char *space;
char *lptr;
shared [10] char *sptr;
shared []   char *pIsptr;
shared      char *p1sptr;

int doit(int iters);

int main(int argc, char **argv) {
  int iters = 10000;
  size_t blocks;

  if (argc > 1) iters = atoi(argv[1]);

  blocks = ((size_t)iters)*(iters+1)/20;
  space = (char shared *)upc_all_alloc(THREADS * blocks,10);
  if (!space) {
    printf("Unsufficient memory for %i iterations\n", iters);
    upc_global_exit(1);
  }

  sptr = (shared [10] char *)space;
  pIsptr = (shared [] char *)space;
  p1sptr = (shared char *)space;
  lptr = (char *)&lptr; /* this is bogus, but ok */

  printf("Executing ptrmath tests with %i iters...\n",iters);

  doit(iters);

  upc_barrier;
  printf("done.\n");
  return 0;
}

volatile shared [2] int sar[2*THREADS];
volatile shared int p1ar[THREADS];
volatile shared [] int pIar[100];
volatile int vlar[2];
volatile int lar[2];

volatile shared [2] double d_sar[2*THREADS];
volatile shared double d_p1ar[THREADS];
volatile shared [] double d_pIar[100];
volatile double d_vlar[2];
volatile double d_lar[2];

int doit(int iters) {
  shared [10] char * volatile mysptr = sptr;
  shared [10] char * volatile mysptr2 = sptr;
  char * volatile mylptr = lptr;
  char * volatile mylptr2 = lptr;
  shared char * volatile myp1sptr = p1sptr;
  shared char *volatile myp1sptr2 = p1sptr;
  shared [] char * volatile mypIsptr = pIsptr;
  shared [] char * volatile mypIsptr2 = pIsptr;
  int i;
  int x=0;
  volatile int j;
  volatile double dj;
  int64_t start,end;

  #define TIMEIT(desc, code)                             \
    start = TIME();                                      \
    for(i=0;i<iters;i++) {                               \
      code;                                              \
    }                                                    \
    end = TIME();                                        \
    printf(desc " time: %f us/iter, totaltime %f sec\n", \
    (end-start)/(double)iters,        \
    (end-start)/(double)1000000);

  if (MYTHREAD == 0) {
    TIMEIT("local        ptr-plus", mylptr = mylptr + i);
    TIMEIT("phased       ptr-plus", mysptr = mysptr + i);
    TIMEIT("phaseless(1) ptr-plus", myp1sptr = myp1sptr + i);
    TIMEIT("phaseless(I) ptr-plus", mypIsptr = mypIsptr + i);

    TIMEIT("local        ptr-minus", mylptr = mylptr - i);
    TIMEIT("phased       ptr-minus", mysptr = mysptr - i);
    TIMEIT("phaseless(1) ptr-minus", myp1sptr = myp1sptr - i);
    TIMEIT("phaseless(I) ptr-minus", mypIsptr = mypIsptr - i);

    TIMEIT("local        ptr-incr", ++mylptr);
    TIMEIT("phased       ptr-incr", ++mysptr);
    TIMEIT("phaseless(1) ptr-incr", ++myp1sptr);
    TIMEIT("phaseless(I) ptr-incr", ++mypIsptr);

    TIMEIT("local        ptr-decr", --mylptr);
    TIMEIT("phased       ptr-decr", --mysptr);
    TIMEIT("phaseless(1) ptr-decr", --myp1sptr);
    TIMEIT("phaseless(I) ptr-decr", --mypIsptr);
    
    TIMEIT("local        ptr-sub", x += mylptr - mylptr2);
    TIMEIT("phased       ptr-sub", x += mysptr - mysptr2);
    TIMEIT("phaseless(1) ptr-sub", x += myp1sptr - myp1sptr2);
    TIMEIT("phaseless(I) ptr-sub", x += mypIsptr - mypIsptr2);
    
    TIMEIT("local        ptr-compare", x += (int)(mylptr == mylptr2));
    TIMEIT("phased       ptr-compare", x += (int)(mysptr == mysptr2));
    TIMEIT("phaseless(1) ptr-compare", x += (int)(myp1sptr == myp1sptr2));
    TIMEIT("phaseless(I) ptr-compare", x += (int)(mypIsptr == mypIsptr2));
  }
    
  printf("\n");
  /* pointer conversion */
  if (MYTHREAD == 0) {
      TIMEIT("phased       ptr-to-local", mylptr = (char *) sptr);
      TIMEIT("phaseless(1) ptr-to-local", mylptr = (char *) p1sptr);
      TIMEIT("phaseless(I) ptr-to-local", mylptr = (char *) pIsptr);
    /* Doesn't work right now because of translator bugs  
       TIMEIT("phased       ptr-to-phaseless(I)", mypIsptr = (shared [] char *) sptr);
       TIMEIT("phaseless(I) ptr-to-phased", mysptr = (shared void *) pIsptr); 
       TIMEIT("phaseless(1) ptr-to-phased", mysptr = (shared void *) p1sptr); 
    */
  }

  /* assignments for integer pointers */
  printf("\n");
  if (MYTHREAD == 0) {
    TIMEIT("local ptr store", lar[0] = i);
    TIMEIT("local ptr load", j = lar[0]);
    //TIMEIT("local ptr store -- no caching", vlar[0] = i);
    //TIMEIT("local ptr load -- no caching", j = vlar[0]);
    TIMEIT("shared local phased ptr store", sar[0] = i);
    TIMEIT("shared local phased ptr load", j = sar[0]);
    TIMEIT("shared local phaseless(1) store", p1ar[0] = i);
    TIMEIT("shared local phaseless(I) load", j = pIar[0]);
  }
  upc_barrier;
  if (MYTHREAD == 1) {
      TIMEIT("shared remote phase ptr store", sar[0] = i);
      TIMEIT("shared remote phase ptr load", j = sar[0]);
      TIMEIT("shared remote phaseless(1) ptr store", p1ar[0] = i);
      TIMEIT("shared remote phaseless(1) ptr load", j = p1ar[0]);
      TIMEIT("shared remote phaseless(I) ptr store", pIar[0] = i);
      TIMEIT("shared remote phaseless(I) ptr load", j = pIar[0]);
  }
  
  printf("\n");
  /* assignments for double pointers */
  if (MYTHREAD == 0) {
    TIMEIT("DOUBLE local ptr store", d_lar[0] = i);
    TIMEIT("DOUBLE local ptr load", dj = d_lar[0]);
    //TIMEIT("DOUBLE local ptr store -- no caching", d_vlar[0] = i);
    //TIMEIT("DOUBLE local ptr load -- no caching", dj = d_vlar[0]);
    TIMEIT("DOUBLE shared local phased ptr store", d_sar[0] = i);
    TIMEIT("DOUBLE shared local phased ptr load", dj = d_sar[0]);
    TIMEIT("DOUBLE shared local phaseless(1) store", d_p1ar[0] = i);
    TIMEIT("DOUBLE shared local phaseless(1) load", dj = d_p1ar[0]);
    TIMEIT("DOUBLE shared local phaseless(I) store", d_pIar[0] = i);
    TIMEIT("DOUBLE shared local phaseless(I) load", dj = d_pIar[0]);
  }
  upc_barrier;	
  if (MYTHREAD == 1) {
    TIMEIT("DOUBLE shared remote phase ptr store", d_sar[0] = i);
    TIMEIT("DOUBLE shared remote phase ptr load", dj = d_sar[0]);
    TIMEIT("DOUBLE shared remote phaseless(1) ptr store", d_p1ar[0] = i);
    TIMEIT("DOUBLE shared remote phaseless(1) ptr load", dj = d_p1ar[0]);
    TIMEIT("DOUBLE shared remote phaseless(I) ptr store", d_pIar[0] = i);
    TIMEIT("DOUBLE shared remote phaseless(I) ptr load", dj = d_pIar[0]);
  }  

  upc_barrier;

  /* global writeback to inhibit DCE */
  lptr = mylptr;
  sptr = mysptr;
  p1sptr = myp1sptr;
  pIsptr = mypIsptr;

  return x + (mylptr - mylptr2) + (mysptr - mysptr2) + (myp1sptr - myp1sptr2) + (mypIsptr - mypIsptr2);
}

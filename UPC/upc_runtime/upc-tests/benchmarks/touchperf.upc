#include <upc.h>
#include <upc_tick.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

unsigned long long SZ=0;
#define MAXSTATIC (10*1024*1024)
int iters=0;
char *tmp = NULL;

void display(const char *desc, const char *type, double bw) {
  static shared double all_bw[THREADS];
  upc_barrier;
  all_bw[MYTHREAD] = bw;
  upc_barrier;
  if (!MYTHREAD) {
    double max = 0,min=1E100, sum = 0;
    char tmp[1024];
    char *pos = tmp;
    for (int i=0; i<THREADS;i++) {
      double thisbw = all_bw[i];
      if (thisbw > max) max = thisbw;
      if (thisbw < min) min = thisbw;
      sum += thisbw;
      sprintf(pos," %8.3f", thisbw); pos += strlen(pos);
    }
    printf("%s %s bandwidth in MB/sec: avg=%8.3f min=%8.3f max=%8.3f\n", 
           desc, type, (sum/THREADS), min, max);
    printf("%s\n", tmp);
    fflush(NULL);
  }
  upc_barrier;
}

void timetouch(const char * desc, shared [] char *p, size_t sz) {
 {
  upc_memput(p, tmp, sz); /* warm up */
  upc_barrier;
  upc_tick_t t = upc_ticks_now();
  for (int i=0; i < iters; i++) {
    upc_memput(p, tmp, sz);
  }
  t = upc_ticks_now() - t; 
  upc_barrier;
  double bw = (SZ/1048576.0) * iters / 
              (upc_ticks_to_ns(t)*1e-9);
  display(desc, "write", bw);
 }
 {
  upc_memget(tmp, p, sz); /* warm up */
  upc_barrier;
  upc_tick_t t = upc_ticks_now();
  for (int i=0; i < iters; i++) {
    upc_memget(tmp, p, sz);
  }
  t = upc_ticks_now() - t; 
  upc_barrier;
  double bw = (SZ/1048576.0) * iters / 
              (upc_ticks_to_ns(t)*1e-9);
  display(desc, "read ", bw);
 }
}

void getmem(shared [] char **pp, char memtype, unsigned long long SZ) {
  static shared [] char * shared allp[THREADS];
  upc_barrier;
  if (memtype == 'A') {
    shared char *p = upc_all_alloc(THREADS,SZ);
    for (int i=0; i < THREADS; i++) { pp[i] = (shared [] char *)&(p[i]); }
  } else if (memtype == 'L') {
    allp[MYTHREAD] = upc_alloc(SZ);
    upc_barrier;
    for (int i=0; i < THREADS; i++) { pp[i] = allp[i]; }
  } else if (memtype == 'G') {
    if (!MYTHREAD) {
      shared char *p = upc_global_alloc(THREADS,SZ);
      for (int i=0; i < THREADS; i++) { allp[i] = (shared [] char *)&(p[i]); }
    }
    upc_barrier;
    for (int i=0; i < THREADS; i++) { pp[i] = allp[i]; }
  } else {
    static shared char arr[2*THREADS*MAXSTATIC];
    static int call = 0;
    if (SZ > MAXSTATIC) { printf("ERR: sz > %llu\n", (unsigned long long)MAXSTATIC); exit(1); }
    assert(call < 2);
    for (int i=0; i < THREADS; i++) { 
      pp[i] = (shared [] char *)&(arr[i]); 
      pp[i] += MAXSTATIC;
    }
    call++;
  }
  upc_barrier;
  for (int i=0; i < THREADS; i++) { assert(upc_threadof(pp[i]) == i); }
}

void Usage(const char *argvzero) {
    if (!MYTHREAD)
      printf("Usage: %s memtype (allocsz) (numiterations)\n"
             "memtype: (A)ll_alloc, (L)ocal_alloc, (G)lobal_alloc, (S)tatic alloc\n",argvzero);
    exit(1);
}
int main(int argc, char **argv) {
  shared [] char **zp = malloc(THREADS*sizeof(shared char *));
  shared [] char **ap = malloc(THREADS*sizeof(shared char *));
  if (argc < 2) Usage(argv[0]);
  char memtype='A'; const char *tdesc="upc_all_alloc"; 
  if (argc > 1) memtype = toupper(argv[1][0]);
  switch (memtype) {
    case 'A': tdesc="upc_all_alloc"; break;
    case 'L': tdesc="upc_alloc"; break;
    case 'G': tdesc="upc_global_alloc"; break;
    case 'S': tdesc="statically-allocated"; break;
    default: printf("unknown memtype=%s\n",argv[1]); Usage(argv[0]);
  }
  if (argc > 2) SZ = atol(argv[2]);
  if (!SZ) SZ = 10*1024*1024;
  if (argc > 3) iters = atoi(argv[3]);
  if (!iters) iters = 100;
  if (!MYTHREAD) printf("Running %s touchperf with %i threads, sz=%llu iters=%i\n",
                        tdesc, THREADS, (unsigned long long)SZ, iters);
  tmp = malloc(SZ);
  if (!MYTHREAD) {printf("establish thread-CPU affinity...\n"); fflush(NULL);}
  for (int i=0; i < iters/10; i++) {
    for (int j=0; j < SZ; j++) tmp[j]++;
  }
  upc_barrier;
  getmem(zp, memtype, SZ);
  if (MYTHREAD == 0) { /* zero touches all the data first */
    printf("first touch zero...\n"); fflush(NULL);
    for (int i=0; i < THREADS; i++) {
      upc_memput(zp[i], tmp, SZ);
    }
  }
  upc_barrier;
  getmem(ap, memtype, SZ);
  if (MYTHREAD == 0) { /* each thread touches its own data */
    printf("first touch all...\n"); fflush(NULL);
  }
  upc_memput(ap[MYTHREAD], tmp, SZ);
  upc_barrier;
  if (MYTHREAD == 0) { /* each thread touches its own data */
    printf("timing...\n"); fflush(NULL);
  }
  upc_barrier;
  for (int i=0 ; i < 4; i++) {
    if (!MYTHREAD) printf("----------------\n");
    upc_barrier;
    timetouch("zero-touched", zp[MYTHREAD], SZ);
    upc_barrier;
    timetouch("all-touched ", ap[MYTHREAD], SZ);
    upc_barrier;
  }
  if (!MYTHREAD) printf("----------------\ndone.\n");
  return 0;
}


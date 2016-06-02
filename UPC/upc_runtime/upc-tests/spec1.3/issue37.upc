/* Tester for upc_castable.h library
 * Written by Dan Bonachea 
 * Copyright 2012, The Regents of the University of California 
 * This code is under BSD license: http://upc.lbl.gov/download/dist/LICENSE.TXT
 */

// note this must be PRE defined in a conformant implementation, not defined in upc_castable.h
#if !defined(__UPC_CASTABLE__) || __UPC_CASTABLE__ != 1
#error __UPC_CASTABLE__ incorrectly defined
#endif

#include <upc_castable.h>
#include <upc.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef UPC_CASTABLE_ALL_ALLOC
#error  UPC_CASTABLE_ALL_ALLOC not defined!
#endif
#ifndef UPC_CASTABLE_GLOBAL_ALLOC
#error  UPC_CASTABLE_GLOBAL_ALLOC not defined!
#endif
#ifndef UPC_CASTABLE_ALLOC
#error  UPC_CASTABLE_ALLOC not defined!
#endif
#ifndef UPC_CASTABLE_STATIC
#error  UPC_CASTABLE_STATIC not defined!
#endif

// T is the element type
#ifndef T
#define T char
#endif

// BS is the size of each local block
#ifndef BS
#define BS 1024
#endif

// How much to churn the heap between iterations
#ifndef CHURN_FACTOR
#define CHURN_FACTOR 100
#endif

shared [BS] T a_static[BS*THREADS];

shared void * shared global_temp;

shared void * shared local_temp[THREADS];

int errors = 0;
int total = 0;
int casted = 0;

struct { int val;
         const char *name;
} flags[] = {
  { UPC_CASTABLE_STATIC,       "UPC_CASTABLE_STATIC" },
  { UPC_CASTABLE_ALLOC,        "UPC_CASTABLE_ALLOC" },
  { UPC_CASTABLE_ALL_ALLOC,    "UPC_CASTABLE_ALL_ALLOC" },
  { UPC_CASTABLE_GLOBAL_ALLOC, "UPC_CASTABLE_GLOBAL_ALLOC" },
  { UPC_CASTABLE_ALL,          "UPC_CASTABLE_ALL" },
};

void churn_memory() {
  shared void *ltemp[CHURN_FACTOR];
  shared void *gtemp[CHURN_FACTOR];
  for (int i=0; i < CHURN_FACTOR; i++) {
    size_t rsz = (size_t)(MYTHREAD*1024.0*rand()/RAND_MAX);
    ltemp[i] = upc_alloc(rsz);
    gtemp[i] = upc_all_alloc(i*THREADS, BS);
  }
  for (int i=0; i < CHURN_FACTOR; i++) {
    upc_free(ltemp[i]);
    if (!MYTHREAD) upc_free(gtemp[i]);
  }
}

int main(int argc, char **argv) {
  int iters = 0;
  if (argc > 1) {
    iters = atoi(argv[1]);
  }
  if (iters < 1) iters = 100;
  srand(MYTHREAD*time(0));
  if (!MYTHREAD) {
    printf("Running upc_castable test with %i iterations\n", iters);
    printf("Testing upc_thread_info flags...\n");
    int sum = 0;
    #define TEST_FLAG(flag) do { \
      if ((flag) == 0) { printf(#flag" value is zero!\n"); errors++; } \
      if (sum & (flag)) { printf(#flag" value is not unique!\n"); errors++; } \
      sum = sum | flag; \
    } while(0)
    TEST_FLAG(UPC_CASTABLE_ALL_ALLOC);  
    TEST_FLAG(UPC_CASTABLE_GLOBAL_ALLOC);  
    TEST_FLAG(UPC_CASTABLE_ALLOC);  
    TEST_FLAG(UPC_CASTABLE_STATIC);  
    if ((sum & UPC_CASTABLE_ALL) != sum) {
      printf("UPC_CASTABLE_ALL does not cover all flags!\n");
      errors++;
    }
    if (((int)UPC_CASTABLE_ALL) ^ sum) {
      printf(" - UPC_CASTABLE_ALL contains some vendor-defined flags\n");
    } else {
      printf(" - UPC_CASTABLE_ALL does not contain vendor-defined flags\n");
    }
  }

  upc_barrier;
  upc_thread_info_t *info = malloc(THREADS*sizeof(upc_thread_info_t));
  if (!MYTHREAD) { // check some type properties
    printf("Testing upc_thread_info_t...\n");
    if (sizeof(info->probablyCastable) != sizeof(int)) {
      printf("Incorrect size of upc_thread_info_t.probablyCastable field\n");
      errors++;
    }
    if (sizeof(info->guaranteedCastable) != sizeof(int)) {
      printf("Incorrect size of upc_thread_info_t.guaranteedCastable field\n");
      errors++;
    }
    if (sizeof(*info) == 2*sizeof(int)) {
      printf(" - upc_thread_info_t does not contain vendor-defined fields\n");
    } else {
      printf(" - upc_thread_info_t might contain vendor-defined fields\n");
    }
  }

  upc_barrier;
  if (!MYTHREAD) printf("Testing upc_thread_info()...\n");
  for (int iter=0; iter < iters; iter++) {
    for (size_t th=0; th < THREADS; th++) {
      upc_thread_info_t ti = upc_thread_info(th);
      if (iter == 0) info[th] = ti;
      else {
        if (ti.guaranteedCastable != info[th].guaranteedCastable ||
            ti.probablyCastable   != info[th].probablyCastable) {
          printf("%i: upc_thread_info(%i) changed between calls!\n",
                 MYTHREAD, (int)th);
          errors++;
        }
      }
      upc_thread_info_t *pi = &info[th];
      // check that probablyCastable is a superset of guaranteedCastable
      if ((pi->guaranteedCastable & pi->probablyCastable) != pi->guaranteedCastable) {
        printf("%i: upc_thread_info(%i) probablyCastable(%i) is a subset of guaranteedCastable(%i)!\n",
               MYTHREAD, (int)th, pi->probablyCastable, pi->guaranteedCastable);
        errors++;
      }
      if (pi->guaranteedCastable & (~(int)UPC_CASTABLE_ALL)) {
        printf("%i: upc_thread_info(%i) guaranteedCastable(%i) sets bits outside UPC_CASTABLE_ALL(%i)!\n",
               MYTHREAD, (int)th, pi->guaranteedCastable, (int)UPC_CASTABLE_ALL);
        errors++;
      }
      if (pi->probablyCastable & (~(int)UPC_CASTABLE_ALL)) {
        printf("%i: upc_thread_info(%i) probablyCastable(%i) sets bits outside UPC_CASTABLE_ALL(%i)!\n",
               MYTHREAD, (int)th, pi->probablyCastable, (int)UPC_CASTABLE_ALL);
        errors++;
      }
    }
  } // iters
  upc_thread_info_t *li = &info[MYTHREAD];
  for (size_t i = 0; i < (sizeof(flags)/sizeof(flags[0])); i++) {
    if (!(li->guaranteedCastable & flags[i].val)) {
      printf("%i: upc_thread_info(MYTHREAD) guaranteedCastable(%i) fails to set %s\n",
             MYTHREAD, li->guaranteedCastable, flags[i].name);
      errors++;
    }
    if (!(li->probablyCastable & flags[i].val)) {
      printf("%i: upc_thread_info(MYTHREAD) probablyCastable(%i) fails to set %s\n",
             MYTHREAD, li->probablyCastable, flags[i].name);
      errors++;
    }
  }

  upc_barrier;
  if (!MYTHREAD) printf("Allocating...\n");
  churn_memory();
  if (!MYTHREAD) global_temp = upc_global_alloc(THREADS,BS*sizeof(T));
  upc_barrier;
  shared [BS] T *a_all = upc_all_alloc(THREADS,BS*sizeof(T));
  shared []   T *a_local = upc_alloc(BS*sizeof(T));
  local_temp[MYTHREAD] = a_local;
  shared [BS] T *a_global = global_temp;

  upc_barrier;
  if (!MYTHREAD) printf("Testing local casts...\n");
  for (int iter=0; iter < iters; iter++) {
    churn_memory();
    void *nullcheck = upc_cast(NULL);
    if (nullcheck != NULL) {
      printf("%i: upc_cast(NULL) returned incorrect non-null pointer\n", MYTHREAD);
      errors++;
    }
    shared [] T *my_regions[] = { 
                                    (shared [] T *)&a_static[BS*MYTHREAD],
                                    a_local,
                                    (shared [] T *)&a_all[BS*MYTHREAD],
                                    (shared [] T *)&a_global[BS*MYTHREAD],
                                  };
  
    for (size_t region = 0; region < sizeof(my_regions)/sizeof(my_regions[0]); region++) {
      shared [] T *regionp = my_regions[region];
      assert(upc_threadof(regionp) == (size_t)MYTHREAD);
      for (int i=0; i < BS; i++) {
        shared [] T *sp = regionp + i;
        assert(upc_threadof(sp) == (size_t)MYTHREAD);
        T *lp = (T *)sp;
        assert(lp != NULL);
        T *cp = upc_cast(sp);
        T val = (T)(MYTHREAD+iter+i);
        if (cp != lp) {
          printf("%i: upc_cast() of a local pointer at offset %i in region %s returned incorrect %s pointer\n", 
                 MYTHREAD, i, flags[region].name, (cp==NULL?"null":"non-null"));
          errors++;
        }
        *cp = val;
        if (*lp != val || *cp != val) {
          printf("%i: failed read/write test on a local pointer at offset %i in region %s\n", 
                 MYTHREAD, i, flags[region].name);
          errors++;
        }
      }
    }
  } // iters
  upc_barrier;
  if (!MYTHREAD) printf("Testing remote casts...\n");
  for (int iter=0; iter < iters; iter++) {
    churn_memory();
    for (int th = (MYTHREAD+1)%THREADS; th != MYTHREAD; th = (th + 1)%THREADS) {
      upc_barrier;
      upc_thread_info_t *pi = &info[th];
      shared [] T *th_regions[] = { 
                                    (shared [] T *)&a_static[BS*th],
                                    (shared [] T *)local_temp[th],
                                    (shared [] T *)&a_all[BS*th],
                                    (shared [] T *)&a_global[BS*th],
                                  };
      for (size_t region = 0; region < sizeof(th_regions)/sizeof(th_regions[0]); region++) {
        shared [] T *regionp = th_regions[region];
        assert(upc_threadof(regionp) == (size_t)th);
        T *base = upc_cast(regionp);
        int castable = (base != NULL);
  rescan:
        for (int i=0; i < BS; i++) {
          shared [] T *sp = regionp + i;
          assert(upc_threadof(sp) == (size_t)th);
          T *cp = upc_cast(sp);
          total++;
          if (castable && cp == NULL) {
            printf("%i: upc_cast() at offset %i in region %s returned null after a previous upc_cast() of the same object succeeeded\n", 
                   MYTHREAD, i, flags[region].name);
            errors++;
          } else if (!castable && cp != NULL) { // permitted to start working at unspecified time, but must continue to work
            printf("%i: warning: upc_cast() at offset %i in region %s succeeded after a previous failure on the same object\n", 
                   MYTHREAD, i, flags[region].name);
            // not an error
            castable = 1;
            base = upc_cast(regionp);
            goto rescan;
          }
          if ((pi->guaranteedCastable & flags[region].val) && cp == NULL) {
            printf("%i: upc_cast() at offset %i in region %s returned null, but guaranteedCastable(%i) is set\n", 
                   MYTHREAD, i, flags[region].name, pi->guaranteedCastable);
            errors++;
          }
          if ((pi->probablyCastable & flags[region].val) == 0 && cp != NULL) {
            printf("%i: warning: upc_cast() at offset %i in region %s succeeded, but probablyCastable(%i) is not set\n", 
                   MYTHREAD, i, flags[region].name, pi->probablyCastable);
            // not an error
          }
          if (cp != NULL) {
            assert(base != NULL);
            casted++;
            if (cp != base + i) {
              printf("%i: upc_cast() of a pointer at offset %i in region %s returned incorrect pointer\n", 
                 MYTHREAD, i, flags[region].name);
              errors++;
            }
            T val = (T)(MYTHREAD+iter+i);
            *cp = val;
            if (*sp != val || *cp != val) {
              printf("%i: failed read/write test on a local pointer at offset %i in region %s\n", 
                     MYTHREAD, i, flags[region].name);
              errors++;
            }
          }
        } // i
      } // region
    } // th
  } // iters

  upc_barrier;
  if (errors) printf("%i: FAILED %i errors\n", MYTHREAD, errors);
  else printf("%i: SUCCESS (%.1f%% remote castable)\n", MYTHREAD, (casted*100.0/(total?total:1)));
  upc_barrier;
  return errors;
}

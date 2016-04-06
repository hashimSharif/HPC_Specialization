/* UPC 1.3 atomics tester
 * Written by Dan Bonachea 
 * Copyright 2013, The Regents of the University of California 
 * This code is under BSD license: http://upc.lbl.gov/download/dist/LICENSE.TXT
 */

/* This file is a macro template, instantiated once per type */
#ifndef ATOMIC_TEST
#error This file is not meant to be compiled directly
#endif

#ifndef T
#error missing define T
#endif
#ifndef TM
#error missing define TM
#endif

#ifndef _STRINGIFY
#define _STRINGIFY_HELPER(x) #x
#define _STRINGIFY(x) _STRINGIFY_HELPER(x)
#endif

#ifndef _CONCAT
#define _CONCAT_HELPER(a,b) a ## b
#define _CONCAT(a,b) _CONCAT_HELPER(a,b)
#endif

#ifndef MIN
#define MIN(x,y)  ((x)<(y)?(x):(y))
#endif
#ifndef MAX
#define MAX(x,y)  ((x)>(y)?(x):(y))
#endif

/* MAX_ACTIVE: max number of threads that can be active using THVAL for this type */
#undef MAX_ACTIVE
#if CATINT  // ensure at least one bit per active thread
  #define MAX_ACTIVE  (8*sizeof(T)-1) // bits we can freely twiddle without overflow 
#elif CATFLOAT
  #define MAX_ACTIVE  (sizeof(T) >= 8 ? 50 : 21) // be conservative with float types
#elif CATPTS 
  #define MAX_ACTIVE  256
#else
  #error bad type CAT
#endif

/* THVAL is a value of type T that is unique to a given active thread.
   Additionally, for numeric T, any bits set in the integer representation of the value are unique to that thread
*/
#undef THVAL
#define THVAL(threadid) (_CONCAT(thval_,TM)(threadid))
#if CATINT || CATFLOAT
  static T _CONCAT(thval_,TM)(size_t threadid) {
    ASSERT_FATAL(threadid < MAX_ACTIVE);
    T thval = (T)0;
    int volatile threads = THREADS; // bug 3220: workaround icc optimizer bug
    for (size_t bit=threadid; bit < MAX_ACTIVE; bit += threads) {
      thval = thval + (T)(1ULL<<bit); 
    }
    //printf("THVAL_%s(%i) => %llx\n", _STRINGIFY(TM), (int)threadid, (unsigned long long)thval);
    return thval;
  }
#elif CATPTS
  #undef _THARR
  #define _THARR _CONCAT(thpos_,TM)
  static shared [MAX_ACTIVE] char _THARR[THREADS*MAX_ACTIVE];
  static T _CONCAT(thval_,TM)(size_t threadid) {
    ASSERT_FATAL(threadid < MAX_ACTIVE);
    T thval = (T)&_THARR[threadid*MAX_ACTIVE+threadid];
    ASSERT_FATAL(upc_threadof(thval) == threadid);
    ASSERT_FATAL(upc_phaseof(thval) == threadid);
    return thval;
  }
#endif

/* check val is a valid THVAL for any active thread */
#undef CHECK_THVAL
#if CATINT || CATFLOAT
  #define CHECK_THVAL(val) do {                 \
    T thval = (val);                            \
    ASSERTNE(thval,0);                          \
    if (thval) {                                \
      uint64_t tmp = (uint64_t)thval;           \
      size_t th;                                \
      for (th = 0; !(tmp&0x1); th++) tmp >>= 1; \
      ASSERTEQ(thval,THVAL(th));                \
    }                                           \
  } while (0)
#elif CATPTS
  #define CHECK_THVAL(val) do {       \
    T thval = (val);                  \
    size_t th = upc_threadof(thval);  \
    ASSERTEQT(size_t,INT,upc_phaseof(thval),th); \
    ASSERTEQ(thval,THVAL(th));        \
  } while (0)
#endif

#undef PROGRESS
#define PROGRESS(args) do {   \
  upc_barrier;                                \
  if (!MYTHREAD) {                            \
    fflush(NULL);                             \
    if (sec < 'a') printf("%c:  ", thissec);  \
    else printf("%c%c:  ", thissec, sec);     \
    printf args;                              \
    printf("\n");                             \
    fflush(NULL);                             \
  }                                           \
  upc_barrier;                                \
} while (0)

#undef IFSEC
#define IFSEC() \
  if (strchr(sections, ++sec))

/* Main test driver */
int _CONCAT(test_,TM)(int iters, char thissec, const char *sections, int seed_override) {
  int errors = 0;
  char sec = 'a' - 1;
  upc_type_t type = _CONCAT(UPC_,TM);
  upc_op_t allops = _CONCAT(OPS_,CAT);
  upc_op_t oplist[] = { _CONCAT(OPL_,CAT) };
  int numops = sizeof(oplist)/sizeof(upc_op_t);
  upc_atomichint_t hintlist[] = { UPC_ATOMIC_HINT_DEFAULT, UPC_ATOMIC_HINT_LATENCY, UPC_ATOMIC_HINT_THROUGHPUT };
  int numhints = sizeof(hintlist)/sizeof(upc_atomichint_t);

  int Tunsigned = 0;
  T maxval, minval; // approx max and min normal values without overflow
  #if CATINT
    if (((T)-1) > 0) { 
      Tunsigned = 1;
      maxval = (T)-1;
      minval = 0;
    } else { 
      // carefully written to avoid signed integer overflow and translator bug 3230
      maxval = ((T)1) << (sizeof(T)*8-2);
      T volatile tmp = maxval - 1;
      maxval += tmp;
      minval = -maxval - 1;
    }
  #elif CATFLOAT
    if (sizeof(T) >= 8) {
      maxval = 1ULL<<50;
    } else {
      maxval = 1ULL<<21;
    }
    minval = -maxval;
  #endif
  #if !CATPTS
    ASSERT_FATAL(maxval > minval);
    ASSERT_FATAL(maxval > 0);
    ASSERT_FATAL(minval <= 0);
  #endif

  PROGRESS(("Testing %s...", _STRINGIFY(TM)));

  IFSEC() { 
    static shared T a1[THREADS];

    int maxcomb = pow(2, numops) - 1;
    int testcomb = maxcomb;
    int step = 1;
    if (iters < maxcomb) {
      step = (maxcomb + iters - 1) / iters;
      testcomb = maxcomb / step;
    } 

    PROGRESS(("Argument coverage (%i combinations, %.1f%% coverage)", testcomb, 100.0*testcomb/maxcomb));

    upc_atomicdomain_t **doms = calloc(maxcomb+1, sizeof(upc_atomicdomain_t *));
    for (int c = maxcomb; c > 0; c -= step) {
      upc_op_t thisop = 0;
      for (int i=0; i < numops; i++) {
        if (c & (1<<i)) {
          thisop = thisop | oplist[i];
        }
      }
      // call upc_atomic_isfast with every possible combination of type/ops
      upc_atomic_isfast(type, thisop, &a1[0]);
      upc_atomic_isfast(type, thisop, &a1[MYTHREAD]);

      // call upc_all_atomicdomain_alloc with every possible combination of type/ops
      upc_atomicdomain_t *d = upc_all_atomicdomain_alloc(type, thisop, hintlist[c%numhints]);
      ASSERT(d);
      doms[c] = d;
      for (int i=0; i < numops; i++) {
        upc_op_t op = oplist[i];
        if (op & thisop) {
          T fetch;
          T tmp1 = 0;
          T tmp2 = 0;
          T *operand1 = &tmp1;
          T *operand2 = &tmp2;
          if (op != UPC_CSWAP) operand2 = NULL;
          if (op == UPC_INC || op == UPC_DEC || op == UPC_GET) operand1 = NULL;
          // call upc_atomic_strict/relaxed with every possible combination of type/ops
          upc_atomic_strict(d, &fetch, op, &a1[MYTHREAD], operand1, operand2);
          upc_atomic_relaxed(d, &fetch, op, &a1[MYTHREAD], operand1, operand2);
        }
      }
    }
    for (int c = 1; c <= maxcomb; c++) {
      if (doms[c]) upc_all_atomicdomain_free(doms[c]);
    }
  }

  IFSEC() { 
    PROGRESS(("No-op atomics"));
    upc_atomicdomain_t *d = upc_all_atomicdomain_alloc(type, allops, 0);
    ASSERT(d);
    static shared T a1[THREADS];

    T last;
    int myiters = iters / THREADS;
    for (int i=0; i < myiters; i++) {
      #if CATPTS 
        T init = (T)&a1[MYTHREAD];
      #else
        T init = (T)i;
      #endif
      T fetch = 0;
      upc_atomic_relaxed(d, &fetch, UPC_SET, &a1[MYTHREAD], &init, NULL);
      if (i == 0) upc_barrier; // ensure all inits complete
      else ASSERTEQ(fetch,last); // ensure no change

      for (int t=0; t < THREADS; t++) {
        shared T *target = &a1[t];
        for (int o=0; o < numops; o++) {
          upc_op_t op = oplist[(o+MYTHREAD)%numops];
          T arg, arg2;
          T *op1 = &arg;
          T *op2 = NULL;
          int skip = 0;
          switch (op) { // storm of ops designed to have no effect on the stored value
            case UPC_GET: op1 = NULL; break; 
            #if CATPTS 
              case UPC_CSWAP: arg = NULL; 
            #else
              case UPC_CSWAP: arg = (T)-1; op2 = &arg2; break; 
              case UPC_AND:   arg = (T)-1; break;
              case UPC_MULT:  arg = 1; break;
              case UPC_ADD: case UPC_SUB: case UPC_OR: case UPC_XOR: arg = 0; break;
              case UPC_MIN: arg = iters+i; break;
              case UPC_MAX: arg = 0; break;
            #endif
            default: skip = 1;
          }
          if (!skip) upc_atomic_relaxed(d, &fetch, op, target, op1, op2);
        }
      }

      upc_atomic_relaxed(d, &last, UPC_GET, &a1[MYTHREAD], NULL, NULL);
      ASSERTEQ(last,init); // ensure no change
    }

    upc_all_atomicdomain_free(d);
  }

  #if CATPTS
    IFSEC() ((void)0); // keep sections in sync
  #else
  IFSEC() { 
    SRAND();
    PROGRESS(("Bit munging (seed=%u)",seed));
    upc_op_t ops = allops & (UPC_ADD | UPC_SUB | UPC_OR | UPC_AND | UPC_XOR);
    upc_atomicdomain_t *d = upc_all_atomicdomain_alloc(type, ops, 0);
    ASSERT(d);

    #ifndef W
    #define W 3
    #endif
    static shared [W] T vals[W*THREADS];
    int *check = calloc(W*THREADS, sizeof(int)); // boolean backup of our bit state

    if (MYTHREAD < MAX_ACTIVE) { 
      T mybit = THVAL(MYTHREAD);
      T negmybit = -mybit;
      #if CATINT
        const int cases = 4;
        T notmybit = ~mybit;
      #else
        const int cases = 2;
      #endif
      int myiters = iters * 10; // scale to match other tests
      for (int i=0; i < myiters; i++) {
        int locmax = W*THREADS*i/myiters + 1;
        int loc = rand() % locmax;
        shared void *target = &vals[loc];
        int old = check[loc];
        T fetch = 0;
        switch (rand() % cases) {
          case 0:  // toggle my bit using UPC_ADD
            upc_atomic_relaxed(d, &fetch, UPC_ADD, target, (old?&negmybit:&mybit), NULL);
          break;
          case 1:  // toggle my bit using UPC_SUB
            upc_atomic_relaxed(d, &fetch, UPC_SUB, target, (old?&mybit:&negmybit), NULL);
          break;
        #if CATINT
          case 2:  // toggle my bit using UPC_XOR
            upc_atomic_relaxed(d, &fetch, UPC_XOR, target, &mybit, NULL);
          break;
          case 3:  // toggle my bit using UPC_AND/OR
            if (old) upc_atomic_relaxed(d, &fetch, UPC_AND, target, &notmybit, NULL);
            else     upc_atomic_relaxed(d, &fetch, UPC_OR,  target, &mybit, NULL);
          break;
        #endif
        }
        uint64_t set = (uint64_t)(fetch) & (uint64_t)mybit;
        if (old) ASSERTEQT(uint64_t,INT,set,(uint64_t)mybit); // if this fails, some of our bits were incorrectly cleared
        else ASSERTEQT(uint64_t,INT,set,0); // if this fails, some of our bits were incorrectly set
        check[loc] = !old;
      }
    }
    upc_all_atomicdomain_free(d);
  }
  #endif

  #if CATPTS
    IFSEC() ((void)0); // keep sections in sync
  #else
  IFSEC() { 
    SRAND();
    PROGRESS(("ADD/SUB/INC/DEC (seed=%u)",seed));
    upc_atomicdomain_t *d = upc_all_atomicdomain_alloc(type, UPC_ADD | UPC_SUB | UPC_INC | UPC_DEC, 0);
    ASSERT(d);

    #ifndef W
    #define W 3
    #endif
    static shared [W] T vals[W*THREADS];
    T *check = calloc(W*THREADS, sizeof(T)); // local backup of our contribution
    T maxlocal = (T)(int64_t)(maxval / THREADS / 2);
    T minlocal = (T)(int64_t)(minval / THREADS / 2);
    int myiters = iters * 10; // scale to match other tests
    for (int i=0; i < myiters; i++) {
      int locmax = W*THREADS*i/myiters + 1;
      int loc = rand() % locmax;
      shared void *target = &vals[loc];
      double rng = ((double)rand()) / RAND_MAX;
      T newval = (T)(uint64_t)(rng * (maxlocal - minlocal));
      newval += minlocal;
      if (newval > maxlocal) {
        newval = maxlocal; // fp rounding can cause slight excess at rng=1.0
      }
      ASSERTLE(newval, maxlocal);
      ASSERTGE(newval, minlocal);

      switch (rand() % 4) {
        case 0:  
          if (check[loc] < maxlocal) {
            upc_atomic_relaxed(d, NULL, UPC_INC, target, NULL, NULL);
            check[loc]++;
          }
        break;
        case 1:  
          if (check[loc] > minlocal) {
            upc_atomic_relaxed(d, NULL, UPC_DEC, target, NULL, NULL);
            check[loc]--;
          }
        break;
        case 2:  {
          T delta = newval - check[loc];
          upc_atomic_relaxed(d, NULL, UPC_ADD, target, &delta, NULL);
          check[loc] += delta;
        break; }
        case 3:  {
          T delta = -(newval - check[loc]);
          upc_atomic_relaxed(d, NULL, UPC_SUB, target, &delta, NULL);
          check[loc] -= delta;
        break; }
      }
      ASSERTLE(check[loc], maxlocal);
      ASSERTGE(check[loc], minlocal);
    }
    for (int loc = 0; loc < W*THREADS; loc++) { // zero out our contribution
      shared void *target = &vals[loc];
      upc_atomic_relaxed(d, NULL, UPC_SUB, target, &check[loc], NULL);
    }
    upc_barrier;
    for (int i=0; i < W; i++) { // confirm balance
      ASSERTEQ(vals[W*MYTHREAD+i], 0);
    }
    upc_all_atomicdomain_free(d);
  }
  #endif

  { struct { 
     const char *name;
     upc_op_t ops;
     int cases;
    } testinfo[] = {
      { "GET/SET id test", UPC_GET | UPC_SET, 3 },
      { "GET/SET/CSWAP id test", UPC_GET | UPC_SET | UPC_CSWAP, 4 },
    #if !CATPTS
      { "GET/SET/CSWAP/MIN/MAX id test", UPC_GET | UPC_SET | UPC_CSWAP | UPC_MIN | UPC_MAX, 6 }
    #endif
    };
    for (int test = 0; test < sizeof(testinfo)/sizeof(testinfo[0]); test++) IFSEC() {
      SRAND();
      PROGRESS(("%s (seed=%u)", testinfo[test].name, seed));
      upc_atomicdomain_t *d = upc_all_atomicdomain_alloc(type, testinfo[test].ops, 0);
      ASSERT(d);

      static shared [W] T vals[W*THREADS];
      T myval;
      if (MYTHREAD >= MAX_ACTIVE) myval = THVAL(0);
      else myval = THVAL(MYTHREAD);
      for (int i=0; i < W; i++) vals[W*MYTHREAD+i] = myval; // init
      upc_barrier;
      if (MYTHREAD < MAX_ACTIVE) {
        int myiters = iters * 10;
        for (int i=0; i < myiters; i++) {
          int locmax = W*THREADS*i/myiters + 1;
          int loc = rand() % locmax;
          shared void *target = &vals[loc];
          T fetch = 0;
          switch (rand() % testinfo[test].cases) {
            case 0:  
              upc_atomic_relaxed(d, &fetch, UPC_GET, target, NULL, NULL);
              CHECK_THVAL(fetch);
            break;
            case 1:  
              upc_atomic_relaxed(d, NULL, UPC_SET, target, &myval, NULL);
            break;
            case 2:  
              upc_atomic_relaxed(d, &fetch, UPC_SET, target, &myval, NULL);
              CHECK_THVAL(fetch);
            break;
            case 3: {
              T tmp;
              upc_atomic_relaxed(d, &tmp, UPC_GET, target, NULL, NULL);
              CHECK_THVAL(tmp);
              upc_atomic_relaxed(d, &fetch, UPC_CSWAP, target, &tmp, &myval);
              CHECK_THVAL(fetch);
            break; }
            case 4:  
              upc_atomic_relaxed(d, &fetch, UPC_MIN, target, &myval, NULL);
              CHECK_THVAL(fetch);
            break;
            case 5:  
              upc_atomic_relaxed(d, &fetch, UPC_MAX, target, &myval, NULL);
              CHECK_THVAL(fetch);
            break;
          }
          ASSERTEQ(myval, THVAL(MYTHREAD));
        }
      } 
      upc_all_atomicdomain_free(d);
    } // test
  }

  #if !CATINT 
  IFSEC() ((void)0); // keep sections in sync
  #else 
  IFSEC() if (Tunsigned) { 
    PROGRESS(("Unsigned overflow test"));
    upc_atomicdomain_t *d = upc_all_atomicdomain_alloc(type, allops, 0);
    ASSERT(d);
    static shared T a1[THREADS];
    // unsigned integer type overflows are always well-defined, ensure it matches language-level arithmetic
    for (int p=0; p < THREADS; p++) {
      T check = maxval;
      T result;
      shared T *target = &a1[(MYTHREAD+p)%THREADS];
      *target = check;
      upc_barrier; 
      for (int i=0; i < iters/THREADS; i++) { 
        T val = maxval - i - 1; 

        check += val;
        upc_atomic_relaxed(d, NULL, UPC_ADD, target, &val, NULL);
        upc_atomic_relaxed(d, &result, UPC_GET, target, NULL, NULL);
        ASSERTEQ(result, check); 

        check *= val;
        upc_atomic_relaxed(d, NULL, UPC_MULT, target, &val, NULL);
        upc_atomic_relaxed(d, &result, UPC_GET, target, NULL, NULL);
        ASSERTEQ(result, check); 

        check -= val;
        upc_atomic_relaxed(d, NULL, UPC_SUB, target, &val, NULL);
        upc_atomic_relaxed(d, &result, UPC_GET, target, NULL, NULL);
        ASSERTEQ(result, check); 

        check = MAX(check, val);
        upc_atomic_relaxed(d, NULL, UPC_MAX, target, &val, NULL);
        upc_atomic_relaxed(d, &result, UPC_GET, target, NULL, NULL);
        ASSERTEQ(result, check); 

        check = MIN(check, val);
        upc_atomic_relaxed(d, NULL, UPC_MIN, target, &val, NULL);
        upc_atomic_relaxed(d, &result, UPC_GET, target, NULL, NULL);
        ASSERTEQ(result, check); 
      }

      // check INC/DEC across the wraparound
      T val = 0;
      check = val;
      upc_atomic_relaxed(d, NULL, UPC_SET, target, &val, NULL);

      check--;
      upc_atomic_relaxed(d, NULL, UPC_DEC, target, NULL, NULL);
      upc_atomic_relaxed(d, &result, UPC_GET, target, NULL, NULL);
      ASSERTEQ(result, check); 
     
      check++;
      upc_atomic_relaxed(d, NULL, UPC_INC, target, NULL, NULL);
      upc_atomic_relaxed(d, &result, UPC_GET, target, NULL, NULL);
      ASSERTEQ(result, check); 

      ASSERTEQ(check, 0); 
     
      upc_barrier;
    }
    upc_all_atomicdomain_free(d);
  }
  #endif

  #if !CATFLOAT
  IFSEC() ((void)0); // keep sections in sync
  #else 
  IFSEC() { 
    PROGRESS(("Floating-point limit test"));
    upc_atomicdomain_t *d = upc_all_atomicdomain_alloc(type, allops, 0);
    ASSERT(d);
    static shared T a1[THREADS];
    #define DOUBLE 42
    #if defined(__PGI) && (TM == 42) // Bug 3218: INFINITY is broken on PGI
      T inf = HUGE_VAL;
    #elif defined(INFINITY)
      T inf = INFINITY;
    #else
      T inf = ((T)1)/0;
    #endif
    T max = 1.0E+36F, min = 1.0E-36F;
    #if defined(FLT_MAX) && defined(FLT_MIN)
      max = FLT_MAX; min = FLT_MIN;
    #endif
    #if defined(DBL_MAX) && defined(DBL_MIN) && (TM == 42)
      max = (T)DBL_MAX; min = (T)DBL_MIN;
    #endif
    #undef DOUBLE

    T vals[13];
    int cnt = 0;
    vals[cnt++] = inf;
    vals[cnt++] = max;
    vals[cnt++] = (T)1.234E20F;
    vals[cnt++] = (T)3.141;
    vals[cnt++] = (T)1.234E-20F;
    vals[cnt++] = min;
    vals[cnt++] = (T)0;
    vals[cnt++] = -min;
    vals[cnt++] = (T)-1.234E-20F;
    vals[cnt++] = (T)-3.141;
    vals[cnt++] = (T)-1.234E20F;
    vals[cnt++] = -max;
    vals[cnt++] = -inf;
    ASSERT_FATAL(cnt == sizeof(vals)/sizeof(T));

    for (int i=0; i < cnt-1; i++) { // sanity check
      ASSERT_FATAL(vals[i] != vals[i+1]);
      ASSERT_FATAL(vals[i] > vals[i+1]);
      ASSERT_FATAL(vals[i+1] < vals[i]);
    }

    for (int p=0; p < THREADS; p++) {
      shared T *target = &a1[(MYTHREAD+p)%THREADS];

      upc_barrier;
      for (int i=0; i < cnt; i++) { 
        const T LHS = vals[i]; 

        for (int j=0; j < cnt; j++) {
          const T RHS = vals[j]; 
          T result;

          #undef  FP_OP
          #define FP_OP(op, rhs, answer) do {                                \
            static T volatile correct; /* try to force ld/st roundoff */     \
            correct = (answer);                                              \
            upc_atomic_relaxed(d, NULL, UPC_SET, target, &LHS, NULL);        \
            upc_atomic_relaxed(d, NULL, op, target, rhs, NULL);              \
            upc_atomic_relaxed(d, &result, UPC_GET, target, NULL, NULL);     \
            int ok = (isnan(result) && isnan(correct)) || result == correct; \
            if (!ok) {                                                       \
              T diff = result - correct;                                     \
              char RHSs[80];                                                 \
              if (rhs != NULL) sprintf(RHSs,"%14g", RHS);                    \
              else RHSs[0] = 0;                                              \
              fprintf(ERROR_STREAM,"%i: FP RESULT ERROR: %14g %-8s %14s => %14g vs %14g (%g off)\n", \
                      MYTHREAD, LHS, #op, RHSs, result, correct, diff);      \
              fflush(NULL);                                                  \
            }                                                                \
          } while (0)

          FP_OP(UPC_ADD,  &RHS, LHS + RHS);
          FP_OP(UPC_SUB,  &RHS, LHS - RHS);
          FP_OP(UPC_MULT, &RHS, LHS * RHS);
          FP_OP(UPC_MIN,  &RHS, MIN(LHS, RHS));
          FP_OP(UPC_MAX,  &RHS, MAX(LHS, RHS));
          FP_OP(UPC_INC,  NULL, LHS + 1);
          FP_OP(UPC_DEC,  NULL, LHS - 1);

          T flag = (T)43.21;
          T correct = (LHS == RHS) ? flag : LHS;
          upc_atomic_relaxed(d, NULL, UPC_SET, target, &LHS, NULL); 
          upc_atomic_relaxed(d, NULL, UPC_CSWAP, target, &RHS, &flag);
          upc_atomic_relaxed(d, &result, UPC_GET, target, NULL, NULL);
          ASSERTEQ(result, correct);
        }
      }
    }
    upc_all_atomicdomain_free(d);
  }
  #endif

  upc_barrier;
  return errors;
}


/* UPC 1.3 atomics tester
 * Written by Dan Bonachea 
 * Copyright 2013, The Regents of the University of California 
 * This code is under BSD license: http://upc.lbl.gov/download/dist/LICENSE.TXT
 */
/*******************************************************************************
atomic_test is a comprehensive positive correctness tester for the UPC 1.3
atomics library.  It requires a fully-compliant implementation of the atomics
library standard and a UPC 1.2 compliant compiler. It should work on any
platform configuration, although performance may vary significantly.

Build instructions:
Compile atomic_test.upc using your normal UPC command, and link the atomics
library (if necessary).  The helper file atomic_test_help.upc needs to be
present in the source directory but is not directly compiled.  The "width" of
the local block for some of the shared array tests can be overridden at compile
time with -DW=<width> (defaults to 3).

Runtime usage:  atomic_test [iterations] [sections] [seed]

The test defaults to 10000 iterations, which should complete in reasonable time
on most systems, but can be lowered for slower systems or raised to increase
test intensity.  The test works with any number of threads, but provides the
best coverage with at least four threads. Every component test is labelled with
a two-letter section name - an upper-case letter denoting the upc_type_t used
in the test, and a lower-case letter denoting the component test.  The
[sections] command-line argument can be passed a (case-sensitive) list of
section letters to run a selected subset of the tests (defaults to all). Some
tests have a pseudo-randomized component, and the [seed] argument accepts an
integer to override the PRNG seed to improve reproducibility (defaults to a
time-based seed).

Component tests include: 

 - Argument coverage: Tests domain allocation and simple usage of each library
   function for every possible combination of upc_op_t values. This is designed
   to stress library instantiations that switch implementation based on the
   requested set of domain operations.

 - No-op atomics: All threads perform a storm of atomic operations on
   conflicting elements a shared array, where each operation is designed to have
   no semantic effect on the stored value (eg. atomic-add zero). Upon entering
   each (deliberately unsynchronized) iteration, each thread modifies its local
   element, and at the end verifies the value remains unchanged (despite the
   ongoing AMOs). This is designed to test basic concurrent AMO operations to
   conflicting locations, and trivial computational correctness.
 
 - Bit munging: A randomized test where each thread uses fetch-{ADD, SUB, AND,
   OR, XOR} to twiddle some thread-specific bits in random, conflicting elements
   of a shared array. Each thread tracks the correct state of the bits it "owns"
   in each location, and verifies their correctness in the result of each
   fetch-op. This is designed to expose atomicity bugs in concurrent bitwise AMOs,
   especially word tearing or clobbering.
 
 - ADD/SUB/INC/DEC: A randomized test where each thread uses nonfetching
   {ADD/SUB/INC/DEC} to modify random, conflicting elements of a shared array by a
   random amount. Each thread tracks its local contribution to each shared
   "accumulator" and uses a final SUB to nullify its contribution, and after a
   barrier the final accumulator values are verified. Thread contributions are
   kept within predetermined limits to ensure lack of overflow within each
   accumulator during the test. This is designed to expose atomicity bugs in
   concurrent numerical AMOs.
 
 - GET/SET[/CSWAP[/MIN/MAX]]: A randomized set of tests where each thread uses
   fetch-{GET/SET/CSWAP/MIN/MAX} to update random, conflicting elements of a
   shared array to contain values from a small set of allowable values (each value
   is effectively a thread identifier). The result of each fetch-op is verified to
   contain an allowable value. This is designed to expose atomicity bugs in
   concurrent accessor AMOs, especially word tearing or clobbering.
 
 - Unsigned overflow: This test verifies that numeric AMO operations on
   unsigned integer types match C99 arithmetic in the presence of overflow (which
   C99 mandates is well-defined for unsigned integral types). This is designed to
   detect incorrect overflow behavior, especially for AMO implementations that
   offload computation to an auxilliary processor.
 
 - Floating-point limit: This test verifies that numeric AMO operations on
   float/double types match C99 arithmetic, especially in the presence of
   infinities and computational overflow/underflow. This is designed to detect
   incorrect floating point artihemtic, especially for AMO implementations that
   offload computation to an auxilliary processor.
 
Note that some tests are unsupported or partially supported for specific
upc_type_t types - usually due to spec restrictions on supported type/op
combinations, but in some cases for semantic reasons. Unsupported combinations
are automatically skipped.  Most of the component tests for float/double types
use integral values (within a range carefully chosen to avoid precision
errors), thus avoiding the potential for underspecified round-off and ensuring
predictable semantics.

********************************************************************************/
#include <upc.h>
#include <upc_atomic.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define ATOMIC_TEST 1

#define OPS_ACCESS  ((upc_op_t)(UPC_GET | UPC_SET | UPC_CSWAP))
#define OPL_ACCESS  UPC_GET, UPC_SET, UPC_CSWAP
#define OPS_BITWISE ((upc_op_t)(UPC_AND | UPC_OR | UPC_XOR))
#define OPL_BITWISE UPC_AND, UPC_OR, UPC_XOR
#define OPS_NUMERIC ((upc_op_t)(UPC_ADD | UPC_SUB | UPC_MULT | \
                                UPC_INC | UPC_DEC | \
                                UPC_MAX | UPC_MIN))
#define OPL_NUMERIC UPC_ADD, UPC_SUB, UPC_MULT, \
                    UPC_INC, UPC_DEC, \
                    UPC_MAX, UPC_MIN

#define OPS_ALL   (OPS_ACCESS | OPS_BITWISE | OPS_NUMERIC)
#define OPL_ALL   OPL_ACCESS, OPL_BITWISE, OPL_NUMERIC
#define OPS_INT   OPS_ALL
#define OPL_INT   OPL_ALL
#define OPS_PTS   OPS_ACCESS
#define OPL_PTS   OPL_ACCESS
#define OPS_FLOAT (OPS_ACCESS | OPS_NUMERIC)
#define OPL_FLOAT OPL_ACCESS, OPL_NUMERIC

#ifndef ERROR_STREAM
#ifdef BUPC_TEST_HARNESS
#define ERROR_STREAM stdout
#else
#define ERROR_STREAM stderr
#endif
#endif

#define ASSERT(expr) do {                     \
  if (!(expr)) {                              \
    fprintf(ERROR_STREAM, "%i: ERROR Assertion line %i: %s\n", MYTHREAD, __LINE__, #expr); \
    fflush(NULL);                             \
    errors++;                                 \
  } } while(0)

void assert_valformatINT(int64_t val, char *output) {
  sprintf(output, "%lld", (long long)val);
}
void assert_valformatFLOAT(double val, char *output) {
  sprintf(output, "%f", val);
}
void assert_valformatPTS(shared void *val, char *output) {
  sprintf(output, "<th=%i/ph=%i/af=%08llx>", 
          (int)upc_threadof(val), (int)upc_phaseof(val), 
          (unsigned long long)upc_addrfield(val));
}

char v1s[255];
char v2s[255];
#define ASSERTOP(T,CAT,expr1,expr2,op) do {   \
  T _e1 = (expr1);                            \
  T _e2 = (expr2);                            \
  if (!(_e1 op _e2)) {                        \
    _CONCAT(assert_valformat,CAT)(_e1,v1s);   \
    _CONCAT(assert_valformat,CAT)(_e2,v2s);   \
    fprintf(ERROR_STREAM, "%i: ERROR Assertion line %i: %s(%s) %s %s(%s)\n", \
            MYTHREAD, __LINE__,               \
            #expr1, v1s, #op, #expr2, v2s);   \
    fflush(NULL);                             \
    errors++;                                 \
  } } while(0)


#define ASSERTEQ(expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,==)
#define ASSERTNE(expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,!=)
#define ASSERTGT(expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,>)
#define ASSERTGE(expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,>=)
#define ASSERTLT(expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,<)
#define ASSERTLE(expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,<=)

#define ASSERTEQT(T,CAT,expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,==)
#define ASSERTNET(T,CAT,expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,!=)
#define ASSERTGTT(T,CAT,expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,>)
#define ASSERTGET(T,CAT,expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,>=)
#define ASSERTLTT(T,CAT,expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,<)
#define ASSERTLET(T,CAT,expr1,expr2) ASSERTOP(T,CAT,expr1,expr2,<=)

#define ASSERT_FATAL(expr) do {               \
  if (!(expr)) {                              \
    fprintf(ERROR_STREAM, "%i: FATAL ERROR at %s:%i: Assertion failure: %s\n", MYTHREAD, __FILE__, __LINE__, #expr); \
    abort();                                  \
  } } while(0)

#define SRAND()                            \
    upc_barrier;                           \
    static shared unsigned int seed;       \
    if (!MYTHREAD) {                       \
     if (seed_override >= 0) {             \
       seed = (unsigned int)seed_override; \
     } else {                              \
       seed =  (unsigned int)time(NULL);   \
       seed ^= ((unsigned int)clock());    \
       seed %= 0xFFFE;                     \
      }                                    \
    }                                      \
    upc_barrier;                           \
    srand(seed+MYTHREAD)

/* ------------------------------------------------------- */
#define CAT INT
#define CATINT 1

#undef T
#undef TM
#define T  int32_t
#define TM INT32
#include "atomic_test_help.upc"

#undef T
#undef TM
#define T  uint32_t
#define TM UINT32
#include "atomic_test_help.upc"

#undef T
#undef TM
#define T  int64_t
#define TM INT64
#include "atomic_test_help.upc"

#undef T
#undef TM
#define T  uint64_t
#define TM UINT64
#include "atomic_test_help.upc"

#undef T
#undef TM
#define T  int
#define TM INT
#include "atomic_test_help.upc"

#undef T
#undef TM
#define T  unsigned int
#define TM UINT
#include "atomic_test_help.upc"

#undef T
#undef TM
#define T  long
#define TM LONG
#include "atomic_test_help.upc"

#undef T
#undef TM
#define T  unsigned long
#define TM ULONG
#include "atomic_test_help.upc"

#undef CATINT
/* ------------------------------------------------------- */
#undef  CAT
#define CAT FLOAT
#define CATFLOAT 1

#undef T
#undef TM
#define T  float
#define TM FLOAT
#include "atomic_test_help.upc"

#undef T
#undef TM
#define T  double
#define TM DOUBLE
#include "atomic_test_help.upc"

#undef CATFLOAT
/* ------------------------------------------------------- */
#undef  CAT
#define CAT PTS
#define CATPTS 1

#undef T
#undef TM
typedef shared void *svp;
#define T  svp
#define TM PTS
#include "atomic_test_help.upc"

#undef CATPTS
/* ------------------------------------------------------- */

char sections[255];

int main(int argc, char **argv) {
  int iters = 10000;
  int seed = -1;
  if (argc > 1) {
    iters = atoi(argv[1]);
  }
  if (iters < 1) {
    if (!MYTHREAD) fprintf(ERROR_STREAM, "Usage: %s [iterations] [sections] [seed]\n",argv[0]);
    return 1;
  }
  if (argc > 2) {
    strcpy(sections, argv[2]);
  }
  static char ucase[30]; for (int i=0; i < 26; i++) ucase[i] = 'A'+i;
  static char lcase[30]; for (int i=0; i < 26; i++) lcase[i] = 'a'+i;
  if (!strpbrk(sections, ucase)) strcat(sections, ucase);
  if (!strpbrk(sections, lcase)) strcat(sections, lcase);
  if (argc > 3) {
    seed = atoi(argv[3]);
  }

  upc_barrier;
  if (!MYTHREAD) printf("Running %s with %i iterations..\n",argv[0],iters);
  upc_barrier;

  int errors = 0;
  char sec = 'A' - 1;

  #define RUN_TEST(M) do {                      \
    if (strchr(sections, ++sec))                \
      errors += test_##M(iters, sec, sections, seed); \
  } while (0)  

  RUN_TEST(INT32);
  RUN_TEST(UINT32);
  RUN_TEST(INT64);
  RUN_TEST(UINT64);
  RUN_TEST(INT);
  RUN_TEST(UINT); 
  RUN_TEST(LONG);
  RUN_TEST(ULONG);
  RUN_TEST(FLOAT);
  RUN_TEST(DOUBLE);
  RUN_TEST(PTS);
 
  upc_barrier;
  if (errors > 0) printf("%i: %i errors.\n", MYTHREAD, errors);
  fflush(NULL);
  static shared int total;
  upc_atomicdomain_t *dom = upc_all_atomicdomain_alloc(UPC_INT, UPC_ADD, 0);
  upc_atomic_relaxed(dom, NULL, UPC_ADD, &total, &errors, NULL);
  upc_all_atomicdomain_free(dom);
  upc_barrier;
  if (!MYTHREAD) { 
    if (total > 0) printf("FAILED: %i errors.\n", total);
    else printf("SUCCESS\n");
  }
  return 0;
}

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

#define VERBOSE 1

#ifndef MAX
#define MAX(x,y)  ((x)>(y)?(x):(y))
#endif

/*
   UPC 1.2 Spec 6.4.1.2.2:

--begin spec quote--
   The upc_localsizeof operator returns the size, in bytes, of the local portion
   of its operand, which may be a shared object or a shared-qualified type. It
   returns the same value on all threads; the value is an upper bound of the size
   allocated with affinity to any single thread and may include an unspecified
   amount of padding. The result of upc_localsizeof is an integer constant.
--end spec quote--

   Some key points in that text:
   1) "upper bound"
      For static variables this essentially means the value is >= size on thread 0.
   2) "may include an unspecified amount of padding"
      This means a portable test case cannot check for equality.
   3) "integer constant"
      This implies to me (PHH) that I can use it, for instance, as a blocksize.
 */

#if UPC_MAX_BLOCK_SIZE < 65536
  #define BIG_SIZE (UPC_MAX_BLOCK_SIZE / (sizeof(int) * 2))
#else
  #define BIG_SIZE (65536 / (sizeof(int) * 2))
#endif

shared [4] int A[4*THREADS];
shared [4] int B[3*THREADS];
shared [4] char C[THREADS];
shared []  float D[1234];
#if __UPC_STATIC_THREADS__
shared [10] unsigned long E[8];
shared      unsigned long F[128];
shared [*]  double        G[42];
#endif
shared [*]  double        H[5*THREADS];

typedef shared [4] int   T1[4*THREADS];
typedef shared [1] float T2[BIG_SIZE];
typedef shared []  short T3[4321];

shared [BIG_SIZE] int (*p)[BIG_SIZE];
shared [BIG_SIZE] int (*q)[BIG_SIZE-1];
shared [BIG_SIZE/2] int (*r)[BIG_SIZE];
shared [BIG_SIZE/2] int (*s)[BIG_SIZE-1];

// Tests that upc_localsizeof() is truely a compile-time integer constant
shared [upc_localsizeof(A)] char tmpA[THREADS];
shared [upc_localsizeof(B)] char tmpB[THREADS];
shared [upc_localsizeof(C)] char tmpC[THREADS];
shared [upc_localsizeof(D)] char tmpD[THREADS];
#if __UPC_STATIC_THREADS__
shared [upc_localsizeof(E)] char tmpE[THREADS];
shared [upc_localsizeof(F)] char tmpF[THREADS];
shared [upc_localsizeof(G)] char tmpG[THREADS];
#endif
shared [upc_localsizeof(H)] char tmpH[THREADS];
shared [upc_localsizeof(T1)] char tmpT1[THREADS];
shared [upc_localsizeof(T2)] char tmpT2[THREADS];
shared [upc_localsizeof(T3)] char tmpT3[THREADS];
shared [upc_localsizeof(*p)] char (*tmpP)[16];
shared [upc_localsizeof(*q)] char (*tmpQ)[16];
shared [upc_localsizeof(*r)] char (*tmpR)[16];
shared [upc_localsizeof(*s)] char (*tmpS)[16];

shared int fail;

#if VERBOSE
  #define check_msg(_exprstr, _want, _got) \
    if (!MYTHREAD) fprintf(stderr, \
	"upc_localsizeof(%s) = %lu (vs lower bound %lu)\n", \
	(_exprstr), (unsigned long)(_want), (unsigned long)(_got))
#else
  #define check_msg(_exprstr, _want, got) ((void)0)
#endif

#ifdef __BERKELEY_UPC__
  #define check_type(_expr) do { \
      if (!MYTHREAD && !bupc_assert_type(size_t, upc_localsizeof(_expr))) {\
        fprintf (stderr, "wrong type for upc_localsizeof(" #_expr ")\n"); \
        fail = 1; \
      } \
    } while (0)
#else
  #define check_type(_expr) ((void)0)
#endif

#define check(_expr, _size) \
  do { \
    size_t want = (_size); \
    size_t got = upc_localsizeof(_expr); \
    size_t slop = MAX(32, want/128); \
    check_msg(#_expr, got, want); \
    check_type(_expr); \
    if (got < want) { \
      fprintf (stderr, "thread %d observes local size of '" #_expr "' %lu < %lu\n", \
               MYTHREAD, (unsigned long)got, (unsigned long)want); \
      fail = 1; \
    } \
    if (got > want + slop) { \
      fprintf (stderr, "WARNING: thread %d observes suspiciously large local size of '" #_expr "' %lu > %lu\n", \
               MYTHREAD, (unsigned long)got, (unsigned long)want); \
    } \
  } while (0)
#define check_array(_arr) \
  check(_arr, upc_affinitysize(sizeof(_arr), upc_blocksizeof(_arr)*upc_elemsizeof(_arr), 0))
#define check_int_type(_type,_bsize,_elems) \
  check(_type, sizeof(int) * upc_affinitysize((_elems), (_bsize), 0))

int main(void)
{
  if (!MYTHREAD) fail = 0; // Some compilers don't allow shared initializers
  upc_barrier;

  check_array(A);
  check_array(B);
#if __UPC_STATIC_THREADS__
  check_array(C);
#else
  // Must assume at least 1 block, even if not filled for low THREAD values
  check(C, upc_blocksizeof(C)*upc_elemsizeof(C));
#endif
  check_array(D);
#if __UPC_STATIC_THREADS__
  check_array(E);
  check_array(F);
  check_array(G);
#endif
  check_array(H);

  check_array(T1);
#if __UPC_STATIC_THREADS__
  check_array(T2);
#else
  // Same as if THREADS==1, the largest possible value
  check(T2, sizeof(T2));
#endif
  check_array(T3);

  check(*p, sizeof(int) * BIG_SIZE);
  check(*q, sizeof(int) * (BIG_SIZE - 1));
#if __UPC_STATIC_THREADS__
  check(*r, sizeof(int) * upc_affinitysize(BIG_SIZE  , BIG_SIZE/2, 0));
  check(*s, sizeof(int) * upc_affinitysize(BIG_SIZE-1, BIG_SIZE/2, 0));
#else
  // Same as if THREADS==1, the largest possible value
  check(*r, sizeof(*r));
  check(*s, sizeof(*s));
#endif

  check(fail, sizeof(int));

  check(int * shared, sizeof(int *));
  check(shared int * shared, sizeof(int shared *));
  check(shared int, sizeof(int));

  check_int_type(shared [4] int [  THREADS], 4        ,   THREADS);
  check_int_type(shared []  int [    98765], 98765    ,     98765);
  check_int_type(shared     int [4*THREADS], 1        , 4*THREADS);
  check_int_type(shared [*] int [2*THREADS], 2        , 2*THREADS);
#if __UPC_STATIC_THREADS__
  check_int_type(shared [4] int [12], 4 , 12);
  check_int_type(shared []  int [34], 34, 34);
  check_int_type(shared     int [56], 1 , 56);
  check_int_type(shared [*] int [78], (78 + THREADS - 1) / THREADS , 78);
  check_int_type(shared [THREADS] int [90], THREADS, 90);
  check_int_type(shared []  int [3*THREADS], 3*THREADS, 3*THREADS);
#endif

  /*  UPC 1.2 Spec 6.4.1.2.4:
        "If the the operand is an expression, that expression is not evaluated."
      To me that means:
      + pre- and post-{in,de}crement will not occur
      + pointers are not dereferenced
   */
  shared [4] int *p1 = &A[1];
  shared [4] int *p2 = p1;
  shared [4] int *p3 = (shared [4] int *)NULL;
  // Verify no pre-decrement or post-increment occurs:
  check(*(--p1), sizeof(int));
  check(*(p2++), sizeof(int));
  if (p1 != p2) {
    fprintf (stderr,
             "thread %d observes illegal side effect in upc_localsizeof(*(p1++))\n",
             MYTHREAD);
    fail = 1;
  }
  // Verify no dereference occurs:
  check(*p3, sizeof(int));

  upc_barrier;
  if (!MYTHREAD)
    puts(fail ? "FAIL" : "PASS");

  return fail;
}

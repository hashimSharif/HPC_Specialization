#ifndef __UPC_ATOMIC__
#error pre-defined __UPC_ATOMIC__ is undefined.
#endif
#if __UPC_ATOMIC__ != 1
#error pre-defined __UPC_ATOMIC__ is != 1.
#endif

#include <upc.h>
#include <upc_atomic.h>
#include <stdint.h>
#include <stdio.h>

#if DEBUG && !defined(NDEBUG)
int debug = 1;
#else
int debug = 0;
#endif

#define NO_RESULT_CHECK 0
#define RESULT_CHECK 1

shared int failures = 0;
upc_atomicdomain_t *d;

/* Parallel test number of loops.  */
#ifndef LOOPCNT
#define LOOPCNT 10
#endif

#define ARITH_OPS \
  UPC_SET|UPC_GET|UPC_ADD|UPC_SUB|UPC_MULT|UPC_INC|UPC_DEC|UPC_MAX|UPC_MIN

#define ARITH_TEST(_type,_code)					\
static shared _type var_##_code;				\
_type evar_##_code, fvar_##_code;				\
void set_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL; \
    upc_atomic_relaxed (d, sval, UPC_SET, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_SET returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    evar_##_code = val;						\
  }								\
void get_##_code(shared _type *sp, int check)			\
  {								\
    upc_atomic_relaxed (d, &fvar_##_code, UPC_GET,		\
			sp, NULL, NULL);			\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_GET returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    evar_##_code = fvar_##_code;				\
  }								\
void add_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_relaxed (d, sval, UPC_ADD, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_ADD returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    evar_##_code = evar_##_code + val;				\
  }								\
void sub_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_relaxed (d, sval, UPC_SUB, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_SUB returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    evar_##_code = evar_##_code - val;				\
  }								\
void mult_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_relaxed (d, sval, UPC_MULT, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_MULT returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    evar_##_code = evar_##_code * val;				\
  }								\
void inc_##_code(shared _type *sp, int check)			\
  {								\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_relaxed (d, sval, UPC_INC, sp, NULL, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_INC returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    ++evar_##_code;						\
  }								\
void dec_##_code(shared _type *sp, int check)			\
  {								\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_relaxed (d, sval, UPC_DEC, sp, NULL, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_DEC returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    --evar_##_code;						\
  }								\
void min_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_relaxed (d, sval, UPC_MIN, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_MIN returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    if (val < evar_##_code)					\
      evar_##_code = val;					\
  }								\
void max_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL; \
    upc_atomic_relaxed (d, sval, UPC_MAX, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_MAX returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    if (val > evar_##_code)					\
      evar_##_code = val;					\
  }								\
void test_##_code(void)						\
  {								\
    int prev_failures = failures;				\
    int atomic_perf;						\
    int i, j;							\
								\
    atomic_perf = upc_atomic_isfast (_code, ARITH_OPS, &var_##_code); \
								\
    /* Create atomic domain.  */				\
    d = upc_all_atomicdomain_alloc (_code, ARITH_OPS, 0);	\
								\
    if (debug && !MYTHREAD)					\
      {								\
	printf ("+ UPC arithmetic atomics (" #_code ")\n");	\
	fflush(stdout);						\
      }								\
								\
    for (i=0; i<THREADS; ++i)					\
      {								\
	if (i != MYTHREAD)					\
	  {							\
	    upc_barrier i;					\
	    continue;						\
	  }							\
	if (debug && !MYTHREAD)					\
	  {							\
	    printf ("++ serial tests\n");			\
	    fflush(stdout);					\
	  }							\
	/* ADD/SUB/MULT */					\
	set_##_code (&var_##_code, 1, NO_RESULT_CHECK);		\
	get_##_code (&var_##_code, RESULT_CHECK);		\
	set_##_code (&var_##_code, 3, RESULT_CHECK);		\
	add_##_code (&var_##_code, 15, RESULT_CHECK);		\
	sub_##_code (&var_##_code, 5, RESULT_CHECK);		\
	mult_##_code (&var_##_code, 7, RESULT_CHECK);		\
	/* Verify result.  */					\
	get_##_code (&var_##_code, RESULT_CHECK);		\
								\
	/* INC/DEC */						\
	for (j=0; j<1000; ++j)					\
	  inc_##_code (&var_##_code, RESULT_CHECK);		\
	for (j=0; j<1000; ++j)					\
	  dec_##_code (&var_##_code, RESULT_CHECK);		\
								\
	/* MIN/MAX */						\
	{							\
	  for (j=0; j<1000; j++)				\
	    min_##_code (&var_##_code, var_##_code - 1,		\
						RESULT_CHECK);	\
	  for (j=0; j<1000; j++)				\
	    max_##_code (&var_##_code, var_##_code + 1,		\
						RESULT_CHECK);	\
	  get_##_code (&var_##_code, RESULT_CHECK);		\
	}							\
        upc_barrier i;						\
      }								\
    upc_barrier;						\
								\
    /* PARALLEL (pounding) tests */				\
    if (debug && !MYTHREAD)					\
      {								\
        printf("++ parallel tests\n");				\
        fflush(stdout);						\
      }								\
    set_##_code (&var_##_code, 0, NO_RESULT_CHECK);		\
    upc_barrier;						\
								\
    /* Add thread number to atomic var - LOOPCNT times.  */	\
    for (i=0; i<LOOPCNT; ++i)					\
      add_##_code (&var_##_code, MYTHREAD, NO_RESULT_CHECK);	\
    upc_barrier;						\
    /* Calculate expected result and compare.  */		\
    evar_##_code = THREADS * (THREADS - 1) * LOOPCNT / 2;	\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    								\
    /* Sub thread number to atomic var - LOOPCNT times.  */	\
    for (i=0; i<LOOPCNT; ++i)					\
      sub_##_code (&var_##_code, MYTHREAD, NO_RESULT_CHECK);	\
    upc_barrier;						\
    evar_##_code = (_type) 0;					\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    								\
    /* Multiply atomic var - LOOPCNT times.  */			\
    set_##_code (&var_##_code, 1, NO_RESULT_CHECK);		\
    upc_barrier;						\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    /* bug3221: bound iter to avoid signed integer overflow */  \
    /* bug3224: volatile to avoid xlc mis-optimization */       \
    volatile int iter = sizeof(_type)*8-2;                      \
    int myiter;                                                 \
    if (THREADS > iter) myiter = (MYTHREAD >= iter?0:1);        \
    else { myiter = iter/THREADS; iter = myiter*THREADS; }      \
    volatile int limit = (iter>LOOPCNT)?iter:LOOPCNT;           \
    for (i=0; i < limit; ++i)		                        \
      mult_##_code (&var_##_code, (i<myiter)?2:1, NO_RESULT_CHECK); \
    upc_barrier;						\
    /* Calc expected result and compare.  */			\
    evar_##_code = (_type) 1;					\
    for (i=0; i<iter; ++i)				        \
      evar_##_code *= 2;					\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    								\
    /* Inc atomic variable - each thread LOOPCNT times.  */	\
    set_##_code (&var_##_code, 0, NO_RESULT_CHECK);		\
    upc_barrier;						\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    for (i=0; i<LOOPCNT; ++i)					\
      inc_##_code (&var_##_code, NO_RESULT_CHECK);		\
    upc_barrier;						\
    /* Cal expected result and compare to atomic variable.  */  \
    evar_##_code = (_type) (THREADS * LOOPCNT);			\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    								\
    /* Dec atomic variable - LOOPCNT times.  */			\
    for (i=0; i<LOOPCNT; ++i)					\
      dec_##_code (&var_##_code, NO_RESULT_CHECK);		\
    upc_barrier;						\
    evar_##_code = (_type) 0;					\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    								\
    /* Min of thread numbers - LOOPCNT times.  */		\
    set_##_code (&var_##_code, 10000, NO_RESULT_CHECK);		\
    upc_barrier;						\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    for (i=0; i<LOOPCNT; ++i)					\
      min_##_code (&var_##_code, MYTHREAD, NO_RESULT_CHECK);	\
    upc_barrier;						\
    evar_##_code = 0;						\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    								\
    /* Max of thread numbers - LOOPCNT times.  */		\
    set_##_code (&var_##_code, 0, NO_RESULT_CHECK);		\
    upc_barrier;						\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
    for (i=0; i<LOOPCNT; ++i)					\
      max_##_code (&var_##_code, MYTHREAD, NO_RESULT_CHECK);	\
    upc_barrier;						\
    evar_##_code = THREADS - 1;					\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
								\
    upc_all_atomicdomain_free (d);				\
								\
    if (debug && !MYTHREAD && (prev_failures == failures))	\
      {								\
	puts("PASS");						\
      }								\
}

ARITH_TEST (int, UPC_INT)
ARITH_TEST (unsigned int, UPC_UINT)
ARITH_TEST (long, UPC_LONG)
ARITH_TEST (unsigned long, UPC_ULONG)
ARITH_TEST (int32_t, UPC_INT32)
ARITH_TEST (uint32_t, UPC_UINT32)
ARITH_TEST (int64_t, UPC_INT64)
ARITH_TEST (uint64_t, UPC_UINT64)
ARITH_TEST (float, UPC_FLOAT)
ARITH_TEST (double, UPC_DOUBLE)
     int main (void)
{

  test_UPC_INT ();
  test_UPC_UINT ();
  test_UPC_LONG ();
  test_UPC_ULONG ();
  test_UPC_INT32 ();
  test_UPC_UINT32 ();
  test_UPC_INT64 ();
  test_UPC_UINT64 ();
  test_UPC_FLOAT ();
  test_UPC_DOUBLE ();
  upc_barrier;
  if (!MYTHREAD)
    {
      printf ("atomic_r_arith: %s\n", failures ? "FAILURE" : "SUCCESS");
    }
  upc_barrier;
  return failures;
}

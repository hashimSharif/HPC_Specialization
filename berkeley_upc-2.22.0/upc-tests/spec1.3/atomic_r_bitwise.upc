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

#define BITWISE_OPS UPC_OR|UPC_XOR|UPC_AND|UPC_GET|UPC_SET

#define BITWISE_TEST(_type,_code)				\
static shared _type var_##_code;				\
_type evar_##_code, fvar_##_code, op1_##_code;			\
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
void and_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL; \
    upc_atomic_relaxed (d, sval, UPC_AND, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR [%d]: " #_code " UPC_AND returned %d (%d)\n",\
		MYTHREAD, (int)fvar_##_code, (int)evar_##_code);\
	++failures;						\
      }								\
    evar_##_code = evar_##_code & val;				\
  }								\
void or_##_code(shared _type *sp, _type val, int check)		\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL; \
    upc_atomic_relaxed (d, sval, UPC_OR, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_OR returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    evar_##_code = evar_##_code | val;				\
  }								\
void xor_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL; \
    upc_atomic_relaxed (d, sval, UPC_XOR, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_XOR returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    evar_##_code = evar_##_code ^ val;				\
  }								\
void test_##_code(void)						\
  {								\
    int prev_failures = failures;				\
    int atomic_perf;						\
    int i;							\
								\
    atomic_perf = upc_atomic_isfast (_code, BITWISE_OPS, &var_##_code); \
								\
    /* Create an atomic domain.  */				\
    d = upc_all_atomicdomain_alloc (_code, BITWISE_OPS, 0);	\
								\
    /* Private tests */						\
    if (debug && !MYTHREAD)					\
      {								\
	printf ("+ UPC bitwise atomics (" #_code ")\n");	\
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
	    printf ( "++ serial tests\n");			\
	    fflush(stdout);					\
	  }							\
								\
	set_##_code (&var_##_code, 1, NO_RESULT_CHECK);		\
	set_##_code (&var_##_code, 3, RESULT_CHECK);		\
	xor_##_code (&var_##_code, 6, RESULT_CHECK);		\
	or_##_code (&var_##_code, 10, RESULT_CHECK);		\
	and_##_code (&var_##_code, 24, RESULT_CHECK);		\
	get_##_code (&var_##_code, RESULT_CHECK);		\
								\
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
    upc_barrier;						\
								\
    set_##_code (&var_##_code, 0, NO_RESULT_CHECK);		\
    upc_barrier;						\
    or_##_code (&var_##_code, 1 << MYTHREAD, NO_RESULT_CHECK);	\
    upc_barrier;						\
    evar_##_code = 0;						\
    for (i=0; i<THREADS; i++)					\
      evar_##_code |= 1 << i;					\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
								\
    xor_##_code (&var_##_code, 1 << MYTHREAD, NO_RESULT_CHECK);	\
    upc_barrier;						\
    evar_##_code = 0;						\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
								\
    and_##_code (&var_##_code, 1 << MYTHREAD, RESULT_CHECK);	\
    upc_barrier;						\
    get_##_code (&var_##_code, RESULT_CHECK);			\
    upc_barrier;						\
								\
    upc_all_atomicdomain_free (d);				\
								\
    if (debug && !MYTHREAD && (prev_failures == failures))	\
      puts("PASS");						\
}

BITWISE_TEST (int, UPC_INT)
BITWISE_TEST (unsigned int, UPC_UINT)
BITWISE_TEST (long, UPC_LONG)
BITWISE_TEST (unsigned long, UPC_ULONG)
BITWISE_TEST (int32_t, UPC_INT32)
BITWISE_TEST (uint32_t, UPC_UINT32)
BITWISE_TEST (int64_t, UPC_INT64)
BITWISE_TEST (uint64_t, UPC_UINT64)
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
  upc_barrier;
  if (!MYTHREAD)
    {
      printf ("atomic_r_bitwise: %s\n", failures ? "FAILURE" : "SUCCESS");
    }
  upc_barrier;
  return failures;
}

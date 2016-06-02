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
static shared int sum[THREADS];

/* Parallel test number of loops.  */
#ifndef LOOPCNT
#define LOOPCNT 10
#endif

#define ACCESS_OPS \
  UPC_SET|UPC_GET|UPC_CSWAP

#define ACCESS_TEST(_type,_code)				\
static shared _type var_##_code;				\
static _type evar_##_code, fvar_##_code, exp_var_##_code;	\
void set_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_strict (d, sval, UPC_SET, sp, &lval, NULL);	\
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
    upc_atomic_strict (d, &fvar_##_code,			\
			UPC_GET, sp, NULL, NULL);		\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_GET returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    evar_##_code = fvar_##_code;				\
  }								\
void cswap_##_code(shared _type *sp, _type val,	_type eval,	\
		   int check) 					\
  {								\
    _type lval = val;						\
    _type elval = eval;						\
    upc_atomic_strict (d, &fvar_##_code,			\
			UPC_CSWAP, sp, &elval, &lval);		\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_CSWAP returned %d (%d)\n",\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
    if (fvar_##_code == eval) 					\
      evar_##_code = val;					\
  }								\
void test_##_code(void)						\
  {								\
    int prev_failures = failures;				\
    int i;							\
								\
    /* Create atomic domain.  */				\
    d = upc_all_atomicdomain_alloc (_code, ACCESS_OPS, 0);	\
								\
    if (debug && !MYTHREAD)					\
      {								\
	printf ("+ UPC access atomics (" #_code ")\n");		\
	fflush(stdout);						\
      }								\
								\
    for (i=0; i<THREADS; ++i)					\
      {								\
	int j;							\
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
	for (j=0; j<LOOPCNT; ++j)				\
	  {							\
	    cswap_##_code (&var_##_code, var_##_code + 1,	\
			   var_##_code, RESULT_CHECK);		\
	  }							\
	get_##_code (&var_##_code, RESULT_CHECK);		\
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
    /* Increment atomic variable by each thread.  */		\
    do								\
      {								\
	exp_var_##_code = var_##_code;				\
	cswap_##_code (&var_##_code, exp_var_##_code + 1,	\
			   exp_var_##_code, NO_RESULT_CHECK);	\
      } while (fvar_##_code != exp_var_##_code);		\
    upc_barrier;						\
    evar_##_code = THREADS;					\
    get_##_code (&var_##_code, RESULT_CHECK);			\
								\
    upc_barrier;						\
    upc_all_atomicdomain_free (d);				\
								\
    if (debug && !MYTHREAD && (prev_failures == failures))	\
      {								\
	puts("PASS");						\
      }								\
}
#define ACCESS_BITSPIN_TEST(_type,_code)			\
void test_bitspin_##_code(void)					\
  {								\
    int prev_failures = failures;				\
    int atomic_perf;						\
    int i, chgno = 0;						\
								\
    atomic_perf = upc_atomic_isfast (_code, ACCESS_OPS, &var_##_code); \
								\
    /* Create atomic domain.  */				\
    d = upc_all_atomicdomain_alloc (_code, ACCESS_OPS, 0);	\
								\
    upc_barrier;						\
    if (!MYTHREAD)						\
      {								\
	if (debug)						\
	  {							\
	    printf ("+ UPC cswap atomics (" #_code ")\n");	\
	    fflush(stdout);					\
	  }							\
	for (i=0; i<THREADS; ++i)				\
	  sum[i] = 0;						\
	set_##_code (&var_##_code, 0, NO_RESULT_CHECK);		\
      }								\
    evar_##_code = 0;						\
    upc_barrier;						\
								\
    {								\
      _type mbit, ebit;						\
      int notfull = 1;						\
      unsigned int thrno = (MYTHREAD % (sizeof(_type) * 8));	\
      mbit = ((_type) 1) << thrno;				\
      ebit = thrno ? (((_type) 1) << (thrno - 1)) : 0;		\
      while (notfull)						\
	{							\
	  int notdone = 1;					\
	  while (notdone)					\
	    {							\
	      cswap_##_code (&var_##_code,			\
			     mbit, ebit, NO_RESULT_CHECK);	\
	      if ((unsigned long long) fvar_##_code >=		\
	          (unsigned long long) ebit)			\
		{						\
		  notdone = 0;					\
		  if (fvar_##_code == ebit)			\
		    sum[MYTHREAD]++; 				\
		  thrno += THREADS;				\
		  if (thrno >= (sizeof(_type) * 8))		\
		    notfull = 0;				\
		  mbit = ((_type) 1) << thrno;			\
		  ebit = ((_type) 1) << (thrno - 1);		\
		}						\
	    }							\
	}							\
    }								\
    upc_barrier;						\
    if (!MYTHREAD)						\
      {								\
	for (i=0; i<THREADS; ++i)				\
	  {							\
	    chgno += sum[i];					\
	  }							\
   	if (chgno != (sizeof(_type) * 8))			\
	  {							\
	    printf ("Successful updates are %d instead of %d\n",\
		     chgno, (int) sizeof(_type) * 8);		\
	    failures++;						\
	  }							\
      }								\
								\
    upc_all_atomicdomain_free (d);				\
								\
    if (debug && !MYTHREAD && (prev_failures == failures))	\
      {								\
	puts("PASS");						\
      }								\
}

ACCESS_TEST (int, UPC_INT)
ACCESS_TEST (unsigned int, UPC_UINT)
ACCESS_TEST (long, UPC_LONG)
ACCESS_TEST (unsigned long, UPC_ULONG)
ACCESS_TEST (int32_t, UPC_INT32)
ACCESS_TEST (uint32_t, UPC_UINT32)
ACCESS_TEST (int64_t, UPC_INT64)
ACCESS_TEST (uint64_t, UPC_UINT64)
ACCESS_TEST (float, UPC_FLOAT)
ACCESS_TEST (double, UPC_DOUBLE)
ACCESS_BITSPIN_TEST (int, UPC_INT)
ACCESS_BITSPIN_TEST (unsigned int, UPC_UINT)
ACCESS_BITSPIN_TEST (long, UPC_LONG)
ACCESS_BITSPIN_TEST (unsigned long, UPC_ULONG)
ACCESS_BITSPIN_TEST (int32_t, UPC_INT32)
ACCESS_BITSPIN_TEST (uint32_t, UPC_UINT32)
ACCESS_BITSPIN_TEST (int64_t, UPC_INT64)
ACCESS_BITSPIN_TEST (uint64_t, UPC_UINT64)
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

  test_bitspin_UPC_INT ();
  test_bitspin_UPC_UINT ();
  test_bitspin_UPC_LONG ();
  test_bitspin_UPC_ULONG ();
  test_bitspin_UPC_INT32 ();
  test_bitspin_UPC_UINT32 ();
  test_bitspin_UPC_INT64 ();
  test_bitspin_UPC_UINT64 ();

  upc_barrier;
  if (!MYTHREAD)
    {
      printf ("atomic_s_access: %s\n", failures ? "FAILURE" : "SUCCESS");
    }
  upc_barrier;
  return failures;
}

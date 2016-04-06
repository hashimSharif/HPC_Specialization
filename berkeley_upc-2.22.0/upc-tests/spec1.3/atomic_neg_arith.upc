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
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_relaxed (d, sval, UPC_ADD, sp, NULL, NULL);	\
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
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_relaxed (d, sval, UPC_SUB, sp, NULL, NULL);	\
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
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL;	\
    upc_atomic_relaxed (d, sval, UPC_MULT, sp, NULL, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_SUB returned %d (%d)\n",	\
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
	printf("ERROR: " #_code " UPC_SUB returned %d (%d)\n",	\
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
	printf("ERROR: " #_code " UPC_SUB returned %d (%d)\n",	\
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
	printf("ERROR: " #_code " UPC_SUB returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
  }								\
void max_##_code(shared _type *sp, _type val, int check)	\
  {								\
    _type lval = val;						\
    _type *sval = (check==RESULT_CHECK) ? &fvar_##_code : NULL; \
    upc_atomic_relaxed (d, sval, UPC_MAX, sp, &lval, NULL);	\
    if (check == RESULT_CHECK && fvar_##_code != evar_##_code)	\
      {								\
	printf("ERROR: " #_code " UPC_SUB returned %d (%d)\n",	\
		(int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
  }								\
void test_##_code(void)						\
  {								\
    int i;							\
								\
    /* Create atomic domain.  */				\
    d = upc_all_atomicdomain_alloc (_code, ARITH_OPS, 0);	\
								\
    for (i=0; i<THREADS; ++i)					\
      {								\
	if (i != MYTHREAD)					\
	  {							\
	    upc_barrier i;					\
	    continue;						\
	  }							\
	/* ADD/SUB/MULT */					\
	add_##_code (&var_##_code, 15, RESULT_CHECK);		\
	sub_##_code (&var_##_code, 5, RESULT_CHECK);		\
	mult_##_code (&var_##_code, 7, RESULT_CHECK);		\
								\
        upc_barrier i;						\
      }								\
    upc_barrier;						\
								\
    upc_all_atomicdomain_free (d);				\
}

ARITH_TEST (int, UPC_INT)
     int main (void)
{
  test_UPC_INT ();
  upc_barrier;
  if (!MYTHREAD)
    {
      printf ("atomic_neg_arith: %s\n", failures ? "FAILURE" : "SUCCESS");
    }
  upc_barrier;
  return failures;
}

#include <upc.h>
#include <upc_atomic.h>
#include <stdint.h>
#include <stdio.h>

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
	printf("ERROR [%d]: " #_code " UPC_AND returned %d (%d)\n",	\
		MYTHREAD, (int)fvar_##_code, (int)evar_##_code);		\
	++failures;						\
      }								\
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
  }								\
void test_##_code(void)						\
  {								\
    int i;							\
								\
    /* Create an atomic domain.  */				\
    d = upc_all_atomicdomain_alloc (_code, BITWISE_OPS, 0);	\
								\
    /* Private tests */						\
    for (i=0; i<THREADS; ++i)					\
      {								\
	if (i != MYTHREAD)					\
	  {							\
	    upc_barrier i;					\
	    continue;						\
	  }							\
								\
	xor_##_code (&var_##_code, 6, RESULT_CHECK);		\
	or_##_code (&var_##_code, 10, RESULT_CHECK);		\
	and_##_code (&var_##_code, 24, RESULT_CHECK);		\
								\
        upc_barrier i;						\
      }								\
    upc_barrier;						\
								\
    upc_all_atomicdomain_free (d);				\
}

BITWISE_TEST (float, UPC_FLOAT)
     int main (void)
{
  test_UPC_FLOAT ();
  upc_barrier;
  if (!MYTHREAD)
    {
      printf ("atomic_neg_bitwise: %s\n", failures ? "FAILURE" : "SUCCESS");
    }
  upc_barrier;
  return failures;
}

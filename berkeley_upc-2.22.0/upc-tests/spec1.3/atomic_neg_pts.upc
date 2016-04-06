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

#define ACCESS_OPS \
  UPC_SET|UPC_GET|UPC_CSWAP

#define ACCESS_PTS_TEST(_type,_code)
static shared int inta, intb;
static shared int a[THREADS];
static shared void *shared var;
static shared void *vara;
static shared void *fvar;
void
test_pts (void)
{
  int i;

  d = upc_all_atomicdomain_alloc (UPC_PTS, ACCESS_OPS, 0);
  if (debug && !MYTHREAD)
    {
      printf ("+ UPC access atomics (UPC_PTS)\n");
      fflush (stdout);
    }
  for (i = 0; i < THREADS; ++i)
    {
      if (i != MYTHREAD)
	{
	  upc_barrier i;
	  continue;
	}
      if (debug && !MYTHREAD)
	{
	  printf ("++ serial tests\n");
	  fflush (stdout);
	}
      /* ERROR on bitwise.  */
      upc_atomic_relaxed (d, &fvar, UPC_XOR, &var, &vara, NULL);
      upc_atomic_relaxed (d, &fvar, UPC_OR, &var, &vara, NULL);
      upc_atomic_relaxed (d, &fvar, UPC_XOR, &var, &vara, NULL);
    }
  upc_barrier;

  upc_all_atomicdomain_free (d);
}

int
main (void)
{
  test_pts ();
  upc_barrier;
  if (!MYTHREAD)
    {
      printf ("atomic_neg_pts: %s\n", failures ? "FAILURE" : "SUCCESS");
    }
  upc_barrier;
  return failures;
}

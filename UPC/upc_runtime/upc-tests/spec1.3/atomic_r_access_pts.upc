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

#define ACCESS_OPS \
  UPC_SET|UPC_GET|UPC_CSWAP

static shared int inta, intb;
static shared int a[THREADS];
/* note: UPC_PTS locations passed to upc_atomic must be declared as (shared void *) */
static shared void *shared var;
static shared void *vara;
static shared void *varb;
static shared void *fvar;
static shared void *exp_var;
void
test_pts (void)
{
  int prev_failures = failures;
  int atomic_perf;
  int i;

  atomic_perf = upc_atomic_isfast (UPC_PTS, ACCESS_OPS, &var);

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
      vara = &inta;
      varb = &intb;
      var = vara;
      if (debug && !MYTHREAD)
	{
	  printf ("++ serial tests\n");
	  fflush (stdout);
	}
      /* SET/GET/CSWAP */
      upc_atomic_relaxed (d, &fvar, UPC_SET, &var, &vara, NULL);
      upc_atomic_relaxed (d, &fvar, UPC_GET, &var, NULL, NULL);
      if (fvar != vara)
	{
	  printf ("ERROR: UPC_GET returned wrong pointer\n");
	  ++failures;
	}
      upc_atomic_relaxed (d, &fvar, UPC_CSWAP, &var, &vara, &varb);
      if (fvar != vara)
	{
	  printf ("ERROR: UPC_CSWAP returned wrong pointer\n");
	  ++failures;
	}
      upc_atomic_relaxed (d, &fvar, UPC_GET, &var, NULL, NULL);
      if (fvar != varb)
	{
	  printf ("ERROR: UPC_GET after UPC_CSWAP returned wrong pointer\n");
	  ++failures;
	}
      upc_barrier i;
    }
  upc_barrier;

  /* PARALLEL (pounding) tests */
  if (debug && !MYTHREAD)
    {
      printf ("++ parallel tests\n");
      fflush (stdout);
    }
  a[MYTHREAD] = 0;
  upc_barrier;
  vara = &a[THREADS];
  /* Each thread tries to set a shared pointer LOOPCNT times
     to point to its own array entry.  */
  for (i = 0; i < LOOPCNT; i++)
    {
      fvar = vara;
      do
	{
	  exp_var = fvar;
	  upc_atomic_relaxed (d, &fvar, UPC_CSWAP, &var, &exp_var, &vara);
	}
      while (fvar != exp_var);
      ++a[MYTHREAD];
    }
  upc_barrier;
  if (a[MYTHREAD] != LOOPCNT)
    {
      printf ("ERROR: Number of CSWAP successes is wrong\n");
      ++failures;
    }

  upc_all_atomicdomain_free (d);

  if (debug && !MYTHREAD && (prev_failures == failures))
    {
      puts ("PASS");
    }
}

int
main (void)
{
  test_pts ();
  upc_barrier;
  if (!MYTHREAD)
    {
      printf ("atomic_r_access_pts: %s\n", failures ? "FAILURE" : "SUCCESS");
    }
  upc_barrier;
  return failures;
}

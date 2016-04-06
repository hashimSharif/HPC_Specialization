#include <upc.h>
#include <stdio.h>

#define check(t) \
  if (!(t)) \
    { \
      fprintf (stderr, "%s:%d (thread %d) Error: test failed: %s\n", \
               __FILE__, __LINE__, MYTHREAD, #t); \
      fail = 1; \
    }

shared int var = 1;
shared int var_val = 2;

shared [1] int pinfo [  THREADS];
shared [3] int info  [3*THREADS];

int main(void)
{
  int fail = 0;

  check(var == 1);
  check(var_val == 2);

  puts(fail ? "FAIL" : "PASS");
  upc_barrier;

  return fail;
}

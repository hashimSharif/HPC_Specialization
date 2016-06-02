#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 5

#define check(t) \
  if (!(t)) \
    { \
      fprintf (stderr, "%s:%d (thread %d) Error: test failed: %s\n", \
               __FILE__, __LINE__, MYTHREAD, #t); \
      fail = 1; \
    }

shared int A[N*N*THREADS];

shared [1] int *          psi1  = (shared [1] int *)&A;
shared [N] int *          psiN  = (shared [N] int *)&A;
shared []  int *          psiI0 = (shared [] int *)&A; 

shared [1] int * shared s_psi1  = (shared [1] int *)&A;
shared [N] int * shared s_psiN  = (shared [N] int *)&A;
shared []  int * shared s_psiI0 = (shared [] int *)&A; 

const char *sptr(shared void *p)
{
  static char msg[100];
  sprintf(msg, "(%lx,%d,%d)",
         (unsigned long int)upc_addrfield(p),
         (int)upc_threadof(p), (int)upc_phaseof(p));
  return (const char *)msg;
}

int main()
{
  int fail = 0;
  printf ("%d: (shared void *)&A = %s\n", MYTHREAD, sptr((shared void *)&A));
  printf ("%d: (shared void *)psi1 = %s\n", MYTHREAD, sptr((shared void *)psi1));
  upc_barrier;
  check((shared void *)psi1 == (shared void *)&A);
  check((shared void *)psiN == (shared void *)&A);
  check((shared void *)psiI0 == (shared void *)&A);
  check((shared void *)s_psi1 == (shared void *)&A);
  check((shared void *)s_psiN == (shared void *)&A);
  check((shared void *)s_psiI0 == (shared void *)&A);
  upc_barrier;
  printf ("%d: Test static initializaion of expressions"
          " which refer to shared addresses: %s.\n",
          MYTHREAD, fail ? "FAIL" : "PASS");
  return fail;
}

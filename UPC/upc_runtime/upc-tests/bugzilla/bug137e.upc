#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

shared int si;

double foo(va_list ap) {
#ifdef __BERKELEY_UPC__
  // Not actually valid in C99, but BUPC's translator "fixes" this:
  int x = va_arg((NULL,ap), int);
#else
  int x = va_arg(ap, int);
#endif
  double y = *va_arg(ap, double *);

  shared int *psi = va_arg(ap, int shared *);
  assert(psi == &si);
  shared void *psv = va_arg(ap, shared void *);
  assert(psv == &si);
  shared [10] int *psiB = va_arg(ap, shared [10] int *);
  assert(psiB == (shared [10] int *)&si);
  shared [] int *psiI = va_arg(ap, shared [] int *);
  assert(psiI == (shared [] int *)&si);
  shared [0] int *psi0 = va_arg(ap, shared [0] int *);
  assert(psi0 == (shared [0] int *)&si);
  shared [1] int *psi1 = va_arg(ap, shared [1] int *);
  assert(psi1 == &si);
  shared void **ppsv = va_arg(ap, shared void **);
  assert(*ppsv == &si);
  shared void **ppsv2 = va_arg(ap, void shared **);
  assert(*ppsv2== &si);
  return x + y;
}

double bar(int last, ...) {
  va_list ap;
  double d;

  va_start(ap, last);
  d = foo(ap);
  va_end(ap);

  return d;
}
int main(void) {
  shared void *psv = &si;
  shared int *psi = &si;
  shared [10] int *psiB = psv;
  shared [] int *psiI = psv;
  shared [0] int *psi0 = psv;
  shared [1] int *psi1 = psv;
  shared void **ppsv = &psv;
  double a = 7.0;
  si = 10;
  double b = bar(0, 1, &a, psi, psv, psiB, psiI, psi0, psi1, ppsv, ppsv);
  char str[] = "bupc_mangled_va_arg()";

  if (b != 8.0) {
    /* While floating-point comparisions are not safe in general, small integers are OK */
    printf("FAILED (result = %g but expect 8.0)\n", b);
  } else if (strlen(str) != 21) {
    printf("FAILED (modification of non-matching string)\n");
  } else {
    printf("SUCCESS\n");
  }

  upc_barrier;

  return 0;
}

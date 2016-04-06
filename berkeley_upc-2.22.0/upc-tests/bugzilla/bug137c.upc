#include <stdarg.h>
#include <stdio.h>
#include <string.h>

struct xyz {
  int a;
  int b;
};

double foo(va_list ap) {
#ifdef __BERKELEY_UPC__
  // Not actually valid in C99, but BUPC's translator "fixes" this:
  int x = va_arg((NULL,ap), int);
#else
  int x = va_arg(ap, int);
#endif
  double y = *va_arg(ap, double *);
  struct xyz q = va_arg(ap, struct xyz);
  return x + y + q.b;
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
  struct xyz q = {0,1};
  double a = 7.0;
  double b = bar(0, 1, &a, q);
  char str[] = "bupc_mangled_va_arg()";

  if (b != 9.0) {
    /* While floating-point comparisions are not safe in general, small integers are OK */
    printf("FAILED (result = %g but expect 9.0)\n", b);
  } else if (strlen(str) != 21) {
    printf("FAILED (modification of non-matching string)\n");
  } else {
    printf("SUCCESS\n");
  }

  upc_barrier;

  return 0;
}

#include <upc.h>
#include <stdio.h>

#if 1
#define DATA double // Yields back-end compiler error(s)
#else
#define DATA int // Yields back-end compiler warning(s)
#endif

DATA a = 5;
shared struct {
  DATA *p;
  DATA i;
} Var = {NULL, 6};

int main(void)
{
  if (!MYTHREAD) {
    Var.p = &a;

    DATA * shared [] * ppp = &(Var.p);

    // extra work to encourage NB get for p
    DATA i = Var.i;

    // warning comes here:
    DATA p = **ppp;

    puts((p == (i-1)) ? "PASS" : "FAIL");
  }

  return 0;
}

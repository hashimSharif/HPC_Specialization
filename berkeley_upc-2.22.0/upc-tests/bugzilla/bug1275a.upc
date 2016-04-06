#include <upc.h>
#include <stdio.h>

double b[256][256];
double *pb00 = &(b[0][0]);
double *pb01 = &(b[0][1]);
double *pb10 = &(b[1][0]);
double *pb11 = &(b[1][1]);

#define check(_idx) do {\
    if (pa##_idx != pb##_idx) \
      printf("FAIL: Bad value for pb" #_idx "\n"); \
  } while(0)

int main(int argc, char **argv) {
  double *pa00 = &(b[0][0]);
  double *pa01 = &(b[0][1]);
  double *pa10 = &(b[1][0]);
  double *pa11 = &(b[1][1]);

  check(00);
  check(01);
  check(10);
  check(11);

  if (!MYTHREAD) puts("done.");

  return 0;
}

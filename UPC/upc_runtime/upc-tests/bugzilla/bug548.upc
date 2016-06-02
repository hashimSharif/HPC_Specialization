#include <stdio.h>
#include <upc.h>
int main (void)
{
  double x,tmp;
  x = 0.1;
  tmp = 1.0/(1.0 + x*x);
  //fprintf(stderr, "%d: x=%g,tmp=%g\n", MYTHREAD, x, tmp);

  if (MYTHREAD == 0) {
    if (tmp > 1.0) {
      printf("FAILED: x = %f, 1.0 / (1.0 + x * x) = %f\n", x, tmp);
    } else {
      printf("SUCCESS\n");
    }
  }
  return 0;
}


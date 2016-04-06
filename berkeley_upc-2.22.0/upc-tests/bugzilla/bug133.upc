#include <stdio.h>

void foo(int a, int b, double c, double d, int e) {
  printf("%i\n",a);
  printf("%i\n",b);
  printf("%f\n",c);
  printf("%f\n",d);
  printf("%i\n",e);
}

int main() {
  double x = 1.4;
  float y = 2.7;
  short z = 10;
  unsigned long long a = 20ULL;
  printf("%i %i %i\n",(int)sizeof(int),(int)sizeof(double),5);
  printf("%f %f %i\n",x,y,7);
  foo(sizeof(int), z, x, y, 2);
  printf("done.\n");
}




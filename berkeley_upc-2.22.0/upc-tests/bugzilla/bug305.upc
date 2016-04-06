#include <stdio.h>
int main() {
  double c = 1.0001;
  for (int i=0,j=100;i<100;i++,j++) {
   c *= i+j;
  }
  printf("%g\n",c);
  int x = 10;
  int y = 0;
  for (int x = 20; x < 30; x++) {
   if (x < 20 || x > 30) printf("ERROR1\n");
   int x = 1;
   if (x != 1) printf("ERROR2\n");
   y += x;
  }
  if (y != 10) printf("ERROR3\n");
  printf("done.\n");
  return 0;
}

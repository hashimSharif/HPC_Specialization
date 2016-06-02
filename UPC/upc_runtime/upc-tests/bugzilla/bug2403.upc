#include <stdio.h>

int main(void) {
  float f = 4E40;
  
  // Translator -opt replaces 'f' w/ 'INFINITY':
  printf("f=%#-20.7g expr='%s'\n", f, "4E40");

  f = 1;

  // I think translator dies in g_fmt in this call (expanding 'f'):
  // This suggests something "bad" happened w/ the INFINITY.
  printf("f=%#-20.7g expr='%s'\n", f, "1");

  return 0;
}

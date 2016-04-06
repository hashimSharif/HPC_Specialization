#include <stdio.h>

/* Magic header to sneak "sizeof(long double)" past the translator */
#include <bug147.h>

int main() {
  long double ld = 12.6;
  printf("sizeof(long double)=%i, expected %d\n",(int)sizeof(ld), sld);

  if (!MYTHREAD) {
    if ((int)sizeof(ld) == sld) {
      printf("PASS\n");
    } else {
      printf("FAIL\n");
    }
  }

  return 0;
}

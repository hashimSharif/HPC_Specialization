#include <upc.h>
#include <stdio.h>

#define CHECK(cond) if (!(cond)) printf("ERROR i=%i at %s:%i\n", i, __FILE__, __LINE__);
int main() {
  int i = -1;
  int i0 = 100;
  int tmp = 200;
  int tmp0 = 300;
  for (int i=0; i < 5; i++) {
    printf("%i\n", i);
  }
  CHECK(i == -1);
  CHECK(i0 == 100);
  CHECK(tmp == 200);
  CHECK(tmp0 == 300);
  printf("done.\n");
  return 0;
}

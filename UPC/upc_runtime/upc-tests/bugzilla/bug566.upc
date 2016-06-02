#include <stdio.h>

#define CHECK(cond) if (!(cond)) printf("ERROR i=%i at %s:%i\n", i, __FILE__, __LINE__);
int main() {
  int i = -1;
  for (int i=0; i < 5; i++) {
    printf("%i\n", i);
  }
  CHECK(i == -1);
  for (int i=0; i < 10; i++) {
    printf("%i\n", i);
  }
  CHECK(i == -1);
  for (i=0; i < 5; i++) {
    printf("%i\n", i);
  }
  CHECK(i == 5);
  printf("done.\n");
  return 0;
}

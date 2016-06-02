#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char *my_fgets() {
  static char a;
  static int x = 0;
  if (x++ < 10) return &a;
  return NULL;
}
int main() {
int cnt=0;
while (my_fgets() != NULL) {
  printf("%i\n",cnt++);
  if (cnt > 20) abort();
}
printf("done.\n");
return 0;
}

#include <upc.h>
#include <stdlib.h> /* For NULL */
struct S1 { shared void *s; size_t a,b; };
struct S2 { shared [] int *s; size_t a,b; };
int main(void) {
  struct S1 s1 = { NULL, 0, 0 };
  struct S2 s2 = { NULL, 0, 0 };
  return 0;
}

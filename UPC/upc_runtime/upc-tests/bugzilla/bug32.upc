#include <upc.h>
#include <stdio.h>

struct foo {
  int y;
  shared int *x;
};

struct bar {
  int * x;
  int y;
};

shared int x;
struct foo y;
int * norm_p;
shared int* p;
shared [2] int * shared sp;
struct foo foo_ar[10];

int main() {
  /* correct values are for ia32 platforms, with pshared_size = shared_size = 8 */
  printf("size of shared struct: %d, should be 16\n", (int)sizeof (struct foo));
  printf("size of struct: %d, should be 8\n",(int) sizeof (struct bar));
  printf("size of shared int: %d, should be 4\n", (int)sizeof (x));
  printf("regular ptr: %d (should be 4), ptr-to-shared: %d (should be 8)\n", (int)sizeof (norm_p), (int)sizeof(p));
  printf("size of shared ptr-to-shared: %d (should be 8)\n", (int)sizeof (sp));
  printf("size of foo array: %d (should be 160) \n", (int)sizeof (foo_ar));
  y.y = 0;
}

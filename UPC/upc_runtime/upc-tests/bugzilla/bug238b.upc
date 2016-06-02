#include <upc.h>

typedef struct {
  int a;
  int b;
} foo;

int foob(void *p) {

  return ((foo*) p)->b;
}

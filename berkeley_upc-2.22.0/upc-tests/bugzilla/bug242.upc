#include <upc.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef USE_SHARED
#   define MYSHARED shared
#else
#   define MYSHARED
#endif

typedef struct foo_rec {
    int    *intloc;
    float  *fltloc;
} foo_t;

static MYSHARED foo_t foo_bar;

int main(int argc, char* argv[])
{
  int * p = NULL;
  foo_bar.intloc = p;
  return 1;
}

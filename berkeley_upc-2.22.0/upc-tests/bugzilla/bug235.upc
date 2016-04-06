#include <upc.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct foo_rec {
    shared  int    *intloc;
    shared  float  *fltloc;
  //    int junk;
} foo_t;

// static shared structure should have affinity
// to thread 0
static shared foo_t foo_bar;

int main(int argc, char* argv[])
{
  shared int * p = NULL;
  foo_bar.intloc = p;
  return 1;
}

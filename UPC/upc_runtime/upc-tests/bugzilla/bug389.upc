#include <upc.h>
#include <stdio.h>
struct foo {
  int i;
  shared [] int *p;
};
struct foo *p;
shared struct foo *sp;
void f() {
  shared [] int *cp;
  shared [] int **ap;
  sp->p = NULL;
  p->p = NULL;
}

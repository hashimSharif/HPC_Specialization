#include <upc.h>

shared struct {
  struct {
    int *p;
    shared int * sptr1;
    struct {
      int *p;
      shared int * sptr3;
    } s;
  } s;
  shared int * sptr2;
} Var;

int main(void)
{
  int * shared [] * p = &(Var.s.p);
  shared int * shared [] * q = &(Var.sptr2);
  shared int * r = Var.s.sptr1;

  shared int * shared [] * s = &(Var.s.sptr1);
  shared int * shared [] * t = &(Var.s.s.sptr3);

  // Something to keep the optimizer from discarding eveything
  // This will NOT actually run (uninitialized)
  // **p removed to avoid unrelated warning (bug 2964)
  return /* **p +*/ **q + *r + **s + **t;
}

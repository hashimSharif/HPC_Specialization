#include <upc.h>

void baz(shared []  int *arg) { ; }

shared struct {
  shared     int * f1; // Default cyclic
  shared [1] int * f2; // Explicit cyclic
} S;

int main(void)
{
  // NO WARNINGS from the following 4 which are all mismatches
  baz(S.f1);
  baz(S.f2);
  shared [] int * t = S.f1;
  shared [] int * u = S.f2;

  return 0;
}

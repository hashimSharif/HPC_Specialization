#include <upc.h>

void foo(shared     int *arg) { ; }
void bar(shared [1] int *arg) { ; }

shared struct {
  shared     int * f1; // Default cyclic
  shared [1] int * f2; // Explicit cyclic
} S;

int main(void)
{
  shared     int * p = S.f1;   // Default <- Default  OK
  shared     int * q = S.f2;   // Default <- Cyclic   WARNING
  shared [1] int * r = S.f1;   // Cyclic  <- Default  WARNING
  shared [1] int * s = S.f2;   // Cyclic  <- Cyclic   OK

  S.f1 = S.f2; // OK

  foo(S.f1);   // Default <- Default  OK
  foo(S.f2);   // Default <- Cyclic   WARNING

  bar(S.f1);   // Cyclic <- Default  WARNING
  bar(S.f2);   // Cyclic <- Cyclic   WARNING DESPITE MATCH

  return 0;
}

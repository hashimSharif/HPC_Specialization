#include <upc.h>

struct S1 { int (*func)(int, int); };
struct S2 { struct S1 s; };

shared struct S2 Array[THREADS];

int main(void)
{
  shared [1] struct S2 *Ptr1 = &Array[MYTHREAD];
  shared [1] struct S2 *Ptr2 = &Array[(MYTHREAD+1)%THREADS];

  shared [] struct S1 *Ptr3 = &Ptr1->s;
  shared [] struct S1 *Ptr4 = &Ptr2->s;

  int Expr1 = (Ptr3->func != Ptr4->func); // OK

  int Expr2 = (Ptr1->s.func != Ptr2->s.func); // Compiler error

  return (Expr1 != Expr2); // Prevent optimizer from discarding Exprs
}


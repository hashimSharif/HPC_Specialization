#include "upc.h"

shared long a;
extern long f();
extern double g();
double g1;

typedef struct A {
  double a, b;
} AA;

shared struct A t;
extern AA totalAA();

int main()
{
  int i,j,k;

  a = f();
  g1 = g();	
  t = totalAA();  
}




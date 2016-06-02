#include <upc_relaxed.h>


typedef struct { double real; double imag; } dcomplex;

  shared dcomplex chk1 = { 1.1, 2.2 };
  dcomplex chk2 = { 3.3, 4.4 };

int main() { 
  dcomplex chk3 = { 5.5, 6.6 };
return 0; }


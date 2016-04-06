#include <upc.h>

/* The Variable Length Array decl in foo() is causing a failure at LINK time */
void foo(int n) {
  double X[n];
}

int main(void) {
  return 0;
}

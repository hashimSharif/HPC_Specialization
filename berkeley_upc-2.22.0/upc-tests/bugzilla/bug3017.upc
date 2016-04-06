#include <upc.h>

int foo(shared    int *p);
int foo(shared[1] int *p) { return 0; }

int bar(shared[1] int *p);
int bar(shared    int *p) { return 0; }

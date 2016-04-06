#include <upc.h>

struct foo {
  shared [] double* p;
};

struct foo bar;


shared void* tmp;

int main () {

 shared [] double* p;

 p = (shared [] double*) upc_alloc(3*4);
 bar.p = (shared [] double*) upc_alloc(3*4);	
 
 tmp = p; /* prevent p from being optimized away */
}

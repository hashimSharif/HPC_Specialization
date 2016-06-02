#include <upc.h>
#include <stddef.h>

shared void *tmp;
int main() {
  shared void *p = upc_all_alloc(THREADS,1);     
  shared void *myp = (MYTHREAD==0?p:NULL);
  tmp = p; /* prevent p from being optimized away */
  return 0;
}

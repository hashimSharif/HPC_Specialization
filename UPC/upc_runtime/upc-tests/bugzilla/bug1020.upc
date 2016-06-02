#include <upc.h>

shared int *sp;
int main() {
int x;
int *pp = &x;
sp = upc_alloc(10);

/* all of the following are type errors by 6.4.2, constraint 1 */
int res1 = (sp < pp); 
//pp = sp;
//sp = pp;
}

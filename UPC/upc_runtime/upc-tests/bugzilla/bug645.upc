#include <stdio.h>
#include <upc.h>

struct point_name {
  double x;
  double y;
  int n;};
struct point_name lala;
void f(struct point_name x) {
  if (x.x != 5.0 || x.y != 6.0 || x.n != 100) 
    printf("ERROR x.x=%f x.y=%f  x.n=%i \n",x.x,x.y,x.n);
}
shared struct point_name * shared p; 
void initialize() {
  p = upc_all_alloc(1, sizeof(struct point_name));
  if (MYTHREAD == 0) { p->x = 5.0; p->y = 6.0; p->n = 100; }
  upc_barrier;
}
int main() {
  initialize();
  f(*p);
  printf("done.\n");
  return 0;
} 

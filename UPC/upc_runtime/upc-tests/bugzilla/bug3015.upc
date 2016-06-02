#include <upc.h>
#include <stdio.h>

struct node {
  shared void *pts;
  int i;
};

shared struct node X;

int main(void) {
  if (!MYTHREAD) {
    shared [] int *p1;
    shared [] int *p2;

#ifdef WORK_AROUND
    p1 = &((&X)->i); // Gives correct result
#else
    shared struct node *p_X = &X;
    p1 = &(p_X->i); // Incorrectly gives offset equal to that of pointer-to-private
#endif
    p2 = &(X.i); // Address is correct
   
    printf("&X=%p p1=%p p2=%p\n", (void *)(&X), (void *)p1, (void *)p2);
    puts ( (p1 == p2) ? "PASS" : "FAIL" );
  }

  return 0;
}

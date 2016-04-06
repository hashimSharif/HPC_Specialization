#include <upc.h>

struct S {
    int    a;
    double b[2];
};

void func(struct S *sp, int i)
{
    struct S s = *sp;

    s.b[i] = sp->b[i]/2.0;
}


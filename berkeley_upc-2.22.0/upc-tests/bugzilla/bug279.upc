#include <upc.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct box_rec {
    int lo;
    int hi;
} box;

typedef struct fab_rec {
    box b;
    double *data;
    shared [] double *sdata;
} fab;

shared [] fab* fab_alloc(int n) {
    shared [] fab *sp;
    fab *p;

    sp = (shared [] fab*)upc_alloc(sizeof(fab));
    assert( sp != NULL );
    p = (fab*) sp;

    p->sdata = (shared [] double*)upc_alloc(n*sizeof(double));

    p->b.lo = 0;
    p->b.hi = n-1;
    p->data = (double*)p->sdata;

    return sp;
}

int main(int argc, char* argv[])
{
    shared [] fab *bar = fab_alloc(10);

    if (bar->b.hi != 9) {
	printf("Oops, wrong value\n");
	return -1;
    }

    return 0;
}

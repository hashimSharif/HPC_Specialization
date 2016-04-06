#include <assert.h>
#include <stdio.h>

typedef struct foo {
void *p;
} foo_t;

int main() {
double arr[10];
double *d = arr;
void *v = d;
foo_t f;
f.p = d;
int i = 4;
int j = 4;
assert(((double*)v) == d);
assert(&(((double*)v)[i]) == &(d[j]));
assert(&(((double*)f.p)[i]) == &(d[j]));
printf("done.\n");
return 0;
}

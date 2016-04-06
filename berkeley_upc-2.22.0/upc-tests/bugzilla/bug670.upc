#include <upc.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct foo_rec {
    int len;
    float *data;
} foo_t;

int foo_func(const foo_t *cf)
{
    foo_t *f;

    /* cast const ptr to non-const */
    f = (foo_t*)cf;
    f->len += 1;
    f->len -= 1;

    return f->len;
}

int main(int argc, char* argv[])
{
    foo_t f;
    int out;
    int err = 0;

    f.len = 100;
    f.data = (float*)malloc(f.len * sizeof(float));

    out = foo_func(&f);

    if (out != 100) {
	printf("FOO BAD  on Thread [%d] out = %d\n",MYTHREAD,out);
	fflush(stdout);
	err = 1;
    } else {
	printf("FOO GOOD on Thread [%d]\n",MYTHREAD);
	fflush(stdout);
    }
    upc_global_exit(err);
    return 1;
}

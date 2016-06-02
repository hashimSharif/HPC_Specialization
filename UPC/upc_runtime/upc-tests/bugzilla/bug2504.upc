#include <upc.h>
#include <stdio.h>

typedef struct {
	int a[1][1];
} block;

shared [1] block A[THREADS];

int main(int argc,char **argv)
{
    int val;

    A[MYTHREAD].a[0][0] = MYTHREAD;
    val = A[MYTHREAD].a[0][0] * A[MYTHREAD].a[0][0];

    if (val != MYTHREAD*MYTHREAD) {
        printf("FAILURE on thread %i\n", MYTHREAD);
    }

    upc_barrier;
    if (!MYTHREAD) printf("done.\n");

    return 0;
}

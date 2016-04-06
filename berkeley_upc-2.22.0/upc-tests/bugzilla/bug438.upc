#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <upc.h>

inline long trouble(shared long *a, shared long *b)
{
    return *a + *b;
}

shared long longs[THREADS];

int main(int argc, char **argv)
{
    longs[MYTHREAD] = MYTHREAD + 1;

    upc_barrier;

    long result = trouble(&longs[0], &longs[MYTHREAD]);

    if (result != MYTHREAD + 2) {
	printf("FAILURE on thread %d: result=%ld instead of %ld\n",
		(int)MYTHREAD, result, (long)(MYTHREAD+2));
	exit(-1);
    }

    printf("SUCCESS\n");

    return 0;
}



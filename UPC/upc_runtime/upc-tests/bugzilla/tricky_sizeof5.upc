#include <stdio.h>
#include <assert.h>

shared int A[10][10*THREADS];

int main() {
assert(sizeof(A) == sizeof(int)*100*THREADS);
assert(upc_localsizeof(A) == sizeof(int)*100);
printf("done.\n");
return 0;
}

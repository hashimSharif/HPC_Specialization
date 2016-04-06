#include <assert.h>
#include <stdio.h>

int x;
shared [10] int *pts;
shared [10] int * shared [20] spts;
shared [30] int arr[10*THREADS];

int main() {
#if !defined(TEST)
#error must define TEST to be 1..
#elif TEST == 1
/* compile error - upc_*sizeof may not be applied to non-shared type */
size_t sz1a = upc_localsizeof(int); 
size_t sz1b = upc_blocksizeof(int); 
size_t sz1c = upc_elemsizeof(int); 
#elif TEST == 2
/* compile error - upc_*sizeof may not be applied to non-shared object */
size_t sz2a = upc_localsizeof(x); 
size_t sz2b = upc_blocksizeof(x); 
size_t sz3c = upc_elemsizeof(x); 
#elif TEST == 3
/* compile error - upc_*sizeof may not be applied to non-shared type */
//size_t sz3a = upc_localsizeof(shared [10] int *); 
size_t sz3b = upc_blocksizeof(shared [10] int *); 
//size_t sz3c = upc_elemsizeof(shared [10] int *); 
#elif TEST == 4
/* compile error - upc_*sizeof may not be applied to non-shared object */
/* *pts is a shared object, but pts is not */
//size_t sz4a = upc_localsizeof(pts); 
size_t sz4b = upc_blocksizeof(pts); 
//size_t sz4c = upc_elemsizeof(pts); 
#elif TEST == 5
/* should compile and work */
assert(upc_blocksizeof(*pts) == 10);
assert(upc_blocksizeof(*spts) == 10);
assert(upc_blocksizeof(spts) == 20);
assert(upc_blocksizeof(arr) == 30);
assert(upc_blocksizeof(*&arr) == 30);
assert(upc_blocksizeof(arr[0]) == 30);
assert(upc_blocksizeof(*&(arr[0])) == 30);

assert(upc_blocksizeof(shared [10] int) == 10);
assert(upc_blocksizeof(shared [10] int * shared [20]) == 20);
assert(upc_blocksizeof(shared [10] int[100*THREADS]) == 10);
assert(upc_blocksizeof(shared [10] int[100][200*THREADS]) == 10);
printf("done.\n");
#endif
}


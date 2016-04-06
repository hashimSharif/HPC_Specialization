#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct foo_t {
int x;
int y;
int arr[10];
} foo_t;

int main() {
struct foo_t f2 = { 3, 4 };
foo_t f = { .x = 1, .y = 2, .arr = { [2] = 4, [5] = 16 } };
foo_t A[10] = { [2].arr[6] = 12, [5].arr[7] = 56 };
assert(f.x == 1); f.x = 0;
assert(f.y == 2); f.y = 0;
assert(f.arr[2] == 4); f.arr[2] = 0;
assert(f.arr[5] == 16); f.arr[5] = 0;
assert(A[2].arr[6] == 12); A[2].arr[6] = 0;
assert(A[5].arr[7] == 56); A[5].arr[7] = 0;
foo_t *f_c = calloc(1,sizeof(f));
assert(!memcmp(&f, f_c, sizeof(f)));
foo_t *A_c = calloc(1,sizeof(A));
assert(!memcmp(&A, A_c, sizeof(A)));
printf("done.\n");
return 0;
}

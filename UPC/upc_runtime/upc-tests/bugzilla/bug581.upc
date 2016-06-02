#include <upc_relaxed.h>
#include <stdio.h>

shared int grid[3*THREADS];

#define FAIL_UNLESS(expr)                                      \
	if (!(expr)) {                                         \
	    fprintf(stderr, "FAILED: '" #expr "' not true\n"); \
	    errs = 1;                                          \
	}

int main(void)
{
    int p_grid[3];
    int errs = 0;

    if (MYTHREAD == 0) {
	grid[0] = 1;
	grid[1] = 10;
	grid[2] = 100;
    }

    upc_barrier;

    p_grid[0] = grid[0];
    p_grid[1] = grid[1];
    p_grid[2] = grid[2];

    upc_barrier;
    FAIL_UNLESS(p_grid[0] == 1);
    FAIL_UNLESS(p_grid[1] == 10);
    FAIL_UNLESS(p_grid[2] == 100);

    printf("TH%02d: %3d %3d %3d\n", MYTHREAD, p_grid[0], p_grid[1], p_grid[2]);

    if (errs) {
	return -1;
    } else {
	printf("SUCCESS\n");
    }
    return 0;
}


#include <upc_relaxed.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include "sum.h"
#include "libsq.h"

    
shared int nums[THREADS];
shared int total;
  
int main(int argc, char **argv)
{
    int i, t, s;

    if (MYTHREAD == 0) {
	for (i = 0; i < THREADS; i++) 
	    nums[i] = 2;
    }

    upc_barrier;

    for (t = 0; t < THREADS; t++) {
	if (MYTHREAD == t) {
	    for (i = 0; i < THREADS; i++) 
		total = sum(nums[i], total);
	    printf("thread %d added up to %d\n", MYTHREAD, total);
	    fflush(stdout);
	}
	upc_barrier;
    }

    /* throw in a square root, just to test linking -lm */
    if ( (s = sqrt(4)) != 2) {
	fprintf(stderr, "sqrt(4) == %d!\n", s);
    }
    if ( (s = sq(4)) != 2) {
	fprintf(stderr, "sqrt(4) == %d!\n", s);
    }

    if (MYTHREAD == 0) {
	if (total == THREADS*THREADS*2) {
	    printf("Test passed\n");
	    printf("done.\n");
	} else {
	    fprintf(stderr, "ERROR: 'sum' should have been %d, was %d\n",
		    THREADS*THREADS*2, total);
	    exit(-1);
	}
    }

  return 0;
}


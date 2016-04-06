/*
 * Test to check that user calls to exit() do not result in 
 * immediate exit, but are instead intercepted and do final barrier, so other
 * threads can still access their shared memory until global program exit.
 *
 * TODO:  test exit calls from within externally compiled C objects.
 */
#include <upc_relaxed.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

shared int nums[THREADS];
shared int total;
  
int main(int argc, char **argv)
{
    if (THREADS < 2) {
	fprintf(stderr, 
		"ERROR %s must be run with at least 2 UPC threads\n",
		argv[0]);
	fflush(stderr);
	sleep(2);
	upc_global_exit(-1);
    }

    if (MYTHREAD != 1) {
	exit(0);
    } else {
	int i;

	for (i = 0; i < THREADS; i++) {
	    nums[i] = 3;
	}
	/* make sure other threads have called exit() */
	sleep(2);  

	for (i = 0; i < THREADS; i++) {
	    total += nums[i];
	}
	if (total == THREADS*3) {
	    printf("test passed\n");
	    printf("done.\n");
	    fflush(stdout);
	    sleep(2);
	    exit(0);
	} else {
	    fprintf(stderr, "ERROR total was %d, should have been %d!\n",
		    total, THREADS*3);
	    fflush(stderr);
	    sleep(2);
	    exit(-1);
	}
    }

    return 0;
}


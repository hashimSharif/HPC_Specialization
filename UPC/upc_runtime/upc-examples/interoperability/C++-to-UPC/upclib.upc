#include <stdio.h>
#include "upclib.h"
#include "upc.h"

shared int copies[THREADS];


int my_UPC_get_thread(void)
{
    int i;

    /* Verify that UPC works by reading each thread's val from shared array */
    copies[MYTHREAD] = MYTHREAD;

    upc_barrier;

    for (i = 0; i < THREADS; i++) {
	if (copies[i] != i) {
	    fprintf(stderr, "ERROR: T%d: copies[%d]=%d, not %d\n",
		    MYTHREAD, i, copies[i], i);
	    upc_global_exit(-1);
	}
    }
    printf("T%d: saw all thread values OK\n", MYTHREAD);
    fflush(stdout);

    upc_barrier;
	
    return copies[MYTHREAD];
}



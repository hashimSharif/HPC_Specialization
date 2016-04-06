#include <unistd.h>
#include <stdio.h>

#include <upc.h>
#include <upc_collective.h>


/* C-interface functions */

int my_upc_check_threadsum(int *mysrc, int *dst, int correct_sum)
{
    char buf[BUPC_DUMP_MIN_LENGTH];
    int i;
    int retval = 0;

    /* 
     * use UPC collective to sum thread IDs to variable on thread 0
     */

    /* Cast local pointers back to the initial shared pointers 
     * (in this case both pointers point to shared memory on thread 0) */
    shared int *src  = (shared int *) bupc_local_to_shared(mysrc, 0, 0);
    shared int *dest = (shared int *) bupc_local_to_shared(dst, 0, 0);

    upc_all_reduceI(dest, src, UPC_ADD, THREADS, 1, NULL, 0); 

    if (MYTHREAD == 0) {
	void * check = (void *)dest;
	if (dst != check) {
	    fprintf(stderr, "ERROR: dst (%p) != (void *)dest (%p)\n", dst, 
		    (void *)dest);
	}
	if (*(int *)dst != correct_sum) {
	    fprintf(stderr, "ERROR: *dst (%d) != correct_sum of thread IDs (%d)\n", 
		    *(int *)dst, correct_sum);
	}
	printf("T0: gathered thread sum (%d) OK\n", *(int *)dst);
	retval = *dst;
    }

    upc_barrier;

    return retval;
}



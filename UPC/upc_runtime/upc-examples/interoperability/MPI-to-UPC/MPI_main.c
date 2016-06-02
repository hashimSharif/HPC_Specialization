#include <stdio.h>
#include <stdlib.h>

#include <mpi.h>
#include <bupc_extern.h>

#include "UPC_functions.h"

int rest_of_main(int argc, char **argv);

/* Not all UPC threads may be running yet */
int main(int argc, char **argv)
{
    bupc_init_reentrant(&argc, &argv, &rest_of_main);

    return 0;
}

/* Each UPC thread runs this */
int rest_of_main(int argc, char **argv)
{
    int err, MPI_isinit;
    int *mysrc, *dst;
    int threads, mythread;
    int i, sum, correct_sum = 0;
    int rank, size;

    /* Verify that MPI has been set up */
    err = MPI_Initialized(&MPI_isinit);
    if (err != MPI_SUCCESS || !MPI_isinit) {
	fprintf(stderr, "FAILED: UPC runtime did not initialize MPI\n");
	exit(-1);
    }
    threads = bupc_extern_threads();
    mythread = bupc_extern_mythread();

    err = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (err != MPI_SUCCESS) {
	fprintf(stderr, "FAILED: MPI_Comm_rank()\n");
	exit(-1);
    }
    err = MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (err != MPI_SUCCESS) {
	fprintf(stderr, "FAILED: MPI_Comm_size()\n");
	exit(-1);
    }
    printf("This is UPC thread %d with MPI_Comm_rank=%d (out of %d)\n", 
	    mythread, rank, size);

    /* Have each UPC thread write its thread id into its portion of global
     * allocation, then do collective to sum ids into 'dst' on thread 0 */
    mysrc = (int *) bupc_extern_all_alloc(threads, sizeof(int));
    /* Note that 'dst' is safe to dereference only on thread 0, since that is
     * the only thread that this calls allocates memory on */
    dst = (int *) bupc_extern_all_alloc(1, sizeof(int));

    *mysrc = mythread;

    /* UPC code: returns sum of thread counts to thread 0 */
    for (i = 0; i < threads; i++)
	correct_sum += i;
    sum = my_upc_check_threadsum(mysrc, dst, correct_sum);
    printf("T%d: sum returned was %d\n", mythread, sum);

    /* MUST do a UPC barrier before switching from UPC to MPI code */
    bupc_extern_barrier(1);

    /* Now do some MPI code */
    /* MPI_Barrier(MPI_COMM_WORLD); */

    MPI_Bcast(&sum, 1, MPI_INT, 0, MPI_COMM_WORLD); 
    if (sum == correct_sum) {
	printf("SUCCESS: thread %d\n", mythread);
    } else {
	fprintf(stderr, "ERROR: T%d: sum gathered/bcast was %d, not %d!\n", 
		mythread, sum, correct_sum);
	return -1;
    }
    return 0;
}


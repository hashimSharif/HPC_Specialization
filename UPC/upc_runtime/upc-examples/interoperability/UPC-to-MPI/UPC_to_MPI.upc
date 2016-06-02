#include <stdio.h>

#include <mpi.h>
#include <upc.h>

shared int *dest;


int main(int argc, char **argv)
{
#if 0
    int MPIisinit;
        
    /* only init MPI if it's not already initialized (by GASNet, for example) */
    if (MPI_Initialized(&MPIisinit) != MPI_SUCCESS) {
	fprintf(stderr, "Error calling MPI_Initialized()\n");
	abort();
    }
    if (!MPIisinit) 
	MPI_Init(&argc, &argv);
#endif

    int err, MPI_isinit;

    /* Call MPI function to see that MPI has been set up */
    err = MPI_Initialized(&MPI_isinit);
    if (err != MPI_SUCCESS || !MPI_isinit) {
	fprintf(stderr, "FAILED: MPI not initialized\n");
	exit(-1);
    }
    /* Do some UPC code */

    /* Before changing to use MPI, do a UPC barrier */
    upc_barrier;

    /* Do some MPI stuff */

#if 0
    /* Call  MPI_Finalize before exiting */
    /* only finalize MPI if we started it */
    if (!MPIisinit)  
	MPI_Finalize();  
#endif

    printf("SUCCESS: called MPI function from UPC code\n");

    return 0;
}



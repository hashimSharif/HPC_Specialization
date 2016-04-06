
#include <upc.h>
#include <stdio.h>

#define DTYPE float
#define SIZE 502400

shared [] DTYPE * shared src;
shared [] DTYPE * shared dst[THREADS];
shared int err[THREADS];

int main (void)
{
	int i, j, error=0;
 	err[MYTHREAD] = 0;
	
	if (MYTHREAD == 0) { /* Allocate and initialize source array */
		src = upc_alloc(SIZE * sizeof(DTYPE));
		upc_memset(src, 0, SIZE * sizeof(DTYPE));
	}
	
	upc_barrier;

	/* Each thread allocates shared memory with affinity to it, and then
	   initializes the allocated memory */
	dst[MYTHREAD] = upc_alloc(SIZE * sizeof(DTYPE));
	upc_memset(dst[MYTHREAD], MYTHREAD+1, SIZE * sizeof(DTYPE));

	/* Each thread copies the content of src to its own array dst[MYTHREAD] */
	upc_memcpy(dst[MYTHREAD], src, SIZE * sizeof(DTYPE));

	for (i = 0; i < SIZE; i++)
		if (dst[MYTHREAD][i] != (DTYPE)(0)) {
			err[MYTHREAD] = 1;
			break;
		}
	
	upc_barrier;
 printf("done.\n");

	return (error);
}


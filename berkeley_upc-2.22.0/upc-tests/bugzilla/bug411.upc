#include <upc.h>

#include <stdlib.h>
#include <stdio.h>

static shared [] int    *int_vect;
static shared [] float  *flt_vect;

typedef struct foo_rec {
    int junk;
    shared [] int    *intloc;
    shared [] float  *fltloc;
} reduce_init_t;

static shared reduce_init_t reduce_init_rec;

void init_reduce(void)
{
    reduce_init_t myrec;
    if (MYTHREAD == 0) {
	// Allocate vectors of length THREADS+1
	// Indicies 0 .. THREADS-1 will hold posted values
	// Thread 0 computes global reduced value and
	// stores in last element (index THREADS).
	myrec.intloc = upc_alloc((THREADS+1)*sizeof(int));
	myrec.fltloc = upc_alloc((THREADS+1)*sizeof(float));
	// now post this to shared memory
	reduce_init_rec = myrec;
    }
    // barrier to insure all have gotten here
    upc_barrier;

    // each thread reads the structure
    myrec = reduce_init_rec;

    // make sure read is complete
    upc_fence;

    // save to local static pointers for later use
    int_vect = myrec.intloc;
    flt_vect = myrec.fltloc;
}

int int_reduce(int *vect, int len)
{
    int local = vect[0];
    int i;

    // local reduction
    for (i = 1; i < len; i++)
	local += vect[i];

    /* copy value to global array on thread 0 */
    int_vect[MYTHREAD] = local;

flt_vect[MYTHREAD] = 6.9;

    /* enter barrier to wait for all threads to post value */
    upc_barrier;

    /* Now thread 0 performs the global reduction */
    if (MYTHREAD == 0) {
        int *lvect = (int*)int_vect;
	local = lvect[0];
	for (i = 1; i < THREADS; i++)
	    local += lvect[i];
	lvect[THREADS] = local;
    }

    /* barrier to insure all threads see result */
    upc_barrier;

    /* return collective value to all callers */
    return int_vect[THREADS];
}
#define BUFSZ 10;

int main(int argc, char* argv[])
{
    int myval = 10*(1+MYTHREAD);
    int reduction;
    int answer, i;
    int err = 0;

    printf("Thread %d starting with value %d\n",MYTHREAD,myval);
    printf("Thread %d affinity of reduce_init_rec is %d\n",
	   MYTHREAD,(int)upc_threadof(&reduce_init_rec));
    fflush(stdout);

    upc_barrier;

    init_reduce();
    printf("Thread %d Finished init reduce\n",MYTHREAD);
    fflush(stdout);

    upc_barrier;
    
    answer = 0;
    for (i = 0; i < THREADS; i++) {
	answer += 10*(1+i);
    }
    reduction = int_reduce(&myval,1);
    if (reduction == answer) {
	printf("Success: answer on Thread %d is %d\n",MYTHREAD,answer);
    } else {
	err = 1;
	printf("Failure: Thread %d got %d, expected %d\n",
	       MYTHREAD,reduction,answer);
    }
    fflush(stdout);
    
    return(err);
}

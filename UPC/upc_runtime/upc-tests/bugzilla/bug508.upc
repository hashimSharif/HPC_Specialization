#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <upc.h>

typedef struct AmrLevelRec {
    int           level;
} AmrLevel;

// this should have affinity to thread 0
#define numlevel 4
static shared [] AmrLevel G_amr[numlevel];

int main(int argc, char* argv[])
{
    int G_level;
    int i;
    int err = 0;

    printf("I am thread %d of %d\n",MYTHREAD,THREADS);
    for (i = 0; i < numlevel; i++) {
	printf("Thread of G_amr[%d] = %d\n",i,(int)upc_threadof(&G_amr[i]));
    }

    if (MYTHREAD == 0) {

	for (i = 0; i < numlevel; i++) {
	    printf("Setting i = %d: lev = %d\n",i,i);
	    G_amr[i].level = i;
	}
    }

    upc_barrier;

    for (i = 0; i < numlevel; i++) {
	int lev;
	lev = G_amr[i].level;
	printf("For i = %d: Got lev = %d, should be %d\n",i,lev,i);
	if (lev != i) err=1;
    }
    upc_barrier;
    if (err > 0) {
	printf("FAILED\n");
    } else {
	printf("SUCCESS\n");
    }
    upc_global_exit(0);
}

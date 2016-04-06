#include <stdio.h>
#include <upc.h>
#include <assert.h>
#define MAXP 128
#define NUME 5

typedef struct Node_rec {
    double x[3];
} Node;

shared [] Node *nodesSH[MAXP];
Node *nodes;
shared [] Node *shared nodesTMP[THREADS];

int main(void){

    int ip,i;
    assert(MAXP >= THREADS);

    nodesSH[MYTHREAD] = (shared [] Node *) upc_alloc(NUME * sizeof(Node));

    nodes = (Node *) nodesSH[MYTHREAD];

    upc_barrier;
    nodesTMP[MYTHREAD] = nodesSH[MYTHREAD];
    upc_barrier;
    for (ip = 0; ip < THREADS; ip++)
	if (ip != MYTHREAD)
	    nodesSH[ip] = nodesTMP[ip];
    for (i = 0; i < NUME; i++)
	nodes[i].x[0] = -(10000.0+10+i);
    upc_barrier;
    if (MYTHREAD == 0){
	for (ip = 0; ip < THREADS; ip++)
	    for (i = 0; i < NUME; i++){
		nodesSH[ip][i].x[0] = (ip*1000.0)+10+i;
	    }
    }
    upc_barrier;
    for (ip = 0; ip < THREADS; ip++){
	upc_barrier;
	if ( ip == MYTHREAD)
	    for (i = 0; i < NUME; i++)
		printf("Thread %d has nodes[%d].x[0] equal to %4.3f\n",
		       MYTHREAD,i,nodes[i].x[0]);
    }
    upc_barrier;
    for (i = 0; i < NUME; i++) assert(nodes[i].x[0] == (MYTHREAD*1000.0)+10+i);
    upc_barrier;
    upc_free(nodesSH[MYTHREAD]);
    printf("done.\n");
    upc_global_exit(0);
}

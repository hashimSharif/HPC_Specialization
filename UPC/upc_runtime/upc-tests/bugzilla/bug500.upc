#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <upc.h>

#define SPACEDIM 2

typedef double Real;

typedef struct GridRec {
    int    id;
    int    lo[SPACEDIM];
    int    hi[SPACEDIM];
    shared [] Real *data;   /* data at new time level */
} Grid;

void printGrid(shared [] Grid* g)
{
    printf("Grid %d: [%2d,%2d] [%2d,%2d] gthread %d gaddr %lu dthread %d daddr %lu\n",
	   g->id,g->lo[0],g->hi[0],g->lo[1],g->hi[1],
	   (int)upc_threadof(g),(unsigned long)upc_addrfield(g),
	   (int)upc_threadof(g->data),(unsigned long)upc_addrfield(g->data));
}

// set the values directly through the shared pointer
void setGridGlobal(shared [] Grid *gg,
		   int id, int ilo, int ihi, int jlo, int jhi)
{
    int numcell = (ihi - ilo + 1)*(jhi - jlo + 1);
    
    gg->id = id;
    gg->lo[0] = ilo;
    gg->hi[0] = ihi;
    gg->lo[1] = jlo;
    gg->hi[1] = jhi;
    gg->data = (shared [] Real*)upc_alloc(numcell*sizeof(Real));
}

// set the values by first casting the shared ptr to a local
void setGridLocal(shared [] Grid *gg,
		  int id, int ilo, int ihi, int jlo, int jhi)
{
    int numcell = (ihi - ilo + 1)*(jhi - jlo + 1);
    Grid *g;
    
    assert(upc_threadof(gg) == MYTHREAD);
    g = (Grid*)gg;
    g->id = id;
    g->lo[0] = ilo;
    g->hi[0] = ihi;
    g->lo[1] = jlo;
    g->hi[1] = jhi;
    g->data = (shared [] Real*)upc_alloc(numcell*sizeof(Real));
}

// did the proper values get set?
int checkFld(shared [] Grid *gg,
	      int id, int ilo, int ihi, int jlo, int jhi)
{
    if (gg->id != id) return 1;
    if (gg->lo[0] != ilo) return 2;
    if (gg->lo[1] != jlo) return 3;
    if (gg->hi[0] != ihi) return 4;
    if (gg->hi[1] != jhi) return 5;
    return 0;
}

// this should have affinity to thread 0
static shared [] Grid G_grid1;
static shared [] Grid G_grid2;

int main(int argc, char* argv[])
{
    int err1 = 0;
    int err2 = 0;

    printf("I am thread %d of %d\n",MYTHREAD,THREADS);
    printf("Thread of G_grid1 = %d\n",(int)upc_threadof(&G_grid1));
    printf("Thread of G_grid2 = %d\n",(int)upc_threadof(&G_grid2));

    if (MYTHREAD == 0) {
	setGridGlobal (&G_grid1, 1, 8, 25, -3, 7);
	printGrid(&G_grid1);
	setGridLocal  (&G_grid2, 2, 8, 25, -3, 7);
	printGrid(&G_grid2);
    }

    upc_barrier;
    err1 = checkFld(&G_grid1, 1, 8, 25, -3, 7);
    if (err1 != 0) {
	printf("FAILED on Thread %d on grid1 with err = %d\n",MYTHREAD,err1);
    } 
    err2 = checkFld(&G_grid2, 2, 8, 25, -3, 7);
    if (err2 != 0) {
	printf("FAILED on Thread %d on grid2 with err = %d\n",MYTHREAD,err2);
    }
    if (err1 + err2 == 0) {
	printf("SUCCESS on Thread %d\n",MYTHREAD);
    }
    upc_barrier;
    upc_global_exit(0);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

typedef struct AmrLevelRec {
    int           level;
    int           numGrid;
    shared [] Grid *grids;
} AmrLevel;

void printGrid(shared [] Grid* g)
{
    printf("Grid %d: [%2d,%2d] [%2d,%2d] gthread %d gaddr %lu dthread %d daddr %lu\n",
	   g->id,g->lo[0],g->hi[0],g->lo[1],g->hi[1],
	   (int)upc_threadof(g),(unsigned long)upc_addrfield(g),
	   (int)upc_threadof(g->data),(unsigned long)upc_addrfield(g->data));
}

void printAMR(const char *str, shared [] AmrLevel *a)
{
    int i;
    printf("%s level %d numGrid %d\n",str,a->level,a->numGrid);
    for (i = 0; i < a->numGrid; i++) {
	printGrid(&a->grids[i]);
    }
    printf("\n");
}

void setGrid(shared [] Grid *gg,
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

// this should have affinity to thread 0
static shared [] AmrLevel G_amr[3];

int main(int argc, char* argv[])
{
    int num_grid = 4;
    int G_level;
    int G_ng;
    AmrLevel L_amr;

    printf("I am thread %d of %d\n",MYTHREAD,THREADS);
    printf("Thread of G_amr = %d\n",(int)upc_threadof(&G_amr[0]));

    if (MYTHREAD == 0) {
	shared [] AmrLevel *al = &G_amr[0];

	G_amr[0].level = 0;
	G_amr[0].numGrid = num_grid;
	G_amr[0].grids = (shared [] Grid*)upc_alloc(num_grid*sizeof(Grid));

        int one = 1, zero = 0;

        int translator_sz1 = sizeof(Grid);

        char *tp_one = (char*)&(G_amr[0].grids[one]);
        char *tp_zero = (char*)&(G_amr[0].grids[zero]);
        int translator_sz2 = tp_one - tp_zero;

        int translator_sz3 = (char*)&(G_amr[0].grids[one]) - (char*)&(G_amr[0].grids[zero]);

        Grid *tmpg = (Grid *)G_amr[0].grids;
        char *p_one = (char*)&(tmpg[one]);
        char *p_zero = (char*)&(tmpg[zero]);
        int translator_sz4 = p_one - p_zero;

        printf("translator_sz1 sizeof(Grid)=%i\n", translator_sz1);
        printf("translator_sz2 sizeof(Grid)=%i\n", translator_sz2);
        printf("translator_sz3 sizeof(Grid)=%i\n", translator_sz3);
        printf("translator_sz4 sizeof(Grid)=%i\n", translator_sz4);
        assert(translator_sz1 == translator_sz2);
        assert(translator_sz1 == translator_sz3);
        assert(translator_sz1 == translator_sz4);

#if 1
	// ERROR: this does not work but should
	// &G_amr[N].grids[M] should give the addr of G_amr[N].grids[M]
	setGrid(&G_amr[0].grids[0],0, 0, 9, 0, 9);
	setGrid(&G_amr[0].grids[1],1,10,19, 0, 9);
	setGrid(&G_amr[0].grids[2],2, 0, 9,10,19);
	setGrid(&G_amr[0].grids[3],3,10,19,10,19);
#else
	// this does work
	setGrid(&al->grids[0],0, 0, 9, 0, 9);
	setGrid(&al->grids[1],1,10,19, 0, 9);
	setGrid(&al->grids[2],2, 0, 9,10,19);
	setGrid(&al->grids[3],3,10,19,10,19);
#endif
    }

    upc_barrier;

    printAMR("Global AMR ",&G_amr[0]);

    // if we made it here, probably success
    printf("SUCCESS\n");

    upc_barrier;

    upc_global_exit(0);
}

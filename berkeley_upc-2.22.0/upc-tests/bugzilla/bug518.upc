#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <upc.h>

#define SPACEDIM 2

typedef double Real;

typedef struct {
    int v[SPACEDIM];
} IntVect;

typedef unsigned int IndexType;

typedef struct Box_Rec {
    IntVect   lo;       // lower left-hand corner
    IntVect   hi;       // upper right-hand corner
    int       len[SPACEDIM];   // length in each index dir
    IndexType type;
    struct Box_Rec *next, *prev;  // Boxes are often in linked lists.
} Box;

typedef struct {
    int       thread;          /* which thread do I have affinity to */
    Box       box;             /* loction in index space */
    Real      time, oldtime;   /* time levels */
    shared [] Real *old;    /* data at old time level */
    shared [] Real *new;    /* data at new time level */
    int       level;           /* what level do I live at */
    int       id;           
} Grid;

int check_global(int ix, shared [] Grid* g)
{
    printf("Global Grid %d, id = %d thread = %d addr = %lu\n",ix,g->id,
	   (int)upc_threadof(g),(unsigned long)upc_addrfield(g));
    if (ix == g->id) {
	return 0;
    } else {
	return ix+1;
    }
}

int check_local(int ix, Grid* g)
{
    printf("Local  Grid %d, id = %d, addr = 0x%p\n",ix,g->id,(void*)g);
    if (ix == g->id) {
	return 0;
    } else {
	return ix+1;
    }
}

int main(int argc, char* argv[])
{
    int numgrid = 8;
    int i;
    shared [] Grid *grids;
    Grid *mygrids;

    grids = (shared [] Grid*)upc_alloc(numgrid*sizeof(Grid));
    mygrids = (Grid*)malloc(numgrid*sizeof(Grid));

    for (i = 0; i < numgrid; i++) {
	grids[i].id = i;
	mygrids[i].id = i;
    }

    if (MYTHREAD == 0) assert(upc_threadof(grids) == 0);
    
    if (MYTHREAD == 0) {
	int g_err = 0;
	int l_err = 0;
	Grid *local_grids = (Grid*) grids;

	for (i = 0; i < numgrid; i++) {
	    int a, b, g;
	    g = check_global(i, &grids[i]);
	    a = check_local(i, &local_grids[i]);
	    b = check_local(i, &mygrids[i]);

	    g_err += g;
	    l_err += (a+b);
	}
	

	if (g_err > 0) {
	    printf("FAILURE in global access: %d\n",g_err);
	}
	if (l_err > 0) {
	    printf("FAILURE in local access: %d\n",l_err);
	}
	if (g_err + l_err == 0) {
	    printf("SUCCESS\n");
	}
    }
    return 0;
}
	    

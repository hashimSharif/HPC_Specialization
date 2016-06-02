#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <upc.h>

#define SPACEDIM 2

typedef double Real;

typedef struct IntVect_Rec {
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

typedef struct Grid_Rec {
    int       thread;          /* which thread do I have affinity to */
    Box       box;             /* loction in index space */
    Real      time, oldtime;   /* time levels */
    shared [] Real *old;    /* data at old time level */
    shared [] Real *new;    /* data at new time level */
    int       level;           /* what level do I live at */
    int       id;           
} Grid;

shared [] Real* data = NULL;
const int mylevel = 5;
const Real eps = 1.0e-6;
const unsigned int BTYPE = 100;

#define ABS(x) ((x) >= 0.0 ? (x) : -(x))

void local_grid_init(Grid *g, int id, Real time)
{
    g->id = id;
    g->thread = MYTHREAD;
    g->box.type = BTYPE + id;
    g->time = time;
    g->new = data;
    g->oldtime = 1.0;
    g->old = NULL;
    g->level = mylevel;
} 

void shared_grid_init(shared [] Grid *g, int id, Real time)
{
    Grid *lg = (Grid*)g;
    local_grid_init(lg,id,time);
} 

int check_grid(int id, Real time, Grid* g)
{
    int err = 0;
    Real diff;
    if (g->id != id) {
	printf("Thread %d: incorrect id = %d, should be %d\n",
	       (int)MYTHREAD,g->id,id);
	err = 1;
    }
    if (g->thread != MYTHREAD) {
	printf("Thread %d: incorrect thread %d\n",
	       (int)MYTHREAD,g->thread);
	err = 2;
    }
    if (g->box.type != BTYPE+id) {
	printf("Thread %d: incorrect boxtype %d should be %d\n",
	       (int)MYTHREAD,g->box.type,BTYPE+id);
	err = 3;
    }
    if (g->level != mylevel) {
	printf("Thread %d: incorrect level %d should be %d\n",
	       (int)MYTHREAD,g->level,mylevel);
	err = 4;
    }
    if (g->old != NULL) {
	printf("Thread %d: incorrect old should be NULL\n",
	       (int)MYTHREAD);
	err = 5;
    }
    if (g->new != data) {
	printf("Thread %d: incorrect new\n",
	       (int)MYTHREAD);
	err = 6;
    }
    diff = ABS(g->time - time);
    if (diff > eps) {
	printf("Thread %d: incorrect time %8.4f should be %8.4f\n",
	       (int)MYTHREAD,g->time,time);
	err = 7;
    }

    diff = ABS(g->oldtime - 1.0);
    if (diff > eps) {
	printf("Thread %d: incorrect oldtime %8.4f should be %8.4f\n",
	       (int)MYTHREAD,g->oldtime,1.0);
	err = 8;
    }
    return err;
}

int check_shared(int id, Real time, shared [] Grid* g, const char* str)
{
    int err = 0;
    printf("Shared Grid %s, id = %d thread = %d addr = %lu\n",str,id,
	   (int)upc_threadof(g),(unsigned long)upc_addrfield(g));
    err = check_grid(id, time, (Grid*)g);
    if (err > 0) {
	printf("FAILURE on thread %d for shared %s\n",(int)MYTHREAD,str);
    }
    return err;
}


int check_local(int id, Real time, Grid* g, const char *str)
{
    int err = 0;
    printf("Local Grid %s, id = %d addr = 0x%p\n",str,id,(void*)g);
    err = check_grid(id,time,g);
    if (err > 0) {
	printf("FAILURE on thread %d for private %s\n",(int)MYTHREAD,str);
    }
    return err;
}



int main(int argc, char* argv[])
{
    int numgrid = 8;
    int i;
    int err = 0;
    shared [] Grid *g_grids;
    shared [] Grid *g_copy;
    Grid *l_grids;
    Grid *l_copy;
    Grid *local_grids;

    g_grids = (shared [] Grid*)upc_alloc(numgrid*sizeof(Grid));
    g_copy = (shared [] Grid*)upc_alloc(numgrid*sizeof(Grid));
    l_grids = (Grid*)malloc(numgrid*sizeof(Grid));
    l_copy  = (Grid*)malloc(numgrid*sizeof(Grid));
    data = (shared [] Real*)upc_alloc(10*sizeof(Real));

    for (i = 0; i < numgrid; i++) {
	// init private grid
	local_grid_init(&l_grids[i], i,(Real)i);

	// init shared grid
	shared_grid_init(&g_grids[i], i, (Real)i);

	// copy private grid to shared space
	g_copy[i] = l_grids[i];

	// copy shared grid to private space
	l_copy[i] = g_grids[i];
    }

    if (MYTHREAD == 0) assert(upc_threadof(g_grids) == 0);
    
    local_grids = (Grid*) g_grids;

    for (i = 0; i < numgrid; i++) {
	err += check_shared(i, (Real)i, &g_grids[i], "g_grids");
	err += check_shared(i, (Real)i, &g_copy[i], "g_copy");
	err += check_local(i, (Real)i, &l_grids[i], "l_grids");
	err += check_local(i, (Real)i, &l_copy[i], "l_copy");
	err += check_local(i, (Real)i, &local_grids[i], "local_grids");
    }
	
    if (err == 0) {
	printf("SUCCESS on thread %d\n",(int)MYTHREAD);
    }
}
	    

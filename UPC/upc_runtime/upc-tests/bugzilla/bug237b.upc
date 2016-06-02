#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef CH_SPACEDIM
#define CH_SPACEDIM 2
#endif

#if CH_SPACEDIM==1
#  define D_EXPR(a,b,c) ((void)((a),0))
#  define D_DECL(a,b,c) a
#  define D_TERM(a,b,c) a
#elif CH_SPACEDIM==2
#  define D_EXPR(a,b,c) ((void)((a),(b),0))
#  define D_DECL(a,b,c) a,b
#  define D_TERM(a,b,c) a b
#elif CH_SPACEDIM==3
#  define D_EXPR(a,b,c) ((void)((a),(b),(c),0))
#  define D_DECL(a,b,c) a,b,c
#  define D_TERM(a,b,c) a b c
#endif

typedef struct {
    int v[CH_SPACEDIM];
} IntVect;
typedef enum { CELL = 0, NODE } CellIndex;
typedef unsigned int IndexType;

typedef struct Box_Rec {
    IntVect   lo;       // lower left-hand corner
    IntVect   hi;       // upper right-hand corner
    int       len[CH_SPACEDIM];   // length in each index dir
    IndexType type;
    struct Box_Rec *next, *prev;  // Boxes are often in linked lists.
} Box;


#define COMPUTE_LEN_DIR(b,dir) (b).len[dir] = (b).hi.v[dir] - (b).lo.v[dir] + 1
#define COMPUTE_BOX_LEN(b) D_TERM(   COMPUTE_LEN_DIR(b,0) ,\
                                   ; COMPUTE_LEN_DIR(b,1) ,\
                                   ; COMPUTE_LEN_DIR(b,2) )

const IndexType It_Cell_Centered = 0U;

Box Bx_new(const IntVect *lower, const IntVect *upper)
{
    Box b;
    b.next = b.prev = NULL;
    b.lo = *lower;
    b.hi = *upper;
    COMPUTE_BOX_LEN(b);
    b.type = It_Cell_Centered;
    return b;
}

int main(int argc, char *argv[])
{
    IntVect lower;
    IntVect upper;
    Box     bx;
    int     dir;
    int     npts = 1;
    int     ncell = 1;
    int     err = 0;

    for (dir = 0; dir < CH_SPACEDIM; dir++) {
	lower.v[dir] = 0;
	upper.v[dir] = 9;
	npts *= 10;
    }
    bx = Bx_new(&lower,&upper);

    for (dir = 0; dir < CH_SPACEDIM; dir++) {
	ncell *= bx.len[dir];
    }

    printf("npts = %d  ncell = %d\n",npts,ncell);
    if (npts == ncell) {
	printf("SUCCESS\n");
    } else {
	printf("FAILURE\n");
	err = 1;
    }

    return err;
}

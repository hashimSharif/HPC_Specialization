#include <upc.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define CH_SPACEDIM 2
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

#define IV(iv,dir) (iv).v[(dir)]

/*
 * The CellIndex enumeration type is used to signify
 * whether the associated index represents cell-centered
 * or node-centered quantities.
 */
typedef enum { CELL = 0, NODE } CellIndex;

/*
 * The IndexType of Box encodes the CellIndex of each
 * index direction in the least significant CH_SPACEDIM
 * bits of an unsigned integer
 */
typedef unsigned int IndexType;

#define It_init 0U

/*
  A Box is an abstraction for defining discrete rectangular regions of
  SpaceDim-dimensioned indexing space.  Boxes have an IndexType, which
  defines IndexType::CELL or IndexType::NODE based points for each
  direction and a low and high IntVect which defines the lower and
  upper corners of the Box.  Boxes can exist in positive and negative
  indexing space.

  There is a set of canonical Empty Boxes, once for each centering
  type.  The cell-centered Empty Box can be accessed as Box::Empty.

  Box is a dimension dependent class, so SpaceDim must be 
  defined as either 1, 2, or 3 when compiling.  

*/
typedef struct Box_Rec {
    IntVect   lo;       // lower left-hand corner
    IntVect   hi;       // upper right-hand corner
    int       len[CH_SPACEDIM];   // length in each index dir
    IndexType type;
    struct Box_Rec *next, *prev;  // Boxes are often in linked lists.
} Box;

/* -------------------------------------------------------------------------
 * IndexType Class
 * -------------------------------------------------------------------------
 */

const IndexType It_Cell_Centered = 0U;
const IndexType It_Node_Centered = D_TERM( 1U, |(1U<<1), |(1U<<2) );
#if CH_SPACEDIM == 1
const IndexType It_Edge_Centered[] = { 1U };
#elif CH_SPACEDIM == 2
const IndexType It_Edge_Centered[] = { 1U, (1U << 1) };
#elif CH_SPACEDIM == 3
const IndexType It_Edge_Centered[] = { 1U, (1U << 1), (1U << 2) };
#endif

/* -------------------------------------------------------------------------
 * Box Class
 * -------------------------------------------------------------------------
 */

#define COMPUTE_LEN_DIR(b,dir) (b).len[dir] = (b).hi.v[dir] - (b).lo.v[dir] + 1
#define COMPUTE_BOX_LEN(b) D_TERM(   COMPUTE_LEN_DIR(b,0) ,\
                                   ; COMPUTE_LEN_DIR(b,1) ,\
                                   ; COMPUTE_LEN_DIR(b,2) )


/*
 * Simple cell-centered constructor
 * where lower and upper limits are specified
 */
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

int main(int argc, char* argv[])
{
    IntVect lo;
    IntVect hi;
    int i;
    Box b;
    unsigned int error = 0;

    for (i = 0; i < CH_SPACEDIM; i++) {
	lo.v[i] = i-5;
	hi.v[i] = i+5;
    }
    b = Bx_new(&lo,&hi);
    for (i = 0; i < CH_SPACEDIM; i++) {
	if (b.lo.v[i] != i-5) {
	    error |= (1U << i);
	}
	if (b.hi.v[i] != i+5) {
	    error |= (1U << (i+3));
	}
    }

    if (error) {
	printf("Failure: Thread=%d error=0x%x\n",MYTHREAD,error);
    } else if (MYTHREAD == 0) {
	printf("Success: Thread=%d error=0x%x\n",MYTHREAD,error);
    }
    return((int)error);
}


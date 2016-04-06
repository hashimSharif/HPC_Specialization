#include <upc.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#undef CH_SPACEDIM
#define CH_SPACEDIM 2

#define USE_STRUCT

#ifdef USE_STRUCT
typedef struct IV_REC {
    int v[CH_SPACEDIM];
} IntVect;

const IntVect IntVectUnit = { {1, 1} };
const IntVect IntVectZero = { {0, 0} };

#else

typedef int IntVect;
const IntVect IntVectUnit = 1;
const IntVect IntVectZero = 0;

#endif

typedef struct Box_Rec {
    IntVect   lo;       // lower left-hand corner
    IntVect   hi;       // upper right-hand corner
    int       len[CH_SPACEDIM];   // length in each index dir
    unsigned int type;
    struct Box_Rec *next, *prev;  // Boxes are often in linked lists.
} Box;


Box* Bx_alloc(void)
{
    Box *b = (Box*)malloc(sizeof(Box));
    assert(b!=NULL);
    b->next = b->prev = NULL;
    b->type = 0;
    b->lo = IntVectUnit;
    b->hi = IntVectZero;
    b->len[0] = 0;
    b->len[1] = 0;
    return b;
}

int main(int argc, char* argv[])
{
    Box *bx = Bx_alloc();

    printf("type is %d\n",bx->type);
    return 0;
}

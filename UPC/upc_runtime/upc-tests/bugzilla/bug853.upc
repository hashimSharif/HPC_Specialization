 #include <upc.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define CH_SPACEDIM 2
#define D_DECL(a,b,c) a,b

typedef struct IntVect_Rec {
    int v[CH_SPACEDIM];
} IntVect;

#define Iv_unitInit { { D_DECL( 1, 1, 1 ) } }
#define Iv_zeroInit { { D_DECL( 0, 0, 0 ) } }

typedef unsigned int IndexType;
#define It_init 0U

typedef struct Box_Rec {
    IntVect   lo;       // lower left-hand corner
    IntVect   hi;       // upper right-hand corner
    int       len[CH_SPACEDIM];   // length in each index dir
    IndexType type;
    struct Box_Rec *next;  // for linking onto free list.
} Box;

// Initialization of an invalid box
#define Bx_init {Iv_unitInit, Iv_zeroInit, {D_DECL(0,0,0)}, It_init, NULL}

Box foobar(const Box* b)
{
   Box bb = Bx_init;

   bb.type = b->type;
   return bb;
}

int main(int argc, char *argv[])
{
   Box b = Bx_init;
   Box b2;

   b.type = 2;
   b2 = foobar(&b);

   if (b2.type != b.type) {
     printf("FAILURE on thread %d\n",(int)MYTHREAD);
   } else {
     printf("SUCCESS on thread %d\n",(int)MYTHREAD);
   }
}


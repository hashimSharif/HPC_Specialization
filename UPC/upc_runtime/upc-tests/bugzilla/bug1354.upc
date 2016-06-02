#include <upc.h>
#include <stdio.h>

typedef struct Node_rec {
   double x[3];
   double xo[3];
   double ht;
   double ref;

   double d[4];


   int hn;
   int fix;
   double qu;

   int *l, *lp;
   int nl, ml;
} Node;

typedef shared [] Node *ptr_shared_node;
shared ptr_shared_node nodesSH[THREADS];

int main() {
 int pTmp = MYTHREAD;
 int nTmp = 3;
 nodesSH[pTmp] = upc_alloc(10*sizeof(Node));
 nodesSH[pTmp][nTmp].nl--;
 printf("done.\n");
}


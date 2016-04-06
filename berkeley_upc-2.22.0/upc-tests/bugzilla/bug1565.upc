#include <stdio.h>
#include <upc.h>
#define MAXP 1024
#define NUME 5

typedef struct Node_rec {
   shared [] int *l; 
   int nl;
} Node;

shared [] Node *nodesSH[MAXP];
Node *nodes;
shared [] Node *shared nodesTMP[THREADS];

int main(void){

   int ip,i;
   
   nodesSH[MYTHREAD] = (shared [] Node *) upc_alloc(NUME * sizeof(Node));
   
   nodes = (Node *) nodesSH[MYTHREAD];
   
   upc_barrier;
   nodesTMP[MYTHREAD] = nodesSH[MYTHREAD];
   upc_barrier;
   for (ip = 0; ip < THREADS; ip++)
      if (ip != MYTHREAD)
         nodesSH[ip] = nodesTMP[ip];
   upc_barrier;  
   for (i = 0; i < NUME; i++){
      nodes[i].nl = 0;
   }
   upc_barrier;  
   if (MYTHREAD == 0)
      for (ip = 0; ip < THREADS; ip++)
         for (i = 0; i < NUME; i++)
            nodesSH[ip][i].nl++;
   for (ip = 0; ip < THREADS; ip++){
      upc_barrier;
      if (ip == MYTHREAD)
         for (i = 0; i < NUME; i++) {
            if (nodes[i].nl != 1)
              printf("ERROR: Thread %d has nodes[%d].nl equal to %d\n",MYTHREAD,i,nodes[i].nl);
         } 
   }
   upc_barrier;
   printf("done.\n");
   upc_free(nodesSH[MYTHREAD]);
   upc_global_exit(0);
}


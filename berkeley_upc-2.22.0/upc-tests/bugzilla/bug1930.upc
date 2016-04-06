/*  "PUBLIC" INCLUDE FILE FOR THE DYNAMIC-MESH API LIBRARY  */
/*                                                          */
/*  ANDREW A. JOHNSON - 2006                                */
/*                                                          */
/*  Copyright 2005-2006, Network Computing Services, Inc.   */
/*                                                          */

#include <stdlib.h>
#include <stdio.h>

#define MAX_PROC 512

typedef struct _DynamicMeshRec {

   shared [] int *a[MAX_PROC];
   shared [] int *b[MAX_PROC];
   shared [] int *c[MAX_PROC];
   shared [] int *d[MAX_PROC];
   shared [] int *e[MAX_PROC];
   shared [] int *f[MAX_PROC];
   shared [] int *g[MAX_PROC];
   shared [] int    *h[MAX_PROC];

   int debug;

} DynamicMeshRec;


typedef struct _DynamicMeshRec *DynamicMesh;

DynamicMesh newDynamicMesh(int val){
   DynamicMesh mesh;

   mesh = (DynamicMesh) malloc(sizeof(DynamicMeshRec));

   mesh->debug = val;
   /* printf("mesh debug in newDynamicMesh is %d\n",mesh->debug); */
   return mesh;
}

int readDynamicMesh(DynamicMesh mesh){

  /* printf("mesh debug in readDynamicMesh is %d\n",mesh->debug); */

   return mesh->debug;
}

int main(int argc, char *argv[]){

   int ier;
   DynamicMesh mesh;
   
   mesh = newDynamicMesh(1);

   ier = readDynamicMesh(mesh);

   if (ier != 1) 
     printf("ERROR: a=%d expect=%d\n",ier,1);
    else printf("done.\n");
 
   return 0;
}


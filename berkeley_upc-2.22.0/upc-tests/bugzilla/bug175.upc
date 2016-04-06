#include <upc.h>
#include <stdio.h>

shared float x1;
shared float a[4*THREADS];

#if __UPC_STATIC_THREADS__
#if THREADS != 2
 #error test must be compiled with 2 static threads
#endif
#else
 #error test must be compiled with 2 static threads
#endif

int main() {

  int x = 0 + 
     sizeof(x1) + 
     upc_localsizeof(x1) + 
     upc_blocksizeof(x1) + 
     upc_elemsizeof(x1) +  

     sizeof(a) + 
     upc_localsizeof(a) + 
     upc_blocksizeof(a) + 
     upc_elemsizeof(a) +  

     sizeof(shared float) + 
     upc_localsizeof(shared float) + 
     upc_blocksizeof(shared float) + 
     upc_elemsizeof(shared float) +   

     sizeof(shared float[10]) + 
     upc_localsizeof(shared float[10]) + 
     upc_blocksizeof(shared float[10]) + 
     upc_elemsizeof(shared float[10]) +  

     0;
if (x != 144) printf("ERROR: %i\n",x);
printf("done.\n");
  return 0;
}

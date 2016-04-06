#include <upc.h>
#include <stdio.h>

#if __UPC_DYNAMIC_THREADS__
#error This test is only valid for static threads
#endif

shared [0] int Indef[4] = {0,1,2,3};
shared [1] int Cyclic[4] = {4,5,6,7};
shared [2] int Block2[4] = {8,9,10,11};
shared int fail;

int main(void) {
   upc_forall (int i = 0; i < 4; ++i; i) {
     if (Indef[i] != i) {
       fprintf(stderr, "ERROR: validation failed for Indef[%d]\n", i);
       fail = 1;
     }
     if (Cyclic[i] != 4+i) {
       fprintf(stderr, "ERROR: validation failed for Cyclic[%d]\n", i);
       fail = 1;
     }
     if (Block2[i] != 8+i){
       fprintf(stderr, "ERROR: validation failed for Block2[%d]\n", i);
       fail = 1;
     }
   }

   upc_barrier;

   if (!MYTHREAD) puts ( fail ? "FAIL" : "PASS" );

   return fail;
}

#include <stdio.h>
#include <upc.h>
#define MAXP 10

shared[MAXP] int numMap[THREADS][MAXP];

int main(void){

   int iloc;
 
   iloc = numMap[MYTHREAD][0]++;

   upc_barrier;
   upc_global_exit(0);
}

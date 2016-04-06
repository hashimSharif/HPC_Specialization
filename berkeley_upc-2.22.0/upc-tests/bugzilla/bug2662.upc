#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/* Want to exceed GASNet's 65536 handle limit */
#define ITERS 100000

shared int X[THREADS];

int foo(int op, shared int *src)
{
    if (op == 1) { return *src & 1; }
    if (op == 2) { return *src | 1; }
    return 0;
}

int main (void) {
   int i;
   int sum = 0;

   if (THREADS == 1) {
      printf("This test trivially passes when run with 1 thread.");
      printf("done.");
   } else {
      X[MYTHREAD] = 0;

      upc_barrier;
      for (i = 0; i < ITERS; ++i) {
         sum += foo(i, &X[MYTHREAD ^ 1]);
      }
      upc_barrier;
   }
 
   if (!MYTHREAD) printf("done.");
   return 0;
}
   

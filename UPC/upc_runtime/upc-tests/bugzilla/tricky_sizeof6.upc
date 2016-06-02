#include <stdio.h>
#include <assert.h>

shared int A[10][10*THREADS];

int main() {
int x = sizeof(int)*100*THREADS;
switch (x) {
  case sizeof(A): ; /* error in dyn env, ok in static */
   printf("done.\n");
  break;
  default:
   printf("ERROR\n");
} 
return 0;
}

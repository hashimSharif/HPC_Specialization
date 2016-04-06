#include <stdio.h>
#include <upc_strict.h>
#include <stdlib.h>

int * shared p;

int main(int argc, char **argv) {
 if (MYTHREAD == 0) {
    int i;
    p = (int*)malloc(10*sizeof(int));
    for (i=0;i<10;i++)
     p[i] = i;
    for (i=0;i<10;i++) {
      if(p[i] != i) {
	printf("%s: Error\n", argv[0]);
	upc_global_exit(1);
      }
    }
    printf("%s: Passed\n", argv[0]);
 }
 upc_barrier;
 
 return 0;
}

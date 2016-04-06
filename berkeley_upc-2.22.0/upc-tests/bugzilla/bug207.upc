/* compile with -T 1 to see problem */

#include <upc.h>
#include <stdio.h>

int xneedstart[THREADS];

int main() {
    int i;
    for(i=0;i < THREADS;i++) {
      xneedstart[i]=i;
    }
    printf("done.\n");
    return 0;
}

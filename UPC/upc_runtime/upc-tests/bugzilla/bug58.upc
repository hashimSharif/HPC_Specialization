#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

int * shared a[THREADS];
int *qint;

struct S {
  int *p;
  shared [] int *q;
};

struct S *ps;
struct S * shared pss;

int localint;

int *local[1000];
int main() {
  int i, j;
  
  a[MYTHREAD] = &localint;
  
  if(a[MYTHREAD] != &localint) {
    fprintf(stderr, "%d: Error in assignment",MYTHREAD);
    upc_global_exit(1);
  }
  
  if(MYTHREAD == 0) {
    pss = malloc(sizeof(struct S));
    pss->p = &localint;
    if(pss->p != &localint) {
      fprintf(stderr, "%d: Error in assignment",MYTHREAD);
      upc_global_exit(1);
    }
  }
}


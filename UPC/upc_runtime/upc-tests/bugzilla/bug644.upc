#include <stdio.h>
#include <stdlib.h>
#include <upc_relaxed.h>

#define M 10

struct S {
    int x;
    int y; 
    shared int *p;
};

shared struct S s;

int main(){
  int i;

  if(MYTHREAD==0){
    s.p = upc_global_alloc(M, sizeof(int));
    for(i=0; i<M; i++){
      s.p[i] = 0;
    }
  }
  printf("SUCCESS\n");
}

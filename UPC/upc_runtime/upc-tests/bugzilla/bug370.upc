#include <upc.h>
#define NUMBER 100
#define BLOCK 8

struct foo {
  char No;
  int  a[NUMBER];
};

shared[BLOCK] struct foo barray[THREADS];

int main() {

  int i = 0,j =0;
  for(i=0; i<THREADS; i++){
    barray[i].No=i;
    for(j=0; j<NUMBER; j++)
      barray[i].a[j]=i*NUMBER+j;
  }
}


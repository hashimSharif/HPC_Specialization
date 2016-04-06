#include <stdlib.h>
#include <stdio.h>
#include <upc_relaxed.h>

shared float f;

int main(){
  if(MYTHREAD==0){
    f = 12;
    printf("%f\n", f);
  }
  return 0;
}


#include <stdio.h>

int main(){

  #pragma omp parallel
  printf("hello from thread \n");

  return 0;
}

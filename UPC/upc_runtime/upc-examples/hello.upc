/* hello.upc - a simple UPC example */
#include <upc.h>
#include <stdio.h>

int main() {
  if (MYTHREAD == 0) {
    printf("Welcome to Berkeley UPC!!!\n");
  }
  upc_barrier;
  printf(" - Hello from thread %i\n", MYTHREAD);
  return 0;
} 
 

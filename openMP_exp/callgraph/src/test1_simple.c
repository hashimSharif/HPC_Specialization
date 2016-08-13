
#include <stdio.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
 
  #pragma omp parallel default(shared)
  {
    printf("Hello from thread \n");  
  }
  
  return 0;
}

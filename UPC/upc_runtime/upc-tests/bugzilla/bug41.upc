#include <upc.h>
#include <sys/time.h>
#include <stdlib.h>
#include <bug41.uph>

struct timeval tv;

int main() {

  shared int *p1;
  shared [5] int *p2;
  shared [] int *p3;
  shared [10] int *p4;
  struct foo f1;	
  double sec;
  FILE* file = NULL;

  f1.x = foo();

  gettimeofday(&tv, (void *)0);	
  
  fprintf(file, "done\n");
  exit(0);
}

#include <stdlib.h>



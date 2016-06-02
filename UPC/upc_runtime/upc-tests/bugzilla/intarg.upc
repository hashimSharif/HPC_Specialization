#include <stdio.h>
#include <upc.h>
#include <string.h>

shared [10] int x[10*THREADS];

int main() {
  shared [10] int *x0;
  int x1 = 1;
  short x2 = 2;
  shared [10] int *x3;
  long x4 = 4;
  long long x5 = 5;
  char str[80];

  x0 = &(x[0]);
  x3 = &(x[3]);
  
  sprintf(str, "%s %i %i %i %i %i %i %i %s",
       "begin",
       (int)upc_threadof(x0),
       x1,
       x2,
       (int)upc_phaseof(x3),
       (int)x4,
       (int)x5,
       6,
       "end");
  if (!strcmp(str, "begin 0 1 2 3 4 5 6 end")) 
    printf("Success: %s\n",str);
  else
    printf("Fail: %s\n",str);
  return 0;
}


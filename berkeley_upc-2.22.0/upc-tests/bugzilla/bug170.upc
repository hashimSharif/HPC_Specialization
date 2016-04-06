#include <upc.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

#define NUMBER 100

struct foo { 
  char No;
  int  a[NUMBER]; 
};

shared struct foo sarray[100*THREADS];
shared struct stat s;

int main() {

  sarray[20].No = 't';
  sarray[40].a[13] = 5;

  if (MYTHREAD == 0) {
    struct stat *ls = (struct stat *)&s;
    stat("/",ls);

    printf("%i\n",(int)(s.st_size));
  }
  return 0;
}

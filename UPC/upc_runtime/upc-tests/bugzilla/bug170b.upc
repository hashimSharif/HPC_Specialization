#include <upc.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


shared struct stat s;

int main() {

  if (MYTHREAD == 0) {
    struct stat *ls = (struct stat *)&s;
    stat("/",ls);

    printf("%i\n",(int)(s.st_size));
  }
  return 0;
}


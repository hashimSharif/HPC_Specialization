#include <upc.h>

struct foo {
  char No;
  int  a[10];
};
shared [5] struct foo sarray[10*THREADS];
int main() {
     int i = 2;
     shared [] char *pNo;
     pNo=&sarray[i].No; 
     return 0;
}

#include <upc_strict.h>

struct foo { 
  char No;
  int  a[100]; 
};

shared [8] struct foo barray[THREADS];

int main()
{
   int i = 0;
   
   barray[i].No = 0;
}       

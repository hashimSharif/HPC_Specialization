#include <stdio.h>
#include <stdlib.h>
#include <upc_relaxed.h>

typedef shared [] int *sintptr;
shared [] sintptr globaldir[THREADS];
int main()
{
  sintptr *localdir = NULL;
  int i = 0;
  localdir[i] = 0;

}




#include <stdio.h>
#include <upc.h>

shared void *sfoo(shared void *p) { return p; }
void *pfoo(void *p) { return p; }

int main() { 
#define NUM 6
shared int *pts[NUM];
shared [4] int *ptb[NUM];
int *ptl[NUM];
int i=0;

pts[i] = 0;
ptb[i] = 0;
ptl[i] = 0;
i++;

pts[i] = (void *)0;
ptb[i] = (void *)0;
ptl[i] = (void *)0;
i++;

pts[i] = NULL;
ptb[i] = NULL;
ptl[i] = NULL;
i++;

pts[i] = sfoo(0);
ptb[i] = sfoo(0);
ptl[i] = pfoo(0);
i++;

pts[i] = sfoo((void *)0);
ptb[i] = sfoo((void *)0);
ptl[i] = pfoo((void *)0);
i++;

pts[i] = sfoo(NULL);
ptb[i] = sfoo(NULL);
ptl[i] = pfoo(NULL);
i++;

for (int i=0; i<NUM; i++) {
  if (pts[i] != NULL) printf("ERROR at pts[%i]\n", i);
  if (ptb[i] != NULL) printf("ERROR at ptb[%i]\n", i);
  if (ptl[i] != NULL) printf("ERROR at ptl[%i]\n", i);
}

printf("done.\n");
return 0;
}

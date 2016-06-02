#include <stdio.h>
#include <upc.h>
#include <inttypes.h>

shared [5] int x[5*THREADS];
shared void *p;
int main() {
 char *lp;
 int t;
 intptr_t y;

 if (MYTHREAD==1) {
   p = &(x[7]);
   lp = (char *)p;
   y = (intptr_t)(char *)p;
   t = upc_threadof(p);
   printf("%i 0x%08x 0x%08x\n",t,(int)(intptr_t)lp, (int)y);
 }
 return 0;
}


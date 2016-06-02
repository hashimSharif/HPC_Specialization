#include <stdio.h>
#include <upc.h>

shared [] int * shared sx1;

int main() {
char tmp[100];
shared [] int *foo;

foo = sx1;
bupc_dump_shared(foo, tmp, 100);
printf("%i: %s\n",MYTHREAD,tmp);

upc_barrier;

// this put causes incorrect data to arrive on node 0
if (MYTHREAD != 0) sx1 = NULL; 

upc_barrier;

foo = sx1;
bupc_dump_shared(foo, tmp, 100);
printf("%i: %s\n",MYTHREAD,tmp);

printf("%i done.\n", MYTHREAD);
return 0;
}

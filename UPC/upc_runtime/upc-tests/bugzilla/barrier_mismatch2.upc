#include <upc.h>
#include <stdio.h>

int main() {
int x;
int me = MYTHREAD;
upc_barrier;
printf("Hello from %i/%i\n",MYTHREAD,THREADS); fflush(stdout);
if (MYTHREAD == 2) return 0;
upc_barrier;
printf("Hello again from %i/%i\n",MYTHREAD,THREADS); fflush(stdout);
//upc_barrier;
printf("Goodbye from %i/%i\n",MYTHREAD,THREADS); fflush(stdout);
return 0;
}

#include <upc.h>
#include <stdio.h>

int main() {
char name[50];
sprintf(name, "foo.%i",MYTHREAD);
FILE *fp = fopen(name,"wb");
for (int i=0; i < 1000; i++) {
  fprintf(fp,"%i\n",i);
}
upc_barrier;
upc_global_exit(0);
}

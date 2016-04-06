#include <upc.h>

typedef shared [] double *sdblptr;
sdblptr reduce_incoming;
volatile double *reduce_incoming_local;
shared sdblptr reduce_incoming_directory[THREADS];

void initdoublereduce()
{
  int i;
  reduce_incoming = (sdblptr) upc_alloc(THREADS*sizeof(double));
  reduce_incoming_local = (double *) reduce_incoming;
  reduce_incoming_directory[MYTHREAD] = reduce_incoming;

}
int main(){return 0;}

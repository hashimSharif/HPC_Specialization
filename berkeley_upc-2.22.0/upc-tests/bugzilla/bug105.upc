#include <upc_relaxed.h>

typedef shared [] double *sdblptr;
shared sdblptr directory[THREADS];
sdblptr mypart;  

int main()
{
  mypart = (sdblptr) upc_alloc(THREADS*sizeof(double));
  directory[MYTHREAD]=mypart;
}





#include <upc_relaxed.h>
#include <stdio.h>
 
typedef shared [] double *sdblptr;
shared sdblptr x[THREADS];
shared double y[THREADS];
int main()
{
printf("done.\n");
}

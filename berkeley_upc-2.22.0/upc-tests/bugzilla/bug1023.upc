#include <upc.h>
#define STRUCTSIZE 6
typedef struct { char a[STRUCTSIZE]; } cpstruct;
shared[] char* localrow[10];
int main() {
localrow[0] = upc_alloc(2*sizeof(cpstruct));
shared [] cpstruct *psp = (shared void*)localrow[0];
shared [] cpstruct *p = (shared void*)localrow[0];
*(psp++) = *(p++);
}


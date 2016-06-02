#include <upc.h>
#include <math.h>
shared[129] double ry[129][129];

shared[1] double rym;

int main() {

int i;
int j;
int m;
shared[1] double *d__7;

for (j = 0; (j < 257); j = (j + 1)) {

 d__7 = (&rym);
 (*d__7) = (((fabs((((shared[129] double *)(ry + 0))[j]))) > ((*d__7))) ?
           (fabs((((shared[129] double *)(ry + 0))[j]))) : 
           ((*d__7))); 
} 
return 0;
}


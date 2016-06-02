#include <stdio.h>
#include <upc.h>

int main() {
double d;
double zero = 0.0;
d = 0.0;
d = d / zero;
printf("%f\n",d);
d = 1.0;
d = d / zero;
printf("%f\n",d);
d = -1.0;
d = d / zero;
printf("%f\n",d);
upc_barrier;
printf("done.\n");
return 0;
}

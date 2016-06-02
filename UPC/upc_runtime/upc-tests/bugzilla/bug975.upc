#include <upc.h>
#include <stdio.h>

int main() {
shared [10] int *i = NULL;
shared [10] int *s = NULL;
if (s == i) printf("OK\n");
if (s != i) printf("ERROR\n");
printf("done.\n");
return 0;
}

#include <stdio.h>
int * shared sx7; /* a shared pointer-to-local-int */

int main() {
if (sx7 != NULL) printf("ERROR");
sx7 = NULL;
if (sx7 != NULL) printf("ERROR");
printf("done.\n");
return 0;
}

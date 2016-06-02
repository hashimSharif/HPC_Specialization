#include <stdio.h>
#include <upc.h>

int main() {
upc_forall(int i = 0; i < 10; i++; i) {
 printf("%i\n", i);
}
upc_forall(int i = 0, j = 10; i < 10; i++, j--; i) {
 printf("%i %i\n", i, j);
}
printf("done.\n");
return 0;
}

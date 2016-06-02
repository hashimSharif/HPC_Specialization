#include <upc.h>
#include <stdio.h>
shared int x = 5;
shared int y = 6;

int main() {
 printf("%i %i\n", x, y);
 printf("done.\n");
 return 0;
}

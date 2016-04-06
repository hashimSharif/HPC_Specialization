#include <upc.h>

int x;
int * shared sp = &x; // BAD - this is invalid

int main(void) { return 0; }

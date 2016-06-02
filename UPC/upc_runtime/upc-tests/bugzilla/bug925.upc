#include <upc.h>
#include <stdio.h>

int main() {
shared void *p = NULL;
printf("%lu\n",(unsigned long)upc_addrfield(p));
return 0;
}

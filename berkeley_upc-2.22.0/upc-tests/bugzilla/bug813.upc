#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
shared void *foo() {
return NULL;
}
shared [] char *bar() {
return NULL;
}
shared [10] char *blah() {
return NULL;
}
int main() {
assert(foo() == NULL);
assert(bar() == NULL);
assert(blah() == NULL);
printf("done.\n");
return 0;
}

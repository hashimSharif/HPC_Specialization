#include <stddef.h>
int* shared sp1;
int main() {
 int *p;
 sp1 = NULL;
 p = sp1;
 return 0;
}

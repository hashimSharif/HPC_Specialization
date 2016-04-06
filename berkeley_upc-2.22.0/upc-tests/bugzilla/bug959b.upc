#include <stdio.h>
int x = 1;

int main() {
 const char *p = ( x ? "hi" : "there" );
 printf("%s", ( x ? "peanutbutter" : "jelly") );
 return 0;
}

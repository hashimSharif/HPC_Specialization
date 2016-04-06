#include <assert.h>
#include <stdio.h>
char my_char = 100;
short my_short = 2000;
int my_int = 400000;
double my_double = 23.0;
int main() {
assert(my_char == 100);
assert(my_short == 2000);
assert(my_int == 400000);
assert(my_double == 23.0);
printf("done.\n");
return 0;
}

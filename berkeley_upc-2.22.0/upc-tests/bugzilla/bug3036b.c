#include "bug3036b.h"
enum e1 foo (int x) { return (enum e1)x; }
int main(void) { return (int) foo( 0 ); }

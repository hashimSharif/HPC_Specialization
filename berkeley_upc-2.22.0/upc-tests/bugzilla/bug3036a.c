#include "bug3036a.h"
int foo (enum foo x) { return (int)x; }
int main(void) { return foo( e_a ); }

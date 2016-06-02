#include <upc.h>

// Some of the following fail to compile on 64-bit targets
shared [1] int array1   [1    * THREADS]; // OK
shared [1] int array1L  [1L   * THREADS]; // BUG
shared [1] int array1LL [1LL  * THREADS]; // OK
shared [1] int array1U  [1U   * THREADS]; // BUG
shared [1] int array1UL [1UL  * THREADS]; // BUG
shared [1] int array1ULL[1ULL * THREADS]; // BUG

int main(void) { return 0; }

#include <string.h>
// alloca() is non-standard and may be in stdlib.h or alloc.h
#include <stdlib.h>
#if !defined(alloca) && !defined(__NetBSD__) && !defined(__OpenBSD__)
#include <alloca.h>
#endif

int main() {
  return 0;
}

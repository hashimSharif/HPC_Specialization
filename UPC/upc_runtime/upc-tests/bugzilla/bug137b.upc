#include <string.h>
// alloca() is non-standard and may be in stdlib.h or alloc.h
#include <stdlib.h>
#if !defined(alloca) && !defined(__NetBSD__) && !defined(__OpenBSD__)
#include <alloca.h>
#endif

int main() {
  char *x = alloca(1);
  char *y;
  int z;
  memset(x,0,1);
  z = strlen(x);
  y = x;
  memcpy(x, y, 1); 
  z = memcmp(x,y,1);
  return 0;
}

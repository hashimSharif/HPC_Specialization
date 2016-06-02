#include <stdio.h>

#define BLK 3

typedef int I;
typedef I J[10];
typedef shared [BLK] J K[10];
typedef K L[10];
K k;
L l;
shared [BLK] int k2[10][10];
shared [BLK] int l2[10][10][10];

shared int fail = 0;

#define check(_lhs, _rhs) do { \
    int _tmpl = (int)(_lhs); \
    int _tmpr = (int)(_rhs); \
    printf(#_lhs "=%d\n", _tmpl);\
    if (_tmpl != _tmpr) { \
      printf("ERROR: " #_lhs " != %d\n", _tmpr);\
      fail = 1; \
    } \
  } while (0)
  
int main() {
check(upc_blocksizeof(K), 3);
check(upc_blocksizeof(L), 3);
check(upc_blocksizeof(k), 3);
check(upc_blocksizeof(l), 3);
check(upc_blocksizeof(k2), 3);
check(upc_blocksizeof(l2), 3);
upc_barrier;

if (!MYTHREAD) puts("done.");

return fail;
}

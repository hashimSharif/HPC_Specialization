#include <stdio.h>

#define div_threads_round_up(X) (((X) + THREADS - 1) / THREADS)

typedef int I;
typedef I J[10];
typedef shared [div_threads_round_up(100)] J K[10];
typedef K L[10];
K k;
L l;
shared [*] int k2[10][10];
shared [*] int l2[10][10][10];

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
check(upc_blocksizeof(K), div_threads_round_up(100));
check(upc_blocksizeof(L), upc_blocksizeof(K));
check(upc_blocksizeof(k), upc_blocksizeof(K));
check(upc_blocksizeof(l), upc_blocksizeof(L));
check(upc_blocksizeof(k2), div_threads_round_up(100));
check(upc_blocksizeof(l2), div_threads_round_up(1000));
upc_barrier;

if (!MYTHREAD) puts("done.");

return fail;
}

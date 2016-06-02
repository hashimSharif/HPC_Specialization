#include <upc.h>
#include <upc_collective.h>

#define SUM_FUNC(_suffix, _type) \
	static _type Sum##_suffix(_type x, _type y) { return (x + y); }
SUM_FUNC(F, float)
SUM_FUNC(D, double)
SUM_FUNC(LD, long double)

static void foo(shared void *s, shared void *d)
{
  upc_all_reduceF(s, d, UPC_FUNC, 1, 1, SumF, 0);
  upc_all_reduceD(s, d, UPC_FUNC, 1, 1, SumD, 0);
  upc_all_reduceLD(s, d, UPC_FUNC, 1, 1, SumLD, 0);
  upc_all_prefix_reduceF(s, d, UPC_FUNC, 1, 1, SumF, 0);
  upc_all_prefix_reduceD(s, d, UPC_FUNC, 1, 1, SumD, 0);
  upc_all_prefix_reduceLD(s, d, UPC_FUNC, 1, 1, SumLD, 0);
}

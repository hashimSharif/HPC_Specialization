#include <upc.h>

#if ! UPC_MAX_BLOCK_SIZE
#error UPC_MAX_BLOCK_SIZE is not defined
#endif

#if UPC_MAX_BLOCK_SIZE < 100
  #error bad UPC_MAX_BLOCK_SIZE
#else
int y;
#endif

#if ! __UPC__
#error __UPC__ is not defined
#endif

#if ! __UPC_DYNAMIC_THREADS__ && ! __UPC_STATIC_THREADS__
  #error __UPC_DYNAMICTHREADS__ or __UPC_STATICTHREADS__ must be defined to one!
#endif

#if defined(__UPC_DYNAMIC_THREADS__) && defined(__UPC_STATIC_THREADS__)
  #error __UPC_DYNAMIC_THREADS__ and __UPC_STATIC_THREADS__ both defined!
#endif

int main() {}

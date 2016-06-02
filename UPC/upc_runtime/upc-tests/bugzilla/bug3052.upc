#include <upc.h>

int main(void)
{
  // These are not legal UPC by 6.5.1.1, constraint 6:
#if !defined(TEST) || (TEST == 1)
  shared [*] int (*X)[THREADS];
#endif
#if !defined(TEST) || (TEST == 2)
  shared [*] int (*Y)[1000];
#endif
#if !defined(TEST) || (TEST == 3)
  shared [*] int *Z;
#endif
#if !defined(TEST) || (TEST == 4)
  shared [*] int **A;
#endif

  return 0;
}

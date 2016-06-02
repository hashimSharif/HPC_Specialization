#include <upc.h>
#include <stdio.h>


#define NOTEQUAL(t1,t2) do { \
  if (bupc_assert_type(t1,t2)) \
   fprintf(stderr,"ERROR line %i: mismatched types compare equal: (%s) != (%s)\n", \
	__LINE__,#t1, #t2); \
  } while (0)

typedef shared [2] int *(*fnptr)(const int *, shared float *);

int main() {
  NOTEQUAL(const volatile int, int);
  NOTEQUAL(const volatile int *, int *);
  NOTEQUAL(int * const, int *);
  NOTEQUAL(int * * const * * , int ****);
  NOTEQUAL(int * * volatile * * , int ****);
  NOTEQUAL(shared [10] int, shared [2] int);
  NOTEQUAL(fnptr, int);

  printf("done.\n");
  return 0;
}

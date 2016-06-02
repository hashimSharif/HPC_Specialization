#include <upc.h>
#include <stdio.h>

static void various(int ii, int jj)
{
  // These are illegal in dynamic threads environment:
  typedef shared int (*pc)[THREADS][ 13  ][THREADS];
  typedef shared int (*pd)[THREADS][ii+jj][THREADS];

  unsigned long eltSize = sizeof(int);

  if (MYTHREAD == 0) {
    int fail = 0;
    printf("THREADS is %d; eltSize is %lu\n", THREADS, eltSize);

    printf("sizeof(*pc) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pc)NULL), (THREADS*(13)*THREADS)*eltSize);
    fail += (sizeof(*(pc)NULL) != (THREADS*(13)*THREADS)*eltSize);

    printf("sizeof(*pd) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pd)NULL), (THREADS*(ii+jj)*THREADS)*eltSize);
    fail += (sizeof(*(pd)NULL) != (THREADS*(ii+jj)*THREADS)*eltSize);

    puts ( fail ? "FAIL" : "PASS" );
  }
}

int main(void)
{
  various(11, 13);
  return 0;
}

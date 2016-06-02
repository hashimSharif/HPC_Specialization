#include <upc.h>
#include <stdio.h>

static void various(int ii, int jj)
{
  typedef int (*pa)[5 ][THREADS][7 ];
  typedef int (*pb)[ii][THREADS][jj];
  typedef int (*pc)[THREADS][ 13  ][THREADS];
  typedef int (*pd)[THREADS][ii+jj][THREADS];
  typedef int aa   [5 ][THREADS][7 ];
  typedef int ba   [ii][THREADS][jj];
  typedef int ca   [THREADS][ 13  ][THREADS];
  typedef int da   [THREADS][ii+jj][THREADS];
  typedef aa * pa2;
  typedef ba * pb2;
  typedef ca * pc2;
  typedef da * pd2;

  if (MYTHREAD == 0) {
    unsigned long eltSize = sizeof(int);
    int fail = 0;

    printf("THREADS is %d; eltSize is %lu\n", THREADS, eltSize);

    printf("sizeof(*pa) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pa)NULL), (5*THREADS*7)*eltSize);
    fail += (sizeof(*(pa)NULL) != (5*THREADS*7)*eltSize);
    printf("sizeof(*pb) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pb)NULL), (ii*THREADS*jj)*eltSize);
    fail += (sizeof(*(pb)NULL) != (ii*THREADS*jj)*eltSize);
    printf("sizeof(*pc) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pc)NULL), (THREADS*(13)*THREADS)*eltSize);
    fail += (sizeof(*(pc)NULL) != (THREADS*(13)*THREADS)*eltSize);
    printf("sizeof(*pd) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pd)NULL), (THREADS*(ii+jj)*THREADS)*eltSize);
    fail += (sizeof(*(pd)NULL) != (THREADS*(ii+jj)*THREADS)*eltSize);
    printf("sizeof(aa) is %lu; expect %lu\n", 
           (unsigned long)sizeof(aa), (5*THREADS*7)*eltSize);
    fail += (sizeof(aa) != (5*THREADS*7)*eltSize);
    printf("sizeof(ba) is %lu; expect %lu\n", 
           (unsigned long)sizeof(ba), (ii*THREADS*jj)*eltSize);
    fail += (sizeof(ba) != (ii*THREADS*jj)*eltSize);
    printf("sizeof(ca) is %lu; expect %lu\n", 
           (unsigned long)sizeof(ca), (THREADS*(13)*THREADS)*eltSize);
    fail += (sizeof(ca) != (THREADS*(13)*THREADS)*eltSize);
    printf("sizeof(da) is %lu; expect %lu\n", 
           (unsigned long)sizeof(da), (THREADS*(ii+jj)*THREADS)*eltSize);
    fail += (sizeof(da) != (THREADS*(ii+jj)*THREADS)*eltSize);
    printf("sizeof(*pa2) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pa2)NULL), (5*THREADS*7)*eltSize);
    fail += (sizeof(*(pa2)NULL) != (5*THREADS*7)*eltSize);
    printf("sizeof(*pb2) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pb2)NULL), (ii*THREADS*jj)*eltSize);
    fail += (sizeof(*(pb2)NULL) != (ii*THREADS*jj)*eltSize);
    printf("sizeof(*pc2) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pc2)NULL), (THREADS*(13)*THREADS)*eltSize);
    fail += (sizeof(*(pc2)NULL) != (THREADS*(13)*THREADS)*eltSize);
    printf("sizeof(*pd2) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pd2)NULL), (THREADS*(ii+jj)*THREADS)*eltSize);
    fail += (sizeof(*(pd2)NULL) != (THREADS*(ii+jj)*THREADS)*eltSize);

    puts( fail ? "FAIL" : "PASS" );
  }
}

int main(void)
{
  various(11, 13);
  return 0;
}

#include <stdio.h>
#include <upc.h>

static void various(int ii, int jj)
{
  typedef shared int (*pa)[5 ][THREADS][7 ];
  typedef shared int aa   [5 ][THREADS][7 ];
  typedef shared int ba   [ii][THREADS][jj]; // BUPC says this has sizeof == 0
  typedef aa * pa2;

  if (MYTHREAD == 0) {
    unsigned long eltSize = sizeof(int);
    int fail = 0;

    printf("THREADS is %d; eltSize is %lu\n", THREADS, eltSize);
    printf("sizeof(*pa) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pa)NULL), (5*THREADS*7)*eltSize);
    fail += (sizeof(*(pa)NULL) != (5*THREADS*7)*eltSize);
    printf("sizeof(aa) is %lu; expect %lu\n", 
           (unsigned long)sizeof(aa), (5*THREADS*7)*eltSize);
    fail += (sizeof(aa) != (5*THREADS*7)*eltSize);
    printf("sizeof(ba) is %lu; expect %lu\n", 
           (unsigned long)sizeof(ba), (ii*THREADS*jj)*eltSize);
    fail += (sizeof(ba) != (ii*THREADS*jj)*eltSize);
    printf("sizeof(*pa2) is %lu; expect %lu\n", 
           (unsigned long)sizeof(*(pa2)NULL), (5*THREADS*7)*eltSize);
    fail += (sizeof(*(pa2)NULL) != (5*THREADS*7)*eltSize);

    puts( fail ? "FAIL" : "PASS" );
  }
}

int main(void)
{
  various(11, 13);
  return 0;
}

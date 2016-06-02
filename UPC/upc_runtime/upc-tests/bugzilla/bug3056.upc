#include <upc.h>
#include <stdio.h>

#ifndef BUG1
#define BUG1 1
#endif
#ifndef BUG2
#define BUG2 1
#endif

static void various(int ii, int jj)
{
  typedef shared int (*pb)[ii][THREADS][jj];
  typedef shared int ba   [ii][THREADS][jj];
  typedef ba * pb2;
  pb pb_p = upc_all_alloc (ii * THREADS * jj, sizeof (int));
  pb2 pb2_p = upc_all_alloc (ii * THREADS * jj, sizeof (int));
  long eltSize = sizeof(int);
  if (MYTHREAD == 0) {
    int fail = 0;
    printf("THREADS is %d; eltSize is %ld\n", THREADS, eltSize);
#if BUG1
    printf("sizeof(*pb) is %ld; expect %ld\n", 
           (long int)sizeof(*pb_p), (ii*THREADS*jj)*eltSize);
    fail += (sizeof(*pb_p) != (size_t)(ii*THREADS*jj)*eltSize);
#endif
#if BUG2
    printf("sizeof(*pb2) is %ld; expect %ld\n", 
           (long int)sizeof(*pb2_p), (ii*THREADS*jj)*eltSize);
    fail += (sizeof(*pb2_p) != (size_t)(ii*THREADS*jj)*eltSize);
#endif
    upc_free (pb_p);
    upc_free (pb2_p);
    puts ( fail ? "FAIL" : "PASS" );
  }
}

int main(void)
{
  various(11, 13);
  return 0;
}

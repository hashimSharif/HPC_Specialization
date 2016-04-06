#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  shared [0] int (*X0)[THREADS] = upc_alloc (THREADS * sizeof (int));
  shared [1] int (*X1)[THREADS] = upc_all_alloc (THREADS, sizeof(int));
  shared [0] int (*Y0)[argc] = upc_alloc (argc * sizeof (int));
  shared [1] int (*Y1)[argc] = upc_all_alloc (argc, sizeof(int));
  shared     int  **Z =  malloc (sizeof(shared int *));
  if (MYTHREAD == 0) {
    puts( (sizeof(*X0) == (THREADS * sizeof (int)))
      ? "X0 - PASS" : "X0 - FAIL" );
    puts( (sizeof(*X1) == (THREADS * sizeof (int)))
      ? "X1 - PASS" : "X1 - FAIL" );
    puts( (sizeof(*Y0) == (argc * sizeof (int)))
      ? "Y0 - PASS" : "Y0 - FAIL" );
    puts( (sizeof(*Y1) == (argc * sizeof (int)))
      ? "Y1 - PASS" : "Y1 - FAIL" );
    puts( (sizeof(*Z ) == sizeof (shared int *))
      ? "Z  - PASS" : "Z  - FAIL" );
    upc_free(X1);
    upc_free(Y1);
  }
  upc_free(X0);
  upc_free(Y0);
  free(Z);
  return 0;
}

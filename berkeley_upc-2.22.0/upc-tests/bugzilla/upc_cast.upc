/* Test of bupc_cast() and friends, including comparison to bupc_thread_distance() */
#include <upc.h>
#include <stdio.h>

shared int X[THREADS];

int main(int argc, const char **argv)
{
  int offset = (argc > 1) ? atoi(argv[1]) : (867-5309);
  int i, j;

  X[MYTHREAD] = offset + MYTHREAD;

  for (i = 0; i <THREADS; ++i) {
    upc_barrier;
    if (i == MYTHREAD) {
      for (j=0; j <THREADS; ++j) {
        int a = bupc_castable(&X[j]);
        int *p = a ? bupc_cast(&X[j]) : NULL;
        int x = (a ? *p : -1);
        int distance = bupc_thread_distance(i,j);
     
        if ((j==i) && !a) {
          printf("ERROR: On thread %d: bupc_castable(&X[MYTHREAD]) is FALSE)\n", i);
        }
        if (!a != (distance > BUPC_THREADS_VERYNEAR)) {
          printf("ERROR: On thread %d: bupc_castable(&X[%d]) disagrees with bupc_thread_distance(%d,%d)\n", i, j, i, j);
        }
#if __BERKELEY_UPC__ /* Assumption that castable implies thread_castable */
        if (!a != !bupc_thread_castable(j)) {
          printf("ERROR: On thread %d: bupc_castable(&X[%d]) != bupc_thread_castable(%d)\n", i, j, j);
        }
#endif
        if (a && (x != X[j])) {
          printf("ERROR: On thread %d: *bupc_cast(&X[%d]) != X[%d]\n", i, j, j);
        }
      }
      fflush(stdout);
    }
  }

  upc_barrier;
  if (!MYTHREAD) printf("Done.\n");
 
  return 0;
}

#include <upc.h>
#include <stdio.h>

static shared [*] int arr[THREADS][6];
shared int fail;

int main(void) {
  if (!MYTHREAD)  {
    for (int i = 0; i <THREADS; ++i) {
      for (int j = 0; j <6; ++j) {
        int th = (int)upc_threadof(&arr[i][j]);
        printf("%d ", th);
        if (th != i) fail = 1;
      }
      printf("\n");
    }
    puts(fail ? "FAIL" : "PASS");
  }

  upc_barrier;
  return fail;
}

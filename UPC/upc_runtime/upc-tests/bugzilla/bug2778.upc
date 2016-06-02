#include <upc.h>
#include <stdio.h>

shared [*] int a[THREADS][3];

int main(void) {
  if (MYTHREAD == 0) {
    int i,j;
    int valErrs = 0;
    int affErrs = 0;

    for (i=0; i<3; i++) {
      for (j=0; j<THREADS; j++) {
        a[j][i] = 100*(j+1) + i;
      }
    }
    for (i=0; i<3; i++) {
      for (j=0; j<THREADS; j++) {
        valErrs += (a[j][i] != 100*(j+1) + i);
        if (valErrs == 1) printf("First value error found at a[%i][%i]\n", j,i);
        affErrs += (upc_threadof(&a[j][i]) != j);
        if (affErrs == 1) printf("First affinity error found at a[%i][%i]\n", j,i);
      }
    }
    puts((valErrs || affErrs) ? "FAIL" : "PASS");
  }

  return 0;
}

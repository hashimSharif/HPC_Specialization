#include <assert.h>
#include <stdlib.h>
#include <upc_relaxed.h>


typedef struct { double real; double imag; } dcomplex;
/* Static reshuffle array */
typedef struct
  {
    dcomplex arr[10*10*10];
  }
reshuffle_arr_line;

shared[1] reshuffle_arr_line big_reshuffle_arr[THREADS];

shared[]
     dcomplex *shared reshuffle_arr_shd[THREADS];



static void
setup (void)
{

  shared dcomplex *dbg_sum=NULL;
  dcomplex chk;
  int i;
  chk.real = 0; chk.imag = 0;
   dbg_sum->real += chk.real;

  reshuffle_arr_shd[MYTHREAD] = (shared[] dcomplex*)&big_reshuffle_arr[MYTHREAD].arr;

}

int main() { return 0; }


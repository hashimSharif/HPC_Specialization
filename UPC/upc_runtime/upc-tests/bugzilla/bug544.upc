#if __UPC__
#include <upc_strict.h>
#endif
#include <stdio.h>

int foo[100];
int *pfoo = &(foo[2]);
int *pcrazy = &(foo[(&(foo[40]) - &(foo[30]))]);

int main() {
#if __UPC__
  int mythread = MYTHREAD;
#else
  int mythread = 0; /* single-threaded C99 prog */
#endif

foo[2] = mythread;
foo[10] = 100 + mythread;

/* check initialization */
if (pfoo != &(foo[2])) printf("%i: ERROR1\n",mythread);
else printf("%i: OK1\n", mythread);
if (pcrazy != &(foo[10])) printf("%i: ERROR2\n", mythread);
else printf("%i: OK2\n", mythread);

#if __UPC__
  upc_barrier;
#endif

/* check no other thread stomped on our private value */
if (*pfoo != mythread) printf("%i: ERROR3\n", mythread);
else printf("%i: OK3\n", mythread);
if (*pcrazy != 100+mythread) printf("%i: ERROR4\n", mythread);
else printf("%i: OK4\n", mythread);

return 0;
}

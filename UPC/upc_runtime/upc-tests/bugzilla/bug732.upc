/*
  This test is related to bug 732
  IFF run w/ the -trace option to upcrun it will check for bogus #line's
  This makes it unsuitable for automated testing.
*/
#include <upc.h>
#include <stdio.h>
#include <string.h>

shared int x[THREADS];

/* HACK: only work's w/o pthreads */
extern unsigned int gasneti_srclinenum;
extern char *gasnet_getenv(const char *s);

int main(int argc, char **argv) {
#if !GASNET_TRACE
  printf("WARNING: unable to run test because tracing is disabled.\n");
#elif GASNETI_CLIENT_THREADS
  printf("WARNING: unable to run test because pthreads are enabled.\n");
#else
  const char *file, *mask;
  int a,b;
  int y;

  y = x[MYTHREAD];
  a = __LINE__;
  b = gasneti_srclinenum; /* line number for the get, expecting (a-1) */

  if ((file = gasnet_getenv("GASNET_TRACEFILE")) == NULL) {
    printf("WARNING: unable to run test because tracing is not active.\n");
  } else if (((mask = gasnet_getenv("GASNET_TRACEMASK")) != NULL) &&
	     (strchr(mask, 'N') == NULL)) {
    printf("WARNING: unable to run test because 'N' is not in GASNET_TRACEMASK.\n");
  } else if (b == 0) {
    printf("WARNING: unable to run test for unknown reason.\n");
  } else if (b >= a) {
    printf("FAILED: get on line %d appears to come from line %d\n", (a-1), b);
  } else {
    printf("PASSED: get on line %d appears to come from line %d\n", (a-1), b);
  }
#endif
  printf("done.\n");
  return 0;
}

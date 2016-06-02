#include <stdio.h>
#include <upc.h>

/* This test verifies the compiler's default argument promotion is working correctly */
/* Do NOT NOT NOT NOT NOT add a prototype for foo here!!!! */


int x;
shared int y;

int main() {
 char c=1;
 short s=2;
 int i=3;
 long l=4;
 float f=5.0;
 double d=6.0;
 int *ip=&x;
 shared int *sip=&y;
 int r;

 r = foo(c,s,i,l,f,d,ip,sip);
 if (!r) printf("ERROR\n");
 else printf("done.\n");
 return 0;
}

int foo(int c, int s, int i, long l, double f, double d, int *ip, shared int *sip) {
  printf("%i %i %i %li %f %f\n",c,s,i,l,f,d);
  if (c != 1) return 0;
  if (s != 2) return 0;
  if (i != 3) return 0;
  if (l != 4) return 0;
  if (f != 5.0) return 0;
  if (d != 6.0) return 0;
  if (ip != &x) return 0;
  if (sip != &y) return 0;
  return 1;
}


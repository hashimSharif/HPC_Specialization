#include <upc.h>
#include <stdio.h>

#if defined(__UPC_DYNAMIC_THREADS__) 
  #error "Test is only valid for static threads"
#endif

#define check(t) \
  if (!(t)) \
    { \
      fprintf (stderr, "%s:%d (thread %d) Error: test failed: %s\n", \
               __FILE__, __LINE__, MYTHREAD, #t); \
      fail = 1; \
    }

shared     int a[3]  = {1,2};
shared [*] int b[7]  = {13,14,15,16,17};
shared []  int c[16] = {26,27,28,29,30,31,32,33,34,35,36};
shared [2] int d[8]  = {47,48,49,50};

shared []  int e[2*THREADS] = {
	100,101,
 #if THREADS > 1
	102,103,
 #endif
 #if THREADS > 2
	104,105,
 #endif
 #if THREADS > 3
	106,107,
 #endif
 #if THREADS > 4
	108,109
 #endif
};

int
main(void) {
  int fail = 0;

  check(a[0] == 1);
  check(a[1] == 2);
  check(a[2] == 0);

  check(b[0] == 13);
  check(b[1] == 14);
  check(b[2] == 15);
  check(b[3] == 16);
  check(b[4] == 17);
  check(b[5] == 0);
  check(b[6] == 0);

  check(c[0]  == 26);
  check(c[1]  == 27);
  check(c[2]  == 28);
  check(c[3]  == 29);
  check(c[4]  == 30);
  check(c[5]  == 31);
  check(c[6]  == 32);
  check(c[7]  == 33);
  check(c[8]  == 34);
  check(c[9]  == 35);
  check(c[10] == 36);
  check(c[11] == 0);
  check(c[12] == 0);
  check(c[13] == 0);
  check(c[14] == 0);
  check(c[15] == 0);

  check(d[0]  == 47);
  check(d[1]  == 48);
  check(d[2]  == 49);
  check(d[3]  == 50);
  check(d[4]  == 0);
  check(d[5]  == 0);
  check(d[6]  == 0);
  check(d[7]  == 0);

  if (MYTHREAD < 5) {
    check(e[2*MYTHREAD+0] == 100 + 2*MYTHREAD);
    check(e[2*MYTHREAD+1] == 101 + 2*MYTHREAD);
  } else {
    check(e[2*MYTHREAD+0] == 0);
    check(e[2*MYTHREAD+1] == 0);
  }

  puts(fail ? "FAIL" : "PASS");
  return fail;
}


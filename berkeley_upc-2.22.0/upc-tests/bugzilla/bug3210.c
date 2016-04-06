#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void test(int tnum, const char *check, const char *format, ...) {
  #if 1
    va_list l1, l2;
  #else
    va_list l1;
    va_list l2;
  #endif
  int vlen = strlen(check);
  char s1[80];
  char s2[80];
  s1[0] = 0;
  s2[0] = 0;
  printf("case %i:\n",tnum);
  va_start(l1, format);
    va_copy(l2, l1);
    switch (tnum) {
      case 0:
        #define CHECK(T, verify) do { \
          T a1 = va_arg(l1, T);       \
          T a2 = va_arg(l2, T);       \
          if (a1 != verify) printf("ERROR %i: a1 mismatch\n",__LINE__); \
          if (a2 != verify) printf("ERROR %i: a2 mismatch\n",__LINE__); \
        } while (0)
        #define CHECKP(verify) do { \
          char * a1 = va_arg(l1, char *);       \
          char * a2 = va_arg(l2, char *);       \
          if (strcmp(a1,verify)) printf("ERROR %i: a1 mismatch: '%s' '%s'\n",__LINE__,a1,verify); \
          if (strcmp(a2,verify)) printf("ERROR %i: a2 mismatch: '%s' '%s'\n",__LINE__,a2,verify); \
        } while (0)
        CHECK(int, '1');
        CHECK(int, 23);
        CHECK(double, 4.5);
        CHECKP("67");
        CHECK(unsigned long long, 8);
        CHECK(double, 9.0);
        CHECKP("ABC");
        CHECK(int, 'D');
      break;
      case 1: {
        int a1len = vfprintf(stdout, format, l1); printf("\n");
        int a2len = vfprintf(stdout, format, l2); printf("\n");
        #define CHECKLEN() do { \
          if (a1len != vlen) printf("ERROR: a1len=%i vlen=%i\n",a1len,vlen); \
          if (a2len != vlen) printf("ERROR: a2len=%i vlen=%i\n",a2len,vlen); \
        } while (0)
        CHECKLEN();
      break; }
      case 2: {
        int a1len = vprintf(format, l1); printf("\n");
        int a2len = vprintf(format, l2); printf("\n");
        CHECKLEN();
      break; }
      case 3: {
        int a1len = vsnprintf(s1, 80, format, l1);
        int a2len = vsnprintf(s2, 80, format, l2);
        #define CHECKSTR() do { \
          if (strcmp(s1,check)) printf("ERROR: s1=%s check=%s\n",s1,check); \
          if (strcmp(s2,check)) printf("ERROR: s2=%s check=%s\n",s2,check); \
        } while (0)
        CHECKLEN();
        CHECKSTR();
      break; }
      case 4: {
        int a1len = vsprintf(s1, format, l1);
        int a2len = vsprintf(s2, format, l2);
        CHECKLEN();
        CHECKSTR();
      break; }
      case 5: {
        if (tnum == 0) { // skip input execution, just typecheck
          vfscanf(stdin, format, l1);
          vfscanf(stdin, format, l2);
        }
      break; }
      case 6: {
        if (tnum == 0) { // skip input execution, just typecheck
          vscanf(format, l1);
          vscanf(format, l2);
        }
      break; }
      case 7: {
        if (tnum == 0) { // skip input execution, just typecheck
          vsscanf(s1, format, l1);
          vsscanf(s2, format, l2);
        }
      break; }
    }
  va_end(l1);
  va_end(l2);
}

int main() {
#ifdef __UPC__
  if (MYTHREAD == THREADS-1) 
#endif
  {
    for (int i=0; i <= 7; i++) {
      test(i, "1234.56789.0ABCD","%c%i%3.1f%s%llu%3.1f%s%c",'1',23,4.5,"67",8ULL,9.0f,"ABC",'D');
    }
    printf("done.\n");
  }
  return 0;
}

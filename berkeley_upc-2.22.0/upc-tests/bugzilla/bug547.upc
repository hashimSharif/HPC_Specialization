#include <limits.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#define CONCAT_HELPER(a,b) a ## b
#define CONCAT(a,b) CONCAT_HELPER(a,b)
#define ID(x)  #x
#define STR(x) ID(x)

#define FTEST(expr) do { \
  float CONCAT(f,__LINE__) = expr; \
  printf("f"STR(__LINE__)"=%#-20.7g expr='%s'\n", CONCAT(f,__LINE__), #expr); \
  CONCAT(f,__LINE__) = expr; \
  printf("f"STR(__LINE__)"=%#-20.7g expr='%s'\n", CONCAT(f,__LINE__), #expr); \
} while(0)
#define DTEST(expr) do { \
  double CONCAT(d,__LINE__) = expr; \
  printf("d"STR(__LINE__)"=%#-20.14g expr='%s'\n", CONCAT(d,__LINE__), #expr); \
  CONCAT(d,__LINE__) = expr; \
  printf("d"STR(__LINE__)"=%#-20.14g expr='%s'\n", CONCAT(d,__LINE__), #expr); \
} while(0)
#define TEST(expr) \
  FTEST(expr); DTEST(expr)

int main() {
TEST(0.0);
TEST(4E10);
TEST(4E40);
TEST(-4.7E-10);
FTEST(0.0F);
FTEST(4E10f);
#if 0 /* test case covered by bug2403 */
FTEST(4E40F);
#endif
FTEST(-4.7E-10f);
TEST(FLT_MAX);
TEST(FLT_MIN);
TEST(FLT_EPSILON);
TEST(DBL_MAX);
TEST(DBL_MIN);
TEST(DBL_EPSILON);
TEST(4);
TEST(-10);
TEST(0);
TEST(0.09);
TEST(-1.234E-16);
TEST(-1.234E16);
TEST(0.3*0.3/1.0);
TEST(0.0/0.0);
TEST(NAN);
TEST(INFINITY);
DTEST(HUGE_VAL);
TEST(HUGE_VALF);
printf("SUCCESS\n");
}

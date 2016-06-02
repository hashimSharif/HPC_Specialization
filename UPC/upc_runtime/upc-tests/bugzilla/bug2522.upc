#include <stdint.h>
#include <stdio.h>

typedef struct test_case_t {
  struct {int value;} first[1];
  int second;
  int third[1];
} test_case_t;

int test_case_fun (test_case_t testing)
{
  printf ("%d", testing.third[0]);

  return 0;
}

int main(void) { return 0; }

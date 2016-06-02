#include <stdio.h>

void foo(void) {
  extern int value;  /* <-- the problem starts here */
  printf("value=%d\n", value);
}

int value;

int main(void) {
  value = 42;  /* <-- translator sees this a a differnt symbol */
  foo();
  return 0;
}

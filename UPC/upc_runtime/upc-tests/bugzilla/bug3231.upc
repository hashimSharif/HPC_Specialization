#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
struct s1 { char c; shared void *pts; };
struct s2 { char c; uint64_t u64;     };
int main(void) {
  int pass = offsetof(struct s1,pts) == offsetof(struct s2,u64);
  puts(pass ? "PASS" : "FAIL");
  return pass ? 0 : 1;
}

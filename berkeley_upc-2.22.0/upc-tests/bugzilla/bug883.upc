#include <stdio.h>
#include <assert.h>

void p(int s[2][2][10])
{ 
  s[0][0][9] = 100; 
}

int main() {
  int s[2][2][10];
  s[0][0][9] = 0;
  p(s); 
  assert(s[0][0][9] == 100);
  printf("done.\n");
  return 0;
}

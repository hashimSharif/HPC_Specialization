// bug 3105: -opt was moving initializers to file-scope causing multiply defined symbols
#include <stdio.h>

int f1(void) {
  int a[10] = { 1,2,3,4 };
  return a[0] + a[3];
}

int f2(void) {
  int a[10] = { 4,3,2,1 };
  return a[1] + a[2];
}

int main(void) {
  int same = (f1() == f2());
  puts( same ? "PASS" : "FAIL");
  return !same;
}

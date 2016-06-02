#pragma upc c_code

#include "bug899.h"

int foo(int shared) { return shared+1; }

struct S {
 int MYTHREAD;
 int THREADS;
 int strict;
 int relaxed;
 int shared;
} s;

int main(void)
{ 
  int MYTHREAD = 1;
  int THREADS = 2;
  int strict = 3;
  int relaxed = 4;
  int shared;
  MYTHREAD = 10;
  THREADS = 20;
  strict = 30;
  relaxed = 40;
  shared = foo(5);
  s.MYTHREAD = 3;
  s.THREADS = 3;
  s.strict = 3;
  s.relaxed = 3;
  s.shared = 3;
  return 0;
}

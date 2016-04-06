#include <upc_relaxed.h>
#include <stdio.h>
int foo(int a, int b)
{
  return(a+b);
}
 
typedef int (*ftype)(int,int);
int bar(int a)
{
  int (*baz)(int,int);
  baz = foo;
  return(baz(a,a));
}
 
int main()
{
  printf("%d\n",bar(MYTHREAD));
  return 0;
}


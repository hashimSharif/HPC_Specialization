#include <upc_relaxed.h>
#include <stdio.h>
int count(int a, int b)
{
  int num;
  num = (a > 0) + (b > 0);
  return(num);
}


int main()
{
  printf("%d\n",count(2,-1));
}

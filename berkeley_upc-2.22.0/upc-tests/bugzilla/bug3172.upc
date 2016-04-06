#include <upc.h>
#include <stddef.h>

// function declaration goes in header
shared [] int *testReturnType();

// function definition causes warning for return type
shared [] int *testReturnType(void)
{
  shared [] int *t = NULL;
  return t;
}

// initialization causes warning for return type
int main(int argc, char **argv)
{
  shared [] int *t = testReturnType();
  return 0;
}

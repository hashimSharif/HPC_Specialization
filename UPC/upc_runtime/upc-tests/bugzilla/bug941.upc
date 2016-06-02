#include <stdlib.h>
int (*p)[];
int main(void)
{
  p = malloc(800);
  return 0;
}


#include "bug909.h"

int main(void)
{
  BARSTRUCT mybar, *myp;
  myp = &mybar;
  myp->q = 0;
  return 0;
}

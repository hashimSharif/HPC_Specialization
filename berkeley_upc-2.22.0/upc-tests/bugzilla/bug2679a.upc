#include <upc.h>
#include <stdio.h>

shared [] int s[1];

int main(void)
{
  int i, j;
  int *p[1] = { &i };

  if (p[0] != &i) printf("Error: test failed\n");
  else printf("done.\n");

#if 1
  /* Changing to "#if 0" appears to allow the code above to compile correctly.
     Also worth noting: rewriting w/ either 's' or 'p' as scalars fixes things too.
     So, it would appear that at least one shared array access is a necessary condition. */
  j = s[0];
#endif

  return 0;
}

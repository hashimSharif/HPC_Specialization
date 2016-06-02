/* Warning: #pragma upc not allowed in this context.  */
#include <upc.h>

shared int v;

shared int *pts;

int main (void)
{
  pts = &v;
  /* pragma upc must appear contextually as first token
     after opening brace.  Invalid here.  */
  #pragma upc strict
  *pts = 1;
  return 0;
}

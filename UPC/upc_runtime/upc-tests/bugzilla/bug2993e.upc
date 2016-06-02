/* Use keyword defined in old 1.0 specification that is
   now depracated.  This should be a compilation error.  */
#include <upc.h>
#include <stdio.h>
   
int main()
{
  fence;  /* ERROR  */
  if (!MYTHREAD)
    fprintf (stderr, "FAIL: compilation error expected\n");
  return 1;
}

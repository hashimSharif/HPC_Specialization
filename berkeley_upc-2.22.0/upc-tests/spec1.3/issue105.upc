// #include <upc.h>  Not required for this test.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __UPC_VERSION__
#if __UPC_VERSION__ != 201311L
#error __UPC_VERSION__ is not equal to 201311.
#endif
#else
#error __UPC_VERSION__ is not a pre-defined macro.
#endif

#define _XSTR(X) #X
#define _STR(S) _XSTR(S)

#define UPC_VERSION_STRING _STR(__UPC_VERSION__)

int
main (void)
{
  if (!MYTHREAD)
    {
      if (strcmp (UPC_VERSION_STRING, "201311L"))
	{
	  fprintf (stderr, "__UPC_VERSION__ is '%s', expected: '201311L'.\n",
		   UPC_VERSION_STRING);
	  abort ();
	}
      puts ("Check that __UPC_VERSION__ is '201311L': passed.");
    }
  return 0;
}

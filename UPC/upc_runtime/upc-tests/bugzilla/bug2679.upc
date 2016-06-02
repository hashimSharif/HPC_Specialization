#include <stdio.h>
#include <upc.h>

/* Changing timer[] from shared to private eliminates the bug */
#define WORKAROUND1 0

/* Making the array for char* 'static' eliminates the bug */
#define WORKAROUND2 0

#define T_MAX 9

#if !WORKAROUND1
shared []
#endif
    double timer[T_MAX];

int main(void) {
#if WORKAROUND2
  static
#endif
  const char *tstrings[] =
  {"string1 ",
   "string2 ",
   "string3 ",
   "string4 ",
   "string5 ",
   "string6 ",
   "string7 ",
   "string8 ",
   "done."};

  if (!MYTHREAD) {
    for (int i = 0; i < T_MAX; i++)
      printf ("%s = %10.3f\n", tstrings[i], timer[i]);
  }

  return 0;
}

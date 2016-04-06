#include <stdlib.h> /* For NULL */
#include <fenv.h>
int foo (fenv_t *p) { return feholdexcept(p); }



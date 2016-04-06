#include <upc.h>
#include <stdint.h>

/* When bug is "live" this include (linux+pthreads) is sufficient */
#include <stdlib.h>

/* This is the type of code that causes the warning */
typedef union
{
  int *p;
  uintptr_t u;
} foo_t __attribute__ ((__transparent_union__));

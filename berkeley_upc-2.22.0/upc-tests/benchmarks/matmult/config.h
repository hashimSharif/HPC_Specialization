#include <upc_relaxed.h>

#define M 64
#define N 64
#define P 32

typedef double elem_t;

#include "bupc_timers.h"
#define second() (TIME()/1000000.0)

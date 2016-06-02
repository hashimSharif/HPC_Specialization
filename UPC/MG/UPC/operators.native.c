#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <immintrin.h>
#ifdef _UPC
#include "upc.h"
#endif 

#ifdef _UPCR
#ifdef _UPC 
#error DDs
#endif
#include "upcr.h"
#endif

#include "timer.h"
#include "defines.h"
#include "box.h"
#include "mg.h"
#include "operators.h"

#if 1
#include "../operators.sse/buffer_copy.c"
#include "../operators.sse/ghosts.c"
#include "../operators.sse/smooth.c"
#else
#include "../operators.naive/buffer_copy.c"
#include "../operators.naive/ghosts.c"
#include "../operators.reference/smooth.c"
#endif 

#include "../operators.reference/residual.c"
#include "../operators.ompif/restriction.c"
#include "../operators.ompif/interpolation.c"
#include "../operators.naive/misc.c"
#include "operators.upc/max_norm.c"

#ifdef NO_PACK
#include "operators.upc/exchange_boundary.immediate.c"
#else
#ifdef _USE_GET 
#include "operators.upc/exchange_boundary.aggregate.get.c"
#else
#include "operators.upc/exchange_boundary.aggregate.c"
#endif
#endif
